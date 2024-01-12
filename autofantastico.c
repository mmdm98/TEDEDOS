///////////////////////////////////////////////////////////////////////////////////////
/////                                                                             /////
/////                            AUTOFANTASTICO                                   /////
/////                                                                             /////
///////////////////////////////////////////////////////////////////////////////////////
// User libs
#include "EasyPIO.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// User extern vars
extern int led[], aux, contador;

// User func
void apagar(void);
void control(void);

// User code
void autofantastico(void)
{
	aux = 0;
	system("clear");
	printf("AUTO FANTÁSTICO \n");
	printf("Presione los dos pulsadores al mismo tiempo para salir\n");

	while (1)
	{
		for (int i = 0; i < 8; i++)
		{
			digitalWrite(led[i], 1);
			control();
			if (aux)
				return;
			digitalWrite(led[i], 0);
		}

		for (int i = 7; i > -1; i--)
		{
			digitalWrite(led[i], 1);
			control();
			if (aux)
				return;
			digitalWrite(led[i], 0);
		}
	}
}
