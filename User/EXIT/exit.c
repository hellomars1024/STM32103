#include "exit.h"



//≈‰÷√NVIC 
static void setNVICConfig(void){
		NVIC_InitTypeDef NVIC_InitStruct;
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
		NVIC_InitStruct.NVIC_IRQChannel=EXTI0_IRQn;
		NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=1;
		NVIC_InitStruct.NVIC_IRQChannelSubPriority=1;
		NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
		
		NVIC_Init(&NVIC_InitStruct);
}

void  init_EXIT(void){
	
		GPIO_InitTypeDef GPIO_InitStruct;
		EXTI_InitTypeDef EXTI_InitStruct;
			
		EXTI_InitStruct.EXTI_Line=SW_INT_EXTI_LINE;
		EXTI_InitStruct.EXTI_Mode=EXTI_Mode_Interrupt;
		EXTI_InitStruct.EXTI_Trigger=EXTI_Trigger_Falling;
		EXTI_InitStruct.EXTI_LineCmd=ENABLE;
	
		//≥ı ºªØ EXIT
		EXTI_Init(&EXTI_InitStruct);
	
		//≈‰÷√NVIC
		setNVICConfig();
//	  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
		
		RCC_APB2PeriphClockCmd(EXIT_GPIO_CLK,ENABLE);
		GPIO_InitStruct.GPIO_Mode=EXIT_GPIO_MODE;
		GPIO_InitStruct.GPIO_Pin=EXIT_GPIO_PIN;

		GPIO_Init(EXIT_GPIO_PORT,&GPIO_InitStruct);
}


