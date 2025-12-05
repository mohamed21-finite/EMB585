/*
 * DCMOTOR_interface.h
 *
 * Created: 12/3/2025 6:31:32 PM
 *  Author: DELL
 */ 


#ifndef DCMOTOR_INTERFACE_H_
#define DCMOTOR_INTERFACE_H_

void DCMotor_voidInit(void);

void DCMotor_voidForward(u8 speed);

void DCMotor_voidReverse(u8 speed);

void DCMotor_voidRight(u8 speed);

void DCMotor_voidLeft(u8 speed);

void DCMotor_voidStop(void);



#endif /* DCMOTOR_INTERFACE_H_ */