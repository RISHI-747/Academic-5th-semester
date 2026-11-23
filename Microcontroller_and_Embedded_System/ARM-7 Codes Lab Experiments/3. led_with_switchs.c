#include <LPC214x.h>

int main(void){
    PINSEL2 = 0x00000000;
    IODIR1 = 0x00FF0000;      // LEDs output

    while(1){
    	IOPIN1 = ((IOPIN1 >> 8) & 0x00FF0000);
	}
}
