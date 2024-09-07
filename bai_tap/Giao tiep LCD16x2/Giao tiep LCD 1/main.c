#include "main.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"

// khai bao ket noi chan LCD
#define LCD_DATA P0
sbit LCD_RS = P2^6;
sbit LCD_EN = P2^7;
sbit LCD_RW = P2^5;

//ham ghi lenh
void LCD_CMD(unsigned char cmd)
{
		// cho chan RS xuong muc thap de LCD hieu la ta muon ghi lenh
		LCD_RS = 0;
		// DATA = lenh
		LCD_DATA = cmd;
		//tao xung tren chan EN de cho phep ghi du lieu bang cach bat keo xuong 0 sau do bat len 1 hoac nguoc lai
		LCD_EN = 0;
		LCD_EN = 1;
		// voi nhung lenh nho hon 0x02 thi Delay khoang 1.53s, con lon hon se Delay khoang 37us do vay ta chon 2ms cho lenh <=0x02 va 1ms cho nhung lenh >0x02
		if(cmd <= 0x02)
		{
			Delay_ms(2);
		}
		else
		{
			Delay_ms(1);
		}
}

// ham ghi 1 ky tu len LCD
void LCD_CHR_CP(char c) //Current Position
{
		// cho chan RS len muc cao de LCD hieu la ta muon ghi du lieu len LCD
		LCD_RS = 1;
		// DATA = lenh
		LCD_DATA = c;
		//tao xung tren chan EN de cho phep ghi du lieu bang cach bat keo xuong 0 sau do bat len 1 hoac nguoc lai
		LCD_EN = 0;
		LCD_EN = 1;
		Delay_ms(1);
}
//ham ghi 1 chuoi ky tu len LCD
void LCD_OUT_CP(char *str)
{
	unsigned char i = 0;
	while( *(str+i ) != 0 )
	{
		LCD_CHR_CP( *(str+i) );
		i++;
	}

}
void main()
{
	//bat hien thi lcd va bat hien thi con tro
//	LCD_CMD(0x0E);
	//bat hien thi lcd va tat hien thi con tro
	LCD_CMD(0x0C);
	//hien thi ky tu A len man hinh
//	LCD_CHR_CP('A');
	//hien thi chuoi ky tu "Hello World"
	LCD_OUT_CP("Hello World");
	while(1)
	{
	
	}
}
