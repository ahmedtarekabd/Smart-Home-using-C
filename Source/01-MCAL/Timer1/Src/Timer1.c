/*
 * TimerI.c
 *
 *  Created on: Sep 9, 2022
 *      Author: ahmed
 */

#include "Timer1.h"
#include "LCD.h"

static u16 top = 0;
static f32 timerFreq = 0;

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

	// Prescale to 0 to use the OR properly
	Timer1_Stop();
	// Clock select (Prescale)
	TCCR1B_REG |= clockSelect;

}

void Timer1_Stop()
{

	// Stop Timer/Counter by clearing prescaler
	TCCR1B_REG &= 0xf8;

}




// For PWM Modes
void Timer1_SetDuty(f32 Ton)
{

	// Timer freq = 16000000/prescale
	u16 tmp = Ton * timerFreq;

	OCR1AL_REG = tmp;
	OCR1AH_REG = tmp >> 8;

}

void Timer1_SetFrequency(u16 frequency)
{

	timerFreq = 16000000.0 / 256.0;
	top = ( timerFreq / frequency ) - 1;

	ICR1L_REG = top;
	ICR1H_REG = top >> 8;

}


/*
 * Testing
 * */
/* setDuty */
//	LCD_setAddressPosition(0, 2);
//	LCD_displayChar(' ');
//	LCD_displayChar(' ');
//	LCD_displayChar(' ');
//	LCD_setAddressPosition(0, 2);
////	LCD_displayInt(tmp);
//	LCD_displayInt((u16) ((OCR1AH_REG << 8) | OCR1AL_REG));

/* setFreq */
//	LCD_setAddressPosition(1, 0);
//	LCD_displayString("top");
//	LCD_displayInt(top);
//	LCD_displayChar(' ');
//	LCD_displayString("freq");
//	LCD_displayFloat(timerFreq);

