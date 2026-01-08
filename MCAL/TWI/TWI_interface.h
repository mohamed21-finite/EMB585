/*
 * TWI_prog.c
 *
 * Created: 1/1/2026 6:16:19 PM
 *  Author: fathi
 */ 

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_


typedef enum {
	NOErr , 
	StartConditionErr , 
	RepeatedStartErr , 
	SlaveAddressWithWriteErr,
	SlaveAddressWithReadErr ,
	MasterSendDataErr,
	MasterReciveDataErr,
	SendStopConditionErr,
	StatusACKOrNotACKErr , 
	
	
	
	
	}TWI_Err_Status;



// SEND 0 for no address 
void TWI_voidMasterInit(u8 copy_u8address) ; 

/*master function */

TWI_Err_Status TWI_TWI_Err_StatusSendStartCondition(void) ; 

TWI_Err_Status TWI_TWI_Err_StatusSendRepeatedStart(void) ;

TWI_Err_Status TWI_TWI_Err_StatusSlaveAddressWithWrite(u8 copy_u8address) ; 
TWI_Err_Status TWI_TWI_Err_StatusSlaveAddressWithRead(u8 copy_u8address) ;

TWI_Err_Status TWI_TWI_Err_StatusMasterSendData(u8 copy_u8data) ; 
TWI_Err_Status TWI_TWI_Err_StatusMasterReciveData(u8 *copy_u8data) ;


void TWI_voidSendStopCondition(void) ; 


/*slave function */

void TWI_voidSlaveInit(u8 copy_u8address)  ;

TWI_Err_Status  TWI_TWI_Err_StatusACKOrNotACK(void) ; 


u8 TWI_u8SlaveReciveData() ; 





















#endif /* TWI_INTERFACE_H_ */