/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   MCAL			      ***************************/
/*************                SWC :     ADC 		          ***************************/
/*************                VERSION : 1.00		          ***************************/
/*************                DATE : 12-10-2022		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

/*
 * ADC REGISTERS
 * */
#define ADMUX   *( ( volatile u8* ) 0x27 ) /*ADC Multiplexer Selection Register*/
#define ADCSRA  *( ( volatile u8* ) 0x26 ) /*ADC Control and Status Register A*/
#define ADCH    *( ( volatile u8* ) 0x25 ) /*ADC High Register*/
#define ADCL    *( ( volatile u8* ) 0x24 ) /*ADC Low Register*/
#define SFIOR   *( ( volatile u8* ) 0x50 ) /*Special Function IO Register*/

#define ADC     *( ( volatile u16* ) 0x24 )/*To Access All 10 Bits of The Register*/

/*
 * ADMUX BITS
 * */
#define ADMUX_REFS1  7 /*Reference Selection Bit1*/
#define ADMUX_REFS0  6 /*Reference Selection Bit0*/
#define ADMUX_ADLAR  5 /*ADC Left Adjust Result*/
#define ADMUX_MUX4   4 /*Bits 4:0 -> Analog Channel and Gain Selection Bits*/
#define ADMUX_MUX3   3
#define ADMUX_MUX2   2
#define ADMUX_MUX1   1
#define ADMUX_MUX0   0

/*
 * ADCSRA BITS
 * */
#define ADCSRA_ADEN   7 /*ADC Enable*/
#define ADCSRA_ADSC   6 /*ADC Start Conversion*/
#define ADCSRA_ADATE  5 /*ADC Auto Trigger Enable*/
#define ADCSRA_ADIF   4 /*ADC Interrupt Flag*/
#define ADCSRA_ADIE   3 /*ADC Interrupt Enable*/
#define ADCSRA_ADPS2  2 /*Bits 2:0 -> ADC Prescaler Selection Bits*/
#define ADCSRA_ADPS1  1
#define ADCSRA_ADPS0  0

/*
 * SFIOR BITS
 * */
#define SFIOR_ADTS2  7 /*Bits 7:5 -> ADC Trigger Source Selection Bits*/
#define SFIOR_ADTS1  6
#define SFIOR_ADTS0  5

#endif /* 1_MCAL_ADC_ADC_REGISTER_H_ */
