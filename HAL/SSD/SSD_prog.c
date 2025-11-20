/*
 * SSD_prog.c
 *
 * Created: 10/8/2025 7:27:04 PM
 *  Author: DELL
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../MCAL/DIO/DIO_reg.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "SSD_config.h"

u8 ssd[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

void SSD_voidDisplayNum(u8 Num)
{ 
	DIO_voidSetPinDir(DIO_PORTB, DIO_PIN1 , OUTPUT);
	DIO_voidSetPinVal(DIO_PORTB, DIO_PIN1 , HIGH);
	DIO_voidSetPortDir( SSD_port ,  0x7F);
	DIO_voidSetPortVal(SSD_port , ssd[Num]);
	
}