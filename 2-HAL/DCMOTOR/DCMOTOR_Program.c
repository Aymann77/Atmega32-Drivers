/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   HAL 			      ***************************/
/*************                SWC :     DC MOTOR	          ***************************/
/*************                VERSION : 1.00		          ***************************/
/*************                DATE : 29-9-2022		          ***************************/
/****************************************************************************************/
/****************************************************************************************/



#include "../../4-LIB/STD_TYPES.h"

#include "../../1-MCAL/DIO/DIO_Interface.h"
#include "DCMOTOR_Config.h"
#include "DCMOTOR_Interface.h"
#include "DCMOTOR_Private.h"


void DCMOTOR_voidInit( u8 Copy_u8Port , u8 Copy_u8RightToLeftPin , u8 Copy_u8LeftToRightPin )
{
	DIO_u8SetPinDirection( Copy_u8Port , Copy_u8LeftToRightPin , DIO_u8PIN_OUTPUT ) ;
	DIO_u8SetPinDirection( Copy_u8Port , Copy_u8RightToLeftPin , DIO_u8PIN_OUTPUT ) ;
}


void DCMOTOR_voidRotateCW( u8 Copy_u8Port , u8 Copy_u8RightToLeftPin , u8 Copy_u8LeftToRightPin  )
{
	/*Rotate CW*/
	DIO_u8SetPinValue( Copy_u8Port , Copy_u8RightToLeftPin , DIO_u8PIN_LOW ) ;
	DIO_u8SetPinValue( Copy_u8Port , Copy_u8LeftToRightPin , DIO_u8PIN_HIGH ) ;
}

void DCMOTOR_voidRotateCCW( u8 Copy_u8Port ,  u8 Copy_u8RightToLeftPin , u8 Copy_u8LeftToRightPin  )
{
	/*Rotate CCW*/
	DIO_u8SetPinValue( Copy_u8Port , Copy_u8LeftToRightPin , DIO_u8PIN_LOW ) ;
	DIO_u8SetPinValue( Copy_u8Port , Copy_u8RightToLeftPin , DIO_u8PIN_HIGH ) ;

}

void DCMOTOR_voidTurnOFF( u8 Copy_u8Port ,  u8 Copy_u8RightToLeftPin , u8 Copy_u8LeftToRightPin  )
{
	/*Turn Motor OFF*/
	DIO_u8SetPinValue( Copy_u8Port , Copy_u8LeftToRightPin , DIO_u8PIN_LOW ) ;
	DIO_u8SetPinValue( Copy_u8Port , Copy_u8RightToLeftPin , DIO_u8PIN_LOW ) ;
}
