#ifndef _BSP_LED_H_
#define _BSP_LED_H_

#include "stm32f4xx.h"

#define LED_RED_GPIO_PORT GPIOF
#define LED_RED_GPIO_PIN  GPIO_Pin_9
#define LED_GREEN_GPIO_PORT GPIOF
#define LED_GREEN_GPIO_PIN  GPIO_Pin_10


typedef enum{
	LED_OFF = 0x00,
	LED_ON = 0x01,
	LED_TOGGLE = 0x02,
}LEDSate_TypeDef;

//#define LED_RED(a) if(a) \
//	                   GPIO_SetBits(LED_RED_GPIO_PORT,LED_RED_GPIO_PIN);\
//                   else \
//	                   GPIO_ResetBits(LED_RED_GPIO_PORT,LED_RED_GPIO_PIN)

void LED_GPIO_Init(void);
void LED(GPIO_TypeDef *LED_GPIO_PORT, uint16_t LED_GPIO_PIN, LEDSate_TypeDef LED_State);


#endif  //_BSP_LED_H_
