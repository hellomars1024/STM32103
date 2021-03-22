#include "led.h"

void initLED(void){
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(LED_GPIO_CLK,ENABLE);
	

	
	GPIO_InitStruct.GPIO_Mode=LED_GPIO_MODE;
	GPIO_InitStruct.GPIO_Pin=LED_GPIO_PIN;
	GPIO_InitStruct.GPIO_Speed=LED_GPIO_SPEED;
	


	GPIO_Init(LED_GPIO_PORT,&GPIO_InitStruct);
	
	//GPIO_SetBits(LED_GPIO_PORT,LED_GPIO_PIN);
	
	//GPIO_ResetBits(LED_GPIO_PORT,LED_GPIO_PIN);

}
