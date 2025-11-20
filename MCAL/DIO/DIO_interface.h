/*
 * DIO_interface.h
 *
 * Created: 10/6/2025 6:27:37 PM
 *  Author: fathi
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_





/* dio dir */

#define  OUTPUT      1 
#define  INPUT       0

/*DIO VAL */

#define  HIGH        1 
#define  LOW         0
typedef enum {DIO_PORTA ,DIO_PORTB,DIO_PORTC ,DIO_PORTD}ports;

typedef enum {DIO_PIN0 ,DIO_PIN1,DIO_PIN2 ,DIO_PIN3,DIO_PIN4,DIO_PIN5,DIO_PIN6,DIO_PIN7}PINS;


/* pin function */
/*****************************************************************************
* Function Name: DIO_voidSetPinDir
* Purpose      : set pin dir (OUTPUT , INPUT)
* Parameters   : u8 Copy_u8_port,u8 Copy_u8_pin,u8 Copy_u8_dir
* Return value : void
*****************************************************************************/

void DIO_voidSetPinDir(u8 copy_u8port, u8 copy_u8pin , u8 copy_u8dir);
/*****************************************************************************
* Function Name: DIO_voidSetPinVal
* Purpose      : set pin val (HIGH , LOW )
* Parameters   : u8 Copy_u8_port,u8 Copy_u8_pin,u8 Copy_u8_val
* Return value : void
*****************************************************************************/

void DIO_voidSetPinVal(u8 copy_u8port, u8 copy_u8pin , u8 copy_u8val);


void DIO_voidTogglePinVal(u8 copy_u8port, u8 copy_u8pin) ; 


u8 DIO_u8ReadPinVal(u8 copy_u8port, u8 copy_u8pin) ; 


/*port function */

void DIO_voidSetPortDir(u8 copy_u8port , u8 copy_u8dir) ; 
void DIO_voidSetPortVal(u8 copy_u8port , u8 copy_u8val) ;










#endif /* DIO_INTERFACE_H_ */