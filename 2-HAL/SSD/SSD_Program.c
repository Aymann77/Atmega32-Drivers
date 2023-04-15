/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   HAL 			      ***************************/
/*************                SWC :     SSD		              ***************************/
/*************                VERSION : 1.00		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

/*---------------------------------------------------------------------------------------*/

#include "../../4-LIB/STD_TYPES.h"
#include "../../1-MCAL/DIO/DIO_Interface.h"
#include "SSD_Config.h"
#include "SSD_Interface.h"
#include "SSD_Private.h"

/*---------------------------------------------------------------------------------------*/

u8 SSD_arru8SevSegNumbers [] ={ ZERO , ONE , TWO , THREE , FOUR , FIVE , SIX , SEVEN , EIGHT , NINE };

/*---------------------------------------------------------------------------------------*/


u8 SSD_Init( u8 Copy_u8Port )
{
	u8 Local_u8StateError = 0 ;
	if( Copy_u8Port <= DIO_u8PORTD )
	{
		DIO_u8SetPortDirection( Copy_u8Port , DIO_u8PORT_OUTPUT ) ;
	}
	else
	{
		Local_u8StateError = 1 ;
	}
	return Local_u8StateError ;
}


/*---------------------------------------------------------------------------------------*/

u8 SSD_MUXInit( u8 Copy_u8Port ,u8 Copy_u8EnablePort , u8 Copy_u8EnablePin )
{
	u8 Local_u8StateError = 0 ;
	if( Copy_u8Port <= DIO_u8PORTD && Copy_u8EnablePort <= DIO_u8PORTD && Copy_u8EnablePin <= DIO_u8Pin7 )
	{
		DIO_u8SetPortDirection( Copy_u8Port , DIO_u8PORT_OUTPUT ) ;
		DIO_u8SetPinDirection( Copy_u8EnablePort , Copy_u8EnablePin , DIO_u8PIN_OUTPUT ) ;
	}
	else
	{
		Local_u8StateError = 1 ;
	}
	return Local_u8StateError ;
}


/*---------------------------------------------------------------------------------------*/

u8 SSD_MuxAddInit( u8 Copy_u8EnablePort , u8 Copy_u8EnablePin )
{
	u8 Local_u8StateError = 0 ;
	if( Copy_u8EnablePort <=DIO_u8PORTD && Copy_u8EnablePin <= DIO_u8Pin7 )
	{
		DIO_u8SetPinDirection( Copy_u8EnablePort , Copy_u8EnablePin , DIO_u8PIN_OUTPUT );
	}
	else
	{
		Local_u8StateError = 1 ;
	}
	return Local_u8StateError ;
}


/*---------------------------------------------------------------------------------------*/

u8 SSD_DisplayNumber ( u8 Copy_u8Port , u8 Copy_u8Number )
{
	u8 Local_u8StateError = 0 ;
	if( Copy_u8Port <= DIO_u8PORTD )
	{
		DIO_u8SetPortValue( Copy_u8Port , SSD_arru8SevSegNumbers[Copy_u8Number] );
	}
	else
	{
		Local_u8StateError = 1 ;
	}
	return Local_u8StateError ;
}


/*---------------------------------------------------------------------------------------*/

u8 SSD_MuxEnableCom ( u8 Copy_u8EnablePort , u8 Copy_u8EnablePin )
{
	u8 Local_u8StateError = 0 ;
	if( Copy_u8EnablePort <= DIO_u8PORTD && Copy_u8EnablePin <= DIO_u8Pin7 )
	{
#if SSD_u8COM_TYPE == COM_ANODE
		DIO_u8SetPinValue( Copy_u8EnablePort , Copy_u8EnablePin , DIO_u8PIN_HIGH ) ;
#elif SSD_u8COM_TYPE == COM_CATHODE
		DIO_u8SetPinValue( Copy_u8EnablePort , Copy_u8EnablePin , DIO_u8PIN_LOW ) ;
#endif
	}
	else
	{
		Local_u8StateError = 1 ;
	}
	return Local_u8StateError ;
}


/*---------------------------------------------------------------------------------------*/

u8 SSD_MuxDisableCom ( u8 Copy_u8EnablePort , u8 Copy_u8EnablePin )
{
	u8 Local_u8StateError = 0 ;
	if( Copy_u8EnablePort <= DIO_u8PORTD && Copy_u8EnablePin <= DIO_u8Pin7 )
	{
#if SSD_u8COM_TYPE == COM_ANODE
		DIO_u8SetPinValue( Copy_u8EnablePort , Copy_u8EnablePin , DIO_u8PIN_LOW ) ;
#elif SSD_u8COM_TYPE == COM_CATHODE
		DIO_u8SetPinValue( Copy_u8EnablePort , Copy_u8EnablePin , DIO_u8PIN_HIGH ) ;
#endif
	}
	else
	{
		Local_u8StateError = 1 ;
	}
	return Local_u8StateError ;
}


/*---------------------------------------------------------------------------------------*/


/*
u8 SSD_DiplayRange1Sec ( u8 Copy_u8PortSevSeg1 , u8 Copy_u8PortSevSeg2 , u8 Copy_u8StartNumber , u8 Copy_u8EndNumber )
{
	u8 Local_u8StateError = 0 ;
	u8 Local_u8Itterator1 = 0 , Local_u8Itterator2 = 0 ;
	u8 Local_u8Number1Part1 = 0 , Local_u8Number1Part2 = 0 ;

	u8 Local_u8MaxItterator1 = 0 , Local_u8MaxItterator2= 0 ;

	u8 Local_u8Number2Part1 = 0 , Local_u8Number2Part2 = 0 ;
	if( Copy_u8PortSevSeg1 <= DIO_u8PORTD && Copy_u8PortSevSeg2 <= DIO_u8PORTD )
	{
		if( Copy_u8StartNumber < Copy_u8EndNumber )
		{
			Local_u8Number1Part2 = Copy_u8StartNumber % 10 ;
			Local_u8Number2Part2 = Copy_u8EndNumber %10 ;

			if( Local_u8Number1Part2 !=0 )
			{
				Local_u8Itterator2 = Local_u8Number1Part2 ;
				Copy_u8StartNumber = Copy_u8StartNumber - Local_u8Number1Part2 ;
				Local_u8Number1Part1 = Copy_u8StartNumber / 10 ;
				Local_u8Itterator1 = Local_u8Number1Part1 ;
			}
			if(  Local_u8Number2Part2 !=0 )
			{
				Local_u8MaxItterator2 = Local_u8Number2Part2 ;
				Copy_u8EndNumber = Copy_u8EndNumber - Local_u8Number2Part2 ;
				Local_u8Number2Part1 = Copy_u8StartNumber / 10 ;
				Local_u8MaxItterator1 = Local_u8Number2Part1 ;
			}

			for( Local_u8Itterator1=Local_u8Number1Part1 ;Local_u8Itterator1 <= Local_u8MaxItterator1 ; Local_u8Itterator1++ )
			{
				DIO_u8SetPortValue( Copy_u8PortSevSeg1 , SSD_arru8SevSegNumbers[Local_u8Itterator1]  );
				for( Local_u8Itterator2=Local_u8Number1Part2 ;Local_u8Itterator2 <= 9 ; Local_u8Itterator2++ )
				{
					DIO_u8SetPortValue( Copy_u8PortSevSeg2 , SSD_arru8SevSegNumbers[Local_u8Itterator2]  );
				}
			}

		}
	}
}
*/
