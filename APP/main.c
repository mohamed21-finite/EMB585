/*
 * EM_585.c
 *
 * Created: 10/6/2025 6:00:15 PM
 * Author : DELL
 */ 

#include "main.h"

/*
volatile u16 T_on = 0;
volatile u16 T_total = 0 ;

void app()
{
	static u8 count = 0;
	count++ ;
	if (count == 1)
	{
		TIM1_voidReset();
		TIM1_voidSelectEdge(TIM1_FALLING_EDGE);
	}
	else if (count == 2)
	{
		T_on = TIM1_u16ReadICR();
		TIM1_voidSelectEdge(TIM1_RISING_EDGE);
		
	}
	else if (count == 3)
	{
		T_total = TIM1_u16ReadICR();
		count = 0 ;
	}
}*/
/*volatile u16 T_on = 0 ;
volatile u16 T_total = 0; 

void app()
{
	static u8 count = 0;
	count++ ;
	if (count == 1)
	{
		TIM1_voidReset();
		
		EXTI_voidInit(INT_0, FALLING_EDGE);
	}
	else if (count == 2)
	{
		T_on = TIM1_u16ReadVal();
		
		EXTI_voidInit(INT_0, RISING_EDGE);
	}
	else if (count == 3)
	{
		T_total = TIM1_u16ReadVal();
		
		count = 0 ;
	}
}*/
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

/*#define NUM_CHANNELS   3
u8 password[4] = {1, 2, 3, 4} ;
u8 button = 0 ;
Bool passing = F ;
volatile u8 current_channel = 0;
volatile u16 sensor_values[NUM_CHANNELS] = {0} ;

u8 ADC_channels[NUM_CHANNELS] = {ADC0, ADC1, ADC2} ; 
	
// This function is to get the button from the keypad
u8 get_button()
{
	u8 button = 50 ;
	
	while(1) 
	{
	button = KPD_u8_GetKey();
	
	if(button != 50)
	{
		break ;
	}
	}
	
	
	
	return button ;
}

// This function is to compare the user input to the password return true or false
Bool password_validation(u8 *ptr)
{
	for(u8 i = 0; i < 4; i++)
	{
		if(ptr[i] == password[i])
		{
			continue ;
		}
		else
		{
			return F ;
		}
	}
	
	return T ;
}

// using interrupt to get the ADC value
void ADC_value()
{
	

		sensor_values[current_channel] = ADC ;
		
		current_channel++ ;
		current_channel %= NUM_CHANNELS;
		 
		
		ADC_voidReadChannel_Interrupt(ADC_channels[current_channel]);
	

	
}

//this is a prototype for the function responsible for get access to the software the body of the function after the main
void pass_word() ;
*/

