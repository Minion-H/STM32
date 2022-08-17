#ifndef STM32F407xx_H
#define STM32F407xx_H

#define GPIOF_BASE     (unsigned int)0x40021400
#define RCC_BASE       (unsigned int)0x40023800
//	
//#define GPIOF_MODER    *(unsigned int *)(GPIOF_BASE+0x00)
//#define GPIOF_OTYPER   *(unsigned int *)(GPIOF_BASE+0x04)
//#define GPIOF_ODR      *(unsigned int *)(GPIOF_BASE+0x14)

//#define RCC_AHB1ENR    *(unsigned int *)(RCC_BASE+0x30)

#define  __IO volatile  //易变变量防止被编译器优化
typedef unsigned int   uint32_t;
typedef unsigned short uint16_t;

//GPIO 寄存器列表
typedef struct{
	
	__IO uint32_t MODER;
	__IO uint32_t OTYPER;
	__IO uint32_t OSPEEDR;
	__IO uint32_t PUPDR;
	__IO uint32_t IDR;
	__IO uint32_t ODR;
	__IO uint16_t BSRRL;
	__IO uint16_t BSRRH;
	__IO uint32_t LCKR;
	__IO uint32_t AFR[2];

}GPIO_TypeDef;

//RCC 寄存器列表
typedef struct {
	
	__IO uint32_t CR; /*!< RCC 时钟控制寄存器, 地址偏移:? , →0x00 */
	__IO uint32_t PLLCFGR; /*!< RCC PLL 配置寄存器, 地址偏移:? , →0x04 */
	__IO uint32_t CFGR; /*!< RCC 时钟配置寄存器, 地址偏移:? , →0x08 */
	__IO uint32_t CIR; /*!< RCC 时钟中断寄存器, 地址偏移:? , →0x0C */
	__IO uint32_t AHB1RSTR; /*!< RCC AHB1 外设复位寄存器, 地址偏移:? , →0x10 */
	__IO uint32_t AHB2RSTR; /*!< RCC AHB2 外设复位寄存器, 地址偏移:? , →0x14 */
	__IO uint32_t AHB3RSTR; /*!< RCC AHB3 外设复位寄存器, 地址偏移:? , →0x18 */
	__IO uint32_t RESERVED0; /*!< 保留, 地址偏移：0x1C */
	__IO uint32_t APB1RSTR; /*!< RCC APB1 外设复位寄存器, 地址偏移:? , →0x20 */
	__IO uint32_t APB2RSTR; /*!< RCC APB2 外设复位寄存器, 地址偏移:? , →0x24 */
	__IO uint32_t RESERVED1[2]; /*!< 保留, 地址偏移：0x28-,→0x2C*/
	__IO uint32_t AHB1ENR; /*!< RCC AHB1 外设时钟寄存器, 地址偏移:? , →0x30 */
	__IO uint32_t AHB2ENR; /*!< RCC AHB2 外设时钟寄存器, 地址偏移:? , →0x34 */
	__IO uint32_t AHB3ENR; /*!< RCC AHB3 外设时钟寄存器, 地址偏移:? , →0x38 */
 /*RCC 后面还有很多寄存器，此处省略 */
	
}RCC_TypeDef;

//定义 GPIOF 寄存器结构体指针
#define GPIOF     ((GPIO_TypeDef *)GPIOF_BASE)

//定义 RCC外设 寄存器结构体指针
#define RCC 			((RCC_TypeDef *)RCC_BASE)

#endif
