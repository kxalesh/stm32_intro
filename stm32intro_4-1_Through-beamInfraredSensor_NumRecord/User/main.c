#include "stm32f10x.h"    // Device headeraa
#include "Delay.h"
#include "OLED.h"
#include "Through-beamInfraredSensor.h"


uint8_t key_num;

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	OLED_Init();
	throughBeam_infrared_sensor_init();

	OLED_ShowString(1, 1, "Count:");
	while (1)
	{
		OLED_ShowNum(1, 7, counter_get(), 5);
	}
}
