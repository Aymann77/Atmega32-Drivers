/*
 * STEPPER_Interface.h
 *
 *  Created on: Sep 26, 2022
 *      Author: moham
 */

#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_

/*---------------------------------------------------------------------------------------*/

/*FULL STEP*/
/*------------------------------------------------------------------------------------------------------------
 *
 *     NAME     : STEPPER_Init
 *     FUNCTION : INTIALIZATION FOR STEPPER MOTOR
 *     ARGUMENT : PORT NUMBER  , BLUE PIN NUMBER , PINK PIN NUMBER , YELLOW PIN NUMBER , ORANGE PIN NUMBER
 *     RETURN   : VOID
 *
 *------------------------------------------------------------------------------------------------------------*/
void STEPPER_Init( u8 Copy_u8Port , u8 Copy_u8BluePin , u8 Copy_u8PinkPin , u8 Copy_u8YellowPin , u8 Copy_u8OrangePin  ) ;



/*----------------------------------------------------------------------------------------------------------------------------
 *
 *     NAME     : STEPPER_GoForward
 *     FUNCTION : STEPPER MOTOR GO FORWARD(C.C.W)
 *     ARGUMENT : PORT NUMBER  , BLUE PIN NUMBER , PINK PIN NUMBER , YELLOW PIN NUMBER , ORANGE PIN NUMBER , NUMBER OF STEPS
 *     RETURN   : VOID
 *
 *----------------------------------------------------------------------------------------------------------------------------*/
void STEPPER_GoForward( u8 Copy_u8Port , u8 Copy_u8BluePin , u8 Copy_u8PinkPin , u8 Copy_u8YellowPin , u8 Copy_u8OrangePin , u32 Copy_u32Steps ) ;



/*----------------------------------------------------------------------------------------------------------------------------
 *
 *     NAME     : STEPPER_GoBackward
 *     FUNCTION : STEPPER MOTOR GO BACKWARD(C.W)
 *     ARGUMENT : PORT NUMBER  , BLUE PIN NUMBER , PINK PIN NUMBER , YELLOW PIN NUMBER , ORANGE PIN NUMBER , NUMBER OF STEPS
 *     RETURN   : VOID
 *
 *----------------------------------------------------------------------------------------------------------------------------*/
void STEPPER_GoBackward(  u8 Copy_u8Port , u8 Copy_u8BluePin , u8 Copy_u8PinkPin , u8 Copy_u8YellowPin , u8 Copy_u8OrangePin , u32 Copy_u32Steps ) ;



/*----------------------------------------------------------------------------------------------------------------------------
 *
 *     NAME     : STEPPER_TurnOFF
 *     FUNCTION : STEPPER MOTOR TURN OFF
 *     ARGUMENT : PORT NUMBER  , BLUE PIN NUMBER , PINK PIN NUMBER , YELLOW PIN NUMBER , ORANGE PIN NUMBER , NUMBER OF STEPS
 *     RETURN   : VOID
 *
 *----------------------------------------------------------------------------------------------------------------------------*/
void STEPPER_TurnOFF( u8 Copy_u8Port , u8 Copy_u8BluePin , u8 Copy_u8PinkPin , u8 Copy_u8YellowPin , u8 Copy_u8OrangePin  ) ;


/* STEPPER MOTOR DRIVER ( A4988 ) WITH NEMA17 */

/*----------------------------------------------------------------------------------------------------------------------------
 *
 *     NAME     : STEPPER_NEMA17_Control
 *     FUNCTION : CONTROL NEMA17 STEPPER MOTOR USING STEPPER MOTOR DRIVER A4988
 *     ARGUMENT : PORT NUMBER   ,  PIN NUMBER , NUMBER OF DEGREES
 *     RETURN   : VOID
 *
 *----------------------------------------------------------------------------------------------------------------------------*/
void STEPPER_NEMA17_Control( u8 Copy_u8ControlPort , u8 Copy_u8ControlPin , u16 Copy_u16Degree );
/*---------------------------------------------------------------------------------------*/

#endif /* 2_HAL_STEPPER_STEPPER_INTERFACE_H_ */
