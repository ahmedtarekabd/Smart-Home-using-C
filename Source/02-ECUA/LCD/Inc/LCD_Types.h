/*
 * LCD_Types.h
 *
 *  Created on: Aug 31, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_02_ECUA_LCD_HEADER_LCD_TYPES_H_
#define SOURCE_02_ECUA_LCD_HEADER_LCD_TYPES_H_

typedef enum
{

	_LCD_CLEAR=0x01,
	_LCD_CURSOR_OFF=0x0C,		// 1100: Display only
	_LCD_CURSOR_BLINKING=0x0D,		// 1100: Display, blinking
	_LCD_CURSOR_UNDERLINE=0x0E,	// 1110: Display, cursor
	_LCD_CURSOR_ON=0x0F,		// 1111: Display, cursor, blinking
	//_LCD_ON=0x0F,
	_LCD_4BIT_MODE=0x28,
	_LCD_8BIT_MODE=0x38,
	_LCD_CURSOR_INCREMENT=0x06,
	_LCD_CURSOR_SHIFT_LEFT=0x10,
	_LCD_CURSOR_SHIFT_RIGHT=0x14,
	_LCD_CGRAM_START_ADDRESS=0x40

}lcd_cmd_t;

typedef enum
{

	LCD_LEFT,
	LCD_CENTER,
	LCD_RIGHT

} lcd_alignment_t;

typedef enum
{

	LCD_ROW0,
	LCD_ROW1

} lcd_row_t;

typedef enum
{

	LCD_COL0,
	LCD_COL1

} lcd_col_t;

typedef enum
{

	LCD_NO_ANIMATE,
	LCD_ANIMATE

} lcd_animate_t;


#endif /* SOURCE_02_ECUA_LCD_HEADER_LCD_TYPES_H_ */
