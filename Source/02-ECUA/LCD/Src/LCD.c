/*
 * LCD.c
 *
 *  Created on: Aug 31, 2022
 *      Author: ahmed
 */

#include "LCD.h"

static u8 row = 0;
static u8 col = 0;
static lcd_alignment_t alignment = LCD_LEFT;
static void LCD_staticdisplayString(u8* _char, lcd_animate_t animate, lcd_alignment_t align);

void LCD_init(void)
{

	// Control pins
	Dio_configChanel(DIO_PORTB, DIO_PIN1, DIO_OUTPUT);
	Dio_configChanel(DIO_PORTB, DIO_PIN2, DIO_OUTPUT);
	Dio_configChanel(DIO_PORTB, DIO_PIN3, DIO_OUTPUT);

	// Data pins
	Dio_configChanel(DIO_PORTA, DIO_PIN4, DIO_OUTPUT);
	Dio_configChanel(DIO_PORTA, DIO_PIN5, DIO_OUTPUT);
	Dio_configChanel(DIO_PORTA, DIO_PIN6, DIO_OUTPUT);
	Dio_configChanel(DIO_PORTA, DIO_PIN7, DIO_OUTPUT);

	// R/W -> Write to LCD
	Dio_writeChanel(DIO_PORTB, DIO_PIN2, DIO_LOW);

	_delay_ms(15);
	LCD_sendCmd(0x03);

	_delay_ms(5);
	LCD_sendCmd(0x03);

	_delay_us(100);
	LCD_sendCmd(0x03);

	LCD_sendCmd(0x02);
	LCD_sendCmd(_LCD_4BIT_MODE);
	LCD_sendCmd(_LCD_CLEAR);
	LCD_sendCmd(_LCD_CURSOR_ON);

}

static void LCD_generateEnablePulse()
{

	Dio_writeChanel(DIO_PORTB, DIO_PIN3, DIO_HIGH);
	_delay_ms(2);
	Dio_writeChanel(DIO_PORTB, DIO_PIN3, DIO_LOW);

}

static void LCD_sendData(u8 data)
{

	u8 msb = data & ~LCD_MASK;
	u8 lsb = data << 4;

	// Write to port by group two times
	// MSB (Most)
	Dio_writeChanelGroup(DIO_PORTA, msb, LCD_MASK);

	// Generate enable pulse to enable lcd to read last bits
	LCD_generateEnablePulse();

	// LSB (Least)
	Dio_writeChanelGroup(DIO_PORTA, lsb, LCD_MASK);

	// Generate enable pulse to enable lcd to read last bits
	LCD_generateEnablePulse();


}

void LCD_displayChar(u8 _char)
{

	if (_char == '\0')
	{
		return;
	}

	// RS = 1 -> to be displayed
	Dio_writeChanel(DIO_PORTB, DIO_PIN1, DIO_HIGH);

	LCD_sendData(_char);
	col++;

}

void LCD_displayInt(u32 number)
{

	u8 buffer[100];

	sprintf(buffer, "%d", number);

	LCD_staticdisplayString(buffer, LCD_NO_ANIMATE, LCD_NONE);

}

void LCD_displayFloat(f32 number)
{

	u8 wholeNum = number;

	LCD_displayInt(wholeNum);
	LCD_displayChar('.');

	number -= wholeNum;
	number *= 100;

	LCD_displayInt(number);

}

static void LCD_staticdisplayString(u8* _char, lcd_animate_t animate, lcd_alignment_t align)
{

	u8 size = strlen(_char);

	if (align)
	{

		switch (alignment)
		{

		case LCD_LEFT:
			LCD_setAddressPosition(row, 0);
			break;
		case LCD_CENTER:
			LCD_setAddressPosition(row, 8 - (size / 2));
			break;
		case LCD_RIGHT:
			LCD_setAddressPosition(row, 16 - size);
			break;

		}

	}

	for (u8* i = _char; *i != '\0'; i++)
	{

		LCD_displayChar(*i);
		if (animate == LCD_ANIMATE)
		{
			_delay_ms(100);
		}

	}

}

void LCD_displayString(u8* _char)
{

	LCD_staticdisplayString(_char, LCD_NO_ANIMATE, alignment);

}

void LCD_displayStringWithAnimation(u8* _char)
{

	LCD_staticdisplayString(_char, LCD_ANIMATE, alignment);

}

void LCD_sendCmd(u8 cmd)
{

	// RS = 0 -> to get command
	Dio_writeChanel(DIO_PORTB, DIO_PIN1, DIO_LOW);

	LCD_sendData(cmd);

}

void LCD_ClearRow(lcd_row_t rowNum)
{

	LCD_setAddressPosition(rowNum, 0);

	for (u8 i = 0; i < 16; i++)
		LCD_displayChar(' ');

	LCD_setAddressPosition(rowNum, 0);

}

void LCD_setAlignment(lcd_alignment_t align)
{

	alignment = align;

}

void LCD_setAddressPosition(u8 rowIn, u8 colIn)
{

	switch (rowIn)
	{

	case LCD_ROW0:
		row = rowIn;
		LCD_sendCmd(LCD_ROW0_AD + colIn);
		break;

	case LCD_ROW1:
		row = rowIn;
		LCD_sendCmd(LCD_ROW1_AD + colIn);
		break;

	}

}


// 0000 0000 0000 0100
// 1111 1111 1111 1011
// 0000 0000 0010 0000
