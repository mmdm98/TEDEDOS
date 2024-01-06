//Configuración de los pines GPIO como entradas o salidas.
#include "EasyPIO.h"

#define INPUT 0
#define OUTPUT 1

extern int led[],pulsadores[],llaves[];

//Variables globales definidas en main.c

void set_gpio(void){

	for(int i=0;i<8;i++)
		pinMode(led[i],OUTPUT);
	
	for(int i=0;i<2;i++)
		pinMode(pulsadores[i],INPUT);
 
	for(int i=0;i<4;i++)
		pinMode(llaves[i],INPUT);
 
}
