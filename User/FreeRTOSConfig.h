#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H
 
 
//��Բ�ͬ�ı��������ò�ͬ��stdint.h�ļ�
//��ȷ��stdintֻ��������ʹ�ã����������ʹ��
#if defined(__ICCARM__) || defined(__CC_ARM) || defined(__GNUC__)
    #include <stdint.h>
    extern uint32_t SystemCoreClock;
#endif
 
 
/***********************************************************************************************************************/
 /*                                         FreeRTOS������������ѡ��                                                   */
 /**********************************************************************************************************************/
 
 //#define configOVERRIDE_DEFAULT_TICK_CONFIGURATION 1 //ʹ�÷�systick�ж���Ϊ����ʱ��
 
 
 
#define configUSE_PREEMPTION                    1   //��1��RTOSʹ����ռʽ����������0��RTOSʹ��Э��ʽ��������ʱ��Ƭ��
/* ע��
 * �ڶ������������ϣ�����ϵͳ���Է�Ϊ��ռʽ��Э��ʽ���֡�
 * ��ռʽ��������������ȼ������ȼ��ߵ���������󣬻�ȡCPU��ʹ��Ȩ��
 * Э��ʽ�����������ͷ�CPU���л�����һ������
 */
 
 
 
#define configUSE_TIME_SLICING					1	//1��ʹ��ʱ��Ƭ����(Ĭ����ʹ�ܵ�)
/* ע��
 * Ϊ��ʵ��ʱ��Ƭ��ת���ȣ�ϵͳ�����о������̰������ȳ���ԭ���ų�һ�����С������Ľ��̼ӵ���������ĩβ��
 * ÿ��ִ�н��̵���ʱ�����̵��ȳ�������ѡ���������еĶ��׽��̣�������CPU������һ��ʱ��Ƭ��ʱ�䡣
 * ����������ָ�����ʱ��Ƭ��ϵͳ�ļ�ʱ������ʱ���жϣ����ȳ����ֹͣ�ý��̵����У���������������е�ĩβ��
 * Ȼ�󣬰�CPU�ָ��������еĶ��׽��̣�ͬ��Ҳ��������һ��ʱ��Ƭ�����������
 */
 
 
 
#define configUSE_PORT_OPTIMISED_TASK_SELECTION 1   //1��ʹ�����ⷽ��ѡ����һ��Ҫִ�е�����Ӳ��֧�֣�
/* ע��
 * ĳЩ����FreeRTOS��Ӳ�������ַ���ѡ����һ��Ҫִ�е�����ͨ�÷������ض���Ӳ���ķ��������¼�ơ����ⷽ��������
 * ͨ�÷�����
 *      1.configUSE_PORT_OPTIMISED_TASK_SELECTION Ϊ 0 ����Ӳ����֧���������ⷽ����
 *      2.������������FreeRTOS֧�ֵ�Ӳ��
 *      3.��ȫ��Cʵ�֣�Ч���Ե������ⷽ����
 *      4.��ǿ��Ҫ���������������ȼ���Ŀ
 * ���ⷽ����
 *      1.���뽫configUSE_PORT_OPTIMISED_TASK_SELECTION����Ϊ1��
 *      2.����һ�������ض��ܹ��Ļ��ָ�һ�������Ƽ���ǰ����[CLZ]ָ���
 *      3.��ͨ�÷�������Ч
 *      4.һ��ǿ���޶����������ȼ���ĿΪ32
 * һ����Ӳ������ǰ����ָ������ʹ�õģ�MCUû����ЩӲ��ָ��Ļ��˺�Ӧ������Ϊ0��
 */
 
 
 
