/*
 * stm32f103c8_rcc.c
 *
 *  Created on: Sep 6, 2021
 *      Author: evil
 */


#include "rcc.h"

_REG RCC_t *RCC = (RCC_t *)RCC_REG_ADDR;

void rcc_config(void){
	//HSE 8MHz is connected, set PLL to 40MHz

    //Multipy PLL with 5 to bring 40MHz (PLLMUL= 0x03)
	RCC->CFGR |= PLL_MUL_5 | GET_BIT_VAL(RCC_PLLSRC_BP) | 4<<8;

	// select pllsource to externel HSE
    RCC->CR |= GET_BIT_VAL(RCC_PLLON_BP) | GET_BIT_VAL(RCC_HSEON_BP);

	//wait until the PLL reaches the desired freq and switch the clock source to PLL
	RCC->CFGR |= PLL_HSE_SWITCH;
	while(!(RCC->CFGR & PLL_HSE_STATUS));

	RCC->APB2ENR |= GPIOB_EN;
	RCC->APB2ENR |= AFIO_EN;
}


