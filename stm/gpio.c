/*
 * stm32f103c8_gpio.c
 *
 *  Created on: Sep 6, 2021
 *      Author: Golden Eagle
 */


#include "gpio.h"


_REG GPIO_t *GPIOB = (GPIO_t *)GPIOB_BASE_ADDR;
_REG AFIO_t *AFIO = (AFIO_t *)AFIO_BASE_ADDR;

void gpio_config(void){
	// configure B3 pin as output
	GPIOB->CRL &= ~(0xf<<12);
	GPIOB->CRL |= (0x2 << 12);
	//alternate function(B3 pin is set as GPIO): JTAG-DP Disabled and SW-DP Enabled
	AFIO->MAPR &= ~(0x7 << 24);
	AFIO->MAPR |= (0x2 << 24);
}
