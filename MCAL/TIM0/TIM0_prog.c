/*
 * TIM0_prog.c
 *
 * Created: 11/24/2025 6:40:15 PM
 *  Author: DELL
 */ 

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/Interrupt_vector.h"
#include "TIM0_interface.h"
#include "TIM0_reg.h"


void (*TIM0_PTR[2])(void) = {null} ;

void TIM0_voidInit(u8 copy_u8mode)
{
	switch(copy_u8mode)
	{
		case OV_MODE: /*Select mode : normal mode*/
		
						CLR_BIT(TCCR0_REG, 3);
						CLR_BIT(TCCR0_REG, 6);
						
						/*set prescaler*/
						
						TCCR0_REG &= 0b11111000 ;
						TCCR0_REG |= TIM0_prescaler;
						
						/*Enable overflow interrupt : PIE*/
						
						SET_BIT(TIMSK_REG,0); break ;
						
		case CTC_MODE: /*Select mode : CTC mode*/
		
						SET_BIT(TCCR0_REG, 3);
						CLR_BIT(TCCR0_REG, 6);
						
						/*set prescaler*/
						
						TCCR0_REG &= 0b11111000 ;
						TCCR0_REG |= TIM0_prescaler;
						
						/*Enable CTC interrupt*/
						SET_BIT(TIMSK_REG, 1);
						
						/*set OCR0 val*/
						OCR0_REG = OCR0_VAL; break ;
	}
	
}


void TIM0_voidSetCallBack(void (*ptr)(void), u8 copy_u8mode)
{
	switch(copy_u8mode)
	{
		case OV_MODE: TIM0_PTR[0] = ptr; break;
		case CTC_MODE: TIM0_PTR[1] = ptr; break;
	}
}


ISR(TIMER0_CTC)
{
	TIM0_PTR[1]();
}



/*void __vector_11(void)__attribute__((signal));
void __vector_11(void)
{
	TIM0_PTR[0]() ;
}


void __vector_10(void)__attribute__((signal));
void __vector_10(void)
{
	TIM0_PTR[1]() ;
}*/