#include "main.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"
#include "C:\hoc\8051\bai_tap\Library\UartMode1\UartMode1.h"
void main()
{
	Uart_Init();
	P1_0 = 0;
	while(1)
	{
		if(Uart_Data_Ready() == 1)
		{
			if(Uart_Read() == 0x01)
			{
				P1_0 = 1;
			}
			else
			{
				P1_0 = 0;
			}
		}
	
	}
}
