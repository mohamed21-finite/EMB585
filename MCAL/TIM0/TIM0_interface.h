/*
 * TIM0_interface.h
 *
 * Created: 11/24/2025 6:39:32 PM
 *  Author: DELL
 */ 


#ifndef TIM0_INTERFACE_H_
#define TIM0_INTERFACE_H_

#define TIM0_prescaler_0    1
#define TIM0_prescaler_8    2
#define TIM0_prescaler_64    3
#define TIM0_prescaler_256   4
#define TIM0_prescaler_1024   5


#define TIM0_prescaler     TIM0_prescaler_64

#define OV_MODE   0
#define CTC_MODE  1
#define PC_PWM    2
#define FAST_PWM  3

#define OCR0_VAL  250

void TIM0_voidInit(u8 copy_u8mode);
void TIM0_voidSetCallBack(void (*ptr)(void), u8 copy_u8mode);

void TIM0_voidPWM(u8 copy_u8mode, u8 copy_u8duty) ;

#endif /* TIM0_INTERFACE_H_ */