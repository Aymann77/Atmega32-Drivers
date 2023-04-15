/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   HAL 			      ***************************/
/*************                SWC :     LED		              ***************************/
/*************                VERSION : 1.00		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

#include "../../4-LIB/STD_TYPES.h"
#include "../../1-MCAL/DIO/DIO_Interface.h"
#include "LED_Config.h"
#include "LED_Interface.h"
#include "LED_Private.h"
/*---------------------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------------
 *
 *     NAME     : LED_u8Init
 *     FUNCTION : INTIALIZATION FOR SPECIFIC PIN IN A SPECIFIC PORT AS OUTPUT
 *     ARGUMENT : PORT NUMBER  , PIN NUMBER
 *     RETURN   : U8 ERROR STATE TO CHECK IF FUCTION WORKED CORRECT OR NOT
 *
 *---------------------------------------------------------------------------------*/
u8 LED_u8Init( u8 Copy_u8Port , u8 Copy_u8Pin )
{
	/* VARIABLE TO CHECK IF FUNTION WORKED CORRECTLY OR NOT */

	u8 Local_u8StateError = 0 ;
	if( Copy_u8Port <= DIO_u8PORTD && Copy_u8Pin <= DIO_u8Pin7 ) /* CHECK IF ARGUMENTS( PORT NUMBER & PIN NUMBER ) ARE VALID OR NOT */
	{
		/* SET PIN AS OUTPUT */
		DIO_u8SetPinDirection( Copy_u8Port , Copy_u8Pin , DIO_u8PIN_OUTPUT ) ;

	}
	else
	{
		Local_u8StateError = 1 ;
	}
	return Local_u8StateError ;
}


/*---------------------------------------------------------------------------------
 *
 *     NAME     : LED_u8StringInit
 *     FUNCTION : INTIALIZATION FOR SPECIFIC PORT AS OUTPUT
 *     ARGUMENT : PORT NUMBER
 *     RETURN   : U8 ERROR STATE TO CHECK IF FUCTION WORKED CORRECT OR NOT
 *
 *---------------------------------------------------------------------------------*/
u8 LED_u8StringInit( u8 Copy_u8Port )
{
	/* VARIABLE TO CHECK IF FUNTION WORKED CORRECTLY OR NOT */

	u8 Local_u8StateError = 0 ;
	if( Copy_u8Port <= DIO_u8PORTD )  /* CHECK IF ARGUMENTS( PORT NUMBER ) ARE VALID OR NOT */
	{
		DIO_u8SetPortDirection( Copy_u8Port , DIO_u8PORT_OUTPUT ) ;
	}
	else
	{
		Local_u8StateError = 1 ;
	}
	return Local_u8StateError ;
}


/*---------------------------------------------------------------------------------
 *
 *     NAME     : LED_u8ON
 *     FUNCTION : TURN ON SPECIFIC LED
 *     ARGUMENT : PORT NUMBER  , PIN NUMBER
 *     RETURN   : U8 ERROR STATE TO CHECK IF FUCTION WORKED CORRECT OR NOT
 *
 *---------------------------------------------------------------------------------*/
u8 LED_u8ON( u8 Copy_u8Port , u8 Copy_u8Pin )
{
	/* VARIABLE TO CHECK IF FUNTION WORKED CORRECTLY OR NOT */

	u8 Local_u8StateError = 0 ;
	if( Copy_u8Port <= DIO_u8PORTD && Copy_u8Pin <= DIO_u8Pin7 ) /* CHECK IF ARGUMENTS( PORT NUMBER & PIN NUMBER ) ARE VALID OR NOT */
	{
		DIO_u8SetPinValue( Copy_u8Port , Copy_u8Pin , DIO_u8PIN_HIGH ) ;
	}
	else
	{
		Local_u8StateError = 1 ;
	}
	return Local_u8StateError ;
}


