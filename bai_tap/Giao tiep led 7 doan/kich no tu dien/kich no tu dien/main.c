#include "main.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"

#define dem P0

sbit btn = P1^0;
sbit notu = P2^0;

unsigned char code Code7Seg[] = {0xC0, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};
void main()
{
	signed char i;
	while(1)
	{
		if( btn == 0 )
		{
			Delay_ms(20);
			for(i=9;i>=0;i--)
			{
				dem = Code7Seg[i];
				Delay_ms(1000);
			}
			notu = !notu;
			Delay_ms(5000);
			notu = !notu;
			
		}
	
	}
}

