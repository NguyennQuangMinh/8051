#include "main.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"

void main()
{
	unsigned char b;
	SM0 = SM1 = 0; // UART mode 0
	REN = 1; // cho phep nhan du lieu
	P1_0 = 0;
	while(1)
	{
		// tao xung chot du lieu cho 74165
		P3_2 = 0;
		P3_2 = 1;
	
		// khi RI len 1 thi se truyen toan bo bit trong thanh ghi cua 74165 ra vi dieu khien
		RI = 0;
		while(RI==0);
		b = SBUF;
		if( (b&0x02) == 0 ) //0000 0010
		{
			P1_0 = 1;
		}
		if( (b&0x01) == 0 ) //0000 0001
		{
			P1_0 = 0;
		}
		
	}
}
