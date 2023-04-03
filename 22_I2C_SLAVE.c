#include "I2C.h"

uint8_t BUFF[8] = {0x48, 0x44, 0x88, 0x84, 0xE4, 0xE8, 0xEE, 0x8E};

int main(void)
{
    I2C1_Slave_init_Interrupt();

    while (1);
}

void I2C1_EV_IRQHandler(void)
{
    if (I2C1->SR1 & I2CTXE)
        I2C1_SLave_Write(sizeof(BUFF), BUFF);
    else
        I2C1_Slave_Read(sizeof(BUFF), BUFF);
}