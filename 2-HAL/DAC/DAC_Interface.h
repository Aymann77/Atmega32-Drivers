/*
 * DAC_Interface.h
 *
 *  Created on: Oct 29, 2022
 *      Author: moham
 */

#ifndef DAC_INTERFACE_H_
#define DAC_INTERFACE_H_


/*---------------------------------------------------------------------------------
 *
 *     NAME     : DAC_u8SetAnalogValue
 *     FUNCTION : SET ANALOG VALUE TO GET FROM DAC (R2R CIRCUIT)
 *     ARGUMENT : Copy_u32AnalogValue -> VALUE RANGE FROM  0 -> 5000 (VALUE IN MILLIVOLTS)
 *     RETURN   : U8 ERROR STATE TO CHECK IF USER PUT A VOLT IN THE SPECIFIED RANGE
 *
 *---------------------------------------------------------------------------------*/
u8 DAC_u8SetAnalogValue( u32 Copy_u32AnalogValue ) ;

#endif /* 2_HAL_DAC_DAC_INTERFACE_H_ */
