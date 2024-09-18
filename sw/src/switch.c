

#include "switch.h"


void SwitchE0_Init(void){
		SYSCTL_RCGCGPIO_R |= 0x10; // enable port e clock
		GPIO_PORTE_DEN_R |= 0x01;  // Enable PORTE Pin0 as digital pin
		GPIO_PORTE_PDR_R |= 0x01; // enable pulldown resistor on PE0
}
uint32_t SwitchE0_In(void){
  // write something that reads the state of the GPIO pin as required
  return (*GPIO_PORTE_DATA_PIN0); // read the input pin at porte pin0
}

void SwitchE1_Init(void){
		SYSCTL_RCGCGPIO_R |= 0x10; // enable port e clock
		GPIO_PORTE_DEN_R |= 0x02;  // Enable PORTE Pin1 as digital pin
		GPIO_PORTE_PDR_R |= 0x02; // enable pulldown resistor on PE1
}
uint32_t SwitchE1_In(void){
  // write something that reads the state of the GPIO pin as required
  return (*GPIO_PORTE_DATA_PIN1) >> 1; // read the input pin at porte pin1
}

void SwitchE2_Init(void){
		SYSCTL_RCGCGPIO_R |= 0x10; // enable port e clock
		GPIO_PORTE_DEN_R |= 0x04;  // Enable PORTE Pin2 as digital pin
		GPIO_PORTE_PDR_R |= 0x04; // enable pulldown resistor on PE2
}
uint32_t SwitchE2_In(void){
  // write something that reads the state of the GPIO pin as required
  return (*GPIO_PORTE_DATA_PIN2) >> 2; // read the input pin at porte pin2
}

void SwitchE3_Init(void){
		SYSCTL_RCGCGPIO_R |= 0x10; // enable port e clock
		GPIO_PORTE_DEN_R |= 0x08;  // Enable PORTE Pin3 as digital pin
		GPIO_PORTE_PDR_R |= 0x08; // enable pulldown resistor on PE3
}
uint32_t SwitchE3_In(void){
  // write something that reads the state of the GPIO pin as required
  return (*GPIO_PORTE_DATA_PIN3) >> 3; // read the input pin at porte pin3
}

void SwitchE4_Init(void){
		SYSCTL_RCGCGPIO_R |= 0x10; // enable port e clock
		GPIO_PORTE_DEN_R |= 0x10;  // Enable PORTE Pin4 as digital pin
		GPIO_PORTE_PDR_R |= 0x10; // enable pulldown resistor on PE4
}
uint32_t SwitchE4_In(void){
  // write something that reads the state of the GPIO pin as required
  return (*GPIO_PORTE_DATA_PIN4) >> 4; // read the input pin at porte pin4
}

/*
Enable all of the switches
*/
void allSwitchInit(void){
	SwitchE0_Init();
	SwitchE1_Init();
	SwitchE2_Init();
	SwitchE3_Init();
	SwitchE4_Init();
}

uint32_t SwitchE01234_In(void){
	
	return (*GPIO_PE01234); // reutrns the current value of all the switches for port e
}

/*
Used obtain a particular pin from a bit banded number
@Param pin what pin number you want
@Param input the bit banded number
@return an u8bit binary value for that specific pin
*/

uint8_t regPinSelect(uint8_t pin, uint32_t input){
	return input >> pin;
}


