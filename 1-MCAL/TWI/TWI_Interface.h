/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   MCAL  		          ***************************/
/*************                SWC :     TWI                   ***************************/
/*************                VERSION : 1.00		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

typedef enum
{
 NoError,
 StartConditionError,
 RepeatedStartError,
 SlaveAddressWithWriteError,
 SlaveAddressWithReadError,
 MasterWriteByteError,
 MasterReadByteError,
 SlaveReadByteError

}TWI_ErrorStatus;

/* NOTE : PASS 0 in the Slave Address Argument If Master will not be Addressed */
void TWI_voidInitMaster( u8 Copy_u8SlaveAddress ) ;

void TWI_voidInitSlave( u8 Copy_u8SlaveAddress ) ;

TWI_ErrorStatus TWI_SendStartCondition( void ) ;

TWI_ErrorStatus TWI_SendRepeatedStart( void ) ;

TWI_ErrorStatus TWI_SendSlaveAddressWithWrite( u8 Copy_u8SlaveAddress ) ;

TWI_ErrorStatus TWI_SendSlaveAddressWithRead( u8 Copy_u8SlaveAddress ) ;

TWI_ErrorStatus TWI_MasterWriteDataByte( u8 Copy_u8DataByte ) ;

TWI_ErrorStatus TWI_MasterReadDataByte( u8 * Copy_pu8ReceivedData ) ;

TWI_ErrorStatus TWI_SlaveReadDataByte( u8 * Copy_pu8ReceivedDataByte ) ;

void TWI_SlaveReadMatchAddress( void ) ;

void TWI_SendStopCondition( void ) ;

#endif /* 1_MCAL_TWI_TWI_INTERFACE_H_ */
