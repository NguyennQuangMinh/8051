#include "main.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"
#include "C:\hoc\8051\bai_tap\Library\UartMode1\UartMode1.h"

void main()
{
	char c;
	Uart_Init();

//	for(c='a'; c<='z'; c++)
//	{
//		Uart_Write(c);
//		Delay_ms(100);
//	}
//	Uart_Write_Text("Hello, World");

	while(1)
	{
//		if(Uart_Data_Ready() == 1)
//		{
//			P2 = Uart_Read();
//		}
	
		// doi ky tu thuong sang ky tu in hoa
		Uart_Write_Text("Moi ban nhap chu thuong: ");
		while(Uart_Data_Ready() == 0); // doi nguoi dung nhap ky tu
		c = Uart_Read(); 							// truyen ky tu nhan duoc vao bien c
		c = c - 32;										// doi chu thuong sang chu in hoa
		Uart_Write_Text("=>");			
		Uart_Write(c);								// in ra chu in hoa sau khi doi ra
		Uart_Write_Text("\n\r"); 						// xuong dong
	
	}
		
	
}
