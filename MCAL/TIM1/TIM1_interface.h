/*
 * TIM1_interface.h
 *
 * Created: 12/8/2025 6:21:11 PM
 *  Author: DELL
 */ 


#ifndef TIM1_INTERFACE_H_
#define TIM1_INTERFACE_H_

#define TIM1_prescaler_1    1
#define TIM1_prescaler_8    2
#define TIM1_prescaler_64    3
#define TIM1_prescaler_256   4
#define TIM1_prescaler_1024   5


#define TIM1_prescaler     TIM1_prescaler_8


void TIM1_voidFastPWMICR(void);


void TIM1_voidSetOCRVal(u16 copy_u16val);



#endif /* TIM1_INTERFACE_H_ */