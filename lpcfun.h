#include<lpc21xx.h>
/*#define lcd 0xff
#define rs 1<<24
#define e 1<<25*/
#define lcd1 (1<<4)|(1<<5)|(1<<6)|(1<<7)
#define lcd2 (1<<23)|(1<<24)|(1<<25)|(1<<26)
#define lcd (lcd1)|(lcd2)
#define rs 1<<8
#define e 1<<9
void delay_ms(int ms)
{
	T0PR=15000-1;
	T0TCR=0x01;
	while(T0TC<ms);
	T0TCR=0x03;
	T0TCR=0x00;
}
void delay_s(int ms)
{
	T0PR=15000000-1;
	T0TCR=0x01;
	while(T0TC<ms);
	T0TCR=0x03;
	T0TCR=0x00;
}
void lcd_cmd(unsigned char cmd)
{
	IOCLR0=lcd;
	IOSET0=cmd;
	IOCLR0=rs;
	IOSET0=e;
	delay_ms(2);
	IOCLR0=e;
}
void lcd_init(void)
{
	IODIR0= lcd|rs|e;
	lcd_cmd(0x01);
	lcd_cmd(0x02);
	lcd_cmd(0x0c);
	lcd_cmd(0x38);
}
void lcd_data(unsigned char d)
{
	IOCLR0=lcd;
	IOSET0=d;
	IOSET0=rs;
	IOSET0=e;
	delay_ms(2);
	IOCLR0=e;
}
void lcd_str(unsigned char *s)
{
	int count=0;
	while(*s){
		lcd_data(*s++);
		count ++;
		if(count==16)
			lcd_cmd(0xc0);
	}
}
void lcd_int(int n){
	unsigned char arr[5];
	signed int i=0;
	if(n==0)
		lcd_data('0');
	else
	{
		if(n<0)
		{
			lcd_data('-');
			n=-n;
		}
		while(n>0){
			arr[i++]=n%10;
			n/=10;
		}
		for(i=i-1;i>=0;i--)
		lcd_data(arr[i]+48);
	}
}

