#include <REGX52.H>

void Delay_ms(unsigned int t)
{
	unsigned int x, y;
	for(x =0; x<t; x++)
	{
		for(y=0; y<123; y++);
	}
}

void main()
{
	unsigned char i;
	
	while(1)
	{
		P0 = 0x01;
		for(i=0; i<8; i++)
		{
			Delay_ms(1000);
			P0 = P0 << 1;
		}
	}
}
