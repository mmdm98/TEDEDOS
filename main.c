#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "EasyPIO.h"
#include <wiringPi.h>

void autofantastico(void);
void lacarrera(void);
void contrasenia(void); 
void set_gpio(void);
int recibir(void);
char lectura(int);
void elchoque(void);
void apilada(void);
void secuencia5(void);
void secuencia6(void);
void secuencia7(void);
void secuencia8(void);
void leerAdc(void);

//Variable globales
int led[8]={23,24,25,12,16,20,21,26}, pulsadores[2]={17,27};
int llaves[4]={5,6,13,19}, contador=25000, aux, fd, flag_recibir=0;


int main(void)
{
	int s;
	
	contrasenia(); //Control de acceso
	
	pioInit();	//Inicializa puertos
	
	set_gpio();	//Configura entradas y salidas
	
	//leerAdc();	//Setea la velocidad inicial de las secuencias
	
	while(1){
		
		system("clear");//Limpieza de pantalla
		printf("Seleccione la secuencia de LUCES\n -1)Auto Fantastico\n -2)La Carrera\n -3)El Choque\n -4)La Apilada\n -5)Secuencia 5\n -6)Secuencia 6\n -7)Secuencia 7\n -8)Secuencia 8\n -9)Control Remoto\n -10)Seteo de Velocidad \n -11)Salir \n");
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
			secuencia5();
			break;	
			}
			case 6:{
			secuencia6();
			break;	
			}
			case 7:{
			secuencia7();
			break;	
			}
			case 8:{
			secuencia8();
			break;	
			}
			case 9:{
			recibir();
			flag_recibir=0;	// Al salir del modo remoto, bajo la bandera para ignorar el read en control.c
			break;
			}
			case 10:{
			leerAdc();
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
