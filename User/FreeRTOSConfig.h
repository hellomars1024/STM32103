#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H
 
 
//针对不同的编译器调用不同的stdint.h文件
//并确保stdint只被编译器使用，不被汇编器使用
#if defined(__ICCARM__) || defined(__CC_ARM) || defined(__GNUC__)
    #include <stdint.h>
    extern uint32_t SystemCoreClock;
#endif
 
 
/***********************************************************************************************************************/
 /*                                         FreeRTOS基础配置配置选项                                                   */
 /**********************************************************************************************************************/
 
 //#define configOVERRIDE_DEFAULT_TICK_CONFIGURATION 1 //使用非systick中断作为调度时钟
 
 
 
#define configUSE_PREEMPTION                    1   //置1：RTOS使用抢占式调度器；置0：RTOS使用协作式调度器（时间片）
/* 注：
 * 在多任务管理机制上，操作系统可以分为抢占式和协作式两种。
 * 抢占式：根据任务的优先级，优先级高的任务就绪后，获取CPU的使用权。
 * 协作式：任务主动释放CPU后，切换到下一个任务。
 */
 
 
 
#define configUSE_TIME_SLICING					1	//1：使能时间片调度(默认是使能的)
/* 注：
 * 为了实现时间片轮转调度，系统把所有就绪进程按先入先出的原则排成一个队列。新来的进程加到就绪队列末尾。
 * 每当执行进程调度时，进程调度程序总是选出就绪队列的队首进程，让它在CPU上运行一个时间片的时间。
 * 当进程用完分给它的时间片后，系统的计时器发出时钟中断，调度程序便停止该进程的运行，把它放入就绪队列的末尾；
 * 然后，把CPU分给就绪队列的队首进程，同样也让它运行一个时间片，如此往复。
 */
 
 
 
#define configUSE_PORT_OPTIMISED_TASK_SELECTION 1   //1：使用特殊方法选择下一个要执行的任务（硬件支持）
/* 注：
 * 某些运行FreeRTOS的硬件有两种方法选择下一个要执行的任务：通用方法和特定于硬件的方法（以下简称“特殊方法”）。
 * 通用方法：
 *      1.configUSE_PORT_OPTIMISED_TASK_SELECTION 为 0 或者硬件不支持这种特殊方法。
 *      2.可以用于所有FreeRTOS支持的硬件
 *      3.完全用C实现，效率略低于特殊方法。
 *      4.不强制要求限制最大可用优先级数目
 * 特殊方法：
 *      1.必须将configUSE_PORT_OPTIMISED_TASK_SELECTION设置为1。
 *      2.依赖一个或多个特定架构的汇编指令（一般是类似计算前导零[CLZ]指令）。
 *      3.比通用方法更高效
 *      4.一般强制限定最大可用优先级数目为32
 * 一般是硬件计算前导零指令，如果所使用的，MCU没有这些硬件指令的话此宏应该设置为0！
 */
 
 
 
#define configUSE_TICKLESS_IDLE                 0   //0：不启用低功耗tickless模式                                                                 
/* 注：
 * 置1：使能低功耗tickless模式；置0：保持系统节拍（tick）中断一直运行
 *
 * 假设开启低功耗的话可能会导致下载出现问题，因为程序在睡眠中,可用以下办法解决
 * 下载方法：
 *      1.将开发版正常连接好
 *      2.按住复位按键，点击下载瞬间松开复位按键
 *     
 *      1.通过跳线帽将 BOOT 0 接高电平(3.3V)
 *      2.重新上电，下载
 *    
 * 			1.使用FlyMcu擦除一下芯片，然后进行下载
 *			STMISP -> 清除芯片(z)
 */
 
 
 
#define configUSE_QUEUE_SETS                     1  //1：启用队列集合
/* 注：
 * 队列集合：用于对多个队列以及信号量进行“监听”，
 * 只要其中不管哪一个有消息到来，都可以让任务退出阻塞状态。
 */
 
 
 
#define configCPU_CLOCK_HZ                      (SystemCoreClock) //CPU频率
/* 注：
 * 写入实际的CPU内核时钟频率，也就是CPU指令执行频率，通常称为Fclk
 * Fclk为供给CPU内核的时钟信号，我们所说的cpu主频为 XX MHz，
 * 就是指的这个时钟信号，相应的，1/Fclk即为cpu时钟周期；
 */
 
 
 
