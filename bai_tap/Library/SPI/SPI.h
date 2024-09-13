//khai bao ket noi chan SPI
//sbit SPI_SCLK = P2^0;
//sbit SPI_MOSI = P2^1;
//sbit SPI_MISO = P2^2;
//sbit SPI_CS = P2^3;

#ifndef _SPI_H_
#define _SPI_H_

// SPI mode 0: CPOL =0; CPHA = 0
void Soft_SPI_Init();
void Soft_SPI_Write(unsigned char b);
unsigned char Soft_SPI_Read();

#endif