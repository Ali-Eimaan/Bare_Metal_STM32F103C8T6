#include "stdint.h"
#include "stm32f1xx.h"

#define USART1EN            (1U<<14)
#define GPIOAEN             (1U<<2)
#define AFIOEN              (1U<<0)

#define CR1_TE              (1U<<3)
#define CR1_UE              (1U<<13)
#define SR_TXE              (1U<<7)

#define SYS_FREQ            8000000
#define APB2_CLK            SYS_FREQ

#define BAUDRATE            115200

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

    AFIO->MAPR &=~ (1U<<2);

    uart_set_baudrate(USART1, APB2_CLK, BAUDRATE);

    USART1->CR1 = CR1_TE;
    USART1->CR1 |= CR1_UE;
}

void uart1_write(int ch)
{
    while(!(USART1->SR & SR_TXE)){};
    USART1->DR = (ch & 0xFF);
}

int main()
{
    Uart1Init();
    uart1_write('X');
    while (1){}
}
