#include "main.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"

void Uart_Init()
{
	// khoi tao UART mode 1, 9600 baud
	SM0 = 0; SM1 = 1; // Khoi tao UART kieu 1
	TMOD = 0x20;			// 0010_0000 - Timer 1 hoat dong o che do 8 bit tu dong nap lai
	TH1 = 0xFD;				// toc do baud 9600
	TR1 = 1;					// Timer 1 bat dau chay
	TI = 1;						// san sang gui du lieu
	REN = 1; 					// cho phep nhan du lieu
}

void Uart_Write(char c)
{
	while( TI == 0 ); // cho cho den khi ky tu duoc gui het 
	TI = 0;
	SBUF = c;
}

void Uart_Write_Text(char *str)
{
	unsigned char i=0;
	while( *(str+i) != 0 )
	{
		Uart_Write( *(str+i) );
		i++;
	}

}

char Uart_Data_Ready()
{
	// neu RI bang 1 thi bao hieu da nhan xong 1 ky tu
	return RI;
}

char Uart_Read()
{
	RI = 0; // neu nhan duoc tin hieu da nhan xong 1 ky tu se tat co bao hieu da nhan xong 1 ky tu
	return SBUF; // tra ve ky tu nhan duoc
}

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
		Uart_Write_Text("->");			
		Uart_Write(c);								// in ra chu in hoa sau khi doi ra
		Uart_Write_Text("\n\r"); 						// xuong dong
	
	}
		
	
}
