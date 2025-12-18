/*
 * TIM1_interface.h
 *
 * Created: 12/8/2025 6:21:11 PM
 *  Author: DELL
 */ 


#ifndef TIM1_INTERFACE_H_
#define TIM1_INTERFACE_H_

#define TIM1_prescaler_0    1
#define TIM1_prescaler_8    2
#define TIM1_prescaler_64    3
#define TIM1_prescaler_256   4
#define TIM1_prescaler_1024   5


#define TIM1_prescaler     TIM1_prescaler_64

#define TIM1_FALLING_EDGE   0
#define TIM1_RISING_EDGE    1

void TIM1_voidInit_Input_Capture(void);
void TIM1_voidSelectEdge(u8 Edge_select);
u16 TIM1_u16ReadICR(void);
void TIM1_voidICRReset(void);
void TIM1_voidCallBack(void (*ptr)(void));

void TIM1_voidFastPWMICR(void);


void TIM1_voidSetOCRVal(u16 copy_u16val);

void TIM1_voidReset(void);
u16 TIM1_u16ReadVal(void);
void TIM1_voidInit(void);

#endif /* TIM1_INTERFACE_H_ */