#include <REGX51.H>

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
	// 4 chan dau tien cua port 0 sang 500 ms sau do tat, 4 chan sau cua port 0 sang 500ms sau do tat
	while(1)
	{
		P0 = 0x0F; // doi he 2 -> he 16 (BIN -> HEX)
		Delay_ms(500);
		P0 = 0xF0;
		Delay_ms(500); // doi he 2 -> he 16 (BIN -> HEX)
	}
}