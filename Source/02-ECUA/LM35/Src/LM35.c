/*
 * LM35.c
 *
 *  Created on: Sep 9, 2022
 *      Author: ahmed
 */

#include "LM35.h"

void LM35_Init(void)
{


	Dio_configChanel(DIO_PORTA, DIO_PIN0, DIO_INPUT);

	ADC_InitADC();

}

u8 LM35_ReadTemperature(void)
{


	// Convert from V to mV
	f32 mVolts = ADC_f32ReadChannel(ADC_CHANNEL1) * 1000;

	// From mV to degree C, where each 10mv -> 1 C
	u8 degreeC = mVolts / 10;

	return degreeC;

}
