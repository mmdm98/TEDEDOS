#include "EasyPIO.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern int led[], aux;

void control(void);

void secuencia6(void)
{
	int matriz[6][8]={{1,1,1,0,0,0,0,0},
		              {0,1,1,1,0,0,0,0},
		              {0,0,1,1,1,0,0,0},
		              {0,0,0,1,1,1,0,0},
		              {0,0,0,0,1,1,1,0},
					  {0,0,0,0,0,1,1,1}};
		            
	
	system("clear");
	printf("SECUENCIA 6\n");
	printf("Presione los dos pulsadores al mismo tiempo para salir\n");
	aux = 0;
	while(1){
				
			for(int i=0;i<6;i++){
				
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
