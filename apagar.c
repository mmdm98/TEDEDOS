//Función que coloca en cero las salidas GPIO

#include "EasyPIO.h"

extern int led[];

void apagar(void){
	
	for(int i=0; i<8; i++)
		digitalWrite(led[i],0);
 
 }

