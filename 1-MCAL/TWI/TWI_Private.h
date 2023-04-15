/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   MCAL  		          ***************************/
/*************                SWC :     TWI                   ***************************/
/*************                VERSION : 1.00		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

#ifndef TWI_PRIVATE_H_
#define TWI_PRIVATE_H_

#define START_ACK                       0x08 /* Start has been sent */
#define REP_START_ACK                   0x10 /* Repeated Start */
#define SLAVE_ADD_AND_WR_ACK            0x18 /* Master Transmit ( Slave Address + Write Request ) ACK */
#define MSTR_WR_BYTE_ACK                0x28 /* Master Transmit Data ACK */
#define SLAVE_ADD_AND_RD_ACK            0x40 /* Master Transmit ( Slave Address + Read Request ) ACK */
#define MSTR_RD_BYTE_WITH_ACK           0x50 /* Master Received Data With ACK */
#define MSTR_RD_BYTE_WITH_NACK          0x58 /* Master Received Data With NACK */
#define SLAVE_ADD_RCVD_RD_REQ           0xA8 /* Means That the Slave Address is Received With Read Req */
#define SLAVE_ADD_RCVD_WR_REQ           0x60 /* Means That the Slave Address is Received With Write Req */
#define SLAVE_DATA_RECEIVED             0x80 /* Means That the Byte is Received */
#define SLAVE_BYTE_TRANSMITTED          0xB8 /* Means That the Written Byte is Tranasmitted */

#define STATUS_BITS                     ( TWSR & 0xF8 )

#endif /* 1_MCAL_TWI_TWI_PRIVATE_H_ */