/*u16 Time = 0 ;
u16 Time1 = 0 ;

void alarm_display(u16 Time_seconds) ; 
void TIM0_app()
{
	static u32 count = 0 ;
 
	
	if(count == 0)
	{
     		alarm_display(Time1) ;
	}
		count++ ;
	
	if(count % 1000 == 0)
	{
		Time1-- ;
		alarm_display(Time1) ;
	}
	if(count == (Time * 1000))
	{
		while(1)
		{
		LED_voidon(DIO_PORTB,DIO_PIN0);
		}

	}
}
*/

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

	/*DIO_voidSetPinDir(DIO_PORTD, DIO_PIN5 , INPUT);
	DIO_voidSetPinDir(DIO_PORTD, DIO_PIN6 , INPUT);
	DIO_voidSetPinDir(DIO_PORTD, DIO_PIN7 , INPUT);
	
	DIO_voidSetPinVal(DIO_PORTD, DIO_PIN5 , HIGH);
	DIO_voidSetPinVal(DIO_PORTD, DIO_PIN6 , HIGH);
	DIO_voidSetPinVal(DIO_PORTD, DIO_PIN7 , HIGH);*/
	
	/*KPD_voidInit();
	
	//DIO_voidSetPortDir(DIO_PORTC,0x07);
	DIO_voidSetPortDir(DIO_PORTA,0xF0);
	DIO_voidSetPortDir(DIO_PORTB,0x0A);
	LCD_voidInit();
	
	ADC_voidInit_Interrupt() ;
	GI_voidEnable();
	
	ADC_voidReadChannel_Interrupt(ADC_channels[current_channel]);
	ADC_CallBack(ADC_value);
	
	DIO_voidSetPinDir(DIO_PORTB, DIO_PIN7, OUTPUT);
	DIO_voidSetPinDir(DIO_PORTB, DIO_PIN6, OUTPUT);
	DIO_voidSetPinDir(DIO_PORTB, DIO_PIN5, OUTPUT);
	
	f32 temperature = 0 ;
	f32 light_intensity = 0;
	f32 pir_value = 0; 
	//LCD_voidSendNumber(1);
	
	pass_word();*/
	/*
	DIO_voidSetPinDir(DIO_PORTD, DIO_PIN2, INPUT);
	DIO_voidSetPinDir(DIO_PORTD, DIO_PIN3, INPUT);
	DIO_voidSetPinDir(DIO_PORTD, DIO_PIN7, INPUT);
	
	DIO_voidSetPinVal(DIO_PORTD, DIO_PIN2, HIGH);
	DIO_voidSetPinVal(DIO_PORTD, DIO_PIN3, HIGH);
	DIO_voidSetPinVal(DIO_PORTD, DIO_PIN7, HIGH);
	
	DIO_voidSetPortDir(DIO_PORTA,0xF0);
	DIO_voidSetPortDir(DIO_PORTB,0x06);
	LCD_voidInit();
	

	
	alarm_display(Time1);
	
	while(DIO_u8ReadPinVal(DIO_PORTD, DIO_PIN7) == 1 || Time == 0)
	{
			if(DIO_u8ReadPinVal(DIO_PORTD, DIO_PIN2) == 0)
			{
				while(DIO_u8ReadPinVal(DIO_PORTD, DIO_PIN2) == 0) ;
				
				Time += 30 ;
				Time1 += 30 ;
				
				alarm_display(Time1);
			}
			else if(DIO_u8ReadPinVal(DIO_PORTD, DIO_PIN3) == 0)
			{
				while(DIO_u8ReadPinVal(DIO_PORTD, DIO_PIN3) == 0);
				
				if(Time >= 30)
				{
					Time -= 30 ;
					Time1 -= 30 ;
			
				}
				alarm_display(Time1);
			}
	}
	
		GI_voidEnable();
		TIM0_voidInit(CTC_MODE);
		TIM0_voidSetCallBack(TIM0_app, CTC_MODE);
*/

    /* Replace with your application code */
	//if(passing == T)
	//{
	//LCD_voidSendCommand(1);
	//u8 wait = 60 ;
	//DIO_voidSetPortDir(DIO_PORTA,0xF0);
	//DIO_voidSetPortDir(DIO_PORTB,0x0A);
	//LCD_voidInit();
	/*
	DIO_voidSetPinDir(DIO_PORTA, DIO_PIN0, INPUT);
	DIO_voidSetPinDir(DIO_PORTD, DIO_PIN5, OUTPUT);
	ADC_voidInit() ;
	TIM1_voidFastPWMICR() ;

	//GI_voidEnable();
	

	u16 val = 0;
	u16 analog = ADC_u16ReadChannel(ADC0);*/
	
	/*DIO_voidSetPortDir(DIO_PORTA,0xF0);
	DIO_voidSetPortDir(DIO_PORTB,0x0F);
	LCD_voidInit();
	DIO_voidSetPinDir(DIO_PORTD,DIO_PIN2,INPUT);
	EXTI_voidInit(INT_0,RISING_EDGE);
	
	GI_voidEnable();
	EXTI0_voidEnable();
	EXTI_CallBack(app,INT_0);
	TIM1_voidInit();
	u8 duty = 0 ;
	u8 f = 0 ;*/
	/*
	DIO_voidSetPortDir(DIO_PORTA,0xF0);
	DIO_voidSetPortDir(DIO_PORTB,0x0F);
	LCD_voidInit();
	DIO_voidSetPinDir(DIO_PORTD,DIO_PIN6,INPUT);
	
	TIM1_voidInit_Input_Capture();
	TIM1_voidSelectEdge(TIM1_RISING_EDGE);
	GI_voidEnable();
	TIM1_voidICRReset();
	TIM1_voidCallBack(app);
	
	u8 duty = 0 ;
	u8 f = 0 ;*/
	
	/*LED_voidon(DIO_PORTA, DIO_PIN0);
	_delay_ms(1000);
	LED_voidoff(DIO_PORTA, DIO_PIN0);
	_delay_ms(1000);
	GI_voidEnable();
	WDT_voidEnableInit();*/
	UART_voidInit();
	SPI_voidMasterInit();
	u8 i = 0 ;
    while (1) 
    {
		i = UART_u8RX() % 48;
		_delay_ms(50);
		SPI_voidMasterSendData(i);

		

		/*LED_voidon(DIO_PORTA, DIO_PIN1);
		//_delay_ms(1000);
		wdt_reset();
		//WDT_voidDisable();*/
		
		
		/*duty = ((f32)T_on / T_total) * 100 ;
		
		f = 1000000 / (4 * T_total) ;
		//T_on = (f32)(T_on / 4000000);
		//T_total =(f32)(T_total / 4000000);
		TIM0_voidPWM(FAST_PWM, 50);
		LCD_voidGotoXY(0,0);
		LCD_voidSendNumber(duty);
		LCD_voidGotoXY(0,1);
		LCD_voidSendNumber(f);*/
		
		/*analog = ADC_u16ReadChannel(ADC0);
		val = (2000 + (f32) analog  * 400 * 5 / 1023);
		
			TIM1_voidSetOCRVal(val);
			_delay_ms(500);*/
			
			
		
		//DCMotor_voidStop();
		//_delay_ms(5000);
		
		/*alarm_display(wait);
		wait--;
		_delay_ms(1000);
		
		if(wait == 0)
		{	
			alarm_display(wait);
			while(1){
			LED_voidon(DIO_PORTB,DIO_PIN0);
			}
		}*/
		/*temperature = (f32) sensor_values[1] * 500 / 1023 ;
		light_intensity = (f32) sensor_values[2] * 5 / 1023 ;
		pir_value = (f32) sensor_values[0] * 5 / 1023 ;
		
		LCD_voidGotoXY(0,0);
		LCD_voidSendNumber(temperature);
		LCD_voidstring("C");
		
		if(light_intensity >= 2.5)
		{
			DIO_voidSetPinVal(DIO_PORTB, DIO_PIN7, HIGH);
			
		}
		else if(light_intensity < 2.5)
		{
			DIO_voidSetPinVal(DIO_PORTB, DIO_PIN7, LOW);
		}
		
		if(temperature > 35)
		{
			LED_voidon(DIO_PORTB,DIO_PIN6);
		}
		else
		{
			LED_voidoff(DIO_PORTB,DIO_PIN6);
		}
		
		if(pir_value >= 2.5)
		{
			
			DIO_voidSetPinVal(DIO_PORTB, DIO_PIN5, HIGH);
		}
		else if(pir_value < 2.5)
		{

			DIO_voidSetPinVal(DIO_PORTB, DIO_PIN5, LOW);
		}
	}*/
	}
  }

