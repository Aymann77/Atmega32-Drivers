/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   MCAL			      ***************************/
/*************                SWC :     WDT 	              ***************************/
/*************                VERSION : 1.00		          ***************************/
/****************************************************************************************/
/****************************************************************************************/
#include "../../4-LIB/STD_TYPES.h"

#include "WDT_Interface.h"
#include "WDT_Config.h"
#include "WDT_Private.h"
#include "WDT_Register.h"


void WDT_voidSleep( u8 Copy_u8SleepTime )
{
	/* Clear Prescaler Bits */
	WTCR &= WDT_PRESC_MASK;

	/* Set Required Prescaler */
	WTCR |= Copy_u8SleepTime ;
}

void WDT_voidEnable( void )
{
	/* Enable Watchdog Timer */
	WTCR |= ( 1 << WTCR_WDE ) ;
}

void WDT_voidDisable( void )
{
	/* 1- Write a logic one to WDTOE and WDE in the same operation */
	WTCR |=  WDT_WDE_WDTOE_EQUALS_1 ;

	/* 2- Within the next four clock cycles, write a logic 0 to WDE */
	WTCR = WDT_DISABLE_VALUE ;
}
