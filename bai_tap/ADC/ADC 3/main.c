//du dung ic ADC0808 doc gia tri ADC hien thi LCD

#include "main.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"
#include "Port.h"
#include "C:\hoc\8051\bai_tap\Library\LCD16x2_4bit\LCD4.h"
#include "C:\hoc\8051\bai_tap\Library\ADC0808\ADC0808.h"
#include "String.h"

void main()
{
	unsigned char adc_value;
	unsigned int voltage;
	LCD_RW = 0; // keo chan RW cua LCD xuong muc 0 de vao che do ghi du lieu len LCD (dat truoc ham khoi tao LCD)
	Lcd_Init(); // khoi tao LCD
	while(1)
	{
		// doc gia tri ADC
		adc_value = ADC0808_Read(0); // doc gia tri ADC tu kenh 0 cua ADC0808
		Lcd_Out(1,1,"ADC value: ");
		Lcd_Chr_Cp(adc_value/100 + 0x30);
		Lcd_Chr_Cp(adc_value%100/10 + 0x30);
		Lcd_Chr_Cp(adc_value%10 + 0x30);
		
		// doc gia tri voltage
		voltage = (unsigned int)adc_value*(5.0/255.0)*100;
		Lcd_Out(2,1,"voltage: ");
		Lcd_Chr_Cp(voltage/100 + 0x30);
		Lcd_Chr_Cp('.');
		Lcd_Chr_Cp(voltage%100/10 + 0x30);
		Lcd_Chr_Cp(voltage%10 + 0x30);
		
		Delay_ms(500); // trang man hinh LCD nhap nhay lien tuc
	}
}
