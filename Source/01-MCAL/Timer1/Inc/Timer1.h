/*
 * TimerI.h
 *
 *  Created on: Sep 9, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_01_MCAL_TIMER1_INC_TIMER1_H_
#define SOURCE_01_MCAL_TIMER1_INC_TIMER1_H_

#include "Timer1_Defs.h"
#include "Bit_Math.h"
#include "Timer1_Types.h"
#include "GIE.h"
#include "Dio.h"


void Timer1_Init(timer1_waveform_t waveform);

void Timer1_Start(timer1_clockSelect_t clockSelect);
void Timer1_Stop();

// For PWM Modes
void Timer1_SetDuty(f32 Ton);
void Timer1_SetFrequency(u16 frequency);

#endif /* SOURCE_01_MCAL_TIMER1_INC_TIMER1_H_ */
