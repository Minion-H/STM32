#include "stm32f4xx.h"
#include "delay.h"
#include "led.h"
#include "key.h"
#include "key_exti.h"

//ALIENTEK ̽����STM32F407������ ʵ��0
//STM32F4����ģ��-�⺯���汾
//����֧�֣�www.openedv.com
//�Ա����̣�http://eboard.taobao.com
//������������ӿƼ����޹�˾  
//���ߣ�����ԭ�� @ALIENTEK

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ����� 2
	delay_init(168);
	LED_GPIO_Init();
	KEY_GPIO_Init();
	EXTI_Key_Init();
	
	LED(LED_RED_GPIO_PORT, LED_RED_GPIO_PIN, LED_OFF);
	LED(LED_GREEN_GPIO_PORT, LED_GREEN_GPIO_PIN, LED_OFF);
	
	while(1)
	{
//		if(Key_Scan(KEY_GPIO_PORT, KEY0_GPIO_PIN) == KEY_ON)
//			LED(LED_RED_GPIO_PORT, LED_RED_GPIO_PIN, LED_TOGGLE);
		if(Key_Scan(KEY_GPIO_PORT, KEY1_GPIO_PIN) == KEY_ON)
			LED(LED_GREEN_GPIO_PORT, LED_GREEN_GPIO_PIN, LED_TOGGLE);
	}
}

/*
�ֲ��н��⵽����15��ʱ���main.cԴ�����£�
#include "stm32f4xx.h"

//ALIENTEK ̽����STM32F407������ ʵ��0
//STM32F4����ģ��-�⺯���汾
//����֧�֣�www.openedv.com
//�Ա����̣�http://eboard.taobao.com
//������������ӿƼ����޹�˾  
//���ߣ�����ԭ�� @ALIENTEK
  
void Delay(__IO uint32_t nCount);

void Delay(__IO uint32_t nCount)
{
  while(nCount--){}
}

int main(void)
{

  GPIO_InitTypeDef  GPIO_InitStructure;
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOF, &GPIO_InitStructure);

  while(1){
		GPIO_SetBits(GPIOF,GPIO_Pin_9|GPIO_Pin_10);
		Delay(0x7FFFFF);
		GPIO_ResetBits(GPIOF,GPIO_Pin_9|GPIO_Pin_10);
		Delay(0x7FFFFF);
	
	}
}
*/


