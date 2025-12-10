/*
 * TIM1_prog.c
 *
 * Created: 12/8/2025 6:20:18 PM
 *  Author: DELL
 */ 

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/Interrupt_vector.h"
#include "TIM1_interface.h"
#include "TIM1_reg.h"


void TIM1_voidFastPWMICR(void)
{
	SET_BIT(TCCR1A_REG,7);
	CLR_BIT(TCCR1A_REG,6);
	
	CLR_BIT(TCCR1A_REG, 0);
	SET_BIT(TCCR1A_REG, 1);
	SET_BIT(TCCR1B_REG, 3);
	SET_BIT(TCCR1B_REG, 4);
	
	TCCR1B_REG &= 0b11111000 ;
	TCCR1B_REG |= TIM1_prescaler_8 ;
	
	ICR1L_REG = 40000;
}


void TIM1_voidSetOCRVal(u16 copy_u16val)
{
	OCR1AL_REG = copy_u16val ;
}