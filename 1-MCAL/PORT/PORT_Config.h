/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   MCAL			      ***************************/
/*************                SWC :     PORT	              ***************************/
/*************                VERSION : 1.00		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

#ifndef PORT_CONFIG_H_
#define PORT_CONFIG_H_


/*
 * Choose : 0  FOR INPUT
 *          1  FOR OUTPUT
 *
 */


/* DIRECTION*/
#define PORTA_PIN0_DIR  1 /* LED PORT */
#define PORTA_PIN1_DIR  1
#define PORTA_PIN2_DIR  1
#define PORTA_PIN3_DIR  1
#define PORTA_PIN4_DIR  1
#define PORTA_PIN5_DIR  1
#define PORTA_PIN6_DIR  1
#define PORTA_PIN7_DIR  1

#define PORTB_PIN0_DIR  0
#define PORTB_PIN1_DIR  0
#define PORTB_PIN2_DIR  0
#define PORTB_PIN3_DIR  0
#define PORTB_PIN4_DIR  0  /* SS Input Pulled Up For Master */
#define PORTB_PIN5_DIR  0  /* MOSI : Master Output Slave Input */
#define PORTB_PIN6_DIR  0  /* MISO : Master Input Slave Ouput */
#define PORTB_PIN7_DIR  0  /* SCK  : Output */

#define PORTC_PIN0_DIR  0
#define PORTC_PIN1_DIR  0
#define PORTC_PIN2_DIR  0
#define PORTC_PIN3_DIR  0
#define PORTC_PIN4_DIR  0
#define PORTC_PIN5_DIR  0
#define PORTC_PIN6_DIR  0
#define PORTC_PIN7_DIR  0

#define PORTD_PIN0_DIR  0  /* RX */
#define PORTD_PIN1_DIR  1 /* TX */
#define PORTD_PIN2_DIR  0 /* LED */
#define PORTD_PIN3_DIR  0
#define PORTD_PIN4_DIR  0
#define PORTD_PIN5_DIR  0
#define PORTD_PIN6_DIR  0
#define PORTD_PIN7_DIR  0


/*INTIAL VALUE*/

/* Choose : 0  IF Output (LOW)  , IF Input (FLOATING)
 *          1  IF OUTPUT (HIGH) , IF INPUT (PULL UP)
 */

#define PORTA_PIN0_INTIAL_VALUE  0
#define PORTA_PIN1_INTIAL_VALUE  0
#define PORTA_PIN2_INTIAL_VALUE  0
#define PORTA_PIN3_INTIAL_VALUE  0
#define PORTA_PIN4_INTIAL_VALUE  0
#define PORTA_PIN5_INTIAL_VALUE  0
#define PORTA_PIN6_INTIAL_VALUE  0
#define PORTA_PIN7_INTIAL_VALUE  0

#define PORTB_PIN0_INTIAL_VALUE  0
#define PORTB_PIN1_INTIAL_VALUE  0
#define PORTB_PIN2_INTIAL_VALUE  0
#define PORTB_PIN3_INTIAL_VALUE  0
#define PORTB_PIN4_INTIAL_VALUE  0
#define PORTB_PIN5_INTIAL_VALUE  0
#define PORTB_PIN6_INTIAL_VALUE  0
#define PORTB_PIN7_INTIAL_VALUE  0

#define PORTC_PIN0_INTIAL_VALUE  0
#define PORTC_PIN1_INTIAL_VALUE  0
#define PORTC_PIN2_INTIAL_VALUE  0
#define PORTC_PIN3_INTIAL_VALUE  0
#define PORTC_PIN4_INTIAL_VALUE  0
#define PORTC_PIN5_INTIAL_VALUE  0
#define PORTC_PIN6_INTIAL_VALUE  0
#define PORTC_PIN7_INTIAL_VALUE  0

#define PORTD_PIN0_INTIAL_VALUE  0
#define PORTD_PIN1_INTIAL_VALUE  0
#define PORTD_PIN2_INTIAL_VALUE  0
#define PORTD_PIN3_INTIAL_VALUE  0
#define PORTD_PIN4_INTIAL_VALUE  0
#define PORTD_PIN5_INTIAL_VALUE  0
#define PORTD_PIN6_INTIAL_VALUE  0
#define PORTD_PIN7_INTIAL_VALUE  0


#endif /* 1_MCAL_PORT_PORT_CONFIG_H_ */