#define configTICK_RATE_HZ                      (( TickType_t )1000) //时钟节拍频率1000HZ，周期就是1ms
/* 注：
 * RTOS系统节拍中断的频率。
 * 即一秒中断的次数，每次中断RTOS都会进行任务调度
 */
 
 
 
#define configMAX_PRIORITIES                    (32)  //可使用的最大优先级
/* 注：
 * 设置任务优先级时，数字越小，优先级越高
 */
 
 
 
#define configMINIMAL_STACK_SIZE                ((unsigned short)128)   //空闲任务使用的堆栈大小
/* 注：
 * 空闲任务就是CPU无事可做的时候，操作系统为了不让CPU闲着，强行让它做的一个任务
 * 空闲任务是FreeRTOS不可缺少的任务，因为FreeRTOS设计要求必须至少有一个任务处于运行状态。
 */  
 
 
 
#define configMAX_TASK_NAME_LEN					(16)    //任务名字字符串的长度
 
 
#define configUSE_16_BIT_TICKS					0       //系统节拍计数器变量的数据类型，
                                                        //1表示为16位无符号整形，0表示为32位无符号整形     
 
#define configIDLE_SHOULD_YIELD					1       //1：空闲任务放弃CPU使用权给其他同优先级的用户任务    
 
 
#define configUSE_TASK_NOTIFICATIONS            1       //1：开启任务通知功能，默认开启
 
 
#define configUSE_MUTEXES                       1       //1：使用互斥信号量
 
 
#define configQUEUE_REGISTRY_SIZE				8       //设置可以注册的信号量和消息队列个数
 
 
#define configCHECK_FOR_STACK_OVERFLOW			0       //不使用堆栈溢出检测功能
/* 注：
 * 大于0时启用堆栈溢出检测功能，如果使用此功能 
 * 用户必须提供一个栈溢出钩子函数，如果使用的话
 * 此值可以为1或者2，因为有两种栈溢出检测方法 */
 
 
#define configUSE_RECURSIVE_MUTEXES			    1       //1：使用递归互斥信号量   
 
 
#define configUSE_COUNTING_SEMAPHORES		    1       //1：使用计数信号量
 
                                    
#define configUSE_APPLICATION_TASK_TAG		    0       //不可为任务分配标签（默认不可）
 
 
/*****************************************************************
              FreeRTOS与内存申请有关配置选项                                               
*****************************************************************/
#define configSUPPORT_DYNAMIC_ALLOCATION        1       //支持动态内存申请
 
 
#define configTOTAL_HEAP_SIZE					((size_t)(10*1024)) //系统所有总的堆大小
//#define configTOTAL_HEAP_SIZE					((size_t)(32*1024)) //系统所有总的堆大小
 
 
/***************************************************************
             FreeRTOS与钩子函数有关的配置选项                                            
**************************************************************/
#define configUSE_IDLE_HOOK						0   //置1：使用空闲钩子；置0：忽略空闲钩子
/* 注：
 * 空闲任务钩子是一个函数，这个函数由用户来实现，
 * FreeRTOS规定了函数的名字和参数：void vApplicationIdleHook(void )，
 * 这个函数在每个空闲任务周期都会被调用
 * 对于已经删除的RTOS任务，空闲任务可以释放分配给它们的堆栈内存。
 * 因此必须保证空闲任务可以被CPU执行
 * 使用空闲钩子函数设置CPU进入省电模式是很常见的
 * 不可以调用 会引起空闲任务阻塞 的API函数
 */
 
 
#define configUSE_TICK_HOOK			            0   //置1：使用时间片钩子；置0：忽略时间片钩子
/* 注：
 * 时间片钩子是一个函数，这个函数由用户来实现，
 * FreeRTOS规定了函数的名字和参数：void vApplicationTickHook(void )
 * 时间片中断可以周期性的调用
 * 函数必须非常短小，不能大量使用堆栈，
 * 不能调用以”FromISR" 或 "FROM_ISR”结尾的API函数
 */
 
/*xTaskIncrementTick函数是在xPortSysTickHandler中断函数中被调用的。因此，vApplicationTickHook()函数执行的时间必须很短才行*/
        
 
//使用内存申请失败钩子函数
#define configUSE_MALLOC_FAILED_HOOK			0   //不使用内存申请失败钩子函数
 
 
/********************************************************************
          FreeRTOS与运行时间和任务状态收集有关的配置选项   
**********************************************************************/
 
