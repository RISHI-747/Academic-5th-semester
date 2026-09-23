#include <LPC214x.h>

void delay(int x);
int main(void){
    PINSEL0 = 0x00000000;
    IODIR0  = 0x00000800;
	IOPIN0 = 0x00000000;

    while(1){
       if(IOPIN1 & 0x01000000){
         IOPIN0 = 0x00000800; 		
        delay(1000);
        IOPIN0 = 0x00000000; 
        delay(1000);
 }
 		else if(IOPIN1 & 0x02000000){
         IOPIN0 = 0x00000800; 		
        delay(700);
        IOPIN0 = 0x00000000; 
        delay(700);
 }

 else if(IOPIN1 & 0x03000000){
         IOPIN0 = 0x00000800; 		
        delay(500);
        IOPIN0 = 0x00000000; 
        delay(500);
 }

 else if(IOPIN1 & 0x04000000){
         IOPIN0 = 0x00000800; 		
        delay(400);
        IOPIN0 = 0x00000000; 
        delay(400);
 }

 else if(IOPIN1 & 0x05000000){
         IOPIN0 = 0x00000800; 		
        delay(300);
        IOPIN0 = 0x00000000; 
        delay(300);
 }

 else{
 	IOPIN1 = 0x00000000;
 }


}}
void delay(int x){
    unsigned int y,z;
    for(y=x; y>0; y--)
        for(z=0; z<x; z++);
}