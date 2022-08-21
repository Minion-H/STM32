#include "key_exti.h"
#include "key.h"

static void NVIC_Config(void)
{
	//定义NVIC初始化结构体
	NVIC_InitTypeDef NVIC_InitStructure;
	
	//配置NVIC优先级组
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	//配置初始化结构体
	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	//初始化NVIC
	NVIC_Init(&NVIC_InitStructure);
	
}

void EXTI_Key_Config(void)
{
	//定义初始化结构体
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	
	//开启外设时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);
	
	//配置NVIC
	NVIC_Config();
	
	//初始化KEY0的GPIO
	GPIO_InitStructure.GPIO_Pin = KEY0_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(KEY_GPIO_PORT, &GPIO_InitStructure);
	
	//选择EXTI中断源为KEY0的引脚PE4
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource4);
	
	//初始化EXTI
	EXTI_InitStructure.EXTI_Line = EXTI_Line4; //选择需要初始化的中断线
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
}
