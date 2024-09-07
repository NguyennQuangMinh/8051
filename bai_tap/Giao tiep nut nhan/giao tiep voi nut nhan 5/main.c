#include"main.h"
#include"C:\hoc\8051\bai_tap\Library\Delay\Delay.h"

#define Led P2

sbit BTN = P1^0;
bit pressFlag = 0;

unsigned char pressBTN()
{
	unsigned char i;
	for(i=0; i<50; i++)
	{
		Delay_ms(10);
		if(BTN == 0)
		{
			if(pressFlag == 0)
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
	unsigned char count = 0;
	Led = 0x00;
	while(1)
	{
		if(BTN == 0)
		{
			if(pressBTN())
			{
				count++;
				if(count%2 !=0)
				{
					Led = 0xAA;
					while(1)
					{
						if(pressBTN())
						{
							count++;
							Led = 0x00;
							break;
						}
						Led = ~Led;
					}
				}
			}
		}
	}
}
