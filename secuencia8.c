#include "EasyPIO.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern int led[], aux;

void control(void);

void secuencia8(void)
{
	system("clear");
	printf("SECUENCIA 8\n");
	printf("Presione los dos pulsadores al mismo tiempo para salir\n");
	aux = 0;
	while(1){
			for(int i=0 ;i < 8; i++){
				digitalWrite(led[i],1);
				control();
				if(aux) return;
				digitalWrite(led[i],0);
				i++;
				i++;
				digitalWrite(led[i],1);
				control();
				if(aux) return;
				digitalWrite(led[i],0);
				i--;
				digitalWrite(led[i],1);
				control();
				if(aux) return;
				digitalWrite(led[i],0);
				}							
			}
}

