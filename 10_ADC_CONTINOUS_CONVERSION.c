#include "ADC.h"

uint32_t ADC;

int main(void)
{
    PA4_ADC_INIT();
    Start_Conversion_Continous();
    while (1)
    {
        ADC = ADC_Read();
    }
}