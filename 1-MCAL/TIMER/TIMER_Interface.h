/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   MCAL			      ***************************/
/*************                SWC :     TIMER	              ***************************/
/*************                VERSION : 1.00		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_


/* INTERRUPT SOURCES ID */
#define TIMER2_COMP      0
#define TIMER2_OVF       1
#define TIMER1_CAPT      2
#define TIMER1_COMPA     3
#define TIMER1_COMPB     4
#define TIMER1_OVF       5
#define TIMER0_COMP      6
#define TIMER0_OVF       7

/* TIMERS ID */
#define TIMER0    0
#define TIMER1    1
#define TIMER1A   2
#define TIMER1B   3
#define TIMER2    4


/*---------------------------------------------------------------------*/
/*----------------------------- TIMER0 --------------------------------*/
/*---------------------------------------------------------------------*/

/* STRUCT TO CREATE ELEMENT FROM */
typedef struct
{
   u8 TimerMode ;
   u8 CompOutputMode ;
   u8 Prescaler ;
   u8 InterruptEnable ;
}Timer0_t;


/* Timer0Mode Element */
#define NORMAL_MODE         0
#define PHASE_CORRECT_PWM   1
#define CTC_MODE            2
#define FAST_PWM            3

/* CompOutputMode 0 Element */

/* non-PWM */
#define DISCONNECTED    0
#define TOGGLE_ON_COMP  1
#define CLR_ON_COMP     2
#define SET_ON_COMP     3


/* Fast PWM MODE */
#define DISCONNECTED               0
#define CLR_ON_COMP_SET_ON_TOP     2
#define SET_ON_COMP_CLR_ON_TOP     3


/* Phase Correct PWM MODE */
#define DISCONNECTED                        0
#define CLR_ON_COMP_UP_SET_ON_COMP_DOWN     2
#define SET_ON_COMP_UP_CLR_ON_COMP_DOWN     3


/* Prescaler Options Timer 0 */
#define PRESC_0_NO_CLK_SOURCE            0
#define PRESC_0_NO_PRESCALING            1
#define PRESC_0_DIVIDE_BY_8              2
#define PRESC_0_DIVIDE_BY_64             3
#define PRESC_0_DIVIDE_BY_256            4
#define PRESC_0_DIVIDE_BY_1024           5
#define PRESC_0_CLK_ON_FALLING_EDGE_T0   6  /* Counter Mode */
#define PRESC_0_CLK_ON_RISING_EDGE_T0    7  /* Counter Mode */

/* Interrupt Enable */
#define ENABLED   1
#define DISABLED  2


/*---------------------------------------------------------------------*/
/*----------------------------- TIMER1 --------------------------------*/
/*---------------------------------------------------------------------*/

/* STRUCT TO CREATE ELEMENT FROM */
typedef struct
{
	u8 TimerChannel ;
	u8 TimerMode ;
	u8 CompOutputMode ;
	u8 Prescaler ;
	u8 InterruptEnable ;
}Timer1_t;

/* Timer1 Channels */
#define TIMER1A   2
#define TIMER1B   3

/* Timer1Mode Element */
#define NORMAL_MODE                           0
#define PWM_PHASE_CORRECT_8_BIT               1
#define PWM_PHASE_CORRECT_9_BIT               2
#define PWM_PHASE_CORRECT_10_BIT              3
#define CTC_MODE_TOP_IN_OCR1A                 4
#define FAST_PWM_8_BIT                        5
#define FAST_PWM_9_BIT                        6
#define FAST_PWM_10_BIT                       7

#define PWM_PHASE_FREQ_CORRECT_TOP_IN_ICR1    8
#define PWM_PHASE_FREQ_CORRECT_TOP_IN_OCR1A   9

#define PWM_PHASE_CORRECT_TOP_IN_ICR1         10
#define PWM_PHASE_CORRECT_TOP_IN_OCR1A        11
#define CTC_MODE_TOP_IN_ICR1                  12
#define FAST_PWM_TOP_IN_ICR1                  13
#define FAST_PWM_TOP_IN_OCR1A                 14




/* CompOutputMode 1 Element */
/* ALL OPTIONS FOR TIMER1A & TIMER2B ( FOR THE TWO CHANNELS ) */

/* non-PWM */
#define DISCONNECTED    0
#define TOGGLE_ON_COMP  1
#define CLR_ON_COMP     2
#define SET_ON_COMP     3


/* Fast PWM MODE */
#define DISCONNECTED               0
#define CLR_ON_COMP_SET_ON_TOP     2
#define SET_ON_COMP_CLR_ON_TOP     3


