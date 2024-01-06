#include "EasyPIO.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern int led[], aux, contador;

void apagar(void);
void control(void);

void autofantastico(void)
{
	system("clear");
	printf("AUTO FANTÁSTICO \n");
	printf("Presione los dos pulsadores al mismo tiempo para salir\n");
	aux = 0;
	
	while(1){
				
		for(int i=0; i<8; i++){ //Prendido y apagado en forma ascendente
			digitalWrite(led[i],1);
			control();
			if(aux) return;
			digitalWrite(led[i],0);
		}

		for(int i=7; i>-1; i--){//Prendido y apagado en forma descendente
			digitalWrite(led[i],1);
			control();
			if(aux) return;
			digitalWrite(led[i],0);
		}
	}
}

