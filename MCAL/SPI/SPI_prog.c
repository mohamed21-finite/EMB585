/*
 * SPI_prog.c
 *
 * Created: 12/22/2025 7:11:30 PM
 *  Author: DELL
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/interrupt_vector.h"
#include "../DIO/DIO_interface.h"
#include "SPI_interface.h"
#include "SPI_reg.h"


void SPI_voidMasterInit(void)
{
	
	DIO_voidSetPinDir(DIO_PORTB, DIO_PIN5,OUTPUT);
	DIO_voidSetPinDir(DIO_PORTB, DIO_PIN7,OUTPUT);
	DIO_voidSetPinDir(DIO_PORTB, DIO_PIN4,OUTPUT);
	DIO_voidSetPinVal(DIO_PORTB, DIO_PIN4,LOW);
	DIO_voidSetPinDir(DIO_PORTB, DIO_PIN3,OUTPUT);
	DIO_voidSetPinVal(DIO_PORTB, DIO_PIN3,LOW);
	
	
	/*LSB*/
	//SET_BIT(SPCR_REG, 5);
	
	/*Master Mode*/
	SET_BIT(SPCR_REG, 4);
	
	/*CPOL*/
	//CLR_BIT(SPCR_REG, 3);
	
	/*Clock Phase*/
	//SET_BIT(SPCR_REG, 2);
	
	SPCR_REG |= SCK_FREQ  ;
	/*Enable SPI*/
	SET_BIT(SPCR_REG, 6);
}

void SPI_voidSlaveInit(void)
{
	
	
	/*LSB*/
	//SET_BIT(SPCR_REG, 5);
	
	/*Slave Mode*/
	CLR_BIT(SPCR_REG, 4);
	
	/*Enable SPI*/
	SET_BIT(SPCR_REG, 6);
	
}

void SPI_voidMasterSendData(u8 data)
{
	SPDR_REG = data ;
	while(GET_BIT(SPSR_REG, 7) == 0);
}

u8 SPI_u8SalveRecieveData(void)
{
	while(GET_BIT(SPSR_REG, 7) == 0);
	return SPDR_REG ;
}