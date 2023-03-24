#include "UART.h"

#define GPIOCEN                 (1U<<4)
#define PIN13                   (1U<<13)

uint8_t BUFF[8] = {0x48, 0x44, 0x88, 0x84, 0xE4, 0xE8, 0xEE, 0x8E};

int main()
{
    RCC->APB2ENR |= GPIOCEN;

    GPIOC->CRH |= (1U<<20);
    GPIOC->CRH |= (1U<<21);
    GPIOC->CRH &=~ (1U<<22);
    GPIOC->CRH &=~ (1U<<23);

    Uart1Init();

    DMA1_Channel4_INIT((uint32_t) BUFF, (uint32_t) USART1->DR, sizeof(BUFF));

    while (1){}
}

void DMA1_Channel4_IRQHandler(void)
{
    if(DMA1->ISR & DMA1TCIF)
    {
        DMA1->IFCR |= DMA1IFCR;
        GPIOC->ODR ^= PIN13;
    }
}