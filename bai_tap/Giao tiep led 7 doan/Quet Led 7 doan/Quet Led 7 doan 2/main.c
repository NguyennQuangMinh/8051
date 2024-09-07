#include "main.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"

#define LED_PORT P2

sbit LED_PIN_1 = P3^0;
sbit LED_PIN_2 = P3^1;

unsigned char code Code7Seg[] = {0xC0, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};
//dem tu 0 den 99 moi giay tang 1 so
void main()
{
	unsigned int dem ;
	unsigned int i;
	while(1)
	{
		for(dem=0; dem<100; dem++)
		{
			for(i=0; i<500; i++) // vi moi giay tang 1 so ma thuc hien quet led mat 2 giay => vong for se quet 500 lan thi se Led se tang 1 so
			{
				LED_PORT = Code7Seg[dem/10];
				LED_PIN_1 = 0;							// bat led 1
				Delay_ms(1);
				LED_PIN_1 = 1;							//tat led 1
				
				LED_PORT = Code7Seg[dem%10];
				LED_PIN_2 = 0;							//bat led 2
				Delay_ms(1);
				LED_PIN_2 = 1;							//tat led 2
			}
		}
	}
}
