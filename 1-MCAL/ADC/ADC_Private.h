/*
 * ADC_Private.h
 *
 *  Created on: Oct 12, 2022
 *      Author: moham
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_




/*REFERENCE SELECTION OPTIONS*/
#define AREF 		   1
#define AVCC	       2
#define INTERNAL2_56V  3

/*PRESCALER SELECTOIN OPTIONS*/
#define  DIV_BY_2    0
#define  DIV_BY_4    2
#define  DIV_BY_8    3
#define  DIV_BY_16   4
#define  DIV_BY_32   5
#define  DIV_BY_64   6
#define  DIV_BY_128  7

#define ADC_PRESCALER_MASK  0xF8

/*ADC RESOLUTION SELECTION OPTIONS*/
#define _10_BIT  1
#define _8_BIT   2

/*ADC ENABLE & ADC AUTO TRIGGER ENABLE  OPTIONS*/
#define ENABLED   1
#define DISABLED  2

/*ADC AUTO TRIGGER SOURCE OPTIONS*/
#define FREE_RUNNING_MODE                    0
#define ANALOG_COMP            				 1
#define EXTERNAL_INT0          				 2
#define TIMER0_COMPARE_MATCH   				 3
#define TIMER0_OVERFLOW        				 4
#define TIMER1_COMPARE_MATCH_   			 5
#define TIMER1_OVERFLOW        				 6
#define TIMER1_CAPTURE_EVENT   				 7

#define ADC_AUTO_TRIGGER_MASK   			0x1F
#define ADC_AUTO_TRIGGER_BITS_STARTING_FROM  5

#define ADC_ANALOG_CHANNEL_MASK             0xE0

#define IDLE   0
#define BUSY   1

#define SINGLE_CHANNEL_ASYNCH  1
#define CHAIN_CHANNEL_ASYNCH   2

#endif /* 1_MCAL_ADC_ADC_PRIVATE_H_ */
