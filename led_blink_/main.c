//Learning...

/*

PF1 = red
PF2 = blue
PF3 = green

*/

/*														Base				Offset
clock enable to PORTF				0x400F.E000	+	0x608		=> 0x400F.E608 =>RCGCCGPIO
digitalize the PORTFpins		0x4002.5000 + 0x51C		=> 0x4002.551C =>GPIOFDEN
direction for PORTF					0x4002.5000 + 0x400		=> 0x4002.5400 =>GPIOFDIR
data to PORTF								0x4002.5000 + 0x000		=> 0x4002.5000 =>GPIOFDATA
*/

/*

GPIOPortF(APB)base:0x4002.5000

Register1:GPIOData(GPIODATA),offset0x000
Offset0x000
TypeRW,reset0x0000.0000

Register2:GPIODirection(GPIODIR),offset0x400
Offset0x400
TypeRW,reset0x0000.0000
	0:Input
	1:Output

Register18:GPIODigitalEnable(GPIODEN),offset0x51C
	0:Enable
	1:Disable

Register60:General-PurposeInput/OutputRunModeClockGatingControl
(RCGCGPIO),offset0x608
Base0x400F.E000		Offset0x608
TypeRW,reset0x0000.0000
	Bit 31:6 - reserved
	Bit 5 - GPIO PortF Run Mode Clock Gating Control
					0:Disable
					1:Enable
	Bit 4 - GPIO PortE Run Mode Clock Gating Control
					0:Disable
					1:Enable 
	Bit 3 - GPIO PortD Run Mode Clock Gating Control
					0:Disable
					1:Enable 
	Bit 2 - GPIO PortC Run Mode Clock Gating Control
					0:Disable
					1:Enable 
	Bit 1 - GPIO PortB Run Mode Clock Gating Control
					0:Disable
					1:Enable  
	Bit 0 - GPIO PortA Run Mode Clock Gating Control
					0:Disable
					1:Enable  
*/


int main()
{

unsigned int *RCGCGPIO;
RCGCGPIO =(unsigned int *)0x400FE608;
	*RCGCGPIO=0X20U; // Enable the clock for PORTF
	
	unsigned int *GPIOFDEN;
GPIOFDEN =(unsigned int *)0x4002551CU;
		*GPIOFDEN=0X0EU; // PF1 PF2 PF3 are digitalised
	
	unsigned int *GPIOFDIR;
GPIOFDIR =(unsigned int *)0x40025400;
	*GPIOFDIR=0x0EU; // PF1 PF2 PF3 as output
	
	unsigned int *GPIOFDATA;
GPIOFDATA =(unsigned int *)0x400253FCU;//after mask 0011 1111 1100
	*GPIOFDATA=0X02U; // RED led on
	*GPIOFDATA=0X04U; // BLUE led on
	*GPIOFDATA=0X08U; // GREEN led on
	
	while(1)
	{
		
	}
}
