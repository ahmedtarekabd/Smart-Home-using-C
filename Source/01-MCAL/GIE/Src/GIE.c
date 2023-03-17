/*
 * GIE.c
 *
 *  Created on: Sep 7, 2022
 *      Author: ahmed
 */

#include "GIE.h"

void GIE_EnableGlobalInterrupt()
{

	SET_BIT(GIE_SREG, GIE_l_bit);

}

void GIE_DisableGlobalInterrupt()
{

	CLEAR_BIT(GIE_SREG, GIE_l_bit);

}
