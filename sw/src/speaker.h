

#ifndef SPEAKER_H
#define SPEAKER_H
#include "stdint.h"
#include "../inc/tm4c123gh6pm.h"
#include "Timer1A.c"
#define GPIO_PORTD_DATA_PIN0 ((volatile uint32_t *)0x40007004) // bit band for PORTD pin0

void SwitchD0_Init(void);
void startAlarm();
void stopAlarm();

#endif