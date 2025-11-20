/*
 * LED_prog.c
 *
 * Created: 10/8/2025 6:22:11 PM
 *  Author: DELL
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../MCAL/DIO/DIO_reg.h"
#include "../../MCAL/DIO/DIO_interface.h"

void LED_voidon(u8 copy_u8port, u8 copy_u8pin) 
{
	DIO_voidSetPinDir(copy_u8port, copy_u8pin , OUTPUT) ;
	DIO_voidSetPinVal(copy_u8port, copy_u8pin , HIGH) ;
	
}

void LED_voidoff(u8 copy_u8port, u8 copy_u8pin) 
{
	DIO_voidSetPinDir(copy_u8port, copy_u8pin , OUTPUT) ;
	DIO_voidSetPinVal(copy_u8port, copy_u8pin , LOW) ;
		
	
}

void LED_voidToggle(u8 copy_u8port, u8 copy_u8pin) 
{
	DIO_voidSetPinDir(copy_u8port, copy_u8pin , OUTPUT) ;
	DIO_voidTogglePinVal(copy_u8port, copy_u8pin) ;
	
}
