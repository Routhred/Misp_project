
all : Fonction.o main.o
	gcc Fonction.o main.o -o prog -Wall

Fonction.o : Fonction.c Fonction.h data.h struct.h
	gcc -c Fonction.c -o Fonction.o -Wall

main.o : main.c Fonction.h data.h
	gcc -c main.c -o main.o -Wall

clean :
	rm *.o
