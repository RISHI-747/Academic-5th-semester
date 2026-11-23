#include <LPC214X.h>

void delay(int x);

int main(void){
    PINSEL2 = 0x00000000;
    PINSEL1 = 0x00000000;
    PINSEL0 = 0x00000000;

    IO0DIR = 0x00078000;
    IO1DIR = 0x00FF0000;

    IOPIN0 = 0x00078000;

    while (1){
        if (IOPIN1 & 0x01000000){
            IOPIN0 = 0x00008000;
            IOPIN1 = 0x00600000;
            delay(3000);

            IOPIN0 = 0x00010000;
            IOPIN1 = 0x005B0000;
            delay(3000);

            IOPIN0 = 0x00020000;
            IOPIN1 = 0x004F0000;
            delay(3000);
        }

        if (IOPIN1 & 0x02000000){
            IOPIN0 = 0x00008000;
            IOPIN1 = 0x00600000;
            delay(3000);

            IOPIN0 = 0x00010000;
            IOPIN1 = 0x005B0000;
            delay(3000);

            IOPIN0 = 0x00020000;
            IOPIN1 = 0x004F0000;
            delay(3000);
        }
    }

    IO0CLR = 0x00078000;
}

void delay(int x){
    unsigned int y, z;

    for (y = x; y > 0; y--)
        for (z = 0; z < x; z++);
}
