/*
 * TIM0_reg.h
 *
 * Created: 11/24/2025 6:39:52 PM
 *  Author: DELL
 */ 


#ifndef TIM0_REG_H_
#define TIM0_REG_H_


#define TCCR0_REG      (*(volatile u8*)0x53)
#define TIMSK_REG      (*(volatile u8*)0x59)
#define TIFR_REG       (*(volatile u8*)0x58)
#define OCR0_REG       (*(volatile u8*)0x5C)
#define TCNT0_REG      (*(volatile u8*)0x52)

#endif /* TIM0_REG_H_ */