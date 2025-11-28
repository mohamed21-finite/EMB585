/*
 * Interrupt_vector.h
 *
 * Created: 11/26/2025 7:27:36 PM
 *  Author: DELL
 */ 


#ifndef INTERRUPT_VECTOR_H_
#define INTERRUPT_VECTOR_H_

#define ISR(__vector_NUM)   void __vector_NUM(void)__attribute__((signal)); \
							void __vector_NUM(void)
							

#define EXT_INT0		__vector_1
#define EXT_INT1		__vector_2
#define EXT_INT2		__vector_3

#define TIMER2_CTC		__vector_4
#define TIMER2_OVF		__vector_5

#define TIMER1_CE		__vector_6
#define TIMER1_CTCA		__vector_7
#define TIMER1_CTCB		__vector_8
#define TIMER1_OVF		__vector_9


#define TIMER0_CTC		__vector_10
#define TIMER0_OVF		__vector_11

#define SPI_STC			__vector_12

#define USART_RXC		__vector_13
#define USART_UDRE		__vector_14
#define USART_TXC		__vector_15

#define ADC_COMP		__vector_16

#define EE_RDY			__vector_17

#define ANA_COMP		__vector_18
#define TWI				__vector_19
#define SPM_RDY			__vector_20



#endif /* INTERRUPT_VECTOR_H_ */