#ifndef _KEY_H_
#define _KEY_H_

#include "stm32f4xx.h"

#define KEY_GPIO_PORT GPIOE
#define KEY0_GPIO_PIN GPIO_Pin_4
#define KEY1_GPIO_PIN GPIO_Pin_3

#define KEY_ON 0 //按键按下接地
#define KEY_OFF 1

void KEY_GPIO_Config(void);
uint8_t Key_Scan(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

#endif /* _KEY_H_ */
