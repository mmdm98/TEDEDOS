#include <stdio.h>
#include <string.h> //gets, strcmp
#include <stdlib.h> // system
#include <termios.h>
#include <unistd.h>

#define CLAVE "12345"
#define USUARIO "ramiro"
#define LONGITUD 10


int getch(void);


int key(void)
{
	char usuario[LONGITUD + 1];
	char clave[LONGITUD + 1];
	char caracter;
	int intentos = 0;
	int ingreso = 0;
	int i=0;

	do{
	i = 0;
	system("clear");//Limpieza de pantalla
	printf("\n Inicio de Sesión: \n");
	printf("\n Ingrese Usuario: ");
	scanf("%s", usuario);


    printf("\n Ingrese su clave de 5 digitos, y luego presione espacio: ");

	while(1){	
		caracter = getch();		//Leo de a un caracter

		if(caracter == 32 ){	//comparo con espacio
		clave[i] = '\0'; 		//final de cadena igual a cero
		break;
		}
		else if(caracter == 127 && i>0 ){	/* 127 = DEL and cursor mayor a cero (para no borrar palabras de la terminal)*/
		i--;
		printf("\b \b");	/*\b retrocede un lugar del cursor, inserta un espacio en blanco,
								y retrocede otro lugar para seguir escribiendo */
		}

		else if(caracter > 47 && caracter < 123 ){	/*Control de carácteres ingresados*/
		clave[i] = caracter;
		printf("*");
		i++;
		}
	}

	if(strcmp(usuario, USUARIO) == 0 && strcmp(clave, CLAVE) == 0){ 
	ingreso = 1;	
	}	
	
	else{
		printf("\n Usuario y/o clave son incorrectos \n");
		intentos++;
		getchar();
	}

	}while (intentos < 3 && ingreso == 0);

	
	if (ingreso == 1){
		printf("\n\n Bienvenido al Sistema \n");
		sleep(2);
	}
	else{
		printf("\n\n Ha superado el numero máximo de intentos permitidos \n");
	}
return 0;
}

int getch(){
	struct termios oldt, newt;
	char ch;
	tcgetattr(STDIN_FILENO, &oldt);	// STDIN_FILENO es la entrada estandar, igual a 0.
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt); 
	
	ch = getchar();
	
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	return ch;
}
