/*vdk o cac chan luc khoi dong se o muc 1 nen khi khoi dong se xuat ra dien ap 5V luon dieu nay rat nguy hiem cho he thong mach dien lon
	do vay, ta su dung transistor PNP lay dien ap 0V kich mo de dam bao an toan cho mach dien, 
	luc nay can dieu khien vdk xuat ra muc dien ap 0v de kich mo dieu khien
*/
#include"main.h"
#include"C:\hoc\8051\bai_tap\Library\Delay\Delay.h"
sbit btn = P1^0;
sbit relay = P2^0;

void main()
{
	while(1)
	{
		if(btn == 0)
		{
			Delay_ms(20); //chong doi phim
			relay = !relay;
			while(btn == 0);
		}
	
	}
}

