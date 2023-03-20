#include "TIMER.h"

#define GPIOCEN                 (1U<<4)
#define PIN13                   (1U<<13)

#define GPIOAEN                 (1U<<2)
#define PIN4                    (1U<<4)

int main(void)
{
    RCC->APB2ENR |= GPIOCEN;
    RCC->APB2ENR |= GPIOAEN;

    GPIOC->CRH |= (1U<<20);
    GPIOC->CRH |= (1U<<21);
    GPIOC->CRH &=~ (1U<<22);
    GPIOC->CRH &=~ (1U<<23);

    GPIOA->CRL &=~ (1U<<16);
    GPIOA->CRL &=~ (1U<<17);
    GPIOA->CRL &=~ (1U<<18);
    GPIOA->CRL |= (1U<<19);

    tim4_PB8_output_compare();

    while(1)
    {
        if(GPIOA->IDR & PIN4)
            GPIOC->BSRR = (1U<<29);
        else
            GPIOC->BSRR = PIN13;
    }
}
