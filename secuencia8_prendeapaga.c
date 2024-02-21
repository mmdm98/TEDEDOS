#include "EasyPIO.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern int led[], aux;

void control(void);
void apagar(void);

void secuencia8_prendeapaga(void)
{
	system("clear");
	printf("SECUENCIA 8: Prendeapaga\n");
	printf("Presione los dos pulsadores al mismo tiempo para salir\n");
	aux = 0;
    int out[8] ={0,0,0,0,0,0,0,0};
    int i, j = 0;
	while(1){
			for(i=0 ;i < 8; i++){
                digitalWrite(led[0], 1);
            }
            control();
			if(aux) return; 
            apagar();
                for(i=0;i<=7;i++){
                    if(i==0){
                    digitalWrite(led[7], 0);
                    digitalWrite(led[0], 1);
                }
                else{
                    out[i]=1;
                    out[i-1]=0;
                    digitalWrite(led[i-1], out[i-1]);
                    digitalWrite(led[i], out[i]);
                }      
				control();
				if(aux) return; 						
                }
            for( j=7;j>=0;j--){
                if(j==7){
                    digitalWrite(led[0], 0);
                    digitalWrite(led[7], 1);
                }
                else{
                    out[j]=1;
                    out[j+1]=0;
                    digitalWrite(led[j], out[j]);
                    digitalWrite(led[j+1], out[j+1]);
                }
            }
            apagar();
            control();
			if(aux) return;
			
    }
}
