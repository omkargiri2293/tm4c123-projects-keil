//learning...

/*
Bitwise operation

setting a bit:
reg = reg | (1 << bit number)
eg. GPIOF->DATA = DATA | (1<<3)

clearing a bit:
reg = reg & ~(1 << bit number)

*/
#include "TM4C123GH6PM.h"
#include "delay.h"

int main()
{
SYSCTL->RCGCGPIO=0X20U;
	
GPIOF->DIR=0X0EU;
	
GPIOF->DEN=0x0EU;
	

	
	while(1)
	{
		// GPIOF->DATA=0x04U;
		GPIOF->DATA |=(1<<3);
		delay(10000000);
		GPIOF->DATA &= (~(1<<3));
		delay(10000000);
		
		
	}
}

