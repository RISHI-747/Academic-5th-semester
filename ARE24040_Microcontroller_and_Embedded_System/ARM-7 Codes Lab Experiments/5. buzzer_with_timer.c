#include <LPC214x.h>

void delay(unsigned int x);
int main(void){
    PINSEL0 = 0x00000000;
    IODIR0  = 0x00000400;

    while(1){
        IOPIN0 = 0x00000400;   // Buzzer ON
        delay(1000);
        IOPIN0 = 0x00000000;   // Buzzer OFF
        delay(1000);
    }
}

void delay(unsigned int x){
    unsigned int y,z;
    for(y=x; y>0; y--)
        for(z=0; z<x; z++);
}