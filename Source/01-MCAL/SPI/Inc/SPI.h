/*
 * SPI.h
 *
 *  Created on: Sep 20, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_01_MCAL_SPI_INC_SPI_H_
#define SOURCE_01_MCAL_SPI_INC_SPI_H_

#include "Std_Types.h"
#include "SPI_Defs.h"
#include "Dio.h"

void SPI_MasterInit();
void SPI_SlaveInit();

u8 SPI_MasterTranser(u8 data);

void SPI_MasterSend(u8 data);
u8 SPI_MasterReceive();

void SPI_SlaveSend(u8 data);
u8 SPI_SlaveReceive();

#endif /* SOURCE_01_MCAL_SPI_INC_SPI_H_ */
