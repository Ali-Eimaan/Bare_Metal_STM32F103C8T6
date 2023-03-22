#include "SYSTICK.h"

#define GPIOCEN                 (1U<<4)
#define PIN13                   (1U<<13)

int main(void)
{
    RCC->APB2ENR |= GPIOCEN;

    GPIOC->CRH |= (1U<<20);
    GPIOC->CRH |= (1U<<21);
    GPIOC->CRH &=~ (1U<<22);
    GPIOC->CRH &=~ (1U<<23);

    SYSTICK_1Hz_Interrupt();
    
    while (1){}
}

void SysTick_Handler(void)
{
    GPIOC->ODR ^= PIN13;
}