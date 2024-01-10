//#include "EasyPIO.h"
#include <wiringPi.h>
#include <stdio.h>

void velocidad();

// const unsigned char Leds[8]={23,24,25,12,16,20,21,26};
// const unsigned char PULS=17;

extern int vel,time,Leds[8],PULSADOR;

void puente() {

    int i,j,PULS=0;
    int Mat[18][8]={{0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,1},
                    {0,0,0,0,0,0,0,0},
                    {1,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,1,0,0,0,0,0,0},
                    {0,0,0,0,0,0,1,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,1,0,0},
                    {0,0,1,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,1,0,0,0,0},
                    {0,0,0,0,1,0,0,0},
                    {0,0,0,0,0,0,0,0}};

    // pioInit();
    // pinMode(PULS,INPUT);

    // for(i=0;i<8;i++){
    //     pinMode(Leds[i], OUTPUT);
    //         };

    while(1){

    printf("Secuencia: Puente.\n Para salir presione EL PULSADOR!!\n");

        for(i=0;i<18;i++){
            for(j=0;j<8;j++){
                digitalWrite(Leds[j],Mat[i][j]);
                PULS=digitalRead(PULSADOR);
                if(PULS==1){
                    goto salir;
                }
                velocidad();
                delay(time);
            }
        }
    }

    salir:
    for(j=0;j<8;j++){
        digitalWrite(Leds[j],0);
    }

    // for(i=0;i<8;i++){
    //     pinMode(Leds[i], INPUT);
    //         }
}