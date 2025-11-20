/*
 * KPD_prog.c
 *
 * Created: 10/22/2025 7:06:41 PM
 *  Author: DELL
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../MCAL/DIO/DIO_reg.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "KPD_config.h"

void KPD_voidInit()
{
	/*SET the rows pin direction input*/
	DIO_voidSetPinDir(KPD_ROWS, KPD_R0 , INPUT);
	DIO_voidSetPinDir(KPD_ROWS, KPD_R1 , INPUT);
	DIO_voidSetPinDir(KPD_ROWS, KPD_R2 , INPUT);
	
	/*SET the columns pin direction output*/
	DIO_voidSetPinDir(KPD_CLMS, KPD_C0 , OUTPUT);
	DIO_voidSetPinDir(KPD_CLMS, KPD_C1 , OUTPUT);
	DIO_voidSetPinDir(KPD_CLMS, KPD_C2 , OUTPUT);
	
	/*activation of row pull up*/
	DIO_voidSetPinVal(KPD_ROWS, KPD_R0 , HIGH);
	DIO_voidSetPinVal(KPD_ROWS, KPD_R1 , HIGH);
	DIO_voidSetPinVal(KPD_ROWS, KPD_R2 , HIGH);
	
	/*initially columns deactivated*/
	DIO_voidSetPinVal(KPD_CLMS, KPD_C0 , HIGH);
	DIO_voidSetPinVal(KPD_CLMS, KPD_C1 , HIGH);
	DIO_voidSetPinVal(KPD_CLMS, KPD_C2 , HIGH);
}

u8 KPD_u8_GetKey()
{
	u8 button_pressed = 50;
	u8 buttons_elements[ROWS_SIZE][COLUMNS_SIZE] = {{1, 2, '+'},
													{3, 4, '-'}, 
													{'C', 0, '='}} ;
	u8 ROWS_arr[ROWS_SIZE] = {KPD_R0, KPD_R1, KPD_R2};
	u8 COLS_arr[COLUMNS_SIZE] = {KPD_C0, KPD_C1, KPD_C2};
		
		for(u8 i = 0; i < COLUMNS_SIZE;i++)
		{
			/*Activate column*/
			DIO_voidSetPinVal(KPD_CLMS, COLS_arr[i] , LOW);
			
			for(u8 j = 0; j < ROWS_SIZE; j++)
			{
				
				if(DIO_u8ReadPinVal(KPD_ROWS, ROWS_arr[j]) == 0)
				{
					button_pressed = buttons_elements[j][i];
					while(DIO_u8ReadPinVal(KPD_ROWS, ROWS_arr[j])==0);
					
					return button_pressed ;
					
				}
				
			}
			DIO_voidSetPinVal(KPD_CLMS, COLS_arr[i] , HIGH);
		}
		
		return button_pressed ;
		
	
	
}