/*
 * TimerI.h
 *
 *  Created on: Sep 9, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_01_MCAL_TIMER0_INC_TIMER0_H_
#define SOURCE_01_MCAL_TIMER0_INC_TIMER0_H_

#include "Timer0_Defs.h"
#include "Bit_Math.h"
#include "Timer0_Types.h"
#include "GIE.h"
#include "Dio.h"


void Timer0_Init(timer0_waveform_t waveform);

// Normal | CTC
void Timer0_SetPreload(u8 preload);
void Timer0_SetTime(u16 time);
void Timer0_Start(u8 prescale);
void Timer0_Stop();

// For PWM Modes
void Timer0_SetDuty(u8 dutyPercentage);
void Timer0_SetFrequency(u8 frequency);

#endif /* SOURCE_01_MCAL_TIMER0_INC_TIMER0_H_ */
