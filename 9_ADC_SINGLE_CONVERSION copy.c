#include "ADC.h"

uint32_t ADC;

int main(void)
{
    PA4_ADC_INIT();
    while (1)
    {
        Start_Conversion();
        ADC = ADC_Read();
    }
}