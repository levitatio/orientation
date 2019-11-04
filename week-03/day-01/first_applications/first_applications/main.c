/*
 * first_applications.c
 *
 * Created: 2019. 11. 04. 11:08:48
 * Author : CFY
 */ 

#include <avr/io.h>
#include <util/delay.h>

void myDelay (uint32_t millisec)
{
	uint32_t max = millisec * 512;
	for (uint32_t i = 0; i < max; i++){}
}

int main(void)
{
	DDRB &= 0b01111111;
	PORTB = 0b10000000; 
	uint32_t temp = PINB & 0x80;
    /* Replace with your application code */
    while (1) 
    {
		DDRB |= 0x20;
		uint8_t counter = 0;
		//if (!(PINB & 0x80) || temp == 0 ){
		if (!(PINB & 0x80) && counter < 5)
			//myDelay(500);
			PORTB = PORTB ^ 0X20;
			_delay_ms(500);
			
			if (counter == 4){
			 PORTB = 0x20;
			}else {
				counter++;	
			}
			
		
    }
}

