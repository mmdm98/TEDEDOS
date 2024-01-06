#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
 

#define GPIO_BASE  0x3F200000	// BCM2835_PERI_BASE + 0x200000
#define GPLEV0 (* (volatile unsigned int *) (gpio + 13))
#define BLOCK_SIZE (4*1024)   
#define GPFSEL 	 (volatile unsigned int *) (gpio)			
#define	GPSET	 (volatile unsigned int *) (gpio + 7)   
#define GPCLR	 (volatile unsigned int *) (gpio + 10)
#define	GPLEV	 (volatile unsigned int *) (gpio + 13)
#define	INPUT 0
#define OUTPUT 1
#define ALT0 4
#define HIGH 1
#define LOW 0

 

volatile unsigned int *gpio; //Pointer to base of gpio




void pioInit(){
	int fd;
	void *reg_map; // /dev/mem is a psuedo-driver for accessing memory in Linux
	fd = open("/dev/gpiomem", O_RDWR|O_SYNC);  // abre fichero /dev/gpiomem
	reg_map = mmap(						//dirección base del mapeo
	NULL,   							//No interesa donde comienza el bloque de memoria virtual
	BLOCK_SIZE,							// 4KB bloque mapeado
	PROT_READ|PROT_WRITE,				// permite lectura y escritura
	MAP_SHARED,							// acceso no exclusivo
	fd,									// puntero a /dev/gpiomem
	GPIO_BASE); 						// offset a la GPIO

	gpio = (volatile unsigned *)reg_map;  
	close(fd);
}


void pinMode(int num_pin, int modo)
{
	
	int num_reg,offset;
	
	num_reg= num_pin/10;
	offset= (num_pin % 10 ) * 3; 	
	
	*(GPFSEL + num_reg) &= ~((0b111 & ~modo) << offset);		
	*(GPFSEL + num_reg) |= ((0b111 & modo) << offset);		

}

void digitalWrite(int num_pin, int value )
{
	
	int num_reg,offset;	
	num_reg= num_pin/32;
	offset= num_pin % 32; 	

	if(value)
		*(GPSET + num_reg) = 1 << offset;
	else 
		*(GPCLR + num_reg) = 1 << offset;			

}

int digitalRead(int num_pin) {
	
int num_reg,offset;	
	num_reg= num_pin/32;
	offset= num_pin % 32;  

	if( *(GPLEV+num_reg) & (0b1 << offset))
		return 1;

	else 
		return 0; 
	

}
