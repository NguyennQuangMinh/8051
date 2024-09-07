#include "main.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"


// Mang chua ma cua led 7 doan Anode chung, va duoc luu trong bo nho chuowng trinh (bo nho chuong trinh cua 8051 la 4Kb)
unsigned char code Code7Seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x00, 0x10}; 
															//  0			1			2			3			4			5			6			7			8			9

void main()
{
	// led 7seg su dung o bai nay la anode chung
	//do cac chan cua led 7 doan duoc noi voi port 2 nen cac chan tuong ung voi cac so la:
	// P2_0 <=> a
	// P2_1 <=> b
	// P2_2 <=> c
	// P2_3 <=> d
	// P2_4 <=> e
	// P2_5 <=> f
	// P2_6 <=> g

	// P2_7 khong noi voi chan nao cua led 7seg nen co the tuy chon muc logic thong thuong se de muc logic la 1 de de doi sang he HEX
	/*muon hien thi so 1 thi can bat chan b va chan c, do led o bai nay la anode chung nen muon bat sang o vi tri nao thi can cap muc logic 0 cho chan do
	
	  			 			g      f      e     d      c       b     a 
	 		P2_7		P2_6   P2_5   P2_4   P2_3   P2_2   P2_1   P2_0
				1				1      1      1     1    		0			 0		 1		=> hien thi so 1 => Hex = 0xF9	*/
//	P2 = 0xF9;
	
	// lam tuong tu voi cac so khac
	/* vi du muon hien thi so 0 thi phai bat cac led o chan a, b, c, d, e, f
	
	  			 			g      f      e     d      c       b     a 
	 		P2_7		P2_6   P2_5   P2_4   P2_3   P2_2   P2_1   P2_0
				1				1      0      0     0    		0			 0		 0		=> hien thi so 1 => Hex = 0xC0	
	P2 = 0xC0;	
	*/
				
	/*
		dem tu 1 -> 9 su dung led 7 doan
	*/
	unsigned char i;
	while(1)
	{
		for(i=0; i<10; i++)
		{
			P2 = Code7Seg[i];
			Delay_ms(1000);
		}
	
	}
}

