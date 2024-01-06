#include "EasyPIO.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

extern int led[], aux;    //v
//v significa que es una linea agregada para que el programa se adecue el proyecto

void control(void);     //v

void secuenciaXI(void){
    int i;

    system("clear");    //v
	printf("SECUENCIA X (CUENTA BINARIA)\n");   //v
	printf("Presione los dos pulsadores al mismo tiempo para salir\n"); //v
	aux = 0;

    while(1){
        for(i=0; i<4; i++){             //prende de a uno hacia el centro
            digitalWrite(led[7-i], 1);
            digitalWrite(led[0+i], 1);
            control();
            if(aux) return; //v
        }
        for(i=0; i<4; i++){             //apaga de a uno hacia el centro
            digitalWrite(led[7-i], 0);
            digitalWrite(led[0+i], 0);
            control();
            if(aux) return; //v  
        }

        for(int j=0; j<5; j++){     //prende y apaga todos a la vez
            for(i=0; i<8; i++){
                digitalWrite(led[i], 1);
            }
            control();
            if(aux) return; //v
            for(i=0; i<8; i++){
                digitalWrite(led[i], 0);
            }
            control();
            if(aux) return; //v
        }
    }

}