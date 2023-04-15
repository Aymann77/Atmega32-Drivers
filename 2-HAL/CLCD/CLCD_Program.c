/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   HAL  			      ***************************/
/*************                SWC :     CLCD	              ***************************/
/*************                VERSION : 1.00		          ***************************/
/*************                DATE : 7/9/2022		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

/*---------------------------------------------------------------------------------------*/


#include "../../4-LIB/STD_TYPES.h"
#include "../../4-LIB/BIT_MATH.h"

#include "../../1-MCAL/DIO/DIO_Interface.h"

#include "CLCD_Config.h"
#include "CLCD_Interface.h"
#include "CLCD_Private.h"

#include <util/delay.h>


/*---------------------------------------------------------------------------------------*/

#if LCD_MODULE == LCD_16X2
void CLCD_voidInit( void )
{


#if LCD_MODE == LCD_8BIT_MODE

	/*DATA PINS DIRICTION*/
	DIO_u8SetPortDirection( CLCD_DATA_PORT , DIO_u8PORT_OUTPUT );

	/*CTRL PINS DIRECTION*/
	DIO_u8SetPinDirection( CLCD_CTRL_PORT , CLCD_RS_PIN , DIO_u8PIN_OUTPUT );
	DIO_u8SetPinDirection( CLCD_CTRL_PORT , CLCD_RW_PIN , DIO_u8PIN_OUTPUT );
	DIO_u8SetPinDirection( CLCD_CTRL_PORT , CLCD_E_PIN  , DIO_u8PIN_OUTPUT );

	/*Display ON/OFF Control*/
	u8 DISPLAY_ON_OFF_CONTROL = 0x08 ;

	/*Function Set*/
	u8 FUNCTION_SET_8BIT = 0x30 ;

	/*Wait For More Than 30ms*/
	_delay_ms(40) ;

	/*FUNCTION SET 8 BIT INTIALIZATION*/
#if NUMBER_OF_LINES == ONE_LINE
	CLEAR_BIT( FUNCTION_SET_8BIT , NUMBER_OF_LINES_BIT ) ;
#elif NUMBER_OF_LINES == TWO_LINES
	SET_BIT( FUNCTION_SET_8BIT , NUMBER_OF_LINES_BIT ) ;
#endif

#if FONT_SIZE == FONT_5x8
	CLEAR_BIT( FUNCTION_SET_8BIT , FONT_SIZE_BIT ) ;
#elif FONT_SIZE == FONT_5x11
	SET_BIT( FUNCTION_SET_8BIT , FONT_SIZE_BIT ) ;
#endif

	CLCD_voidSendCommand( FUNCTION_SET_8BIT );

	/*Display ON/OFF Control*/
#if DISPLAY == DISPLAY_ENABLE
	SET_BIT( DISPLAY_ON_OFF_CONTROL , DISPLAY_BIT );
#elif DISPLAY == DISPLAY_DISABLE
	CLEAR_BIT( DISPLAY_ON_OFF_CONTROL , DISPLAY_BIT );
#endif

#if CURSOR == CURSOR_DISABLE
	CLEAR_BIT( DISPLAY_ON_OFF_CONTROL , CURSOR_BIT );
#elif CURSOR == CURSOR_ENABLE
	SET_BIT( DISPLAY_ON_OFF_CONTROL , CURSOR_BIT );
#endif

#if BLINK_CURSOR == BLINK_DISABLE
	CLEAR_BIT( DISPLAY_ON_OFF_CONTROL , BLINK_BIT );
#elif BLINK_CURSOR == BLINK_ENABLE
	SET_BIT( DISPLAY_ON_OFF_CONTROL , BLINK_BIT );
#endif

	CLCD_voidSendCommand( DISPLAY_ON_OFF_CONTROL );


	/*Clear Display*/
	CLCD_voidSendCommand( CLCD_CLEAR_DISPLAY );

	/*Return Cursor Home*/
	CLCD_voidSendCommand(CLCD_RETURN_HOME);

	_delay_ms(2);

#elif LCD_MODE == LCD_4BIT_MODE

	/*DATA PINS DIRICTION*/
	DIO_u8SetPortDirection( CLCD_DATA_PORT , 0xF0 );

	/*CTRL PINS DIRECTION*/
	DIO_u8SetPinDirection( CLCD_CTRL_PORT , CLCD_RS_PIN , DIO_u8PIN_OUTPUT );
	DIO_u8SetPinDirection( CLCD_CTRL_PORT , CLCD_RW_PIN , DIO_u8PIN_OUTPUT );
	DIO_u8SetPinDirection( CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_OUTPUT );

	/*Initially enable bit is zero*/
	DIO_u8SetPinValue( CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_LOW );

	/*Function Set*/
	u8 FUNCTION_SET_4BIT = 0x20 ;

	/*Display ON/OFF Control*/
	u8 DISPLAY_ON_OFF_CONTROL = 0x08 ;

	/*Wait For More Than 30ms*/
	_delay_ms(40) ;

	/*FUNCTION SET 4 BIT INTIALIZATION*/
#if NUMBER_OF_LINES == ONE_LINE
	CLEAR_BIT( FUNCTION_SET_4BIT , NUMBER_OF_LINES_BIT ) ;
#elif NUMBER_OF_LINES == TWO_LINES
	SET_BIT( FUNCTION_SET_4BIT , NUMBER_OF_LINES_BIT ) ;
#endif

#if FONT_SIZE == FONT_5x8
	CLEAR_BIT( FUNCTION_SET_4BIT , FONT_SIZE_BIT ) ;
#elif FONT_SIZE == FONT_5x11
	SET_BIT( FUNCTION_SET_4BIT , FONT_SIZE_BIT ) ;
#endif

	CLCD_voidSendCommand(0b00100000);
	CLCD_voidSendCommand(FUNCTION_SET_4BIT);

	/*Display ON/OFF Control*/

#if DISPLAY == DISPLAY_ENABLE
	SET_BIT( DISPLAY_ON_OFF_CONTROL , DISPLAY_BIT );
#elif DISPLAY == DISPLAY_DISABLE
	CLEAR_BIT( DISPLAY_ON_OFF_CONTROL , DISPLAY_BIT );
#endif

#if CURSOR == CURSOR_DISABLE
	CLEAR_BIT( DISPLAY_ON_OFF_CONTROL , CURSOR_BIT );
#elif CURSOR == CURSOR_ENABLE
	SET_BIT( DISPLAY_ON_OFF_CONTROL , CURSOR_BIT );
#endif

#if BLINK_CURSOR == BLINK_DISABLE
	CLEAR_BIT( DISPLAY_ON_OFF_CONTROL , BLINK_BIT );
#elif BLINK_CURSOR == BLINK_ENABLE
	SET_BIT( DISPLAY_ON_OFF_CONTROL , BLINK_BIT );
#endif

	CLCD_voidSendCommand(DISPLAY_ON_OFF_CONTROL);

	/*Clear Display*/
	CLCD_voidSendCommand(CLCD_CLEAR_DISPLAY);

	/*Return Cursor Home*/
	CLCD_voidSendCommand(CLCD_RETURN_HOME);

	_delay_ms(2);

#endif

}

