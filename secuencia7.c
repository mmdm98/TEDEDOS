#include "EasyPIO.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern int led[], aux, llaves[];

void control(void);

void secuencia7(void)
{
	
	system("clear");
	printf("SECUENCIA 7\n");
	printf("Presione los dos pulsadores al mismo tiempo para salir\n");
	aux = 0;
	while(1){
			
			if(digitalRead(llaves[0])){
				digitalWrite(led[0],1);
				digitalWrite(led[1],1);
			}
			else{
				digitalWrite(led[0],0);
				digitalWrite(led[1],0);
				}
			
			if(digitalRead(llaves[1])){
				digitalWrite(led[2],1);
				digitalWrite(led[3],1);
			}
			else{
				digitalWrite(led[2],0);
				digitalWrite(led[3],0);
				}
			
			if(digitalRead(llaves[2])){
				digitalWrite(led[4],1);
				digitalWrite(led[5],1);
			}
			else{
				digitalWrite(led[4],0);
				digitalWrite(led[5],0);
				}
			
			if(digitalRead(llaves[3])){
				digitalWrite(led[6],1);
				digitalWrite(led[7],1);
			}
			else{
				digitalWrite(led[6],0);
				digitalWrite(led[7],0);
				}
			control();
			if(aux) return;			
		}					
}

