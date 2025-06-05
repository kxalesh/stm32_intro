#include "stm32f10x.h"    // Device headeraa
#include "Delay.h"

int main(void)
{
	GPIO_InitTypeDef GPIO_InitStructor;
	GPIO_InitStructor.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructor.GPIO_Pin = GPIO_Pin_0 | 
								 GPIO_Pin_1 | 
								 GPIO_Pin_2 | 
								 GPIO_Pin_3 | 
								 GPIO_Pin_4 | 
								 GPIO_Pin_5 | 
								 GPIO_Pin_6 | 
								 GPIO_Pin_7;

	GPIO_InitStructor.GPIO_Speed = GPIO_Speed_50MHz;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_Init(GPIOA, &GPIO_InitStructor);

	int LED_orders[8] = {0x0001, 0x0002, 0x0004, 0x0008, 0x0010, 0x0020, 0x0040, 0x0080};

	while (1)
	{
		for (int idx = 0; idx < 8; idx++)
		{
			GPIO_Write(GPIOA, ~LED_orders[idx]);
			Delay_ms(100);
		}

		// GPIO_Write(GPIOA, ~0x0001);
		// Delay_ms(100);
		// GPIO_Write(GPIOA, ~0x0002);
		// Delay_ms(100);
		// GPIO_Write(GPIOA, ~0x0004);
		// Delay_ms(100);
		// GPIO_Write(GPIOA, ~0x0008);
		// Delay_ms(100);
		// GPIO_Write(GPIOA, ~0x0010);
		// Delay_ms(100);
		// GPIO_Write(GPIOA, ~0x0020);
		// Delay_ms(100);
		// GPIO_Write(GPIOA, ~0x0040);
		// Delay_ms(100);
		// GPIO_Write(GPIOA, ~0x0080);
		// Delay_ms(100);
	}
}
