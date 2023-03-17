/*
 * Button.h
 *
 *  Created on: Aug 27, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_02_ECUA_BUTTON_HEADER_BUTTON_H_
#define SOURCE_02_ECUA_BUTTON_HEADER_BUTTON_H_

#include "Button_Types.h"
#include "Dio.h"

void Button_buttonInit();

button_buttonState_t Button_udtisPressed(button_buttonId_t button);

#endif /* SOURCE_02_ECUA_BUTTON_HEADER_BUTTON_H_ */
