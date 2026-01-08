/*
 * EEPROM_interface.h
 *
 * Created: 1/5/2026 6:33:16 PM
 *  Author: DELL
 */ 


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_voidSendData(u16 Address, u8 Data);

u8 EEPROM_u8ReadData(u16 Address) ;



#endif /* EEPROM_INTERFACE_H_ */