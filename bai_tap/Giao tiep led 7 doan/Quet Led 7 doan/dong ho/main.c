#include "main.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"

sbit gio_1 = P3^0;
sbit gio_2 = P3^1;

sbit phut_1 = P3^2;
sbit phut_2 = P3^3;

sbit giay_1 = P3^4;
sbit giay_2 = P3^5;

unsigned char code Code7Seg[] = {0xC0, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};

void main()
{
	unsigned int gio, phut, giay;
	unsigned int i;
	gio = phut = giay = 0 ;
	while(1)
	{
		for(i=0; i<167; i++)
		{
			//gio 
			P2 = Code7Seg[gio/10];
			gio_1 = 0;
			Delay_ms(1);
			gio_1 = 1;
			
			P2 = Code7Seg[gio%10];
			gio_2 = 0;
			Delay_ms(1);
			gio_2 = 1;
			
			//phut
			P2 = Code7Seg[phut/10];
			phut_1 = 0;
			Delay_ms(1);
			phut_1 = 1;
			
			P2 = Code7Seg[phut%10];
			phut_2 = 0;
			Delay_ms(1);
			phut_2 = 1;
			
			//giay
			P2 = Code7Seg[giay/10];
			giay_1 = 0;						// bat led 1 hien thi hang chuc
			Delay_ms(1);
			giay_1 = 1;						// tat led 1
			
			P2 = Code7Seg[giay%10];
			giay_2 = 0;						// bat led 2 hien thi hang chuc
			Delay_ms(1);
			giay_2 = 1;						// tat led 2 hien thi hang don vi		
		}
		giay++;
		if(giay == 60)
		{
			giay = 0;
			phut++;
		}
		if(phut == 60)
		{
			phut = 0;
			gio++;
		}
		
		if(gio == 24)
		{
			gio = 0;
			giay = 0;
		}
	}
		
}

