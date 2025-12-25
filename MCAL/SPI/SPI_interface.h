/*
 * SPI_interface.h
 *
 * Created: 12/22/2025 7:12:08 PM
 *  Author: DELL
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#define SCK_4     0
#define SCK_16     1
#define SCK_64     2
#define SCK_128     3

#define SCK_FREQ    SCK_128  



void SPI_voidMasterInit(void);

void SPI_voidSlaveInit(void);

void SPI_voidMasterSendData(u8 data);

u8 SPI_u8SalveRecieveData(void);



#endif /* SPI_INTERFACE_H_ */