#include "main.h"

void Delay_Timer2_1ms(unsigned int t)
{
	do
	{
		TR2 = 1;      // Timer 2 bat dau dem
		while(!TF2); //cho den khi timer 2 bao tran
		TF2 = 0;     // tat co bao tran
		TR2 = 0;		// Timer 2 ngung dem
		t--;
	}while(t!=0);
}

void main()
{
	//thiet lap che do timer 2, 16bit tu dong nap lai
	T2CON = 0x00; //xoa bo nho thanh ghi T2CON
	T2MOD = 0x00;
	
	// dem 1000 xung thi se tra tuong duong voi 1ms => 65536 - 1000 = 64536 => HEX = 3CB0
	// luu gia tri tu dong nap lai vao 2 thanh ghi RCAP2L va RCAP2H
	RCAP2L = 0x18;
	RCAP2H = 0xFC;
	
	// luu 2 gia tri dem vao 2 thanh ghi TL2 va TH2
	TL2 = 0x18;
	TH2 = 0xFC;
	
	while(1)
	{
		P2 = ~P2;
		Delay_Timer2_1ms(1000); //delay 1 giay
		
	}
}
