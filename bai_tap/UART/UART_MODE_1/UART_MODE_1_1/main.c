#include "main.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"

void main()
{
	char c;
	SM0 = 0; SM1 =1;  // khoi tao UART kieu 1
	TMOD = 0x20;			// 0010_0000 - Timer 1 hoat dong o che do 8 bit tu dong nap lai
	TH1 = 0xFD;      	// khoi tao toc do baud 9600
	TR1 = 1; 					// Start Timer 1
	TI = 1;						// san sang gui du lieu
	for( c='a'; c<='z'; c++)
	{
		while(TI == 0); // neu viec gui ky tu truoc do chua hoan thanh se cho 
		TI = 0;
		SBUF = c;
	}
	while(1)
	{
	
	}
}
