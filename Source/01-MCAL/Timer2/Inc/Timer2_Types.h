/*
 * TIMER2_Types.h
 *
 *  Created on: Sep 13, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_01_MCAL_TIMER2_INC_TIMER2_TYPES_H_
#define SOURCE_01_MCAL_TIMER2_INC_TIMER2_TYPES_H_


typedef enum
{

	TIMER2_NO_SOURCE,
	TIMER2_NO_PRESCALE,
	TIMER2_BY_8,
	TIMER2_BY_64,
	TIMER2_BY_256,
	TIMER2_BY_1024

}timer2_clockSelect_t;

typedef enum
{

	TIMER2_NORMAL,
	TIMER2_PWM_PHASE_CORRECT,
	TIMER2_CTC,
	TIMER2_FAST_PWM

}timer2_waveform_t;

#endif /* SOURCE_01_MCAL_TIMER2_INC_TIMER2_TYPES_H_ */
