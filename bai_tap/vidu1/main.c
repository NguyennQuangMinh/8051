#include <REGX52.H>

sbit LED_PIN = P2^0;

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
	while(1)                                        
	{
		LED_PIN = !LED_PIN; // dao trang thai cua chan P0^0
		Delay_ms(500);
	}
}
