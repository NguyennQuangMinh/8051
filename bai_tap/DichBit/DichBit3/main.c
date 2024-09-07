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
		P0 = 0x00;
		Delay_ms(500);
		b = 0x80; // -128							       7 6 5 4 3 2 1 0
		P0 = b;   // bin  									 1 0 0 0 0 0 0 0
						  // bu 1: "~"					     0 1 1 1 1 1 1 1
						  // bu 2: "~" + logic:1		 1 0 0 0 0 0 0 0   => HEX = 0x80
		for(i=0; i<8; i++)
		{
			Delay_ms(1000);
			b = b >> 1;
			P0 = b;
		}
		for(i=0; i<8; i++)
		{
			Delay_ms(1000);
			b = b << 1;
			P0 = b;
		}
	}
	// led sang dan sau do tat dan
}
