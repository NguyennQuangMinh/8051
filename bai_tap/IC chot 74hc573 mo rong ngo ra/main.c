#include "main.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"

sbit LE_1 = P2^0;
sbit LE_2 = P2^1;

unsigned char code Code7Seg[] = {0xC0, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};

void main()
{
	unsigned int i;
	LE_1 = LE_2 = 0;
	while(1)
	{
		for(i=0; i <100; i++)
		{
			P0 = Code7Seg[i/10];
			LE_1 = 1;
			Delay_ms(10); // delay o day de thay duoc su thay doi muc logic trong mo phong
			LE_1 = 0;

		
			P0 = Code7Seg[i%10];
			LE_2 = 1;
			Delay_ms(10); // delay o day de thay duoc su thay doi muc logic trong mo phong
			LE_2 = 0;

			
			Delay_ms(500);
		}
	
	}
}
