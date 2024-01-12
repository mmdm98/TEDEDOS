///////////////////////////////////////////////////////////////////////////////////////
/////                                                                             /////
/////                                  CONTROL                                    /////
/////                                                                             /////
///////////////////////////////////////////////////////////////////////////////////////
// función que provoca un retardo de tiempo, aumento y disminución de
// velocidad y salida de la secuencia tanto en manejo local como remoto
// en local funciona apretando ambos pulsadores, en remoto "s", "d" y "a"

// User libs
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

// User funx
void apagar(void);
char lectura(int);

// User extrn vals
extern int contador, aux, pulsadores[], flag_recibir, fd;

void control(void)
{
	//variables para evitar errores al mantener presionado un botón
	int i = 0, j = 0; 
	//variable para guardar la input
	char dato;

	for (int c = 0; c < contador; c++)
	{ 
		//manejo con pulsadores
		if (digitalRead(pulsadores[0]) && digitalRead(pulsadores[1]))
		{
			//si se presionan los dos, salir de la secuencia
			apagar();
			//aux flag para salir de las secuencias
			aux = 1; 
		}

		if (digitalRead(pulsadores[0]) && i < 1)
		{
			//disminución de velocidad
			contador = contador + 25000;
			i++;
		}

		if (digitalRead(pulsadores[1]) && j < 1 && contador > 45000)
		{ 
			//aumento de velocidad, para ello disminuyo el número a contar,
			//por lo tanto cuando llego a 50000 - 25000 = 25000, no entro más a restar
			contador = contador - 25000;
			j++;
		}
		//leo el puerto solo si entro a las secuencias desde la funcion recibir(modo remoto)
		if (flag_recibir) 
			dato = lectura(fd);

		if (dato == 's')
		{ 
			//salir de la secuencia
			apagar();
			aux = 1;
		}

		if (dato == 'd' && i < 1)
		{
			//disminución de velocidad
			contador = contador + 25000;
			i++;
		}

		if (dato == 'a' && j < 1 && contador > 45000)
		{
			//aumento de velocidad
			contador = contador - 25000;
			j++;
		}
	}
}
