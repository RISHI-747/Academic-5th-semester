#include<LPC214x.h>

void delay(unsigned int x);
int main(void){
	PINSEL0=0x00000000;
	PINSEL1=0x00000000;
	PINSEL2=0x00000000; 
	IODIR0=0x00078000;
	IODIR1=0x00FF0000;
	IOPIN0=0x00078000;
	IOPIN1=0x00000000;
	
	while(1){
	     IOPIN0=0x00008000;
		 IOPIN1=0x00060000;		// 1
		 delay(1000);
		 IOPIN0=0x00010000;
		 IOPIN1=0x005B0000;		// 2
		 delay(1000);
		 IOPIN0=0x00020000;
		 IOPIN1=0x004F0000;		// 3
		 delay(1000);
		 IOPIN0=0x00040000;
		 IOPIN1=0x00660000; 	// 4
	 	 delay(1000);
	}		 
}

void delay(unsigned int x){
    unsigned int y,z;
    for(y=x; y>0; y--)
        for(z=0; z<x; z++);
}
