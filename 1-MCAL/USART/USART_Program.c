/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   MCAL			      ***************************/
/*************                SWC :     USART	              ***************************/
/*************                VERSION : 1.00		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

#include "../../4-LIB/BIT_MATH.h"
#include "../../4-LIB/STD_TYPES.h"

#include "USART_Config.h"
#include "USART_Interface.h"
#include "USART_Private.h"
#include "USART_Register.h"

/* BAUD RATE DIVISOR DEFINTIONS */
#if    ( TRANSMISSION_SPEED     ==     NORMAL_SPEED )  && ( USART_MODE  ==  ASYNCHRONOUS )

#define DIVISOR            16

#elif  ( TRANSMISSION_SPEED     ==    DOUBLE_SPEED )  &&  ( USART_MODE  ==  ASYNCHRONOUS )

#define DIVISOR             8

#endif

#if    USART_MODE          ==     SYNCHRONOUS

#define DIVISOR             2

#endif

#define CALC_UBRR( BAUD_RATE )    (u16)( ( ( F_CPUUU / ( DIVISOR * (u32)BAUD_RATE ) ) - 1 ) + 0.5 )

/* Global Variable to Store Buffer Size ( ASYCH ) */
u8 USART_BufferSize = 0 ;

/* Global Pointer to Function to Store Notification Function ( ASYCH ) */
void( *USART_PvNotificationFunc )(void) = NULL ;

/* Global Variable to Store Buffer Elements */
char * USART_Buffer = 0 ;

/* Global Variable to Store Bit Index When Sending or Recieving String */
u8 USART_BitIndex = 0 ;

/* Variable To Store the Eighth Bit if 9 Bits Data Frame is Used */
u16 Local_u16EighthBit = 0 ;

/* Variable to Check in ISR The Source of Interrupt is which Function */
u8 USART_ISR_SOURCE = 0 ;

u8 USART_BUSY_STATE = USART_IDLE ;

