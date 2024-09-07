#include "main.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"

void main()
{
	P2=0;
	while(1)
	{
		do{
			P2++;
			Delay_ms(10);
		}while(P2!=255);
		
		do{
			P2--;
			Delay_ms(10);
		}while(P2!=0);
	
	}
}
