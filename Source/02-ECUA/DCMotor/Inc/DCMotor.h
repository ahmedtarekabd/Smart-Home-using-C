/*
 * DCMotor.h
 *
 *  Created on: Sep 13, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_02_ECUA_DCMOTOR_INC_DCMOTOR_H_
#define SOURCE_02_ECUA_DCMOTOR_INC_DCMOTOR_H_

#include "Dio.h"
#include "DCMotor_Types.h"

void DCMotor_Init(dcmotor_motorID_t motorID);

void DCMotor_Start(dcmotor_motorID_t motor, dcmotor_direction_t direction);
void DCMotor_Stop(dcmotor_motorID_t motor);

#endif /* SOURCE_02_ECUA_DCMOTOR_INC_DCMOTOR_H_ */
