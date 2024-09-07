#include "main.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"

#define chuc P2
#define donvi P3

// mac theo kieu sink dong nen muc kich hoat la 0
sbit red = P0^0;
sbit yellow = P0^1;
sbit green = P0^2;

//khai bao ma cua led 7 doan
unsigned char code Code7Seg[] = {0xC0, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};
void main()
{
	signed char i;
	while(1)
	{
		//den do
		red = 0;
		yellow = 1;
		green = 1;
		for(i=20; i>=0; i--)
		{
			chuc = Code7Seg[i/10];
			donvi = Code7Seg[i%10];
			Delay_ms(1000);
		}
		
		//den xanh
		red = 1;
		yellow = 1;
		green = 0;
		for(i=15; i>=0; i--)
		{
			chuc = Code7Seg[i/10];
			donvi = Code7Seg[i%10];
			Delay_ms(1000);
		}
		
		//den vang
		red = 1;
		yellow = 0;
		green = 1;
		for(i=5; i>=0; i--)
		{
			chuc = Code7Seg[i/10];
			donvi = Code7Seg[i%10];
			Delay_ms(1000);
		}
	}
}

