#include "SYSTICK.h"

void SYSTICK_DelayMS(int delay)
{
    SysTick->LOAD = SYSTICK_LOAD;
    SysTick->VAL = 0;
    SysTick->CTRL = CSR_EN | CSR_CLKSRC;
    for (int i = 0; i < delay; i++)
        while ((SysTick->CTRL & CSR_COUNTFLAG) == 0);
    SysTick->CTRL = 0;
}