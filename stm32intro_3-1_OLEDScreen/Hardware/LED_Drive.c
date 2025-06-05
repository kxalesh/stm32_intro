#include "LED_Drive.h"

/**
 * 
 */
void LED_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructor;
    GPIO_InitStructor.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructor.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_4;
    GPIO_InitStructor.GPIO_Speed = GPIO_Speed_50MHz;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_Init(GPIOA, &GPIO_InitStructor);

    GPIO_SetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_4);
}

void LED_ON_GPIOA_0(void)
{
    GPIO_ResetBits(GPIOA, GPIO_Pin_0);
}

void LED_OFF_GPIOA_0(void)
{
    GPIO_SetBits(GPIOA, GPIO_Pin_0);
}

void LED_ON_GPIOA_4(void)
{
    GPIO_ResetBits(GPIOA, GPIO_Pin_4);
}

void LED_OFF_GPIOA_4(void)
{
    GPIO_SetBits(GPIOA, GPIO_Pin_4);
}

void LED_Turn_GPIO_0(void)
{
    if (GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_0) == 0)
    {
        GPIO_SetBits(GPIOA, GPIO_Pin_0);
    }
    else
    {
        GPIO_ResetBits(GPIOA, GPIO_Pin_0);
    }
}

void LED_Turn_GPIO_4(void)
{
    if (GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_4) == 0)
    {
        GPIO_SetBits(GPIOA, GPIO_Pin_4);
    }
    else
    {
        GPIO_ResetBits(GPIOA, GPIO_Pin_4);
    }
}


