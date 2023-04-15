/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   HAL 			      ***************************/
/*************                SWC :     SWITCH	              ***************************/
/*************                VERSION : 1.00		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

#include "../../4-LIB/STD_TYPES.h"

#include "../../1-MCAL/DIO/DIO_Interface.h"
#include "SW_Config.h"
#include "SW_Interface.h"
#include "SW_Private.h"

/*---------------------------------------------------------------------------------------*/

u8 SWITCH_u8Init( u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8PullType )
{
	/*CHECK ERROR STATE VARIABLE*/
	u8 Local_u8ErrorState = 0 ;

	if( Copy_u8Port <= DIO_u8PORTD && Copy_u8Pin <= DIO_u8Pin7 )
	{
		if( Copy_u8PullType == PULL_UP_RESISTOR )
		{
			/*INTERNAL PULL UP RESISTOR IN AVR*/
			/*SET PIN AS INPUT AND ENABLE PULL UP RESISTOR  */
			DIO_u8PinPullUpResistor( Copy_u8Port , Copy_u8Pin ) ;
		}
		else if ( Copy_u8PullType == PULL_DOWN_RESISTOR )
		{
			/*SET PIN AS INPUT ONLY*/
			DIO_u8SetPinDirection( Copy_u8Port , Copy_u8Pin , DIO_u8PIN_INPUT ) ;
		}
		else
		{
			Local_u8ErrorState = 1 ;
		}
	}
	else
	{
		Local_u8ErrorState = 1 ;
	}
	return Local_u8ErrorState ;
}

/*---------------------------------------------------------------------------------------*/

u8 SWITCH_u8PressedOrNot( u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8PullType )
{
	/*VARIABLE TO HOLD RETURN THROUGH POINTER (GetPinValue) FUNCTION*/
	u8 Local_u8PinValue = 0 ;

	/*VARIABLE TO HOLD SWITCH STATE TO RETURN IT*/
	u8 Local_u8SwitchState = SWITCH_NOT_PRESSED ;

	if( Copy_u8Port <= DIO_u8PORTD && Copy_u8Pin <= DIO_u8Pin7 )
	{
		if( Copy_u8PullType == PULL_UP_RESISTOR )
		{
			/*GET PIN REGISTER VALUE AND CHECK ON IT*/
			DIO_u8GetPinValue( Copy_u8Port , Copy_u8Pin , &Local_u8PinValue ) ;

			if( Local_u8PinValue == DIO_u8PIN_HIGH )
			{
				Local_u8SwitchState = SWITCH_NOT_PRESSED ;
			}
			else if( Local_u8PinValue == DIO_u8PIN_LOW )
			{
				/*Polling Until Switch is Released*/
				while( Local_u8PinValue == DIO_u8PIN_LOW  )
				{
					DIO_u8GetPinValue( Copy_u8Port , Copy_u8Pin , &Local_u8PinValue ) ;
				}
				Local_u8SwitchState = SWITCH_PRESSED ;
			}

		}
		else if( Copy_u8PullType == PULL_DOWN_RESISTOR )
		{
			/*GET PIN REGISTER VALUE AND CHECK ON IT*/
			DIO_u8GetPinValue( Copy_u8Port , Copy_u8Pin , &Local_u8PinValue ) ;
			if( Local_u8PinValue == DIO_u8PIN_HIGH )
			{
				/*Polling Until Switch is Released*/
				while( Local_u8PinValue == DIO_u8PIN_HIGH  )
				{
					DIO_u8GetPinValue( Copy_u8Port , Copy_u8Pin , &Local_u8PinValue ) ;
				}
				Local_u8SwitchState = SWITCH_PRESSED ;
			}
			else if( Local_u8PinValue == DIO_u8PIN_LOW )
			{
				Local_u8SwitchState = SWITCH_NOT_PRESSED ;
			}
		}

	}

	return Local_u8SwitchState ;
}

/*---------------------------------------------------------------------------------------*/

u8 SWITCH_u8PollingUntilSwitchPressed( u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8PullType )
{
	/*POLLING(BUSY WAITING) UNTIL SWITCH IS PRESSED*/
	u8 Local_u8SwitchState = SWITCH_NOT_PRESSED ;
	do
	{
		Local_u8SwitchState = SWITCH_u8PressedOrNot( Copy_u8Port , Copy_u8Pin , Copy_u8PullType );
	}while( Local_u8SwitchState == SWITCH_NOT_PRESSED ) ;

	return Local_u8SwitchState ;
}
