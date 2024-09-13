#include "main.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"
#include "port.h"
#include "C:\hoc\8051\bai_tap\Library\SPI\SPI.h"

unsigned char EEPROM_25LCxxx_WIP();
void EEPROM_25LCxxx_Write(unsigned int add, unsigned char b);
unsigned char EEPROM_25LCxxx_Read(unsigned int add);

void main()
{
	unsigned int i;
	Soft_SPI_Init(); //khoi tao giao thuc SPI
	
	/* Gui 1 byte du lieu
	EEPROM_25LCxxx_Write(0, 0x01); // ghi du lieu 0x50 len EEPROM tai dia chi 0

	P3 = EEPROM_25LCxxx_Read(0);   // doc du lieu ve tu EEPROM tai dia chi 0 xuat ra port 3
	*/
	
	// gui 100 byte du lieu tu 0-99
	for(i=0; i<100; i++)
	{
		EEPROM_25LCxxx_Write(i,i);
	}
	
	while(1)
	{
		// doc 100 byte du lieu tu EEPROM ve
		for(i=0; i<100; i++)
		{
			P3 = EEPROM_25LCxxx_Read(i);
			Delay_ms(500);
		}
	
	}
}

//ghi du lieu sang EEPROM tai dia chi add
void EEPROM_25LCxxx_Write(unsigned int add, unsigned char b)
{
	//cho phep ghi du lieu len EEPROM
	SPI_CS = 0;
	Soft_SPI_Write(0x06); //chot cho phep ghi du lieu (WREN)
	SPI_CS = 1;
	
	// ghi du lieu b sang dia chi add tren EEPROM
	SPI_CS = 0;
	Soft_SPI_Write(0x02); 				//cho phep ghi du lieu len EEPROM
	Soft_SPI_Write(add>>8); 			//gui 8 bit cao cua dia chi add sang EEPROM
	Soft_SPI_Write(add & 0x00FF);	// gui 8 bit thap cua dia chi add sang EEPROM
	Soft_SPI_Write(b);						// ghi du lieu len dia chi add cua EEPROM
	SPI_CS = 1;
	
	while(EEPROM_25LCxxx_WIP());	// kiem tra bit cuoi cung bang 0 thi la da gui het
}

// kiem tra trang thai cua EEPROM
unsigned char EEPROM_25LCxxx_WIP()
{
	unsigned char result;
	SPI_CS = 0;
	Soft_SPI_Write(0x05); // gui bit 0x05 la bit yeu cau kiem tra trang thai sang EEPROM
	result = Soft_SPI_Read();
	SPI_CS = 1;
	return result & 0x01; // tra ve gia tri cua EEPROM_25LCxxx_WIP
}

// doc du lieu tu EEPROM ve tai dia chi add
unsigned char EEPROM_25LCxxx_Read(unsigned int add)
{
	unsigned char b;
	
	SPI_CS = 0;
	Soft_SPI_Write(0x03);				// cho phep doc du lieu tu EEPROM ve
	Soft_SPI_Write(add>>8);			// lay 8 bit cao cua dia chi can doc 
	Soft_SPI_Write(add & 0x00FF); //lay 8 bit thap cua dia chi can doc 
	b = Soft_SPI_Read();					// doc du lieu tu EEPROM ve tai dia chi add gan vao bien b
	SPI_CS = 1;
	
	return b;
}
