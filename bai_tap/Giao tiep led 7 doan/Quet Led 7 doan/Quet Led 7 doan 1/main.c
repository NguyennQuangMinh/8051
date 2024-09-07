#include "main.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"

// khai bao chan dieu khien ma Led 7 doan
#define Led_port P3

// khai bao 2 chan kich mo Led so 1 va Led so  2
sbit Led_1 = P2^0;
sbit Led_2 = P2^1;

// ma led 7 doan
unsigned char code Code7Seg[] = {0xC0, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};

void main()
{
	while(1)
	{
		// Led 1 hien thi so 1
		Led_port = Code7Seg[1];
		Led_1 = 0; 							//bat led 1
		Delay_ms(1);
		Led_1 = 1;							//tat led 1


		// Led 2 hien thi so 2
		Led_port = Code7Seg[2];
		Led_2 = 0;							//bat led 2
		Delay_ms(1);		
		Led_2 = 1;							//tat led 2

	}
}