void USART_voidInit( void )
{
	u8  Local_u8UCSRCValue = 0 ;
	u16 Local_u16UBRRValue = 0 ;

	/* Double USART Transmission Speed */
#if   ( TRANSMISSION_SPEED     ==    NORMAL_SPEED )   ||  ( USART_MODE      ==    SYNCHRONOUS  )
	UCSRA &= ( ~ ( 1 << UCSRA_U2X ) ) ;
#elif ( TRANSMISSION_SPEED     ==    DOUBLE_SPEED )
	UCSRA |= ( 1 << UCSRA_U2X ) ;
#endif


	/* Multi Processor Communication Mode Select */
	UCSRA |= ( MULTI_PROCECCOR_COMMUNICATION_MODE ) ;

	/* Recieve Complete Interrupt */
#if     RECIEVE_COMPLETE_INTERRUPT     ==     ENABLED
	UCSRB |= ( 1 << UCSRB_RXCIE ) ;
#elif   RECIEVE_COMPLETE_INTERRUPT     ==     DISABLED
	UCSRB &= ( ~ ( 1 << UCSRB_RXCIE ) ) ;
#endif

	/* Transmit Complete Interrupt */
#if   TRANSMIT_COMPLETE_INTERRUPT      ==     ENABLED
	UCSRB |= ( 1 << UCSRB_TXCIE ) ;
#elif   TRANSMIT_COMPLETE_INTERRUPT     ==     DISABLED
	UCSRB &= ( ~ ( 1 << UCSRB_TXCIE ) ) ;
#endif

	/* Data  Register Empty Interrupt */
#if     DATA_REGISTER_EMPTY_INTERRUPT  ==      ENABLED
	UCSRB |= ( 1 << UCSRB_UDRIE ) ;
#elif   DATA_REGISTER_EMPTY_INTERRUPT     ==     DISABLED
	UCSRB &= ( ~ ( 1 << UCSRB_UDRIE ) ) ;
#endif


	/* USART MODE */
#if    USART_MODE                      ==         ASYNCHRONOUS
	Local_u8UCSRCValue &= ( ~ ( 1 << UCSRC_UMSEL ) ) ;
#elif  USART_MODE                      ==         SYNCHRONOUS
	Local_u8UCSRCValue |= ( 1 << UCSRC_UMSEL ) ;
#endif


	/* Set Parity Mode */
	Local_u8UCSRCValue |= ( PARITY_MODE << UCSRC_UPM0 ) ;

	/* Stop Bit Select */
#if   STOP_BIT_SELECT      ==    _1_BIT
	Local_u8UCSRCValue &= ( ~ ( 1 << UCSRC_USBS ) ) ;
#elif STOP_BIT_SELECT      ==    _2_BIT
	Local_u8UCSRCValue |= ( 1 << UCSRC_USBS ) ;
#endif


	/* SET DATA BITS ( CHARACTER SIZE ) */
#if   ( DATA_BITS >= _5_BIT ) && ( DATA_BITS <=  _8_BIT )

	/* BIT MASKING */
	Local_u8UCSRCValue &= ( CHARACTER_SIZE_MASK ) ;
	Local_u8UCSRCValue |= ( DATA_BITS << UCSRC_UCSZ0 ) ;
#elif  DATA_BITS         ==    _9_BIT

	UCSRB |= ( 1 << UCSRB_UCSZ2 ) ;
	/* BIT MASKING */
	Local_u8UCSRCValue &= ( CHARACTER_SIZE_MASK ) ;
	Local_u8UCSRCValue |= ( _8_BIT << UCSRC_UCSZ0 ) ;
#endif


	/* Clock Polarity */
#if    ( CLOCK_POLARITY    ==    SEND_ON_RISING_RECIEVE_ON_FALLING )  ||  ( USART_MODE  ==   ASYNCHRONOUS )
	Local_u8UCSRCValue &= ( ~ ( 1 << UCSRC_UCPOL ) ) ;
#elif  ( CLOCK_POLARITY   == SEND_ON_FALLING_RECIEVE_ON_RISING )
	Local_u8UCSRCValue |= ( 1 << UCSRC_UCPOL ) ;
#endif

	/* Set the MSB To Access UCSRC */
	Local_u8UCSRCValue |= ( 1 << UCSRC_URSEL ) ;

	/* Set UCSRC Value To The Register */
	UCSRC = Local_u8UCSRCValue ;

	/* Set Baud Rate */
	Local_u16UBRRValue = CALC_UBRR( BAUD_RATE_VALUE ) ;

	/* Send on UBRR Value */
	if( ( Local_u16UBRRValue >=0 )  && ( Local_u16UBRRValue <= 255 ) )
	{
		UBRRL = (u8)Local_u16UBRRValue ;
	}
	else if( ( Local_u16UBRRValue > 255 ) &&  ( Local_u16UBRRValue <= 4095UL ) )
	{
		/* To Get The First 8 Bits */
		UBRRL = (u8)Local_u16UBRRValue ;

		/* To Get The 4 Last Bits , the Bit 7 in UBRRH is Zero to Access UBRRH */
		UBRRH = ( u8 )( Local_u16UBRRValue >> 8 ) ;
	}

	/* Enable Transmitter */
#if    TRANSMITER_ENABLE    ==    ENABLED
	UCSRB |= ( 1 << UCSRB_TXEN ) ;
#elif  TRANSMITER_ENABLE    ==    DISABLED
	UCSRB &= ( ~ ( 1 << UCSRB_TXEN ) ) ;
#endif


	/* Enable Reciever */
#if    RECIEVER_ENABLE    ==    ENABLED
	UCSRB |= ( 1 << UCSRB_RXEN ) ;
#elif  RECIEVER_ENABLE    ==    DISABLED
	UCSRB &= ( ~ ( 1 << UCSRB_RXEN ) ) ;
#endif


}

u8 USART_voidSendCharSynch( u16 Copy_u16Data )
{
	u8 Local_u8ErrorStatus = 0 ;

	if( USART_BUSY_STATE == USART_IDLE )
	{
		/* Make USART BUSY */
		USART_BUSY_STATE = USART_BUSY ;

		/* Waiting Until Data Register Empty Flag is Set OR Timeout is Reached */
		while( ( GET_BIT( UCSRA , UCSRA_UDRE ) == 0 ) ) ;

#if  DATA_BITS  ==  _9_BIT

		/* First : Eighth Bit Must be Written in UCSRB - BIT 0 - before Writing the Lower Bits */
		UCSRB |= ( GET_BIT( Copy_u16Data , 8 ) ) ;

		/* Second : Writing The Lower Bits in UDR */
		UDR = ( u8 ) Copy_u16Data ;

#elif ( DATA_BITS >= _5_BIT ) && ( DATA_BITS <= _8_BIT )

		/* Put Data in UDR with Casting it */
		UDR = ( u8 ) Copy_u16Data ;

#endif

		/* Return Back USART to IDLE */
		USART_BUSY_STATE = USART_IDLE ;

	}
	else
	{
		/* USART is Busy */
		Local_u8ErrorStatus = BUSY_FUNC ;
	}

	return Local_u8ErrorStatus ;
}

