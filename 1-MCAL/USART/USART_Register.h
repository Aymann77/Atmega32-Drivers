/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   MCAL			      ***************************/
/*************                SWC :     USART	              ***************************/
/*************                VERSION : 1.00		          ***************************/
/****************************************************************************************/
/****************************************************************************************/
#ifndef  _USART_REGISTER_H_
#define  _USART_REGISTER_H_


#define UDR                       *( ( volatile u8 * ) 0x2C )  /* USART I/O Data Register */

#define UCSRA                     *( ( volatile u8 * ) 0x2B )  /* USART Control & Status Register A */
#define UCSRB                     *( ( volatile u8 * ) 0x2A )  /* USART Control & Status Register B */
#define UCSRC                     *( ( volatile u8 * ) 0x40 )  /* USART Control & Status Register C */

#define UBRRH                     *( ( volatile u8 * ) 0x40 )  /* USART Baud Rate Register H */
#define UBRRL                     *( ( volatile u8 * ) 0x29 )  /* USART Baud Rate Register L */


/* UCSRA Register Bits */
#define UCSRA_RXC                  7  /* USART Receive Complete Flag */
#define UCSRA_TXC                  6  /* USART Transmit Complete Flag */
#define UCSRA_UDRE                 5  /* USART Data Register Empty Flag */
#define UCSRA_FE                   4  /* Frame Error */
#define UCSRA_DOR                  3  /* Data OverRun */
#define UCSRA_PE                   2  /* Parity Error */
#define UCSRA_U2X                  1  /* Double the USART Transmission Speed */
#define UCSRA_MPCM                 0  /* Multi-processor Communication Mode */


/* UCSRB Register Bits */
#define UCSRB_RXCIE                7  /* Receive Complete Interrupt Enable */
#define UCSRB_TXCIE                6  /* Transmit Complete Interrupt Enable */
#define UCSRB_UDRIE                5  /* USART Data Register Empty Interrupt Enable */
#define UCSRB_RXEN                 4  /* Receiver Enable */
#define UCSRB_TXEN                 3  /* Transmitter Enable */
#define UCSRB_UCSZ2                2  /* Character Size Bit 2 */
#define UCSRB_RXB8                 1  /* Receive Data Bit 8 */
#define UCSRB_TXB8                 0  /* Transmit Data Bit 8 */


/* UCSRC Register Bits */
#define UCSRC_URSEL                7  /* USART Register Select */
#define UCSRC_UMSEL                6  /* USART Mode Select */
#define UCSRC_UPM1                 5  /* USART Parity Mode Bit 1 */
#define UCSRC_UPM0                 4  /* USART Parity Mode Bit 0 */
#define UCSRC_USBS                 3  /* USART Stop Bit Select*/
#define UCSRC_UCSZ1                2  /* Character Size Bit 1 */
#define UCSRC_UCSZ0                1  /* Character Size Bit 0 */
#define UCSRC_UCPOL                0  /* USART Clock Polarity */


/* UBRRH Register Bits */
#define UBRRH_URSEL                7  /* USART Register Select */

#endif /* 1_MCAL_USART_USART_REGISTER_H_ */
