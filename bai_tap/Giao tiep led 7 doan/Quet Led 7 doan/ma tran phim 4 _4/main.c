#include "main.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"
#include "C:\hoc\8051\bai_tap\Library\KeyPad 4x4\KeyPad4x4.h"
#include "port.h"

unsigned char code Code7Seg[] = {0xC0, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};


void main()
{
	unsigned char key = 0xFF, tmp = 0xFF;
	while(1)
	{
		key = KeyPress();
		if(key != 0xFF)  // Ki?m tra xem có phím nào du?c nh?n không
		{
		 	tmp = key;
		}

		// Hi?n th? mã phím trên 7 do?n
		LED_PORT = Code7Seg[tmp/10];
		Led_1 = 0;
		Delay_ms(1);
		Led_1 = 1;

		LED_PORT = Code7Seg[tmp%10];
		Led_2 = 0;
		Delay_ms(1);
		Led_2 = 1;
	}
}