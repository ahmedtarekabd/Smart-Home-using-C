/*
 * Servo.h
 *
 *  Created on: Nov 3, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_02_ECUA_SERVO_INC_SERVO_H_
#define SOURCE_02_ECUA_SERVO_INC_SERVO_H_

#include "Timer1.h"
#include "Std_Types.h"

void Servo_Init();
void Servo_Start();
void Servo_Stop();
void Servo_SetAngle(u8 angle);

#endif /* SOURCE_02_ECUA_SERVO_INC_SERVO_H_ */
