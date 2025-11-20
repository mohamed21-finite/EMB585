/*
 * ADC_prog.c
 *
 * Created: 11/17/2025 6:38:21 PM
 *  Author: DELL
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "ADC_interface.h"
#include "ADC_reg.h"

void (* ADC_PTR)(void) = null ;

void ADC_voidInit()
{
	SET_BIT(ADCMUX_REG,6);
	CLR_BIT(ADCMUX_REG,7);
	
	ADCSAR_REG &= 0b11111000;
	ADCSAR_REG |= ADC_prescaler;
	
	/*ADC Enable*/
	SET_BIT(ADCSAR_REG,7);
}

/*polling*/
u16 ADC_u16ReadChannel(u8 channel)
{
	ADCMUX_REG &= 0b11100000;
	ADCMUX_REG |= channel;
	
	/*Start Conversion*/
	SET_BIT(ADCSAR_REG,6);
	
	while(GET_BIT(ADCSAR_REG,4) == 0);
	
	
	return ADC_REG ;
}


/*Interrupt mode*/
void ADC_voidReadChannel_Interrupt(u8 channel)
{
	ADCMUX_REG &= 0b11100000;
	ADCMUX_REG |= channel;
	
	/*Start Conversion*/
	SET_BIT(ADCSAR_REG,6);
	
	/*Auto Trigger*/
	SET_BIT(ADCSAR_REG,5);
	
}



/*Interrupt Initialization*/
void ADC_voidInit_Interrupt()
{
	SET_BIT(ADCMUX_REG,6);
	CLR_BIT(ADCMUX_REG,7);
	
	ADCSAR_REG &= 0b11111000;
	ADCSAR_REG |= ADC_prescaler;
	
	/*Interrupt Enable*/
	SET_BIT(ADCSAR_REG,3);
	
	/*ADC Enable*/
	SET_BIT(ADCSAR_REG,7);
}


void ADC_CallBack(void (*ptr)(void))
{
	ADC_PTR = ptr ;
}

void __vector_16(void)__attribute__((signal));
void __vector_16(void)
{
	
	ADC_PTR() ;
	
}