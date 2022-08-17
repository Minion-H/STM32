#include "stm32f4xx.h"
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
		LED(LED_RED_GPIO_PORT, LED_RED_GPIO_PIN, LED_TOGGLE);
		delay(0x0ffffff);
		LED(LED_RED_GPIO_PORT, LED_RED_GPIO_PIN, LED_TOGGLE);
		delay(0x0ffffff);
	}
}

