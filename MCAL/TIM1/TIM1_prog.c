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

void (*TIM1PTR)(void) = null ;
 
void TIM1_voidInit_Input_Capture(void)
{
	CLR_BIT(TCCR1A_REG, 0);
	CLR_BIT(TCCR1A_REG, 1);
	CLR_BIT(TCCR1B_REG, 3);
	CLR_BIT(TCCR1B_REG, 4);
	
	TCCR1B_REG &= 0b11111000 ;
	TCCR1B_REG |= TIM1_prescaler ;
	
	SET_BIT(TIMSK_REG,5);
}

void TIM1_voidSelectEdge(u8 Edge_select)
{
	switch(Edge_select)
	{
		case TIM1_FALLING_EDGE: CLR_BIT(TCCR1B_REG,6);break;
		case TIM1_RISING_EDGE: SET_BIT(TCCR1B_REG,6);break;
	}
}

u16 TIM1_u16ReadICR(void)
{
	return ICR1L_REG ;
}

void TIM1_voidICRReset(void)
{
	ICR1L_REG = 0 ;
}

void TIM1_voidFastPWMICR(void)
{
	SET_BIT(TCCR1A_REG,7);
	CLR_BIT(TCCR1A_REG,6);
	
	CLR_BIT(TCCR1A_REG, 0);
	SET_BIT(TCCR1A_REG, 1);
	SET_BIT(TCCR1B_REG, 3);
	SET_BIT(TCCR1B_REG, 4);
	
	TCCR1B_REG &= 0b11111000 ;
	TCCR1B_REG |= TIM1_prescaler ;
	
	ICR1L_REG = 40000;
}

void TIM1_voidInit(void)
{
	CLR_BIT(TCCR1A_REG, 0);
	CLR_BIT(TCCR1A_REG, 1);
	CLR_BIT(TCCR1B_REG, 3);
	CLR_BIT(TCCR1B_REG, 4);
	
	TCCR1B_REG &= 0b11111000 ;
	TCCR1B_REG |= TIM1_prescaler ;
}

u16 TIM1_u16ReadVal(void)
{
	return TCNT1L_REG ;
}

void TIM1_voidReset(void)
{
	TCNT1L_REG = 0 ;
}

void TIM1_voidSetOCRVal(u16 copy_u16val)
{
	OCR1AL_REG = copy_u16val ;
}


void TIM1_voidCallBack(void (*ptr)(void))
{
	TIM1PTR = ptr ;
}

ISR(TIMER1_CE)
{
	TIM1PTR();
}