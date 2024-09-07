#include"main.h"
#include"C:\hoc\8051\bai_tap\Library\Delay\Delay.h"

void main()
{
	P2_0 = 0;
	while(1)
	{
		if(P1_0 == 0 )
		{
			P2_0 = 1;
		}
		else{
			P2_0 =0;
		}
	
	}
}
