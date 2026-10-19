#include <LPC214x.h>
#define DAC_BIAS 0
void DacInit(void);
void DacOut(unsigned int val);
void _Delay45Us();

void delay(void){
	int i;
	for (i = 0; i < 100; i++)
	_Delay45Us();
}

int main(void){
	unsigned int i = 0;
	DacInit();
	IODIR1 |= 0xFFFF0000;
	IOPIN1 &= ~(0xFFFF0000);
	while (1){
		for (i = 0; i < 1023; i++){
			DacOut(i);
			i = i+15;
		}

		for (i = 0; i > 0; i--){
			DacOut(i);
			i = i-15;
		}
	}
}

void DacInit(void){
	PINSEL1 |= 0x00080000;
}

void DacOut(unsigned int val){
	DACR = (val << 6) | (DAC_BIAS << 16);
}

void _Delay45Us(void){
	volatile unsigned int k;
	for (k = 0; k < 409; k++){
		__asm{
			nop;
		 }	
	} 
}