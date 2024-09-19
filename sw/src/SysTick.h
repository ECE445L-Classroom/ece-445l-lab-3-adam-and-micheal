

#ifndef SYSTICK_H
#define SYSTICK_H
#include "../inc/Timer0A.h"
#include "../inc/tm4c123gh6pm.h"
#include "Timer2A.h"

#define GPIO_B1 ((volatile uint32_t *)0x40005008)

struct {
uint8_t hour;
uint8_t minute;
uint8_t second;	
} typedef time_t;

void enableTimer(void);
void stopTimer(void);

void enableHeartbeat(void);
void stopHeartbeat(void);

#endif