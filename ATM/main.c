#include <at89c5131.h>
#include "endsem.h"

char S_str[6]= {0,0,0,0,0,0};   //String for Balance Sita
char G_str[6] = {0,0,0,0,0,0};  //String for Balance Gita
char n500_s[3]= {0,0,0};    // STRING FOR 500RS NOTE
char n100_s[3]= {0,0,0};    // STRING FOR 100RS NOTE

char password[5] = {0,0,0,0,0} ;   //PASSWORD ARRAY
//Main function

//-------------------------------------------------
void money(void)
{
	unsigned char money = receive_char();
	int a = 100*money;
	char b =0;
  char c= 0;
	int_to_string(a/500,&b);
	int_to_string((a%500)/100,&c);
	transmit_char(b);
	transmit_string("\r\n");
	transmit_char(c);
}
void account(void)
{
	unsigned char number = receive_char();
	switch(number)
	{
		case '1': transmit_string("Account Holder: Sita\r\n");
			        transmit_string("Account Balance: 10000\r\n");
							 break;
		case '2': transmit_string("Account Holder: Gita\r\n");
			        transmit_string("Account Balance: 10000\r\n");
							 break;
		default : transmit_string("No such account, please enter valid details\r\n");
			        break;
	}
	return;
}

void withdraw(void)
{
	unsigned char number = receive_char();
	switch(number)
	{
		case '1': transmit_string("Enter Amount in hundreds\r\n");
              money();
   case '2': transmit_string("Enter Amount in hundreds\r\n");
              money();		
	 default: transmit_string("Invalid");
		 
	}
	
}





void main(void)
{
	uart_init();
	//unsigned int s = 10000;
	//unsigned int g = 10000;
	transmit_string("Press A for Account display and W for withdrawing cash\r\n");            // Please finish this function in endsem.h 
    while (1)
    {
     unsigned char ch = receive_char();
			switch(ch)
			{
			  case 'A': transmit_string("Hello, Please enter Account number\r\n");
					        account();
				          break;
				
				case 'W': transmit_string("Withdraw state, enter account number\r\n");
				          withdraw();
			}
    }
}