#elif LCD_MODULE == LCD_20X4

void CLCD_voidInit( void )
{


#if LCD_MODE == LCD_8BIT_MODE

	/*DATA PINS DIRICTION*/
	DIO_u8SetPortDirection( CLCD_DATA_PORT , DIO_u8PORT_OUTPUT );

	/*CTRL PINS DIRECTION*/
	DIO_u8SetPinDirection( CLCD_CTRL_PORT , CLCD_RS_PIN , DIO_u8PIN_OUTPUT );
	DIO_u8SetPinDirection( CLCD_CTRL_PORT , CLCD_RW_PIN , DIO_u8PIN_OUTPUT );
	DIO_u8SetPinDirection( CLCD_CTRL_PORT , CLCD_E_PIN  , DIO_u8PIN_OUTPUT );

	/*Display ON/OFF Control*/
	u8 DISPLAY_ON_OFF_CONTROL = 0x08 ;

	/*Function Set*/
	u8 FUNCTION_SET_8BIT = 0x30 ;

	/*Wait For More Than 30ms*/
	_delay_ms(20) ;

	/*FUNCTION SET 8 BIT INTIALIZATION*/
#if NUMBER_OF_LINES == ONE_LINE
	CLEAR_BIT( FUNCTION_SET_8BIT , NUMBER_OF_LINES_BIT ) ;
#elif NUMBER_OF_LINES == TWO_LINES
	SET_BIT( FUNCTION_SET_8BIT , NUMBER_OF_LINES_BIT ) ;
#endif

#if FONT_SIZE == FONT_5x8
	CLEAR_BIT( FUNCTION_SET_8BIT , FONT_SIZE_BIT ) ;
#elif FONT_SIZE == FONT_5x11
	SET_BIT( FUNCTION_SET_8BIT , FONT_SIZE_BIT ) ;
#endif

	/*1*/	CLCD_voidSendCommand( FUNCTION_SET_8BIT );

	_delay_ms(6);

	/*2*/	CLCD_voidSendCommand( FUNCTION_SET_8BIT );

	_delay_ms(1);

	/*3*/	CLCD_voidSendCommand( FUNCTION_SET_8BIT );

	/*4*/	CLCD_voidSendCommand( FUNCTION_SET_8BIT );

	/*Display ON/OFF Control*/
#if DISPLAY == DISPLAY_ENABLE
	SET_BIT( DISPLAY_ON_OFF_CONTROL , DISPLAY_BIT );
#elif DISPLAY == DISPLAY_DISABLE
	CLEAR_BIT( DISPLAY_ON_OFF_CONTROL , DISPLAY_BIT );
#endif

#if CURSOR == CURSOR_DISABLE
	CLEAR_BIT( DISPLAY_ON_OFF_CONTROL , CURSOR_BIT );
#elif CURSOR == CURSOR_ENABLE
	SET_BIT( DISPLAY_ON_OFF_CONTROL , CURSOR_BIT );
#endif

#if BLINK_CURSOR == BLINK_DISABLE
	CLEAR_BIT( DISPLAY_ON_OFF_CONTROL , BLINK_BIT );
#elif BLINK_CURSOR == BLINK_ENABLE
	SET_BIT( DISPLAY_ON_OFF_CONTROL , BLINK_BIT );
#endif

	CLCD_voidSendCommand( DISPLAY_ON_OFF_CONTROL );


	/*Clear Display*/
	CLCD_voidSendCommand( CLCD_CLEAR_DISPLAY );

	/*Return Cursor Home*/
	CLCD_voidSendCommand(CLCD_RETURN_HOME);

	_delay_ms(2);

#elif LCD_MODE == LCD_4BIT_MODE

	/*DATA PINS DIRICTION*/
	DIO_u8SetPortDirection( CLCD_DATA_PORT , 0xF0 );

	/*CTRL PINS DIRECTION*/
	DIO_u8SetPinDirection( CLCD_CTRL_PORT , CLCD_RS_PIN , DIO_u8PIN_OUTPUT );
	DIO_u8SetPinDirection( CLCD_CTRL_PORT , CLCD_RW_PIN , DIO_u8PIN_OUTPUT );
	DIO_u8SetPinDirection( CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_OUTPUT );

	/*Initially enable bit is zero*/
	DIO_u8SetPinValue( CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_LOW );

	/*Function Set*/
	u8 FUNCTION_SET_4BIT = 0x20 ;

	/*Display ON/OFF Control*/
	u8 DISPLAY_ON_OFF_CONTROL = 0x08 ;

	/*Wait For More Than 30ms*/
	_delay_ms(40) ;

	/*FUNCTION SET 4 BIT INTIALIZATION*/
#if NUMBER_OF_LINES == ONE_LINE
	CLEAR_BIT( FUNCTION_SET_4BIT , NUMBER_OF_LINES_BIT ) ;
#elif NUMBER_OF_LINES == TWO_LINES
	SET_BIT( FUNCTION_SET_4BIT , NUMBER_OF_LINES_BIT ) ;
#endif

#if FONT_SIZE == FONT_5x8
	CLEAR_BIT( FUNCTION_SET_4BIT , FONT_SIZE_BIT ) ;
#elif FONT_SIZE == FONT_5x11
	SET_BIT( FUNCTION_SET_4BIT , FONT_SIZE_BIT ) ;
#endif

	CLCD_voidSendCommand(0b00100000);
	CLCD_voidSendCommand(FUNCTION_SET_4BIT);

	/*Display ON/OFF Control*/

#if DISPLAY == DISPLAY_ENABLE
	SET_BIT( DISPLAY_ON_OFF_CONTROL , DISPLAY_BIT );
#elif DISPLAY == DISPLAY_DISABLE
	CLEAR_BIT( DISPLAY_ON_OFF_CONTROL , DISPLAY_BIT );
#endif

#if CURSOR == CURSOR_DISABLE
	CLEAR_BIT( DISPLAY_ON_OFF_CONTROL , CURSOR_BIT );
#elif CURSOR == CURSOR_ENABLE
	SET_BIT( DISPLAY_ON_OFF_CONTROL , CURSOR_BIT );
#endif

#if BLINK_CURSOR == BLINK_DISABLE
	CLEAR_BIT( DISPLAY_ON_OFF_CONTROL , BLINK_BIT );
#elif BLINK_CURSOR == BLINK_ENABLE
	SET_BIT( DISPLAY_ON_OFF_CONTROL , BLINK_BIT );
#endif

	CLCD_voidSendCommand(DISPLAY_ON_OFF_CONTROL);

	/*Clear Display*/
	CLCD_voidSendCommand(CLCD_CLEAR_DISPLAY);

	/*Return Cursor Home*/
	CLCD_voidSendCommand(CLCD_RETURN_HOME);

	_delay_ms(2);

#endif

}



