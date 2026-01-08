/*
 * TWI_prog.c
 *
 * Created: 1/1/2026 6:16:19 PM
 *  Author: fathi
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "TWI_interface.h"
#include "TWI_reg.h"
#include "TWI_private.h"







void TWI_voidMasterInit(u8 copy_u8address){
	
	
	/*Set scl = 400khz , with fs = 16MHZ , prscaler =0  
	
	 TWBR =12 
	
	*/
	
	
	TWBR_REG=12 ; 
	
	/*select prscaler */
	
	
	CLR_BIT(TWSR_REG,0) ;
	CLR_BIT(TWSR_REG,1) ;
	
	
	
	if (copy_u8address != 0)
	{
		TWAR_REG = copy_u8address<<1 ; 
		
	}
	else {
		
		 // do nothing 
	}
	
	
	/*Enable ACK */
	SET_BIT(TWCR_REG,6) ; 
	/*Enable TWI*/
	SET_BIT(TWCR_REG,2) ;
	
	
	
}

void TWI_voidSlaveInit(u8 copy_u8address)  {
	
	
	// set slave address 
   TWAR_REG = copy_u8address<<1 ;

	/*Enable ACK */
	SET_BIT(TWCR_REG,6) ;
	/*Enable TWI*/
	SET_BIT(TWCR_REG,2) ;
	
}

TWI_Err_Status TWI_TWI_Err_StatusSendStartCondition(void) {
	
	TWI_Err_Status Loc_Err = NOErr ; 
	
	/*set start condition bit */
	
	 SET_BIT(TWCR_REG,5) ; 
	 
	 /*CLR Flag to start the next operation */
	 
	 SET_BIT(TWCR_REG,7) ; 
	 
	 /*wait */
	 
	 while(GET_BIT(TWCR_REG,7)==0) ; 
	 
	  /*check the operation status */
	 
	    if ((TWSR_REG&0xf8) != START_ACK)
	    {
			
			Loc_Err = StartConditionErr ; 
	    }
	      else {
			  
			  // do nothing 
		  }
	 
	 
	
	
	return Loc_Err ; 
	
}

TWI_Err_Status TWI_TWI_Err_StatusSendRepeatedStart(void){
	
	TWI_Err_Status Loc_Err = NOErr ;
	
	/*set start condition bit */
	
	SET_BIT(TWCR_REG,5) ;
	
	/*CLR Flag to start the next operation */
	
	SET_BIT(TWCR_REG,7) ;
	
	/*wait */
	
	while(GET_BIT(TWCR_REG,7)==0) ;
	
	/*check the operation status */
	
	if ((TWSR_REG&0xf8) != REP_START)
	{
		
		Loc_Err = RepeatedStartErr ;
	}
	else {
		
		// do nothing
	}
	
	
	
	
	return Loc_Err ;
	
	
	
	
}

TWI_Err_Status TWI_TWI_Err_StatusSlaveAddressWithWrite(u8 copy_u8address){
		TWI_Err_Status Loc_Err = NOErr ;
		
		/*SEND the 7 bit slave address on the bus */
	    TWDR_REG = copy_u8address<<1 ; 
		
		CLR_BIT(TWDR_REG,0) ; 
		
		 CLR_BIT(TWCR_REG,5) ; 
	
		
		/*CLR Flag to start the next operation */
		
		SET_BIT(TWCR_REG,7) ;
		
		/*wait */
		
		while(GET_BIT(TWCR_REG,7)==0) ;
		
		/*check the operation status */
		
		if ((TWSR_REG&0xf8) != SLAVE_ADD_AND_WR_ACK)
		{
			
			Loc_Err = SlaveAddressWithWriteErr ;
		}
		else {
			
			// do nothing
		}
		
		
		
		
		return Loc_Err ;
	
	
	
}
TWI_Err_Status TWI_TWI_Err_StatusSlaveAddressWithRead(u8 copy_u8address){
	TWI_Err_Status Loc_Err = NOErr ;
	
	/*SEND the 7 bit slave address on the bus */
	TWDR_REG = copy_u8address<<1 ;
	
	 SET_BIT(TWDR_REG,0) ;
	
	CLR_BIT(TWCR_REG,5) ;
	
	
	/*CLR Flag to start the next operation */
	
	SET_BIT(TWCR_REG,7) ;
	
	/*wait */
	
	while(GET_BIT(TWCR_REG,7)==0) ;
	
	/*check the operation status */
	
	if ((TWSR_REG&0xf8) != SLAVE_ADD_AND_RR_ACK)
	{
		
		Loc_Err = SlaveAddressWithReadErr ;
	}
	else {
		
		// do nothing
	}
	
	
	
	
	return Loc_Err ;
	
	
	
	
	
}

TWI_Err_Status TWI_TWI_Err_StatusMasterSendData(u8 copy_u8data){
	
	TWI_Err_Status Loc_Err = NOErr ;
	
	
	/*send data on bus */
	
	TWDR_REG =copy_u8data ; 
	
	
	/*CLR Flag to start the next operation */
	
	SET_BIT(TWCR_REG,7) ;
	
	/*wait */
	while(GET_BIT(TWCR_REG,7)==0) ;
	
	/*check the operation status */
	
	if ((TWSR_REG&0xf8) != MASTER_WR_BYTE_ACK)
	{
		
		Loc_Err = MasterSendDataErr ;
	}
	else {
		
		// do nothing
	}
	
	
	return Loc_Err ;
	
	
}
TWI_Err_Status TWI_TWI_Err_StatusMasterReciveData(u8 *copy_u8data) {
	
	
	TWI_Err_Status Loc_Err = NOErr ;
	
	/*CLR Flag to start the next operation */
	
	SET_BIT(TWCR_REG,7) ;
	
	/*wait */
	
	while(GET_BIT(TWCR_REG,7)==0) ;
	
	/*check the operation status */
	
	if ((TWSR_REG&0xf8) != MASTER_RD_BYTE_WITH_ACK)
	{
		
		Loc_Err = MasterReciveDataErr ;
	}
	else {
		

          *copy_u8data =TWDR_REG ; 
	}
	
	
	return Loc_Err ;
	
	
	
}


void TWI_voidSendStopCondition(void) {
	
	 /*send SendStopCondition*/
	
	SET_BIT(TWCR_REG,4) ; 
	
	/*CLR Flag to start the next operation */
	
	SET_BIT(TWCR_REG,7) ;
	
	
}



TWI_Err_Status  TWI_TWI_Err_StatusACKOrNotACK(void) {
	
	TWI_Err_Status LOC_Err =NOErr ; 
	
	
 
 /*Enable ACK */
 SET_BIT(TWCR_REG,6) ;
 /*Enable TWI*/
 SET_BIT(TWCR_REG,2) ;
 
 	/*CLR Flag to start the next operation */
 	
 	SET_BIT(TWCR_REG,7) ;
 	
 	/*wait */
 	
 	while(GET_BIT(TWCR_REG,7)==0) ;
	 
	 if((TWSR_REG&0xf8)!= SLAVE_ADD_RCVD_WD_REQ){
		 
		 
		 LOC_Err =StatusACKOrNotACKErr ; 
	 }	
	
	
	return LOC_Err ; 
}


u8 TWI_u8SlaveReciveData() 
{
	

/*Enable ACK */
SET_BIT(TWCR_REG,6) ;
/*Enable TWI*/
SET_BIT(TWCR_REG,2) ;

/*CLR Flag to start the next operation */

SET_BIT(TWCR_REG,7) ;

/*wait */

while(GET_BIT(TWCR_REG,7)==0) ;	
	
	
	return TWDR_REG ; 
	
}


