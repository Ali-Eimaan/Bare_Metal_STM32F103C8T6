#include "UART.h"

int main (void)
{
    Uart1Init();
    printf("Hello From Bluepill...............\n\r");
    while (1);
}