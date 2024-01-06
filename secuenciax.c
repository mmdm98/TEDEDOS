#include "EasyPIO.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


extern int led[], aux;    //v
//v significa que es una linea agregada para que el programa se adecue el proyecto

void control(void);     //v

void secuenciax(void){

    int c = 0;
    char binary[8];

    system("clear");    //v
	printf("SECUENCIA X (CUENTA BINARIA)\n");   //v
	printf("Presione los dos pulsadores al mismo tiempo para salir\n"); //v
	aux = 0;
    
    while(1){
        for(int i=0; i<256 ; i++){      //cambiar el numero hasta el que tiene que contar i para cambiar la cuenta
            control();      //v
			if(aux) return; //v
            c=i;
            for(int j=0; j<8; j++){     //conversor entero a binario (numero de 8 bits)
                binary[j] = c%2?'1':'0';
                c = c/2;
            }

            //printf("%s\n", strrev(binary));       //debug - muestra en pantalla la cuenta binaria
            for(int j=0; j<8; j++){                 //enciende los correspondientes leds
                digitalWrite(led[j], binary[j]);
            }
        }
    }

}