#endif

/*---------------------------------------------------------------------------------------*/


void CLCD_voidSendCommand( u8 Copy_u8Command )
{
#if LCD_MODE == LCD_8BIT_MODE

	/*Set RS Pin To LOW For Command*/
	DIO_u8SetPinValue( CLCD_CTRL_PORT , CLCD_RS_PIN , DIO_u8PIN_LOW ) ;

	/*Set RW Pin To LOW For Write*/
	DIO_u8SetPinValue( CLCD_CTRL_PORT , CLCD_RW_PIN , DIO_u8PIN_LOW ) ;

	/*Send Command To Data Pins*/
	DIO_u8SetPortValue( CLCD_DATA_PORT , Copy_u8Command ) ;

	/*Send Enable Pulse*/
	DIO_u8SetPinValue( CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_HIGH ) ;
	_delay_ms(2);
	DIO_u8SetPinValue( CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_LOW ) ;

#elif LCD_MODE == LCD_4BIT_MODE

	/*Set RS Pin To LOW For Command*/
	DIO_u8SetPinValue( CLCD_CTRL_PORT , CLCD_RS_PIN , DIO_u8PIN_LOW ) ;

	/*Set RW Pin To LOW For Write*/
	DIO_u8SetPinValue( CLCD_CTRL_PORT , CLCD_RW_PIN , DIO_u8PIN_LOW ) ;

	/*Send Higher Four bits of Command To Data Pins*/
	DIO_u8SetPortValue( CLCD_DATA_PORT , (Copy_u8Command&0xF0) ) ;

	/*Send Enable Pulse for Higher Four Bits*/
	DIO_u8SetPinValue( CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_HIGH ) ;
	_delay_ms(2);
	DIO_u8SetPinValue( CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_LOW ) ;

	/*Send Lower Four bits of Command To Data Pins*/
	DIO_u8SetPortValue( CLCD_DATA_PORT , (Copy_u8Command<<4) ) ;

	/*Send Enable Pulse for Lower Four Bits*/
	DIO_u8SetPinValue( CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_HIGH ) ;
	_delay_ms(2);
	DIO_u8SetPinValue( CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_LOW ) ;

#endif
}


