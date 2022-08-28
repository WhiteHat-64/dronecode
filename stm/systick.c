/*
 * cortexm3_systick.c
 *
 *  Created on: Sep 6, 2021
 *      Author: Golden Eagle
 */

#include "systick.h"

_REG SYSTICK_t *SYSTICK = (SYSTICK_t *)SYSTICK_REG_ADDR;
_REG U32_t systick_ms = 0;

void cortex_m3_systick_config(void){
	//clock source AHB/8
	SYSTICK->CTRL = 0x00;

	//clear systick timer
	SYSTICK->VAL = 0x05;

	//reload with a value for 1MS tick
	// 8MHZ --> *5 = 40MHz --> /8 = 5MHz. reload value to get 1ms is 5000
	SYSTICK->LOAD = 50000;

	// enable system_tick interrupt, tick enable
	SYSTICK->CTRL = GET_BIT_VAL(TICKINT_BP)|
					GET_BIT_VAL(TICK_ENABLE_BP);
}


void SysTick_Handler(void){
	SYSTICK->CTRL |= 1<<16;	//CLR systick interrupt flag
	systick_ms++;
}
