#include <lpc214x.h>
#include <stdio.h>

#define RS (1 << 16)
#define RW (1 << 17)
#define EN (1 << 18)

void lcd_cmd(unsigned char);
void lcd_data(unsigned char);
void lcd_initialize(void);
void lcd_display(void);
void LCD4_Convert(unsigned char);
void delay(unsigned int);

const unsigned char cmd[4] = {0x28, 0x0C, 0x06, 0x01};
unsigned char msg[]  = {" XYZ"};
unsigned char msg1[] = {" ABC "};

int main(void)
{
    PINSEL1 = 0;              
    IODIR0  = 0xFF << 16;    
    lcd_initialize();
    lcd_display();
    while(1);
}

void delay(unsigned int n)
{
    unsigned int i, j;
    for(i = 0; i < n; i++)
        for(j = 0; j < 12000; j++);
}

void lcd_cmd(unsigned char data)
{
    IOCLR0 |= RS;  
    IOCLR0 |= RW;   
    LCD4_Convert(data);
    if(data == 0x01 || data == 0x02) 
        delay(200);
    else
        delay(20);
}

void lcd_initialize(void)
{
    int i;
    for(i = 0; i < 4; i++)
    {
        lcd_cmd(cmd[i]);
    }
}

void lcd_data(unsigned char data)
{
    IOSET0 |= RS;  
    IOCLR0 |= RW;  
    LCD4_Convert(data);
    delay(20);
}

void LCD4_Convert(unsigned char c)
{
    if (c & 0x80) IOSET0 |= (1 << 22); else IOCLR0 |= (1 << 22);
    if (c & 0x40) IOSET0 |= (1 << 21); else IOCLR0 |= (1 << 21);
    if (c & 0x20) IOSET0 |= (1 << 20); else IOCLR0 |= (1 << 20);
    if (c & 0x10) IOSET0 |= (1 << 19); else IOCLR0 |= (1 << 19);

    IOSET0 |= EN;
    delay(8);
    IOCLR0 |= EN;
    if (c & 0x08) IOSET0 |= (1 << 22); else IOCLR0 |= (1 << 22);
    if (c & 0x04) IOSET0 |= (1 << 21); else IOCLR0 |= (1 << 21);
    if (c & 0x02) IOSET0 |= (1 << 20); else IOCLR0 |= (1 << 20);
    if (c & 0x01) IOSET0 |= (1 << 19); else IOCLR0 |= (1 << 19);

    IOSET0 |= EN;
    delay(8);
    IOCLR0 |= EN;
}

void lcd_display(void)
{
    char i;

    lcd_cmd(0x80);
    i = 0;
    while(msg[i] != '\0')
    {
        lcd_data(msg[i]);
        i++;
    }
    lcd_cmd(0xC0);
    i = 0;
    while(msg1[i] != '\0')
    {
        lcd_data(msg1[i]);
        i++;
    }
}
