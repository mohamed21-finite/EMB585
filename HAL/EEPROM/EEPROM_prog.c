/*
 * EEPROM_prog.c
 *
 * Created: 1/5/2026 6:32:50 PM
 *  Author: DELL
 */ 

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/Interrupt_vector.h"
#include "../../MCAL/TWI/TWI_interface.h"
#include "EEPROM_interface.h"
#define  F_CPU 16000000UL
#include <util/delay.h>


void EEPROM_voidSendData(u16 address, u8 data)
{
	
	u8 LOC_u8DeviceAddress = 0b1010000 | address>>8 ;
	/*Send Start condition */
	TWI_TWI_Err_StatusSendStartCondition() ;
	/*SEND Device address */
	TWI_TWI_Err_StatusSlaveAddressWithWrite(LOC_u8DeviceAddress) ;
	/*send location address (8 bit) */
	TWI_TWI_Err_StatusMasterSendData((u8)address) ;
	
	/*send data */
	
	TWI_TWI_Err_StatusMasterSendData(data) ;
	
	TWI_voidSendStopCondition() ;
	
	_delay_ms(5) ;
}


u8 EEPROM_u8ReadData(u16 address) 
{
	u8 val=0 ;
	u8 LOC_u8DeviceAddress = 0b1010000 | address>>8 ;
	/*Send Start condition */
	TWI_TWI_Err_StatusSendStartCondition() ;
	/*SEND Device address */
	TWI_TWI_Err_StatusSlaveAddressWithWrite(LOC_u8DeviceAddress) ;
	/*send location address (8 bit) */
	TWI_TWI_Err_StatusMasterSendData((u8)address) ;
	
	/*SEND repeated start */
	
	TWI_TWI_Err_StatusSendRepeatedStart() ;
	
	TWI_TWI_Err_StatusSlaveAddressWithRead(LOC_u8DeviceAddress) ;
	
	/*read data */
	
	TWI_TWI_Err_StatusMasterReciveData(&val) ;
	
	
	TWI_voidSendStopCondition() ;
	
	
	return val ;
}