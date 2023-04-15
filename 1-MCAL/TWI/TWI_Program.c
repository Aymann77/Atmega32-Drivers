/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   MCAL  		          ***************************/
/*************                SWC :     TWI                   ***************************/
/*************                VERSION : 1.00		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

#include "../../4-LIB/BIT_MATH.h"
#include "../../4-LIB/STD_TYPES.h"

#include "TWI_Config.h"
#include "TWI_Interface.h"
#include "TWI_Private.h"
#include "TWI_Register.h"


void TWI_voidInitMaster( u8 Copy_u8SlaveAddress )
{
	/* Set Clock Frequency to 100Kbps */

	/* Set TWBR to 2 */
	TWBR = 32 ;

	/* Clear the 2 Bits of TWPS */
	CLEAR_BIT( TWSR , TWSR_TWPS0 ) ;
	CLEAR_BIT( TWSR , TWSR_TWPS1 ) ;

	/* Initialize the Node address */
	if( Copy_u8SlaveAddress == 0 )
	{
		/* Master will not be Addressed */
	}
	else
	{
		/* Master will be Addressed */
		TWAR = ( Copy_u8SlaveAddress << 1 ) ;
	}
	/*Enable Master Generating Acknowledge Bit*/
	SET_BIT( TWCR , TWCR_TWEA ) ;
}

void TWI_voidInitSlave( u8 Copy_u8SlaveAddress )
{
	/* Initialize the Node address */
	TWAR = ( Copy_u8SlaveAddress << 1 ) ;

	/*Enable Slave Generating Acknowledge Bit*/
	SET_BIT( TWCR , TWCR_TWEA ) ;

}

TWI_ErrorStatus TWI_SendStartCondition( void )
{
	TWI_ErrorStatus Local_ErrorStatus = NoError ;

	/* Clear TWINT Flag , Enable TWI , Send Start Condition */
	TWCR = ( 1 << TWCR_TWINT ) | ( 1 << TWCR_TWEN ) | ( 1 << TWCR_TWSTA ) ;

	/* Wait Until the TWINT Flag is Raised Again */
	while( GET_BIT( TWCR , TWCR_TWINT ) == 0 ) ;

	/* Check the Operation Status in the Status Register */
	if( STATUS_BITS !=  START_ACK )
	{
		Local_ErrorStatus = StartConditionError ;
	}
	else
	{
		/* do nothing */
	}



	return Local_ErrorStatus ;
}

TWI_ErrorStatus TWI_SendRepeatedStart( void )
{

	TWI_ErrorStatus Local_ErrorStatus = NoError ;

	/* Clear TWINT Flag , Enable TWI , Send Start Condition */
	TWCR = ( 1 << TWCR_TWINT ) | ( 1 << TWCR_TWEN ) | ( 1 << TWCR_TWSTA ) ;

	/* Wait Until the TWINT Flag is Raised Again */
	while( GET_BIT( TWCR , TWCR_TWINT ) == 0 ) ;

	/* Check the Operation Status in the Status Register */
	if( STATUS_BITS !=  REP_START_ACK )
	{
		Local_ErrorStatus = RepeatedStartError ;
	}
	else
	{
		/* do nothing */
	}



	return Local_ErrorStatus ;
}

