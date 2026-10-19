#include <LPC214x.h>

int main(void){
    PINSEL2 = 0x00000000;
    IODIR1  = 0x00FF0000;

    while(1){
        if(IOPIN1 & 0x01000000){
            IOPIN1 = 0x00010000;
        }
        else{
            IOPIN1 = 0x00000000;
        }
    }
}
