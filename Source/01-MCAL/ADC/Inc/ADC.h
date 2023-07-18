/*
 * ADC.h
 *
 *  Created on: Sep 8, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_01_MCAL_ADC_INC_ADC_H_
#define SOURCE_01_MCAL_ADC_INC_ADC_H_

#include "Std_Types.h"
#include "Bit_Math.h"
#include "ADC_Types.h"
#include "ADC_REG.h"
#include "Dio.h"


void ADC_InitADC();

f32 ADC_f32ReadChannel(adc_channel_t channelNum);

#endif /* SOURCE_01_MCAL_ADC_INC_ADC_H_ */
