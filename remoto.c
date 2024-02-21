///////////////////////////////////////////////////////////////////////////////////////
/////                                                                             /////
/////                                 REMOTO                                      /////
/////                                                                             /////
///////////////////////////////////////////////////////////////////////////////////////
//sudo chmod 777 /dev/ttyACM0
// gcc -o remoto remoto.c

// User libs
#include <stdio.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <termios.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

// User vars
struct termios tio, oldtio;

// User code
int main(void)
{
  int fd, vel, result; 
  long baud = B9600;
  char puerto[15] = "/dev/ttyACM0";
  char dato;
	
	system("clear");
	printf("\n\n---- PROYECTO FINAL TD2 ----");
	
	printf("\n\n Iniciando Control Remoto del Dispositivo \n");
	
	//printf("\n Ingrese el Puerto Serial a utilizar: \n");
 	
 	//printf("\n Puerto '/dev/ttyUSB ': ");
 	//scanf(" %c", &puerto[0]);

 		
 	/* open the serial port device file
	 * O_NDELAY - indica al puerto que operará e ignorará la línea DCD
	 * O_NOCTTY - este proceso no es para convertirse en el proceso de control para el puerto.
	 * El controlador no enviará estas señales de proceso debido a abortos del teclado, etc.  */
	  if ((fd = open(puerto, O_RDWR | O_NDELAY | O_NOCTTY)) < 0)
	  {
		    printf("Couldn't open %c\n", puerto[15]);
		    exit(1);
	  }
       
          printf("\nVelocidad de transmición de datos: \nIngrese 1200, 2400, 9600, 19200, o 38400: ");
	  scanf("%d", &vel);
       
	  switch (vel) {
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
          printf("\nBaud rate is not supported, ");
          printf("\nUse 1200, 2400, 9600, 19200 or 38400.\n");
          break;
  } 


if(tcgetattr(fd, &oldtio) != 0){
	printf(" \n Error: tcgetattr \n");
	return -1;
}

tio = oldtio;

/* no estamos preocupados por la preservación de la antigua configuración del puerto serie
 * CS8, 8 data bits
 * CREAD, receiver enabled
 * CLOCAL, no cambie el propietario del puerto
 */
  tio.c_cflag = baud | CS8 | CREAD | CLOCAL; //CLOACAL ignora el estado de linea del modem  

  tio.c_cflag &= ~HUPCL; /* clear the HUPCL bit, close doesn't change DTR; HUPCL: hang up on last close. */

//  tio.c_lflag = 0;       /* set input flag noncanonical, no processing */

    tio.c_lflag &= ~(ECHO | ICANON | ISIG);
    
    tio.c_iflag = IGNPAR;  /* ignore parity errors */

//  tio.c_oflag = 0;       /* set output flag noncanonical, no processing */

    tio.c_oflag &= ~OPOST;

    tio.c_cc[VTIME] = 0;   /* no time delay */
    tio.c_cc[VMIN]  = 1;   /* no char delay */

  tcflush(fd, TCIFLUSH); /* flush the buffer */
  tcsetattr(fd, TCSANOW, &tio); /* set the attributes */

/* Set up for no delay, ie nonblocking reads will occur.
   When we read, we'll get what's in the input buffer or nothing */
//  fcntl(fd, F_SETFL, FNDELAY);

fcntl(fd, F_SETFL, 0); //transmición síncrona.

while(1){

	system("clear");//Limpieza de pantalla
	printf("\nSeleccione la secuencia de luces a ejecturar en el Dispositivo Remoto:\n -1)Auto Fantastico\n -2)La Carrera\n -3)El Choque\n -4)La Apilada\n -5)Secuencia 5\n -6)Secuencia 6\n -7)Secuencia 7\n -8)Secuencia 8\n -9)Salir del Programa");
	
	printf("\n\n Presione: \n'a' para aumentar la velocidad de las secuencias \n'd' para disminuir la velocidad de las secuencias \n's' para salir de la secuencia elegida ");
		
	
	printf("\n\n Opción: ");
		
	scanf(" %c", &dato); /* dato es un tipo de variable char, se deja un espacio en blanco " %c", para no tener problemas con el buffer*/	
	getchar();

	result = write(fd, &dato, 1);
  		if (result < 0)
  		{
  		  fputs("write failed\n", stderr);
   	          close(fd);
  		  exit(1);
 		 }
		
	switch(dato){
		case '0':
		break;
		
		case '1':
		printf("\nEjecutando Auto Fantastico\n");
		usleep(1000 * 2000);
		break;
		
		case '2':
		printf("\nEjecutando La Carrera\n");
		usleep(1000 * 2000);
		break;
		
		case '3':
		printf("\nEjecutando El Choque\n");
		usleep(1000 * 2000);
		break;
		
		case '4':
		printf("\nEjecutando La Apilada\n");
		usleep(1000 * 2000);
		break;
		
		case '5':
		printf("\nEjecutando Secuencia 5\n");
		usleep(1000 * 2000);
		break;
		
		case '6':
		printf("\nEjecutando Secuencia 6\n");
		usleep(1000 * 2000);
		break;
		
		case '7':
		printf("\nEjecutando Secuencia 7\n");
		usleep(1000 * 2000);
		break;
		
		case '8':
		printf("\nEjecutando Secuencia 8\n");
		usleep(1000 * 2000);
		break;
		
		case 'a':
		printf("\nAumentando velocidad\n");
		usleep(1000 * 1000);
		break;
		
		case 'd':
		printf("\nDisminuyendo velocidad\n");
		usleep(1000 * 1000);
		break;
		
		case 's':
		printf("\nSecuencia de luces apagada\n");
		usleep(1000 * 2000);
		break;
		
		case '9':
		printf("\nCerrando Puerto...\n");
		tcsetattr(fd, TCSANOW, &oldtio);
		close(fd);
		return 0;
		
		default:
		printf("\n****SELECCIÓN NO VÁLIDA****\n");
		usleep(1000 * 2000);
		break;
	}
}
  return 0;
}
