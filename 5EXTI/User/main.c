#include "stm32f4xx.h"
#include "bsp_led.h"
#include "./KEY/key.h"

void delay(unsigned int count)
{
	for( ; count > 0; count--);
}

int main(void)
{
	LED_GPIO_Config();
	KEY_GPIO_Config();
	LED(LED_RED_GPIO_PORT, LED_RED_GPIO_PIN, LED_OFF);
	LED(LED_GREEN_GPIO_PORT, LED_GREEN_GPIO_PIN, LED_OFF);
	while(1)
	{
		if(Key_Scan(KEY_GPIO_PORT, KEY0_GPIO_PIN) == KEY_ON)
			LED(LED_RED_GPIO_PORT, LED_RED_GPIO_PIN, LED_TOGGLE);
		
		if(Key_Scan(KEY_GPIO_PORT, KEY1_GPIO_PIN) == KEY_ON)
			LED(LED_GREEN_GPIO_PORT, LED_GREEN_GPIO_PIN, LED_TOGGLE);
		
		
	}
}

