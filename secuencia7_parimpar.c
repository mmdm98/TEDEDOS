///////////////////////////////////////////////////////////////////////////////////////
/////                                                                             /////
/////                                  PARIMPAR                                   /////
/////                                                                             /////
///////////////////////////////////////////////////////////////////////////////////////
// User libs
#include "EasyPIO.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// User extern vars
extern int led[], aux;

// User func
void control(void);
void apagar(void);

// User code
void secuencia7_parimpar(void)
{
	
	system("clear");
	printf("SECUENCIA 7: Parimpar\n");
	printf("Presione los dos pulsadores al mismo tiempo para salir\n");
	aux = 0;
	int i=0;
	while(1){
		//pares
		for(i=0; i<4;i++){
			digitalWrite(led[i*2],1);
		}
		control();
		if(aux) return;
		apagar();
		//impares
		for(i=0; i<5;i++){
			digitalWrite(led[(i*2)-1],1);
		}
		control();
		if(aux) return;
		apagar();
    }
}


