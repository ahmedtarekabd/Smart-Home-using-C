/*
 * ADC_Types.h
 *
 *  Created on: Sep 8, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_01_MCAL_ADC_INC_ADC_TYPES_H_
#define SOURCE_01_MCAL_ADC_INC_ADC_TYPES_H_

// We will only modify the first bits
#define ADC_MASK 		0xf8;	// 1111 1000
#define ADC_BIT_SIZE	4.8

typedef enum
{

	ADC_MUX0,	// Select a channel from 8 possible channels
	ADC_MUX1,
	ADC_MUX2,
	ADC_MUX3,
	ADC_MUX4,
	ADC_ADLR,	// Left Adjustment
	ADC_REFS0,	// Reference selection (selects the Vref from which pin)
	ADC_REFS1	// Reference selection (selects the Vref from which pin)

}adc_admux_bits_t;

typedef enum
{

	ADC_INT_FLAG = 4,
	ADC_START_CONV = 6,
	ADC_Enable

}adc_adcsra_bits_t;

typedef enum
{

	ADC_CHANNEL0,
	ADC_CHANNEL1,
	ADC_CHANNEL2,
	ADC_CHANNEL3,
	ADC_CHANNEL4,
	ADC_CHANNEL5,
	ADC_CHANNEL6,
	ADC_CHANNEL7

}adc_channel_t;


#endif /* SOURCE_01_MCAL_ADC_INC_ADC_TYPES_H_ */
