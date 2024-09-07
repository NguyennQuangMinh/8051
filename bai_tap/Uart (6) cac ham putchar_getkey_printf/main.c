#include "main.h"
#include "stdio.h" // cac ham dung uart chua trong day
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"
#include "C:\hoc\8051\bai_tap\Library\UartMode1\UartMode1.h"

void main()
{
	char c;
	Uart_Init(); // khoi tao Uart mode 1, 9600baud, 1 start, 1 stop,8bit du lieu

	//	putchar('A'); // gui 1 ky tu ra Uart <=> Uart_Write trong thu vien UartMode1
	
	printf("Hello World\r\n");
	
	while(1)
	{
		Uart_Write_Text("Nhap vao 1 ky tu: ");
		c = _getkey(); // doi nguoi dung nhap vao 1 ky tu, sau do truyen ky tu do vao bien c <=> Uart_Read nhung Uart_Read khong doi nguoi dung nhap
		putchar(c-32);
		Uart_Write_Text("\r\n");
		
	}
}
