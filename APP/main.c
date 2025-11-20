/*
 * EM_585.c
 *
 * Created: 10/6/2025 6:00:15 PM
 * Author : DELL
 */ 

#include "main.h"

/*u8 count = 0;
void app0()
{
	
	count++ ;
	//LCD_voidSendCommand(1);
	//LCD_voidSendNumber(count);
}

void app1()
{
	if(count != 0)
	{
		count-- ;
		//LCD_voidSendCommand(1);
		//LCD_voidSendNumber(count);	
	}
}

void app2()
{
	count = 0 ;
	//LCD_voidSendCommand(1);
	//LCD_voidSendNumber(count);
}*/

u16 value = 0 ;
u8 conversion_complete = 0;
void ADC_value()
{
	value = ADC ;
	conversion_complete = 1;
}

int main(void)
{
	
	/*DIO_voidSetPortDir(DIO_PORTA,0x03);
	DIO_voidSetPinDir(DIO_PORTD,DIO_PIN2,INPUT);
	EXTI_voidInit(INT_0,FALLING_EDGE);
	DIO_voidSetPinDir(DIO_PORTD,DIO_PIN3,INPUT);
	EXTI_voidInit(INT_1,FALLING_EDGE);
	DIO_voidSetPinDir(DIO_PORTB,DIO_PIN3,INPUT);
	EXTI_voidInit(INT_2,FALLING_EDGE);
	
	GI_voidEnable();
	EXTI0_voidEnable();
	EXTI1_voidEnable();
	EXTI2_voidEnable();
	
	EXTI_CallBack(app0,INT_0);
	EXTI_CallBack(app1,INT_1);
	EXTI_CallBack(app2,INT_2);*/
	//DIO_voidSetPinDir(DIO_PORTD, DIO_PIN2 , INPUT);
	//DIO_voidSetPinDir(DIO_PORTD, DIO_PIN3 , INPUT);
	//DIO_voidSetPinDir(DIO_PORTD, DIO_PIN7 , INPUT);
	
	//DIO_voidSetPinVal(DIO_PORTD, DIO_PIN2 , HIGH);
	//DIO_voidSetPinVal(DIO_PORTD, DIO_PIN3 , HIGH);
	//DIO_voidSetPinVal(DIO_PORTD, DIO_PIN7 , HIGH);
	
	//KPD_voidInit();
	
	DIO_voidSetPortDir(DIO_PORTC,0x07);
	DIO_voidSetPortDir(DIO_PORTA,0xF0);
	DIO_voidSetPortDir(DIO_PORTB,0x0A);
	LCD_voidInit();
	
	ADC_voidInit_Interrupt() ;
	GI_voidEnable();
	
	ADC_voidReadChannel_Interrupt(ADC0);
	ADC_CallBack(ADC_value);
	

	f32 analog_value = 0 ;
	LCD_voidSendNumber(analog_value);
	
    /* Replace with your application code */
    while (1) 
    {
		analog_value = (f32) value * 5 / 1023 ;
		LCD_voidGotoXY(0,0);
		LCD_voidSendNumber(analog_value);
		
		if(conversion_complete == 1)
		{
		conversion_complete = 0 ;
		if(analog_value >= 2.5)
		{
			LED_voidon(DIO_PORTC, DIO_PIN0);
		}
		else if(analog_value < 2.5)
		{
			LED_voidoff(DIO_PORTC, DIO_PIN0);
			
		}
		}
		
		//ADC_voidReadChannel_Interrupt(ADC0);
		//LCD_voidSendCommand(1);

	}
		
}

/*void __vector_1(void)__attribute__((signal));
void __vector_1(void)
{
	LED_voidToggle(DIO_PORTA,DIO_PIN1);
}*/