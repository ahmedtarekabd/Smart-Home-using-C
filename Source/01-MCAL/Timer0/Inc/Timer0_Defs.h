/*
 * Timer0_Reg.h
 *
 *  Created on: Sep 13, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_01_MCAL_TIMER0_INC_TIMER0_DEFS_H_
#define SOURCE_01_MCAL_TIMER0_INC_TIMER0_DEFS_H_

#include "Std_Types.h"

// Time/counter control reg
#define TCCR0_REG	(*(u8*) 0x53)
// Timer/Counter Reg
#define TCNT0_REG	(*(u8*) 0x52)
// Output compare reg
#define OCR0_REG	(*(u8*) 0x5C)
// Timer/counter Interrupt mask reg
#define TIMSK_REG	(*(u8*) 0x59)


/*
 * TIMER0_MODE_NONE
 * TIMER0_MODE_NORMAL
 * TIMER0_MODE_PWM_PHASE_CONTROL
 * TIMER0_MODE_CTC
 * TIMER0_MODE_FAST_PWM
 * */

#define TIMER0_MODE_NONE
#define TIMER0_MODE_NORMAL
#define TIMER0_MODE_PWM_PHASE_CONTROL
#define TIMER0_MODE_CTC
#define TIMER0_MODE_FAST_PWM

#define TIMER0_MODE_SELECTED	TIMER0_MODE_NONE

#endif /* SOURCE_01_MCAL_TIMER0_INC_TIMER0_DEFS_H_ */
