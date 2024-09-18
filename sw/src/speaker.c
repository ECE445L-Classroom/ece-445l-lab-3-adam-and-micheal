

#include "speaker.h"

void SwitchD0_Init(void){
		SYSCTL_RCGCGPIO_R |= 0x10; // enable port e clock
		GPIO_PORTD_DEN_R |= 0x01;  // Enable PORTE Pin0 as digital pin
		GPIO_PORTD_DIR_R |= 0x01; // Enable PORTE Pin0 as an output pin
}

void toggleD0(void){
	*GPIO_PORTD_DATA_PIN0 ^= 0x1;
}

void startAlarm(){
	Timer1A_Init(toggleD0, 40000, 6);
}

void stopAlarm(){
 Timer1A_Stop();
}
	

