/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   MCAL 		          ***************************/
/*************                SWC :     SPI	                  ***************************/
/*************                VERSION : 1.00		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/* INTERRUPT OPTIONS :
 *              1 - DISABLED       2 - ENABLED
 */
#define SPI_INTERRUPT          DISABLED



/* DATA ORDER MODES :
 *              1 - MSB_FIRST      2 - LSB_FIRST
 */
#define DATA_ORDER                  MSB_FIRST



/* CLOCK POLARITY OPTIONS :
 *              1 - IDLE_LOW       2 - IDLE_HIGH
 */
#define CLOCK_POLARITY_MODE         IDLE_LOW



/* CLOCK PHASE OPTIONS :
 *              1 - SAMPLE_FIRST   2 - SETUP_FIRST
 */
#define CLOCK_PHASE_MODE            SAMPLE_FIRST


/* CLOCK RATE SELECT OPTIONS :
 *                   1 - FREQ_DIVIDE_BY_4
                     2 - FREQ_DIVIDE_BY_16
                     3 - FREQ_DIVIDE_BY_64
                     4 - FREQ_DIVIDE_BY_128
                     5 - FREQ_DIVIDE_BY_2
                     6 - FREQ_DIVIDE_BY_8
                     7 - FREQ_DIVIDE_BY_32
 */
#define CLOCK_RATE_SELECT        FREQ_DIVIDE_BY_16
#endif /* 1_MCAL_SPI_SPI_CONFIG_H_ */
