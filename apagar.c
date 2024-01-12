///////////////////////////////////////////////////////////////////////////////////////
/////                                                                             ///// 
/////                                    APAGAR                                   /////
/////                                                                             /////
///////////////////////////////////////////////////////////////////////////////////////
//User libs
#include "EasyPIO.h"

//User extern vars
extern int led[];

//User code
//se apaga cada led con un for
void apagar(void){

	for(int i=0; i<8; i++)
		digitalWrite(led[i],0);

 }

