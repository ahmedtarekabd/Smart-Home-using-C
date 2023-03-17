/*
 * Timer0_Reg.h
 *
 *  Created on: Sep 13, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_01_MCAL_TIMER1_INC_TIMER1_DEFS_H_
#define SOURCE_01_MCAL_TIMER1_INC_TIMER1_DEFS_H_

#include "Std_Types.h"

// Time/counter control reg
#define TCCR1A_REG	(*(u8*) 0x4F)
// Timer/Counter Reg
#define TCCR1B_REG	(*(u8*) 0x4E)
// Output compare reg
#define OCR1AH_REG	(*(u8*) 0x4B)
#define OCR1AL_REG	(*(u8*) 0x4A)
#define ICR1H_REG	(*(u8*) 0x47)
#define ICR1L_REG	(*(u8*) 0x46)

#define TCNT1H_REG	(*(u8*) 0x4D)
#define TCNT1L_REG	(*(u8*) 0x4C)


/*
 * TIMER1_MODE_NONE
 * TIMER1_MODE_NORMAL
 * TIMER1_MODE_PWM_PHASE_CONTROL
 * TIMER1_MODE_CTC
 * TIMER1_MODE_FAST_PWM
 * */

#define TIMER1_MODE_NONE
#define TIMER1_MODE_NORMAL
#define TIMER1_MODE_PWM_PHASE_CONTROL
#define TIMER1_MODE_CTC
#define TIMER1_MODE_FAST_PWM

#define TIMER1_MODE_SELECTED	TIMER1_MODE_NONE

#endif /* SOURCE_01_MCAL_TIMER1_INC_TIMER1_DEFS_H_ */
