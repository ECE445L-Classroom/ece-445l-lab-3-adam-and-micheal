

#include "speaker.h"

void SwitchD0_Init(void){
		SYSCTL_RCGCGPIO_R |= 0x10; // enable port e clock
		GPIO_PORTD_DEN_R |= 0x01;  // Enable PORTE Pin0 as digital pin
		GPIO_PORTD_DIR_R |= 0x01; // Enable PORTE Pin0 as an output pin
}

void toggleD0(void){
	
	
}