/* Phase Correct PWM MODE */
#define DISCONNECTED                        0
#define CLR_ON_COMP_UP_SET_ON_COMP_DOWN     2
#define SET_ON_COMP_UP_CLR_ON_COMP_DOWN     3


/* Prescaler Options Timer 1 */
#define PRESC_1_NO_CLK_SOURCE               0
#define PRESC_1_NO_PRESCALING               1
#define PRESC_1_DIVIDE_BY_8                 2
#define PRESC_1_DIVIDE_BY_64                3
#define PRESC_1_DIVIDE_BY_256               4
#define PRESC_1_DIVIDE_BY_1024              5
#define PRESC_1_CLK_ON_FALLING_EDGE_T1      6
#define PRESC_1_CLK_ON_RISING_EDGE_T1       7

/* Interrupt Enable */
#define ENABLED   1
#define DISABLED  2



/*---------------------------------------------------------------------*/
/*----------------------------- TIMER2 --------------------------------*/
/*---------------------------------------------------------------------*/

/* STRUCT TO CREATE ELEMENT FROM */
typedef struct
{
   u8 TimerMode ;
   u8 CompOutputMode ;
   u8 Prescaler ;
   u8 InterruptEnable ;
   u8 Synchronization ;
}Timer2_t;


/* Timer2Mode Element */
#define NORMAL_MODE         0
#define PHASE_CORRECT_PWM   1
#define CTC_MODE            2
#define FAST_PWM            3

/* CompOutputMode 2 Element */

/* non-PWM */
#define DISCONNECTED    0
#define TOGGLE_ON_COMP  1
#define CLR_ON_COMP     2
#define SET_ON_COMP     3


/* Fast PWM MODE */
#define DISCONNECTED               0
#define CLR_ON_COMP_SET_ON_TOP     2
#define SET_ON_COMP_CLR_ON_TOP     3


/* Phase Correct PWM MODE */
#define DISCONNECTED                        0
#define CLR_ON_COMP_UP_SET_ON_COMP_DOWN     2
#define SET_ON_COMP_UP_CLR_ON_COMP_DOWN     3


/* Prescaler Options Timer 2 */
#define PRESC_2_NO_CLK_SOURCE            0
#define PRESC_2_NO_PRESCALING            1
#define PRESC_2_DIVIDE_BY_8              2
#define PRESC_2_DIVIDE_BY_32             3
#define PRESC_2_DIVIDE_BY_64             4
#define PRESC_2_DIVIDE_BY_128            5
#define PRESC_2_DIVIDE_BY_256            6
#define PRESC_2_DIVIDE_BY_1024           7

/* Interrupt Enable */
#define ENABLED   1
#define DISABLED  2

/* Synchronization */
#define SYNCHRONOUS  1
#define ASYNCHRONOUS 2



/* ICU TRIGGER EDGE */
#define ICU_FALLING_EDGE    0
#define ICU_RISING_EDGE     1


/****************** PROTOTYPES ******************/
u8 TIMER0_u8Init( Timer0_t * psTimer0Config ) ;

u8 TIMER_u8SetCallBack( void ( *Copy_pvCallBackFunc )( void )  , u8 Copy_u8InterruptSourceID ) ;

u8 TIMER2_u8Init( Timer2_t * psTimer2Config ) ;

u8 TIMER_u8SetCompareMatchValue( u8 Copy_u8TimerID , u16 Copy_u16CompareValue ) ;

u8 TIMER_u8SetPWMDutyCycle( u8 Copy_u8TimerID , u16 Copy_u16DutyCycleValue ) ;

u8 TIMER_u8SetPreLoadValue( u8 Copy_u8TimerID , u16 Copy_u16TimerValue ) ;

u8 TIMER_u8SetTimerValue( u8 Copy_u8TimerID , u16 Copy_u16TimerValue ) ;

u8 TIMER_u8InterruptEnable( u8 Copy_u8InterruptSourceID , u8 Copy_u8InterruptEnableDisable ) ;

u8 TIMER_u8Stop( u8 Copy_u8TimerID ) ;

u8 TIMER_u8ForceOutputCompare ( u8 Copy_u8TimerID ) ;

u8 TIMER1_u8Init( Timer1_t * psTimer1Config ) ;

void TIMER1_voidSetICRValue( u16 Copy_u16ICRTopValue ) ;

void ICU_voidInit( void ) ;

u8 ICU_voidSetTriggerEdge( u8 Copy_u8TriggerEdge ) ;

u16 ICU_u16ReadInputCapture( void ) ;

#endif /* 1_MCAL_TIMER_TIMER_INTERFACE_H_ */
