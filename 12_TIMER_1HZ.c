#include "TIMER.h"

#define GPIOCEN                 (1U<<4)
#define PIN13                   (1U<<13)

int main(void)
{
    RCC->APB2ENR |= GPIOCEN;

    GPIOC->CRH |= (1U<<20);
    GPIOC->CRH |= (1U<<21);
    GPIOC->CRH &= ~(1U<<22);
    GPIOC->CRH &= ~(1U<<23);

    tim4_1hz_init();

    while (1)
    {
        GPIOC->ODR ^= PIN13;
        while (!(TIM4->SR & SR_UIF));
        TIM4->SR &= ~(SR_UIF);
    }
}