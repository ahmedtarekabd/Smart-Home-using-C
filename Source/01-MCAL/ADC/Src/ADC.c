/*
 * ADC.c
 *
 *  Created on: Sep 8, 2022
 *      Author: ahmed
 */

#include "ADC.h"

void ADC_InitADC()
{

	// Don't know how it works without config dio pins to input!

	// Enable ADC
	SET_BIT(ADC_ADCSRA_REG, ADC_Enable);

	// Prescale clock (die by 128)
	ADC_ADCSRA_REG |= 0x07;			// 0000 0111

	// Vref (reference bits) match to the MC VCC
	SET_BIT(ADC_ADMUX_REG, ADC_REFS0);

	// ADLAR is default -> 0

}

f32 ADC_f32ReadChannel(adc_channel_t channelNum)
{

	// Clear MUX bits
	ADC_ADMUX_REG &= ADC_MASK;

	// Select channel
	ADC_ADMUX_REG |= channelNum;	// xxx0 0000

	// Start Conversion
	SET_BIT(ADC_ADCSRA_REG, ADC_START_CONV);

	// wait for ADIF become 1
	while (CHECK_BIT(ADC_ADCSRA_REG, ADC_INT_FLAG) != 1);

	// Clear ADIF by setting 1
	SET_BIT(ADC_ADCSRA_REG, ADC_INT_FLAG);

	u16 data = ADC_ADCL_REG | (u16)(ADC_ADCH_REG << 8);

	// Convert from mV to V
	f32 volt = (data * ADC_BIT_SIZE) / (f32) 1000;

	return volt;

}