/*---------------------------------------------------------------------------------------*/


void CLCD_voidSendData( u8 Copy_u8Data )
{


#if LCD_MODE == LCD_8BIT_MODE

	/*Set RS Pin to HIGH For Data*/
	DIO_u8SetPinValue( CLCD_CTRL_PORT , CLCD_RS_PIN , DIO_u8PIN_HIGH ) ;

	/*Set RW Pin to LOW For Write*/
	DIO_u8SetPinValue( CLCD_CTRL_PORT , CLCD_RW_PIN , DIO_u8PIN_LOW ) ;

	/*Send  Data To Data Pins*/
	DIO_u8SetPortValue( CLCD_DATA_PORT , Copy_u8Data ) ;

	/*Send Enable Pulse*/
	DIO_u8SetPinValue( CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_HIGH ) ;
	_delay_ms(2);
	DIO_u8SetPinValue( CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_LOW ) ;



#elif LCD_MODE == LCD_4BIT_MODE

	/*Set RS Pin to HIGH For Data*/
	DIO_u8SetPinValue( CLCD_CTRL_PORT , CLCD_RS_PIN , DIO_u8PIN_HIGH ) ;

	/*Set RW Pin to LOW For Write*/
	DIO_u8SetPinValue( CLCD_CTRL_PORT , CLCD_RW_PIN , DIO_u8PIN_LOW ) ;

	/*Send Higher Four Bits of Data To Data Pins*/
	DIO_u8SetPortValue( CLCD_DATA_PORT , (Copy_u8Data&0xF0) ) ;

	/*Send Enable Pulse for Higher Four Bits*/
	DIO_u8SetPinValue( CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_HIGH ) ;
	_delay_ms(2);
	DIO_u8SetPinValue( CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_LOW ) ;

	/*Send Lower Four bits of Data To Data Pins*/
	DIO_u8SetPortValue( CLCD_DATA_PORT , (Copy_u8Data<<4) ) ;

	/*Send Enable Pulse for Lower Four Bits*/
	DIO_u8SetPinValue( CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_HIGH ) ;
	_delay_ms(2);
	DIO_u8SetPinValue( CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_LOW ) ;


#endif

}


