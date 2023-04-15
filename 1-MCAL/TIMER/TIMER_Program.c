/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   MCAL			      ***************************/
/*************                SWC :     TIMER	              ***************************/
/*************                VERSION : 1.00		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

#include "../../4-LIB/STD_TYPES.h"

#include "TIMER_Interface.h"
#include "TIMER_Config.h"
#include "TIMER_Private.h"
#include "TIMER_Register.h"

/* Array of Pointers To Functions */
static void ( *TIMERS_pvCallBackFunction [8] ) ( void ) = { NULL } ;

/* NOTE :
 *   IN FAST PWM & PHASE CORRECT PWM INTERRUPT ENABLE DOES NOT MATTER IF ENABLED OR DISABLED
 **/
u8 TIMER0_u8Init( Timer0_t * psTimer0Config )
{
	u8 Local_u8ErrorState = OK ;

	if( psTimer0Config != NULL )
	{
		if( psTimer0Config -> TimerMode == NORMAL_MODE )
		{
			/* Chosing Normal Mode */
			/* BIT MASKING WGM00 & WGM01 ARE ZEROS */
			TCCR0 &= (~ ( ( 1 << TCCR0_WGM00 ) | ( 1 << TCCR0_WGM01 ) ) ) ;

			if( psTimer0Config -> CompOutputMode == DISCONNECTED )
			{
				/* BIT MASKING COM00 & COM01 ARE ZEROS */
				TCCR0 &= (~ ( ( 1 << TCCR0_COM00 ) | ( 1 << TCCR0_COM01 ) ) ) ;
			}
			else if( psTimer0Config -> CompOutputMode == TOGGLE_ON_COMP )
			{
				/* Toggle OC0 on Compare match */
				TCCR0 |= ( 1 << TCCR0_COM00 ) ;
				TCCR0 &= ( ~ ( 1 << TCCR0_COM01 ) ) ;
			}
			else if( psTimer0Config -> CompOutputMode == CLR_ON_COMP )
			{
				/* Clear OC0 on Compare match */
				TCCR0 |= ( 1 << TCCR0_COM01 ) ;
				TCCR0 &= ( ~ ( 1 << TCCR0_COM00 ) ) ;
			}
			else if( psTimer0Config -> CompOutputMode == SET_ON_COMP )
			{
				/* Set OC0 on Compare match */
				/* BIT MASKING COM00 & COM01 ARE ONES */
				TCCR0 |= ( ( 1 << TCCR0_COM00 ) | ( 1 << TCCR0_COM01 ) ) ;
			}
			else
			{
				Local_u8ErrorState = NOK ;
			}
			if( psTimer0Config -> InterruptEnable == ENABLED )
			{
				/* Enable Timer 0 Overflow Interrupt */
				TIMSK |= ( 1 << TIMSK_TOIE0 ) ;
			}
		}
		else if ( psTimer0Config -> TimerMode == PHASE_CORRECT_PWM )
		{
			/* Chosing Phase Correct PWM */
			TCCR0 |= ( 1 << TCCR0_WGM00 ) ;
			TCCR0 &= ( ~ ( 1 << TCCR0_WGM01 ) ) ;

			if( psTimer0Config -> CompOutputMode == DISCONNECTED )
			{
				/* BIT MASKING COM00 & COM01 ARE ZEROS */
				TCCR0 &= (~ ( ( 1 << TCCR0_COM00 ) | ( 1 << TCCR0_COM01 ) ) ) ;
			}
			else if( psTimer0Config -> CompOutputMode == CLR_ON_COMP_UP_SET_ON_COMP_DOWN )
			{
				/* Non Inverting Mode */
				/* Clear on Compare when Up Counting , Set on Compare when down Counting */
				TCCR0 |= ( 1 << TCCR0_COM01 ) ;
				TCCR0 &= ( ~ ( 1 << TCCR0_COM00 ) ) ;
			}
			else if( psTimer0Config -> CompOutputMode == SET_ON_COMP_UP_CLR_ON_COMP_DOWN )
			{
				/* Inverting Mode */
				/* Set on Compare when Up Counting , Clear on Compare when down Counting */
				/* BIT MASKING COM00 & COM01 ARE ONES */
				TCCR0 |= ( ( 1 << TCCR0_COM00 ) | ( 1 << TCCR0_COM01 ) ) ;
			}
			else
			{
				Local_u8ErrorState = NOK ;
			}
		}
		else if( psTimer0Config -> TimerMode == CTC_MODE )
		{
			/* Chosing Clear Timer on Compare ( CTC ) Mode */
			TCCR0 |= ( 1 << TCCR0_WGM01 ) ;
			TCCR0 &= ( ~ ( 1 << TCCR0_WGM00 ) ) ;

			if( psTimer0Config -> CompOutputMode == DISCONNECTED )
			{
				/* BIT MASKING COM00 & COM01 ARE ZEROS */
				TCCR0 &= (~ ( ( 1 << TCCR0_COM00 ) | ( 1 << TCCR0_COM01 ) ) ) ;
			}
			else if( psTimer0Config -> CompOutputMode == TOGGLE_ON_COMP )
			{
				/* Toggle OC0 on Compare match */
				TCCR0 |= ( 1 << TCCR0_COM00 ) ;
				TCCR0 &= ( ~ ( 1 << TCCR0_COM01 ) ) ;
			}
			else if( psTimer0Config -> CompOutputMode == CLR_ON_COMP )
			{
				/* Clear OC0 on Compare match */
				TCCR0 |= ( 1 << TCCR0_COM01 ) ;
				TCCR0 &= ( ~ ( 1 << TCCR0_COM00 ) ) ;
			}
			else if( psTimer0Config -> CompOutputMode == SET_ON_COMP )
			{
				/* Set OC0 on Compare match */
				/* BIT MASKING COM00 & COM01 ARE ONES */
				TCCR0 |= ( ( 1 << TCCR0_COM00 ) | ( 1 << TCCR0_COM01 ) ) ;
			}
			else
			{
				Local_u8ErrorState = NOK ;
			}
			if( psTimer0Config -> InterruptEnable == ENABLED )
			{
				/* Enable Timer 0 Output Compare Match Interrupt Enable */
				TIMSK |= ( 1 << TIMSK_OCIE0 ) ;
			}
		}
		else if( psTimer0Config -> TimerMode == FAST_PWM )
		{
			/* Chosing Fast PWM */
			/* BIT MASKING WGM00 & WGM01 ARE ONES */
			TCCR0 |= ( ( 1 << TCCR0_WGM00 ) | ( 1 << TCCR0_WGM01 ) ) ;

			if( psTimer0Config -> CompOutputMode == DISCONNECTED )
			{
				/* BIT MASKING COM00 & COM01 ARE ZEROS */
				TCCR0 &= (~ ( ( 1 << TCCR0_COM00 ) | ( 1 << TCCR0_COM01 ) ) ) ;
			}
			else if( psTimer0Config -> CompOutputMode == CLR_ON_COMP_SET_ON_TOP )
			{
				/* Non Inverting Mode */
				/* Clear on Compare , Set on Top */
				TCCR0 |= ( 1 << TCCR0_COM01 ) ;
				TCCR0 &= ( ~ ( 1 << TCCR0_COM00 ) ) ;
			}
			else if( psTimer0Config -> CompOutputMode == SET_ON_COMP_CLR_ON_TOP )
			{
				/* Inverting Mode */
				/* Set on Compare , Clear on Top */
				/* BIT MASKING COM00 & COM01 ARE ONES */
				TCCR0 |= ( ( 1 << TCCR0_COM00 ) | ( 1 << TCCR0_COM01 ) ) ;
			}
			else
			{
				Local_u8ErrorState = NOK ;
			}
		}
		/* Check if Prescaler In Range */
		if( ( psTimer0Config -> Prescaler >= PRESC_0_NO_CLK_SOURCE ) && ( psTimer0Config -> Prescaler <= PRESC_0_CLK_ON_RISING_EDGE_T0  ) )
		{
			/* Set Prescaler */
			TCCR0 &= ( TIMER_PRESC_MASK ) ;
			TCCR0 |= ( psTimer0Config -> Prescaler ) ;
		}
		else
		{
			Local_u8ErrorState = NOK ;
		}

	}
	else
	{
		Local_u8ErrorState = NULL_POINTER ;
	}
	return Local_u8ErrorState ;
}


