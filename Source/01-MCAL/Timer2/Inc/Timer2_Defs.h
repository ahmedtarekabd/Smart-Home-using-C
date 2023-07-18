/*
 * Timer1_Reg.h
 *
 *  Created on: Sep 13, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_01_MCAL_TIMER2_INC_TIMER2_DEFS_H_
#define SOURCE_01_MCAL_TIMER2_INC_TIMER2_DEFS_H_

#include "Std_Types.h"

// Time/counter control reg
#define TCCR2_REG	(*(u8*) 0x45)
// Timer/Counter Reg
#define TCNT2_REG	(*(u8*) 0x44)
// Output compare reg
#define OCR2_REG	(*(u8*) 0x43)
// Timer/counter Interrupt mask reg
#define TIMSK_REG	(*(u8*) 0x59)


/*
 * TIMER2_MODE_NONE
 * TIMER2_MODE_NORMAL
 * TIMER2_MODE_PWM_PHASE_CONTROL
 * TIMER2_MODE_CTC
 * TIMER2_MODE_FAST_PWM
 * */

#define TIMER2_MODE_NONE
#define TIMER2_MODE_NORMAL
#define TIMER2_MODE_PWM_PHASE_CONTROL
#define TIMER2_MODE_CTC
#define TIMER2_MODE_FAST_PWM

#define TIMER2_MODE_SELECTED	TIMER2_MODE_NONE

#endif /* SOURCE_01_MCAL_TIMER2_INC_TIMER2_DEFS_H_ */
