#include <LPC214x.h>

int main(void){
    PINSEL2 = 0x00000000;
    IODIR1  = 0x00FF0000;
    while(1){
        IOPIN1 = 0x00FE0000;   // Only LED at P1.16 ON
    }
}