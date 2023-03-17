/*
 * TimerI.c
 *
 *  Created on: Sep 9, 2022
 *      Author: ahmed
 */

#include "Timer1.h"

static u8 top = 0;

static void Timer1_SetFastPWM()
{

	// Set Fast PWM, TOP in ICR1, Clear OC1A on compare match
	TCCR1A_REG = (1<<1)|(1<<7);
	TCCR1B_REG = (1<<3)|(1<<4);

	TCNT1L_REG = 0;
	TCNT1H_REG = 0;

	// Set DDR as output
	Dio_configChanel(DIO_PORTD, DIO_PIN5, DIO_OUTPUT);

}

void Timer1_Init(timer1_waveform_t waveform)
{

	// Global Interrupt
	GIE_EnableGlobalInterrupt();

	// Select Mode (waveform)
	switch(waveform)
	{

//	case TIMER1_NORMAL:
//		Timer1_SetNormal();
//		break;
//	case TIMER1_PWM_PHASE_CORRECT:
//		Timer1_SetPWMPhaseControl();
//		break;
//	case TIMER1_CTC:
//		Timer1_SetCTC();
//		break;

	case TIMER1_FAST_PWM:
		Timer1_SetFastPWM();
		break;

	}

}

void Timer1_Start(timer1_clockSelect_t clockSelect)
{

	// Clock select (Prescale)
	TCCR1B_REG |= clockSelect;

}

void Timer1_Stop()
{

	// Stop Timer/Counter by clearing prescaler
	TCCR1B_REG &= 0xf8;

}


// For PWM Modes
void Timer1_SetDuty(u8 dutyPercentage)
{

	u16 tmp = (top * ((f32) dutyPercentage / 100));
	OCR1AL_REG = tmp;
	OCR1AH_REG = tmp << 8;

}

void Timer1_SetFrequency(u8 frequency)
{

	top = ( (16000000) / (frequency * 64) ) - 1;

	ICR1L_REG = top;
	ICR1H_REG = top << 8;

}

