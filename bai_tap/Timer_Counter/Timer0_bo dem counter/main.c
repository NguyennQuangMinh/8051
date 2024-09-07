
// mach dem san pham su dung counter

#include "main.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"

sbit btn_reset = P1^0;

unsigned char code Code7seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x00, 0x10}; 

void Display(unsigned int c)
{
	unsigned char chuc_ngan, ngan, tram, chuc, donvi;
	chuc_ngan = c/10000;
	ngan = (c%10000)/1000;
	tram = (c%1000)/100;
	chuc = (c%100)/10;
	donvi = c%10;
	
	P2_0 = 0;
	P0 = Code7seg[chuc_ngan];
	Delay_ms(1);
	P2_0 = 1;
	
	P2_1 = 0;
	P0 = Code7seg[ngan];
	Delay_ms(1);
	P2_1 = 1;
	
	P2_2 = 0;
	P0 = Code7seg[tram];
	Delay_ms(1);
	P2_2 = 1;
	
	P2_3 = 0;
	P0 = Code7seg[chuc];
	Delay_ms(1);
	P2_3 = 1;
	
	P2_4 = 0;
	P0 = Code7seg[donvi];
	Delay_ms(1);
	P2_4 = 1;	
}

void main()
{
	unsigned char high, low;
	unsigned int number;
	//thiet lap che do lam viec timer 0 kieu bo dem counter 16bit
	TMOD &= 0xF0;
	TMOD |= 0x05;
	TR0 = 1; //cho phep timer 0 dem
	while(1)
	{
		do
		{			
			high = TH0; // luu gia tri 4bit cao vao bien high
			low = TL0;	// luu gia tri 4 bit thap vao bien low
		}while(high != TH0);
		
		number = high; // luu gia tri thanh ghi TH0 vao 8 bit thap cua number
		number <<= 8;  // dich 8 bit thap cua number len 8 bit vao
		number|= low; // luu gia tri thanh ghi TL0 vao 8 bit thap cua number
		
		Display(number);
		
		if(btn_reset == 0)
		{
			Delay_ms(20);
			TR0=0;
			TH0=0;
			TL0=0;
		}
		else
		{
			TR0 = 1;
		}
	}
}