#define configUSE_TICKLESS_IDLE                 0   //0�������õ͹���ticklessģʽ                                                                 
/* ע��
 * ��1��ʹ�ܵ͹���ticklessģʽ����0������ϵͳ���ģ�tick���ж�һֱ����
 *
 * ���迪���͹��ĵĻ����ܻᵼ�����س������⣬��Ϊ������˯����,�������°취���
 * ���ط�����
 *      1.���������������Ӻ�
 *      2.��ס��λ�������������˲���ɿ���λ����
 *     
 *      1.ͨ������ñ�� BOOT 0 �Ӹߵ�ƽ(3.3V)
 *      2.�����ϵ磬����
 *    
 * 			1.ʹ��FlyMcu����һ��оƬ��Ȼ���������
 *			STMISP -> ���оƬ(z)
 */
 
 
 
#define configUSE_QUEUE_SETS                     1  //1�����ö��м���
/* ע��
 * ���м��ϣ����ڶԶ�������Լ��ź������С���������
 * ֻҪ���в�����һ������Ϣ�������������������˳�����״̬��
 */
 
 
 
#define configCPU_CLOCK_HZ                      (SystemCoreClock) //CPUƵ��
/* ע��
 * д��ʵ�ʵ�CPU�ں�ʱ��Ƶ�ʣ�Ҳ����CPUָ��ִ��Ƶ�ʣ�ͨ����ΪFclk
 * FclkΪ����CPU�ں˵�ʱ���źţ�������˵��cpu��ƵΪ XX MHz��
 * ����ָ�����ʱ���źţ���Ӧ�ģ�1/Fclk��Ϊcpuʱ�����ڣ�
 */
 
 
 
#define configTICK_RATE_HZ                      (( TickType_t )1000) //ʱ�ӽ���Ƶ��1000HZ�����ھ���1ms
/* ע��
 * RTOSϵͳ�����жϵ�Ƶ�ʡ�
 * ��һ���жϵĴ�����ÿ���ж�RTOS��������������
 */
 
 
 
#define configMAX_PRIORITIES                    (32)  //��ʹ�õ�������ȼ�
/* ע��
 * �����������ȼ�ʱ������ԽС�����ȼ�Խ��
 */
 
 
 
#define configMINIMAL_STACK_SIZE                ((unsigned short)128)   //��������ʹ�õĶ�ջ��С
/* ע��
 * �����������CPU���¿�����ʱ�򣬲���ϵͳΪ�˲���CPU���ţ�ǿ����������һ������
 * ����������FreeRTOS����ȱ�ٵ�������ΪFreeRTOS���Ҫ�����������һ������������״̬��
 */  
 
 
 
#define configMAX_TASK_NAME_LEN					(16)    //���������ַ����ĳ���
 
 
#define configUSE_16_BIT_TICKS					0       //ϵͳ���ļ������������������ͣ�
                                                        //1��ʾΪ16λ�޷������Σ�0��ʾΪ32λ�޷�������     
 
#define configIDLE_SHOULD_YIELD					1       //1�������������CPUʹ��Ȩ������ͬ���ȼ����û�����    
 
 
#define configUSE_TASK_NOTIFICATIONS            1       //1����������֪ͨ���ܣ�Ĭ�Ͽ���
 
 
#define configUSE_MUTEXES                       1       //1��ʹ�û����ź���
 
 
#define configQUEUE_REGISTRY_SIZE				8       //���ÿ���ע����ź�������Ϣ���и���
 
 
#define configCHECK_FOR_STACK_OVERFLOW			0       //��ʹ�ö�ջ�����⹦��
/* ע��
 * ����0ʱ���ö�ջ�����⹦�ܣ����ʹ�ô˹��� 
 * �û������ṩһ��ջ������Ӻ��������ʹ�õĻ�
 * ��ֵ����Ϊ1����2����Ϊ������ջ�����ⷽ�� */
 
 