u8 TIMER_u8SetCallBack( void ( *Copy_pvCallBackFunc )( void )  , u8 Copy_u8InterruptSourceID )
{
	u8 Local_u8ErrorState = OK ;
	if( Copy_pvCallBackFunc != NULL )
	{
		if( ( Copy_u8InterruptSourceID >= TIMER2_COMP ) && ( Copy_u8InterruptSourceID <= TIMER0_OVF ) )
		{
			if( Copy_u8InterruptSourceID == TIMER2_COMP )
			{
				TIMERS_pvCallBackFunction[ TIMER2_COMP ] = Copy_pvCallBackFunc ;
			}
			else if( Copy_u8InterruptSourceID == TIMER2_OVF )
			{
				TIMERS_pvCallBackFunction[ TIMER2_OVF ] = Copy_pvCallBackFunc ;
			}
			else if( Copy_u8InterruptSourceID == TIMER1_CAPT )
			{
				TIMERS_pvCallBackFunction[ TIMER1_CAPT ] = Copy_pvCallBackFunc ;
			}
			else if( Copy_u8InterruptSourceID == TIMER1_COMPA )
			{
				TIMERS_pvCallBackFunction[ TIMER1_COMPA ] = Copy_pvCallBackFunc ;
			}
			else if( Copy_u8InterruptSourceID == TIMER1_COMPB )
			{
				TIMERS_pvCallBackFunction[ TIMER1_COMPB ] = Copy_pvCallBackFunc ;
			}
			else if( Copy_u8InterruptSourceID == TIMER1_OVF )
			{
				TIMERS_pvCallBackFunction[ TIMER1_OVF ] = Copy_pvCallBackFunc ;
			}
			else if( Copy_u8InterruptSourceID == TIMER0_COMP )
			{
				TIMERS_pvCallBackFunction[ TIMER0_COMP ] = Copy_pvCallBackFunc ;
			}
			else if( Copy_u8InterruptSourceID == TIMER0_OVF )
			{
				TIMERS_pvCallBackFunction[ TIMER0_OVF ] = Copy_pvCallBackFunc ;
			}
		}
		else
		{
			Local_u8ErrorState = NOK ;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER ;
	}
	return Local_u8ErrorState ;
}


u8 TIMER2_u8Init( Timer2_t * psTimer2Config )
{
	u8 Local_u8ErrorState = OK ;

	if( psTimer2Config != NULL )
	{
		/* Default is Synchronous -> Clock is Taken From Input Clock */
		if( psTimer2Config -> Synchronization == ASYNCHRONOUS )
		{
			ASSR |= (1<<ASSR_AS2);
		}

		if( psTimer2Config -> TimerMode == NORMAL_MODE )
		{
			/* Chosing Normal Mode */
			/* BIT MASKING WGM20 & WGM21 ARE ZEROS */
			TCCR2 &= (~ ( ( 1 << TCCR2_WGM20 ) | ( 1 << TCCR2_WGM21 ) ) ) ;

			if( psTimer2Config -> CompOutputMode == DISCONNECTED )
			{
				/* BIT MASKING COM20 & COM21 ARE ZEROS */
				TCCR2 &= (~ ( ( 1 << TCCR2_COM20 ) | ( 1 << TCCR2_COM21 ) ) ) ;
			}
			else if( psTimer2Config -> CompOutputMode == TOGGLE_ON_COMP )
			{
				/* Toggle OC2 on Compare match */
				TCCR2 |= ( 1 << TCCR2_COM20 ) ;
				TCCR2 &= ( ~ ( 1 << TCCR2_COM21 ) ) ;
			}
			else if( psTimer2Config -> CompOutputMode == CLR_ON_COMP )
			{
				/* Clear OC2 on Compare match */
				TCCR2 |= ( 1 << TCCR2_COM21 ) ;
				TCCR2 &= ( ~ ( 1 << TCCR2_COM20 ) ) ;
			}
			else if( psTimer2Config -> CompOutputMode == SET_ON_COMP )
			{
				/* Set OC2 on Compare match */
				/* BIT MASKING COM20 & COM21 ARE ONES */
				TCCR2 |= ( ( 1 << TCCR2_COM20 ) | ( 1 << TCCR2_COM21 ) ) ;
			}
			else
			{
				Local_u8ErrorState = NOK ;
			}
			if( psTimer2Config -> InterruptEnable == ENABLED )
			{
				/* Enable Timer 2 Overflow Interrupt */
				TIMSK |= ( 1 << TIMSK_TOIE2 ) ;
			}
		}
		else if ( psTimer2Config -> TimerMode == PHASE_CORRECT_PWM )
		{
			/* Chosing Phase Correct PWM */
			TCCR2 |= ( 1 << TCCR2_WGM20 ) ;
			TCCR2 &= ( ~ ( 1 << TCCR2_WGM21 ) ) ;

			if( psTimer2Config -> CompOutputMode == DISCONNECTED )
			{
				/* BIT MASKING COM20 & COM21 ARE ZEROS */
				TCCR2 &= (~ ( ( 1 << TCCR2_COM20 ) | ( 1 << TCCR2_COM21 ) ) ) ;
			}
			else if( psTimer2Config -> CompOutputMode == CLR_ON_COMP_UP_SET_ON_COMP_DOWN )
			{
				/* Non Inverting Mode */
				/* Clear on Compare when Up Counting , Set on Compare when down Counting */
				TCCR2 |= ( 1 << TCCR2_COM21 ) ;
				TCCR2 &= ( ~ ( 1 << TCCR2_COM20 ) ) ;
			}
			else if( psTimer2Config -> CompOutputMode == SET_ON_COMP_UP_CLR_ON_COMP_DOWN )
			{
				/* Inverting Mode */
				/* Set on Compare when Up Counting , Clear on Compare when down Counting */
				/* BIT MASKING COM20 & COM21 ARE ONES */
				TCCR2 |= ( ( 1 << TCCR2_COM20 ) | ( 1 << TCCR2_COM21 ) ) ;
			}
			else
			{
				Local_u8ErrorState = NOK ;
			}
		}
		else if( psTimer2Config -> TimerMode == CTC_MODE )
		{
			/* Chosing Clear Timer on Compare ( CTC ) Mode */
			TCCR2 |= ( 1 << TCCR2_WGM21 ) ;
			TCCR2 &= ( ~ ( 1 << TCCR2_WGM20 ) ) ;

			if( psTimer2Config -> CompOutputMode == DISCONNECTED )
			{
				/* BIT MASKING COM20 & COM21 ARE ZEROS */
				TCCR2 &= (~ ( ( 1 << TCCR2_COM20 ) | ( 1 << TCCR2_COM21 ) ) ) ;
			}
			else if( psTimer2Config -> CompOutputMode == TOGGLE_ON_COMP )
			{
				/* Toggle OC2 on Compare match */
				TCCR2 |= ( 1 << TCCR2_COM20 ) ;
				TCCR2 &= ( ~ ( 1 << TCCR2_COM21 ) ) ;
			}
			else if( psTimer2Config -> CompOutputMode == CLR_ON_COMP )
			{
				/* Clear OC2 on Compare match */
				TCCR2 |= ( 1 << TCCR2_COM21 ) ;
				TCCR2 &= ( ~ ( 1 << TCCR2_COM20 ) ) ;
			}
			else if( psTimer2Config -> CompOutputMode == SET_ON_COMP )
			{
				/* Set OC2 on Compare match */
				/* BIT MASKING COM20 & COM21 ARE ONES */
				TCCR2 |= ( ( 1 << TCCR2_COM20 ) | ( 1 << TCCR2_COM21 ) ) ;
			}
			else
			{
				Local_u8ErrorState = NOK ;
			}
			if( psTimer2Config -> InterruptEnable == ENABLED )
			{
				/* Enable Timer 2 Output Compare Interrupt */
				TIMSK |= ( 1 << TIMSK_OCIE2 ) ;
			}
		}
		else if( psTimer2Config -> TimerMode == FAST_PWM )
		{
			/* Chosing Fast PWM */
			/* BIT MASKING WGM20 & WGM21 ARE ONES */
			TCCR2 |= ( ( 1 << TCCR2_WGM20 ) | ( 1 << TCCR2_WGM21 ) ) ;

			if( psTimer2Config -> CompOutputMode == DISCONNECTED )
			{
				/* BIT MASKING COM20 & COM21 ARE ZEROS */
				TCCR2 &= (~ ( ( 1 << TCCR2_COM20 ) | ( 1 << TCCR2_COM21 ) ) ) ;
			}
			else if( psTimer2Config -> CompOutputMode == CLR_ON_COMP_SET_ON_TOP )
			{
				/* Non Inverting Mode */
				/* Clear on Compare , Set on Top */
				TCCR2 |= ( 1 << TCCR2_COM21 ) ;
				TCCR2 &= ( ~ ( 1 << TCCR2_COM20 ) ) ;
			}
			else if( psTimer2Config -> CompOutputMode == SET_ON_COMP_CLR_ON_TOP )
			{
				/* Inverting Mode */
				/* Set on Compare , Clear on Top */
				/* BIT MASKING COM20 & COM21 ARE ONES */
				TCCR2 |= ( ( 1 << TCCR2_COM20 ) | ( 1 << TCCR2_COM21 ) ) ;
			}
			else
			{
				Local_u8ErrorState = NOK ;
			}
		}
		/* Check if Prescaler In Range */
		if( ( psTimer2Config -> Prescaler >= PRESC_2_NO_CLK_SOURCE ) && ( psTimer2Config -> Prescaler <= PRESC_2_DIVIDE_BY_1024  ) )
		{
			/* Set Prescaler */
			TCCR2 &= ( TIMER_PRESC_MASK ) ;
			TCCR2 |= ( psTimer2Config -> Prescaler ) ;
		}
		else
		{
			Local_u8ErrorState = NOK ;
		}

	}
	else
	{
		Local_u8ErrorState = NULL_POINTER ;
	}
	return Local_u8ErrorState ;
}

u8 TIMER_u8SetCompareMatchValue( u8 Copy_u8TimerID , u16 Copy_u16CompareValue )
{
	u8 Local_u8ErrorState = OK ;

	switch( Copy_u8TimerID )
	{
	case TIMER0 : ( Copy_u16CompareValue > 255 ) ? ( Local_u8ErrorState=NOK ) : ( OCR0=(u8)Copy_u16CompareValue ) ; break ;
	case TIMER1A: ( Copy_u16CompareValue > 65535UL ) ? ( Local_u8ErrorState=NOK ) : ( OCR1A=Copy_u16CompareValue ) ; break ;
	case TIMER1B: ( Copy_u16CompareValue > 65535UL ) ? ( Local_u8ErrorState=NOK ) : ( OCR1B=Copy_u16CompareValue ) ; break ;
	case TIMER2: ( Copy_u16CompareValue > 255 ) ? ( Local_u8ErrorState=NOK ) : ( OCR2=(u8)Copy_u16CompareValue ) ; break ;
	default : Local_u8ErrorState = NOK ;
	}

	return Local_u8ErrorState ;
}

/* Non Inverting */

u8 TIMER_u8SetPWMDutyCycle( u8 Copy_u8TimerID , u16 Copy_u16DutyCycleValue )
{
	u8 Local_u8ErrorState = OK ;

	switch( Copy_u8TimerID )
	{
	case TIMER0 :
		  OCR0 = (u8)( (f32)( (f32)Copy_u16DutyCycleValue / 100.00  ) * (u16)256 ) ; break ;
	case TIMER1A:
		  OCR1A = (u16)( (f32)( (f32)Copy_u16DutyCycleValue / 100.00  ) * 65536UL ) ; break ;
	case TIMER1B:
		  OCR1B = (u16)( (f32)( (f32)Copy_u16DutyCycleValue / 100.00  ) * 65536UL ) ; break ;
	case TIMER2:
		  OCR2 = (u8)( (f32)( (f32)Copy_u16DutyCycleValue / 100.00  ) * (u16)256 ) ; break ;
	default : Local_u8ErrorState = NOK ;
	}

	return Local_u8ErrorState ;
}

u8 TIMER_u8ReadTimerValue( u8 Copy_u8TimerID , u16 * Copy_u16TimerReading )
{
	u8 Local_u8ErrorState = OK ;

	switch( Copy_u8TimerID )
	{
	case TIMER0 : *Copy_u16TimerReading = TCNT0 ; break ;
	case TIMER1 : *Copy_u16TimerReading = TCNT1 ; break ;
	case TIMER2 : *Copy_u16TimerReading = TCNT2 ; break ;
	default : Local_u8ErrorState = NOK ;
	}

	return Local_u8ErrorState ;
}

u8 TIMER_u8SetPreLoadValue( u8 Copy_u8TimerID , u16 Copy_u16TimerValue )
{
	u8 Local_u8ErrorState = OK ;

	switch( Copy_u8TimerID )
	{
	case TIMER0 : ( Copy_u16TimerValue > 255 )     ? ( Local_u8ErrorState=NOK ) : ( TCNT0=(u8)Copy_u16TimerValue ) ; break ;
	case TIMER1 : ( Copy_u16TimerValue > 65535UL ) ? ( Local_u8ErrorState=NOK ) : ( TCNT1=Copy_u16TimerValue ) ; break ;
	case TIMER2 : ( Copy_u16TimerValue > 65535UL ) ? ( Local_u8ErrorState=NOK ) : ( TCNT2=Copy_u16TimerValue ) ; break ;
	default : Local_u8ErrorState = NOK ;
	}

	return Local_u8ErrorState ;
}


u8 TIMER_u8InterruptEnable( u8 Copy_u8InterruptSourceID , u8 Copy_u8InterruptEnableDisable )
{
	u8 Local_u8ErrorState = OK ;

	switch( Copy_u8InterruptSourceID )
	{
	case TIMER2_COMP : ( Copy_u8InterruptEnableDisable == ENABLED ) ? ( TIMSK |= (1<<TIMSK_OCIE2) ) : ( TIMSK &= (~(1<<TIMSK_OCIE2)) )   ; break ;
	case TIMER2_OVF  : ( Copy_u8InterruptEnableDisable == ENABLED ) ? ( TIMSK |= (1<<TIMSK_TOIE2) ) : ( TIMSK &= (~(1<<TIMSK_TOIE2)) )   ; break ;
	case TIMER1_CAPT : ( Copy_u8InterruptEnableDisable == ENABLED ) ? ( TIMSK |= (1<<TIMSK_TICIE1) ) : ( TIMSK &= (~(1<<TIMSK_TICIE1)) ) ; break ;
	case TIMER1_COMPA: ( Copy_u8InterruptEnableDisable == ENABLED ) ? ( TIMSK |= (1<<TIMSK_OCIE1A) ) : ( TIMSK &= (~(1<<TIMSK_OCIE1A)) ) ; break ;
	case TIMER1_COMPB: ( Copy_u8InterruptEnableDisable == ENABLED ) ? ( TIMSK |= (1<<TIMSK_OCIE1B) ) : ( TIMSK &= (~(1<<TIMSK_OCIE1B)) ) ; break ;
	case TIMER1_OVF  : ( Copy_u8InterruptEnableDisable == ENABLED ) ? ( TIMSK |= (1<<TIMSK_TOIE1) ) : ( TIMSK &= (~(1<<TIMSK_TOIE1)) )   ; break ;
	case TIMER0_COMP : ( Copy_u8InterruptEnableDisable == ENABLED ) ? ( TIMSK |= (1<<TIMSK_OCIE0) ) : ( TIMSK &= (~(1<<TIMSK_OCIE0)) )   ; break ;
	case TIMER0_OVF  : ( Copy_u8InterruptEnableDisable == ENABLED ) ? ( TIMSK |= (1<<TIMSK_TOIE0) ) : ( TIMSK &= (~(1<<TIMSK_TOIE0)) )   ; break ;
	default : Local_u8ErrorState = NOK ;
	}
	return Local_u8ErrorState ;
}

u8 TIMER_u8Stop( u8 Copy_u8TimerID )
{
	u8 Local_u8ErrorState = OK ;

	switch( Copy_u8TimerID )
	{
	case TIMER0 :  TCCR0  &= ( TIMER_PRESC_MASK ) ; break ;
	case TIMER1 :  TCCR1B &= ( TIMER_PRESC_MASK ) ; break ;
	case TIMER2 :  TCCR2  &= ( TIMER_PRESC_MASK ) ; break ;
	default : Local_u8ErrorState = NOK ;
	}
	return Local_u8ErrorState ;
}

u8 TIMER_u8ForceOutputCompare ( u8 Copy_u8TimerID )
{
	u8 Local_u8ErrorState = OK ;

	switch( Copy_u8TimerID )
	{
	case TIMER0 : TCCR0  |= ( 1 << TCCR0_FOC0 )   ; break ;
	case TIMER1A: TCCR1A |= ( 1 << TCCR1A_FOC1A ) ; break ;
	case TIMER1B: TCCR1A |= ( 1 << TCCR1A_FOC1B ) ; break ;
	case TIMER2 : TCCR2  |= ( 1 << TCCR2_FOC2 )   ; break ;
	default : Local_u8ErrorState = NOK ;
	}
	return Local_u8ErrorState ;
}


u8 TIMER1_u8Init( Timer1_t * psTimer1Config )
{
	u8 Local_u8ErrorState = OK ;
	if( psTimer1Config != NULL )
	{
		if( psTimer1Config -> TimerChannel == TIMER1A )
		{
			switch ( psTimer1Config -> TimerMode )
			{
			case NORMAL_MODE :
				/* BIT MASKING WGM10 & WGM11 ARE ZEROS */
				TCCR1A &= (~ ( ( 1 << TCCR1A_WGM10 ) | ( 1 << TCCR1A_WGM11 ) ) ) ;

				/* BIT MASKING WGM12 & WGM13 ARE ZEROS */
				TCCR1B &= (~ ( ( 1 << TCCR1B_WGM12 ) | ( 1 << TCCR1B_WGM13 ) ) ) ;

				if( psTimer1Config -> CompOutputMode == DISCONNECTED )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ZEROS */
					TCCR1A &= (~ ( ( 1 << TCCR1A_COM1A0 ) | ( 1 << TCCR1A_COM1A1 ) ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == TOGGLE_ON_COMP )
				{
					TCCR1A |= ( 1 << TCCR1A_COM1A0 ) ;
					TCCR1A &= ( ~ ( 1 << TCCR1A_COM1A1 ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == CLR_ON_COMP )
				{
					TCCR1A |= ( 1 << TCCR1A_COM1A1 ) ;
					TCCR1A &= ( ~ ( 1 << TCCR1A_COM1A0 ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == SET_ON_COMP )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ONES */
					TCCR1A |= ( ( 1 << TCCR1A_COM1A0 ) | ( 1 << TCCR1A_COM1A1 ) ) ;
				}
				else
				{
					Local_u8ErrorState = NOK ;
				}
				if( psTimer1Config -> InterruptEnable == ENABLED )
				{
					/* Enable Timer/Counter 1 Overflow Interrupt */
					TIMSK |= ( 1 << TIMSK_TOIE1 ) ;
				}
				break;

			case PWM_PHASE_CORRECT_8_BIT :

				/* Chose PWM , Phase Correct 8 bit  */

				/* BIT MASKING WGM12 & WGM13 ARE ZEROS */
				TCCR1B &= (~ ( ( 1 << TCCR1B_WGM12 ) | ( 1 << TCCR1B_WGM13 ) ) ) ;

				TCCR1A |= ( 1 << TCCR1A_WGM10 ) ;
				TCCR1A &= ( ~ ( 1 << TCCR1A_WGM11 ) ) ;

				if( psTimer1Config -> CompOutputMode == DISCONNECTED )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ZEROS */
					TCCR1A &= (~ ( ( 1 << TCCR1A_COM1A0 ) | ( 1 << TCCR1A_COM1A1 ) ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == CLR_ON_COMP_UP_SET_ON_COMP_DOWN )
				{
					TCCR1A |= ( 1 << TCCR1A_COM1A1 ) ;
					TCCR1A &= ( ~ ( 1 << TCCR1A_COM1A0 ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == SET_ON_COMP_UP_CLR_ON_COMP_DOWN )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ONES */
					TCCR1A |= ( ( 1 << TCCR1A_COM1A0 ) | ( 1 << TCCR1A_COM1A1 ) ) ;
				}
				else
				{
					Local_u8ErrorState = NOK ;
				}
				break ;

			case PWM_PHASE_CORRECT_9_BIT :

				/* Chose PWM , Phase Correct 9 bit  */

				/* BIT MASKING WGM12 & WGM13 ARE ZEROS */
				TCCR1B &= (~ ( ( 1 << TCCR1B_WGM12 ) | ( 1 << TCCR1B_WGM13 ) ) ) ;

				TCCR1A |= ( 1 << TCCR1A_WGM11 ) ;
				TCCR1A &= ( ~ ( 1 << TCCR1A_WGM10 ) ) ;

				if( psTimer1Config -> CompOutputMode == DISCONNECTED )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ZEROS */
					TCCR1A &= (~ ( ( 1 << TCCR1A_COM1A0 ) | ( 1 << TCCR1A_COM1A1 ) ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == CLR_ON_COMP_UP_SET_ON_COMP_DOWN )
				{
					TCCR1A |= ( 1 << TCCR1A_COM1A1 ) ;
					TCCR1A &= ( ~ ( 1 << TCCR1A_COM1A0 ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == SET_ON_COMP_UP_CLR_ON_COMP_DOWN )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ONES */
					TCCR1A |= ( ( 1 << TCCR1A_COM1A0 ) | ( 1 << TCCR1A_COM1A1 ) ) ;
				}
				else
				{
					Local_u8ErrorState = NOK ;
				}
				break ;

			case PWM_PHASE_CORRECT_10_BIT :

				/* Chose PWM , Phase Correct 10 bit  */

				/* BIT MASKING WGM12 & WGM13 ARE ZEROS */
				TCCR1B &= (~ ( ( 1 << TCCR1B_WGM12 ) | ( 1 << TCCR1B_WGM13 ) ) ) ;
				/* BIT MASKING WGM11 & WGM10 ARE ONES */
				TCCR1A |= ( ( 1 << TCCR1A_WGM11 ) | ( 1 << TCCR1A_WGM10 ) ) ;


				if( psTimer1Config -> CompOutputMode == DISCONNECTED )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ZEROS */
					TCCR1A &= (~ ( ( 1 << TCCR1A_COM1A0 ) | ( 1 << TCCR1A_COM1A1 ) ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == CLR_ON_COMP_UP_SET_ON_COMP_DOWN )
				{
					TCCR1A |= ( 1 << TCCR1A_COM1A1 ) ;
					TCCR1A &= ( ~ ( 1 << TCCR1A_COM1A0 ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == SET_ON_COMP_UP_CLR_ON_COMP_DOWN )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ONES */
					TCCR1A |= ( ( 1 << TCCR1A_COM1A0 ) | ( 1 << TCCR1A_COM1A1 ) ) ;
				}
				else
				{
					Local_u8ErrorState = NOK ;
				}
				break ;

			case CTC_MODE_TOP_IN_OCR1A :

				/* CTC MODE TOP IN OCR1A REGISTER */

				/* BIT MASKING WGM10 & WGM11 ARE ZEROS */
				TCCR1A &= (~ ( ( 1 << TCCR1A_WGM10 ) | ( 1 << TCCR1A_WGM11 ) ) ) ;

				TCCR1B |= ( 1 << TCCR1B_WGM12 ) ;
				TCCR1B &= ( ~ ( 1 << TCCR1B_WGM13 ) ) ;

				if( psTimer1Config -> CompOutputMode == DISCONNECTED )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ZEROS */
					TCCR1A &= (~ ( ( 1 << TCCR1A_COM1A0 ) | ( 1 << TCCR1A_COM1A1 ) ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == TOGGLE_ON_COMP )
				{
					TCCR1A |= ( 1 << TCCR1A_COM1A0 ) ;
					TCCR1A &= ( ~ ( 1 << TCCR1A_COM1A1 ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == CLR_ON_COMP )
				{
					TCCR1A |= ( 1 << TCCR1A_COM1A1 ) ;
					TCCR1A &= ( ~ ( 1 << TCCR1A_COM1A0 ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == SET_ON_COMP )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ONES */
					TCCR1A |= ( ( 1 << TCCR1A_COM1A0 ) | ( 1 << TCCR1A_COM1A1 ) ) ;
				}
				else
				{
					Local_u8ErrorState = NOK ;
				}
				if( psTimer1Config -> InterruptEnable == ENABLED )
				{
					TIMSK |= ( 1 << TIMSK_OCIE1A ) ;
				}
				break;

			case FAST_PWM_8_BIT :

				/* Chosing Fast PWM 8 Bit */
				TCCR1A |= ( 1 << TCCR1A_WGM10 );
				TCCR1A &= ( ~ ( 1 << TCCR1A_WGM11 ) );
				TCCR1B &= ( ~ ( 1 << TCCR1B_WGM13 ) );
				TCCR1B |= ( 1 << TCCR1B_WGM12 ) ;

				if( psTimer1Config -> CompOutputMode == DISCONNECTED )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ZEROS */
					TCCR1A &= (~ ( ( 1 << TCCR1A_COM1A0 ) | ( 1 << TCCR1A_COM1A1 ) ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == CLR_ON_COMP_SET_ON_TOP )
				{
					TCCR1A |= ( 1 << TCCR1A_COM1A1 ) ;
					TCCR1A &= ( ~ ( 1 << TCCR1A_COM1A0 ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == SET_ON_COMP_CLR_ON_TOP )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ONES */
					TCCR1A |= ( ( 1 << TCCR1A_COM1A0 ) | ( 1 << TCCR1A_COM1A1 ) ) ;
				}
				else
				{
					Local_u8ErrorState = NOK ;
				}
				break;

			case FAST_PWM_9_BIT :

				/* Chosing Fast PWM 9 Bit */
				TCCR1A |= ( 1 << TCCR1A_WGM11 );
				TCCR1A &= ( ~ ( 1 << TCCR1A_WGM10 ) );
				TCCR1B &= ( ~ ( 1 << TCCR1B_WGM13 ) );
				TCCR1B |= ( 1 << TCCR1B_WGM12 ) ;

				if( psTimer1Config -> CompOutputMode == DISCONNECTED )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ZEROS */
					TCCR1A &= (~ ( ( 1 << TCCR1A_COM1A0 ) | ( 1 << TCCR1A_COM1A1 ) ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == CLR_ON_COMP_SET_ON_TOP )
				{
					TCCR1A |= ( 1 << TCCR1A_COM1A1 ) ;
					TCCR1A &= ( ~ ( 1 << TCCR1A_COM1A0 ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == SET_ON_COMP_CLR_ON_TOP )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ONES */
					TCCR1A |= ( ( 1 << TCCR1A_COM1A0 ) | ( 1 << TCCR1A_COM1A1 ) ) ;
				}
				else
				{
					Local_u8ErrorState = NOK ;
				}
				break;

			case FAST_PWM_10_BIT :

				/* Chosing Fast PWM 10 Bit */
				TCCR1A |= ( 1 << TCCR1A_WGM11 ) ;
				TCCR1A |= ( 1 << TCCR1A_WGM10 ) ;
				TCCR1B &= ( ~ ( 1 << TCCR1B_WGM13 ) );
				TCCR1B |= ( 1 << TCCR1B_WGM12 ) ;

				if( psTimer1Config -> CompOutputMode == DISCONNECTED )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ZEROS */
					TCCR1A &= (~ ( ( 1 << TCCR1A_COM1A0 ) | ( 1 << TCCR1A_COM1A1 ) ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == CLR_ON_COMP_SET_ON_TOP )
				{
					TCCR1A |= ( 1 << TCCR1A_COM1A1 ) ;
					TCCR1A &= ( ~ ( 1 << TCCR1A_COM1A0 ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == SET_ON_COMP_CLR_ON_TOP )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ONES */
					TCCR1A |= ( ( 1 << TCCR1A_COM1A0 ) | ( 1 << TCCR1A_COM1A1 ) ) ;
				}
				else
				{
					Local_u8ErrorState = NOK ;
				}
				break;

			case PWM_PHASE_CORRECT_TOP_IN_ICR1 :

				/* Chosing Phase Correct PWM Top IN ICR1 Register */
				TCCR1A |= ( 1 << TCCR1A_WGM11 );
				TCCR1A &= ( ~ ( 1 << TCCR1A_WGM10 ) );
				TCCR1B &= ( ~ ( 1 << TCCR1B_WGM12 ) );
				TCCR1B |= ( 1 << TCCR1B_WGM13 ) ;


				if( psTimer1Config -> CompOutputMode == DISCONNECTED )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ZEROS */
					TCCR1A &= (~ ( ( 1 << TCCR1A_COM1A0 ) | ( 1 << TCCR1A_COM1A1 ) ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == CLR_ON_COMP_UP_SET_ON_COMP_DOWN )
				{
					TCCR1A |= ( 1 << TCCR1A_COM1A1 ) ;
					TCCR1A &= ( ~ ( 1 << TCCR1A_COM1A0 ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == SET_ON_COMP_UP_CLR_ON_COMP_DOWN )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ONES */
					TCCR1A |= ( ( 1 << TCCR1A_COM1A0 ) | ( 1 << TCCR1A_COM1A1 ) ) ;
				}
				else
				{
					Local_u8ErrorState = NOK ;
				}
				break ;

			case PWM_PHASE_CORRECT_TOP_IN_OCR1A :

				/* Chosing Phase Correct PWM Top IN ICR1 Register */
				TCCR1A |= ( 1 << TCCR1A_WGM11 );
				TCCR1A |= ( 1 << TCCR1A_WGM10 );
				TCCR1B &= ( ~ ( 1 << TCCR1B_WGM12 ) );
				TCCR1B |= ( 1 << TCCR1B_WGM13 ) ;


				if( psTimer1Config -> CompOutputMode == DISCONNECTED )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ZEROS */
					TCCR1A &= (~ ( ( 1 << TCCR1A_COM1A0 ) | ( 1 << TCCR1A_COM1A1 ) ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == CLR_ON_COMP_UP_SET_ON_COMP_DOWN )
				{
					TCCR1A |= ( 1 << TCCR1A_COM1A1 ) ;
					TCCR1A &= ( ~ ( 1 << TCCR1A_COM1A0 ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == SET_ON_COMP_UP_CLR_ON_COMP_DOWN )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ONES */
					TCCR1A |= ( ( 1 << TCCR1A_COM1A0 ) | ( 1 << TCCR1A_COM1A1 ) ) ;
				}
				else
				{
					Local_u8ErrorState = NOK ;
				}
				break ;

			case CTC_MODE_TOP_IN_ICR1 :

				/* CTC MODE TOP IN OCR1A REGISTER */

				/* BIT MASKING WGM10 & WGM11 ARE ZEROS */
				TCCR1A &= (~ ( ( 1 << TCCR1A_WGM10 ) | ( 1 << TCCR1A_WGM11 ) ) ) ;

				TCCR1B |= ( 1 << TCCR1B_WGM12 ) ;
				TCCR1B &= ( ~ ( 1 << TCCR1B_WGM13 ) ) ;

				if( psTimer1Config -> CompOutputMode == DISCONNECTED )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ZEROS */
					TCCR1A &= (~ ( ( 1 << TCCR1A_COM1A0 ) | ( 1 << TCCR1A_COM1A1 ) ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == TOGGLE_ON_COMP )
				{
					TCCR1A |= ( 1 << TCCR1A_COM1A0 ) ;
					TCCR1A &= ( ~ ( 1 << TCCR1A_COM1A1 ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == CLR_ON_COMP )
				{
					TCCR1A |= ( 1 << TCCR1A_COM1A1 ) ;
					TCCR1A &= ( ~ ( 1 << TCCR1A_COM1A0 ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == SET_ON_COMP )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ONES */
					TCCR1A |= ( ( 1 << TCCR1A_COM1A0 ) | ( 1 << TCCR1A_COM1A1 ) ) ;
				}
				else
				{
					Local_u8ErrorState = NOK ;
				}
				if( psTimer1Config -> InterruptEnable == ENABLED )
				{
					TIMSK |= ( 1 << TIMSK_OCIE1A ) ;
				}
				break;

			case FAST_PWM_TOP_IN_ICR1 :

				/* Chosing Fast Top Value in ICR1 Register */
				TCCR1A |= ( 1 << TCCR1A_WGM11 ) ;
				TCCR1A &= ( ~ ( 1 << TCCR1A_WGM10 ) ) ;
				TCCR1B |= ( 1 << TCCR1B_WGM12 ) ;
				TCCR1B |= ( 1 << TCCR1B_WGM13 ) ;

				if( psTimer1Config -> CompOutputMode == DISCONNECTED )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ZEROS */
					TCCR1A &= (~ ( ( 1 << TCCR1A_COM1A0 ) | ( 1 << TCCR1A_COM1A1 ) ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == CLR_ON_COMP_SET_ON_TOP )
				{
					TCCR1A |= ( 1 << TCCR1A_COM1A1 ) ;
					TCCR1A &= ( ~ ( 1 << TCCR1A_COM1A0 ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == SET_ON_COMP_CLR_ON_TOP )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ONES */
					TCCR1A |= ( ( 1 << TCCR1A_COM1A0 ) | ( 1 << TCCR1A_COM1A1 ) ) ;
				}
				else
				{
					Local_u8ErrorState = NOK ;
				}
				break;

			case FAST_PWM_TOP_IN_OCR1A :

				/* Chosing Fast Top Value in OCR1A Register */
				TCCR1A |= ( ( 1 << TCCR1A_WGM11 ) | ( 1 << TCCR1A_WGM10 ) ) ;
				TCCR1B |= ( ( 1 << TCCR1B_WGM12 ) | ( 1 << TCCR1B_WGM13 ) ) ;

				if( psTimer1Config -> CompOutputMode == DISCONNECTED )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ZEROS */
					TCCR1A &= (~ ( ( 1 << TCCR1A_COM1A0 ) | ( 1 << TCCR1A_COM1A1 ) ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == CLR_ON_COMP_SET_ON_TOP )
				{
					TCCR1A |= ( 1 << TCCR1A_COM1A1 ) ;
					TCCR1A &= ( ~ ( 1 << TCCR1A_COM1A0 ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == SET_ON_COMP_CLR_ON_TOP )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ONES */
					TCCR1A |= ( ( 1 << TCCR1A_COM1A0 ) | ( 1 << TCCR1A_COM1A1 ) ) ;
				}
				else
				{
					Local_u8ErrorState = NOK ;
				}
				break;
			}
		}
		else if( psTimer1Config -> TimerChannel == TIMER1B )
		{
			switch ( psTimer1Config -> TimerMode )
			{
			case NORMAL_MODE :
				/* BIT MASKING WGM10 & WGM11 ARE ZEROS */
				TCCR1A &= (~ ( ( 1 << TCCR1A_WGM10 ) | ( 1 << TCCR1A_WGM11 ) ) ) ;

				/* BIT MASKING WGM12 & WGM13 ARE ZEROS */
				TCCR1B &= (~ ( ( 1 << TCCR1B_WGM12 ) | ( 1 << TCCR1B_WGM13 ) ) ) ;

				if( psTimer1Config -> CompOutputMode == DISCONNECTED )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ZEROS */
					TCCR1A &= (~ ( ( 1 << TCCR1A_COM1B0 ) | ( 1 << TCCR1A_COM1B1 ) ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == TOGGLE_ON_COMP )
				{
					TCCR1A |= ( 1 << TCCR1A_COM1B0 ) ;
					TCCR1A &= ( ~ ( 1 << TCCR1A_COM1B1 ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == CLR_ON_COMP )
				{
					TCCR1A |= ( 1 << TCCR1A_COM1B1 ) ;
					TCCR1A &= ( ~ ( 1 << TCCR1A_COM1B0 ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == SET_ON_COMP )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ONES */
					TCCR1A |= ( ( 1 << TCCR1A_COM1B0 ) | ( 1 << TCCR1A_COM1B1 ) ) ;
				}
				else
				{
					Local_u8ErrorState = NOK ;
				}
				if( psTimer1Config -> InterruptEnable == ENABLED )
				{
					/* Enable Timer/Counter 1 Overflow Interrupt */
					TIMSK |= ( 1 << TIMSK_TOIE1 ) ;
				}
				break;

			case PWM_PHASE_CORRECT_8_BIT :

				/* Chose PWM , Phase Correct 8 bit  */

				/* BIT MASKING WGM12 & WGM13 ARE ZEROS */
				TCCR1B &= (~ ( ( 1 << TCCR1B_WGM12 ) | ( 1 << TCCR1B_WGM13 ) ) ) ;

				TCCR1A |= ( 1 << TCCR1A_WGM10 ) ;
				TCCR1A &= ( ~ ( 1 << TCCR1A_WGM11 ) ) ;

				if( psTimer1Config -> CompOutputMode == DISCONNECTED )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ZEROS */
					TCCR1A &= (~ ( ( 1 << TCCR1A_COM1B0 ) | ( 1 << TCCR1A_COM1B1 ) ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == CLR_ON_COMP_UP_SET_ON_COMP_DOWN )
				{
					TCCR1A |= ( 1 << TCCR1A_COM1B1 ) ;
					TCCR1A &= ( ~ ( 1 << TCCR1A_COM1B0 ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == SET_ON_COMP_UP_CLR_ON_COMP_DOWN )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ONES */
					TCCR1A |= ( ( 1 << TCCR1A_COM1B0 ) | ( 1 << TCCR1A_COM1B1 ) ) ;
				}
				else
				{
					Local_u8ErrorState = NOK ;
				}
				break ;

			case PWM_PHASE_CORRECT_9_BIT :

				/* Chose PWM , Phase Correct 9 bit  */

				/* BIT MASKING WGM12 & WGM13 ARE ZEROS */
				TCCR1B &= (~ ( ( 1 << TCCR1B_WGM12 ) | ( 1 << TCCR1B_WGM13 ) ) ) ;

				TCCR1A |= ( 1 << TCCR1A_WGM11 ) ;
				TCCR1A &= ( ~ ( 1 << TCCR1A_WGM10 ) ) ;

				if( psTimer1Config -> CompOutputMode == DISCONNECTED )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ZEROS */
					TCCR1A &= (~ ( ( 1 << TCCR1A_COM1B0 ) | ( 1 << TCCR1A_COM1B1 ) ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == CLR_ON_COMP_UP_SET_ON_COMP_DOWN )
				{
					TCCR1A |= ( 1 << TCCR1A_COM1B1 ) ;
					TCCR1A &= ( ~ ( 1 << TCCR1A_COM1B0 ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == SET_ON_COMP_UP_CLR_ON_COMP_DOWN )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ONES */
					TCCR1A |= ( ( 1 << TCCR1A_COM1B0 ) | ( 1 << TCCR1A_COM1B1 ) ) ;
				}
				else
				{
					Local_u8ErrorState = NOK ;
				}
				break ;

			case PWM_PHASE_CORRECT_10_BIT :

				/* Chose PWM , Phase Correct 10 bit  */

				/* BIT MASKING WGM12 & WGM13 ARE ZEROS */
				TCCR1B &= (~ ( ( 1 << TCCR1B_WGM12 ) | ( 1 << TCCR1B_WGM13 ) ) ) ;
				/* BIT MASKING WGM11 & WGM10 ARE ONES */
				TCCR1A |= ( ( 1 << TCCR1A_WGM11 ) | ( 1 << TCCR1A_WGM10 ) ) ;


				if( psTimer1Config -> CompOutputMode == DISCONNECTED )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ZEROS */
					TCCR1A &= (~ ( ( 1 << TCCR1A_COM1B0 ) | ( 1 << TCCR1A_COM1B1 ) ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == CLR_ON_COMP_UP_SET_ON_COMP_DOWN )
				{
					TCCR1A |= ( 1 << TCCR1A_COM1B1 ) ;
					TCCR1A &= ( ~ ( 1 << TCCR1A_COM1B0 ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == SET_ON_COMP_UP_CLR_ON_COMP_DOWN )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ONES */
					TCCR1A |= ( ( 1 << TCCR1A_COM1B0 ) | ( 1 << TCCR1A_COM1B1 ) ) ;
				}
				else
				{
					Local_u8ErrorState = NOK ;
				}
				break ;

			case CTC_MODE_TOP_IN_OCR1A :

				/* CTC MODE TOP IN OCR1A REGISTER */

				/* BIT MASKING WGM10 & WGM11 ARE ZEROS */
				TCCR1A &= (~ ( ( 1 << TCCR1A_WGM10 ) | ( 1 << TCCR1A_WGM11 ) ) ) ;

				TCCR1B |= ( 1 << TCCR1B_WGM12 ) ;
				TCCR1B &= ( ~ ( 1 << TCCR1B_WGM13 ) ) ;

				if( psTimer1Config -> CompOutputMode == DISCONNECTED )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ZEROS */
					TCCR1A &= (~ ( ( 1 << TCCR1A_COM1B0 ) | ( 1 << TCCR1A_COM1B1 ) ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == TOGGLE_ON_COMP )
				{
					TCCR1A |= ( 1 << TCCR1A_COM1B0 ) ;
					TCCR1A &= ( ~ ( 1 << TCCR1A_COM1B1 ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == CLR_ON_COMP )
				{
					TCCR1A |= ( 1 << TCCR1A_COM1B1 ) ;
					TCCR1A &= ( ~ ( 1 << TCCR1A_COM1B0 ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == SET_ON_COMP )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ONES */
					TCCR1A |= ( ( 1 << TCCR1A_COM1B0 ) | ( 1 << TCCR1A_COM1B1 ) ) ;
				}
				else
				{
					Local_u8ErrorState = NOK ;
				}
				if( psTimer1Config -> InterruptEnable == ENABLED )
				{
					TIMSK |= ( 1 << TIMSK_OCIE1B ) ;
				}
				break;

			case FAST_PWM_8_BIT :

				/* Chosing Fast PWM 8 Bit */
				TCCR1A |= ( 1 << TCCR1A_WGM10 );
				TCCR1A &= ( ~ ( 1 << TCCR1A_WGM11 ) );
				TCCR1B &= ( ~ ( 1 << TCCR1B_WGM13 ) );
				TCCR1B |= ( 1 << TCCR1B_WGM12 ) ;

				if( psTimer1Config -> CompOutputMode == DISCONNECTED )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ZEROS */
					TCCR1A &= (~ ( ( 1 << TCCR1A_COM1B0 ) | ( 1 << TCCR1A_COM1B1 ) ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == CLR_ON_COMP_SET_ON_TOP )
				{
					TCCR1A |= ( 1 << TCCR1A_COM1B1 ) ;
					TCCR1A &= ( ~ ( 1 << TCCR1A_COM1B0 ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == SET_ON_COMP_CLR_ON_TOP )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ONES */
					TCCR1A |= ( ( 1 << TCCR1A_COM1B0 ) | ( 1 << TCCR1A_COM1B1 ) ) ;
				}
				else
				{
					Local_u8ErrorState = NOK ;
				}
				break;

			case FAST_PWM_9_BIT :

				/* Chosing Fast PWM 9 Bit */
				TCCR1A |= ( 1 << TCCR1A_WGM11 );
				TCCR1A &= ( ~ ( 1 << TCCR1A_WGM10 ) );
				TCCR1B &= ( ~ ( 1 << TCCR1B_WGM13 ) );
				TCCR1B |= ( 1 << TCCR1B_WGM12 ) ;

				if( psTimer1Config -> CompOutputMode == DISCONNECTED )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ZEROS */
					TCCR1A &= (~ ( ( 1 << TCCR1A_COM1B0 ) | ( 1 << TCCR1A_COM1B1 ) ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == CLR_ON_COMP_SET_ON_TOP )
				{
					TCCR1A |= ( 1 << TCCR1A_COM1B1 ) ;
					TCCR1A &= ( ~ ( 1 << TCCR1A_COM1B0 ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == SET_ON_COMP_CLR_ON_TOP )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ONES */
					TCCR1A |= ( ( 1 << TCCR1A_COM1B0 ) | ( 1 << TCCR1A_COM1B1 ) ) ;
				}
				else
				{
					Local_u8ErrorState = NOK ;
				}
				break;

			case FAST_PWM_10_BIT :

				/* Chosing Fast PWM 10 Bit */
				TCCR1A |= ( 1 << TCCR1A_WGM11 ) ;
				TCCR1A |= ( 1 << TCCR1A_WGM10 ) ;
				TCCR1B &= ( ~ ( 1 << TCCR1B_WGM13 ) );
				TCCR1B |= ( 1 << TCCR1B_WGM12 ) ;

				if( psTimer1Config -> CompOutputMode == DISCONNECTED )
				{
					/* BIT MASKING COM1B0 & COM1B1 ARE ZEROS */
					TCCR1A &= (~ ( ( 1 << TCCR1A_COM1B0 ) | ( 1 << TCCR1A_COM1B1 ) ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == CLR_ON_COMP_SET_ON_TOP )
				{
					TCCR1A |= ( 1 << TCCR1A_COM1B1 ) ;
					TCCR1A &= ( ~ ( 1 << TCCR1A_COM1B0 ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == SET_ON_COMP_CLR_ON_TOP )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ONES */
					TCCR1A |= ( ( 1 << TCCR1A_COM1B0 ) | ( 1 << TCCR1A_COM1B1 ) ) ;
				}
				else
				{
					Local_u8ErrorState = NOK ;
				}
				break;

			case PWM_PHASE_CORRECT_TOP_IN_ICR1 :

				/* Chosing Phase Correct PWM Top IN ICR1 Register */
				TCCR1A |= ( 1 << TCCR1A_WGM11 );
				TCCR1A &= ( ~ ( 1 << TCCR1A_WGM10 ) );
				TCCR1B &= ( ~ ( 1 << TCCR1B_WGM12 ) );
				TCCR1B |= ( 1 << TCCR1B_WGM13 ) ;


				if( psTimer1Config -> CompOutputMode == DISCONNECTED )
				{
					/* BIT MASKING COM1B0 & COM1B1 ARE ZEROS */
					TCCR1A &= (~ ( ( 1 << TCCR1A_COM1B0 ) | ( 1 << TCCR1A_COM1B1 ) ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == CLR_ON_COMP_UP_SET_ON_COMP_DOWN )
				{
					TCCR1A |= ( 1 << TCCR1A_COM1B1 ) ;
					TCCR1A &= ( ~ ( 1 << TCCR1A_COM1B0 ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == SET_ON_COMP_UP_CLR_ON_COMP_DOWN )
				{
					/* BIT MASKING COM1B0 & COM1B1 ARE ONES */
					TCCR1A |= ( ( 1 << TCCR1A_COM1A0 ) | ( 1 << TCCR1A_COM1A1 ) ) ;
				}
				else
				{
					Local_u8ErrorState = NOK ;
				}
				break ;

			case PWM_PHASE_CORRECT_TOP_IN_OCR1A :

				/* Chosing Phase Correct PWM Top IN ICR1 Register */
				TCCR1A |= ( 1 << TCCR1A_WGM11 );
				TCCR1A |= ( 1 << TCCR1A_WGM10 );
				TCCR1B &= ( ~ ( 1 << TCCR1B_WGM12 ) );
				TCCR1B |= ( 1 << TCCR1B_WGM13 ) ;


				if( psTimer1Config -> CompOutputMode == DISCONNECTED )
				{
					/* BIT MASKING COM1B0 & COM1B1 ARE ZEROS */
					TCCR1A &= (~ ( ( 1 << TCCR1A_COM1B0 ) | ( 1 << TCCR1A_COM1B1 ) ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == CLR_ON_COMP_UP_SET_ON_COMP_DOWN )
				{
					TCCR1A |= ( 1 << TCCR1A_COM1B1 ) ;
					TCCR1A &= ( ~ ( 1 << TCCR1A_COM1B0 ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == SET_ON_COMP_UP_CLR_ON_COMP_DOWN )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ONES */
					TCCR1A |= ( ( 1 << TCCR1A_COM1B0 ) | ( 1 << TCCR1A_COM1B1 ) ) ;
				}
				else
				{
					Local_u8ErrorState = NOK ;
				}
				break ;

			case CTC_MODE_TOP_IN_ICR1 :

				/* CTC MODE TOP IN OCR1A REGISTER */

				/* BIT MASKING WGM10 & WGM11 ARE ZEROS */
				TCCR1A &= (~ ( ( 1 << TCCR1A_WGM10 ) | ( 1 << TCCR1A_WGM11 ) ) ) ;

				TCCR1B |= ( 1 << TCCR1B_WGM12 ) ;
				TCCR1B &= ( ~ ( 1 << TCCR1B_WGM13 ) ) ;

				if( psTimer1Config -> CompOutputMode == DISCONNECTED )
				{
					/* BIT MASKING COM1B0 & COM1B1 ARE ZEROS */
					TCCR1A &= (~ ( ( 1 << TCCR1A_COM1B0 ) | ( 1 << TCCR1A_COM1B1 ) ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == TOGGLE_ON_COMP )
				{
					TCCR1A |= ( 1 << TCCR1A_COM1B0 ) ;
					TCCR1A &= ( ~ ( 1 << TCCR1A_COM1B1 ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == CLR_ON_COMP )
				{
					TCCR1A |= ( 1 << TCCR1A_COM1B1 ) ;
					TCCR1A &= ( ~ ( 1 << TCCR1A_COM1B0 ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == SET_ON_COMP )
				{
					/* BIT MASKING COM1A0 & COM1A1 ARE ONES */
					TCCR1A |= ( ( 1 << TCCR1A_COM1B0 ) | ( 1 << TCCR1A_COM1B1 ) ) ;
				}
				else
				{
					Local_u8ErrorState = NOK ;
				}
				if( psTimer1Config -> InterruptEnable == ENABLED )
				{
					TIMSK |= ( 1 << TIMSK_OCIE1B ) ;
				}
				break;

			case FAST_PWM_TOP_IN_ICR1 :

				/* Chosing Fast Top Value in ICR1 Register */
				TCCR1A |= ( 1 << TCCR1A_WGM11 ) ;
				TCCR1A &= ( ~ ( 1 << TCCR1A_WGM10 ) ) ;
				TCCR1B |= ( 1 << TCCR1B_WGM12 ) ;
				TCCR1B |= ( 1 << TCCR1B_WGM13 ) ;

				if( psTimer1Config -> CompOutputMode == DISCONNECTED )
				{
					/* BIT MASKING COM1B0 & COM1B1 ARE ZEROS */
					TCCR1A &= (~ ( ( 1 << TCCR1A_COM1B0 ) | ( 1 << TCCR1A_COM1B1 ) ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == CLR_ON_COMP_SET_ON_TOP )
				{
					TCCR1A |= ( 1 << TCCR1A_COM1B1 ) ;
					TCCR1A &= ( ~ ( 1 << TCCR1A_COM1B0 ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == SET_ON_COMP_CLR_ON_TOP )
				{
					/* BIT MASKING COM1B0 & COM1B1 ARE ONES */
					TCCR1A |= ( ( 1 << TCCR1A_COM1B0 ) | ( 1 << TCCR1A_COM1B1 ) ) ;
				}
				else
				{
					Local_u8ErrorState = NOK ;
				}
				break;

			case FAST_PWM_TOP_IN_OCR1A :

				/* Chosing Fast Top Value in OCR1A Register */
				TCCR1A |= ( ( 1 << TCCR1A_WGM11 ) | ( 1 << TCCR1A_WGM10 ) ) ;
				TCCR1B |= ( ( 1 << TCCR1B_WGM12 ) | ( 1 << TCCR1B_WGM13 ) ) ;

				if( psTimer1Config -> CompOutputMode == DISCONNECTED )
				{
					/* BIT MASKING COM1B0 & COM1B1 ARE ZEROS */
					TCCR1A &= (~ ( ( 1 << TCCR1A_COM1B0 ) | ( 1 << TCCR1A_COM1B1 ) ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == CLR_ON_COMP_SET_ON_TOP )
				{
					TCCR1A |= ( 1 << TCCR1A_COM1B1 ) ;
					TCCR1A &= ( ~ ( 1 << TCCR1A_COM1B0 ) ) ;
				}
				else if( psTimer1Config -> CompOutputMode == SET_ON_COMP_CLR_ON_TOP )
				{
					/* BIT MASKING COM1B0 & COM1B1 ARE ONES */
					TCCR1A |= ( ( 1 << TCCR1A_COM1B0 ) | ( 1 << TCCR1A_COM1B1 ) ) ;
				}
				else
				{
					Local_u8ErrorState = NOK ;
				}
				break;
			}
		}
		else{
			Local_u8ErrorState = NOK ;
		}

		/* Check if Prescaler In Range */
		if( ( psTimer1Config -> Prescaler >= PRESC_1_NO_CLK_SOURCE ) && ( psTimer1Config -> Prescaler <= PRESC_1_CLK_ON_RISING_EDGE_T1  ) )
		{
			/* Set Prescaler */
			TCCR1B &= ( TIMER_PRESC_MASK ) ;
			TCCR1B |= ( psTimer1Config -> Prescaler ) ;
		}
		else
		{
			Local_u8ErrorState = NOK ;
		}

	}
	else
	{
		Local_u8ErrorState = NOK ;
	}
	return Local_u8ErrorState ;
}


void TIMER1_voidSetICRValue( u16 Copy_u16ICRTopValue )
{
	ICR1 = Copy_u16ICRTopValue ;
}


void ICU_voidInit( void )
{
	/* Set Trigger Source to Rising Edge Initially */
	TCCR1B |= ( 1 << TCCR1B_ICES1 ) ;

	/* Input Capture Interrupt Enable */
	TIMSK |= ( 1 << TIMSK_TICIE1 ) ;
}

u8 ICU_voidSetTriggerEdge( u8 Copy_u8TriggerEdge )
{
	u8 Local_u8ErrorState = OK ;

	if( Copy_u8TriggerEdge == ICU_FALLING_EDGE )
	{
		TCCR1B &= ( ~ ( 1 << TCCR1B_ICES1 ) ) ;
	}
	else if( Copy_u8TriggerEdge == ICU_RISING_EDGE )
	{
		TCCR1B |= ( 1 << TCCR1B_ICES1 ) ;
	}
	else
	{
		Local_u8ErrorState = NOK ;
	}

	return Local_u8ErrorState ;
}



u16 ICU_u16ReadInputCapture( void )
{
	return ICR1 ;
}

/*------------------------------------------------------------------*/
/*----------------------------- ISR --------------------------------*/
/*------------------------------------------------------------------*/


/* TIMER2 COMPARE MATCH ISR  */
void __vector_4  (void)       __attribute__((signal)) ;
void __vector_4  (void)
{
	if( TIMERS_pvCallBackFunction[ TIMER2_COMP ] != NULL )
	{
		TIMERS_pvCallBackFunction [ TIMER2_COMP ] ( ) ;
	}

}

/* TIMER2 OVERFLOW ISR */
void __vector_5  (void)       __attribute__((signal)) ;
void __vector_5  (void)
{
	if( TIMERS_pvCallBackFunction[ TIMER2_OVF ] != NULL )
	{
		TIMERS_pvCallBackFunction [ TIMER2_OVF ] ( ) ;
	}

}

/* TIMER1 CAPTURE EVENT ( ICU ) ISR */
void __vector_6  (void)   __attribute__((signal));
void __vector_6  (void)
{
	if( TIMERS_pvCallBackFunction[ TIMER1_CAPT ] != NULL )
	{
		TIMERS_pvCallBackFunction [ TIMER1_CAPT ] ( ) ;
	}
}

/* TIMER1 COMPARE MATCH A ISR */
void __vector_7  (void)   __attribute__((signal));
void __vector_7  (void)
{
	if( TIMERS_pvCallBackFunction[ TIMER1_COMPA ] != NULL )
	{
		TIMERS_pvCallBackFunction [ TIMER1_COMPA ] ( ) ;
	}
}

/* TIMER1 COMPARE MATCH B ISR */
void __vector_8  (void)   __attribute__((signal));
void __vector_8  (void)
{
	if( TIMERS_pvCallBackFunction[ TIMER1_COMPB ] != NULL )
	{
		TIMERS_pvCallBackFunction [ TIMER1_COMPB ] ( ) ;
	}
}

/* TIMER1 OVERFLOW ISR */
void __vector_9  (void)   __attribute__((signal));
void __vector_9  (void)
{
	if( TIMERS_pvCallBackFunction[ TIMER1_OVF ] != NULL )
	{
		TIMERS_pvCallBackFunction [ TIMER1_OVF ] ( ) ;
	}
}

/* TIMER0 COMPARE MATCH ISR */
void __vector_10  (void)   __attribute__((signal));
void __vector_10  (void)
{
	if( TIMERS_pvCallBackFunction[ TIMER0_COMP ] != NULL )
	{
		TIMERS_pvCallBackFunction [ TIMER0_COMP ] ( ) ;
	}
}

/* TIMER0 OVERFLOW ISR */
void __vector_11  (void)   __attribute__((signal));
void __vector_11  (void)
{
	if( TIMERS_pvCallBackFunction[ TIMER0_OVF ] != NULL )
	{
		TIMERS_pvCallBackFunction [ TIMER0_OVF ] ( ) ;
	}
}
