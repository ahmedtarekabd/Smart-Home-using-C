/*
 * EXTI.h
 *
 *  Created on: Sep 7, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_01_MCAL_EXTI_HEADER_EXTI_H_
#define SOURCE_01_MCAL_EXTI_HEADER_EXTI_H_

#include "EXTI_Types.h"
#include "Bit_Math.h"
#include "Std_Types.h"

#define MCUCR_REG	(*(u8*) 0x55)	// Includes INT0(0, 1), INT1(2, 3) enable bits
#define MCUCSR_REG	(*(u8*) 0x54)	// Includes INT2 enable bits 6
#define GICR_REG	(*(u8*) 0x5b)	// Includes	INT0(6), INT1(7), INT2(5) bits


void EXTI_EnableInterrupt(exti_intId_t intId, exti_senseControl_t senseControl);
void EXTI_DisableInterrupt(exti_intId_t intId);



/*
#define ISR(vectorName) void vectorName(void) __attribute__ ((signal)); \
						void vectorName(void)

// Vector numbers are according to the datasheet's (vector number  - 1)
#define vect_INT0	__vector_1
#define vect_INT1	__vector_2
#define vect_INT2	__vector_3

void (* int0)(void) = NULL;
void (* int1)(void) = NULL;
void (* int2)(void) = NULL;
*/

#endif /* SOURCE_01_MCAL_EXTI_HEADER_EXTI_H_ */
