#include "stm32f4xx.h"

void delay(unsigned int count)
{
	for( ; count > 0; count--);
}

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

void SystemInit(void)
{}
	