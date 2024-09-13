//khai bao ket noi chan SPI
//sbit SPI_SCLK = P2^0;
//sbit SPI_MOSI = P2^1;
//sbit SPI_MISO = P2^2;
//sbit SPI_CS = P2^3;

#include "main.h"
#include "port.h"
#include "C:\hoc\8051\bai_tap\Library\SPI\SPI.h"

// SPI mode 0: CPOL =0; CPHA = 0
void Soft_SPI_Init()
{
	SPI_CS = 1;
	SPI_SCLK = 0;
	SPI_MISO = 1;
}

// ghi 1 byte du lieu
void Soft_SPI_Write(unsigned char b)
{
	unsigned char i;
	for(i=0; i<8;i++)
	{
		if( (b&0x80)==0x80 )
		{
			SPI_MOSI = 1;
		}else{ 
			SPI_MOSI = 0;
		}
		SPI_SCLK = 1;
		SPI_SCLK = 0;
		b<<=1;
	}
}

// doc 1 byte du lieu
unsigned char Soft_SPI_Read()
{
	unsigned char i,b;
	for(i=0; i<8; i++)
	{
		b<<=1;
		SPI_SCLK = 1;
		if(SPI_MISO)
		{
			b |= 0x01;
		}
		SPI_SCLK = 0;
	}
	return b;
}