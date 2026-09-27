#include<stdint.h>
//
//int main(void)
//{
//	volatile uint32_t *GPIOC_CLOCK=(volatile uint32_t *)0x40023830;
//	*GPIOC_CLOCK=(1<<2); //bit 2
//
//	volatile uint32_t *GPIOC_MODE=(volatile uint32_t *)0x40020800;
//	*GPIOC_MODE=(1<<26);
//
//	volatile uint32_t *GPIOC_ODR=(volatile uint32_t *)0x40020814;
//	while(1)
//	{
//	*GPIOC_ODR^=(1<<13);
//	for(uint32_t time=0; time<1000000; time++);
//	}
//}

#define RCC_BASE 0X40023800UL
#define RCC_AHB1ENR_OFFSET 0X30UL

#define GPIOC_BASE 0X40020800UL
//#define GPIO_MODER_OFFSET 0X00UL
//#define GPIO_OTYPER_OFFSET 0X04UL
//#define GPIO_OSPEEDR_OFFSET 0X08UL
//#define GPIO_PUPDR_OFFSET 0X0CUL
//#define GPIO_IDR_OFFSET 0X10UL
//#define GPIO_ODR_OFFSET 0X14UL


#define RCC_AHB1ENR (*((volatile uint32_t *)(RCC_BASE + RCC_AHB1ENR_OFFSET)))
//
//#define GPIO_MODER  (*((volatile uint32_t *)(GPIOC_BASE + GPIO_MODER_OFFSET)))
//#define GPIO_OTYPER (*((volatile uint32_t *)(GPIOC_BASE + GPIO_OTYPER_OFFSET)))
//#define GPIO_OSPEEDR (*((volatile uint32_t *)(GPIOC_BASE + GPIO_OSPEEDR_OFFSET)))
//#define GPIO_PUPDR (*((volatile uint32_t *)(GPIOC_BASE + GPIO_PUPDR_OFFSET)))
//#define GPIO_IDR (*((volatile uint32_t *)(GPIOC_BASE + GPIO_IDR_OFFSET)))
//#define GPIO_ODR (*((volatile uint32_t *)(GPIOC_BASE + GPIO_ODR_OFFSET)))

typedef struct {
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
}GPIO_TypeDef;

#define GPIOC ((GPIO_TypeDef *)GPIOC_BASE)

int main(){
	RCC_AHB1ENR|=(1<<2);
	GPIOC->MODER|=(1<<26);

	while(1){
		GPIOC->ODR^=(1<<13);
		for(uint32_t time=0; time<2500000; time++);
	}
}
