/*
 * WDT_Register.h
 *
 *  Created on: Dec 18, 2022
 *      Author: moham
 */

#ifndef WDT_REGISTER_H_
#define WDT_REGISTER_H_

#define WTCR  *( ( volatile u8* ) 0x41 )  /* Watchdog Timer Control Register */

#define WTCR_WDTOE                     4  /* Watchdog Turn-off Enable */
#define WTCR_WDE                       3  /* Watchdog Enable */
#define WTCR_WDP2                      2  /* Watchdog Timer Prescaler 2 */
#define WTCR_WDP1                      1  /* Watchdog Timer Prescaler 1 */
#define WTCR_WDP0                      0  /* Watchdog Timer Prescaler 0 */


#endif /* 1_MCAL_WDT_WDT_REGISTER_H_ */
