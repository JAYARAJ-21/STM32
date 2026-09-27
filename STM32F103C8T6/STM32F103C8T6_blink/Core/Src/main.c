#include "stm32f1xx.h"


void delay(volatile uint32_t t)
{
    while(t--);
}


int main()
{   //GPIOC clock enable
	RCC->APB2ENR |= (1<<4); // 0000 0000 0000 0000 0000 0000 00001 0000

	//configure GPIOC 13 - output push pull mode and 2MHz speed
    GPIOC->CRH |=0X00100000;

    //Toggle GPIO 13
    while(1)
    {
    	GPIOC->ODR ^= (1<<13);
    }
}
