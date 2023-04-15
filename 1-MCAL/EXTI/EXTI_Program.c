/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   MCAL			      ***************************/
/*************                SWC :     EXTI		          ***************************/
/*************                VERSION : 1.10		          ***************************/
/*************                DATE : 29-9-2022		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

#include "../../4-LIB/STD_TYPES.h"

#include "EXTI_Interface.h"
#include "EXTI_Private.h"
#include "EXTI_Register.h"
#include "EXTI_Config.h"

/*GLOBAL POINTER TO FUNCTION FOR INT0 ISR ADDRESS*/
void ( *EXTI_pvInt0Func ) ( void ) = NULL ;

/*GLOBAL POINTER TO FUNCTION FOR INT1 ISR ADDRESS*/
void ( *EXTI_pvInt1Func ) ( void ) = NULL ;

/*GLOBAL POINTER TO FUNCTION FOR INT2 ISR ADDRESS*/
void ( *EXTI_pvInt2Func ) ( void ) = NULL ;


/*--------------------------------------------------------------------------------*/
/*                        PRE BUILD CONFIGURATION FUNCTIONS                       */
/*--------------------------------------------------------------------------------*/


void EXTI_voidInit0( void )
{
	/*Check Sense Control For Sense 0*/
#if INT0_SENSE_CONTROL == FALLING_EDGE   	  /*  ISC01 ----> 1
                                                  ISC00 ----> 0  */
	MCUCR |= ( 1 << MCUCR_ISC01 ) ;
	MCUCR &= ( ~ ( 1 << MCUCR_ISC00 ) )  ;

#elif INT0_SENSE_CONTROL == RISING_EDGE       /*  ISC01 ----> 1
                                                  ISC00 ----> 1  */
	MCUCR |= ( ( 1<< MCUCR_ISC01 ) | ( 1 << MCUCR_ISC00 ) ) ;       /*Bit Masking*/

#elif INT0_SENSE_CONTROL == LOW_LEVEL         /*  ISC01 ----> 0
                                                  ISC00 ----> 0  */
	MCUCR &= ( ~ ( ( 1 << MCUCR_ISC01 ) | ( 1 << MCUCR_ISC00 ) ) ) ; /*Bit Masking*/

#elif INT0_SENSE_CONTROL == ON_CHANGE         /*  ISC01 ----> 0
                                                  ISC00 ----> 1  */
	MCUCR |= ( 1 << MCUCR_ISC00 ) ;
	MCUCR &= ( ~ ( 1 << MCUCR_ISC01 ) )  ;

#else

#error "WRONG INT0_SENSE_CONTROL Configuration Option"

#endif

	/*Check Peripheral Interrupt Enable ( PIE ) For INT0*/
#if INT0_INTIAL_STATE_PIE == ENABLED          /*  INT0 ----> 1  */

	GICR |= ( 1<< GICR_INT0 ) ;

#elif INT0_INTIAL_STATE_PIE == DISABLED       /*  INT0 ----> 0  */

	GICR &= ( ~ ( 1<< GICR_INT0 )  ) ;

#else

#error "WRONG INT0_INTIAL_STATE_PIE Configuration Option"

#endif

}


