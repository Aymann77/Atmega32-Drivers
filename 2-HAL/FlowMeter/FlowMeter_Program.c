/*
 * FlowMeter_Program.c
 *
 *  Created on: Nov 6, 2022
 *      Author: moham
 */

#include "../../4-LIB/STD_TYPES.h"

#include "FlowMeter_Config.h"
#include "FlowMeter_Interface.h"
#include "FlowMeter_Private.h"
#include "../../1-MCAL/EXTI/EXTI_Interface.h"
#include "../../1-MCAL/TIMER/TIMER_Interface.h"

u16 * FLOWMETER_VolumeReading = NULL ;
u16 * FLOWMETER_FlowRate = NULL ;

u16 Frequency  = 0 ;
u16 Volume = 0 ;
u16 FlowRate_ml_s = 0 ;

u8 ISR_Flag = UNDONE ;

u16 Previous_Freq = 0;

u8 Function_Called = CALLED_ONCE ;

void FLOWMETER_Init( u16 * Copy_pu16VolumeInSec , u16 * Copy_pu16FlowRate )
{
	Timer0_t T1 = { NORMAL_MODE , DISCONNECTED , PRESC_0_DIVIDE_BY_8 , ENABLED } ;
	/*Intialize Global Variable to Carry Volume*/
	FLOWMETER_VolumeReading = Copy_pu16VolumeInSec ;

	/*Intialize Global Variable to Carry Flow Rate*/
	FLOWMETER_FlowRate = Copy_pu16FlowRate ;

	/*EXTI2 Init and Set Call Back */
	EXTI_u8Int2SenseControl(RISING_EDGE);
	EXTI_u8Int2CallBack( &EXTI ) ;
	EXTI_u8IntEnable(INT2);

	/*Timer0 Init and Set Call Back*/
	TIMER0_u8Init( &T1 );
	TIMER_u8SetCallBack( TIMER_ISR , TIMER0_OVF ) ;
}

void FLOWMETER_voidGetVolume( u16 * Copy_pu16VolumeInSec , u16 * Copy_pu16FlowRate )
{
	if( Function_Called == CALLED_ONCE )
	{
		Function_Called = CALLED_MORE_THAN_ONCE;
		FLOWMETER_Init( Copy_pu16VolumeInSec , Copy_pu16FlowRate );
	}

	/*Polling Until Required Number of Interrupts is Reached , In Our Case -> 50 */
	while( ISR_Flag == UNDONE ) ;

	/*Flow Rate Equation in ml/s*/
	FlowRate_ml_s = (u16)( ( Previous_Freq * (u32)60000 ) / ( (u16)27000  ) ) ;

	/*Calculating Volume */
	Volume = Volume + FlowRate_ml_s ;

	/*Derefrencing Global Pointer to Volume Variable*/
	*FLOWMETER_VolumeReading = Volume ;

	/*Derefrencing Global Pointer to Flow Rate Variable */
	/* Flow Rate is Calculated witin 1/80 from second so multiplied by 80 in order to make it in one second */
	*FLOWMETER_FlowRate = FlowRate_ml_s * (u16)80 ;

	/*Turn Back ISR_Flag -> (UNDONE)*/
	ISR_Flag = UNDONE ;

	/*Freqency equalls zero to make sure that the timer is working correctly*/
	Frequency = 0 ;

}

void FLOWMETER_voidFinished( void )
{
	/*Disable Timer0 Peripheral and EXTI*/
	EXTI_u8IntDisable(INT2);
	TIMER_u8Stop( TIMER0 ) ;
}

void EXTI (void)
{
	Frequency ++ ;
}

void TIMER_ISR(void)
{
	static u16 Local_u16Counter = 0 ;
	Local_u16Counter++ ;

	if( Local_u16Counter == 50 ) /* 1/80 from second passed */
	{
		/*Required Number of Interrupts is Reached*/
		ISR_Flag = DONE ;

		/*Assign Current Frequency into a Variable in order to use it in flow equation*/
		Previous_Freq = Frequency ;

		Frequency = 0 ;

		Local_u16Counter = 0 ;
	}
}
