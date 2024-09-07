#include"main.h"
#include"C:\hoc\8051\bai_tap\Library\Delay\Delay.h"

void sangdantatdan()
{
		unsigned char i;
		P0 = 0x00;
		// sang dan 8 led
		for(i=0; i<8; i++)
		{
			P0 = P0 << 1;
			P0 = P0 | 0x01;
			Delay_ms(500);
		}
		Delay_ms(500);
		//Tat dan 8 led
		for(i=0; i<8; i++)
		{
			P0 = P0 << 1;
			Delay_ms(500);
		}
}

void choptatxenke()
{
	unsigned char i;
	P0 = 0xAA;
	for( i=0; i<10; i++)
	{
		P0 = ~P0;
		Delay_ms(500);
	}
}

void main()
{
	unsigned char i;
	while(1)
	{
		sangdantatdan();
		choptatxenke();
	}
}




