/*
 * GI_prog.c
 *
 * Created: 10/29/2025 5:51:51 PM
 *  Author: DELL
 */ 

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "GI_reg.h"
#include "GI_interface.h"


void GI_voidEnable()
{
	SET_BIT(SREG,I_BIT);
}

void GI_voidDisable()
{
	CLR_BIT(SREG,I_BIT);
}