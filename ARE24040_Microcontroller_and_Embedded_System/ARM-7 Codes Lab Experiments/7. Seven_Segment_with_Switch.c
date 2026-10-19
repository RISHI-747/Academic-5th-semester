#include<LPC214x.h>

void delay(unsigned int x);
int main(void){
	PINSEL0=0x00000000;
	PINSEL1=0x00000000;
	PINSEL2=0x00000000; 
	IODIR0=0x00078000;
	IODIR1=0x00FF0000;
	IOPIN0=0x00078000;
	IOPIN1=0x00000000;
	
	    while(1){
	       if(IOPIN1 & 0x01000000){
	             IO0CLR=0X00078000;
			     IOPIN0=0x00008000;
				 IOPIN1=0x00060000;
				 delay(1000);
			
				 IOPIN0=0x00010000;
				 IOPIN1=0x005B0000;
			     delay(1000);
			
				 IOPIN0=0x00020000;
				 IOPIN1=0x004F0000;
			     delay(1000);
			
				 IOPIN0=0x00040000;
				 IOPIN1=0x00660000;
				 delay(1500);
		  }
	
		 else if(IOPIN1 & 0x02000000){
		     IO0CLR=0X00078000;
		     IOPIN0=0x00008000;
			 IOPIN1=0x006D0000;
			 delay(1000);
		
			 IOPIN0=0x00010000;
			 IOPIN1=0x007D0000;
			 delay(1000);
		
			 IOPIN0=0x00020000;
			 IOPIN1=0x00070000;
			 delay(1000);
		
			 IOPIN0=0x00040000;
			 IOPIN1=0x007F0000;
			 delay(3000);
		}
		
		
		else if(IOPIN1 & 0x03000000){
		     IO0CLR=0X00078000;
		     IOPIN0=0x00008000;
			 IOPIN1=0x00670000;
		     delay(1000);
		
			 IOPIN0=0x00010000;
			 IOPIN1=0x00770000;
			 delay(1000);
		
			 IOPIN0=0x00020000;
			 IOPIN1=0x0007F000;
		     delay(1000);
		
			 IOPIN0=0x00040000;
			 IOPIN1=0x00390000;
			 delay(3000);
		}
	
		else if(IOPIN1 & 0x04000000){
		     IO0CLR=0X00078000;
		     IOPIN0=0x00008000;
			 IOPIN1=0x003F0000;
			 delay(1000);
		
			 IOPIN0=0x00010000;
			 IOPIN1=0x00790000;
			 delay(1000);
		
			 IOPIN0=0x00020000;
			 IOPIN1=0x00710000;
			 delay(1000);
		
			 IOPIN0=0x00040000;
			 IOPIN1=0x003F0000;
			 delay(3000);
		}
	
		else if(IOPIN1 & 0x05000000){
		     IO0CLR=0X00078000;
		     IOPIN0=0x00008000;
			 IOPIN1=0x00710000;
			 delay(1000);
		
			 IOPIN0=0x00010000;
			 IOPIN1=0x003F0000;
			 delay(1000);
		
			 IOPIN0=0x00020000;
			 IOPIN1=0x00390000;
			 delay(1000);
		
			 IOPIN0=0x00040000;
			 IOPIN1=0x00760000;
			 delay(3000);
		}
	
	    else{
	         IOPIN1 = 0x00000000;
	    }
	}
}

void delay(unsigned int x){
    unsigned int y,z;
    for(y=x; y>0; y--)
        for(z=0; z<x; z++);
}
