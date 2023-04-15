/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   MCAL			      ***************************/
/*************                SWC :     EXTI		          ***************************/
/*************                VERSION : 1.00		          ***************************/
/*************                DATE : 29-9-2022		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

/*
 * EXTI Registers
 * */
#define GICR        *( (volatile u8*) 0x5B )
#define GIFR        *( (volatile u8*) 0x5A )
#define MCUCR       *( (volatile u8*) 0x55 )
#define MCUCSR      *( (volatile u8*) 0x54 )

/*
 * GICR Bits
 * */
#define GICR_INT1    7
#define GICR_INT0    6
#define GICR_INT2    5

/*
 * MCUCR Bits
 * */
#define MCUCR_ISC11  3
#define MCUCR_ISC10  2
#define MCUCR_ISC01  1
#define MCUCR_ISC00  0

/*
 * MCUCSR Bits
 * */
#define MCUCSR_ISC2  6

/*
 * GIFR Bits
 * */
#define GIFR_INTF1   7
#define GIFR_INTF0   6
#define GIFR_INTF2   5

#endif /* 1_MCAL_EXTI_EXTI_REGISTER_H_ */