/*---------------------------------------------------------------------------------
 *
 *     NAME     : LED_u8StringON
 *     FUNCTION : TURN ON SPECIFIC STRING OF LEDS
 *     ARGUMENT : PORT NUMBER
 *     RETURN   : U8 ERROR STATE TO CHECK IF FUCTION WORKED CORRECT OR NOT
 *
 *---------------------------------------------------------------------------------*/
u8 LED_u8StringON( u8 Copy_u8Port )
{
	/* VARIABLE TO CHECK IF FUNTION WORKED CORRECTLY OR NOT */

	u8 Local_u8StateError = 0 ;
	if( Copy_u8Port <= DIO_u8PORTD )  /* CHECK IF ARGUMENTS( PORT NUMBER ) ARE VALID OR NOT */
	{
		DIO_u8SetPortValue( Copy_u8Port , DIO_u8PORT_HIGH ) ;
	}
	else
	{
		Local_u8StateError = 1 ;
	}
	return Local_u8StateError ;
}


/*---------------------------------------------------------------------------------
 *
 *     NAME     : LED_u8OFF
 *     FUNCTION : TURN OFF SPECIFIC LED
 *     ARGUMENT : PORT NUMBER  , PIN NUMBER
 *     RETURN   : U8 ERROR STATE TO CHECK IF FUCTION WORKED CORRECT OR NOT
 *
 *---------------------------------------------------------------------------------*/
u8 LED_u8OFF( u8 Copy_u8Port , u8 Copy_u8Pin )
{
	/* VARIABLE TO CHECK IF FUNTION WORKED CORRECTLY OR NOT */

	u8 Local_u8StateError = 0 ;
	if( Copy_u8Port <= DIO_u8PORTD && Copy_u8Pin <= DIO_u8Pin7 )  /* CHECK IF ARGUMENTS( PORT NUMBER & PIN NUMBER ) ARE VALID OR NOT */
	{
		DIO_u8SetPinValue( Copy_u8Port , Copy_u8Pin , DIO_u8PIN_LOW ) ;
	}
	else
	{
		Local_u8StateError = 1 ;
	}
	return Local_u8StateError ;
}


/*---------------------------------------------------------------------------------
 *
 *     NAME     : LED_u8StringOFF
 *     FUNCTION : TURN OFF SPECIFIC STRING OF LEDS
 *     ARGUMENT : PORT NUMBER
 *     RETURN   : U8 ERROR STATE TO CHECK IF FUCTION WORKED CORRECT OR NOT
 *
 *---------------------------------------------------------------------------------*/
u8 LED_u8StringOFF( u8 Copy_u8Port )
{
	/* VARIABLE TO CHECK IF FUNTION WORKED CORRECTLY OR NOT */

	u8 Local_u8StateError = 0 ;
	if( Copy_u8Port <= DIO_u8PORTD ) /* CHECK IF ARGUMENTS( PORT NUMBER ) ARE VALID OR NOT */
	{
		DIO_u8SetPortValue( Copy_u8Port , DIO_u8PORT_LOW ) ;
	}
	else
	{
		Local_u8StateError = 1 ;
	}
	return Local_u8StateError ;
}


/*---------------------------------------------------------------------------------
 *
 *     NAME     : LED_u8Toggle
 *     FUNCTION : TOGGLE LED STATE IF OFF MAKE IT ON IF ON MAKE IT OFF
 *     ARGUMENT : PORT NUMBER , PIN NUMBER
 *     RETURN   : U8 ERROR STATE TO CHECK IF FUCTION WORKED CORRECT OR NOT
 *
 *---------------------------------------------------------------------------------*/
u8 LED_u8Toggle( u8 Copy_u8Port , u8 Copy_u8Pin )
{
	u8 Local_u8ErrorState = 0 ;
	if( Copy_u8Port <= DIO_u8PORTD && Copy_u8Pin <= DIO_u8Pin7 )
	{
		DIO_u8TogglePinValue( Copy_u8Port , Copy_u8Pin ) ;
	}
	else
	{
		Local_u8ErrorState = 1 ;
	}
	return Local_u8ErrorState ;
}

/*---------------------------------------------------------------------------------------*/


