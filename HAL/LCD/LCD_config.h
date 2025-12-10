/*
 * LCD_config.h
 *
 * Created: 10/13/2025 6:48:35 PM
 *  Author: DELL
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#if LCD_MODE == LCD_8_BIT

#define LCD_DPORT       DIO_PORTA

#elif LCD_MODE == LCD_4_BIT

#define LCD_DPORT    DIO_PORTA
#define LCD_D4_PIN   DIO_PIN4
#define LCD_D5_PIN   DIO_PIN5
#define LCD_D6_PIN   DIO_PIN6
#define LCD_D7_PIN   DIO_PIN7

#endif
/*lcd control pins*/
#define LCD_CPORT       DIO_PORTB
#define LCD_RS_PIN      DIO_PIN1
#define LCD_RW_PIN      DIO_PIN0
#define LCD_E_PIN       DIO_PIN3



#endif /* LCD_CONFIG_H_ */