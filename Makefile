# .PHONY: clean

# objetos = main.o readADC.o lectura.o recibir.o secuencia8_prendeapaga.o secuencia7_parimpar.o secuencia6_puente.o setGPIO.o secuencia5_parpadeo.o elchoque.o apilada.o control.o apagar.o key.o autofantastico.o lacarrera.o EasyPIO.o strcmp_arm.o


# integrador: $(objetos) EasyPIO.h
# 	gcc -o integrador $(objetos) -lwiringPi

# EasyPIO.o: EasyPIO.c
# 	gcc -static -c EasyPIO.c -o EasyPIO.o

# main.o: main.c
# 	gcc -c $^

# setGPIO.o: setGPIO.c
# 	gcc -c $^

# # Regla específica para compilar el archivo de ensamblador
# strcmp_arm.o: strcmp_arm.s
# 	gcc -c $^

# key.o: key.c
# 	gcc -c $^

# autofantastico.o: autofantastico.c
# 	gcc -c $^

# lacarrera.o: lacarrera.c
# 	gcc -c $^

# elchoque.o: elchoque.c
# 	gcc -c $^

# apilada.o: apilada.c
# 	gcc -c $^

# secuencia5_parpadeo.o: secuencia5_parpadeo.c
# 	gcc -c $^

# secuencia6_puente.o: secuencia6_puente.c
# 	gcc -c $^

# secuencia7_parimpar.o: secuencia7_parimpar.c
# 	gcc -c $^

# secuencia8_prendeapaga.o: secuencia8_prendeapaga.c
# 	gcc -c $^

# apagar.o: apagar.c
# 	gcc -c $^

# control.o: control.c
# 	gcc -c $^

# recibir.o: recibir.c
# 	gcc -c $^

# lectura.o: lectura.c
# 	gcc -c $^

# readADC.o: readADC.c
# 	gcc -c $^

# clean: 
# 	rm -f integrador *.o
.PHONY: clean

# Lista de todos los archivos objeto
objetos = main.o readADC.o lectura.o recibir.o secuencia8_prendeapaga.o secuencia7_parimpar.o secuencia6_puente.o setGPIO.o secuencia5_parpadeo.o elchoque.o apilada.o control.o apagar.o key.o autofantastico.o lacarrera.o EasyPIO.o strcmp_arm.o

# Nombre del ejecutable final
ejecutable = integrador

# Regla para construir el ejecutable final
$(ejecutable): $(objetos) EasyPIO.h
	gcc -o $(ejecutable) $(objetos) -lwiringPi

# Reglas para compilar cada archivo fuente
main.o: main.c
	gcc -c $^

setGPIO.o: setGPIO.c
	gcc -c $^

# Regla específica para compilar el archivo de ensamblador
strcmp_arm.o: strcmp_arm.s
	gcc -c $^

key.o: key.c
	gcc -c $^

autofantastico.o: autofantastico.c
	gcc -c $^

lacarrera.o: lacarrera.c
	gcc -c $^

elchoque.o: elchoque.c
	gcc -c $^

apilada.o: apilada.c
	gcc -c $^

secuencia5_parpadeo.o: secuencia5_parpadeo.c
	gcc -c $^

secuencia6_puente.o: secuencia6_puente.c
	gcc -c $^

secuencia7_parimpar.o: secuencia7_parimpar.c
	gcc -c $^

secuencia8_prendeapaga.o: secuencia8_prendeapaga.c
	gcc -c $^

apagar.o: apagar.c
	gcc -c $^

control.o: control.c
	gcc -c $^

recibir.o: recibir.c
	gcc -c $^

lectura.o: lectura.c
	gcc -c $^

readADC.o: readADC.c
	gcc -c $^


clean: 
	rm -f $(ejecutable) *.o
