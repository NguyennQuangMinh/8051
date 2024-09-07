#include "main.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"

void Uart_mode0_write(unsigned char b)
{
	SBUF = b;
	
	while( TI==0 );
	TI = 0;
	
	P3_2 = 0;
	P3_2 = 1;
}

void main()
{
	unsigned int i;
	// khoi tao UART mode 0
	SM0 = 0;
	SM1 = 0;
	
	while(1)
	{
		for(i=0; i<3; i++)
		{
			Uart_mode0_write(0x00);
			Delay_ms(500);
			Uart_mode0_write(0xFF);
			Delay_ms(500);		
		}
		for(i=0; i<3; i++)
		{
			Uart_mode0_write(0xAA);
			Delay_ms(500);
			Uart_mode0_write(0x55);
			Delay_ms(500);
		}
	}
}
