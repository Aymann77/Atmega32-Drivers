/*
 * ADC_Configuration.h
 *
 *  Created on: Oct 12, 2022
 *      Author: moham
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_


/*REFERENCE OPTIONS:
 * 1 - AREF     , Internal VREF(2.56V) Turned OFF
 * 2 - AVCC     , With External Capacitor at AREF Pin
 * 3 - INTERNAL2_56V , With External Capacitor at AREF Pin
 * */
#define ADC_REFERENCE_SELECT   AVCC



/*PRESCALER OPTIONS:
 * 1 - DIV_BY_2
 * 2 - DIV_BY_4
 * 3 - DIV_BY_8
 * 4 - DIV_BY_16
 * 5 - DIV_BY_32
 * 6 - DIV_BY_64
 * 7 - DIV_BY_128
 * */
#define ADC_PRESCALER   DIV_BY_64



/*RESOLUTION OPTIOINS:
 *               1->  _10_BIT
 *               2->  _8_BIT
 * */
#define ADC_RESOLUTION  _10_BIT



/*ADC ENABLE OPTIONS:
 *                    1-> ENABLED
 *                    2-> DISABLED
 * */
#define ADC_ENABLE      ENABLED



/*ADC AUTO TRIGGER ENABLE OPTIONS:
 *                                1-> ENABLED
 *                                2-> DISABLED
 * */
#define ADC_AUTO_TRIGGER_ENABLE  DISABLED



/*ADC AUTO TRIGGER SOURCE OPTIONS:
 *
 *                                1-> FREE_RUNNING_MODE
 *                                2-> ANALOG_COMP
 *                                3-> EXTERNAL_INT0
 *                                4-> TIMER0_COMPARE_MATCH
 *                                5-> TIMER0_OVERFLOW
 *                                6-> TIMER1_COMPARE_MATCH_B
 *                                7-> TIMER1_OVERFLOW
 *                                8-> TIMER1_CAPTURE_EVENT
 *
 * */

/* HAS NO EFFECT IF ADC_AUTO_TRIGGER_ENABLE IS DISABLED
 * */

#define ADC_AUTO_TRIGGER_SOURCE   FREE_RUNNING_MODE



/*ADC INTERRUPT ENABLE OPTIONS:
 *                                1-> ENABLED
 *                                2-> DISABLED
 * */
#define ADC_INTERRUPT_ENABLE     DISABLED


#define ADC_u32TIME_OUT    600

#endif /* 1_MCAL_ADC_ADC_CONFIGURATION_H_ */
