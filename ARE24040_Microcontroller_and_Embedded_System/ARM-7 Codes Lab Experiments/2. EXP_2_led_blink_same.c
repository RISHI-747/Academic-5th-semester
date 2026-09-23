#include <LPC214x.h>

void delay(unsigned int x);
int main(void){
    PINSEL2 = 0x00000000;
    IODIR1  = 0x00FF0000;
    while(1){
        IOPIN1 = 0x00000000;   // LEDs ON
        delay(1000);
        IOPIN1 = 0x00FF0000;   // LEDs OFF
        delay(1000);
    }
}

void delay(unsigned int x){
    unsigned int y,z;
    for(y=x; y>0; y--){
        for(z=0; z<x; z++);
    }
}
