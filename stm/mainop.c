#include "mainop.h"

void schedule(void);

void SystemInit(void)
{
	rcc_config();
	gpio_config();
    cortex_m3_systick_config();
}

int main(void)
{
    while(1){
        schedule();
    }
}


void schedule(void)
{
    switch (systick_ms % 10) {
        
        case 0:
        	GPIOB->ODR &= ~(1 << 3);
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;        
        case 4:
            break;
        case 5:
        	GPIOB->ODR |= 1 << 3;
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        default:
            break;
    }
}
