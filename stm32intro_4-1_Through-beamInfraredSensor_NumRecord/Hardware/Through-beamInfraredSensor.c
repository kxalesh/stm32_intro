#include "Through-beamInfraredSensor.h"

uint16_t num_count;

void throughBeam_infrared_sensor_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructor;
    GPIO_InitStructor.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructor.GPIO_Pin = GPIO_Pin_14;
    GPIO_InitStructor.GPIO_Speed = GPIO_Speed_50MHz;

    EXTI_InitTypeDef EXTI_InitStructor;
    EXTI_InitStructor.EXTI_Line = EXTI_Line14;
    EXTI_InitStructor.EXTI_LineCmd = ENABLE;
    EXTI_InitStructor.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructor.EXTI_Trigger = EXTI_Trigger_Rising;

    NVIC_InitTypeDef NVIC_InitStructor;
    NVIC_InitStructor.NVIC_IRQChannel = EXTI15_10_IRQn;
    NVIC_InitStructor.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStructor.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructor.NVIC_IRQChannelSubPriority = 1;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

    GPIO_Init(GPIOB, &GPIO_InitStructor);

    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource14);

    EXTI_Init(&EXTI_InitStructor);

    NVIC_Init(&NVIC_InitStructor);
}

uint16_t counter_get(void)
{
    return num_count;
}

void EXTI15_10_IRQHandler(void)
{
    if (EXTI_GetITStatus(EXTI_Line14) == SET)
    {
        if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14) == RESET)
        {
            num_count++;
        }
        EXTI_ClearITPendingBit(EXTI_Line14);
    }
}







