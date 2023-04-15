/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   MCAL 		          ***************************/
/*************                SWC :     SPI	                  ***************************/
/*************                VERSION : 1.00		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_


#define SPCR                     ( * ( volatile u8* ) 0x2D )  /* SPI Control Register */
#define SPSR                     ( * ( volatile u8* ) 0x2E )  /* SPI Status Register */
#define SPDR                     ( * ( volatile u8* ) 0x2F )  /* SPI Data Register */

/* SPCR REGISTER BITS */
#define SPCR_SPIE                           7  /* SPI Interrupt Enable */
#define SPCR_SPE                            6  /* SPI Enable */
#define SPCR_DORD                           5  /* Data Order */
#define SPCR_MSTR                           4  /* Master / Slave Select */
#define SPCR_CPOL                           3  /* Clock Polarity */
#define SPCR_CPHA                           2  /* Clock Phase */
#define SPCR_SPR1                           1  /* SPI Clock Rate Select Bit 1 */
#define SPCR_SPR0                           0  /* SPI Clock Rate Select Bit 0 */

/* SPSR REGISTER BITS */
#define SPSR_SPIF                           7  /* SPI Interrupt Flag */
#define SPSR_WCOL                           6  /* Write Collision Flag */
#define SPSR_SPI2X                          0  /* Double SPI Speed Bit */


#endif /* 1_MCAL_SPI_SPI_REGISTER_H_ */