void EXTI_voidInit1( void )
{
	/*Check Sense Control For Sense 1*/
#if INT1_SENSE_CONTROL == FALLING_EDGE          /*  ISC11 ----> 1
                                                    ISC10 ----> 0  */
	MCUCR |= ( 1 << MCUCR_ISC11 ) ;
	MCUCR &= ( ~ ( 1 << MCUCR_ISC10 ) )  ;

#elif INT1_SENSE_CONTROL == RISING_EDGE 	    /*  ISC11 ----> 1
                                                    ISC10 ----> 1  */

	MCUCR |= ( ( 1<< MCUCR_ISC11 ) | ( 1 << MCUCR_ISC10 ) ) ;        /*Bit Masking*/

#elif INT1_SENSE_CONTROL == LOW_LEVEL          /*  ISC11 ----> 0
                                                   ISC10 ----> 0   */
	MCUCR &= ( ~ ( ( 1 << MCUCR_ISC11 ) | ( 1 << MCUCR_ISC10 ) ) ) ;  /*Bit Masking*/

#elif INT1_SENSE_CONTROL == ON_CHANGE          /*  ISC11 ----> 0
                                                   ISC10 ----> 1   */

	MCUCR |= ( 1 << MCUCR_ISC10 ) ;
	MCUCR &= ( ~ ( 1 << MCUCR_ISC11 ) )  ;

#else

#error "WRONG INT1_SENSE_CONTROL Configuration Option"

#endif

	/*Check Peripheral Interrupt Enable ( PIE ) For INT1*/
#if INT1_INTIAL_STATE_PIE == ENABLED			  /*  INT1 ----> 1  */

	GICR |= ( 1<< GICR_INT1 ) ;

#elif INT1_INTIAL_STATE_PIE == DISABLED			  /*  INT1 ----> 0  */

	GICR &= ( ~ ( 1<< GICR_INT1 )  ) ;

#else

#error "WRONG INT1_INTIAL_STATE_PIE Configuration Option"

#endif

}


void EXTI_voidInit2( void )
{
	/*Check Sense Control For Sense 2*/
#if INT2_SENSE_CONTROL == FALLING_EDGE         /*  ISC2 ----> 0  */


	MCUCSR &= ( ~ ( 1 << MCUCSR_ISC2 ) ) ;

#elif INT2_SENSE_CONTROL == RISING_EDGE        /*  ISC2 ----> 1  */

	MCUCSR |= ( 1 << MCUCSR_ISC2 ) ;

#else

#error "WRONG INT2_SENSE_CONTROL Configuration Option"

#endif

	/*Check Peripheral Interrupt Enable ( PIE ) For INT2*/

#if INT2_INTIAL_STATE_PIE == ENABLED			 /*  INT2 ----> 1  */

	GICR |= ( 1<< GICR_INT2 ) ;

#elif INT2_INTIAL_STATE_PIE == DISABLED			 /*  INT2 ----> 0  */

	GICR &= ( ~ ( 1<< GICR_INT2 )  ) ;

#else

#error "WRONG INT2_INTIAL_STATE_PIE Configuration Option"

#endif

}

/*--------------------------------------------------------------------------------*/
/*                       POST BUILD CONFIGURATION FUNCTIONS                       */
/*--------------------------------------------------------------------------------*/

u8 EXTI_u8Int0SenseControl( u8 Copy_u8Sense )
{
	u8 Local_u8ErrorState = OK ;

	switch( Copy_u8Sense )
	{
	case FALLING_EDGE : MCUCR |= ( 1 << MCUCR_ISC01 ) ; MCUCR &= ( ~ ( 1 << MCUCR_ISC00 ) )  ; break;

	case RISING_EDGE  :	MCUCR |= ( ( 1<< MCUCR_ISC01 ) | ( 1 << MCUCR_ISC00 ) ) ; break;

	case LOW_LEVEL    : MCUCR &= ( ~ ( ( 1 << MCUCR_ISC01 ) | ( 1 << MCUCR_ISC00 ) ) ) ; break;

	case ON_CHANGE    : MCUCR |= ( 1 << MCUCR_ISC00 ) ; MCUCR &= ( ~ ( 1 << MCUCR_ISC01 ) ) ; break;

	default           :	Local_u8ErrorState = NOK ; break;
	}

	return Local_u8ErrorState ;
}


