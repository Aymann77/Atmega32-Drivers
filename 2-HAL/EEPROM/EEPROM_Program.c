/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   			          ***************************/
/*************                SWC :     	                  ***************************/
/*************                VERSION : 1.00		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

#include "../../4-LIB/STD_TYPES.h"
#include "../../4-LIB/BIT_MATH.h"

#include "../../1-MCAL/TWI/TWI_Interface.h"

#include "EEPROM_Private.h"
#include "EEPROM_Config.h"
#include "EEPROM_Interface.h"


void EEPROM_SendDataByte( u8 Copy_u8DataByte , u16 Copy_u16ByteAddress , u8 * Copy_pu8Errors )
{
	/* Master Send Start Condition */
	*( Copy_pu8Errors + 0 ) = TWI_SendStartCondition( ) ;

	/* Send 7Bits Slave Address ( 1010_A2PinConfig_2MSBinByteAddress ) + Write Request */
	*( Copy_pu8Errors + 1 ) = TWI_SendSlaveAddressWithWrite( ( ( u8 )(0x50) | ( A2_HARD_WIRED_CONNECTION << 2 ) | ( Copy_u16ByteAddress >> 8 ) ) ) ;

	/* Send the Rest of the Address ( 8 LSB in Byte Address ) */
	*( Copy_pu8Errors + 2 ) = TWI_MasterWriteDataByte( ( u8 ) Copy_u16ByteAddress ) ;

	/* Send the Data Byte to Be Written in the EEPROM */
	*( Copy_pu8Errors + 3 ) = TWI_MasterWriteDataByte( Copy_u8DataByte ) ;

	/* Send Stop Condition */
	TWI_SendStopCondition(  ) ;
}

void EEPROM_ReadDataByte( u8 * Copy_pu8DataByte , u16 Copy_u16ByteAddress , u8 * Copy_pu8Errors )
{
	/* Master Send Start Condition */
	*( Copy_pu8Errors + 0 ) = TWI_SendStartCondition( ) ;

	/* Send 7Bits Slave Address ( 1010_A2PinConfig_2MSBinByteAddress ) + Write Request to Send the Rest of the Addres in the Next Packet */
	*( Copy_pu8Errors + 1 ) = TWI_SendSlaveAddressWithWrite( ( ( u8 )(0x50) | ( A2_HARD_WIRED_CONNECTION << 2 ) | ( Copy_u16ByteAddress >> 8 ) ) ) ;

	/* Send the Rest of the Address ( 8 LSB in Byte Address ) */
	*( Copy_pu8Errors + 2 ) = TWI_MasterWriteDataByte( ( u8 ) Copy_u16ByteAddress ) ;

	/* Send Repeated Start to Change To Read Request */
	*( Copy_pu8Errors + 3 ) = TWI_SendRepeatedStart(  ) ;

	/* Send the Same 7 Bits Slave Address as Above + Read Request */
	*( Copy_pu8Errors + 4 ) = TWI_SendSlaveAddressWithRead( ( ( u8 )(0x50) | ( A2_HARD_WIRED_CONNECTION << 2 ) | ( Copy_u16ByteAddress >> 8 ) ) ) ;

	/* Read Data From EEPROM */
	*( Copy_pu8Errors + 5 ) = TWI_MasterReadDataByte( Copy_pu8DataByte ) ;

	/* Send Stop Condition */
	TWI_SendStopCondition(  ) ;

}
