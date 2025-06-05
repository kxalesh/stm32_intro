#include "stm32f10x.h"    // Device headeraa
#include "Delay.h"
#include "OLED.h"


uint8_t key_num;

int main(void)
{
	OLED_Init();
	OLED_ShowChar(1, 1, 'A');
	OLED_ShowString(2, 1, "Aleshkigali");
	OLED_ShowString(1, 3, "HelloWorld!");
	OLED_ShowNum(3, 1, 114514, 6);
	OLED_ShowSignedNum(3, 8, -66, 2);
	OLED_ShowHexNum(4, 1, 0x0721, 4);
	OLED_ShowBinNum(4, 6, 0x0721, 8);

	while (1)
	{
		
	}
}
