#include"main.h"
#include"C:\hoc\8051\bai_tap\Library\Delay\Delay.h"

// ket noi cac nut nhan
sbit BTN1 = P1^0;
sbit BTN2 = P1^1;

// ket noi cac Led
sbit Led = P2^0;

void main()
{
	Led = 0;
	while(1)
	{
		if(BTN1 == 0)
		{
			Delay_ms(20);// chong doi phim
			Led = !Led; // dao trang thai cu led
			while(BTN1 == 0); // dung tai day cho toi khi nut nhan duoc tha ra de tranh truong hop giu phim và Led dao trang thai lien tuc
		}
		if(BTN2 == 0)
		{
			Led = 0;
		}
	}
}
