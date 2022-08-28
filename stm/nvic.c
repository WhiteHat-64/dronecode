/*
 * cortexm3_nvic.c
 *
 *  Created on: Sep 6, 2021
 *      Author: Golden Eagle
 */

#include "nvic.h"

_REG NVIC_t *NVIC = (NVIC_t *)NVIC_BASE_ADDR;



void cortexm3_nvic_config(void){
	NVIC->IPR10 = 0x01;
}
