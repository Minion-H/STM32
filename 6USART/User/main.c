#include "stm32f4xx.h"
#include "delay.h"
#include "led.h"
#include "key.h"
#include "key_exti.h"

//ALIENTEK 探索者STM32F407开发板 实验0
//STM32F4工程模板-库函数版本
//技术支持：www.openedv.com
//淘宝店铺：http://eboard.taobao.com
//广州市星翼电子科技有限公司  
//作者：正点原子 @ALIENTEK

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组 2
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
手册中讲解到步骤15的时候的main.c源码如下：
#include "stm32f4xx.h"

//ALIENTEK 探索者STM32F407开发板 实验0
//STM32F4工程模板-库函数版本
//技术支持：www.openedv.com
//淘宝店铺：http://eboard.taobao.com
//广州市星翼电子科技有限公司  
//作者：正点原子 @ALIENTEK
  
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


