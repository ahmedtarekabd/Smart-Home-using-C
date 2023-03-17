/*
 * Button_Types.h
 *
 *  Created on: Aug 27, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_02_ECUA_BUTTON_HEADER_BUTTON_TYPES_H_
#define SOURCE_02_ECUA_BUTTON_HEADER_BUTTON_TYPES_H_

typedef enum
{

	BUTTON0,
	BUTTON1,
	BUTTON2

}button_buttonId_t;

typedef enum
{

	ISRELEASED,
	ISPRESSED

}button_buttonState_t;

#endif /* SOURCE_02_ECUA_BUTTON_HEADER_BUTTON_TYPES_H_ */
