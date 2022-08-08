#ifndef STM32F407xx_H
#define STM32F407xx_H

#define GPIOF_BASE     (unsigned int)0x40021400
#define RCC_BASE       (unsigned int)0x40023800
//	
//#define GPIOF_MODER    *(unsigned int *)(GPIOF_BASE+0x00)
//#define GPIOF_OTYPER   *(unsigned int *)(GPIOF_BASE+0x04)
//#define GPIOF_ODR      *(unsigned int *)(GPIOF_BASE+0x14)

//#define RCC_AHB1ENR    *(unsigned int *)(RCC_BASE+0x30)

#define  __IO volatile  //�ױ������ֹ���������Ż�
typedef unsigned int   uint32_t;
typedef unsigned short uint16_t;

//GPIO �Ĵ����б�
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

//RCC �Ĵ����б�
typedef struct {
	
	__IO uint32_t CR; /*!< RCC ʱ�ӿ��ƼĴ���, ��ַƫ��:? , ��0x00 */
	__IO uint32_t PLLCFGR; /*!< RCC PLL ���üĴ���, ��ַƫ��:? , ��0x04 */
	__IO uint32_t CFGR; /*!< RCC ʱ�����üĴ���, ��ַƫ��:? , ��0x08 */
	__IO uint32_t CIR; /*!< RCC ʱ���жϼĴ���, ��ַƫ��:? , ��0x0C */
	__IO uint32_t AHB1RSTR; /*!< RCC AHB1 ���踴λ�Ĵ���, ��ַƫ��:? , ��0x10 */
	__IO uint32_t AHB2RSTR; /*!< RCC AHB2 ���踴λ�Ĵ���, ��ַƫ��:? , ��0x14 */
	__IO uint32_t AHB3RSTR; /*!< RCC AHB3 ���踴λ�Ĵ���, ��ַƫ��:? , ��0x18 */
	__IO uint32_t RESERVED0; /*!< ����, ��ַƫ�ƣ�0x1C */
	__IO uint32_t APB1RSTR; /*!< RCC APB1 ���踴λ�Ĵ���, ��ַƫ��:? , ��0x20 */
	__IO uint32_t APB2RSTR; /*!< RCC APB2 ���踴λ�Ĵ���, ��ַƫ��:? , ��0x24 */
	__IO uint32_t RESERVED1[2]; /*!< ����, ��ַƫ�ƣ�0x28-,��0x2C*/
	__IO uint32_t AHB1ENR; /*!< RCC AHB1 ����ʱ�ӼĴ���, ��ַƫ��:? , ��0x30 */
	__IO uint32_t AHB2ENR; /*!< RCC AHB2 ����ʱ�ӼĴ���, ��ַƫ��:? , ��0x34 */
	__IO uint32_t AHB3ENR; /*!< RCC AHB3 ����ʱ�ӼĴ���, ��ַƫ��:? , ��0x38 */
 /*RCC ���滹�кܶ�Ĵ������˴�ʡ�� */
	
}RCC_TypeDef;

//���� GPIOF �Ĵ����ṹ��ָ��
#define GPIOF     ((GPIO_TypeDef *)GPIOF_BASE)

//���� RCC���� �Ĵ����ṹ��ָ��
#define RCC 			((RCC_TypeDef *)RCC_BASE)

#endif
