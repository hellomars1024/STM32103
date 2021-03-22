#ifndef 	__SW_SPST_H
#define  __SW_SPST_H

#define SW_GPIO_PORT   	GPIOA

#define SW_GPIO_PIN   		GPIO_Pin_0
//#define LED_GPIO_SPEED   	GPIO_Speed_10MHz
//#define LED_GPIO_MODE  		GPIO_Mode_Out_PP

#define SW_GPIO_CLK    	RCC_APB2Periph_GPIOA
#include "stm32f10x.h"

#define SW_ON			1
#define SW_OFF		0


void initSW_SPST(void);
uint8_t GPIO_Scan(void);

#endif /*__SW_SPST_H*/
