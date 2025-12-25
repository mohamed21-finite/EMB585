/*
 * WDT_interface.h
 *
 * Created: 12/18/2025 10:52:55 PM
 *  Author: DELL
 */ 


#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_

#define WDT_prescaler_16k    0
#define WDT_prescaler_32k    1
#define WDT_prescaler_64k    2
#define WDT_prescaler_128k    3
#define WDT_prescaler_256k    4
#define WDT_prescaler_512k    5
#define WDT_prescaler_1024k    6
#define WDT_prescaler_2048k    7

#define WDT_prescaler        WDT_prescaler_2048k

#define wdt_reset() __asm__ __volatile__ ("wdr")

void WDT_voidEnableInit(void);

void WDT_voidDisable(void);


#endif /* WDT_INTERFACE_H_ */