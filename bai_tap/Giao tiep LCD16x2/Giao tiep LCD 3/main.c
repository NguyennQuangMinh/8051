#include "main.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"

// khai bao ket noi chan LCD
#define LCD_DATA P3
sbit LCD_RS = P2^0;
sbit LCD_EN = P2^1;

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

//ham ghi 1 ky tu vao 1 vi tri bat ky ( xac dinh row, col)
void LCD_CHR(unsigned char row, unsigned char col, char c)
{
	unsigned char cmd;
	cmd = (row==1?0x80:0xC0) + col - 1;
	LCD_CMD(cmd);
	LCD_CHR_CP(c);
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

// ham ghi 1 chuoi ky tu len 1 vi tri bat ky
void LCD_OUT(unsigned char row, unsigned char col, char *str)
{
	unsigned char cmd;
	cmd = (row==1?0x80:0xC0) + col - 1;
	LCD_CMD(cmd);
	LCD_OUT_CP(str);
}

void LCD_INIT() 
{
	// khoi tao LCD che do 8 bit, 2 dong
	LCD_CMD(0x30);
	Delay_ms(5);
	LCD_CMD(0x30);
	Delay_ms(1);
	LCD_CMD(0x30);
	
	LCD_CMD(0x38);// khoi tao che do 8 bit, 2 dong
	LCD_CMD(0x01);// xoa man hinh
	LCD_CMD(0x0C);// bat che do hien thi LCD, Tat con tro man hinh
}

void main()
{
	LCD_INIT();
	LCD_CHR(1,16,'K');// viet ky tu 'K' tai dong 1 cot 6
	LCD_OUT(2,2,"HELLO");//viet chuoi ky tu 'HELLO' tai dong 2 cot 2
	while(1)
	{
	
	}
}

