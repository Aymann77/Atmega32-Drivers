/*
 * SW_Interface.h
 *
 *  Created on: Sep 6, 2022
 *      Author: moham
 */

#ifndef SW_INTERFACE_H_
#define SW_INTERFACE_H_



#define PULL_UP_RESISTOR   1
#define PULL_DOWN_RESISTOR 2


#define SWITCH_NOT_PRESSED  0X00
#define SWITCH_PRESSED      0XFF

/*-------------------------------------------------------------------------------------------------------
 *
 *     NAME     : SWITCH_u8Init
 *     FUNCTION : INTIALIZE SWITCH DIRECTION AND IF PULL TYPE IS PULL UP ENABLE INTERNAL PULL UP IN AVR
 *     ARGUMENT : PORT NUMBER , PIN NUMBER , PULL TYPE ( PULL_UP_RESISTOR , PULL_DOWN_RESISTOR )
 *     RETURN   : U8 ERROR STATE TO CHECK IF FUCTION WORKED CORRECT OR NOT
 *
 *-------------------------------------------------------------------------------------------------------*/
u8 SWITCH_u8Init( u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8PullType ) ;



/*---------------------------------------------------------------------------------------------------------------------
 *
 *     NAME     : SWITCH_u8PressedOrNot
 *     FUNCTION : CHECK ON SWITCH IF PRESSED
 *     ARGUMENT : PORT NUMBER , PIN NUMBER , PULL TYPE ( PULL_UP_RESISTOR , PULL_DOWN_RESISTOR )
 *     RETURN   : U8 SWITCH STATE IF PRESSED-> ( SWITCH_PRESSED=0XFF ) , IF NOT PRESSED->( SWITCH_NOT_PRESSED=0X00 )
 *
 *--------------------------------------------------------------------------------------------------------------------*/
u8 SWITCH_u8PressedOrNot( u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8PullType ) ;



/*----------------------------------------------------------------------------------------------------------------------
 *
 *     NAME     : SWITCH_u8PollingUntilSwitchPressed
 *     FUNCTION : POLLING UNTIL SWITCH IS PRESSED
 *     ARGUMENT : PORT NUMBER , PIN NUMBER , PULL TYPE (  PULL_UP_RESISTOR , PULL_DOWN_RESISTOR )
 *     RETURN   : U8 SWITCH STATE IF PRESSED-> ( SWITCH_PRESSED=0XFF ) , IF NOT PRESSED->( SWITCH_NOT_PRESSED=0X00 )
 *
 *----------------------------------------------------------------------------------------------------------------------*/
u8 SWITCH_u8PollingUntilSwitchPressed( u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8PullType ) ;





#endif /* 2_HAL_SW_SW_INTERFACE_H_ */
