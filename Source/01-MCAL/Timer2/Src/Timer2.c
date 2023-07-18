/*
 * Timer2.c
 *
 *  Created on: Sep 9, 2022
 *      Author: ahmed
 */

#include "Timer2.h"

static u16 top = 0;
static f32 timerFreq = 0;

static void Timer2_SetPWMPhaseControl()
{

	SET_BIT(TCCR2_REG, 6);

	// Non-Inverted
	TCCR2_REG |= 2 << 4;

	// Set DDR as output
//	Dio_writeChanel(DIO_PORTB, DIO_PIN3, DIO_OUTPUT);
	Dio_configChanel(DIO_PORTD, DIO_PIN7, DIO_OUTPUT);

}

static void Timer2_SetNormal()
{

	// Enable Timer2 Interrupt overflow
	TIMSK_REG |= 1;

}
static void Timer2_SetCTC()
{

	// Enable Timer2 Interrupt overflow
	TIMSK_REG |= 2;
	SET_BIT(TCCR2_REG, 3);

}

static void Timer2_SetFastPWM()
{

	SET_BIT(TCCR2_REG, 6);
	SET_BIT(TCCR2_REG, 3);

	// Non-Inverted
	TCCR2_REG |= 2 << 4;

	// Set DDR as output
	Dio_configChanel(DIO_PORTD, DIO_PIN7, DIO_OUTPUT);

}

void Timer2_Init(timer2_waveform_t waveform)
{

	// Global Interrupt
	GIE_EnableGlobalInterrupt();

	// Select Mode (waveform)
	switch(waveform)
	{

	case TIMER2_NORMAL:
		Timer2_SetNormal();
		break;
	case TIMER2_PWM_PHASE_CORRECT:
		Timer2_SetPWMPhaseControl();
		break;
	case TIMER2_CTC:
		Timer2_SetCTC();
		break;
	case TIMER2_FAST_PWM:
		Timer2_SetFastPWM();
		break;

	}

}

// Normal | CTC



void Timer2_SetPreload(u8 preload)
{

	if (preload > 256)
	{
		return;
	}

	TCNT2_REG |= preload;

}

void Timer2_SetTime(u16 time)
{

	// Tick time = 1/prescale
	// Overload time = (256 - preload value) * Tick time
	// Preload = 256 - (time/Tick Time)

	u8 prescale = TCCR2_REG & 0x07;		// 0000 0111
	u8 tickTime = 1 / prescale;
	u8 preload = 256 - (time / tickTime);

	Timer2_SetPreload(preload);

}

void Timer2_Start(timer2_clockSelect_t clockSelect)
{

	// Clock select (Prescale)
	TCCR2_REG |= clockSelect;

	u8 prescale = TCCR2_REG & 0x07;		// 0000 0111
	timerFreq = 16000000.0 / prescale;

}

void Timer2_Stop()
{

	// Stop Timer/Counter by clearing prescaler
	TCCR2_REG &= 0xf8;

}


// For PWM Modes
void Timer2_SetDuty(u8 percentage)
{


	// OCR2 is 8bit -> 255 max
	OCR2_REG = (u8) 255 * (percentage / 100.0);


}

//void Timer2_SetFrequency(u8 frequency)
//{
//
//	timerFreq = 16000000.0 / 256.0;
//
//}

