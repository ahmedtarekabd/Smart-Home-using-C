/*
 * LCD.h
 *
 *  Created on: Aug 31, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_02_ECUA_LCD_HEADER_LCD_H_
#define SOURCE_02_ECUA_LCD_HEADER_LCD_H_

#include "Dio.h"
#include "Std_Types.h"
#include "LCD_Types.h"
#include "LCD_Defs.h"
#include <stdio.h>
#include <util/delay.h>

void LCD_init(void);

void LCD_displayChar(u8 _char);
void LCD_displayInt(u32 number);
void LCD_displayFloat(f32 number);
void LCD_displayString(u8* _char);
void LCD_displayStringWithAnimation(u8* _char);

void LCD_sendCmd(u8 cmd);

void LCD_ClearRow(lcd_row_t rowNum);
void LCD_setAlignment(lcd_alignment_t align);
void LCD_setAddressPosition(u8 row, u8 col);

#endif /* SOURCE_02_ECUA_LCD_HEADER_LCD_H_ */
