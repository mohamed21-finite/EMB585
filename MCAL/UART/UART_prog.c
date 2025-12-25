/*
 * UART_prog.c
 *
 * Created: 12/15/2025 8:59:27 PM
 *  Author: DELL
 */ 

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/interrupt_vector.h"
#include "UART_interface.h"
#include "UART_reg.h"


void UART_voidInit(void)
{
	

	u8 temp = 0 ;
	/*9600 16MHZ*/
	UBRRL_REG = 103;
	
	SET_BIT(temp, 7);
	
	SET_BIT(temp, 1);
	SET_BIT(temp, 2);
	
	UCSRC_REG = temp ;
	

	
	
	/*Enable Tx Rx*/
	
	SET_BIT(UCSRB_REG,3);
	SET_BIT(UCSRB_REG,4);
	
}


void UART_voidTX(u8 copy_u8data)
{
	UDR_REG = copy_u8data ;
	
	while(GET_BIT(UCSRA_REG, 5) == 0);
}

u8 UART_u8RX(void)
{
	while(GET_BIT(UCSRA_REG, 7) == 0);
	
	return UDR_REG ;
}

void UART_voidSendString(char *ptr_string)
{
	u8 i = 0 ;
	while(ptr_string[i] != '\0')
	{
		UART_voidTX(ptr_string[i]);
		
		i++  ;
	}
}