/*
 * EXTI_prog.c
 *
 * Created: 10/29/2025 6:39:50 PM
 *  Author: DELL
 */ 

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "EXTI_reg.h"
#include "EXTI_interface.h"

void (*EXPTR[3])(void) = {null};


void EXTI_voidInit(u8 interruptNum,u8 sense)
{
	switch(interruptNum)
	{
		case INT_0: 
					if (sense == LOW_LEVEL)
					{
						CLR_BIT(MCUCR_REG,0);
						CLR_BIT(MCUCR_REG,1);		
					}
					else if(sense == LOGICAL)
					{
						SET_BIT(MCUCR_REG,0);
						CLR_BIT(MCUCR_REG,1);
					}
					else if(sense == FALLING_EDGE)
					{
						CLR_BIT(MCUCR_REG,0);
						SET_BIT(MCUCR_REG,1);
					}
					else if(sense == RISING_EDGE)
					{
						SET_BIT(MCUCR_REG,0);
						SET_BIT(MCUCR_REG,1);
					}
					else{}; break;
		case INT_1:
					if (sense == LOW_LEVEL)
					{
						CLR_BIT(MCUCR_REG,2);
						CLR_BIT(MCUCR_REG,3);
					}
					else if(sense == LOGICAL)
					{
						SET_BIT(MCUCR_REG,2);
						CLR_BIT(MCUCR_REG,3);
					}
					else if(sense == FALLING_EDGE)
					{
						CLR_BIT(MCUCR_REG,2);
						SET_BIT(MCUCR_REG,3);
					}
					else if(sense == RISING_EDGE)
					{
						SET_BIT(MCUCR_REG,2);
						SET_BIT(MCUCR_REG,3);
				}
					else{}; break;
		case INT_2:
					if (sense == RISING_EDGE)
					{
						SET_BIT(MCUCSR_REG,6);

					}
					else if(sense == FALLING_EDGE)
					{
						CLR_BIT(MCUCSR_REG,6);
					}
					else{}; break; 
	}
}

void EXTI0_voidEnable()
{
	SET_BIT(GICR_REG,6);
}
void EXTI0_voidDisable()
{
	CLR_BIT(GICR_REG,6);
}

void EXTI1_voidEnable()
{
	SET_BIT(GICR_REG,7);
}
void EXTI1_voidDisable()
{
	CLR_BIT(GICR_REG,7);
}

void EXTI2_voidEnable()
{
	SET_BIT(GICR_REG,5);
}
void EXTI2_voidDisable()
{
	CLR_BIT(GICR_REG,5);
}


void EXTI_CallBack(void(*ptr)(void),u8 INT_num)
{
	

	switch (INT_num)
	{
		case INT_0: EXPTR[0] = ptr;break;
		case INT_1: EXPTR[1] = ptr;break;
		case INT_2: EXPTR[2] = ptr;break;
	}
	
}

void __vector_1(void)__attribute__((signal));
void __vector_1(void)
{
	EXPTR[0]() ;
	
}

void __vector_2(void)__attribute__((signal));
void __vector_2(void)
{
	EXPTR[1]() ;
	
}

void __vector_3(void)__attribute__((signal));
void __vector_3(void)
{
	EXPTR[2]() ;
	
}