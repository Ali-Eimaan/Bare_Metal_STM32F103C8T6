#include "UART.h"
#include "SYSTICK.h"

#define GPIOCEN                 (1U<<4)
#define PIN13                   (1U<<13)

uint8_t count = 0;

int main()
{
    RCC->APB2ENR |= GPIOCEN;

    GPIOC->CRH |= (1U<<20);
    GPIOC->CRH |= (1U<<21);
    GPIOC->CRH &=~ (1U<<22);
    GPIOC->CRH &=~ (1U<<23);

    Uart1RxInterruptInit();
    while (1){}
}

void USART1_IRQHandler(void)
{
    if(USART1->SR & SR_RXNE)
        count = USART1->DR;
    for (int i = 0; i <= count; i++)
    {
        GPIOC->ODR ^= PIN13;
        SYSTICK_DelayMS(100);
    }
}