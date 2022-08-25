#ifndef _USART1_H_
#define _USART1_H_

#include "stm32f4xx.h"

void USART1_Init(u32 bound);
void USART_SendByte(USART_TypeDef* pUSARTx, uint8_t ch);
void USART_SendString(USART_TypeDef* pUSARTx, char* str);

#endif /* _USART1_H_ */
