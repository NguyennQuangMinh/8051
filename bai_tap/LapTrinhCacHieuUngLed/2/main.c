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
	//chop tat xen ke cac chan chan sang thi cac chan le tat, cac chan le sang thi cac chan chan tat
	while(1)
	{
		P0 = 0xAA; // doi he 2 -> he 16 (BIN -> HEX)
		Delay_ms(500);
		P0 = 0x55;
		Delay_ms(500); // doi he 2 -> he 16 (BIN -> HEX)
	}
}