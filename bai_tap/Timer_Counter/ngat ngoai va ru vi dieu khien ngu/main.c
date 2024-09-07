
// lich van nien

#include "main.h"
#include "port.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"
#include "C:\hoc\8051\bai_tap\Library\LCD16x2_4bit\LCD4.h"
#include "C:\hoc\8051\bai_tap\Library\RTC DS1307\Rtc_Ds1307.h"
#include "C:\hoc\8051\bai_tap\Library\Soft I2C\Soft_I2c.h"
#include "C:\hoc\8051\bai_tap\Library\Lunar Calculator\LunarCalendar.h"

unsigned char *code Days[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
bit buttonFlag = 0;  // bien kiem tra trang thai cu nut nhan

//ISR: interrupt service routine: chuong trinh con phuc vu ngat
void EX1_ISR(void) interrupt 2 // tro chuot vao interrupt sau do nhan F1 de xem ngat dang dung la so may
{

}

void main()
{
	unsigned char Hour, Minute, Second, Mode, Day, Date, Month, Year;
	unsigned char SolarDate, SolarMonth;
	char SolarYear;
	
	// bien co cua nut nhan
  bit btnPressed = 0;
	
	Lcd_Init();
	Ds1307_Init();
	Soft_I2c_Init();
	
	//tao xung ghi du lieu voi toc do 1Mhz tu ds1307 ra chan SOUT
	Ds1307_Write(0x07, 0x10);
	
	// ngat canh xuong ( co 2 loai ngat la ngat canh xuong va ngat o muc 0, vo ngat o muc 0 thi IT1 = 0)
	IT1 = 1;
	//cho phep ngat tai INT1 (cho phep ngat tai ITN0 thi EX0 =1 )
	EX1 = 1;
	//cho phep ngat toan bo
	EA = 1;
	
	while(1)
	{
		//doc gia tri gio, phut, giay tu ds1307
		Ds1307_Read_Time(&Hour, &Minute, &Second, &Mode);
		/* vi doan ma o duoi chay rat nhanh nen neu chay tren mach that thi LCD se chop tat lien tuc
				do vay, can mot bien luu trang thai de LCD hoat dong on dinh
		*/

		//hien thi gio
		Lcd_Chr(1, 5, Hour/10 + 0x30);
		Lcd_Chr_Cp(Hour%10+0x30);
		
		Lcd_Chr_Cp(':');
		
		//hien thi phut
		Lcd_Chr_Cp(Minute/10 + 0x30);
		Lcd_Chr_Cp(Minute%10 + 0x30);
		
		Lcd_Chr_Cp(':');
		
		//hien thi giay
		Lcd_Chr_Cp(Second/10 + 0x30);
		Lcd_Chr_Cp(Second%10 + 0x30);	

		// doc gia tri ngay thang nam tu ds1307
		Ds1307_Read_Date(&Day, &Date, &Month, &Year);
		
		// Kiem tra neu nut nhan duoc nhan
		if(BTN == 0 && !btnPressed ) 
		{
			Delay_ms(20);  // chong doi phim
			if(BTN == 0)
			{
				buttonFlag = !buttonFlag;  // Dao trang thai cua bien co
				btnPressed = 1;  // dat trang thai nut nhan dang duoc nhan
			}
		}
		if(BTN == 1) 
		{
			btnPressed = 0;  // Reset trang thai nut nhan khi nut nhan duoc nha ra
		}

		// Display based on the button state
		if(buttonFlag == 0)
		{
			// Hien thi lich duong
			//Xoa man hinh
			Lcd_Out(2, 1, "                ");
			// Hien thi o dong 2 cot 2, thu
			Lcd_Out(2, 2, Days[Day-1]);
			Lcd_Chr_Cp(' ');
			//Hien thi ngay
			Lcd_Chr_Cp(Date/10 + 0x30);
			Lcd_Chr_Cp(Date%10 + 0x30);
			Lcd_Chr_Cp('/');
			// Hien thi thang
			Lcd_Chr_Cp(Month/10 + 0x30);
			Lcd_Chr_Cp(Month%10 + 0x30);
			Lcd_Out_Cp("/20");
			//Hien thi nam
			Lcd_Chr_Cp(Year/10 + 0x30);
			Lcd_Chr_Cp(Year%10 + 0x30);            
		}
		else
		{ 
			// Hien thi lich am
			Solar2Lunar(Date, Month, Year, &SolarDate, &SolarMonth, &SolarYear);
			Lcd_Out(2, 1, "Lunar:");
			//Hien thi ngay
			Lcd_Chr_Cp(SolarDate/10 + 0x30);
			Lcd_Chr_Cp(SolarDate%10 + 0x30);
			Lcd_Chr_Cp('/');
			//Hien thi thang
			Lcd_Chr_Cp(SolarMonth/10 + 0x30);
			Lcd_Chr_Cp(SolarMonth%10 + 0x30);
			Lcd_Chr_Cp('/');
			//Hien thi nam
			Lcd_Chr_Cp((Year+2000)/1000 + 0x30);
			Lcd_Chr_Cp((Year+2000)/100%10 + 0x30);
			Lcd_Chr_Cp((Year+2000)/10%10 + 0x30);
			Lcd_Chr_Cp((Year+2000)%10 + 0x30);
		}
		PCON |=0x01;
	}
}