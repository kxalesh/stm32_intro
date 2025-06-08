#include "stm32f10x.h"    // Device headeraa
#include "Delay.h"
#include "OLED.h"
#include "rotary_encoder.h"


int16_t num_count;

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	OLED_Init();
	rotary_encoder_init();

	OLED_ShowString(1, 1, "Num:");
	while (1)
	{
		num_count += get_count();
		OLED_ShowSignedNum(1, 5, num_count, 5);
	}
}