#define configUSE_RECURSIVE_MUTEXES			    1       //1��ʹ�õݹ黥���ź���   
 
 
#define configUSE_COUNTING_SEMAPHORES		    1       //1��ʹ�ü����ź���
 
                                    
#define configUSE_APPLICATION_TASK_TAG		    0       //����Ϊ��������ǩ��Ĭ�ϲ��ɣ�
 
 
/*****************************************************************
              FreeRTOS���ڴ������й�����ѡ��                                               
*****************************************************************/
#define configSUPPORT_DYNAMIC_ALLOCATION        1       //֧�ֶ�̬�ڴ�����
 
 
#define configTOTAL_HEAP_SIZE					((size_t)(10*1024)) //ϵͳ�����ܵĶѴ�С
//#define configTOTAL_HEAP_SIZE					((size_t)(32*1024)) //ϵͳ�����ܵĶѴ�С
 
 
/***************************************************************
             FreeRTOS�빳�Ӻ����йص�����ѡ��                                            
**************************************************************/
#define configUSE_IDLE_HOOK						0   //��1��ʹ�ÿ��й��ӣ���0�����Կ��й���
/* ע��
 * ������������һ������������������û���ʵ�֣�
 * FreeRTOS�涨�˺��������ֺͲ�����void vApplicationIdleHook(void )��
 * ���������ÿ�������������ڶ��ᱻ����
 * �����Ѿ�ɾ����RTOS���񣬿�����������ͷŷ�������ǵĶ�ջ�ڴ档
 * ��˱��뱣֤����������Ա�CPUִ��
 * ʹ�ÿ��й��Ӻ�������CPU����ʡ��ģʽ�Ǻܳ�����
 * �����Ե��� ����������������� ��API����
 */
 
 
#define configUSE_TICK_HOOK			            0   //��1��ʹ��ʱ��Ƭ���ӣ���0������ʱ��Ƭ����
/* ע��
 * ʱ��Ƭ������һ������������������û���ʵ�֣�
 * FreeRTOS�涨�˺��������ֺͲ�����void vApplicationTickHook(void )
 * ʱ��Ƭ�жϿ��������Եĵ���
 * ��������ǳ���С�����ܴ���ʹ�ö�ջ��
 * ���ܵ����ԡ�FromISR" �� "FROM_ISR����β��API����
 */
 
/*xTaskIncrementTick��������xPortSysTickHandler�жϺ����б����õġ���ˣ�vApplicationTickHook()����ִ�е�ʱ�����̲ܶ���*/
        
 
//ʹ���ڴ�����ʧ�ܹ��Ӻ���
#define configUSE_MALLOC_FAILED_HOOK			0   //��ʹ���ڴ�����ʧ�ܹ��Ӻ���
 
 
/********************************************************************
          FreeRTOS������ʱ�������״̬�ռ��йص�����ѡ��   
**********************************************************************/
 
#define configGENERATE_RUN_TIME_STATS	        0  //����������ʱ��ͳ�ƹ���(һ����Ե�ʹ����)
 
#define configUSE_TRACE_FACILITY		        1  //���ÿ��ӻ����ٵ���
 
#define configUSE_STATS_FORMATTING_FUNCTIONS	1   
/* ���configUSE_TRACE_FACILITYͬʱΪ1ʱ���������3������
 * prvWriteNameToBuffer()
 * vTaskList(),
 * vTaskGetRunTimeStats()
*/
                    
 
/********************************************************************
                FreeRTOS��Э���йص�����ѡ��                                                
*********************************************************************/
#define configUSE_CO_ROUTINES 	                0       //1������Э�̣�����Э���Ժ��������ļ�croutine.c              
 
#define configMAX_CO_ROUTINE_PRIORITIES         ( 2 )   //Э�̵���Ч���ȼ���Ŀ          
 
 
/***********************************************************************
                FreeRTOS�������ʱ���йص�����ѡ��      
**********************************************************************/
 
#define configUSE_TIMERS	                    1   //1�����������ʱ��
 
#define configTIMER_TASK_PRIORITY		        ( 2 )       //���������ʱ�����ȼ� 
 
#define configTIMER_QUEUE_LENGTH		        10          //�����ʱ�����г���                   
 
