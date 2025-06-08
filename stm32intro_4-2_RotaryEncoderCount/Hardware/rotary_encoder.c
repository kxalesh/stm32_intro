#include "rotary_encoder.h"

int16_t encoder_count;

void rotary_encoder_init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructor;
    GPIO_InitStructor.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructor.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
    GPIO_InitStructor.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Init(GPIOB, &GPIO_InitStructor);

    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource0);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource1);

    EXTI_InitTypeDef EXTI_InitStructor;
    EXTI_InitStructor.EXTI_Line = EXTI_Line0 | EXTI_Line1;
    EXTI_InitStructor.EXTI_LineCmd = ENABLE;
    EXTI_InitStructor.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructor.EXTI_Trigger = EXTI_Trigger_Rising;
    
    EXTI_Init(&EXTI_InitStructor);

    NVIC_InitTypeDef NVIC_InitStructor;
    NVIC_InitStructor.NVIC_IRQChannel = EXTI0_IRQn;
    NVIC_InitStructor.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStructor.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructor.NVIC_IRQChannelSubPriority = 1;

    NVIC_Init(&NVIC_InitStructor);

    NVIC_InitStructor.NVIC_IRQChannel = EXTI1_IRQn;
    NVIC_InitStructor.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStructor.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructor.NVIC_IRQChannelSubPriority = 2;

    NVIC_Init(&NVIC_InitStructor);
}

int16_t get_count(void)
{
    int16_t temp_count;
    temp_count = encoder_count;
    encoder_count = 0;
    return temp_count;
}

void EXTI0_IRQHandler(void)
{
    if (EXTI_GetITStatus(EXTI_Line0) == SET)
    {
        if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0)
        {
            encoder_count++;
        }

        EXTI_ClearITPendingBit(EXTI_Line0);
    }
}

void EXTI1_IRQHandler(void)
{
    if (EXTI_GetITStatus(EXTI_Line1) == SET)
    {
        if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 0)
        {
            encoder_count--;
        }

        EXTI_ClearITPendingBit(EXTI_Line1);
    }
}
