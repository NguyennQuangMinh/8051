// khai bao chan ket noi cua key pad
//sbit COL_1 = P1^0;
//sbit COL_2 = P1^1;
//sbit COL_3 = P1^2;
//sbit COL_4 = P1^3;

//sbit ROW_1 = P1^4;
//sbit ROW_2 = P1^5;
//sbit ROW_3 = P1^6;
//sbit ROW_4 = P1^7;

#include"Keypad4x4.h"
#include"main.h"
#include"port.h"

unsigned char KeyPress()
{
 	unsigned char key = 0xFF;  // khoi tao 1 gia tri khong hop le de kiem tra
	
	// Kiem tra hang 4
	ROW_4 = 0;
	if(COL_4 == 0) key = 0;
	if(COL_3 == 0) key = 1;
	if(COL_2 == 0) key = 2;
	if(COL_1 == 0) key = 3;
	ROW_4 = 1;

	// Kiem tra hang 3
	ROW_3 = 0;
	if(COL_4 == 0) key = 7;
	if(COL_3 == 0) key = 6;
	if(COL_2 == 0) key = 5;
	if(COL_1 == 0) key = 4;
	ROW_3 = 1;

	// Kiem tra hang 4
	ROW_2 = 0;
	if(COL_4 == 0) key = 8;
	if(COL_3 == 0) key = 9;
	if(COL_2 == 0) key = 10;
	if(COL_1 == 0) key = 11;
	ROW_2 = 1;

	// Kiem tra hang 4
	ROW_1 = 0;
	if(COL_4 == 0) key = 15;
	if(COL_3 == 0) key = 14;
	if(COL_2 == 0) key = 13;
	if(COL_1 == 0) key = 12;
	ROW_1 = 1;
	
	return key;	
}