all: planetas.o funciones.o
	gcc -o planetas planetas.o funciones.o -lm

funciones.o: funciones.c funciones.h planetas.h
	gcc -c funciones.c

clean: 
	rm -f planetas *.o