u16 USART_u8RecieveCharSynch( void )
{
	u16 Local_u16ReceivedData = 0 ;

	/* Waiting Until Receicve is Completed ( Receive Complete Flag is Set ) */
	while( ( GET_BIT( UCSRA , UCSRA_RXC )  == 0 ) ) ;

	/* Loop is Broken Because Recieve Complete Flag is Set */

#if   DATA_BITS  ==  _9_BIT

	/* First : Eighth Bit Must Be Read From UCSRB - BIT 1 - Before Reading The Lower Bits */
	Local_u16EighthBit = GET_BIT( UCSRB , UCSRB_RXB8 ) ;

	/* Second : Reading The Lower Bits From UDR */
	Local_u16ReceivedData = UDR ;

	/* Put The Eighth Bit in the Variable Local_u16RecievedValue  */
	Local_u16ReceivedData |= ( Local_u16EighthBit << 8 ) ;

#elif ( DATA_BITS >= _5_BIT ) && ( DATA_BITS <= _8_BIT )

	/* Read UDR Register */
	Local_u16ReceivedData = UDR ;

#endif

	return Local_u16ReceivedData ;
}


void USART_voidSendStringSynch( char * Copy_charString )
{
	/* Counter To Loop Through String Elements */
	u8 Local_u8Counter = 0 ;

	/* Send All Characters Except NULL Character */
	while( Copy_charString[ Local_u8Counter ] != '\0' )
	{
		USART_voidSendCharSynch( Copy_charString[ Local_u8Counter ] ) ;
		Local_u8Counter++;
	}
}

void USART_voidRecieveBufferSynch( char * Copy_p8Buffer , u8 Copy_u8BufferSize )
{
	u8 Local_u8LoopCounter = 0 ;

	for( Local_u8LoopCounter = 0 ; Local_u8LoopCounter < Copy_u8BufferSize ; Local_u8LoopCounter++ )
	{
		Copy_p8Buffer[ Local_u8LoopCounter ] = USART_u8RecieveCharSynch(  ) ;
	}
}

u8 USART_voidRecieveBufferASynch( char * Copy_p8Buffer , u8 Copy_u8BufferSize , void( *Copy_pvNotificationFunc )(void) )
{
	u8 Local_u8ErrorStatus = OK ;

	if( Copy_pvNotificationFunc != NULL )
	{
		/* Define Source of Interrupt */
		USART_ISR_SOURCE = RECIEVE_BUFFER ;

		/* Initialize Global Variables */
		USART_BufferSize = Copy_u8BufferSize ;
		USART_PvNotificationFunc = Copy_pvNotificationFunc ;
		USART_Buffer = Copy_p8Buffer ;

		/* Set Variable Bit Index to Zero To Start From First Element */
		USART_BitIndex = 0 ;

		/* Enable RXC Interrupt */
		SET_BIT( UCSRB , UCSRB_RXCIE ) ;


	}
	else
	{
		Local_u8ErrorStatus = NULL_POINTER ;
	}

	return Local_u8ErrorStatus ;
}


/* RECIEVE COMPLETE ISR ( RXC ) */
void __vector_13(void) __attribute__((signal));
void __vector_13(void)
{
	if( USART_ISR_SOURCE == RECIEVE_BUFFER )
	{

		/* Recieve Buffer */
		/* Assuming 8 data Bits */
		USART_Buffer[ USART_BitIndex ] = UDR ;

		/* Increment Index */
		USART_BitIndex++ ;

		if( USART_BufferSize == USART_BitIndex )
		{
			/* Buffer is Finished */

			/* Disable Recieve Complete Interrupt */
			CLEAR_BIT( UCSRB , UCSRB_RXCIE ) ;

			/* Call Notification Function */
			USART_PvNotificationFunc(  ) ;

		}
		else
		{
			/* Buffer is Not Finished */

			/* Continue Receiving */

		}


	}

}
