/*
 * Led.h
 *
 *  Created on: Aug 27, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_02_ECUA_LED_HEADER_LED_H_
#define SOURCE_02_ECUA_LED_HEADER_LED_H_

#include "Led_Types.h"
#include "Dio.h"

void Led_ledInit();

void Led_turnOn(led_ledId_t led);
void Led_turnOff(led_ledId_t led);
void Led_toggle(led_ledId_t led);

#endif /* SOURCE_02_ECUA_LED_HEADER_LED_H_ */
