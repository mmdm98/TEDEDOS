#include "EasyPIO.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern int led[], aux;

void control(void);

void elchoque(void)
{
	int matriz[8][8]={{1,0,0,0,0,0,0,1},
				       {0,1,0,0,0,0,1,0},
					   {0,0,1,0,0,1,0,0},
					   {0,0,0,1,1,0,0,0},
			           {0,0,0,1,1,0,0,0},
					   {0,0,1,0,0,1,0,0},
					   {0,1,0,0,0,0,1,0},
					   {1,0,0,0,0,0,0,1}};
					
	
	system("clear");
	printf("EL CHOQUE\n");
	printf("Presione los dos pulsadores al mismo tiempo para salir\n");
	aux = 0;
	while(1){
				
			for(int i=0;i<8;i++){
				
				control();
				if(aux) return;
				
				else{
					for(int t=0; t<8; t++){
					digitalWrite(led[t], matriz[i][t]);		// desplazamiento en la matriz de leds
								}	
					}				
				}		
			}
}
