//#include "EasyPIO.h"
#include <wiringPi.h>
#include <stdio.h>

void velocidad();

// const unsigned char Leds[8]={23,24,25,12,16,20,21,26};
// const unsigned char PULS=17;

extern int vel,time,Leds[8],PULSADOR;

void prendeapaga() {
    //pioInit();
    int i,j,PULS=0;
    int out[8]={0,0,0,0,0,0,0,0};

    // for(i=0;i<8;i++){
    //     pinMode(Leds[i], OUTPUT);
    //         };

    // pinMode(PULS,INPUT);


    while(1){

        printf("Secuencia: PrendeApaga.\n Para salir presione EL PULSADOR!!\n");

        for(i=0; i<8; i++){
            digitalWrite(Leds[i],1);
        }
        velocidad();
        delay(time);

        for(i=0; i<8; i++){
            digitalWrite(Leds[i],0);
        }
        velocidad();
        delay(time);
        
        for(i=0;i<=7;i++){
            if(i==0){
                digitalWrite(Leds[7], 0);
                digitalWrite(Leds[0], 1);
                }
            else{
                out[i]=1;
                out[i-1]=0;
                digitalWrite(Leds[i-1], out[i-1]);
                digitalWrite(Leds[i], out[i]);
            }
            PULS=digitalRead(PULSADOR);

            delay(100);

            if(PULS==1){
                break;
            }

        }
        for(j=7;j>=0;j--){
            if(j==7){

                digitalWrite(Leds[0], 0);
                digitalWrite(Leds[7], 1);
            }
            else{
                out[j]=1;
                out[j+1]=0;
                digitalWrite(Leds[j], out[j]);
                digitalWrite(Leds[j+1], out[j+1]);

            }
            PULS=digitalRead(PULSADOR);

            delay(100);
            if(PULS==1){
                break;
            }
        }
    }


    for(j=0;j<8;j++){
        digitalWrite(Leds[j],0);
    }

    // for(i=0;i<8;i++){
    //     pinMode(Leds[i], INPUT);
    //         }
}