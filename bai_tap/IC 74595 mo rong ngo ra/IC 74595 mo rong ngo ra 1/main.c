#include "main.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"

// khai bao ket noi chan IC 74HC595
sbit IE74595_SHCP = P2^0;
sbit IE74595_DS = P2^1;
sbit IE74595_STCP = P2^2;

void IE74595_OUT_BYTE(unsigned char b)
{
	unsigned char i;
	for(i=0; i<8; i++)
	{
		IE74595_DS = b & (0x80 >> i); // Lay tung bit cua byte b gui ra DS, lay tu bit cao truoc
		
		//	tao xung dich du lieu
		IE74595_SHCP = 0;
		IE74595_SHCP = 1;
	}
	
	//tao xung xuat du lieu
	IE74595_STCP = 0;
	IE74595_STCP = 1;
}

void main()
{
	unsigned char i;

	while(1)
	{
		/* nhap nhay led xen ke giua cac chan led chan le
		IE74595_OUT_BYTE(b);
		Delay_ms(500);
		b = ~b; 
		*/
		
		// Led sang dan
		unsigned char b = 0x00;
		IE74595_OUT_BYTE(b);
		Delay_ms(300);
		for(i=0; i<8; i++)
		{
			b = (b<<1) | 0x01;
			IE74595_OUT_BYTE(b);
			Delay_ms(300);
		}
	}
}
