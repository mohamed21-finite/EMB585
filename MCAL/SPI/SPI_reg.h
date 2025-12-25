/*
 * SPI_reg.h
 *
 * Created: 12/22/2025 7:11:50 PM
 *  Author: DELL
 */ 


#ifndef SPI_REG_H_
#define SPI_REG_H_


#define SPCR_REG	*((volatile u8*)0x2D)

#define SPDR_REG	*((volatile u8*)0x2F)

#define SPSR_REG	*((volatile u8*)0x2E)


#endif /* SPI_REG_H_ */