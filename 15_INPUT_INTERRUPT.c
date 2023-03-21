#include "EXTI.h"

#define GPIOCEN                 (1U<<4)
#define PIN13                   (1U<<13)

int main(void)
{
    RCC->APB2ENR |= GPIOCEN;

    GPIOC->CRH |= (1U<<20);
    GPIOC->CRH |= (1U<<21);
    GPIOC->CRH &=~ (1U<<22);
    GPIOC->CRH &=~ (1U<<23);

    PA8_EXTI_INIT();

    while (1){}
}

void EXTI9_5_IRQHandler(void)
{
    if (EXTI->PR & LINE8)
    {
        EXTI->PR |= LINE8;
        GPIOC->ODR ^= PIN13;
    }
}