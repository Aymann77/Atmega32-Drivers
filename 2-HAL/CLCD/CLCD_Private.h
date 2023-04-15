/*
 * CLCD_Private.h
 *
 *  Created on: Sep 7, 2022
 *      Author: moham
 */

#ifndef CLCD_PRIVATE_H_
#define CLCD_PRIVATE_H_

/*COMMANDS*/
#define CLCD_CLEAR_DISPLAY ( 0x01 )
#define CLCD_RETURN_HOME   ( 0X02 )
#define SET_DDRAM_ADDRESS  ( 0x80 )
#define SET_CGRAM_ADDRESS  ( 0x40 )



/*SOME VALUES*/
#define SECOND_LINE_START_ADDRESS ( 0x40 )

/*FOR MORE THAN 2 ROWS LCDS */
#define THIRD_LINE_START_ADDRESS  ( 0x14 )
#define FOURTH_LINE_START_ADRESS  ( 0x54 )

#define LOCATION_SIZE_IN_CGRAM        8
#define MAX_NUMBER_OF_DIGITS_IN_S32  10
#define ZERO_ASCII                   48

#define LCD_8BIT_MODE    1
#define LCD_4BIT_MODE    2

#define DISPLAY_ENABLE   1
#define DISPLAY_DISABLE  2

#define CURSOR_ENABLE    1
#define CURSOR_DISABLE   2

#define BLINK_ENABLE     1
#define BLINK_DISABLE    2

#define ONE_LINE         1
#define TWO_LINES  		 2

#define FONT_5x8  		 1
#define FONT_5x11 		 2

#define NUMBER_OF_LINES_BIT   3
#define FONT_SIZE_BIT         2

#define RIGHT_LEFT_SHIFT_BIT  2

#define DISPLAY_BIT 		  2
#define CURSOR_BIT  		  1
#define BLINK_BIT   	      0

#define LCD_16X2  1
#define LCD_20X4  2


#endif /* 2_HAL_CLCD_CLCD_PRIVATE_H_ */
