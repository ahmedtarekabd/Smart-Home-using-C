/*
 * keypad.h
 *
 *  Created on: Sep 2, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_02_ECUA_KEYPAD_HEADER_KEYPAD_H_
#define SOURCE_02_ECUA_KEYPAD_HEADER_KEYPAD_H_

#include "Dio.h"
#include "keypad_Types.h"

void Keypad_keypadInit();

boolean Keypad_buttonIsPressed();

u8 Keypad_getButton();

keypad_row_t Keypad_getRow();
keypad_col_t Keypad_getCol(keypad_row_t row);

void Keypad_GetString(u8* string, u8 size);


#endif /* SOURCE_02_ECUA_KEYPAD_HEADER_KEYPAD_H_ */
