#include <LPC214x.h>
void PWM (void){
	PINSEL0|=(1<<17)|(1<<19) ;
	PINSEL0 &=~((1<<16)|(1<<18));
	PWMTCR=0x02;
	PWMPR=0;
	PWMMR0=2000000;
	PWMMCR= (1<<1);
	PWMMR4= 1500000;
	PWMMR6= 500000;
	PWMLER= (1<<0)|(1<<4)|(1<<6);
	PWMPCR= (1<<12)|(1<<14);
	PWMTCR=0x09;
}	

void PWM4 (unsigned int d){
	PWMMR4= d;
	PWMLER |=(1<<4);
}

void PWM6 (unsigned int d){
	PWMMR4= d;
	PWMLER |=(1<<6);
}

int main (void){
	PWM();
	while(1){
	}
}