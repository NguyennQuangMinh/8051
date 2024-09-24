#ifndef _PORT_H_
#define _PORT_H_

//khai bao ket noi chan
sbit LCD_RS	= P2^6;
sbit LCD_RW = P2^5; //(optional)
sbit LCD_EN	= P2^7;
sbit LCD_D4	= P0^4;
sbit LCD_D5 = P0^5;
sbit LCD_D6 = P0^6;
sbit LCD_D7 = P0^7;

// khai bao chan ket noi cua ic chuyen doi tin hieu adc ET2046(XPT2046)
sbit DOUT = P3^7;	  
sbit CLK  = P3^6;	  
sbit DIN  = P3^4;	  
sbit CS   = P3^5;	 

#endif