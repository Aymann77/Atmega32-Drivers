/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   MCAL			      ***************************/
/*************                SWC :     USART	              ***************************/
/*************                VERSION : 1.00		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

/* INTERRUPT OPTIONS */
#define DISABLED    	 0
#define ENABLED     	 1


/* PARITY OPTIONS */
#define DISABLED         0
#define EVEN_PARITY      2
#define ODD_PARITY       3


/* STOP BIT OPTIONS */
#define _1_BIT           0
#define _2_BIT           1


/* DOUBLE SPEED OPTIONS */
#define NORMAL_SPEED     0
#define DOUBLE_SPEED     1


/* MULTI PROCESSOR COMMUNICATION MODE */
#define PEER_TO_PEER_ASYNCH     0
#define MASTER_SLAVE_SYNCH      1


/* USART MODES */
#define ASYNCHRONOUS     0
#define SYNCHRONOUS      1


/* DATA BITS */
#define _5_BIT           0
#define _6_BIT           1
#define _7_BIT           2
#define _8_BIT           3
#define _9_BIT           7


/* CLOCK POLARITY OPTIONS */
#define SEND_ON_RISING_RECIEVE_ON_FALLING   0
#define SEND_ON_FALLING_RECIEVE_ON_RISING   1

/* ISR SOURCES */
#define RECIEVE_BUFFER   1
#define RECIEVE_CHAR     2

/*USART STATES*/
#define USART_IDLE       2
#define USART_BUSY       1

#define CHARACTER_SIZE_MASK  0xF9

#define USART_TIMEOUT        50000UL

#endif /* 1_MCAL_USART_USART_PRIVATE_H_ */
