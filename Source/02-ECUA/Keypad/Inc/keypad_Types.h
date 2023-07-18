/*
 * keypad_Types.h
 *
 *  Created on: Sep 2, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_02_ECUA_KEYPAD_HEADER_KEYPAD_TYPES_H_
#define SOURCE_02_ECUA_KEYPAD_HEADER_KEYPAD_TYPES_H_

#define KEYPAD_INVALID	255

typedef enum
{

	KEYPAD_ROW0,
	KEYPAD_ROW1,
	KEYPAD_ROW2,
	KEYPAD_ROW3

}keypad_row_t;


typedef enum
{

	KEYPAD_COL0,
	KEYPAD_COL1,
	KEYPAD_COL2,
	KEYPAD_COL3

}keypad_col_t;

#endif /* SOURCE_02_ECUA_KEYPAD_HEADER_KEYPAD_TYPES_H_ */
