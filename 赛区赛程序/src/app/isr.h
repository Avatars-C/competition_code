/******************** (C) COPYRIGHT 2011 野火嵌入式开发工作室 ********************
 * 文件名       ：isr.h
 * 描述         ：重新宏定义中断号，重映射中断向量表里的中断函数地址，
 *                使其指向我们所定义的中断服务函数。声明中断服务函数
 *                警告：只能在"vectors.c"包含，而且必须在"vectors.h"包含的后面！！！
 *          
 * 实验平台     ：野火kinetis开发板
 * 库版本       ：
 * 嵌入系统     ：
 *
 * 作者         ：野火嵌入式开发工作室 
 * 淘宝店       ：http://firestm32.taobao.com
 * 技术支持论坛 ：http://www.ourdev.cn/bbs/bbs_list.jsp?bbs_id=1008   
**********************************************************************************/	



#ifndef __ISR_H
#define __ISR_H 1

#include  "include.h"  


#undef  VECTOR_014
#undef  VECTOR_015
#if     USOC_EN > 0u    //如果定义了用ucos系统  用ucos的滴答定时器中断服务函数
  #define VECTOR_014    OS_CPU_PendSVHandler
  #define VECTOR_015    OS_CPU_SysTickHandler
#else
  #define VECTOR_014    PendSV_Handler
  #define VECTOR_015    SysTick_Handler   //滴答定时器  OS用得到
#endif

#undef  VECTOR_003
#define VECTOR_003    HardFault_Handler   //发生硬件上访 （就是程序跑飞了）     推荐调试程序时，用个LED显示来指示程序跑飞了

//#undef  VECTOR_063                        //要先取消了，因为在vectors.h里默认是定义为 default_isr  
//#define VECTOR_063    USART1_IRQHandler   //重新定义63号中断的ISR：UART1：Single interrupt vector for UART status sources

#undef  VECTOR_067                        //要先取消了，因为在vectors.h里默认是定义为 default_isr  
#define VECTOR_067    USART3_IRQHandler

#undef  VECTOR_078
#define VECTOR_078    FTM0_IRQHandler     //FTM0输入捕捉中断 

#undef  VECTOR_079
#define VECTOR_079    FTM1_IRQHandler     //FTM0输入捕捉中断

#undef  VECTOR_084
#define VECTOR_084    PIT0_IRQHandler     //重新定义84号中断为PIT0_IRQHandler中断

#undef  VECTOR_101
#define VECTOR_101    LPT_Handler           //LPT中断

#undef  VECTOR_103
#define VECTOR_103    PORTA_IRQHandler    //PORTA中断

#undef  VECTOR_104
#define VECTOR_104    PORTB_IRQHandler    //PORTB中断


extern void PendSV_Handler(void);         //可悬起的系统调用中断服务函数
extern void HardFault_Handler(void);      //发生硬件上访（程序跑飞）
extern void SysTick_Handler(void);        //滴答时钟(os 用到)
extern void USART3_IRQHandler();          //串口3 中断接收函数

extern void PIT0_IRQHandler();            //PIT0 定时中断服务函数
extern void PORTA_IRQHandler();           //PORTA中断服务函数
extern void PORTB_IRQHandler();           //PORTB中断服务函数
extern void FTM0_IRQHandler();            //FTM0输入捕捉中断
extern void FTM1_IRQHandler();            //FTM0输入捕捉中断
extern void LPT_Handler(void);            //LPT脉冲累加中断


extern int16  now_speed,cesu;
extern int16  adc_max;
extern int16  LPT_INT_count,stop_flag_yes,STOP_FLAG;
#endif  //__ISR_H

/* End of "isr.h" */
