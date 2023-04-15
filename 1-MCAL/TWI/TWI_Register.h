/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   MCAL  		          ***************************/
/*************                SWC :     TWI                   ***************************/
/*************                VERSION : 1.00		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

#ifndef TWI_REGISTER_H_
#define TWI_REGISTER_H_

#define TWBR               *(  ( volatile u8 * ) 0x20 )  /* TWI Bit Rate Register */
#define TWCR               *(  ( volatile u8 * ) 0x56 )  /* TWI Control Register */
#define TWSR               *(  ( volatile u8 * ) 0x21 )  /* TWI Status Register */
#define TWDR               *(  ( volatile u8 * ) 0x23 )  /* TWI Data Register */
#define TWAR               *(  ( volatile u8 * ) 0x22 )  /* TWI ( Slave ) Address Register */

/* TWCR BITS */
#define TWCR_TWINT                    7  /* TWI Interrupt Flag */
#define TWCR_TWEA                     6  /* TWI Enable Acknowledge Bit */
#define TWCR_TWSTA                    5  /* TWI Start Condition Bit */
#define TWCR_TWSTO                    4  /* TWI Stop Condition Bit */
#define TWCR_TWWC                     3  /* TWI Write Colision Flag */
#define TWCR_TWEN                     2  /* TWI Enable Bit */
#define TWCR_TWIE                     0  /* TWI Interrupt Enable */


/* TWSR BITS */
#define TWSR_TWS7                     7  /* TWI Status Bit 7 */
#define TWSR_TWS6                     6  /* TWI Status Bit 6 */
#define TWSR_TWS5                     5  /* TWI Status Bit 5 */
#define TWSR_TWS4                     4  /* TWI Status Bit 4 */
#define TWSR_TWS3                     3  /* TWI Status Bit 3 */
#define TWSR_TWPS1                    1  /* TWI Prescaler Bit 1 */
#define TWSR_TWPS0                    0  /* TWI Prescaler Bit 0 */


/* TWAR BITS */
#define TWAR_TWA6                     7  /* TWI ( Slave ) Address Bit 6 */
#define TWAR_TWA5                     6  /* TWI ( Slave ) Address Bit 5 */
#define TWAR_TWA4                     5  /* TWI ( Slave ) Address Bit 4 */
#define TWAR_TWA3                     4  /* TWI ( Slave ) Address Bit 3 */
#define TWAR_TWA2                     3  /* TWI ( Slave ) Address Bit 2 */
#define TWAR_TWA1                     2  /* TWI ( Slave ) Address Bit 1 */
#define TWAR_TWA0                     1  /* TWI ( Slave ) Address Bit 0 */
#define TWAR_TWCGE                    0  /* TWI General Call Recognition Enable */


/* TWDR BITS */
#define TWDR_TWD7                     7
#define TWDR_TWD6                     6
#define TWDR_TWD5                     5
#define TWDR_TWD4                     4
#define TWDR_TWD3                     3
#define TWDR_TWD2                     2
#define TWDR_TWD1                     1
#define TWDR_TWD0                     0
#endif /* 1_MCAL_TWI_TWI_REGISTER_H_ */
