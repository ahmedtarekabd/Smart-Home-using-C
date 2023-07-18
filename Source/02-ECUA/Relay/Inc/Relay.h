/*
 * Relay.h
 *
 *  Created on: Oct 2, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_02_ECUA_RELAY_INC_RELAY_H_
#define SOURCE_02_ECUA_RELAY_INC_RELAY_H_

#include "Dio.h"
typedef enum
{

	Relay_1,
	Relay_2,
	Relay_3,
	Relay_4,
	Relay_5,
	Relay_6

}Relay_t;

void Relay_Init();

void Relay_toogle(Relay_t T);

void Relay_setDimmer(u8 percentage);

#endif /* SOURCE_02_ECUA_RELAY_INC_RELAY_H_ */
