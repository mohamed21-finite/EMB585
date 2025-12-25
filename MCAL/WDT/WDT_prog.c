/*
 * WDT_prog.c
 *
 * Created: 12/18/2025 10:51:15 PM
 *  Author: DELL
 */ 

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/interrupt_vector.h"
#include "WDT_interface.h"
#include "WDT_reg.h"

void WDT_voidEnableInit(void)
{
	wdt_reset();
	
	SET_BIT(WDTCR_REG, 3);
	SET_BIT(WDTCR_REG, 4);
	WDTCR_REG |= WDT_prescaler ;
}


void WDT_voidDisable(void)
{
	wdt_reset();
	
	SET_BIT(WDTCR_REG, 3);
	SET_BIT(WDTCR_REG, 4);
	
	WDTCR_REG = 0x00 ;
}