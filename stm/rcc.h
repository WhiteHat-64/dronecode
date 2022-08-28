/*
 * stm32f103c8_RCC.h
 *
 *  Created on: Sep 6, 2021
 *      Author: evil
 */

#ifndef STM32F103C8_RCC_H_
#define STM32F103C8_RCC_H_

#include "types.h"

#define RCC_PLLRDY_BP   25
#define RCC_PLLON_BP    24
#define RCC_CSSON_BP    19
#define RCC_HSEBYP_BP   18
#define RCC_HSERDY_BP   17
#define RCC_HSEON_BP    16
#define RCC_HSIRDY_BP   1
#define RCC_HSION_BP    0


#define RCC_PLLXTPRE_BP   17
#define RCC_PLLSRC_BP     16


#define PLL_VAL_BP      18
#define PLL_MUL_5    	(0x03<<PLL_VAL_BP)

#define PLL_HSE_SWITCH		0x2
#define PLL_HSE_STATUS		0x8

#define GPIOB_EN	0x8
#define AFIO_EN		0x1

#define RCC_REG_ADDR	0x40021000

typedef struct RCC_s{
    U32_t CR;         //0x00
    U32_t CFGR;
    U32_t CIR;
    U32_t APB2RSTR;
    U32_t APB1RSTR;
    U32_t AHBENR;
    U32_t APB2ENR;
    U32_t APB1ENR;
    U32_t BDCR;
    U32_t CSR;
}RCC_t;

extern _REG RCC_t *RCC;


extern void rcc_config(void);

#endif /* STM32F103C8_RCC_H_ */