#define configGENERATE_RUN_TIME_STATS	        0  //不启用运行时间统计功能(一般调试的使用用)
 
#define configUSE_TRACE_FACILITY		        1  //启用可视化跟踪调试
 
#define configUSE_STATS_FORMATTING_FUNCTIONS	1   
/* 与宏configUSE_TRACE_FACILITY同时为1时会编译下面3个函数
 * prvWriteNameToBuffer()
 * vTaskList(),
 * vTaskGetRunTimeStats()
*/
                    
 
/********************************************************************
                FreeRTOS与协程有关的配置选项                                                
*********************************************************************/
#define configUSE_CO_ROUTINES 	                0       //1：启用协程，启用协程以后必须添加文件croutine.c              
 
#define configMAX_CO_ROUTINE_PRIORITIES         ( 2 )   //协程的有效优先级数目          
 
 
/***********************************************************************
                FreeRTOS与软件定时器有关的配置选项      
**********************************************************************/
 
#define configUSE_TIMERS	                    1   //1：启用软件定时器
 
#define configTIMER_TASK_PRIORITY		        ( 2 )       //设置软件定时器优先级 
 
#define configTIMER_QUEUE_LENGTH		        10          //软件定时器队列长度                   
 
#define configTIMER_TASK_STACK_DEPTH	        (configMINIMAL_STACK_SIZE*2)    //软件定时器任务堆栈大小
 
 
/************************************************************
            FreeRTOS可选函数配置选项                                                     
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
            FreeRTOS与中断有关的配置选项                                                 
******************************************************************/
#ifdef __NVIC_PRIO_BITS
	#define configPRIO_BITS       		__NVIC_PRIO_BITS
#else
	#define configPRIO_BITS       		4                  
#endif
//由于STM32是4位的中断优先级控制，所以此处为4（不同的MCU不同）
 
 
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY			15     //中断最低优先级
//4位优先级全部分组给主优先级，所以总共有16位优先级配置：0-15--优先级最低的为15
//不同的MCU不同
 
#define configKERNEL_INTERRUPT_PRIORITY 		( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )	/* 240 */
//设置内核中断优先级，这个宏是用来设置PendSV和滴答定时器的中断优先级的，port.c中使用到
//此处的左移四位的原因是：STM32采用的是从MSB开始的高四位作为优先级配置
//其实这个宏定义可以简化成：#define configKERNEL_INTERRUPT_PRIORITY 0xF0
 
 
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY	5      //设置系统可管理的最大优先级
//这个就是 BASEPRI 寄存器说的那个阈值优先级，这里我设置为了 5。
//也就是高于 5 的优先级(优先级数小于 5)不归 FreeRTOS 管理！
//这个是给人看的，下面一个宏是给系统看的
 
#define configMAX_SYSCALL_INTERRUPT_PRIORITY 	( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )
//此处需要左移四位的原因：同上
//低于此优先级的中断可以安全的调用 FreeRTOS 的 API 函数，高于此优先级的中断 FreeRTOS 是不能禁止的，
//中断服务函数也不能调用 FreeRTOS 的 API 函数！
//也就是：#define configMAX_SYSCALL_INTERRUPT_PRIORITY  0x50
 
/*
 *	以上配置的结果就是：
 *	优先级为0-4的中断  不会被FreeRTOS禁止，不会因为执行FreeRTOS内核而延时，中断不可调用FreeRTOS的API函数
 *	优先级为5-15的中断 能够被FreeRTOS禁止，可以调用以 FromISR 结尾的FreeRTOS API函数，并且它们可以中断嵌套
 * 	所以：不掉用任何FreeRTOS API的中断可以使用所有的中断优先级，并且它们可以中断嵌套
 *	那些对实时性要求严格的任务就可以使用0-4的优先级，比如四轴飞行器中的壁障检测
*/
 
 
/****************************************************************
            FreeRTOS与中断服务函数有关的配置选项                         
****************************************************************/
#define xPortPendSVHandler 	PendSV_Handler
#define vPortSVCHandler 	SVC_Handler
//#define xPortSysTickHandler SysTickHandler 自行在delay.c函数中实现
 
 
#endif /* FREERTOS_CONFIG_H */
