#include "main.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"
#include "C:\hoc\8051\bai_tap\Library\IE 74595\IE74595.h"

void main()
{
	unsigned char buffer[2], i;
	while(1)
	{
		//tat toan bo led 
		for(i =0; i<2; i++)
		{
			buffer[i] = 0x00;
		}
		IE74595_Out(&buffer, 2);
		
		Delay_ms(500);
		
		// bat toan bo led
		for(i=0; i<2; i++)
		{
			buffer[i] = 0xFF;
		}
		IE74595_Out(&buffer, 2);
		Delay_ms(500);
	}
}
