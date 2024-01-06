/*Función que provoca un retardo de tiempo, aumento y disminución de 
 * velocidad y salida de la secuencia tanto en manejo local como remoto*/
#include <sys/ioctl.h>
#include <fcntl.h>
#include <termios.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "EasyPIO.h"
#include <wiringPi.h>
#include <wiringSerial.h>

void apagar(void);
char lectura(int);

extern int contador, aux, pulsadores[], flag_recibir, fd;


void control(void){
	int i=0,j=0; // Variables para evitar errores al mantener presionado un botón
	
	char dato;
	
		for(int c=0; c<contador; c++){	//Manejo Local
			
			if(digitalRead(pulsadores[0]) && digitalRead(pulsadores[1])){
			//Salir de la secuencia
			apagar();
			aux = 1; // Bandera aux para salir de las secuencias
			}
			
		if(digitalRead(pulsadores[0]) && i<1 ){	//Disminución de velocidad
		contador=contador+25000;
		i++;
		}
		
		if(digitalRead(pulsadores[1]) && j<1 && contador > 45000){ /*Aumento de velocidad, para ello disminuyo el número a contar, 
			por lo tanto cuando llego a 50000 - 25000 = 25000, no entro más a restar */
		contador=contador-25000;
		j++;
		}
		
		if(flag_recibir)	// Leo el puerto solo si entro a las secuencias desde la funcion recibir
			dato = lectura(fd);
		
		
		if(dato == 's'){//Salir de la secuencia
		apagar();
		aux = 1;
		}
		
		if(dato == 'd' && i<1 ){//Disminución de velocidad
		contador=contador+25000;
		i++;
		}
			
		if(dato == 'a' && j<1 && contador > 45000){//Aumento de velocidad
		contador=contador-25000;
		j++;
		}
	
 }
 
 }
