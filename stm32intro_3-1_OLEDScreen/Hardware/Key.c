#include "Key.h"


void key_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructor;
    GPIO_InitStructor.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructor.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_10;
    GPIO_InitStructor.GPIO_Speed = GPIO_Speed_50MHz;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    GPIO_Init(GPIOB, &GPIO_InitStructor);
}

uint8_t key_getNum(void)
{
    uint8_t key_num = 0;
    if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 0)
    {
        Delay_ms(20);
        while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 0);
        Delay_ms(20);
        key_num = 1;
    }

    if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10) == 0)
    {
        Delay_ms(20);
        while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10) == 0);
        Delay_ms(20);
        key_num = 2;
    }
    return key_num;
}










