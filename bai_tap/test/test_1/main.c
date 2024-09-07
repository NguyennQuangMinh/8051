#include"main.h"
#include"C:\hoc\8051\bai_tap\Library\Delay\Delay.h" //#include "..\Library\Delay\Delay.h"

void main()
{
	P0 = 0xAA;
	while(1)
	{
		P0 = ~P0;
		Delay_ms(500);
	}
}