#include "stm32f4xx_gpio.h"

void delay(unsigned int count)
{
	for( ; count > 0; count--);
}

#if 0
int main(void)
{
	RCC_AHB1ENR |= (1<<5);
	
	GPIOF_MODER &= ~(3<<(2*9));
	GPIOF_MODER |= (1<<(2*9));
	
	GPIOF_ODR |= (1<<9);
	
	while(1)
	{
		GPIOF_ODR &= ~(1<<9);
		delay(0x0FFFFF);
		GPIOF_ODR |= (1<<9);
		delay(0x0FFFFF);
		
	}
}

#else

int main()
{
	GPIO_InitTypeDef InitStruct;
	
	RCC->AHB1ENR |= (1 << 5);
	
	InitStruct.GPIO_Pin = GPIO_Pin_9;
	InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	InitStruct.GPIO_OType = GPIO_OType_PP;
	InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
	InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOF, &InitStruct);
	
		while(1)
	{
		GPIO_SetBits(GPIOF, GPIO_Pin_9);
		delay(0x0FFFFF);
		GPIO_ResetBits(GPIOF, GPIO_Pin_9);
		delay(0x0FFFFF);
	}
	
	return 0;
}

void SystemInit(void)
{}
	
#endif
