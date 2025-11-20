/*
 * EXTI_interface.h
 *
 * Created: 10/29/2025 6:38:08 PM
 *  Author: DELL
 */ 


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define LOW_LEVEL      0
#define LOGICAL        1
#define FALLING_EDGE   2
#define RISING_EDGE    3

#define INT_0     0
#define INT_1     1
#define INT_2     2







void EXTI_voidInit(u8 interruptNum,u8 sense);

void EXTI0_voidEnable();
void EXTI0_voidDisable();

void EXTI1_voidEnable();
void EXTI1_voidDisable();

void EXTI2_voidEnable();
void EXTI2_voidDisable();

void EXTI_CallBack(void(*ptr)(void),u8 INT_num);


#endif /* EXTI_INTERFACE_H_ */