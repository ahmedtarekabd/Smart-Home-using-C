/*
 * EXTI.c
 *
 *  Created on: Sep 7, 2022
 *      Author: ahmed
 */

#include "EXTI.h"

void EXTI_EnableInterrupt(exti_intId_t intId, exti_senseControl_t senseControl)
{

	// Enable
	SET_BIT(GICR_REG, intId);

	// Set sensor control
	switch (intId) {
	case EXTI_INT0:
		MCUCR_REG |= senseControl;
		break;
	case EXTI_INT1:
		MCUCR_REG |= (senseControl << 2);
		break;
	case EXTI_INT2:
		MCUCSR_REG |= senseControl;
		break;
	}

}

void EXTI_DisableInterrupt(exti_intId_t intId)
{

	CLEAR_BIT(GICR_REG, intId);

}
