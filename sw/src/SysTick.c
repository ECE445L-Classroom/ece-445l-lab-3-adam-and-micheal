

#include "SysTick.h"
/*
Struct that holds the current time
*/
volatile time_t currTime = {0, 0 ,0};

void timerInterrupt(void);

/*
A timer that calls its interrupt function once every second
*/
void enableTimer(void){
	Timer0A_Init(timerInterrupt, 80000000, 5);	
}

void stopTimer(void){
	Timer0A_Stop();
}


void timerInterrupt(){
	++currTime.second;
	if (currTime.second == 60){
		currTime.second = 0;
	  ++currTime.minute;
		if (currTime.minute == 60){
			currTime.minute = 0;
			++currTime.hour;
			if (currTime.hour == 24){
				currTime.hour = 0;
			}		
		}	
	}	
}