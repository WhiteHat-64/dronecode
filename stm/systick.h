/*
 * cortexm3_systick.h
 *
 *  Created on: Sep 6, 2021
 *      Author: Golden Eagle
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include "types.h"
#include "scb.h"

#define TICKINT_BP			1
#define TICK_ENABLE_BP		0

#define SYSTICK_REG_ADDR	0xE000E010

typedef struct SYSTICK_s{
	U32_t CTRL;
	U32_t LOAD;
	U32_t VAL;
	U32_t CALIB;
}SYSTICK_t;


extern _REG SYSTICK_t *SYSTICK;
extern _REG U32_t systick_ms;

//systick configured with 1ms
extern void cortex_m3_systick_config(void);
extern void SysTick_Handler(void);

#endif /* SYSTICK_H_ */
