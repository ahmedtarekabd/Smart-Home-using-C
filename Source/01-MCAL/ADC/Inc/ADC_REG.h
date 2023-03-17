/*
 * ADC_REG.h
 *
 *  Created on: Sep 8, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_01_MCAL_ADC_INC_ADC_REG_H_
#define SOURCE_01_MCAL_ADC_INC_ADC_REG_H_

// Select desired channel from the available 8 channels
// ADC left Adjust
// Set reference pins
#define ADC_ADMUX_REG	(*(u8*) 0x27)

// ADC Enable, Start conversion, prescaler
#define ADC_ADCSRA_REG	(*(u8*) 0x26)

// Data registers
#define ADC_ADCH_REG	(* (u8*) 0x25)
#define ADC_ADCL_REG	(* (u8*) 0x24)

#endif /* SOURCE_01_MCAL_ADC_INC_ADC_REG_H_ */
