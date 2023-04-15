/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   MCAL			      ***************************/
/*************                SWC :     EXTI		          ***************************/
/*************                VERSION : 1.00		          ***************************/
/*************                DATE : 3-10-2022		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_


/*--------------------------------------------------------------------------------*/
/*                       PRE BUILD CONFIGURATION OPTIONS                          */
/*--------------------------------------------------------------------------------*/

/*OPTIONS:
 *
 * 1-> FALLING_EDGE
 * 2-> RISING_EDGE
 * 3-> LOW_LEVEL
 * 4-> ON_CHANGE
 *
 * */

#define INT0_SENSE_CONTROL RISING_EDGE

/*OPTIONS:
 *
 * 1-> FALLING_EDGE
 * 2-> RISING_EDGE
 * 3-> LOW_LEVEL
 * 4-> ON_CHANGE
 *
 * */

#define INT1_SENSE_CONTROL  ON_CHANGE


/*OPTIONS:
 *
 * 1-> FALLING_EDGE
 * 2-> RISING_EDGE
 *
 * */
#define INT2_SENSE_CONTROL  RISING_EDGE


/*OPTIONS:
 *
 * 1-> ENABLED
 * 2-> DISABLED
 *
 */
#define INT0_INTIAL_STATE_PIE   ENABLED
#define INT1_INTIAL_STATE_PIE   ENABLED
#define INT2_INTIAL_STATE_PIE   ENABLED


#endif /* 1_MCAL_EXTI_EXTI_CONFIG_H_ */
