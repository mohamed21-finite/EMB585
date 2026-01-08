
/*
 * main.h
 *
 * Created: 10/6/2025 6:02:33 PM
 *  Author: DELL
 */ 
#ifndef MAIN_H_
#define MAIN_H_

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPE.h"
#include "../LIB/Interrupt_vector.h"


#include "../HAL/SSD/SSD_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/DIO/DIO_interface.h"

#include "../MCAL/GI/GI_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/ADC/ADC_reg.h"
#include "../MCAL/TIM0/TIM0_interface.h"
#include "../MCAL/TIM1/TIM1_interface.h"
#include "../MCAL/WDT/WDT_interface.h"
#include "../MCAL/UART/UART_interface.h"
#include "../MCAL/SPI/SPI_interface.h"
#include "../MCAL/TWI/TWI_interface.h"

#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/LCD/LCD_config.h"

#include "../HAL/KPD/KPD_interface.h"
#include "../HAL/KPD/KPD_config.h"

#include "../HAL/DCMOTOR/DCMOTOR_interface.h"
#include "../HAL/DCMOTOR/DCMOTOR_config.h"

#include "../HAL/EEPROM/EEPROM_interface.h"
#define F_CPU 16000000UL
#include <util/delay.h>


#endif