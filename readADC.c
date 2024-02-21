///////////////////////////////////////////////////////////////////////////////////////
/////                                                                             /////
/////                                 READADC                                     /////
/////                                                                             /////
///////////////////////////////////////////////////////////////////////////////////////
// User libs
#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// User extern vars
extern int contador, pulsadores[], fd;

// User func
const char PCF8591 = 0x48;
//int fd;

// User code
void readADC(void)
{
	int val;
	
	if(wiringPiSetup() == -1)
		exit(1);
	
	fd = wiringPiI2CSetup(PCF8591);
	
	while( !digitalRead(pulsadores[0]) || !digitalRead(pulsadores[1])  ){
		
	system("clear");
	// Lectura del canal correspondiente al potenciómetro
	val = wiringPiI2CReadReg8(fd, PCF8591 + 0);	
	printf("\n Val: %d \n", val);
	if(val >= 5) // Para que el valor mínimo del contador sea 25000.
	contador = val * 5000;
	
	printf("\n Posicione el potenciómetro para seleccionar la velocidad de las secuencias \n");
	printf("\n Presione los dos botones pulsadores para guardar la selección y salir: %d \n", contador);
	delay(200);
	}
}

