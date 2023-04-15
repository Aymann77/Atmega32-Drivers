/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   MCAL			      ***************************/
/*************                SWC :     EXTI		          ***************************/
/*************                VERSION : 1.00		          ***************************/
/*************                DATE : 29-9-2022		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/*POST BUILD ARGUMENTS*/
#define FALLING_EDGE  1
#define RISING_EDGE   2
#define LOW_LEVEL     3
#define ON_CHANGE     4

#define INT0          1
#define INT1          2
#define INT2          3


/*--------------------------------------------------------------------------------*/
/*                        PRE BUILD CONFIGURATION FUNCTIONS                       */
/*--------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------
 *
 *     NAME     : EXTI_voidInit0
 *     FUNCTION : INITIALIZATION FOR INT0
 *     ARGUMENT : VOID
 *     RETURN   : VOID
 *
 *---------------------------------------------------------------------------------*/
void EXTI_voidInit0( void ) ;



/*---------------------------------------------------------------------------------
 *
 *     NAME     : EXTI_voidInit1
 *     FUNCTION : INITIALIZATION FOR INT1
 *     ARGUMENT : VOID
 *     RETURN   : VOID
 *
 *---------------------------------------------------------------------------------*/
void EXTI_voidInit1( void ) ;



/*---------------------------------------------------------------------------------
 *
 *     NAME     : EXTI_voidInit2
 *     FUNCTION : INITIALIZATION FOR INT2
 *     ARGUMENT : VOID
 *     RETURN   : VOID
 *
 *---------------------------------------------------------------------------------*/
void EXTI_voidInit2( void ) ;


/*--------------------------------------------------------------------------------*/
/*                       POST BUILD CONFIGURATION FUNCTIONS                       */
/*--------------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------------
 *
 *     NAME     : EXTI_u8Int0SenseControl
 *     FUNCTION : SET SENSE CONTROL FOR INT0 USING POST BUILD CONFIGURATION
 *     ARGUMENT : SENSE CONTROL , OPTIONS ARE : 1- FALLING_EDGE
 *     											2- RISING_EDGE
 *     											3- LOW_LEVEL
 *     											4- ON_CHANGE
 *     RETURN   : u8 ErrorState To Check If Function Worked Correctly
 *
 *---------------------------------------------------------------------------------*/
u8 EXTI_u8Int0SenseControl( u8 Copy_u8Sense ) ;




/*---------------------------------------------------------------------------------
 *
 *     NAME     : EXTI_u8Int1SenseControl
 *     FUNCTION : SET SENSE CONTROL FOR INT1 USING POST BUILD CONFIGURATION
 *     ARGUMENT : SENSE CONTROL , OPTIONS ARE : 1- FALLING_EDGE
 *     											2- RISING_EDGE
 *     											3- LOW_LEVEL
 *     											4- ON_CHANGE
 *     RETURN   : u8 ErrorState To Check If Function Worked Correctly
 *
 *---------------------------------------------------------------------------------*/
u8 EXTI_u8Int1SenseControl( u8 Copy_u8Sense ) ;




/*---------------------------------------------------------------------------------
 *
 *     NAME     : EXTI_u8Int2SenseControl
 *     FUNCTION : SET SENSE CONTROL FOR INT2 USING POST BUILD CONFIGURATION
 *     ARGUMENT : SENSE CONTROL , OPTIONS ARE : 1- FALLING_EDGE
 *     											2- RISING_EDGE
 *     RETURN   : u8 ErrorState To Check If Function Worked Correctly
 *
 *---------------------------------------------------------------------------------*/
u8 EXTI_u8Int2SenseControl( u8 Copy_u8Sense ) ;



/*---------------------------------------------------------------------------------
 *
 *     NAME     : EXTI_u8IntEnable
 *     FUNCTION : ENABLE PERIPHERAL INTERRUPT ENABLE ( PIE ) FOR CERTAIN INT
 *     ARGUMENT : INT , OPTIONS ARE :           1- INT0
 *     											2- INT1
 *     											3- INT2
 *     RETURN   : u8 ErrorState To Check If Function Worked Correctly
 *
 *---------------------------------------------------------------------------------*/
u8 EXTI_u8IntEnable( u8 Copy_u8Int ) ;




/*---------------------------------------------------------------------------------
 *
 *     NAME     : EXTI_u8IntDisable
 *     FUNCTION : DISABLE PERIPHERAL INTERRUPT ENABLE ( PIE ) FOR CERTAIN INT
 *     ARGUMENT : INT , OPTIONS ARE :           1- INT0
 *     											2- INT1
 *     											3- INT2
 *     RETURN   : u8 ErrorState To Check If Function Worked Correctly
 *
 *---------------------------------------------------------------------------------*/
u8 EXTI_u8IntDisable( u8 Copy_u8Int ) ;


/*--------------------------------------------------------------------------------*/
/*                               CALL BACK FUNCTIONS                              */
/*--------------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------------
 *
 *     NAME     : EXTI_u8Int0CallBack
 *     FUNCTION : ASSIGN ISR WRITTEN IN MAIN TO A GLOBAL POINTER TO FUNCTION IN PROG.C
 *     ARGUMENT : POINTER TO FUNCTION ( ISR INT0 )
 *     RETURN   : u8 ErrorState To Check If ARGUMENT IS NULL_POINTER
 *
 *---------------------------------------------------------------------------------*/
u8 EXTI_u8Int0CallBack( void ( *Copy_pvInt0Func ) ( void ) ) ;



/*---------------------------------------------------------------------------------
 *
 *     NAME     : EXTI_u8Int1CallBack
 *     FUNCTION : ASSIGN ISR WRITTEN IN MAIN TO A GLOBAL POINTER TO FUNCTION IN PROG.C
 *     ARGUMENT : POINTER TO FUNCTION ( ISR INT1 )
 *     RETURN   : u8 ErrorState To Check If ARGUMENT IS NULL_POINTER
 *
 *---------------------------------------------------------------------------------*/
u8 EXTI_u8Int1CallBack( void ( *Copy_pvInt1Func ) ( void ) ) ;



/*---------------------------------------------------------------------------------
 *
 *     NAME     : EXTI_u8Int2CallBack
 *     FUNCTION : ASSIGN ISR WRITTEN IN MAIN TO A GLOBAL POINTER TO FUNCTION IN PROG.C
 *     ARGUMENT : POINTER TO FUNCTION ( ISR INT2 )
 *     RETURN   : u8 ErrorState To Check If ARGUMENT IS NULL_POINTER
 *
 *---------------------------------------------------------------------------------*/
u8 EXTI_u8Int2CallBack( void ( *Copy_pvInt2Func ) ( void ) ) ;


#endif /* 1_MCAL_EXTI_EXTI_INTERFACE_H_ */
