/*
 * DAC_Program.c
 *
 *  Created on: Oct 29, 2022
 *      Author: moham
 */

#include "../../4-LIB/STD_TYPES.h"
#include "../../4-LIB/BIT_MATH.h"

#include "../../1-MCAL/DIO/DIO_Interface.h"

#include "DAC_Config.h"
#include "DAC_Interface.h"


u8 DAC_u8SetAnalogValue( u32 Copy_u32AnalogValue )
{
	u8 Local_u8ErrorState = OK;

	u8 Local_u8DigitalValueOnPort = 0;

	if( Copy_u32AnalogValue >= 0  && Copy_u32AnalogValue <= 5000 )
	{
       Local_u8DigitalValueOnPort = MAP( 0 , 5000 , 0 , 255 , Copy_u32AnalogValue );
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	DIO_u8SetPortValue( DAC_PORT_NUMBER , Local_u8DigitalValueOnPort );

	return Local_u8ErrorState ;
}


