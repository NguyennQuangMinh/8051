#include "main.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"

unsigned int cnt = 10;

void main()
{
	unsigned int i;
	//chon che do hoat dong Timer 0 - 16 bit su dung dem trong bo nho noi
	TMOD &= 0xF0;
	TMOD |= 0x01;
	
	EA = 1;  //cho phep ngat toan cuc
	ET0  = 1; // cho phep ngat timer 0
	
	// nap gia tri cho 2 thanh ghi TH0 va TL0
	// yeu cau: dem 50000 xung tuong ung voi 50 ms thi se tran
	// ma gia tri toi da co the luu trong 2 thanh ghi la 65535 gia tri, do vay se bat dau dem tu: 65536 - 50000 = 15536, dem den 65536 se bi tran
	TH0 = 0x3C;
	TL0 = 0xB0;
	
	TR0 = 1;  // bat dau dem
	
	while(1)
	{
		// led o port 1 sang dan
		P1 = 0x00;
		Delay_ms(100);
		for(i=0; i<8; i++)
		{
			P1<<=1;
			P1 |= 0x01;
			Delay_ms(100);
		}
	}
}

// khi dem tran se goi ham ngat ben duoi 
void Ngat_Timer0 (void) interrupt 1
{
	//nap lai gia tri cho 2 thanh ghi, ham ngat tu dong xoa co tran
	TH0 = 0x3C;
	TL0 = 0xB0;
	
	// moi lan Timer0 bi tran se nhay vao chay chuowng trinh ngat, ma moi lan nhay vao chuong trinh ngat se mat 50ms do vay can nhay vao chuong trinh ngat 10 lan thi se tao ra duoc 500ms 
	cnt--;
	if(cnt==0){
		cnt = 10;
		
		P2 = ~P2;//dao trang thai cua port P2
	}
}
