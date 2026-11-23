#include <LPC214x.h>

int main(void) {
    PINSEL0 = 0x00000000;
    PINSEL1 = 0x00000000;
    PINSEL2 = 0x00000000;

    IODIR0 = 0x00078000;  // P0.15 to P0.18 set as O/P - (Digit Select lines)
    IODIR1 = 0x00FF0000;  // P1.16 to P1.23 set as 0/P (Segment Data lines)

    while (1) {
        IOPIN0 = 0x00008000;         //'A'
        IOPIN1 = 0x00770000;

        IOPIN0 = 0x00010000;         //'R'
        IOPIN1 = 0x00770000;

        IOPIN0 = 0x00020000;         //'E'
        IOPIN1 = 0x00790000;
    }
}
