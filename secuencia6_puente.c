// #include "EasyPIO.h"
// #include <stdio.h>
// #include <unistd.h>
// #include <unistd.h> 
// #include <stdlib.h>

// extern int led[], aux;
// void control(void);

// void secuencia6_puente(void)
// {	int matriz[38][8]={
//                     {0,0,0,0,0,0,0,0},
//                     {0,0,0,0,0,0,0,1},
//                     {0,0,0,0,0,0,0,0},
//                     {1,0,0,0,0,0,0,0},
//                     {0,0,0,0,0,0,0,0},
//                     {0,1,0,0,0,0,0,0},
//                     {0,0,0,0,0,0,1,0},
//                     {0,0,0,0,0,0,0,0},
//                     {0,0,0,0,0,1,0,0},
//                     {0,0,1,0,0,0,0,0},
//                     {0,0,0,0,0,0,0,0},
//                     {0,0,0,1,0,0,0,0},
//                     {0,0,0,0,1,0,0,0},
//                     {0,0,0,0,0,0,0,0}};

// 	system("clear");
// 	printf("SECUENCIA 6: Puente\n");
// 	printf("Presione los dos pulsadores al mismo tiempo para salir\n");
// 	aux = 0;
// 	while(1){

// 			for(int i=0;i<2;i++){

// 				control();
// 			for(int i=0;i<38;i++){
//             for(int j=0;j<8;j++){
//                 digitalWrite(led[j],matriz[i][j]);
//                 control();
// 				if(aux) return;

// 				else{
// 					for(int t=0; t<8; t++){
// 					digitalWrite(led[t], matriz[i][t]);		// desplazamiento en la matriz de leds
// 								}	
// 					}				
// 				}		
//             }
//         }
//     }
// }

#include "EasyPIO.h"
#include <stdio.h>
#include <unistd.h>
#include <unistd.h> 
#include <stdlib.h>

extern int led[], aux;
void control(void);

void secuencia6_puente(void)
{	int matriz[][8]={{1,0,0,0,0,0,0,0},
		  {0,0,0,0,0,0,0,0},
		  {1,0,0,0,0,0,0,0},
                  {0,1,0,0,0,0,0,0},
                  {1,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0},
                  {1,0,0,0,0,0,0,0},
                  {0,1,0,0,0,0,0,0},
                  {0,0,1,0,0,0,0,0},
                  {0,1,0,0,0,0,0,0},
                  {1,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0},
                  {1,0,0,0,0,0,0,0},
                  {0,1,0,0,0,0,0,0},
                  {0,0,1,0,0,0,0,0},
                  {0,0,0,1,0,0,0,0},
                  {0,0,1,0,0,0,0,0},
                  {0,1,0,0,0,0,0,0},
                  {1,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0},
                  {1,0,0,0,0,0,0,0},
                  {0,1,0,0,0,0,0,0},
                  {0,0,1,0,0,0,0,0},
                  {0,0,0,1,0,0,0,0},
                  {0,0,0,0,1,0,0,0},
                  {0,0,0,1,0,0,0,0},
                  {0,0,1,0,0,0,0,0},
                  {0,1,0,0,0,0,0,0},
                  {1,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0},
                  {1,0,0,0,0,0,0,0},
                  {0,1,0,0,0,0,0,0},
                  {0,0,1,0,0,0,0,0},
                  {0,0,0,1,0,0,0,0},
                  {0,0,0,0,1,0,0,0},
                  {0,0,0,0,0,1,0,0},
                  {0,0,0,0,1,0,0,0},
                  {0,0,0,1,0,0,0,0},
                  {0,0,1,0,0,0,0,0},
                  {0,1,0,0,0,0,0,0},
                  {1,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0},
                  {1,0,0,0,0,0,0,0},
                  {0,1,0,0,0,0,0,0},
                  {0,0,1,0,0,0,0,0},
                  {0,0,0,1,0,0,0,0},
                  {0,0,0,0,1,0,0,0},
                  {0,0,0,0,0,1,0,0},
                  {0,0,0,0,0,0,1,0},
                  {0,0,0,0,0,1,0,0},
                  {0,0,0,0,1,0,0,0},
                  {0,0,0,1,0,0,0,0},
                  {0,0,1,0,0,0,0,0},
                  {0,1,0,0,0,0,0,0},
                  {1,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0},
                  {1,0,0,0,0,0,0,0},
                  {0,1,0,0,0,0,0,0},
                  {0,0,1,0,0,0,0,0},
                  {0,0,0,1,0,0,0,0},
                  {0,0,0,0,1,0,0,0},
                  {0,0,0,0,0,1,0,0},
                  {0,0,0,0,0,0,1,0},
                  {0,0,0,0,0,0,0,1},
                  {0,0,0,0,0,0,1,0},
                  {0,0,0,0,0,1,0,0},
                  {0,0,0,0,1,0,0,0},
                  {0,0,0,1,0,0,0,0},
                  {0,0,1,0,0,0,0,0},
                  {0,1,0,0,0,0,0,0},
                  {1,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0}};

	system("clear");
	printf("SECUENCIA 6: forwardYbackward\n");
	printf("Presione los dos pulsadores al mismo tiempo para salir\n");
	aux = 0;
	while(1){

			for(int i=0;i<2;i++){

				control();
			for(int i=0;i<72;i++){
            for(int j=0;j<8;j++){
                digitalWrite(led[j],matriz[i][j]);
                control();
				if(aux) return;

				else{
					for(int t=0; t<8; t++){
					digitalWrite(led[t], matriz[i][t]);		// desplazamiento en la matriz de leds
								}	
					}				
				}		
            }
        }
    }
}
