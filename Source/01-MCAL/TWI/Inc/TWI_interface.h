/*
 * TWI_interface.h
 *
 * Created: 9/16/2022 10:03:16 PM
 *  Author: AMIT
 */ 


#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

#include "Std_Types.h"
#include "Bit_Math.h"

void TWI_initMaster           (void);
void TWI_initSlave            (u8 slaveAdd);
void TWI_sendStartCondition   (void);
void TWI_sendRepStartCondition(void);
void TWI_sendStopCondition    (void);
void TWI_sendSlaveAddwithWrite(u8 slaveAdd);
void TWI_sendSlaveAddwithRead (u8 slaveAdd);
void TWI_sendMasterDataByte   (u8 data);
void TWI_readMasterDataByte   (u8* returnedData);

#endif /* TWI_INTERFACE_H_ */
