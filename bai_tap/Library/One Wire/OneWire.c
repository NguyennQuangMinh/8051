// khai bao chan ket noi one wire
//sbit OneWire_PIN = P1^0;

//thiet lap timer 0 mode 1 (Mode timer 16 bit) (phuc vu ket noi kieu One Wire)
//TMOD &= 0xF0; //xoa bo nho timer 0
//TMOD |= 0x01; //set cai dat timer 0 chay mode 1

// tap lenh cua cam bien DS18B20
//#define DS18B20_SKIP_ROM  					0xCC //gui lenh den toan bo thiet bi (vi o day co 1 con DS18B20 nen su dung SKIP ROM)
//#define DS18B20_CONVERT_T						0x44 // gui lenh chuyen doi nhiet do sang DS18B20
//#define DS18B20_READ_SCRATCHPAD			0xBE // gui lenh doc gia tri nhiet do tu trong thanh ghi SCRATCHPAD cua DS18B20 ra

#include "C:\hoc\8051\bai_tap\Library\T0_Delay_us\T0_Delay_us.h"
#include "C:\hoc\8051\bai_tap\Library\One Wire\OneWire.h"
#include "main.h"
#include "port.h"

// return 0: ok
// return 1: fail
unsigned char OneWire_Reset()
{
	unsigned char result;
	
	OneWire_PIN = 0;
	T0_Delay_us(480);
	
	OneWire_PIN = 1;
	T0_Delay_us(70);
	
	result = OneWire_PIN;
	
	T0_Delay_us(410);
	
	return result;
}

// ghi bit 1
void OneWire_Write1()
{
	OneWire_PIN = 0;
	T0_Delay_us(6);
	
	OneWire_PIN = 1;
	T0_Delay_us(64);
}

//ghi bit 0
void OneWire_Write0()
{
	OneWire_PIN = 0;
	T0_Delay_us(60);
	
	OneWire_PIN = 1;
	T0_Delay_us(10);
}

// ghi 1 trong 2 bit 0 hoac 1
void OneWire_Write_Bit(unsigned char a)
{
	if(a == 1)
	{
		OneWire_Write1();
	}
	else
	{
		OneWire_Write0();
	}
}

// gui di 1 byte
void OneWire_Write_Byte(unsigned char b)
{
	unsigned i=8;
	while(i--)
	{
		OneWire_Write_Bit(b&0x01);
		b>>=1;
	}
}


// doc ve 1 bit
unsigned char OneWire_Read_Bit()
{
	unsigned char result;
	
	OneWire_PIN = 0;
	T0_Delay_us(6);
	
	OneWire_PIN = 1;
	T0_Delay_us(9);
	
	result = OneWire_PIN;
	T0_Delay_us(55);
	
	return result;
}

// doc ve 1 byte
unsigned char OneWire_Read_Byte()
{
	unsigned char i = 8, result = 0;
	while(i--)
	{
		result >>= 1;
		result |= (OneWire_Read_Bit() << 7);
	}
	return result;
}
