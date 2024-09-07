
// nhan nut BTN1 se chop tat led o port 2, nhan BTN2 se tat che do chop tat led

#include"main.h"
#include"C:\hoc\8051\bai_tap\Library\Delay\Delay.h"

#define Led P2

sbit BTN_1 = P1^0;
sbit BTN_2 = P1^1;

unsigned int Delay1schoptatled()
{
	unsigned int i;
	for(i=0; i<100; i++)
	{
		Delay_ms(10);
		if(BTN_2 == 0)
		{
			Led = 0x00;
			return 1; // co nhan nut BTN_2
		}			
	}
	return 0;
}

void main()
{
	Led = 0x00;
	while(1)
	{
		if(BTN_1 == 0)
		{
			Delay_ms(20);

			while(1)
			{
				Led = ~Led;
				if(Delay1schoptatled()) break;
			}

		}
	}
}
