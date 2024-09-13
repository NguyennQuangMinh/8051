// khai bao chan ket noi one wire
//sbit OneWire_PIN = P1^0;

//thiet lap timer 0 mode 1 (Mode timer 16 bit) (phuc vu ket noi kieu One Wire)
//TMOD &= 0xF0; //xoa bo nho timer 0
//TMOD |= 0x01; //set cai dat timer 0 chay mode 1

// tap lenh cua cam bien DS18B20
//#define DS18B20_SKIP_ROM  					0xCC //gui lenh den toan bo thiet bi (vi o day co 1 con DS18B20 nen su dung SKIP ROM)
//#define DS18B20_CONVERT_T						0x44 // gui lenh chuyen doi nhiet do sang DS18B20
//#define DS18B20_READ_SCRATCHPAD			0xBE // gui lenh doc gia tri nhiet do tu trong thanh ghi SCRATCHPAD cua DS18B20 ra

#ifndef _ONEWIRE_H_
#define _ONEWIRE_H_

unsigned char OneWire_Reset();
void OneWire_Write1();
void OneWire_Write0();
void OneWire_Write_Bit(unsigned char a);
void OneWire_Write_Byte(unsigned char b);
unsigned char OneWire_Read_Bit();
unsigned char OneWire_Read_Byte();

#endif