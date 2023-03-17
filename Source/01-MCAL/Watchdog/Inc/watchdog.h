/*
 * watchdog.h
 *
 *  Created on: Oct 29, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_01_MCAL_WATCHDOG_INC_WATCHDOG_H_
#define SOURCE_01_MCAL_WATCHDOG_INC_WATCHDOG_H_

#include "Std_Types.h"

#define WDTCR	(*(u8*) 0x41)


void Watchdog_ON();
void Watchdog_OFF();


#endif /* SOURCE_01_MCAL_WATCHDOG_INC_WATCHDOG_H_ */
