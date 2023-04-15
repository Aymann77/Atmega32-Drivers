/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   MCAL			      ***************************/
/*************                SWC :     PORT	              ***************************/
/*************                VERSION : 1.00		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

#ifndef PORT_REGISTER_H_
#define PORT_REGISTER_H_

#define DDRA_REG  *( (volatile u8*) 0x3A )
#define DDRB_REG  *( (volatile u8*) 0x37 )
#define DDRC_REG  *( (volatile u8*) 0x34 )
#define DDRD_REG  *( (volatile u8*) 0x31 )

#define PORTA_REG *( (volatile u8*) 0x3B )
#define PORTB_REG *( (volatile u8*) 0x38 )
#define PORTC_REG *( (volatile u8*) 0x35 )
#define PORTD_REG *( (volatile u8*) 0x32 )

#endif /* 1_MCAL_PORT_PORT_REGISTER_H_ */
