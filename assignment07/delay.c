#include "delay.h"

uint32_t delayInMilliseconds;
extern uint32_t MilliSecond;

void delay(uint32_t delayInMilliseconds)

{
    MilliSecond = delayInMilliseconds;
    while (MilliSecond > 0)
    {
        // exit when 1000 SysTick interrup hit (~ 1 sec)
    }
}
