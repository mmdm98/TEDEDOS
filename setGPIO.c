///////////////////////////////////////////////////////////////////////////////////////
/////                                                                             /////
/////                                  SETGPIO                                    /////
/////                                                                             /////
///////////////////////////////////////////////////////////////////////////////////////
//Configuración de los pines GPIO como entradas o salidas.
// User libs
#include "EasyPIO.h"

//User defines
#define INPUT 0
#define OUTPUT 1

// User extern vars
extern int led[],pulsadores[];

// User code
void setGPIO(void){

	for(int i=0;i<8;i++)
		pinMode(led[i],OUTPUT);
	
	for(int i=0;i<2;i++)
		pinMode(pulsadores[i],INPUT);
 
}
