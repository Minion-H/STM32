#include "key.h"
#include "delay.h"

void KEY_GPIO_Init()
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	
	/* 定义初始化结构体 */
	GPIO_InitTypeDef GPIO_InitStruct;
	
	/* 给初始化结构体赋值 */
	GPIO_InitStruct.GPIO_Pin = KEY0_GPIO_PIN|KEY1_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;  //保证按键未按下时是高电平
	
	/* 初始化 */
	GPIO_Init(KEY_GPIO_PORT, &GPIO_InitStruct);

}

uint8_t Key_Scan(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	if(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON)
	{
		delay_ms(10);
		if(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON)
		{
			while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON);
			return KEY_ON;
		}
	}
	else
		return KEY_OFF;
}
