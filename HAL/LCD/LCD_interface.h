/*
 * LCD_interface.h
 *
 * Created: 10/13/2025 6:48:15 PM
 *  Author: DELL
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define LCD_4_BIT   0
#define LCD_8_BIT   1
#define LCD_MODE   LCD_4_BIT


void LCD_voidInit(void);

void LCD_voidSendCommand(u8 copy_u8command);

void LCD_voidSendData(u8 copy_u8data);

void LCD_voidstring(char* S);

void LCD_voidSendNumber(u32 Number);

void LCD_voidGotoXY(u8 copy_u8x, u8 copy_u8y);

void LCD_voidDrawData(u8 pattern, u8 *Data, u8 copy_u8x, u8 copy_u8y);

#endif /* LCD_INTERFACE_H_ */