TWI_ErrorStatus TWI_SendSlaveAddressWithWrite( u8 Copy_u8SlaveAddress )
{
	TWI_ErrorStatus Local_ErrorStatus = NoError ;

	/* Set the Slave Address in 7 MSB in the Data Register */
	/* Set LSB to Zero For Write Request */
	TWDR = ( Copy_u8SlaveAddress << 1 ) ;

	/* Clear TWINT Flag , Enable TWI */
	TWCR = ( 1 << TWCR_TWINT ) | ( 1 << TWCR_TWEN ) ;

	while( GET_BIT( TWCR , TWCR_TWINT ) == 0 ) ;

	/* Check the Operation Status in the Status Register */
	if( STATUS_BITS !=  SLAVE_ADD_AND_WR_ACK )
	{
		Local_ErrorStatus = SlaveAddressWithWriteError ;
	}
	else
	{
		/* Do Noting */
	}
	return Local_ErrorStatus ;
}
TWI_ErrorStatus TWI_SendSlaveAddressWithRead( u8 Copy_u8SlaveAddress )
{
	TWI_ErrorStatus Local_ErrorStatus = NoError ;

	/* Set the Slave Address in 7 MSB in the Data Register */
	/* Set LSB to ONE For Read Request */
	TWDR = ( Copy_u8SlaveAddress << 1 ) ;
	SET_BIT( TWDR , TWDR_TWD0 ) ;

	/* Clear TWINT Flag , Enable TWI */
	TWCR = ( 1 << TWCR_TWINT ) | ( 1 << TWCR_TWEN ) ;

	while( GET_BIT( TWCR , TWCR_TWINT ) == 0 ) ;

	/* Check the Operation Status in the Status Register */
	if( STATUS_BITS !=  SLAVE_ADD_AND_RD_ACK )
	{
		Local_ErrorStatus = SlaveAddressWithReadError ;
	}
	else
	{
		/* Do Noting */
	}
	return Local_ErrorStatus ;
}
TWI_ErrorStatus TWI_MasterWriteDataByte( u8 Copy_u8DataByte )
{
	TWI_ErrorStatus Local_ErrorStatus = NoError ;

	/* Set Data To be Transmitted in Data Register */
	TWDR = Copy_u8DataByte ;

	/* Clear TWINT Flag , Enable TWI */
	TWCR = ( 1 << TWCR_TWINT ) | ( 1 << TWCR_TWEN ) ;

	while( GET_BIT( TWCR , TWCR_TWINT ) == 0 ) ;

	/* Check the Operation Status in the Status Register */
	if( STATUS_BITS !=  MSTR_WR_BYTE_ACK )
	{
		Local_ErrorStatus = MasterWriteByteError ;
	}
	else
	{
		/* Do Noting */
	}
	return Local_ErrorStatus ;

}

TWI_ErrorStatus TWI_SlaveReadDataByte( u8 * Copy_pu8ReceivedDataByte )
{
	TWI_ErrorStatus Local_ErrorStatus = NoError ;

	/* Clear TWINT Flag , Enable TWI , Enable ACK */
	TWCR = ( 1 << TWCR_TWINT ) | ( 1 << TWCR_TWEN ) | ( 1 << TWCR_TWEA )  ;

	/* Wait Until Flag is Set */
	while( GET_BIT( TWCR ,TWCR_TWINT ) == 0 ) ;

	if( STATUS_BITS != SLAVE_DATA_RECEIVED )
	{
		Local_ErrorStatus = SlaveReadByteError ;
	}
	else
	{

	}
	*Copy_pu8ReceivedDataByte = TWDR ;

	return Local_ErrorStatus ;
}

void TWI_SlaveReadMatchAddress( void )
{
	while( STATUS_BITS != SLAVE_ADD_RCVD_WR_REQ )
	{
		/* Clear TWINT Flag , Enable TWI , Enable ACK */
		TWCR = ( 1 << TWCR_TWINT ) | ( 1 << TWCR_TWEN ) | ( 1 << TWCR_TWEA )  ;

		/* Wait Until Flag is Set */
		while( GET_BIT( TWCR ,TWCR_TWINT ) == 0 ) ;

	}


}

TWI_ErrorStatus TWI_MasterReadDataByte( u8 * Copy_pu8ReceivedData )
{
	TWI_ErrorStatus Local_ErrorStatus = NoError ;

	/* By Clearing Flag we give Permission to the Slave to Send Data */
	/* Clear TWINT Flag , Enable TWI */
	TWCR = ( 1 << TWCR_TWINT ) | ( 1 << TWCR_TWEN ) ;

	/* Wait Until Slave Transmit Data and Flag is Raised */
	while( GET_BIT( TWCR , TWCR_TWINT ) == 0 ) ;

	if( STATUS_BITS != MSTR_RD_BYTE_WITH_ACK )
	{
		Local_ErrorStatus = MasterReadByteError ;
	}
	else
	{

	}
	/* Master Read the Received Data */
	*Copy_pu8ReceivedData = TWDR ;
	return Local_ErrorStatus ;
}
void TWI_SendStopCondition( void )
{
	/* Clear TWINT Flag , Send Stop Condition , Enable TWI */
	TWCR = ( 1 << TWCR_TWINT ) | ( 1 << TWCR_TWSTO ) | ( 1 << TWCR_TWEN ) ;
}
