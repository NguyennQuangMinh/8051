#include <REGX52.H>

void Delay_ms(unsigned int t)
{
	unsigned int x, y;
	for(x=0; x<t; x++)
	{
		for(y=0; y<123; y++);
	}
}

void main()
{
	while(1)
	{ 
		// sang va tat tung led tu tren xuong
		P0 = 0x01;
		Delay_ms(500);
		P0 = 0x02;
		Delay_ms(500);
		P0 = 0x04;
		Delay_ms(500);
		P0 = 0x08;
		Delay_ms(500);
		P0 = 0x10;
		Delay_ms(500);
		P0 = 0x20;
		Delay_ms(500);
		P0 = 0x40;
		Delay_ms(500);
		P0 = 0x80;
		Delay_ms(500);
		
		// sang va tat tung led tu duoi lem
		P0 = 0x80;
		Delay_ms(500);
		P0 = 0x40;
		Delay_ms(500);
		P0 = 0x20;
		Delay_ms(500);
		P0 = 0x10;
		Delay_ms(500);
		P0 = 0x08;
		Delay_ms(500);		
		P0 = 0x04;
		Delay_ms(500);		
		P0 = 0x02;
		Delay_ms(500);		
		P0 = 0x01;
		Delay_ms(500);		
		
	}
}