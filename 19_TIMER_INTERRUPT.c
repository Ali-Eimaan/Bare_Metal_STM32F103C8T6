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

    tim4_1hz_interrupt();

    while (1);
}

void TIM4_IRQHandler(void)
{
    TIM4->SR &= ~SR_UIF;
    GPIOC->ODR ^= PIN13;
}