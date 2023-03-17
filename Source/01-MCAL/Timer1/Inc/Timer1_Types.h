/*
 * Timer0_Types.h
 *
 *  Created on: Sep 13, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_01_MCAL_TIMER1_INC_TIMER1_TYPES_H_
#define SOURCE_01_MCAL_TIMER1_INC_TIMER1_TYPES_H_


typedef enum
{

	TIMER1_NO_SOURCE,
	TIMER1_NO_PRESCALE,
	TIMER1_BY_8,
	TIMER1_BY_64,
	TIMER1_BY_256,
	TIMER1_BY_1024

}timer1_clockSelect_t;

typedef enum
{

	TIMER1_NORMAL,
	TIMER1_PWM_PHASE_CORRECT,
	TIMER1_CTC,
	TIMER1_FAST_PWM

}timer1_waveform_t;

#endif /* SOURCE_01_MCAL_TIMER1_INC_TIMER1_TYPES_H_ */
