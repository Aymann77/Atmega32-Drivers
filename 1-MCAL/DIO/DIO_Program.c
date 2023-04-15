/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   MCAL			      ***************************/
/*************                SWC :     DIO		              ***************************/
/*************                VERSION : 1.00		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

/*---------------------------------------------------------------------------------------*/

#include "../../4-LIB/BIT_MATH.h"
#include "../../4-LIB/STD_TYPES.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "DIO_Register.h"

/*---------------------------------------------------------------------------------------*/

u8 DIO_u8SetPinDirection( u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Direction )
{
	u8 Local_u8StateError = 0 ;

	if( Copy_u8Port <= DIO_u8PORTD && Copy_u8Pin <= DIO_u8Pin7 && Copy_u8Direction == DIO_u8PIN_INPUT )
	{
		switch( Copy_u8Port )
		{
		case DIO_u8PORTA : CLEAR_BIT( DDRA_REG , Copy_u8Pin ) ; break ;
		case DIO_u8PORTB : CLEAR_BIT( DDRB_REG , Copy_u8Pin ) ; break ;
		case DIO_u8PORTC : CLEAR_BIT( DDRC_REG , Copy_u8Pin ) ; break ;
		case DIO_u8PORTD : CLEAR_BIT( DDRD_REG , Copy_u8Pin ) ; break ;
		default    : Local_u8StateError = 1          	      ; break ;
		}

	}
	else if(  Copy_u8Port <= DIO_u8PORTD && Copy_u8Pin <= DIO_u8Pin7 && Copy_u8Direction == DIO_u8PIN_OUTPUT )
	{
		switch( Copy_u8Port )
		{
		case DIO_u8PORTA : SET_BIT( DDRA_REG , Copy_u8Pin ) ; break ;
		case DIO_u8PORTB : SET_BIT( DDRB_REG , Copy_u8Pin ) ; break ;
		case DIO_u8PORTC : SET_BIT( DDRC_REG , Copy_u8Pin ) ; break ;
		case DIO_u8PORTD : SET_BIT( DDRD_REG , Copy_u8Pin ) ; break ;
		default    : Local_u8StateError = 1                 ; break ;
		}

	}
	else
	{
		Local_u8StateError = 1 ;
	}

	return Local_u8StateError ;
}

/*---------------------------------------------------------------------------------------*/

u8 DIO_u8SetPortDirection( u8 Copy_u8Port , u8 Copy_u8Direction )
{
	u8 Local_u8StateError = 0 ;

	switch( Copy_u8Port )
	{
	case DIO_u8PORTA : DDRA_REG = Copy_u8Direction ; break ;
	case DIO_u8PORTB : DDRB_REG = Copy_u8Direction ; break ;
	case DIO_u8PORTC : DDRC_REG = Copy_u8Direction ; break ;
	case DIO_u8PORTD : DDRD_REG = Copy_u8Direction ; break ;
	default    : Local_u8StateError = 1            ; break ;
	}
	return Local_u8StateError ;
}

/*---------------------------------------------------------------------------------------*/

u8 DIO_u8SetPinValue( u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value )
{
	u8 Local_u8StateError = 0 ;

	if( Copy_u8Port <= DIO_u8PORTD && Copy_u8Pin <= DIO_u8Pin7 && Copy_u8Value == DIO_u8PIN_LOW )
	{
		switch( Copy_u8Port )
		{
		case DIO_u8PORTA : CLEAR_BIT( PORTA_REG , Copy_u8Pin ) ; break ;
		case DIO_u8PORTB : CLEAR_BIT( PORTB_REG , Copy_u8Pin ) ; break ;
		case DIO_u8PORTC : CLEAR_BIT( PORTC_REG , Copy_u8Pin ) ; break ;
		case DIO_u8PORTD : CLEAR_BIT( PORTD_REG , Copy_u8Pin ) ; break ;
		default    : Local_u8StateError = 1                    ; break ;
		}

	}
	else if( Copy_u8Port <= DIO_u8PORTD && Copy_u8Pin <= DIO_u8Pin7 && Copy_u8Value == DIO_u8PIN_HIGH )
	{
		switch( Copy_u8Port )
		{
		case DIO_u8PORTA : SET_BIT( PORTA_REG , Copy_u8Pin ) ; break ;
		case DIO_u8PORTB : SET_BIT( PORTB_REG , Copy_u8Pin ) ; break ;
		case DIO_u8PORTC : SET_BIT( PORTC_REG , Copy_u8Pin ) ; break ;
		case DIO_u8PORTD : SET_BIT( PORTD_REG , Copy_u8Pin ) ; break ;
		default    : Local_u8StateError = 1                  ; break ;
		}

	}
	else
	{
		Local_u8StateError = 1 ;
	}

	return Local_u8StateError ;
}

/*---------------------------------------------------------------------------------------*/

u8 DIO_u8SetPortValue( u8 Copy_u8Port , u8 Copy_u8Value )
{
	u8 Local_u8StateError = 0 ;

	switch( Copy_u8Port )
	{
	case DIO_u8PORTA : PORTA_REG = Copy_u8Value ; break ;
	case DIO_u8PORTB : PORTB_REG = Copy_u8Value ; break ;
	case DIO_u8PORTC : PORTC_REG = Copy_u8Value ; break ;
	case DIO_u8PORTD : PORTD_REG = Copy_u8Value ; break ;
	default    : Local_u8StateError = 1         ; break ;
	}

	return Local_u8StateError ;
}

