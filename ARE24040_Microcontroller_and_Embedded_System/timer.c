#include<LPC214x.h>

void initPLL(void){
PLL0CFG = 0x24 ;
PLL0CON = 0X01;

PLL0FEED = 0xAA;
PLL0FEED = 0XAA;

while((PLL0STAT & 0x400) == 0);
PLL0CON = 0x03;
PLL0FEED = 0xAA;
PLL0FEED = 0x55;

VPBDIV = 0x01;
}

void delayms(unsigned int ms){
T0CTCR = 0x00;
T0PR = 59999;
T0TC = 0;
T0TCR = 0x01;

while(T0TC < ms);
T0TCR = 0x00;
}

int main(void){
 initPLL();
 PINSEL2 = 0x00000000;
 IO1DIR = 0x00FF0000;
 IOPIN1 = 0x00000000;

 while(1){
 	IOPIN1 = 0x00550000;
	delayms(2000);
	IOPIN1 = 0x000000000;
	IOPIN1 = 0x00AA0000;
	delayms(2000);

 }
}