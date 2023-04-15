/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   HAL  			      ***************************/
/*************                SWC :     CLCD	              ***************************/
/*************                VERSION : 1.00		          ***************************/
/*************                DATE : 7/9/2022		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

/* Preprocessor file guard*/
#ifndef _CLCD_CONFIG_H_
#define _CLCD_CONFIG_H_

#define CLCD_DATA_PORT   DIO_u8PORTD

#define CLCD_CTRL_PORT   DIO_u8PORTC
#define CLCD_RS_PIN      DIO_u8Pin0
#define CLCD_RW_PIN      DIO_u8Pin1
#define CLCD_E_PIN       DIO_u8Pin2



/*
 * 1-> LCD_16X2
 * 2-> LCD_20X4
 *
 */

#define LCD_MODULE LCD_16X2
/*
 * 1-> LCD_8BIT_MODE
 * 2-> LCD_4BIT_MODE
 */



#define LCD_MODE   LCD_8BIT_MODE


/* 1-> DISPLAY_ENABLE
 * 2-> DISPLAY_DISABLE
 */

#define DISPLAY  DISPLAY_ENABLE

/* 1-> CURSOR_ENABLE
 * 2-> CURSOR_DISABLE
 */


#define CURSOR  CURSOR_DISABLE


/* 1-> BLINK_ENABLE
 * 2-> BLINK_DISABLE
 */

#define BLINK_CURSOR  BLINK_DISABLE



/* 1-> ONE_LINE
 * 2-> TWO_LINES
 */

#define NUMBER_OF_LINES  TWO_LINES


/* 1-> FONT_5x8
 * 2-> FONT_5x11
 */
#define FONT_SIZE FONT_5x8



#endif /* 2_HAL_CLCD_CLCD_CONFIG_H_ */
