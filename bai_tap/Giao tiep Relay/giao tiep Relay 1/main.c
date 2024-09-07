
#include"main.h"
#include"C:\hoc\8051\bai_tap\Library\Delay\Delay.h"

sbit btn = P1^0;
sbit relay = P2^0;

void main()
{
	relay = 0;
	while(1)
	{
		if(btn == 0)
		{
			Delay_ms(20);
			relay = !relay;
			while(btn == 0);
		}
	
	}
}

