///////////////////////////////////////////////////////////////////////////////////////
/////                                                                             /////
/////                                     KEY                                     /////
/////                                                                             /////
///////////////////////////////////////////////////////////////////////////////////////
// User libs
#include <stdio.h>
#include <string.h> //gets, strcmp
#include <stdlib.h> // system
#include <termios.h>
#include <unistd.h>

// User defines
#define CLAVE "12345"
#define USUARIO "daniela"
#define LONGITUD 10
// Colores ANSI para la terminal
#define COLOR_ROJO "\033[1;31m"
#define COLOR_VERDE "\033[1;32m"
#define COLOR_RESET "\033[0m"

// User func
int getch(void);
//extern int strcmp_arm(const char *s1, const char *s2);

// User code
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
	printf(COLOR_ROJO "\n Inicio de Sesión: \n" COLOR_RESET);
	printf("\n Ingrese Usuario: " COLOR_VERDE);
	scanf("%s", usuario);


    printf(COLOR_RESET "\n Ingrese su clave de 5 digitos, y luego presione [ESPACIO]: ");

	while(1){	
		caracter = getch();		//Leo de a un caracter

		if(caracter == ' ' ){	//comparo con el espacio
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
		printf(COLOR_VERDE "*" COLOR_RESET);
		i++;
		}
	}

	if(strcmp_arm(usuario, USUARIO) == 0 && strcmp_arm(clave, CLAVE) == 0){ 
	ingreso = 1;	
	}	
	
	else{
		printf(COLOR_ROJO "\n Usuario y/o clave son incorrectos, presione [ENTER] para volver a intentar\n" COLOR_RESET);
		intentos++;
		getchar();
	}

	}while (intentos < 3 && ingreso == 0);

	
	if (ingreso == 1){
		printf(COLOR_VERDE "\n\n Bienvenido al Sistema \n" COLOR_RESET);
		sleep(2);
	}
	else{
		printf(COLOR_ROJO "\n\n Ha superado el numero máximo de intentos permitidos \n" COLOR_RESET);
		return 1;
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
