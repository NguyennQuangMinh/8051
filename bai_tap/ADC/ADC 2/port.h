#ifndef _PORT_H_
#define _PORT_H_

//khai bao cha ket noi cua LCD
sbit LCD_RS	= P0^0;
//sbit LCD_RW = P0^1; (optional)
sbit LCD_EN	= P0^2;

sbit LCD_D4	= P0^4;
sbit LCD_D5 = P0^5;
sbit LCD_D6 = P0^6;
sbit LCD_D7 = P0^7;

// khai bao chan ket noi cua IC adc0804
#define ADC0804_DATA P2

sbit ADC0804_CS = P3^0;
sbit ADC0804_RD = P3^1;
sbit ADC0804_WR = P3^2;
sbit ADC0804_INTR = P3^3;
				
#endif