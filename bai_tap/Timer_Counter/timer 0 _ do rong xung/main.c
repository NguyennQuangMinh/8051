#include "main.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"
#include "C:\hoc\8051\bai_tap\Library\LCD16x2_4bit\LCD4.h"
#include "port.h"

void main()
{
	unsigned int t, f;
	
	//khoi tao Lcd
	Lcd_Init();
	Lcd_Out(1,1,"T = ");
	Lcd_Out(2,1,"f = ");
	
	//set mode cho timer 0 
	TMOD &= 0xF0;
	TMOD |= 0x09;
	
	while(1)
	{
		//gioi han luu gia tri la 65535 gia tri tuong duong voi 4byte
		TH0 = 0;
		TL0 = 0;
		
		while(INT0);    // bo qua xung muc 1 dau tien
		while(!INT0);   // bo qua muc 0
		TR0 = 1;        //cho phep luu gia tri vao thanh ghi TH0 va TL0
		while(INT0);
		TR0 =0;
		
		t = TH0;   // luu gia tri TH0 vao 4 bit thap cua bien t
		t <<= 8;  // luu gia tri TH0 vao 4 bit cao cua bien t
		t |= TL0; //luu gia tri TL0 vao 4 bit thap cua bien t
		t *= 2;  //lay chu ki xung bang cach nhan doi do rong xung

		// +0x30 de doi gia tri tu char sang unikey
		Lcd_Chr(1,5,t/10000 + 0x30);     // lay gia tri hang chuc nghin
		Lcd_Chr_Cp(t%10000/1000 + 0x30); //lay gia tri hang nghin
		Lcd_Chr_Cp(t%1000/100 + 0x30);  //lay gia tri hang tram
		Lcd_Chr_Cp(t%100/10 + 0x30);   //lay gia tri hang chuc
		Lcd_Chr_Cp(t%10 + 0x30);				// lay gia tri hang donvi
		
		f = 1000000 / t;    // do t dang tinh bang uS nen khi doi ra Hz lay 1/1uS = 1000000
		Lcd_Chr(2,5,f/10000 + 0x30); 			// lay gia tri hang chuc nghin
		Lcd_Chr_Cp(f%10000/1000 + 0x30); 	//lay gia tri hang nghin
		Lcd_Chr_Cp(f%1000/100 + 0x30);		 //lay gia tri hang tram
		Lcd_Chr_Cp(f%100/10 + 0x30); 			//lay gia tri han chuc
		Lcd_Chr_Cp(f%10 + 0x30);					// lay gia tri hang don vi
	}
}
