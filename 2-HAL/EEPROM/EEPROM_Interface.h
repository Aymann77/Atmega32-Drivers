/*
 * EEPROM_Interface.h
 *
 *  Created on: Mar 15, 2023
 *      Author: moham
 */

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

/*******************************************************/
/**** 24C08  ->  8 Kbits  -> 8192 Bits -> 1024 Byte ****/
/*******************************************************/

void EEPROM_SendDataByte( u8 Copy_u8DataByte , u16 Copy_u16ByteAddress , u8 * Copy_pu8Errors ) ;


void EEPROM_ReadDataByte( u8 * Copy_pu8DataByte , u16 Copy_u16ByteAddress , u8 * Copy_pu8Errors ) ;


#endif /* 2_HAL_EEPROM_EEPROM_INTERFACE_H_ */
