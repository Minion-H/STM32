#ifndef STM32F407xx_GPIO_H
#define STM32F407xx_GPIO_H

#include "stm32f4xx.h"

#define GPIO_Pin0          ((uint16_t)0x0001)
#define GPIO_Pin1          ((uint16_t)0x0002)
#define GPIO_Pin2          ((uint16_t)0x0004)
#define GPIO_Pin3          ((uint16_t)0x0008)
#define GPIO_Pin4          ((uint16_t)0x0010)
#define GPIO_Pin5          ((uint16_t)0x0020)
#define GPIO_Pin6          ((uint16_t)0x0040)
#define GPIO_Pin7  				 ((uint16_t)0x0080)
#define GPIO_Pin_8         ((uint16_t)0x0100)  /*!< 选择Pin8 */
#define GPIO_Pin_9         ((uint16_t)0x0200)  /*!< 选择Pin9 */
#define GPIO_Pin_10        ((uint16_t)0x0400)  /*!< 选择Pin10 */
#define GPIO_Pin_11        ((uint16_t)0x0800)  /*!< 选择Pin11 */
#define GPIO_Pin_12        ((uint16_t)0x1000)  /*!< 选择Pin12 */
#define GPIO_Pin_13        ((uint16_t)0x2000)  /*!< 选择Pin13 */
#define GPIO_Pin_14        ((uint16_t)0x4000)  /*!< 选择Pin14 */
#define GPIO_Pin_15        ((uint16_t)0x8000)  /*!< 选择Pin15 */
#define GPIO_Pin_All       ((uint16_t)0xFFFF)  /*!< 选择全部引脚 */

typedef enum{

  GPIO_Mode_IN   = 0x00, /*!< 输入模式 */
  GPIO_Mode_OUT  = 0x01, /*!< 输出模式 */
  GPIO_Mode_AF   = 0x02, /*!< 复用模式 */
  GPIO_Mode_AN   = 0x03  /*!< 模拟模式 */
	
}GPIOMode_TypeDef;


typedef enum
{ 
  GPIO_OType_PP = 0x00,	/*!< 推挽模式 */
  GPIO_OType_OD = 0x01	/*!< 开漏模式 */
}GPIOOType_TypeDef;


typedef enum
{ 
  GPIO_Speed_2MHz   = 0x00, /*!< 2MHz   */
  GPIO_Speed_25MHz  = 0x01, /*!< 25MHz  */
  GPIO_Speed_50MHz  = 0x02, /*!< 50MHz  */
  GPIO_Speed_100MHz = 0x03  /*!<100MHz  */
}GPIOSpeed_TypeDef;


typedef enum
{ 
  GPIO_PuPd_NOPULL = 0x00,/*浮空*/
  GPIO_PuPd_UP     = 0x01, /*上拉*/
  GPIO_PuPd_DOWN   = 0x02  /*下拉*/
}GPIOPuPd_TypeDef;


typedef struct{
	
	uint32_t GPIO_Pin;
	GPIOMode_TypeDef GPIO_Mode;
	GPIOSpeed_TypeDef GPIO_Speed;
	GPIOOType_TypeDef GPIO_OType;
	GPIOPuPd_TypeDef GPIO_PuPd;
	
}GPIO_InitTypeDef;

void GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_InitStruct);
void GPIO_SetBits(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void GPIO_ResetBits(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

#endif
