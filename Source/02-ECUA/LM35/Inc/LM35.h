/*
 * LM35.h
 *
 *  Created on: Sep 9, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_02_ECUA_LM35_LM35_H_
#define SOURCE_02_ECUA_LM35_LM35_H_

#include "ADC.h"
#include "Dio.h"
#include "Std_Types.h"

void LM35_Init(void);

u8 LM35_ReadTemperature(void);

#endif /* SOURCE_02_ECUA_LM35_LM35_H_ */
