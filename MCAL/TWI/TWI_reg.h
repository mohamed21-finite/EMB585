/*
 * TWI_prog.c
 *
 * Created: 1/1/2026 6:16:19 PM
 *  Author: fathi
 */ 


#ifndef TWI_REG_H_
#define TWI_REG_H_



#define TWBR_REG     *((volatile  u8*)0x20)
#define TWSR_REG     *((volatile  u8*)0x21)
#define TWCR_REG     *((volatile  u8*)0x56)
#define TWAR_REG     *((volatile  u8*)0x22)
#define TWDR_REG     *((volatile  u8*)0x23)


#endif /* TWI_REG_H_ */