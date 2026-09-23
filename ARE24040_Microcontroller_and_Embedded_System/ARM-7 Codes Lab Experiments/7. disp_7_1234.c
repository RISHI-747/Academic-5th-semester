#include <LPC214x.h>

void delay(int x);
int main(void){
    PINSEL0 = 0x00000000;
    IODIR0  = 0x00000800;
	IOPIN0 = 0x00000000;

    while(1){
         IOPIN0 = 0x00000800; 		
        delay(200);
        IOPIN0 = 0x00000000; 
        delay(200);

}}										   	
void delay(int x){
    unsigned int y,z;
    for(y=x; y>0; y--)
        for(z=0; z<x; z++);
}