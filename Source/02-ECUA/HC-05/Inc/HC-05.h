/*
 * HC-05.h
 *
 *  Created on: Sep 29, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_02_ECUA_HC_05_INC_HC_05_H_
#define SOURCE_02_ECUA_HC_05_INC_HC_05_H_

#include "Std_Types.h"
#include "UART.h"
#include "Dio.h"

void HC05_Init();

boolean HC05_IsConnected();

u8 HC05_ReceiveCharNonBlock();

boolean HC05_SendString(u8* string);
boolean HC05_ReceiveString(u8* string, u8 size);

#endif /* SOURCE_02_ECUA_HC_05_INC_HC_05_H_ */
