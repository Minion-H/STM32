#define GPIOF_BASE     (unsigned int)0x40021400
#define RCC_BASE       (unsigned int)0x40023800
	
#define GPIOF_MODER    *(unsigned int *)(GPIOF_BASE+0x00)
#define GPIOF_OTYPER   *(unsigned int *)(GPIOF_BASE+0x04)
#define GPIOF_ODR      *(unsigned int *)(GPIOF_BASE+0x14)

#define RCC_AHB1ENR    *(unsigned int *)(RCC_BASE+0x30)
