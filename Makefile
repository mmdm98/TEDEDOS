.PHONY: clean

objetos = main.o leerAdc.o lectura.o recibir.o secuencia8.o secuencia7.o secuencia6.o set_gpio.o secuencia5.o elchoque.o apilada.o control.o apagar.o contrasenia.o autofantastico.o lacarrera.o EasyPIO.o

integrador: $(objetos) EasyPIO.h
	gcc -o integrador $(objetos) -lwiringPi

EasyPIO.o: EasyPIO.c
	gcc -static -c EasyPIO.c -o EasyPIO.o

main.o: main.c
	gcc -c $^

set_gpio.o: set_gpio.c
	gcc -c $^

contrasenia.o: contrasenia.c
	gcc -c $^

autofantastico.o: autofantastico.c
	gcc -c $^

lacarrera.o: lacarrera.c
	gcc -c $^

elchoque.o: elchoque.c
	gcc -c $^

apilada.o: apilada.c
	gcc -c $^

secuencia5.o: secuencia5.c
	gcc -c $^

secuencia6.o: secuencia6.c
	gcc -c $^

secuencia7.o: secuencia7.c
	gcc -c $^

secuencia8.o: secuencia8.c
	gcc -c $^

apagar.o: apagar.c
	gcc -c $^

control.o: control.c
	gcc -c $^

recibir.o: recibir.c
	gcc -c $^

lectura.o: lectura.c
	gcc -c $^

leerAdc.o: leerAdc.c
	gcc -c $^

clean: 
	rm -f integrador *.o