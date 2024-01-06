#include "EasyPIO.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern int led[], aux;

void control(void);

void apilada(void)
{
	int j=8;
		
	system("clear");
	printf("LA APILADA\n");
	printf("Presione los dos pulsadores al mismo tiempo para salir\n");
	aux = 0;
	while(1){
			for(int i=0 ;i < j; i++){
				digitalWrite(led[i],1);
				control();
				if(aux) return;
				digitalWrite(led[i],0);
			}
			digitalWrite(led[j],1);
			control();
			if(aux) return;	
			digitalWrite(led[j],0);
			control();
			if(aux) return;	
			digitalWrite(led[j],1);
			j--;
			
			if(j == 0) j=8;					
			}
}
