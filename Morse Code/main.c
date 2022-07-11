#include <at89c5131.h>
#include "lcd.h"				//Header file with LCD interfacing functions
#include "MorseCode.h"	//Header file for Morse Code 

sbit LED=P1^7;
sbit inbit0 = P1^0;
bit membit0;
sbit inbit1 = P1^1;
bit membit1;
sbit inbit2 = P1^2;
bit membit2;
sbit inbit3 = P1^3;
bit membit3;
/*
Port P0.7 is used for the audio signal output
*/	
//Main function

void main(void)
{
		
	//Call initialization functions
	lcd_init();
	
	membit0 = inbit0;
	membit1 = inbit1;
	membit2 = inbit2;
	membit3 = inbit3;
	
	if(membit0){
		lcd_cmd(135);
		lcd_write_char('A');
		morsea();
	}
	else if(membit1){
		lcd_cmd(135);
		lcd_write_char('B');
		morseb();
	}
	else if(membit2){
		lcd_cmd(135);
		lcd_write_char('C');
		morsec();
	}
	else if(membit3){
		lcd_cmd(135);
		lcd_write_char('D');
		morsed();
	}
	else {
		lcd_cmd(135);
		lcd_write_char('E');
		morsee();
	}
	
	while(1){
		
	}

}
