#include "I2C.h"

uint8_t BUFF[8] = {0x48, 0x44, 0x88, 0x84, 0xE4, 0xE8, 0xEE, 0x8E};

int main(void)
{
    I2C1_init();

    I2C1_burstWrite(0xE8, 0x88, sizeof(BUFF), (char*) BUFF);

    while (1);
}
