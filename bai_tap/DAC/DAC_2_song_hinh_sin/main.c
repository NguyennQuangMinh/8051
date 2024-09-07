
// tao song hinh sin có chu ky T = 0.02s <=> 20ms

#include "main.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"

unsigned char code DACvalue[] = {128,168,202,231,245,255,245,231,202,168,128,87,53,24,10,0,10,24,53,87};

void main()
{
	unsigned int i;
	while(1)
	{
		for(i=0; i<20; i++) // 1 chu ky là 20ms => lap 20 lan, moi lan Delay 1ms
		{
			P2 = DACvalue[i];
			Delay_ms(1);
		}
	
	}
}
