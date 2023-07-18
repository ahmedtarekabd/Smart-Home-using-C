/*
 * keypad.c
 *
 *  Created on: Sep 2, 2022
 *      Author: ahmed
 */

#include "keypad.h"
#include "LCD.h"


u8 Keypad_Layout[4][4] = {
		{'1', '2', '3', 'A'},
		{'4', '5', '6', 'B'},
		{'7', '8', '9', 'C'},
		{'*', '0', '#', 'D'}
};

void Keypad_keypadInit()

{

	// Set row to input
	Dio_configChanel(DIO_PORTC, DIO_PIN3, DIO_INPUT);
	Dio_configChanel(DIO_PORTC, DIO_PIN4, DIO_INPUT);
	Dio_configChanel(DIO_PORTC, DIO_PIN5, DIO_INPUT);
	Dio_configChanel(DIO_PORTC, DIO_PIN6, DIO_INPUT);

	// Set col to output
	Dio_configChanel(DIO_PORTB, DIO_PIN4, DIO_OUTPUT);
	Dio_configChanel(DIO_PORTB, DIO_PIN5, DIO_OUTPUT);
	Dio_configChanel(DIO_PORTB, DIO_PIN6, DIO_OUTPUT);
	Dio_configChanel(DIO_PORTB, DIO_PIN7, DIO_OUTPUT);

	// Set col to high
	Dio_writeChanel(DIO_PORTB, DIO_PIN4, DIO_HIGH);
	Dio_writeChanel(DIO_PORTB, DIO_PIN5, DIO_HIGH);
	Dio_writeChanel(DIO_PORTB, DIO_PIN6, DIO_HIGH);
	Dio_writeChanel(DIO_PORTB, DIO_PIN7, DIO_HIGH);

}
boolean Keypad_buttonIsPressed()
{

	if (
			Dio_udtreadChanel(DIO_PORTC, DIO_PIN3) ||
			Dio_udtreadChanel(DIO_PORTC, DIO_PIN4) ||
			Dio_udtreadChanel(DIO_PORTC, DIO_PIN5) ||
			Dio_udtreadChanel(DIO_PORTC, DIO_PIN6)

	)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}

}

u8 Keypad_getButton()
{

//	if (Keypad_buttonIsPressed() == FALSE)
//		return KEYPAD_INVALID;

	keypad_row_t row = KEYPAD_INVALID;
	keypad_col_t col = KEYPAD_INVALID;

//	if (!Keypad_buttonIsPressed())
//		return KEYPAD_INVALID;

	row = Keypad_getRow();

	if (row == KEYPAD_INVALID)
		return KEYPAD_INVALID;

	col = Keypad_getCol(row);

	if (row == KEYPAD_INVALID || col == KEYPAD_INVALID)
		return KEYPAD_INVALID;

	while (Keypad_buttonIsPressed() == TRUE);
	_delay_ms(5);

	return Keypad_Layout[row][col]; // || (row << 4) | col

}

keypad_row_t Keypad_getRow()
{

	if (Dio_udtreadChanel(DIO_PORTC, DIO_PIN3) == 1)
	{
//		LCD_displayInt(KEYPAD_ROW0);
		return KEYPAD_ROW0;
	}
	else if (Dio_udtreadChanel(DIO_PORTC, DIO_PIN4) == 1)
	{
//		LCD_displayInt(KEYPAD_ROW1);
		return KEYPAD_ROW1;
	}
	else if (Dio_udtreadChanel(DIO_PORTC, DIO_PIN5) == 1)
	{
//		LCD_displayInt(KEYPAD_ROW2);
		return KEYPAD_ROW2;
	}
	else if (Dio_udtreadChanel(DIO_PORTC, DIO_PIN6) == 1)
	{
//		LCD_displayInt(KEYPAD_ROW3);
		return KEYPAD_ROW3;
	}
	else
		return KEYPAD_INVALID;

}

keypad_col_t Keypad_getCol(keypad_row_t row)
{

	// Switch every col to 0 and check if row still high
	// If row switched to low, return col


	// Col 1
	Dio_writeChanel(DIO_PORTB, DIO_PIN4, DIO_LOW);
	if (row != Keypad_getRow())
	{

		Dio_writeChanel(DIO_PORTB, DIO_PIN4, DIO_HIGH);
		return KEYPAD_COL0;

	}
	Dio_writeChanel(DIO_PORTB, DIO_PIN4, DIO_HIGH);

	// Col 2
	Dio_writeChanel(DIO_PORTB, DIO_PIN5, DIO_LOW);
	if (row != Keypad_getRow())
	{

		Dio_writeChanel(DIO_PORTB, DIO_PIN5, DIO_HIGH);
		return KEYPAD_COL1;

	}
	Dio_writeChanel(DIO_PORTB, DIO_PIN5, DIO_HIGH);

	// Col 3
	Dio_writeChanel(DIO_PORTB, DIO_PIN6, DIO_LOW);
	if (row != Keypad_getRow())
	{

		Dio_writeChanel(DIO_PORTB, DIO_PIN6, DIO_HIGH);
		return KEYPAD_COL2;

	}
	Dio_writeChanel(DIO_PORTB, DIO_PIN6, DIO_HIGH);

	// Col 4
	Dio_writeChanel(DIO_PORTB, DIO_PIN7, DIO_LOW);
	if (row != Keypad_getRow())
	{

		Dio_writeChanel(DIO_PORTB, DIO_PIN7, DIO_HIGH);
		return KEYPAD_COL3;

	}

	Dio_writeChanel(DIO_PORTB, DIO_PIN7, DIO_HIGH);

	return KEYPAD_INVALID;

}


void Keypad_GetString(u8* string, u8 size)
{

	u8 tmp = Keypad_getButton();
	while (tmp == KEYPAD_INVALID)
	{
		tmp = Keypad_getButton();
	}

	u8 i = 0;

	while ((tmp != '*') && (i < size - 1))
	{

		string[i] = tmp;
		tmp = Keypad_getButton();
		while (tmp == KEYPAD_INVALID)
		{
			tmp = Keypad_getButton();
		}
		i++;

	}

	// For precise memory allocation, add 1 to the size of the array for the null char
	string[i] = '\0';

}

