#include "usart1.h"

void USART1_Init(u32 bound)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	/* 开时钟 */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	
	/* 初始化GPIO */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType =  GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //上拉
	GPIO_Init(GPIOA,&GPIO_InitStructure); //初始化 PA9，PA10
	
	/* 设置引脚复用功能 */
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);
	
	/* 初始化USART */
	USART_InitStructure.USART_BaudRate = bound;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits =USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART1, &USART_InitStructure);
	
	/* 使能USART接收中断 */
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	
	/* 配置USART1 NVIC */
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	/* USART1使能 */
	USART_Cmd(USART1, ENABLE);
}

void USART_SendByte(USART_TypeDef* pUSARTx, uint8_t ch)
{
	/* 发送一个字节到USART发送数据寄存器 */
	USART_SendData(pUSARTx, ch);
	
	/* 等待发送数据寄存器为空 */
	while(USART_GetFlagStatus(pUSARTx,USART_FLAG_TXE) == RESET);
}

void USART_SendString(USART_TypeDef* pUSARTx, char* str)
{
	unsigned int k = 0;
	do{
		USART_SendData(pUSARTx, *(str+k));
		k++;
	}while(*(str+k)!='\0');
	
	while(USART_GetFlagStatus(pUSARTx,USART_FLAG_TC) == RESET);
}
