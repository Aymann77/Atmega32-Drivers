/*
 * LED_Interface.h
 *
 *  Created on: Sep 6, 2022
 *      Author: moham
 */

#ifndef _LED_LED_INTERFACE_H_
#define _LED_INTERFACE_H_

/*---------------------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------------
 *
 *     NAME     : LED_u8Init
 *     FUNCTION : INTIALIZATION FOR SPECIFIC PIN IN A SPECIFIC PORT AS OUTPUT
 *     ARGUMENT : PORT NUMBER  , PIN NUMBER
 *     RETURN   : U8 ERROR STATE TO CHECK IF FUCTION WORKED CORRECT OR NOT
 *
 *---------------------------------------------------------------------------------*/
u8 LED_u8Init( u8 Copy_u8Port , u8 Copy_u8Pin ) ;


/*---------------------------------------------------------------------------------
 *
 *     NAME     : LED_u8StringInit
 *     FUNCTION : INTIALIZATION FOR SPECIFIC PORT AS OUTPUT
 *     ARGUMENT : PORT NUMBER
 *     RETURN   : U8 ERROR STATE TO CHECK IF FUCTION WORKED CORRECT OR NOT
 *
 *---------------------------------------------------------------------------------*/
u8 LED_u8StringInit( u8 Copy_u8Port ) ;


/*---------------------------------------------------------------------------------
 *
 *     NAME     : LED_u8ON
 *     FUNCTION : TURN ON SPECIFIC LED
 *     ARGUMENT : PORT NUMBER  , PIN NUMBER
 *     RETURN   : U8 ERROR STATE TO CHECK IF FUCTION WORKED CORRECT OR NOT
 *
 *---------------------------------------------------------------------------------*/
u8 LED_u8ON( u8 Copy_u8Port , u8 Copy_u8Pin ) ;


/*---------------------------------------------------------------------------------
 *
 *     NAME     : LED_u8StringON
 *     FUNCTION : TURN ON SPECIFIC STRING OF LEDS
 *     ARGUMENT : PORT NUMBER
 *     RETURN   : U8 ERROR STATE TO CHECK IF FUCTION WORKED CORRECT OR NOT
 *
 *---------------------------------------------------------------------------------*/
u8 LED_u8StringON( u8 Copy_u8Port ) ;


/*---------------------------------------------------------------------------------
 *
 *     NAME     : LED_u8OFF
 *     FUNCTION : TURN OFF SPECIFIC LED
 *     ARGUMENT : PORT NUMBER  , PIN NUMBER
 *     RETURN   : U8 ERROR STATE TO CHECK IF FUCTION WORKED CORRECT OR NOT
 *
 *---------------------------------------------------------------------------------*/
u8 LED_u8OFF( u8 Copy_u8Port , u8 Copy_u8Pin ) ;


/*---------------------------------------------------------------------------------
 *
 *     NAME     : LED_u8StringOFF
 *     FUNCTION : TURN OFF SPECIFIC STRING OF LEDS
 *     ARGUMENT : PORT NUMBER
 *     RETURN   : U8 ERROR STATE TO CHECK IF FUCTION WORKED CORRECT OR NOT
 *
 *---------------------------------------------------------------------------------*/
u8 LED_u8StringOFF( u8 Copy_u8Port ) ;


/*---------------------------------------------------------------------------------
 *
 *     NAME     : LED_u8Toggle
 *     FUNCTION : TOGGLE LED STATE IF OFF MAKE IT ON IF ON MAKE IT OFF
 *     ARGUMENT : PORT NUMBER , PIN NUMBER
 *     RETURN   : U8 ERROR STATE TO CHECK IF FUCTION WORKED CORRECT OR NOT
 *
 *---------------------------------------------------------------------------------*/
u8 LED_u8Toggle( u8 Copy_u8Port , u8 Copy_u8Pin ) ;

#endif /* 2_HAL_LED_LED_INTERFACE_H_ */
