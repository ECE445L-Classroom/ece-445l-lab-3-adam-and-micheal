

#ifndef LCD_H
#define LCD_H
#include "stdint.h"
#include "../inc/ST7735.h"
#include "../inc/tm4c123gh6pm.h"
#include "SysTick.h"

struct {
	uint16_t backgroundColor;
	uint16_t setAlarmColor;
	uint16_t setTimeColor;
	uint16_t DClockColor;
	time_t DTime;
	time_t ATime;
	uint8_t showMessage;	
	char message[30];
} typedef screenInputs_t;


void drawEntireScreen(screenInputs_t inputs);


#endif