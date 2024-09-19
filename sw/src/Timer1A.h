
#ifndef TIMER1A_H
#define TIMER1A_H
#include "stdint.h"

void Timer1A_Init(void(*task)(void), uint32_t period, uint32_t priority);
void Timer1A_Stop(void);

#endif