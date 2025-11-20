/*
 * LCD_prog.c
 *
 * Created: 10/13/2025 6:48:59 PM
 *  Author: DELL
 */ 

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../MCAL/DIO/DIO_reg.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"

#define F_CPU 16000000UL
#include <util/delay.h>


static void LCD_voidSHD(u8 copy_u8data)
{
	u8 lcd_pins[4] = {LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN};
		
		u8 loc_in = 0;
		
		for (loc_in = 0; loc_in < 4; loc_in++)
		{
			DIO_voidSetPinVal(LCD_DPORT,lcd_pins[loc_in], GET_BIT(copy_u8data,loc_in));
		}
}

static void LCD_voidSendEnablePulse()
{
	DIO_voidSetPinVal(LCD_CPORT, LCD_E_PIN, HIGH);
	_delay_ms(2);
	DIO_voidSetPinVal(LCD_CPORT, LCD_E_PIN, LOW);
}

void LCD_voidInit(void)
{
	_delay_ms(40);
	/*send command (function set)*/
	#if LCD_MODE == LCD_8_BIT
	LCD_voidSendCommand(0x38);
	_delay_us(45);
	
	#elif LCD_MODE == LCD_4_BIT
	LCD_voidSHD(0b0010);
	LCD_voidSendEnablePulse();
	LCD_voidSHD(0b0010);
	LCD_voidSendEnablePulse();
	LCD_voidSHD(0b1000);
	LCD_voidSendEnablePulse();
	#endif
	
	/*send Display on / off*/
	LCD_voidSendCommand(0x0C);
	
	/*LCD CLR*/
	LCD_voidSendCommand(1);
	
	
}

void LCD_voidSendCommand(u8 copy_u8command)
{

	/*set RS ---> 0 for command*/
	DIO_voidSetPinVal(LCD_CPORT, LCD_RS_PIN, LOW);
	
	/*SET RW*/
	DIO_voidSetPinVal(LCD_CPORT, LCD_RW_PIN, LOW);
	
	/*send command*/
	#if LCD_MODE == LCD_8_BIT
	DIO_voidSetPortVal(LCD_DPORT,copy_u8command);
	LCD_voidSendEnablePulse();
	#elif LCD_MODE == LCD_4_BIT
	LCD_voidSHD(copy_u8command >> 4);
	LCD_voidSendEnablePulse();
	LCD_voidSHD(copy_u8command);
	LCD_voidSendEnablePulse();
	
	#endif
	
	
	//DIO_voidSetPinVal(LCD_CPORT, LCD_E_PIN, HIGH);
	//_delay_ms(2);
	//DIO_voidSetPinVal(LCD_CPORT, LCD_E_PIN, LOW);	
}

void LCD_voidSendData(u8 copy_u8data)
{
	/*set RS ---> 1 for data*/
	DIO_voidSetPinVal(LCD_CPORT, LCD_RS_PIN, HIGH);
	
	/*SET RW*/
	DIO_voidSetPinVal(LCD_CPORT, LCD_RW_PIN, LOW);
	
	/*send data*/
	#if LCD_MODE == LCD_8_BIT
	DIO_voidSetPortVal(LCD_DPORT,copy_u8data);
	LCD_voidSendEnablePulse();
	#elif LCD_MODE == LCD_4_BIT
	LCD_voidSHD(copy_u8data >> 4);
	LCD_voidSendEnablePulse();
	LCD_voidSHD(copy_u8data);
	LCD_voidSendEnablePulse();
	#endif
	
		//DIO_voidSetPinVal(LCD_CPORT, LCD_E_PIN, HIGH);
		//_delay_ms(2);
		//DIO_voidSetPinVal(LCD_CPORT, LCD_E_PIN, LOW);
	
}

void LCD_voidstring(char* S)
{
	u8 i = 0;
	while (S[i] != '\0')
	{
		LCD_voidSendData(S[i]);
		
		i++;
	}
	
}

void LCD_voidSendNumber(u32 Number)
{
	u8 count = 0;
	u32 copy_Number = Number;
	while (copy_Number != 0)
	{
		copy_Number /= 10;
		count++ ;
		
	}
	u32 arr[count];
	
	for (u8 i = 0; i < count; i++)
	{
		copy_Number = Number % 10;
		arr[i] = copy_Number;
		Number /= 10;
	}
	if (count != 0)
	{
		for (u8 i = 0; i < count; i++)
		{
			LCD_voidSendData('0' + arr[count - i - 1]);
		}
		
	}
	else
	{
		LCD_voidSendData('0');
	}
	
}


void LCD_voidGotoXY(u8 copy_u8x, u8 copy_u8y)
{
	u8 DDRAM_address = 0;
	DDRAM_address = copy_u8x + 0x40 * copy_u8y;
	
	SET_BIT(DDRAM_address,7);
	
	LCD_voidSendCommand(DDRAM_address);
}

void LCD_voidDrawData(u8 pattern, u8 *Data, u8 copy_u8x, u8 copy_u8y)
{
	u8 CGRAM_address = 0;
	CGRAM_address = pattern * 8;
	
	CLR_BIT(CGRAM_address, 7);
	SET_BIT(CGRAM_address, 6); 
	
	LCD_voidSendCommand(CGRAM_address);
	
	for(u8 i = 0; i < 8; i++)
	{
		LCD_voidSendData(Data[i]);
	}
	
	LCD_voidGotoXY( copy_u8x, copy_u8y);
	
	LCD_voidSendData(pattern);
	
}