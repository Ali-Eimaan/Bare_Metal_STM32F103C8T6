#include "SPI.h"

uint8_t BUFF[8] = {0x48, 0x44, 0x88, 0x84, 0xE4, 0xE8, 0xEE, 0x8E};

int main(void)
{
    SPI_GPIO_init();
    SPI_Config();
    SPI1_Transmit(BUFF, sizeof(BUFF));

    while (1);
}