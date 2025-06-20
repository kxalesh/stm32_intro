#include "stm32f10x.h"    // Device headeraa
#include "Delay.h"

int main(void)
{
	GPIO_InitTypeDef GPIO_InitStructor;
	GPIO_InitStructor.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructor.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructor.GPIO_Speed = GPIO_Speed_50MHz;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_Init(GPIOA, &GPIO_InitStructor);

	while (1)
	{
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
		Delay_ms(500);
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
		Delay_ms(500);
	}
}
