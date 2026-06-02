#include<lpc21xx.h>
#include "lpcfun.h"
#define A1 1<<10
#define A2 1<<11
#define buzzer 1<<12
void uart0_config(void)
{
U0LCR= 0x83;
U0DLL=97;
U0DLM=0;
U0LCR=0x03;
}
char uart0_rx(void)
{
while(((U0LSR>>0)&1)==0);
return U0RBR;
}
void rfid_rx(char *rfid)
{
int i;
for(i=0;i<12;i++)
	rfid[i]= uart0_rx();
rfid[i]='\0';
}
void door_open(void)
{
IOCLR0=A1;
IOSET0=A2;
delay_ms(1000);
}
void door_close(void)
{
IOCLR0=A2;
IOSET0=A1;
delay_ms(1000);
}

int main() {
int n=1;
char rfid_uid[13];
char org_uid[13];	
lcd_init();
PINSEL0=0x5;
IODIR0|=A1|A2|lcd1|buzzer;
IODIR0|=lcd2;	
IOSET0=A1|A2|buzzer;
uart0_config();

while(1)
{
lcd_cmd(0x80);
lcd_str("Scan ur Tag");
rfid_rx(rfid_uid);
if(strcmp(org_uid,rfid_uid)==0)
{
	lcd_cmd(0xc0);
	lcd_str("Access Granted!");
	door_open();
	door_close();
	IOSET0=A1|A2;
}
else{
	n++;
	lcd_cmd(0xc0);
	lcd_str("Access Denied!");
	IOCLR0=buzzer;
	delay_ms(300);
	IOSET0=buzzer;
	delay_ms(1500);
	lcd_cmd(0x01);
	if(n<3)
	{
		lcd_cmd(0x80);
	  lcd_str("Try again in 5");
	  delay_ms(1000);
		
		lcd_cmd(0x80);	
		lcd_str("Try again in 4");
		delay_ms(1000);
		
		lcd_cmd(0x80);
		lcd_str("Try again in 3");
		delay_ms(1000);
		
		lcd_cmd(0x80);
		lcd_str("Try again in 2");
		delay_ms(1000);
	
		lcd_cmd(0x80);
		lcd_str("Try again in 1");	
		delay_ms(1000);

		lcd_cmd(0xc0);	
		lcd_str("Access Denied!");
		delay_ms(300);
		lcd_cmd(0x01);
	
		lcd_cmd(0xc0);
		lcd_str("Access Denied!");
		delay_ms(300);
		lcd_cmd(0x01);
	
		lcd_cmd(0xc0);
		lcd_str("Access Denied!");
		delay_ms(300);
		lcd_cmd(0x01);
		
		lcd_cmd(0xc0);
		lcd_str("Access Denied!");
		delay_ms(300);
		lcd_cmd(0x01);
		
		lcd_cmd(0xc0);
		lcd_str("Access Denied!");
		delay_ms(300);
		lcd_cmd(0x01);
		
		lcd_cmd(0xc0);
		lcd_str("Access Denied!");
		delay_ms(300);
		lcd_cmd(0x01);
		
		lcd_cmd(0xc0);
		lcd_str("Access Denied!");
		delay_ms(300);
		lcd_cmd(0x01);
		
		lcd_cmd(0xc0);
		lcd_str("Access Denied!");
		delay_ms(300);
		lcd_cmd(0x01);
}
}
}
}





