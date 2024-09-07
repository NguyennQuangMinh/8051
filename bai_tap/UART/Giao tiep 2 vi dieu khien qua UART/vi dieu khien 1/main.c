#include "main.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"
#include "C:\hoc\8051\bai_tap\Library\UartMode1\UartMode1.h"

// ex2: nhan 1 lan de bat, nhan lan 2 de tat
void main()
{
	unsigned char cnt = 0;
	Uart_Init();
	while(1)
	{
		if(P1_0 == 0)
		{
			Delay_ms(20);
			cnt++;
			if( cnt%2 != 0 ) // so lan bam la le thi se gui lenh 0x01
			{
				Uart_Write(0x01);
			}
			if(cnt%2 == 0) // so lan bam la chan thi se gui lenh 0x00
			{
				Uart_Write(0x00);
			}
			while(P1_0 == 0); // cho nguoi dung nha phim 
		}
	
	}
}


// ex1: nhan nut ON de bat, nhan nut OFF de tat
/* 
void main()
{
	Uart_Init();
	
	while(1)
	{
		if( P1_0 == 0 )
		{
			Delay_ms(20);
			Uart_Write(0x01);   // gui lenh on
			while( P1_0 == 0 ); // cho cho nguoi dung nha phim
		}
		if( P1_1 == 0 )
		{
			Delay_ms(20);
			Uart_Write(0x00);
			while( P1_1 == 0 );
		}
		
	}
}
*/
