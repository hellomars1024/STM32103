#include "sw_spst.h"


void initSW_SPST(void){
	
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(SW_GPIO_CLK,ENABLE);
	GPIO_InitStruct.GPIO_Pin=SW_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	
	GPIO_Init(SW_GPIO_PORT,&GPIO_InitStruct);
}

uint8_t GPIO_Scan(void){
		if(GPIO_ReadInputDataBit(SW_GPIO_PORT, SW_GPIO_PIN)==SW_ON){
			
			while(GPIO_ReadInputDataBit(SW_GPIO_PORT, SW_GPIO_PIN)==SW_ON);
				return SW_ON;
		}else{
				return SW_OFF;
		}
		
	
}



