#include "main.h"

void Delay_Timer2_1s()
{
	unsigned int i;
	TR2 = 1; // timer 2 bat dau dem
	for( i=0; i<20 ;i++) //thud hien vong lap 20 lan tuong duong voi 20 lan bao tran => 20*50ms = 1000ms
	{
		while(!TF2); //cho den khi timer 2 bao tran
		TF2 = 0;     // tat co bao tran
	}
	TR2 = 0; //timer 2 dung dem
}

void main()
{
	//thiet lap timer 2 che do 16 bit tu dong nap lai
	T2CON = 0x00; //xoa bo nho thanh ghi T2CON
	T2MOD  = 0x00; // chon che do cho timer2
	
	//dem 50000 xung tuong ung voi 50ms se bi tran => 65536 - 50000 = 15536 => hex = 3CB0
	// luu gia tri 8 bit cao vao 2 thanh ghi tu dong nap lai RCAP2H va 8 bit thap vao thanh ghi RCAP2l
	RCAP2H = 0x3C;
	RCAP2L = 0xB0;
	
	// luu gia tri 8 bit cao vao thanh ghi TH2 va TL2 
	TH2 = 0x3C;
	TL2 = 0xB0;
	
	while(1)
	{ 
		P2 = ~P2;
		Delay_Timer2_1s();
	}
}
