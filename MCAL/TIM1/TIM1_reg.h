/*
 * TIM1_reg.h
 *
 * Created: 12/8/2025 6:20:51 PM
 *  Author: DELL
 */ 


#ifndef TIM1_REG_H_
#define TIM1_REG_H_


#define TCCR1A_REG    (*(volatile u8*)0x4F)
#define TCCR1B_REG    (*(volatile u8*)0x4E)
#define TCNT1L_REG    (*(volatile u16*)0x4C) 
#define OCR1AL_REG    (*(volatile u16*)0x4A) // OCR1AH_REG + OCR1AL_REG
#define OCR1BL_REG    (*(volatile u16*)0x48) // OCR1BH_REG + OCR1BL_REG
#define ICR1L_REG     (*(volatile u16*)0x46) // ICRH_REG + ICRL_REG
#define TIMSK_REG     (*(volatile u8*)0x59)
#define TIFR_REG     (*(volatile u8*)0x58)




#endif /* TIM1_REG_H_ */