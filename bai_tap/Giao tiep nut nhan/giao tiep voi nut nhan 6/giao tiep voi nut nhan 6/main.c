#include"main.h"
#include"C:\hoc\8051\bai_tap\Library\Delay\Delay.h"

sbit BTN = P1^0;
bit pressFlag = 0;

unsigned char DelayChedo()
{
	unsigned char i;
	for(i=0; i<50; i++)
	{
		Delay_ms(10);
		if(BTN == 0)
		{
			if(pressFlag == 0 )
			{
				pressFlag = 1;
				return 1;
			}
		}
		else
		{
			pressFlag = 0;
		}
	}
	return 0;
}

void main()
{
	unsigned char i;

	while(1)
	{
		//che do 1 chop tat led o port 2
		P2 = 0x00;
		for(i=0; i<10; i++)
		{
			if(DelayChedo()) break;
			P2 = ~P2;
		}
		
		// che do 2: chop tat xen ke o port 2
		P2 = 0xAA;
		for(i=0; i<10; i++)
		{
			if(DelayChedo()) break;
			P2 = ~P2;
		}
		
		//che do 3: chop tat 4 led dau và 4 led sau
		P2 = 0xF0;
		for(i=0; i<10; i++)
		{
			if(DelayChedo()) break;
			P2 = ~P2;
		}
	}
}