/*---------------------------------------------------------------------------------------*/


u8 CLCD_u8SendString( const char *Copy_pcString )
{
	/*Check Error Variable To Check On Pointer If Equal NULL*/
	u8 Local_u8StateError = 0 ;

	/*Iterator To Loop Through String Elements*/
	u8 Local_u8Iterator = 0  ;

	/*Check On Pointer*/
	if( Copy_pcString != NULL )
	{
		/*Loop To Traverse Through String Elements*/
		while( Copy_pcString[Local_u8Iterator] != NULL_CHARACTER )
		{
			/*Send Piece Of Data On Data Pins*/
			CLCD_voidSendData( Copy_pcString[Local_u8Iterator] ) ;

			Local_u8Iterator++ ;
		}
	}
	else
	{
		Local_u8StateError = 1 ;
	}
	return Local_u8StateError ;
}


/*---------------------------------------------------------------------------------------*/

#if LCD_MODULE == LCD_20X4
u8 CLCD_u8GoToRowColumn( u8 Copy_u8RowPos , u8 Copy_u8ColumnPos )
{
	/*Store Address*/
	u8 Local_u8Address = 0 ;

	/*Check Error*/
	u8 Local_u8StateError = OK ;

	switch( Copy_u8RowPos )
	{
	case 0 : Local_u8Address = Copy_u8ColumnPos ; break;
	case 1 : Local_u8Address = Copy_u8ColumnPos + SECOND_LINE_START_ADDRESS ; break;
	case 2 : Local_u8Address = Copy_u8ColumnPos + THIRD_LINE_START_ADDRESS  ; break;
	case 3 : Local_u8Address = Copy_u8ColumnPos + FOURTH_LINE_START_ADRESS  ; break;
	default: Local_u8StateError = NOK ;
	}

	/*To Set DDRAM Address Set Bit Number 7 (128 decimal)*/
	CLCD_voidSendCommand( SET_DDRAM_ADDRESS + Local_u8Address ) ;

	return Local_u8StateError ;
}
#elif LCD_MODULE == LCD_16X2

u8 CLCD_u8GoToRowColumn( u8 Copy_u8RowPos , u8 Copy_u8ColumnPos )
{
	/*Store Address*/
	u8 Local_u8Address = 0 ;

	/*Check Error*/
	u8 Local_u8StateError = OK ;

	switch( Copy_u8RowPos )
	{
	case 0 : Local_u8Address = Copy_u8ColumnPos ; break;
	case 1 : Local_u8Address = Copy_u8ColumnPos + SECOND_LINE_START_ADDRESS ; break;
	default: Local_u8StateError = NOK ;
	}

	/*To Set DDRAM Address Set Bit Number 7 (128 decimal)*/
	CLCD_voidSendCommand( SET_DDRAM_ADDRESS + Local_u8Address ) ;

	return Local_u8StateError ;
}

#endif

/*---------------------------------------------------------------------------------------*/


