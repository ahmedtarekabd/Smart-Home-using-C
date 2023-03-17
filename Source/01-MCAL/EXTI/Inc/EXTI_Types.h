/*
 * EXTI_Types.h
 *
 *  Created on: Sep 7, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_01_MCAL_EXTI_HEADER_EXTI_TYPES_H_
#define SOURCE_01_MCAL_EXTI_HEADER_EXTI_TYPES_H_

typedef enum
{

	// Enumerated by enable bits in MCU REGs
	EXTI_INT0 = 6,
	EXTI_INT1 = 7,
	EXTI_INT2 = 5

}exti_intId_t;

typedef enum
{

	// Enumerated by sense control according to datasheet
	EXTI_LOW,
	EXTI_LOGICAL_CHANGE,
	EXTI_FALLING,
	EXTI_RISING

}exti_senseControl_t;

#endif /* SOURCE_01_MCAL_EXTI_HEADER_EXTI_TYPES_H_ */