u8 EXTI_u8Int1SenseControl( u8 Copy_u8Sense )
{
	u8 Local_u8ErrorState = OK ;

	switch( Copy_u8Sense )
	{
	case FALLING_EDGE : MCUCR |= ( 1 << MCUCR_ISC11 ) ; MCUCR &= ( ~ ( 1 << MCUCR_ISC10 ) )  ; break;

	case RISING_EDGE  :	MCUCR |= ( ( 1<< MCUCR_ISC11 ) | ( 1 << MCUCR_ISC10 ) ) ; break;

	case LOW_LEVEL    : MCUCR &= ( ~ ( ( 1 << MCUCR_ISC11 ) | ( 1 << MCUCR_ISC10 ) ) ) ; break;

	case ON_CHANGE    : MCUCR |= ( 1 << MCUCR_ISC10 ) ; MCUCR &= ( ~ ( 1 << MCUCR_ISC11 ) ) ; break;

	default           :	Local_u8ErrorState = NOK ; break;
	}

	return Local_u8ErrorState ;
}


u8 EXTI_u8Int2SenseControl( u8 Copy_u8Sense )
{
	u8 Local_u8ErrorState = OK ;

	switch( Copy_u8Sense )
	{
	case FALLING_EDGE  :  MCUCSR &= ( ~ ( 1 << MCUCSR_ISC2 ) ) ; break;

	case RISING_EDGE   :  MCUCSR |= ( 1 << MCUCSR_ISC2 ) ; break;

	default            :  Local_u8ErrorState = NOK ; break;
	}

	return Local_u8ErrorState ;
}


u8 EXTI_u8IntEnable( u8 Copy_u8Int )
{
	u8 Local_u8ErrorState = OK ;

	switch( Copy_u8Int )
	{
	case INT0 : GICR |= ( 1 << GICR_INT0 ) ; break ;
	case INT1 : GICR |= ( 1 << GICR_INT1 ) ; break ;
	case INT2 : GICR |= ( 1 << GICR_INT2 ) ; break ;
	default   : Local_u8ErrorState = NOK   ; break ;
	}

	return Local_u8ErrorState ;
}

u8 EXTI_u8IntDisable( u8 Copy_u8Int )
{
	u8 Local_u8ErrorState = OK ;

	switch( Copy_u8Int )
	{
	case INT0 : GICR &= ( ~ ( 1 << GICR_INT0 ) ) ; break ;
	case INT1 : GICR &= ( ~ ( 1 << GICR_INT1 ) ) ; break ;
	case INT2 : GICR &= ( ~ ( 1 << GICR_INT2 ) ) ; break ;
	default   : Local_u8ErrorState = NOK         ; break ;
	}

	return Local_u8ErrorState ;
}


u8 EXTI_u8Int0CallBack( void ( *Copy_pvInt0Func ) ( void )  )
{
	u8 Local_ErrorState = OK ;

	if( Copy_pvInt0Func != NULL )
	{
		EXTI_pvInt0Func = Copy_pvInt0Func ;
	}
	else
	{
		Local_ErrorState = NULL_POINTER ;
	}

	return Local_ErrorState ;
}


u8 EXTI_u8Int1CallBack( void ( *Copy_pvInt1Func ) ( void ) )
{
	u8 Local_u8ErrorState = OK ;

	if( Copy_pvInt1Func != NULL )
	{
		EXTI_pvInt1Func = Copy_pvInt1Func ;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER ;
	}

	return Local_u8ErrorState ;
}


u8 EXTI_u8Int2CallBack( void ( *Copy_pvInt2Func ) ( void ) )
{
	u8 Local_u8ErrorState = OK ;

	if( Copy_pvInt2Func != NULL )
	{
		EXTI_pvInt2Func = Copy_pvInt2Func ;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER ;
	}

	return Local_u8ErrorState ;
}

/*ISR For INT0*/
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if( EXTI_pvInt0Func != NULL )
	{
		EXTI_pvInt0Func() ;
	}
	else
	{
		/*DO NOTING*/
	}

}


/*ISR For INT1*/
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if( EXTI_pvInt1Func != NULL )
	{
		EXTI_pvInt1Func() ;
	}
	else
	{
		/*DO NOTING*/
	}
}


/*ISR For INT2*/
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if( EXTI_pvInt2Func != NULL )
	{
		EXTI_pvInt2Func() ;
	}
	else
	{
		/*DO NOTING*/
	}
}
