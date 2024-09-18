

#ifndef SYSTICK_H
#define SYSTICK_H
#include "../inc/Timer0A.h"

struct {
uint8_t hour;
uint8_t minute;
uint8_t second;	
} typedef time_t;

void enableTimer(void);
void stopTimer(void);



#endif