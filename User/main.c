
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
TaskHandle_t task1TaskHandle= NULL; //���
TaskHandle_t task1TaskHandle2= NULL; //���
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
  
  /* ����LED1_Task���� */
  xReturn = xTaskCreate((TaskFunction_t )start_task,
                        (const char*    )"start_task",
                        (uint16_t       )125,
                        (void*          )NULL,
                        (UBaseType_t    )2,
                        (TaskHandle_t*  )&task1TaskHandle);
  if(pdPASS == xReturn)
    printf("����LED1_Task����ɹ�!\r\n");
  
	/* ����LED2_Task���� */
  xReturn = xTaskCreate((TaskFunction_t )start_task2,
                        (const char*    )"start_task2",
                        (uint16_t       )125,
                        (void*          )NULL,
                        (UBaseType_t    )3,
                        (TaskHandle_t*  )&task1TaskHandle2);
  if(pdPASS == xReturn)
    printf("����LED2_Task����ɹ�!\r\n");
  
  vTaskDelete(AppTaskCreate_Handle); //ɾ��AppTaskCreate����
  
  taskEXIT_CRITICAL();            //�˳��ٽ���
}



/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
	 /* ����һ��������Ϣ����ֵ��Ĭ��ΪpdPASS */
  BaseType_t xReturn = pdPASS;
	
	 /* ����AppTaskCreate���� */
  xReturn = xTaskCreate((TaskFunction_t )AppTaskCreate,  /* ������ں��� */
                        (const char*    )"AppTaskCreate",/* �������� */
                        (uint16_t       )512,  /* ����ջ��С */
                        (void*          )NULL,/* ������ں������� */
                        (UBaseType_t    )1, /* ��������ȼ� */
                        (TaskHandle_t*  )&AppTaskCreate_Handle);/* ������ƿ�ָ�� */
  /* ����������� */           
  if(pdPASS == xReturn)
    vTaskStartScheduler();   /* �������񣬿������� */
  else
    return -1;  
												
	  //�����������								
	
//	initLED();
	
//	initSW_SPST();
//	
//	while(1){
//		if(GPIO_Scan()==SW_ON){
//			LED_TOGGLE;
//		}
//	}
	
	//�жϲ���
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



