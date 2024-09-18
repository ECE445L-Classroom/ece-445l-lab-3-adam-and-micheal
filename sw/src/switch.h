

#ifndef SWITCH_H
#define SWITCH_H
#include "stdint.h"
#include "../inc/tm4c123gh6pm.h"
#define GPIO_PORTE_DATA_PIN0 ((volatile uint32_t *)0x40024004) // bit band for PORTE pin3
#define GPIO_PORTE_DATA_PIN1 ((volatile uint32_t *)0x40024008) // bit band for PORTE pin3
#define GPIO_PORTE_DATA_PIN2 ((volatile uint32_t *)0x40024010) // bit band for PORTE pin3
#define GPIO_PORTE_DATA_PIN3 ((volatile uint32_t *)0x40024020) // bit band for PORTE pin3
#define GPIO_PORTE_DATA_PIN4 ((volatile uint32_t *)0x40024040) // bit band for PORTE pin3
#define GPIO_PE01234 ((volatile uint32_t *)0x4002407C) // bit band for PORTE pins 0-4
#define GPIO_PORTC_DATA_PIN5   ((volatile uint32_t *)0x40006080) // bit band for PORTC pin5


void SwitchE0_Init(void);
void SwitchE1_Init(void);
void SwitchE2_Init(void);
void SwitchE3_Init(void);
void SwitchE4_Init(void);

uint32_t SwitchE0_In(void);
uint32_t SwitchE1_In(void);
uint32_t SwitchE2_In(void);
uint32_t SwitchE3_In(void);
uint32_t SwitchE4_In(void);

void allSwitchInit(void);
uint32_t SwitchE01234_In(void);

uint8_t regPinSelect(uint8_t pin, uint32_t input);

#endif