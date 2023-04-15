/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   HAL 			      ***************************/
/*************                SWC :     STEPPER	              ***************************/
/*************                VERSION : 1.00		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

#include "../../4-LIB/STD_TYPES.h"
#include "util/delay.h"

#include "../../1-MCAL/DIO/DIO_Interface.h"
#include "STEPPER_Config.h"
#include "STEPPER_Interface.h"
#include "STEPPER_Private.h"


void STEPPER_Init( u8 Copy_u8Port , u8 Copy_u8BluePin , u8 Copy_u8PinkPin , u8 Copy_u8YellowPin , u8 Copy_u8OrangePin  )
{
	DIO_u8SetPinDirection( Copy_u8Port , Copy_u8BluePin , DIO_u8PIN_OUTPUT ) ;
	DIO_u8SetPinDirection( Copy_u8Port , Copy_u8PinkPin , DIO_u8PIN_OUTPUT ) ;
	DIO_u8SetPinDirection( Copy_u8Port , Copy_u8YellowPin , DIO_u8PIN_OUTPUT ) ;
	DIO_u8SetPinDirection( Copy_u8Port , Copy_u8OrangePin , DIO_u8PIN_OUTPUT ) ;
}


void STEPPER_GoForward(  u8 Copy_u8Port , u8 Copy_u8BluePin , u8 Copy_u8PinkPin , u8 Copy_u8YellowPin , u8 Copy_u8OrangePin , u32 Copy_u32Steps )
{
	u32 Local_u32Iterator = 0 ;
	for( Local_u32Iterator=0 ; Local_u32Iterator < Copy_u32Steps ; Local_u32Iterator++ )
	{
		DIO_u8SetPinValue( Copy_u8Port , Copy_u8BluePin   , DIO_u8PIN_LOW   ) ;
		DIO_u8SetPinValue( Copy_u8Port , Copy_u8PinkPin   , DIO_u8PIN_HIGH  ) ;
		DIO_u8SetPinValue( Copy_u8Port , Copy_u8YellowPin , DIO_u8PIN_HIGH  ) ;
		DIO_u8SetPinValue( Copy_u8Port , Copy_u8OrangePin , DIO_u8PIN_HIGH  ) ;

		_delay_ms( 2 ) ;

		DIO_u8SetPinValue( Copy_u8Port , Copy_u8BluePin   , DIO_u8PIN_HIGH  ) ;
		DIO_u8SetPinValue( Copy_u8Port , Copy_u8PinkPin   , DIO_u8PIN_LOW   ) ;
		DIO_u8SetPinValue( Copy_u8Port , Copy_u8YellowPin , DIO_u8PIN_HIGH  ) ;
		DIO_u8SetPinValue( Copy_u8Port , Copy_u8OrangePin , DIO_u8PIN_HIGH  ) ;

		_delay_ms( 2 ) ;

		DIO_u8SetPinValue( Copy_u8Port , Copy_u8BluePin   , DIO_u8PIN_HIGH  ) ;
		DIO_u8SetPinValue( Copy_u8Port , Copy_u8PinkPin   , DIO_u8PIN_HIGH  ) ;
		DIO_u8SetPinValue( Copy_u8Port , Copy_u8YellowPin , DIO_u8PIN_LOW   ) ;
		DIO_u8SetPinValue( Copy_u8Port , Copy_u8OrangePin , DIO_u8PIN_HIGH  ) ;

		_delay_ms( 2 ) ;

		DIO_u8SetPinValue( Copy_u8Port , Copy_u8BluePin   , DIO_u8PIN_HIGH  ) ;
		DIO_u8SetPinValue( Copy_u8Port , Copy_u8PinkPin   , DIO_u8PIN_HIGH  ) ;
		DIO_u8SetPinValue( Copy_u8Port , Copy_u8YellowPin , DIO_u8PIN_HIGH  ) ;
		DIO_u8SetPinValue( Copy_u8Port , Copy_u8OrangePin , DIO_u8PIN_LOW   ) ;

		_delay_ms( 2 ) ;
	}
}


void STEPPER_GoBackward(  u8 Copy_u8Port , u8 Copy_u8BluePin , u8 Copy_u8PinkPin , u8 Copy_u8YellowPin , u8 Copy_u8OrangePin , u32 Copy_u32Steps )
{
	u32 Local_u32Iterator = 0 ;
	for( Local_u32Iterator=0 ; Local_u32Iterator < Copy_u32Steps ; Local_u32Iterator++ )
	{
		DIO_u8SetPinValue( Copy_u8Port , Copy_u8BluePin   , DIO_u8PIN_HIGH   ) ;
		DIO_u8SetPinValue( Copy_u8Port , Copy_u8PinkPin   , DIO_u8PIN_HIGH  ) ;
		DIO_u8SetPinValue( Copy_u8Port , Copy_u8YellowPin , DIO_u8PIN_HIGH  ) ;
		DIO_u8SetPinValue( Copy_u8Port , Copy_u8OrangePin , DIO_u8PIN_LOW  ) ;

		_delay_ms( 2 ) ;

		DIO_u8SetPinValue( Copy_u8Port , Copy_u8BluePin   , DIO_u8PIN_HIGH  ) ;
		DIO_u8SetPinValue( Copy_u8Port , Copy_u8PinkPin   , DIO_u8PIN_HIGH   ) ;
		DIO_u8SetPinValue( Copy_u8Port , Copy_u8YellowPin , DIO_u8PIN_LOW  ) ;
		DIO_u8SetPinValue( Copy_u8Port , Copy_u8OrangePin , DIO_u8PIN_HIGH  ) ;

		_delay_ms( 2 ) ;

		DIO_u8SetPinValue( Copy_u8Port , Copy_u8BluePin   , DIO_u8PIN_HIGH  ) ;
		DIO_u8SetPinValue( Copy_u8Port , Copy_u8PinkPin   , DIO_u8PIN_LOW  ) ;
		DIO_u8SetPinValue( Copy_u8Port , Copy_u8YellowPin , DIO_u8PIN_HIGH   ) ;
		DIO_u8SetPinValue( Copy_u8Port , Copy_u8OrangePin , DIO_u8PIN_HIGH  ) ;

		_delay_ms( 2 ) ;

		DIO_u8SetPinValue( Copy_u8Port , Copy_u8BluePin   , DIO_u8PIN_LOW  ) ;
		DIO_u8SetPinValue( Copy_u8Port , Copy_u8PinkPin   , DIO_u8PIN_HIGH  ) ;
		DIO_u8SetPinValue( Copy_u8Port , Copy_u8YellowPin , DIO_u8PIN_HIGH  ) ;
		DIO_u8SetPinValue( Copy_u8Port , Copy_u8OrangePin , DIO_u8PIN_HIGH   ) ;

		_delay_ms( 2 ) ;
	}
}


void STEPPER_TurnOFF( u8 Copy_u8Port , u8 Copy_u8BluePin , u8 Copy_u8PinkPin , u8 Copy_u8YellowPin , u8 Copy_u8OrangePin  )
{
	DIO_u8SetPinValue( Copy_u8Port , Copy_u8BluePin   , DIO_u8PIN_HIGH  ) ;
	DIO_u8SetPinValue( Copy_u8Port , Copy_u8PinkPin   , DIO_u8PIN_HIGH  ) ;
	DIO_u8SetPinValue( Copy_u8Port , Copy_u8YellowPin , DIO_u8PIN_HIGH  ) ;
	DIO_u8SetPinValue( Copy_u8Port , Copy_u8OrangePin , DIO_u8PIN_HIGH   ) ;
}

/*Direction is Set By H.W*/
/*Using A4988 Driver*/
void STEPPER_NEMA17_Control( u8 Copy_u8ControlPort , u8 Copy_u8ControlPin , u16 Copy_u16Degree )
{
   u16 Local_u16NumberOfPulses = 0 ;

   u16 Local_u16LoopCounter = 0 ;

   Local_u16NumberOfPulses = (u16)( Copy_u16Degree / NEMA_17_STEP_ANGLE ) ; /* 1.8 Stepper Motor Step Angle */

   for( Local_u16LoopCounter = 0 ; Local_u16LoopCounter <= Local_u16NumberOfPulses ; Local_u16LoopCounter++  )
   {
          DIO_u8SetPinValue( Copy_u8ControlPort , Copy_u8ControlPin , DIO_u8PIN_HIGH );        /* For 1900 Frequency */
          _delay_us( 526 ) ;
          DIO_u8SetPinValue( Copy_u8ControlPort , Copy_u8ControlPin , DIO_u8PIN_LOW );
          _delay_us( 526 ) ;
   }
}

