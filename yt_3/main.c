//learning...

#include <stdint.h>

/* Type 1

struct EmbeddedSystem{

	uint8_t Hardware;
	uint8_t Software;
	
}E1,E2; //directly declaring instances here instead of
// struct EmbeddedSystem E1,E2;

*/

/*Type 2

struct
	{
	uint8_t Hardware;
	uint8_t Software;
}E1,E2,E5,E6;

*/

/*typedef - to create Alias(new name) for 
						existing struct (data type).

application 1 (typedef) -

typedef uint8_t ElectronicComponent;

//uint8_t Resistor;
ElectronicComponent Resistor;//we are using 
		//ElectronicComponent alias of uint8_t 
//uint8_t Capacitor;
ElectronicComponent Capacitor;
//uint8_t Inductor;
ElectronicComponent Inductor;
*/
/* application 2 (typedef) -
typedef struct EmbeddedSystem ES;

ES E1,E2,E5; //creating instances
*/

// ***application 3 (typedef) - recommended
	typedef struct
	{
	uint8_t Hardware;
	uint8_t Software;
}EmbeddedSystem;
	
//EmbeddedSystem E1,E2,E5; // creating instances
EmbeddedSystem E[3];//we can create instances using array

int main(){

//	E1.Hardware =1;//using . operator 
//	E1.Software =1;//we can access struct elements 
								//for any particular instance 
	E[0].Hardware=1;
	E[0].Software=1;
	
//	E2.Hardware =1;
//	E2.Software =1;
	
	E[1].Hardware =1;
	E[1].Software =1;
}