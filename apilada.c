///////////////////////////////////////////////////////////////////////////////////////
/////                                                                             /////
/////                                  APILADA                                    /////
/////                                                                             /////
///////////////////////////////////////////////////////////////////////////////////////
// User libs
#include "EasyPIO.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// User extern vars
extern int led[], aux;

// Speed control
void control(void);

// User code
void apilada(void)
{
	// variable auxiliar
	int j = 8;
	aux = 0;

	// startup
	system("clear");
	printf("LA APILADA\n");
	printf("Presione los dos pulsadores al mismo tiempo para salir\n");

	// secuencia para la apilada
	while (1)
	{
		for (int i = 0; i < j; i++)
		{
			digitalWrite(led[i], 1);
			// velocidad en el for para el cambio en cualquier momento
			control();
			// aux flag de salida
			if (aux)
				return;
			digitalWrite(led[i], 0);
		}
		digitalWrite(led[j], 1);
		control();
		if (aux)
			return;
		digitalWrite(led[j], 0);
		control();
		if (aux)
			return;
		digitalWrite(led[j], 1);
		j--;

		if (j == 0)
			j = 8;
	}
}
