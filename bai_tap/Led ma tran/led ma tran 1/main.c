#include "main.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"

sbit IE74595_STCP = P3^5;     // RCK
sbit IE74595_SHCP = P3^6;     // SRCLK
sbit IE74595_DS = P3^4;       // SER

unsigned char LedMatrix5x7_0[] = {0x0E, 0x11, 0x13, 0x15, 0x19, 0x11, 0x0E};// mã tao so 0 tren led ma tran
//hien thi so 0 len led ma tran
void main()
{
	unsigned int i;
	while(1)
	{
		for(i=0; i<7; i++)
		{
			P0 = LedMatrix5x7_0[i];
			P2 = 0x01<<i;
			Delay_ms(1);
			P2 = 0x00;
		}
	}
}
