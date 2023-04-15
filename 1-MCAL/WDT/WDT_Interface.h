/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   MCAL			      ***************************/
/*************                SWC :     WDT 	              ***************************/
/*************                VERSION : 1.00		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_

/* WDT SLEEP OPTIONS */
#define WDT_TIMEOUT_16_3ms      0
#define WDT_TIMEOUT_32_5ms      1
#define WDT_TIMEOUT_65ms        2
#define WDT_TIMEOUT_0_13s       3
#define WDT_TIMEOUT_0_26s       4
#define WDT_TIMEOUT_0_52s       5
#define WDT_TIMEOUT_1_0s        6
#define WDT_TIMEOUT_2_1s        7


void WDT_voidSleep( u8 Copy_u8SleepTime ) ;
void WDT_voidEnable( void ) ;
void WDT_voidDisable( void ) ;

#endif /* 1_MCAL_WDT_WDT_INTERFACE_H_ */
