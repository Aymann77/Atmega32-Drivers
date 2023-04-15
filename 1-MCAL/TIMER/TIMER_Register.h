/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   MCAL			      ***************************/
/*************                SWC :     TIMER	              ***************************/
/*************                VERSION : 1.00		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

/*--------------------------------------------------------------*/
/*---------------------- TIMER0 REGISTERS ----------------------*/
/*--------------------------------------------------------------*/

#define TCCR0  *((volatile u8*) 0X53 )  /* Timer/Counter 0 Control Register */
#define TCNT0  *((volatile u8*) 0X52 )  /* Timer/Counter 0 Register */
#define OCR0   *((volatile u8*) 0X5C )  /* Output Compare Register 0 */

/*TCCR0 Register Bits*/
#define TCCR0_FOC0                   7  /* Force Output Compare */
#define TCCR0_WGM00                  6  /* Waveform Generation Mode Bit 0 */
#define TCCR0_WGM01                  3  /* Waveform Generation Mode Bit 1 */
#define TCCR0_COM01                  5  /* Compare Match Output Mode Bit 1 */
#define TCCR0_COM00                  4  /* Compare Match Output Mode Bit 0 */
#define TCCR0_CS02                   2  /* Prescaler Bit 2 */
#define TCCR0_CS01                   1  /* Prescaler Bit 1 */
#define TCCR0_CS00                   0  /* Prescaler Bit 0 */



/*--------------------------------------------------------------*/
/*---------------------- TIMER1 REGISTERS ----------------------*/
/*--------------------------------------------------------------*/

#define TCCR1A *((volatile u8*) 0x4F )  /* Timer 1 Control Register A */
#define TCCR1B *((volatile u8*) 0x4E )  /* Timer 1 Control Register B */

#define ICR1   *((volatile u16*) 0x46 ) /* Input Capture Register 1 */

#define OCR1A  *((volatile u16*) 0x4A ) /* Output Compare Register 1 A */
#define OCR1B  *((volatile u16*) 0x48 ) /* Output Compare Register 1 B */

#define TCNT1  *((volatile u16*) 0x4C ) /* Timer 1 Register */


/* TCCR1A Register Bits */
#define TCCR1A_WGM10          0
#define TCCR1A_WGM11          1
#define TCCR1A_FOC1B          2
#define TCCR1A_FOC1A          3
#define TCCR1A_COM1B0         4
#define TCCR1A_COM1B1         5
#define TCCR1A_COM1A0         6
#define TCCR1A_COM1A1         7

/* TCCR1B Register Bits */
#define TCCR1B_CS10           0
#define TCCR1B_CS11           1
#define TCCR1B_CS12           2
#define TCCR1B_WGM12          3
#define TCCR1B_WGM13          4
#define TCCR1B_ICES1          6
#define TCCR1B_ICNC1          7


/*--------------------------------------------------------------*/
/*---------------------- TIMER2 REGISTERS ----------------------*/
/*--------------------------------------------------------------*/

#define TCCR2           ( * ( volatile u8 * ) 0x45 ) /* Timer/Counter 2 Control Register */
#define TCNT2           ( * ( volatile u8 * ) 0x44 ) /* Timer/Counter 2 Register */
#define OCR2            ( * ( volatile u8 * ) 0x43 ) /* Output Compare Register 2 */

#define ASSR            ( * ( volatile u8 * ) 0x42 ) /* Asynchronous Status Register Timer/Counter 2 */

/* TCCR2 Register Bits */
#define TCCR2_FOC2           7 /* Force Output Compare 2 */
#define TCCR2_WGM20          6 /* Waveform Generation Mode Bit 0 */
#define TCCR2_COM21          5 /* Compare Match Output Mode Bit 1 */
#define TCCR2_COM20          4 /* Compare Match Output Mode Bit 0 */
#define TCCR2_WGM21          3 /* Waveform Generation Mode Bit 1 */
#define TCCR2_CS22           2 /* Clock Select Bit 2 */
#define TCCR2_CS21           1 /* Clock Select Bit 1 */
#define TCCR2_CS20           0 /* Clock Select Bit 0 */


/* ASSR Register bits */
#define ASSR_AS2         3 /* Asycnchronous Timer/Counter2 */
#define ASSR_TCN2UB      2 /* Timer/Counter2 Update Busy */
#define ASSR_OCR2UB      1 /* Output Compare Register2 Update Busy */
#define ASSR_TCR2UB      0 /* Timer/Counter Control Register2 Update Busy */



/*--------------------------------------------------------------*/
/*---------------------- SHARED REGISTERS ----------------------*/
/*--------------------------------------------------------------*/
#define TIMSK  *((volatile u8*) 0X59 )  /* Timer/Counter Interrupt Mask Register */
#define TIFR   *((volatile u8*) 0x58 )  /* Timer/Counter Interrupt Flag Register */



/*TIMSK Register Bits*/
#define TIMSK_OCIE2                  7  /* Timer/Counter2 Ouput Compare Match Interrupt Enable */
#define TIMSK_TOIE2                  6  /* Timer/Counter2 Overflow Interrupt Enable */
#define TIMSK_TICIE1                 5  /* Timer/Counter1 Input Capture Interrupt Enable */
#define TIMSK_OCIE1A                 4  /* Timer/Counter1 Output Compare A Match Interrupt Enable */
#define TIMSK_OCIE1B                 3  /* Timer/Counter1 Output Compare B Match Interrupt Enable */
#define TIMSK_TOIE1                  2  /* Timer/Counter1 Overflow Interrupt Enable */
#define TIMSK_OCIE0                  1  /* Output Compare Match Interrupt Enable */
#define TIMSK_TOIE0                  0  /* Timer/Counter0 Overflow Interrupt Enable */


/* TIFR Register Bits */
#define TIFR_OCF2            7 /* Output Compare Flag 2 */
#define TIFR_TOV2            6 /* Timer/Counter2 Overflow Flag */
#define TIFR_ICF1            5 /* Timer/Counter1 Input Capture Flag */
#define TIFR_OCF1A           4 /* Timer/Counter1 Output Compare A Match Flag */
#define TIFR_OCF1B           3 /* Timer/Counter1 Output Compare B Match Flag */
#define TIFR_TOV1            2 /* Timer/Counter1 Overflow Flag */
#define TIFR_OCF0            1 /* Output Compare Flag 0 */
#define TIFR_TOV0            0 /* Timer/Counter0 Overflow Flag */


#endif /* 1_MCAL_TIMER_TIMER_REGISTER_H_ */