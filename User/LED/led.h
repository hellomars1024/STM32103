#ifndef _LED_H
#define _LED_H

#include "stm32f10x.h"

#define LED_GPIO_PORT   	GPIOC

#define LED_GPIO_PIN   		GPIO_Pin_13
#define LED_GPIO_SPEED   	GPIO_Speed_10MHz
#define LED_GPIO_MODE  		GPIO_Mode_Out_PP

#define LED_GPIO_CLK    	RCC_APB2Periph_GPIOC

#define LED_TOGGLE {LED_GPIO_PORT->ODR ^=LED_GPIO_PIN;}

#define ON 		1
#define OFF 	0

#define LEDSWITH(a) if(a)GPIO_ResetBits(LED_GPIO_PORT,LED_GPIO_PIN);else GPIO_SetBits(LED_GPIO_PORT,LED_GPIO_PIN);

void initLED(void);

#endif /*_LED_H*/


