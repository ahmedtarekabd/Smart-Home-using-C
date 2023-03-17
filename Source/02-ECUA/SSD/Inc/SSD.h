/*
 * SSD.h
 *
 *  Created on: Aug 30, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_02_ECUA_SSD_HEADER_SSD_H_
#define SOURCE_02_ECUA_SSD_HEADER_SSD_H_

#include "Std_Types.h"
#include "Dio.h"
#include "util/delay.h"

#define SSD_MASK  0x0f

void SSD_init(void);

void SSD_displayNumber(u8 number);
void SSD_displayNumberAndDelay(u8 number, u8 msec);


#endif /* SOURCE_02_ECUA_SSD_HEADER_SSD_H_ */
