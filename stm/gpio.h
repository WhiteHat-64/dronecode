/*
 * stm32f103c8_gpio.h
 *
 *  Created on: Sep 6, 2021
 *      Author: Golden Eagle
 */

#ifndef STM32F103C8_GPIO_H_
#define STM32F103C8_GPIO_H_

#include "types.h"


#define GPIOA_BASE_ADDR		0x40010800
#define GPIOB_BASE_ADDR		0x40010C00
#define GPIOC_BASE_ADDR		0x40011000
#define GPIOD_BASE_ADDR		0x40011400
#define GPIOE_BASE_ADDR		0x40011800

#define AFIO_BASE_ADDR		0x40010000

typedef struct GPIO_s{
	U32_t CRL;		//0x00
	U32_t CRH;		//0x04
	U32_t IDR;		//0x08
	U32_t ODR;		//0x0C
	U32_t BSRR;		//0x10
	U32_t BRR;		//0x14
	U32_t LCKR;		//0x18
}GPIO_t;

typedef struct AFIO_s{
	U32_t EVCR;		//0x00
	U32_t MAPR;		//0x04
	U32_t EXTICR1;	//0x08
	U32_t EXTICR2;	//0x0C
	U32_t EXTICR3;	//0x10
	U32_t EXTICR4;	//0x14
	U32_t MAPR2;	//0x1C
}AFIO_t;


extern _REG GPIO_t *GPIOA;
extern _REG GPIO_t *GPIOB;
extern _REG GPIO_t *GPIOC;
extern _REG GPIO_t *GPIOD;
extern _REG GPIO_t *GPIOE;
extern _REG GPIO_t *GPIOF;
extern _REG AFIO_t *AFIO;

extern void gpio_config(void);

#endif /* STM32F103C8_GPIO_H_ */