/*---------------------------------------------------------------------------------------*/

u8 DIO_u8GetPinValue( u8 Copy_u8Port , u8 Copy_u8Pin , u8* Copy_pu8Value )
{
	u8 Local_u8StateError = 0 ;

	if( Copy_u8Port <= DIO_u8PORTD && Copy_u8Pin <= DIO_u8Pin7 && Copy_pu8Value != NULL )
	{
		switch( Copy_u8Port )
		{
		case DIO_u8PORTA : *Copy_pu8Value = GET_BIT( PINA_REG , Copy_u8Pin ) ; break ;
		case DIO_u8PORTB : *Copy_pu8Value = GET_BIT( PINB_REG , Copy_u8Pin ) ; break ;
		case DIO_u8PORTC : *Copy_pu8Value = GET_BIT( PINC_REG , Copy_u8Pin ) ; break ;
		case DIO_u8PORTD : *Copy_pu8Value = GET_BIT( PIND_REG , Copy_u8Pin ) ; break ;
		default    : Local_u8StateError = 1                                  ; break ;
		}
	}
	else
	{
		Local_u8StateError = 1 ;
	}

	return Local_u8StateError ;
}

/*---------------------------------------------------------------------------------------*/

u8 DIO_u8PinPullUpResistor( u8 Copy_u8Port , u8 Copy_u8Pin )
{
	u8 Local_u8StateError = 0 ;

	if( Copy_u8Port <= DIO_u8PORTD && Copy_u8Pin <= DIO_u8Pin7 )
	{
		switch( Copy_u8Port )
		{
		case DIO_u8PORTA : CLEAR_BIT( DDRA_REG , Copy_u8Pin )   ; SET_BIT( PORTA_REG , Copy_u8Pin ) ; break ;
		case DIO_u8PORTB : CLEAR_BIT( DDRB_REG , Copy_u8Pin )   ; SET_BIT( PORTB_REG , Copy_u8Pin ) ; break ;
		case DIO_u8PORTC : CLEAR_BIT( DDRC_REG , Copy_u8Pin )   ; SET_BIT( PORTC_REG , Copy_u8Pin ) ; break ;
		case DIO_u8PORTD : CLEAR_BIT( DDRD_REG , Copy_u8Pin )   ; SET_BIT( PORTD_REG , Copy_u8Pin ) ; break ;
		default    : Local_u8StateError = 1                  ;                                        break ;
		}
	}
	else
	{
		Local_u8StateError = 1 ;
	}

	return Local_u8StateError ;
}

/*---------------------------------------------------------------------------------------*/

u8 DIO_u8PortPullUpResistor( u8 Copy_u8Port )
{
	u8 Local_u8StateError = 0 ;

	switch( Copy_u8Port )
	{
	case DIO_u8PORTA : DDRA_REG = DIO_u8PORT_INPUT    ; PORTA_REG = DIO_u8PORT_HIGH ; break ;
	case DIO_u8PORTB : DDRB_REG = DIO_u8PORT_INPUT    ; PORTA_REG = DIO_u8PORT_HIGH ; break ;
	case DIO_u8PORTC : DDRC_REG = DIO_u8PORT_INPUT    ; PORTA_REG = DIO_u8PORT_HIGH ; break ;
	case DIO_u8PORTD : DDRD_REG = DIO_u8PORT_INPUT    ; PORTA_REG = DIO_u8PORT_HIGH ; break ;
	default    : Local_u8StateError = 1         ;                                     break ;
	}

	return Local_u8StateError ;
}

/*---------------------------------------------------------------------------------------*/

u8 DIO_u8TogglePinValue( u8 Copy_u8Port , u8 Copy_u8Pin )
{
	u8 Local_u8StateError = 0 ;

	if( Copy_u8Port <= DIO_u8PORTD && Copy_u8Pin <= DIO_u8Pin7 )
	{
		switch( Copy_u8Port )
		{
		case DIO_u8PORTA : TOGGLE_BIT( PORTA_REG , Copy_u8Pin ) ; break ;
		case DIO_u8PORTB : TOGGLE_BIT( PORTB_REG , Copy_u8Pin ) ; break ;
		case DIO_u8PORTC : TOGGLE_BIT( PORTC_REG , Copy_u8Pin ) ; break ;
		case DIO_u8PORTD : TOGGLE_BIT( PORTD_REG , Copy_u8Pin ) ; break ;
		default    : Local_u8StateError = 1                     ; break ;
		}

	}
	else
	{
		Local_u8StateError = 1 ;
	}
	return Local_u8StateError ;
}

/*---------------------------------------------------------------------------------------*/

u8 DIO_u8TogglePortValue( u8 Copy_u8Port )
{
	u8 Local_u8StateError = 0 ;

	switch( Copy_u8Port )
	{
	case DIO_u8PORTA : PORTA_REG ^=(DIO_u8PORT_HIGH) ; break ;
	case DIO_u8PORTB : PORTB_REG ^=(DIO_u8PORT_HIGH) ; break ;
	case DIO_u8PORTC : PORTC_REG ^=(DIO_u8PORT_HIGH) ; break ;
	case DIO_u8PORTD : PORTD_REG ^=(DIO_u8PORT_HIGH) ; break ;
	default    : Local_u8StateError = 1              ; break ;
	}

	return Local_u8StateError ;
}

/*---------------------------------------------------------------------------------------*/
