/*
 * DCMotor_Types.h
 *
 *  Created on: Sep 14, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_02_ECUA_DCMOTOR_INC_DCMOTOR_TYPES_H_
#define SOURCE_02_ECUA_DCMOTOR_INC_DCMOTOR_TYPES_H_

typedef enum
{

	DCMOTOR_1,
	DCMOTOR_2

}dcmotor_motorID_t;

typedef enum
{

	DCMOTOR_A1,
	DCMOTOR_A2,
	DCMOTOR_A3,
	DCMOTOR_A4

}dcmotor_switches_t;

typedef enum
{

	DCMOTOR_CLOCKWISE,
	DCMOTOR_ANTICLOCKWISE

}dcmotor_direction_t;


#endif /* SOURCE_02_ECUA_DCMOTOR_INC_DCMOTOR_TYPES_H_ */
