///////////////////////////////////////////////////////////////////////////////////////
/////                                                                             /////
/////                                LACARRERA                                    /////
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
void apagar(void);
void control(void);

// User code
void lacarrera(void)
{
	int matriz[18][8]={{1,0,0,0,0,0,0,0},
				     {1,0,0,0,0,0,0,0},
					 {0,1,0,0,0,0,0,0},
					 {0,1,0,0,0,0,0,0},
					 {0,0,1,0,0,0,0,0},
					 {0,0,1,0,0,0,0,0},
					 {0,0,0,1,0,0,0,0},
					 {0,0,0,1,0,0,0,0},
					 {1,0,0,0,1,0,0,0},
				     {0,1,0,0,1,0,0,0},
					 {0,0,1,0,0,1,0,0},
					 {0,0,0,1,0,1,0,0},
					 {0,0,0,0,1,0,1,0},
					 {0,0,0,0,0,1,1,0},
					 {0,0,0,0,0,0,1,1},
					 {0,0,0,0,0,0,0,1},
					 {0,0,0,0,0,0,0,1},
					 {0,0,0,0,0,0,0,0}};
	
	system("clear");
	printf("LA CARRERA\n");
	printf("Presione los dos pulsadores al mismo tiempo para salir\n");
	
	aux = 0;
	while(1){
				
			for(int i=0;i<18;i++){
				
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



