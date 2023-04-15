/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   HAL 			      ***************************/
/*************                SWC :     DC MOTOR	          ***************************/
/*************                VERSION : 1.00		          ***************************/
/*************                DATE : 29-9-2022		          ***************************/
/****************************************************************************************/
/****************************************************************************************/


#ifndef DCMOTOR_INTERFACE_H_
#define DCMOTOR_INTERFACE_H_


/*H-Bridge Using 4 Transistors NPN OR 2 Transistor NPN and 2 Transistors PNP*/

/*---------------------------------------------------------------------------------
 *
 *     NAME     : DCMOTOR_voidInit
 *     FUNCTION : INITIALIZATION DC Motor Pins
 *     ARGUMENT : VOID
 *     RETURN   : VOID
 *
 *---------------------------------------------------------------------------------*/
void DCMOTOR_voidInit( u8 Copy_u8Port , u8 Copy_u8RightToLeftPin , u8 Copy_u8LeftToRightPin ) ;



/*---------------------------------------------------------------------------------
 *
 *     NAME     : DCMOTOR_voidRotateCW
 *     FUNCTION : ROTATE DC MOTOR CLOCKWISE
 *     ARGUMENT : VOID
 *     RETURN   : VOID
 *
 *---------------------------------------------------------------------------------*/
void DCMOTOR_voidRotateCW( u8 Copy_u8Port , u8 Copy_u8RightToLeftPin , u8 Copy_u8LeftToRightPin  ) ;



/*---------------------------------------------------------------------------------
 *
 *     NAME     : DCMOTOR_voidRotateCCW
 *     FUNCTION : ROTATE DC MOTOR COUNTER CLOCKWISE
 *     ARGUMENT : VOID
 *     RETURN   : VOID
 *
 *---------------------------------------------------------------------------------*/
void DCMOTOR_voidRotateCCW( u8 Copy_u8Port ,  u8 Copy_u8RightToLeftPin , u8 Copy_u8LeftToRightPin  ) ;



/*---------------------------------------------------------------------------------
 *
 *     NAME     : DCMOTOR_voidTurnOFF
 *     FUNCTION : Turn Motor OFF
 *     ARGUMENT : VOID
 *     RETURN   : VOID
 *
 *---------------------------------------------------------------------------------*/
void DCMOTOR_voidTurnOFF( u8 Copy_u8Port ,  u8 Copy_u8RightToLeftPin , u8 Copy_u8LeftToRightPin  ) ;

#endif /* 2_HAL_DC_MOTOR_DCMOTOR_INTERFACE_H_ */
