#include "UART.h"

static uint16_t compute_baud_rate(uint32_t PeriphClk, uint32_t BaudRate)
{
    return ((PeriphClk + (BaudRate/2U))/BaudRate);
}

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate)
{
    USARTx->BRR = compute_baud_rate(PeriphClk, BaudRate);
}

void Uart1Init(void)
{
    RCC->APB2ENR |= GPIOAEN;
    RCC->APB2ENR |= USART1EN;
    RCC->APB2ENR |= AFIOEN;

    GPIOA->CRH |= (1U<<4); 
    GPIOA->CRH |= (1U<<5); 
    GPIOA->CRH |= (1U<<7);
    GPIOA->CRH &=~ (1U<<6);  

    GPIOA->CRH &=~ (1U<<8); 
    GPIOA->CRH &=~ (1U<<9); 
    GPIOA->CRH |= (1U<<10);
    GPIOA->CRH &=~ (1U<<11); 

    AFIO->MAPR &=~ (1U<<2);

    uart_set_baudrate(USART1, APB2_CLK, BAUDRATE);

    USART1->CR1 = (CR1_TE | CR1_RE);
    USART1->CR1 |= CR1_UE;
}

void Uart1RxInterruptInit(void)
{
    RCC->APB2ENR |= GPIOAEN;
    RCC->APB2ENR |= USART1EN;
    RCC->APB2ENR |= AFIOEN;

    GPIOA->CRH |= (1U<<4); 
    GPIOA->CRH |= (1U<<5); 
    GPIOA->CRH |= (1U<<7);
    GPIOA->CRH &=~ (1U<<6);  

    GPIOA->CRH &=~ (1U<<8); 
    GPIOA->CRH &=~ (1U<<9); 
    GPIOA->CRH |= (1U<<10);
    GPIOA->CRH &=~ (1U<<11); 

    AFIO->MAPR &=~ (1U<<2);

    uart_set_baudrate(USART1, APB2_CLK, BAUDRATE);

    USART1->CR1 = (CR1_TE | CR1_RE);
    USART1->CR1 |= CR1_RXNEIE;
    NVIC_EnableIRQ(USART1_IRQn);
    USART1->CR1 |= CR1_UE;
}

void uart1_write(int ch)
{
    while(!(USART1->SR & SR_TXE)){};
    USART1->DR = (ch & 0xFF);
}

int __io_putchar(int ch)
{
    uart1_write(ch);
    return ch;
}

char uart1_read(void)
{
    while(!(USART1->SR & SR_RXNE)){};
    return USART1->DR;
}
