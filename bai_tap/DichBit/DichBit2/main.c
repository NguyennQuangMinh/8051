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
	char b;
	while(1)
	{
		b = 0xC0; 		// -32                          7 6 5 4 3 2 1 0
									// Bin                          0 1 0 0 0 0 0 0
									// so bu 1: "~"                 1 0 1 1 1 1 1 1
		              // so bu 2: "~" + muc logic 1   1 1 0 0 0 0 0 0
		// so am se duoc bieu dien duoi dang so bu 2
		P0 = b;
		for(i=0; i<4; i++)
		{
			Delay_ms(1000);
			b = b >> 2;
			P0 = b;
		}
	}
}
