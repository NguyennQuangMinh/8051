#include "main.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"
#include "port.h"
#include "C:\hoc\8051\bai_tap\Library\SPI\SPI.h"

unsigned int 

void EEPROM_25LCxxx_PageWrite(unsigned char P);
unsigned char EEPROM_25LCxxx_WIP();
void main()
{
	Soft_SPI_Init();
	EEPROM_25LCxxx_PageWrite(0xAA);
	while(1)
	{
	
	}
}

void EEPROM_25LCxxx_PageWrite(unsigned char P)
{
	SPI_CS = 0;
	Soft_SPI_Write(0x06);
	SPI_CS = 1;
	
	SPI_CS = 0;
	Soft_SPI_Write(P);
	SPI_CS = 1;
	while(EEPROM_25LCxxx_WIP());
}
unsigned char EEPROM_25LCxxx_WIP()
{
	unsigned result;
	SPI_CS = 0;
	Soft_SPI_Write(0x05);
	result = Soft_SPI_Read();
	SPI_CS = 1;
	
	return result & 0x01;
}
