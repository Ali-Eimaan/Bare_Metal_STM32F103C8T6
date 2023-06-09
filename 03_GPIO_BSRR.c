#include "stm32f1xx.h"

#define GPIOCEN                 (1U<<4)
#define PIN13                   (1U<<13)

int main(void)
{
    RCC->APB2ENR |= GPIOCEN;

    GPIOC->CRH |= (1U<<20);
    GPIOC->CRH |= (1U<<21);
    GPIOC->CRH &= ~(1U<<22);
    GPIOC->CRH &= ~(1U<<23);

    while(1)
    {
        GPIOC->BSRR = PIN13;
        for (int i = 0; i < 1000000; i++);
        GPIOC->BSRR = (1U<<29);
        for (int i = 0; i < 1000000; i++);
    }
}