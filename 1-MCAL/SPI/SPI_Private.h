/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   MCAL 		          ***************************/
/*************                SWC :     SPI	                  ***************************/
/*************                VERSION : 1.00		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

/* INTERRUPT OPTIONS */
#define ENABLED                   1
#define DISABLED                  0

/* DATA ORDER MODES */
#define LSB_FIRST                 1
#define MSB_FIRST                 0

/* MODE OPTIONS */
#define MASTER                    1
#define SLAVE                     0

/* CLOCK POLARITY OPTIONS */
#define IDLE_HIGH                 1
#define IDLE_LOW                  0

/* CLOCK PHASE OPTIONS */
#define SETUP_FIRST               1
#define SAMPLE_FIRST              0

/* CLOCK RATE SELECT OPTIONS */
#define FREQ_DIVIDE_BY_4          0
#define FREQ_DIVIDE_BY_16         1
#define FREQ_DIVIDE_BY_64         2
#define FREQ_DIVIDE_BY_128        3
#define FREQ_DIVIDE_BY_2          4
#define FREQ_DIVIDE_BY_8          5
#define FREQ_DIVIDE_BY_32         6

/* MASKS */
#define CLOCK_MASK             ( 0xFC )
#endif /* 1_MCAL_SPI_SPI_PRIVATE_H_ */
