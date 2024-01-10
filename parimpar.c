//#include "EasyPIO.h"
#include <wiringPi.h>
#include <stdio.h>

void velocidad();

//const unsigned char Leds[8]={23,24,25,12,16,20,21,26};
//const unsigned char PULS=17;

extern int vel,time,Leds[8],PULSADOR;

void parimpar() {
    //pioInit();
    int i,j,PULS=0;
    int out[8]={0,0,0,0,0,0,0,0};

    // for(i=0;i<8;i++){
    //     pinMode(Leds[i], OUTPUT);
    //         };

    // pinMode(PULS,INPUT);


    while(1){

        printf("Secuencia: ParImpar.\n Para salir presione EL PULSADOR!!\n");


        for(i=0; i<4; i++){
            digitalWrite(Leds[(i*2)],1);
        }
        velocidad();
        delay(time);

        for(i=0; i<8; i++){
            digitalWrite(Leds[i],0);
        }
        velocidad();
        delay(time);

        for(i=1; i<5; i++){
            digitalWrite(Leds[(i*2)-1],1);
        }
        velocidad();
        delay(time);

        for(i=0; i<8; i++){
            digitalWrite(Leds[i],0);
        }
        velocidad();
        delay(time);

        PULS=digitalRead(PULSADOR);

        //delayMillis(100);
        if(PULS==1){
            goto salir;
        }
    }


    salir: 

    for(j=0;j<8;j++){
        digitalWrite(Leds[j],0);
    }
    // for(i=0;i<8;i++){
    //     pinMode(Leds[i], INPUT);
    // }

}