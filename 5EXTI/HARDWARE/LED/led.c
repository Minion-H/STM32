#include "led.h"

void LED_GPIO_Config(void)
{
	/* ��ʱ�� */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	
	/* �����ʼ���ṹ�� */
	GPIO_InitTypeDef GPIO_InitStruct;
	
	/* ����ʼ���ṹ�帳ֵ */
	GPIO_InitStruct.GPIO_Pin = LED_RED_GPIO_PIN|LED_GREEN_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_DOWN;
	
	/* ��ʼ�� */
	GPIO_Init(GPIOF, &GPIO_InitStruct);
}

void LED(GPIO_TypeDef *LED_GPIO_PORT, uint16_t LED_GPIO_PIN, LEDSate_TypeDef LED_State)
{
	switch(LED_State)
	{
		case LED_ON:
			GPIO_ResetBits(LED_GPIO_PORT, LED_GPIO_PIN);
			break;
		case LED_OFF:
			GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_PIN);
		  break;
		case LED_TOGGLE:
			LED_GPIO_PORT->ODR ^= LED_GPIO_PIN;
			break;
	}
		
}