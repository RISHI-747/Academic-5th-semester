#include<LPC214x.h>
int main (void){
	PINSEL0 = 0X00000000;
	IO0DIR = 0X00000400;
	IOPIN0 = 0X00000000;

	while(1){
		IOPIN0 = 0X00000400;
	}
}
