
#include "stm32f10x.h"
#include "led.h"
#include "sw_spst.h"
#include "bit_anding.h"
#include "exit.h"
#include "FreeRTOSConfig.h"

void delay(uint32_t count){
	for(;count!=0;count--);
}
/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
	initLED();
	
//	initSW_SPST();
//	
//	while(1){
//		if(GPIO_Scan()==SW_ON){
//			LED_TOGGLE;
//		}
//	}
	
	//÷–∂œ≤‚ ‘
	init_EXIT();
	
//	while(1){
//		PCout(13)=0;
////		LEDSWITH(ON);
//		delay(0xFFFFF);
////		LEDSWITH(OFF);
//		PCout(13)=1;
//		delay(0xFFFFF);
//	}
}

