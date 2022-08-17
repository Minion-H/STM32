#include "bsp_led.h"

void delay(unsigned int count)
{
	for( ; count > 0; count--);
}

int main(void)
{
	LED_GPIO_Config();

	
	while(1)
	{
		GPIO_SetBits(GPIOF, GPIO_Pin_9|GPIO_Pin_10);
		delay(0x0ffffff);
		GPIO_ResetBits(GPIOF, GPIO_Pin_9|GPIO_Pin_10);
		delay(0x0ffffff);
	}
}

