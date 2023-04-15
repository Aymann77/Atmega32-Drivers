/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   HAL  			      ***************************/
/*************                SWC :     KEYPAD	              ***************************/
/*************                VERSION : 1.00		          ***************************/
/*************                DATE : 18/9/2022		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

#include "../../4-LIB/STD_TYPES.h"

#include "../../1-MCAL/DIO/DIO_Interface.h"

#include "KEYPAD_Config.h"
#include "KEYPAD_Interface.h"
#include "KEYPAD_Private.h"

void KEYPAD_voidInit(void)
{
	/*Column Pins Direction As Output*/
	DIO_u8SetPinDirection( KEYPAD_PORT , KEYPAD_COL0_PIN , DIO_u8PIN_OUTPUT ) ;
	DIO_u8SetPinDirection( KEYPAD_PORT , KEYPAD_COL1_PIN , DIO_u8PIN_OUTPUT ) ;
	DIO_u8SetPinDirection( KEYPAD_PORT , KEYPAD_COL2_PIN , DIO_u8PIN_OUTPUT ) ;
	DIO_u8SetPinDirection( KEYPAD_PORT , KEYPAD_COL3_PIN , DIO_u8PIN_OUTPUT ) ;

	/*Set Column Pins Initially High */
	DIO_u8SetPinValue( KEYPAD_PORT , KEYPAD_COL0_PIN , DIO_u8PIN_HIGH ) ;
	DIO_u8SetPinValue( KEYPAD_PORT , KEYPAD_COL1_PIN , DIO_u8PIN_HIGH ) ;
	DIO_u8SetPinValue( KEYPAD_PORT , KEYPAD_COL2_PIN , DIO_u8PIN_HIGH ) ;
	DIO_u8SetPinValue( KEYPAD_PORT , KEYPAD_COL3_PIN , DIO_u8PIN_HIGH ) ;

	/*Set Row Pins As Input and Enable Pull Up Resistor*/
	DIO_u8PinPullUpResistor( KEYPAD_PORT , KEYPAD_ROW0_PIN ) ;
	DIO_u8PinPullUpResistor( KEYPAD_PORT , KEYPAD_ROW1_PIN ) ;
	DIO_u8PinPullUpResistor( KEYPAD_PORT , KEYPAD_ROW2_PIN ) ;
	DIO_u8PinPullUpResistor( KEYPAD_PORT , KEYPAD_ROW3_PIN ) ;

}



u8 KEYPAD_u8GetPressedKey(void)
{
	/*Variable To Hold Pressed Key Value and Return it*/
	u8 Local_u8PressedKey = KEYPAD_NO_PRESSED_KEY ;

	/*Variable To Check on Rows if Certain Switch is Pressed*/
	u8 Local_u8PinState;

	/*For Loop Iterators for Rows And Columns*/
	u8 Local_u8ColumnIndex = 0 , Local_u8RowIndex = 0 ;

	/*Keypad Array that Hold values that Can Change depend on Application From Configuration file*/
	static u8 Local_u8KeypadArr[ ROW_NUM ][ COLUMN_NUM ] = KEYPAD_ARR_VALUE ;

	/*Static Arrays to be Save in .data Section Instead of being pushed in Stack*/

	/*Arrays for Row Pins and Column Pins to traverse through Column Pins and Row Pins Easily*/
	static u8 Local_u8KeypadColumnArr[COLUMN_NUM] = { KEYPAD_COL0_PIN , KEYPAD_COL1_PIN , KEYPAD_COL2_PIN , KEYPAD_COL3_PIN };
	static u8 Local_u8KeypadRowArr[ROW_NUM] = { KEYPAD_ROW0_PIN , KEYPAD_ROW1_PIN , KEYPAD_ROW2_PIN , KEYPAD_ROW3_PIN };

	/*Iterate through Columns */
	for( Local_u8ColumnIndex = 0 ; Local_u8ColumnIndex < COLUMN_NUM ; Local_u8ColumnIndex++ )
	{
		/*Activate Current Column (LOW)*/
		DIO_u8SetPinValue( KEYPAD_PORT , Local_u8KeypadColumnArr[ Local_u8ColumnIndex ] , DIO_u8PIN_LOW );

		/*Iterate through Rows */
		for( Local_u8RowIndex = 0 ; Local_u8RowIndex < ROW_NUM ; Local_u8RowIndex++ )
		{
			/*Read Current Row*/
			DIO_u8GetPinValue( KEYPAD_PORT , Local_u8KeypadRowArr[Local_u8RowIndex] , &Local_u8PinState );

			/*Check If Switch is Pressed*/
			if( Local_u8PinState == KEY_PRESSED )
			{
				Local_u8PressedKey = Local_u8KeypadArr[Local_u8RowIndex][Local_u8ColumnIndex] ;

				/*Polling Until Key is Released To Prevent Returning More than Once*/
				while( Local_u8PinState == KEY_PRESSED )
				{
					DIO_u8GetPinValue( KEYPAD_PORT , Local_u8KeypadRowArr[Local_u8RowIndex] , &Local_u8PinState );
				}
				return Local_u8PressedKey;
			}
		}

		/*Deactivate Current Column (HIGH)*/
		DIO_u8SetPinValue( KEYPAD_PORT ,  Local_u8KeypadColumnArr[ Local_u8ColumnIndex ] , DIO_u8PIN_HIGH );
	}

	return Local_u8PressedKey ;
}

u8 KEYPAD_u8PollingUntilKeyPressed(void)
{
	u8 Local_u8PressedKey = KEYPAD_NO_PRESSED_KEY ;
	do {
		Local_u8PressedKey = KEYPAD_u8GetPressedKey() ;
	}while( Local_u8PressedKey == KEYPAD_NO_PRESSED_KEY ) ;

	return Local_u8PressedKey ;
}
