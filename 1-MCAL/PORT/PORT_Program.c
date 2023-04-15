/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   MCAL			      ***************************/
/*************                SWC :     PORT	              ***************************/
/*************                VERSION : 1.00		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

#include "../../4-LIB/STD_TYPES.h"

#include "PORT_Config.h"

#include "PORT_Private.h"
#include "PORT_Interface.h"
#include "PORT_Register.h"

void PORT_voidInit(void)
{
	/*DIRECTION*/
   DDRA_REG = PORTA_DIR ;
   DDRB_REG = PORTB_DIR ;
   DDRC_REG = PORTC_DIR ;
   DDRD_REG = PORTD_DIR ;
   /*INITIAL VALUE*/
   PORTA_REG = PORTA_INITIAL_VALUE ;
   PORTB_REG = PORTB_INITIAL_VALUE ;
   PORTC_REG = PORTC_INITIAL_VALUE ;
   PORTD_REG = PORTD_INITIAL_VALUE ;

}
