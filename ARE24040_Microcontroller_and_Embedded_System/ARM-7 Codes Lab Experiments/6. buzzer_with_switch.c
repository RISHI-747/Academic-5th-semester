#include <LPC214x.h>

int main(void){
    PINSEL0 = 0x00000000;
    PINSEL2 = 0x00000000;
    IO0DIR = 0x00000400;   // P0.10 as output

    while(1){
        if(IOPIN1 & 0x01000000){
            IOPIN0 = 0x00000400;  // Buzzer ON
        }
        else{
            IOPIN0 = 0x00000000;  // Buzzer OFF
        }
    }
}