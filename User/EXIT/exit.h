#ifndef _EXIT_H
#define _EXIT_H
#include "stm32f10x.h"
#include "stm32f10x_exti.h"

#define EXIT_GPIO_PORT   				GPIOA

#define EXIT_GPIO_PIN   				GPIO_Pin_0
#define EXIT_GPIO_MODE  				GPIO_Mode_IN_FLOATING

#define EXIT_GPIO_CLK    				RCC_APB2Periph_GPIOA
#define SW_INT_EXTI_LINE  			EXTI_Line0


void init_EXIT(void);

#endif /*_EXIT_H*/
