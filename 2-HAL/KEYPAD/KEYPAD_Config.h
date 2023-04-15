/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   HAL  			      ***************************/
/*************                SWC :     KEYPAD	              ***************************/
/*************                VERSION : 1.00		          ***************************/
/*************                DATE : 7/9/2022		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define KEYPAD_PORT             DIO_u8PORTA

#define KEYPAD_COL0_PIN         DIO_u8Pin0
#define KEYPAD_COL1_PIN 	    DIO_u8Pin1
#define KEYPAD_COL2_PIN  		DIO_u8Pin2
#define KEYPAD_COL3_PIN  		DIO_u8Pin3

#define KEYPAD_ROW0_PIN  		DIO_u8Pin4
#define KEYPAD_ROW1_PIN  		DIO_u8Pin5
#define KEYPAD_ROW2_PIN  		DIO_u8Pin6
#define KEYPAD_ROW3_PIN 	    DIO_u8Pin7

#define COLUMN_NUM       4
#define ROW_NUM          4

#define KEYPAD_NO_PRESSED_KEY   0xff

#define KEYPAD_ARR_VALUE       { {1,2,3,4},\
                                 {5,6,7,8},\
								 {9,10,11,12},\
								 {13,14,15,16} }

#endif /* 2_HAL_KEYPAD_KEYPAD_CONFIG_H_ */
