/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   MCAL			      ***************************/
/*************                SWC :     USART	              ***************************/
/*************                VERSION : 1.00		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_


/* MCU CLOCK */
#define F_CPUUU           8000000UL


/* USART MODE OPTIONS :
 *              1 - SYNCHRONOUS     2 - ASYNCHRONOUS
 */
#define USART_MODE                                        ASYNCHRONOUS



/* INTERRUPT OPTIONS :
 *              1 - ENABLED     2 - DISABLED
 */

#define RECIEVE_COMPLETE_INTERRUPT   		          DISABLED

#define TRANSMIT_COMPLETE_INTERRUPT  		          DISABLED

#define DATA_REGISTER_EMPTY_INTERRUPT 		          DISABLED



/* PARITY OPTIONS :
 *              1 - DISABLED     2 - EVEN_PARITY    3 - ODD_PARITY
 */
#define PARITY_MODE                   		           DISABLED



/* STOP BITS OPTIONS :
 *              1 - _1_BIT     2 - _2_BIT
 */
#define STOP_BIT_SELECT               		             _1_BIT



/* NOTE :
 *        Transmission Speed Only Takes Effect in Asynchronous Mode
 */
/* TRANSMISSION SPEED OPTIONS :
 *              1 - NORMAL_SPEED     2 - DOUBLE_SPEED
 */
#define TRANSMISSION_SPEED           		             NORMAL_SPEED



/* NOTE :
 *        Multi Processor Communication Mode Only Takes Effect in Synchronous Mode
 */
/* MULTI PROCESSOR COMMUNICATION OPTIONS :
 *              1 - PEER_TO_PEER_ASYNCH     2 - MASTER_SLAVE_SYNCH
 */
#define MULTI_PROCECCOR_COMMUNICATION_MODE               PEER_TO_PEER_ASYNCH





/* DATA BIT OPTIONS :
 *              1 - _5_BIT
 *              2 - _6_BIT
 *              3 - _7_BIT
 *              4 - _8_BIT
 *              5 - _9_BIT
 */
#define DATA_BITS                                               _8_BIT




/* TRANSMITER / RECIEVER OPTIONS :
 *          1 - ENABLED       2 - DISABLED
 **/
#define TRANSMITER_ENABLE          ENABLED
#define RECIEVER_ENABLE            ENABLED



/* NOTE :
 *        Clock Polarity Only Takes Effect in Synchronous Mode
 */
/* CLOCK POLARITY OPTIONS :
 *              1 - SEND_ON_RISING_RECIEVE_ON_FALLING     2 - SEND_ON_FALLING_RECIEVE_ON_RISING
 */
#define CLOCK_POLARITY                               SEND_ON_FALLING_RECIEVE_ON_RISING


/* NOTE :
 *        Baud Rate is only in Asynchronous mode
 */
/* BAUD RATE VALUE HAS MANY OPTIONS IN BITS/SEC ( bps )*/
/* MOST FAMOUS OPTIONS IN BAUD RATE :
 *
 *          2400   -  4800   -  9600   -  14400
 *          19200  -  28800  -  38400  -  57600
 *          76800  -  115200 -  230400 -  250000
 *          */
#define BAUD_RATE_VALUE                             9600



#endif /* 1_MCAL_USART_USART_CONFIG_H_ */
