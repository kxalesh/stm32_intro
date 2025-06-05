#ifndef __LED_DRIVE_H
#define __LED_DRIVE_H
#include "stm32f10x.h"

void LED_init(void);
void LED_ON_GPIOA_0(void);
void LED_OFF_GPIOA_0(void);
void LED_ON_GPIOA_4(void);
void LED_OFF_GPIOA_4(void);
void LED_Turn_GPIO_0(void);
void LED_Turn_GPIO_4(void);

#endif

