#include "key_exti.h"
#include "key.h"

static void NVIC_Config(void)
{
	//����NVIC��ʼ���ṹ��
	NVIC_InitTypeDef NVIC_InitStructure;
	
	//����NVIC���ȼ���
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	//���ó�ʼ���ṹ��
	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	//��ʼ��NVIC
	NVIC_Init(&NVIC_InitStructure);
	
}

void EXTI_Key_Config(void)
{
	//�����ʼ���ṹ��
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	
	//��������ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);
	
	//����NVIC
	NVIC_Config();
	
	//��ʼ��KEY0��GPIO
	GPIO_InitStructure.GPIO_Pin = KEY0_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(KEY_GPIO_PORT, &GPIO_InitStructure);
	
	//ѡ��EXTI�ж�ԴΪKEY0������PE4
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource4);
	
	//��ʼ��EXTI
	EXTI_InitStructure.EXTI_Line = EXTI_Line4; //ѡ����Ҫ��ʼ�����ж���
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
}
