#ifndef SYSTICK_H_
#define SYSTICK_H_

#include "stdint.h"
#include "stm32f1xx.h"

#define SYSTICK_LOAD                (8000)
#define CSR_EN                      (1U<<0)
#define CSR_CLKSRC                  (1U<<2)
#define CSR_COUNTFLAG               (1U<<16)

void SYSTICK_DelayMS(int delay);

#endif