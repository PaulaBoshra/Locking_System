#include "Controller.h"

int main(void){
	startUp_Controller();
	while (1){}
}

void startUp_Controller(void){
	initialize_Devices();
}


void initialize_Devices(void){
	int BaudRate = 9600;
	USART_Init(BaudRate, NO_PARITY, ONE_STOP_BIT, EIGHT_BITS, ASYNCHRONOUS);
	Buzzer_Init();
	DCMotor_Init();
	EEPROM_Init(1, 1, 400000);
}

void isFirstTime(void){
	U8 FisrtTimeCheckData;
	while(USART_Receive() != IS_FIRST_TIME);  // Busy waiting

	/*Read from the address that is used to tell whether there is saved passwords or not 
	and then store the data in FisrtTimeCheckData */
	EEPROM_Read(FIRST_TIME_CHECK_ADDRESS, &FisrtTimeCheckData);

	if(FisrtTimeCheckData == SAVED_PASSWORDS){
		USART_Transmit(SAVED_PASSWORDS);	
		normal_SystemOperations();
	}
	
	else if(FisrtTimeCheckData == NO_SAVED_PASSWORDS){
		USART_Transmit(NO_SAVED_PASSWORDS);
		firstTime_SystemOperations();
	}
}

void normal_SystemOperations(void){
	
}

void firstTime_SystemOperations(void){
 
}