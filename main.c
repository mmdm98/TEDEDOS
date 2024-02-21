///////////////////////////////////////////////////////////////////////////////////////
/////                                                                             /////
/////                                    MAIN                                     /////
/////                                                                             /////
///////////////////////////////////////////////////////////////////////////////////////
// User libs
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "EasyPIO.h"
#include <wiringPi.h>

// User func
void autofantastico(void);
void lacarrera(void);
void elchoque(void);
void apilada(void);

void secuencia5_parpadeo(void);
void secuencia6_puente(void);
void secuencia7_parimpar(void);
void secuencia8_prendeapaga(void);


int key(void); 
void setGPIO(void);
int recibir(void);
char lectura(int);
void readADC(void);

//User globals
int led[8]={23,24,25,12,16,20,21,26}, pulsadores[2]={17,27};
int contador=25000, aux, fd, flag_recibir=0;

// User code
int main(void)
{
	int s;
	int doorOpen;
	
	doorOpen = key(); //Control de acceso
	if(doorOpen == 1){
		return 0;
	}
	pioInit();	//Inicializa puertos
	
	setGPIO();	//Configura entradas y salidas
	
	//readADC();	//Setea la velocidad inicial de las secuencias
	
	while(1){
		
		system("clear");//Limpieza de pantalla
		//printf("Seleccione la secuencia de LUCES:\n -1)Auto Fantastico\n -2)La Carrera\n -3)El Choque\n -4)La Apilada\n -5)Parpadeo\n -6)Puente\n -7)Parimpar\n -8)Prendeapaga\n -9)Control Remoto\n -10)Seteo de Velocidad \n -11)Salir \n");
		printf("Seleccione la secuencia de LUCES:\n"
       " -\033[1;32m1)\033[0m Auto Fantastico\n"
       " -\033[1;32m2)\033[0m La Carrera\n"
       " -\033[1;32m3)\033[0m El Choque\n"
       " -\033[1;32m4)\033[0m La Apilada\n"
       " -\033[1;32m5)\033[0m Parpadeo\n"
       " -\033[1;32m6)\033[0m Puente\n"
       " -\033[1;32m7)\033[0m Parimpar\n"
       " -\033[1;32m8)\033[0m Prendeapaga\n"
       " -\033[1;32m9)\033[0m Control Remoto\n"
       " -\033[1;32m10)\033[0m Seteo de Velocidad\n"
       " -\033[1;32m11)\033[0m Salir\n");
		printf("\n\n Opción: ");
		scanf("%d", &s);
		getchar(); //Espera el ENTER
	
		switch(s){
			case 1:{
			autofantastico();
			break;
			}
			case 2:{
			lacarrera();
			break;
			}
			case 3:{
			elchoque();
			break;
			}
			case 4:{
			apilada();
			break;
		    }
		    case 5:{
	        secuencia5_parpadeo();
			break;	
			}
			case 6:{
			secuencia6_puente();
			break;	
			}
			case 7:{
			secuencia7_parimpar();
			break;	
			}
			case 8:{
			secuencia8_prendeapaga();
			break;	
			}
			case 9:{
			recibir();
			flag_recibir=0;	// Al salir del modo remoto, bajo la bandera para ignorar el read en control.c
			break;
			}
			case 10:{
			readADC();
			break;	
			}
			case 11:{
			return 0;
			}
			default:
			system("clear");
			printf("\n---- OPCIÓN NO VALIDA----\n\n");
			usleep(1000 * 1000);
			break;
		}
}
return 0;
}
