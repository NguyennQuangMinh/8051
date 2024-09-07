#include "main.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"
#include "C:\hoc\8051\bai_tap\Library\IE 74595\IE74595.h"

unsigned char code Code7Seg[] = {0xC0, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};

void main()
{
	unsigned int i;
	unsigned char buffer[2];
	while(1)
	{
		for(i=0; i<100; i++)
		{
			buffer[0] = Code7Seg[i/10];
			buffer[1] = Code7Seg[i%10];
			IE74595_Out(&buffer, 2);
			Delay_ms(500);
		}
	
	}
}
