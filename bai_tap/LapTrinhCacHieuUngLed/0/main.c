#include <REGX52.H>

void Delay_ms(unsigned int t)
{
	unsigned int x, y;
	for( x=0; x<t; x++)
	{
		for( y=0; y<123; y++);
	}
}

void main()
{

	//vong lap chinh
	while(1)
	{
		// chop tat led 0.5s cac chan o port 0
		P0 = 0x00; // doi he 2 -> he 16
		Delay_ms(500);
		P0 = 0xFF; // doi he 2 -> he 16
		Delay_ms(500);
	}
}
