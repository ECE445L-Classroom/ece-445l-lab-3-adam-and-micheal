

#ifndef TIMER2A_H
#define TIMER2A_H
#include "stdint.h"
#include "../inc/tm4c123gh6pm.h"

void Timer2A_Init(void(*task)(void),uint32_t period, uint32_t priority);
void Timer2A_Stop(void);


#endif