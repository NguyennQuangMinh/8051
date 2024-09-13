// ghi 1 byte du lieu sang EEPROM su dung giao thuc SPI

#include "main.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"
#include "C:\hoc\8051\bai_tap\Library\SPI\SPI.h"
#include "port.h"

//ghi du lieu b sang EEPROM tai dia chi la add
void EEPROM_25LCxxx_Write(unsigned int add, unsigned char b)
{
	//cho phep ghi du lieu
	SPI_CS = 0;
	Soft_SPI_Write(0x06);  // dat chot cho phep ghi du lieu (WREN)
	SPI_CS = 1;
	
	//ghi du lieu b sang add
	SPI_CS = 0;
	Soft_SPI_Write(0x02);  				// cho phep gui du lieu
	Soft_SPI_Write(add>>8); 			//lay 8 bit cao cua dia chi muon luu du lieu len
	Soft_SPI_Write(add & 0x00FF); //lay 8 bit thap cua dia chi muon luu du lieu len
	Soft_SPI_Write(b);	// gui du lieu sang dia chi muon luu sang EEPROm
	SPI_CS = 1;
	//moi lan gui du lieu xong can chu y keo SPI_CS len lai muc 0 de biet rang da gui xong 1 du lieu 
}
void main()
{
	Soft_SPI_Init(); // khoi tao giao thuc SPI
	
	EEPROM_25LCxxx_Write(0,0x09); //gui du lieu 0x01 sang EEPROM tai dia chi 0
	Delay_ms(500);
	EEPROM_25LCxxx_Write(1,0x55); // gui du lieu 0x55 sang EEPROM tai dia chi 1
	while(1)
	{
	
	}
}
