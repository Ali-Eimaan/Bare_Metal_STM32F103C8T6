#include "ADXL345.h"

uint8_t ADXL_Data[6];
int16_t x,y,z;
float xg,yg,zg;
const float FOURG_SCALE_FACT = 0.0078;

int main(void)
{
    ADXL_init();

    while(1)
    {
        ADXL_Read(DATASTART, ADXL_Data);

        x = ((ADXL_Data[1]<<8) | ADXL_Data[0]);
        y = ((ADXL_Data[3]<<8) | ADXL_Data[2]);
        z = ((ADXL_Data[5]<<8) | ADXL_Data[4]);

        xg = x * FOURG_SCALE_FACT;
        yg = y * FOURG_SCALE_FACT;
        zg = z * FOURG_SCALE_FACT;
    }
}
