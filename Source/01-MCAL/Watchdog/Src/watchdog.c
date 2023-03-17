/*
 * watchdog.c
 *
 *  Created on: Oct 29, 2022
 *      Author: ahmed
 */

#include "watchdog.h"



void Watchdog_ON()
{
	/*
	Watchdog timer enables with typical timeout period 2.1
	second.
	*/
	// One Second
	WDTCR = (1<<3)|(1<<2)|(1<<1);
}

void Watchdog_OFF()
{
	/*
	This function use for disable the watchdog timer.
	*/
	WDTCR = (1<<4)|(1<<3);
	WDTCR = 0x00;
}