u8 CLCD_u8StoreSpecialChar( u8* Copy_pu8Pattern , u8 Copy_u8PatternNumber )
{
	u8 Local_u8CGRAMAddress = 0 ;

	u8 Local_u8ErrorState = 0 ;

	u8 Local_u8Iterrator = 0 ;

	if( Copy_pu8Pattern != NULL  )
	{
		/*Calculate the CGRAM Address*/
		Local_u8CGRAMAddress = LOCATION_SIZE_IN_CGRAM * Copy_u8PatternNumber ;

		/*Send CGRAM Address to LCD with Set Bit 6 (64 decimal)*/
		CLCD_voidSendCommand( SET_CGRAM_ADDRESS + Local_u8CGRAMAddress ) ;

		/*Write Pattern Inside CGRAM Memory*/
		for( Local_u8Iterrator=0 ; Local_u8Iterrator < LOCATION_SIZE_IN_CGRAM ; Local_u8Iterrator++ )
		{
			CLCD_voidSendData( Copy_pu8Pattern[Local_u8Iterrator] );
		}

	}
	else
	{
		Local_u8ErrorState = 1 ;
	}
	return Local_u8ErrorState ;
}


/*---------------------------------------------------------------------------------------*/


void CLCD_voidWriteSpecialChar( u8 Copy_u8PatternNumber , u8 Copy_u8XPos , u8 Copy_u8YPos  )
{
	CLCD_u8GoToRowColumn(Copy_u8XPos,Copy_u8YPos);
	CLCD_voidSendData( Copy_u8PatternNumber );
}

/*---------------------------------------------------------------------------------------*/


void CLCD_voidWriteIntegerNumber( s32 Copy_s32Number , u8 Copy_u8XPos , u8 Copy_u8YPos )
{
	/*Array to Hold The Digits of The Number Separated*/
	static u8 Local_u8Arr[ MAX_NUMBER_OF_DIGITS_IN_S32 ]={ 0 };

	/*Iterator to Count Number of Digits in a Number*/
	u8 Local_u8NumOfDigits=0;

	/*Normal For Loop Iterator*/
	u8 Local_u8ForLoopIterator = 0;

	/*Take Copy From Number Before Dividing it*/
	s32 Local_s32CopyOfNumber = Copy_s32Number ;

	/*Go To Certain Position in DDRAM To Display Number*/
	CLCD_u8GoToRowColumn( Copy_u8XPos , Copy_u8YPos ) ;

	/*Check if Number is Negative , Multiply By -1 to Do Operations Correctly*/
	if( Copy_s32Number<0 )
	{
		/*NEGATIVE SIGN*/
		CLCD_voidSendData('-');
		Copy_s32Number = Copy_s32Number * -1 ;
	}

	/*Loop Terminates When Number equals zero*/
	while( Copy_s32Number!=0 )
	{
		/*Assign Every Digit From the Number in the array , Starting from the last digit to the first digit */
		Local_u8Arr[Local_u8NumOfDigits] = Copy_s32Number%10;

		/*Dividing Number By 10 Till Number equals zero*/
		Copy_s32Number = Copy_s32Number / 10 ;

		/*Count Number of Digits*/
		Local_u8NumOfDigits++;
	}

	/*To Have the Exact Number of Digits*/
	Local_u8NumOfDigits--;

	/*DISPLAY  NUMBER*/
	if( Local_s32CopyOfNumber>0 || Local_s32CopyOfNumber <0 )
	{
		for( Local_u8ForLoopIterator = 0 ; Local_u8ForLoopIterator <= Local_u8NumOfDigits ; Local_u8ForLoopIterator++ )
		{
			/*DISPLAY DIGITS STARTING FROM LAST DIGIT SAVED IN ARRAY WHICH IS THE FIRST DIGIT OF THE NUMBER*/
			CLCD_voidSendData( ZERO_ASCII + Local_u8Arr[ Local_u8NumOfDigits-Local_u8ForLoopIterator ] );
		}

	}
	else if( Local_s32CopyOfNumber==0 )
	{
		CLCD_voidSendData( ZERO_ASCII );
	}
}


/*---------------------------------------------------------------------------------------*/


void CLCD_voidClearScreen( void )
{
	CLCD_voidSendCommand( CLCD_CLEAR_DISPLAY );
}


/*---------------------------------------------------------------------------------------*/


