/*
 * TimerI.c
 *
 *  Created on: Sep 9, 2022
 *      Author: ahmed
 */

#include "Timer0.h"

static void Timer0_SetPWMPhaseControl()
{

	SET_BIT(TCCR0_REG, 6);

	// Non-Inverted
	TCCR0_REG |= 2 << 4;

	// Set DDR as output
//	Dio_writeChanel(DIO_PORTB, DIO_PIN3, DIO_OUTPUT);
	Dio_configChanel(DIO_PORTB, DIO_PIN3, DIO_OUTPUT);

}

static void Timer0_SetNormal()
{

	// Enable Timer0 Interrupt overflow
	TIMSK_REG |= 1;

}
static void Timer0_SetCTC()
{

	// Enable Timer0 Interrupt overflow
	TIMSK_REG |= 2;
	SET_BIT(TCCR0_REG, 3);

}

static void Timer0_SetFastPWM()
{

	SET_BIT(TCCR0_REG, 6);
	SET_BIT(TCCR0_REG, 3);

	// Non-Inverted
	TCCR0_REG |= 2 << 4;

	// Set DDR as output
	Dio_configChanel(DIO_PORTB, DIO_PIN3, DIO_OUTPUT);
//	Dio_writeChanel(DIO_PORTB, DIO_PIN3, DIO_HIGH);

}

void Timer0_Init(timer0_waveform_t waveform)
{

	// Global Interrupt
	GIE_EnableGlobalInterrupt();

	// Select Mode (waveform)
	switch(waveform)
	{

	case TIMER0_NORMAL:
		Timer0_SetNormal();
		break;
	case TIMER0_PWM_PHASE_CORRECT:
		Timer0_SetPWMPhaseControl();
		break;
	case TIMER0_CTC:
		Timer0_SetCTC();
		break;
	case TIMER0_FAST_PWM:
		Timer0_SetFastPWM();
		break;

	}

}

// Normal | CTC



void Timer0_SetPreload(u8 preload)
{

	if (preload > 256)
	{
		return;
	}

	TCNT0_REG |= preload;

}

void Timer0_SetTime(u16 time)
{

	// Tick time = 1/prescale
	// Overload time = (256 - preload value) * Tick time
	// Preload = 256 - (time/Tick Time)

	u8 prescale = TCCR0_REG & 0x07;		// 0000 0111
	u8 tickTime = 1 / prescale;
	u8 preload = 256 - (time / tickTime);

	Timer0_SetPreload(preload);

}

void Timer0_Start(timer0_clockSelect_t clockSelect)
{

	// Clock select (Prescale)
	TCCR0_REG |= clockSelect;

}

void Timer0_Stop()
{

	// Stop Timer/Counter by clearing prescaler
	TCCR0_REG &= 0xf8;

}


// For PWM Modes
void Timer0_SetDuty(u8 dutyPercentage)
{

	OCR0_REG = (u8) (255 * ((f32) dutyPercentage / 100));

}

void Timer0_SetFrequency(u8 frequency)
{



}

