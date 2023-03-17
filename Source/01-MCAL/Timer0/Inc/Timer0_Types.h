/*
 * Timer0_Types.h
 *
 *  Created on: Sep 13, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_01_MCAL_TIMER0_INC_TIMER0_TYPES_H_
#define SOURCE_01_MCAL_TIMER0_INC_TIMER0_TYPES_H_


typedef enum
{

	TIMER0_NO_SOURCE,
	TIMER0_NO_PRESCALE,
	TIMER0_BY_8,
	TIMER0_BY_64,
	TIMER0_BY_256,
	TIMER0_BY_1024

}timer0_clockSelect_t;

typedef enum
{

	TIMER0_NORMAL,
	TIMER0_PWM_PHASE_CORRECT,
	TIMER0_CTC,
	TIMER0_FAST_PWM

}timer0_waveform_t;

#endif /* SOURCE_01_MCAL_TIMER0_INC_TIMER0_TYPES_H_ */