void CLCD_WriteFloatingNumber( f32 Copy_f32Number , u8 Copy_u8NumberofDigitsAfterDecimal , u8 Copy_u8XPos , u8 Copy_u8YPos   )
{
	/*Array to hold Digits of the Floating Number*/
	static u8 NumberInDigits[8]={0};

	/*To Hold Number of Digits of Integer Part*/
	u8 Local_u8IntegerDigits = 0 ;

	/*To Hold Number of Digits of Floating Part*/
	u8 Local_u8FloatingDigits ;

	/*Loop Counter*/
	u8 Local_u8LoopCounter = 0 ;

	/*Divide Number into Two Parts*/

	/*Integer Part*/
	u32 IntegerPart = (u32)Copy_f32Number;

	/*Floating Part*/
	f32 FloatingPart = Copy_f32Number-IntegerPart ;

	/*Convert Floating Part to Decimal by multiplying it by expected number of digits after decimal point * 10 */
	u32 Floating = ( FloatingPart * Power(10,Copy_u8NumberofDigitsAfterDecimal) );

	/*Check if Integer Part equals zero*/
	if(IntegerPart==0)
	{
		/*Put Zero in First Location in Array*/
		NumberInDigits[ Local_u8IntegerDigits ] = 0 ;

		Local_u8IntegerDigits+=1;
	}

	/*Dividing Integer Part by 10 and getting Modulus of integer part by 10 and store it in Array*/
	while(IntegerPart!=0)
	{
		/*Store Last Digit in Integer Part in First Index of Array*/
		NumberInDigits[Local_u8IntegerDigits] = IntegerPart%10 ;

		/*Dividing Integer Part by 10 to get rid of last digit*/
		IntegerPart = IntegerPart / 10 ;

		Local_u8IntegerDigits++;
	}
	/*Barrier between Integer Part and Floating Part*/
	NumberInDigits[ Local_u8IntegerDigits ]= '.' ;

	/*Index of Floating Part Starts after space */
	Local_u8FloatingDigits = Local_u8IntegerDigits + 1 ;

	/*Get last Index related to Integer Part to Loop in For*/
	Local_u8IntegerDigits-=1;

	if(Floating==0)
	{
		NumberInDigits[ Local_u8FloatingDigits ] = 0 ;

		Local_u8FloatingDigits+=1;
	}
	while(Floating!=0)
	{
		/*Store Last Digit in Floating Part in First Index after space in Array*/
		NumberInDigits[Local_u8FloatingDigits] = Floating % 10 ;

		/*Dividing Floating Part by 10 to get rid of last digit*/
		Floating = Floating / 10 ;

		Local_u8FloatingDigits++;
	}

	/*Get Last Index related to Floating Part to loop in For loop*/
	Local_u8FloatingDigits-=1;

	CLCD_u8GoToRowColumn( Copy_u8XPos , Copy_u8YPos );


	for( Local_u8LoopCounter = 0 ; Local_u8LoopCounter <= Local_u8IntegerDigits ; Local_u8LoopCounter++ )
	{
		CLCD_voidSendData( ZERO_ASCII + NumberInDigits[ Local_u8IntegerDigits - Local_u8LoopCounter ] ) ;
	}

	CLCD_voidSendData('.') ;
	/*Start Condition : To Start From INdex after Space in array*/
	for( Local_u8LoopCounter = Local_u8IntegerDigits + 2 ; Local_u8LoopCounter <= Local_u8FloatingDigits ; Local_u8LoopCounter++ )
	{
		CLCD_voidSendData( ZERO_ASCII + NumberInDigits [ Local_u8FloatingDigits - Local_u8LoopCounter + Local_u8IntegerDigits + 2 ] ) ;
	}
}


/*---------------------------------------------------------------------------------------*/

u8 CLCD_ShiftDisplay( u8 Copy_u8ShiftingDirection )
{
	u8 Local_u8ErrorState = 0 ;

	/*Shifting Screen Command*/
	u8 Local_u8ShiftingCom = 0x18 ;

	/*POST CONFIGURATION*/
	if( Copy_u8ShiftingDirection == SHIFT_LEFT )
	{
		CLEAR_BIT( Local_u8ShiftingCom , RIGHT_LEFT_SHIFT_BIT ) ;
	}
	else if( Copy_u8ShiftingDirection == SHIFT_RIGHT )
	{
		SET_BIT( Local_u8ShiftingCom , RIGHT_LEFT_SHIFT_BIT ) ;
	}
	else
	{
		Local_u8ErrorState = 1 ;
	}

	CLCD_voidSendCommand( Local_u8ShiftingCom );

	return Local_u8ErrorState ;
}

/*Service Function*/
s32 Power ( u8 Base , u16 Power )
{
	u8 iterator =  0 ;

	u16 Res = 1 ;
	for( iterator=0 ; iterator<Power ; iterator++ )
	{
		Res = Res * Base ;
	}
	return Res ;
}
