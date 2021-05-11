
#include "stm32f10x.h"
#include "led.h"
#include "sw_spst.h"
#include "bit_anding.h"
#include "exit.h"

#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"

void delay(uint32_t count){
	for(;count!=0;count--);
}
TaskHandle_t task1TaskHandle= NULL; //句柄
TaskHandle_t task1TaskHandle2= NULL; //句柄
TaskHandle_t AppTaskCreate_Handle=NULL;

void start_task(void){
	initLED();
		while(1){
			
		PCout(13)=0;
		delay(0xFFFFF);
		PCout(13)=1;
		delay(0xFFFFF);
	}

}

void start_task2(void){
//	initLED();
		while(1){
//		PCout(13)=0;
//		delay(0xFFFFF);
//		PCout(13)=1;
//		delay(0xFFFFF);
	}
}


void AppTaskCreate(void)
{
  BaseType_t xReturn = pdPASS;
  
  taskENTER_CRITICAL();
  
  /* 创建LED1_Task任务 */
  xReturn = xTaskCreate((TaskFunction_t )start_task,
                        (const char*    )"start_task",
                        (uint16_t       )125,
                        (void*          )NULL,
                        (UBaseType_t    )2,
                        (TaskHandle_t*  )&task1TaskHandle);
  if(pdPASS == xReturn)
    printf("创建LED1_Task任务成功!\r\n");
  
	/* 创建LED2_Task任务 */
  xReturn = xTaskCreate((TaskFunction_t )start_task2,
                        (const char*    )"start_task2",
                        (uint16_t       )125,
                        (void*          )NULL,
                        (UBaseType_t    )3,
                        (TaskHandle_t*  )&task1TaskHandle2);
  if(pdPASS == xReturn)
    printf("创建LED2_Task任务成功!\r\n");
  
  vTaskDelete(AppTaskCreate_Handle); //删除AppTaskCreate任务
  
  taskEXIT_CRITICAL();            //退出临界区
}



/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
	 /* 定义一个创建信息返回值，默认为pdPASS */
  BaseType_t xReturn = pdPASS;
	
	 /* 创建AppTaskCreate任务 */
  xReturn = xTaskCreate((TaskFunction_t )AppTaskCreate,  /* 任务入口函数 */
                        (const char*    )"AppTaskCreate",/* 任务名字 */
                        (uint16_t       )512,  /* 任务栈大小 */
                        (void*          )NULL,/* 任务入口函数参数 */
                        (UBaseType_t    )1, /* 任务的优先级 */
                        (TaskHandle_t*  )&AppTaskCreate_Handle);/* 任务控制块指针 */
  /* 启动任务调度 */           
  if(pdPASS == xReturn)
    vTaskStartScheduler();   /* 启动任务，开启调度 */
  else
    return -1;  
												
	  //开启任务调度								
	
//	initLED();
	
//	initSW_SPST();
//	
//	while(1){
//		if(GPIO_Scan()==SW_ON){
//			LED_TOGGLE;
//		}
//	}
	
	//中断测试
//	init_EXIT();
	
//	while(1){
//		PCout(13)=0;
////		LEDSWITH(ON);
//		delay(0xFFFFF);
////		LEDSWITH(OFF);
//		PCout(13)=1;
//		delay(0xFFFFF);
//	}
}



