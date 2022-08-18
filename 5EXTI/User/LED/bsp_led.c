#include "bsp_led.h"

void LED_GPIO_Config(void)
{
	/* 开时钟 */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	
	/* 定义初始化结构体 */
	GPIO_InitTypeDef GPIO_InitStruct;
	
	/* 给初始化结构体赋值 */
	GPIO_InitStruct.GPIO_Pin = LED_RED_GPIO_PIN|LED_GREEN_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_DOWN;
	
	/* 初始化 */
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