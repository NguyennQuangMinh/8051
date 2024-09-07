#include "main.h"

void Delay_ms_timer_0(unsigned int t)
{
	do{
		TL0 = 0x18; // luu gia tri 8 bit thap vao thanh ghi TL0
		TH0 = 0xFC; // luu gia tri 8 bit cao vao thanh ghi TH0
		TR0 = 1; //bat dau dem
		while(!TF0); //co bao tran luc chua tran trang thai TF0 = 0
		TR0 = 0; //timer 0 ngung dem
		TF0 = 0; // tat co bao tran
		t--;
	}while(t!=0);
}

void main()
{
	//thiet lap timer 0 mode 1 (Mode timer 16 bit)
	TMOD &= 0xF0; //xoa bo nho timer 0
	TMOD |= 0x01; //set cai dat timer 0 chay mode 1
	while(1)
	{
		P2_0 = !P2_0;
		Delay_ms_timer_0(1000);
	}
}
