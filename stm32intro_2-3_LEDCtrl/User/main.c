#include "stm32f10x.h"    // Device headeraa
#include "Delay.h"
#include "LED_Drive.h"
#include "Key.h"

uint8_t key_num;

int main(void)
{
	LED_init();
	key_init();

	while(1)
	{
		key_num = key_getNum();
		if (key_num == 1)
		{
			LED_Turn_GPIO_0();
		}

		if (key_num == 2)
		{
			LED_Turn_GPIO_4();
		}
	}
}
