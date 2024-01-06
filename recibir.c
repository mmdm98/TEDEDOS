#include <sys/ioctl.h>
#include <fcntl.h>
#include <termios.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>


void autofantastico(void);
void lacarrera(void);
void elchoque(void);
void apilada(void);
void secuencia5(void);
void secuencia6(void);
void secuencia7(void);
void secuencia8(void);
char lectura(int);
void mensaje(void);


extern int fd, flag_recibir;

int recibir(void)
{
	struct termios oldtty, newtty;
	int  veloc; 
	long baud;
	char  puerto[15] = "/dev/ttyACM0";
	//char  puerto[15] = "COM5";
	char buffer;
		
	flag_recibir = 1;	// Bandera para activar la función lectura en control.c
	
		system("clear");
		printf("\n Ingresar el Puerto Serial a utilizar: ");

		//printf("\nPuerto '/dev/ttySx': ");
		//scanf("%c", &puerto[9]);

		if ((fd = open(puerto,O_RDWR | O_NOCTTY )) < 0)
				{
				printf("\nNo se puede abrir el puerto: %c\n",puerto[15]);
				exit(1);
				}
		

		printf("\n Velocidad: \nIngrese 1200, 2400, 9600, 19200 o 38400: ");
			scanf("%d", &veloc);
			switch (veloc) {
			case 1200:
				baud = B1200;
				break;
			case 2400:
				baud = B2400;
				break;
			case 9600:
				baud = B9600;
				break;
			case 19200:
				baud = B19200;
				break;
			case 38400:
				baud = B38400;
				break;
				default:
						printf("\nVelocidad de transmicion incorrecta.\n ");
						printf("\nIngrese 1200, 2400, 9600, 19200 o 38400.\n");
						break;
			}

	if(tcgetattr(fd, &oldtty) != 0)  //Carga de valores actuales de la terminal
	{
	printf(" ERROR : tcgetattr \n");
	return -1;
	}

		newtty = oldtty;
				/* 	* baud, velocidad de transmisión 
					* CS8, 8 bits de datos 
					* CREAD, habilitar recepcion 
					* CLOACAL ignora el estado de linea del modem  
				*/
		newtty.c_cflag = baud | CS8 | CREAD | CLOCAL;
		newtty.c_cflag &= ~( PARENB | PARODD );       // no parity (N)
		newtty.c_cflag &= ~CSTOPB;                    // 1 stop bit (1)
		newtty.c_cflag &= ~CRTSCTS;              	  // no flow control
		
		newtty.c_iflag &= ~IGNBRK ;                  // disable break processing
		newtty.c_iflag &= ~( IXON | IXOFF | IXANY ); // shut off xon / xoff ctrl
		
		newtty.c_lflag = 0;		 /* establecer bandera de entrada en modo no canonico */
		newtty.c_oflag = 0;		/* establecer bandera de salida en modo no canonico */
		newtty.c_cc[VMIN] = 0; //1
		newtty.c_cc[VTIME] = 0;
		/*
		* TCSANOW : Make the change immediately.
		* TCSADRAIN : Make the change after all queued output has been written.
		* TCSAFLUSH : This is like TCSADRAIN , but also discards any queued input.
		*/
		if(tcsetattr(fd, TCSANOW, &newtty) != 0){
			printf(" ERROR : tcsetattr \n" );
			return -1;
		}
		
		fcntl(fd, F_SETFL, 0); // funciona de forma sincrona
		
		//fcntl(fd, F_SETFL, FNDELAY); 
		/* lectura asincrona, configura sin demora, es decir, se realizarán lecturas sin bloqueo.
		Cuando leemos, obtendremos lo que está en el búfer de entrada o nada. Establece la función de lectura de puerto 
		para devolver 0 si no hay datos disponibles para leer */

		mensaje();	
				
		while(1){

		buffer = lectura(fd);	
			
		switch(buffer){
			case '0':
			break;
			case '1':{
			autofantastico();
			mensaje();	
			break;
			}
			case '2':{
			lacarrera();
			mensaje();	
			break;
			}
			case '3':{
			elchoque();
			mensaje();	
			break;
			}
			case '4':{
			apilada();
			mensaje();	
			break;
		    }
		    case '5':{
			secuencia5();
			mensaje();	
			break;	
			}
			case '6':{
			secuencia6();
			mensaje();	
			break;	
			}
			case '7':{
			secuencia7();
			mensaje();	
			break;	
			}
			case '8':{
			secuencia8();
			mensaje();	
			break;	
			}
			case '9':{
			printf("\n Cerrando puerto...\n");
			usleep(1000 * 1000);
			tcsetattr(fd, TCSANOW, &oldtty); 
			close(fd);
			return 0;
			}
			default:
			system("clear");
			printf("\n----OPCIÓN NO VALIDA----\n\n");
			usleep(1000 * 1000);
			break;
					
	}
	}
		close(fd);
		return 0;
}


void mensaje(){
		system("clear");//Limpieza de pantalla
		printf("\n---- CONTROL REMOTO ----\n\n");
		printf("Seleccione la secuencia de LUCES\n -1)Auto Fantastico\n -2)La Carrera\n -3)El Choque\n -4)La Apilada\n -5)Secuencia 5\n -6)Secuencia 6\n -7)Secuencia 7\n -8)Secuencia 8\n -9)Volver a Control Local \n");
		printf("\n\nRecibiendo datos desde el otro dispositivo: \n");	
	}
