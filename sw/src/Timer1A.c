#include <stdint.h>
#include "Timer1A.h"
#include "../inc/tm4c123gh6pm.h"
#include "../inc/CortexM.h"

#define NVIC_EN0_INT21          0x00200000  // Interrupt 19 enable
#define TIMER_CFG_16_BIT        0x00000004  // 16-bit timer configuration,
                                            // function is controlled by bits
                                            // 1:0 of GPTMTAMR and GPTMTBMR
#define TIMER_TAMR_TACDIR       0x00000010  // GPTM Timer A Count Direction
#define TIMER_TAMR_TAMR_PERIOD  0x00000002  // Periodic Timer mode
#define TIMER_CTL_TAEN          0x00000001  // GPTM TimerA Enable
#define TIMER_IMR_TATOIM        0x00000001  // GPTM TimerA Time-Out Interrupt
                                            // Mask
#define TIMER_ICR_TATOCINT      0x00000001  // GPTM TimerA Time-Out Raw
                                            // Interrupt
#define TIMER_TAILR_TAILRL_M    0x0000FFFF  // GPTM TimerA Interval Load
                                            // Register Low


void (*PeriodicTask1)(void);   // user function

// ***************** Timer0A_Init ****************
// Activate Timer0A interrupts to run user task periodically
// Inputs:  task is a pointer to a user function
//          period in 12.5ns units
//          priority 0 (highest) to 7 (lowest)
// Outputs: none
void Timer1A_Init(void(*task)(void), uint32_t period, uint32_t priority){
  SYSCTL_RCGCTIMER_R |= 0x02;      // 0) activate timer1
  PeriodicTask1 = task;            // user function (this line also allows time to finish activating)
  TIMER1_CTL_R = 0x00000000;     // 1) disable timer1A during setup
  TIMER1_CFG_R = 0x00000000;       // 2) configure for 32-bit timer mode
  TIMER1_TAMR_R = 0x00000002;      // 3) configure for periodic mode, default down-count settings
  TIMER1_TAILR_R = period-1;       // 4) reload value
  TIMER1_TAPR_R = 0;               // 5) 12.5ns timer1A
  TIMER1_ICR_R = 0x00000001;       // 6) clear timer1A timeout flag
  TIMER1_IMR_R |= 0x00000001;      // 7) arm timeout interrupt
  NVIC_PRI4_R = (NVIC_PRI4_R&0x00FFFFFF)|(priority<<29); 
  NVIC_EN0_R = NVIC_EN0_INT21;     // 9) enable interrupt 21 in NVIC
  TIMER1_CTL_R |= 0x00000001;      // 10) enable timer1A
}

void Timer1A_Handler(void){
  TIMER0_ICR_R = TIMER_ICR_TATOCINT;// acknowledge timer1A timeout
  (*PeriodicTask1)();                // execute user task
}
void Timer1A_Stop(void){
  NVIC_EN0_R = 1<<21;            // 9) disable interrupt 21 in NVIC
  TIMER0_CTL_R = 0x00000000;     // 10) disable timer1A
}