/*void __vector_11(void)__attribute__((signal));
void __vector_11(void)
{
	static u16 count = 0 ;
	count++ ;
	
	if(count == 490)
	{
		LED_voidToggle(DIO_PORTA,DIO_PIN0);
		count = 0;
	}
}*/

/*void pass_word()
{
	u8 entering_password[4] = {0, 0, 0, 0};
	
	for(u8 j = 0 ; j < 3; j++)
	{
		LCD_voidSendCommand(1);
		LCD_voidstring("PASSWORD: ");
		for(u8 i = 0 ; i < 4; i++)
		{
			button = get_button();
			entering_password[i] = button;
			LCD_voidSendNumber(button);
		}
		
		if(password_validation(entering_password) == T)
		{
			passing = T ;
			LCD_voidSendCommand(1);
			LCD_voidGotoXY(4,0);
			LCD_voidstring("WELCOME");
			_delay_ms(2000);
			break;
		}
		else
		{
			if(j < 2)
			{
				LCD_voidSendCommand(1);
				LCD_voidGotoXY(0,0);
				LCD_voidstring("WRONG TRY AGAIN");
				LCD_voidGotoXY(0,1);
				LCD_voidstring("PRESS 1");
				button = get_button();
				while(button != 1);
			}
			else
			{
				passing = F ;
				LCD_voidSendCommand(1);
				LCD_voidGotoXY(6,0);
				LCD_voidstring("CLOSE");
				_delay_ms(2000);
				
			}
		}
	}
}*/


