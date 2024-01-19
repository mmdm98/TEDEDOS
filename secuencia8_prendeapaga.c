#include "EasyPIO.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern int i, led[], aux, out[];

void control(void);

void secuencia8(void)
{
	system("clear");
	printf("SECUENCIA 8: Prendeapaga\n");
	printf("Presione los dos pulsadores al mismo tiempo para salir\n");
	aux = 0;
	while(1){
			for(int i=0 ;i < 8; i++){
				
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

            for(int j=7;j>=0;j--){
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
            digitalWrite(led[i],0);
            control();
			if(aux) return;
			
    }
}
