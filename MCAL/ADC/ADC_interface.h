/*
 * ADC_interface.h
 *
 * Created: 11/17/2025 6:37:33 PM
 *  Author: DELL
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADC    ADC_REG

#define ADC0   0
#define ADC1   1
#define ADC2   2
#define ADC3   3
#define ADC4   4
#define ADC5   5
#define ADC6   6
#define ADC7   7

#define prescaler_2    1
#define prescaler_4    2
#define prescaler_8    3
#define prescaler_16   4
#define prescaler_32   5
#define prescaler_64   6
#define prescaler_128  7

#define ADC_prescaler     prescaler_128

void ADC_voidInit();


u16 ADC_u16ReadChannel(u8 channel);

void ADC_voidReadChannel_Interrupt(u8 channel);
void ADC_voidInit_Interrupt();

void ADC_CallBack(void (*ptr)(void));

#endif /* ADC_INTERFACE_H_ */