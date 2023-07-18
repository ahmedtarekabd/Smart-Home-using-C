/*
 * Timer2.h
 *
 *  Created on: Sep 9, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_01_MCAL_TIMER2_INC_TIMER2_H_
#define SOURCE_01_MCAL_TIMER2_INC_TIMER2_H_

#include "Timer2_Defs.h"
#include "Timer2_Types.h"
#include "Bit_Math.h"
#include "GIE.h"
#include "Dio.h"

void Timer2_Init(timer2_waveform_t waveform);

// Normal | CTC
void Timer2_SetPreload(u8 preload);
void Timer2_SetTime(u16 time);
void Timer2_Start(u8 prescale);
void Timer2_Stop();

// For PWM Modes
void Timer2_SetDuty(u8 percentage);
void Timer2_SetFrequency(u8 frequency);


#endif /* SOURCE_01_MCAL_TIMER2_INC_TIMER2_H_ */
