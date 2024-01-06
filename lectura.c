#include <sys/ioctl.h>
#include <fcntl.h>
#include <termios.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>


char lectura(int fd){
	char buf;
	int valor;
	valor = read(fd,&buf,1);
	
	if(valor)
		return buf;
		
	return '0';	
}