#define configTIMER_TASK_STACK_DEPTH	        (configMINIMAL_STACK_SIZE*2)    //�����ʱ�������ջ��С
 
 
/************************************************************
            FreeRTOS��ѡ��������ѡ��                                                     
************************************************************/
#define INCLUDE_xTaskGetSchedulerState          1                       
#define INCLUDE_vTaskPrioritySet		        1
#define INCLUDE_uxTaskPriorityGet		        1
#define INCLUDE_vTaskDelete				        1
#define INCLUDE_vTaskCleanUpResources	        1
#define INCLUDE_vTaskSuspend			        1
#define INCLUDE_vTaskDelayUntil			        1
#define INCLUDE_vTaskDelay				        1
#define INCLUDE_eTaskGetState			        1
#define INCLUDE_xTimerPendFunctionCall	        1
#define INCLUDE_uxTaskGetStackHighWaterMark     1
#define INCLUDE_xTaskGetHandle                  1
 
/******************************************************************
            FreeRTOS���ж��йص�����ѡ��                                                 
******************************************************************/
#ifdef __NVIC_PRIO_BITS
	#define configPRIO_BITS       		__NVIC_PRIO_BITS
#else
	#define configPRIO_BITS       		4                  
#endif
//����STM32��4λ���ж����ȼ����ƣ����Դ˴�Ϊ4����ͬ��MCU��ͬ��
 
 
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY			15     //�ж�������ȼ�
//4λ���ȼ�ȫ������������ȼ��������ܹ���16λ���ȼ����ã�0-15--���ȼ���͵�Ϊ15
//��ͬ��MCU��ͬ
 
#define configKERNEL_INTERRUPT_PRIORITY 		( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )	/* 240 */
//�����ں��ж����ȼ������������������PendSV�͵δ�ʱ�����ж����ȼ��ģ�port.c��ʹ�õ�
//�˴���������λ��ԭ���ǣ�STM32���õ��Ǵ�MSB��ʼ�ĸ���λ��Ϊ���ȼ�����
//��ʵ����궨����Լ򻯳ɣ�#define configKERNEL_INTERRUPT_PRIORITY 0xF0
 
 
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY	5      //����ϵͳ�ɹ����������ȼ�
//������� BASEPRI �Ĵ���˵���Ǹ���ֵ���ȼ�������������Ϊ�� 5��
//Ҳ���Ǹ��� 5 �����ȼ�(���ȼ���С�� 5)���� FreeRTOS ����
//����Ǹ��˿��ģ�����һ�����Ǹ�ϵͳ����
 
#define configMAX_SYSCALL_INTERRUPT_PRIORITY 	( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )
//�˴���Ҫ������λ��ԭ��ͬ��
//���ڴ����ȼ����жϿ��԰�ȫ�ĵ��� FreeRTOS �� API ���������ڴ����ȼ����ж� FreeRTOS �ǲ��ܽ�ֹ�ģ�
//�жϷ�����Ҳ���ܵ��� FreeRTOS �� API ������
//Ҳ���ǣ�#define configMAX_SYSCALL_INTERRUPT_PRIORITY  0x50
 
/*
 *	�������õĽ�����ǣ�
 *	���ȼ�Ϊ0-4���ж�  ���ᱻFreeRTOS��ֹ��������Ϊִ��FreeRTOS�ں˶���ʱ���жϲ��ɵ���FreeRTOS��API����
 *	���ȼ�Ϊ5-15���ж� �ܹ���FreeRTOS��ֹ�����Ե����� FromISR ��β��FreeRTOS API�������������ǿ����ж�Ƕ��
 * 	���ԣ��������κ�FreeRTOS API���жϿ���ʹ�����е��ж����ȼ����������ǿ����ж�Ƕ��
 *	��Щ��ʵʱ��Ҫ���ϸ������Ϳ���ʹ��0-4�����ȼ�����������������еı��ϼ��
*/
 
 
/****************************************************************
            FreeRTOS���жϷ������йص�����ѡ��                         
****************************************************************/
#define xPortPendSVHandler 	PendSV_Handler
#define vPortSVCHandler 	SVC_Handler
//#define xPortSysTickHandler SysTickHandler ������delay.c������ʵ��
 
 
#endif /* FREERTOS_CONFIG_H */
