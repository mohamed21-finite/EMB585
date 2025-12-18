/*
 * UART_reg.h
 *
 * Created: 12/15/2025 8:59:52 PM
 *  Author: DELL
 */ 


#ifndef UART_REG_H_
#define UART_REG_H_

#define UDR_REG		 *((volatile u8*)0x2C)
#define UCSRC_REG	 *((volatile u8*)0x40)
#define UCSRA_REG	 *((volatile u8*)0x2B)
#define UCSRB_REG	 *((volatile u8*)0x2A)



#endif /* UART_REG_H_ */