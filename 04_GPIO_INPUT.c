#include "stm32f1xx.h"

#define GPIOCEN                 (1U<<4)
#define PIN13                   (1U<<13)

#define GPIOAEN                 (1U<<2)
#define PIN8                    (1U<<8)

int main(void)
{
    RCC->APB2ENR |= GPIOCEN;
    RCC->APB2ENR |= GPIOAEN;

    GPIOC->CRH |= (1U<<20);
    GPIOC->CRH |= (1U<<21);
    GPIOC->CRH &= ~(1U<<22);
    GPIOC->CRH &= ~(1U<<23);

    GPIOA->CRH &= ~(1U<<0);
    GPIOA->CRH &= ~(1U<<1);
    GPIOA->CRH &= ~(1U<<2);
    GPIOA->CRH |= (1U<<3);

    while(1)
    {
        if(GPIOA->IDR & PIN8)
            GPIOC->BSRR = (1U<<29)
        else
            GPIOC->BSRR = PIN13;
    }
}