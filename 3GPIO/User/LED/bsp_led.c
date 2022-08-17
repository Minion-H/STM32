#include "bsp_led.h"

void LED_GPIO_Config(void)
{
	/* ��ʱ�� */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	
	/* �����ʼ���ṹ�� */
	GPIO_InitTypeDef GPIO_InitStruct;
	
	/* ����ʼ���ṹ�帳ֵ */
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
	
	/* ��ʼ�� */
	GPIO_Init(GPIOF, &GPIO_InitStruct);
}

void LED(GPIO_TypeDef *LED_GPIO_PORT, uint16_t LED_GPIO_PIN, LEDSate_TypeDef LED_State)
{
	switch(LED_State)
	{
		case 0:
			GPIO_ResetBits(LED_GPIO_PORT, LED_GPIO_PIN);
			break;
		case 1:
			GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_PIN);
		  break;
		case 2:
			LED_GPIO_PORT->ODR ^= LED_GPIO_PIN;
			break;
	}
		
}