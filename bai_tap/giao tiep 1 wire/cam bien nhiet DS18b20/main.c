#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"
#include "C:\hoc\8051\bai_tap\Library\T0_Delay_us\T0_Delay_us.h"
#include "C:\hoc\8051\bai_tap\Library\One Wire\OneWire.h"
#include "main.h"
#include "port.h"

#define DS18B20_SKIP_ROM  					0xCC //gui lenh den toan bo thiet bi (vi o day co 1 con DS18B20 nen su dung SKIP ROM)
#define DS18B20_CONVERT_T						0x44 // gui lenh chuyen doi nhiet do sang DS18B20
#define DS18B20_READ_SCRATCHPAD			0xBE // gui lenh doc gia tri nhiet do tu trong thanh ghi SCRATCHPAD cua DS18B20 ra


unsigned char code  Code7Seg[]={0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

void main()
{
	unsigned int temp;
	unsigned char int_part, decimal_part;
	//thiet lap timer 0 mode 1 (Mode timer 16 bit)
	TMOD &= 0xF0; //xoa bo nho timer 0
	TMOD |= 0x01; //set cai dat timer 0 chay mode 1
	
	while(1)
	{
		// gui lenh chuyen doi sang DS18B20
		while(OneWire_Reset());
		OneWire_Write_Byte(DS18B20_SKIP_ROM);
		OneWire_Write_Byte(DS18B20_CONVERT_T);
		
		Delay_ms(800); // cho cho DS18B20 chuyen doi gia tri sang nhiet do voi thoi gian toi da chuyen doi la 750ms
		
		// gui lenh lay gia tri tu DS18B20 ve
		while(OneWire_Reset());
		OneWire_Write_Byte(DS18B20_SKIP_ROM);
		OneWire_Write_Byte(DS18B20_READ_SCRATCHPAD);
		
		temp = OneWire_Read_Byte(); 							// doc ve 8 bit thap
		temp = (OneWire_Read_Byte()<<8) | temp;		// doc ve 8 bit cao va luu 16 bit lai vao bien temp
		
		int_part = temp>>4;  								// lay gia tri nguyen nhiet do
		decimal_part = temp & 0x000F; 			// lay bit chua gia tri thap phan cua nhiet do
		decimal_part = decimal_part*10/16; 	// doi tu nhi phan sang thap phan lay so dau tien
		
		P0 = Code7Seg[int_part/10];
		P2 = Code7Seg[int_part%10];
		P3 = Code7Seg[decimal_part];
	
	}
}
