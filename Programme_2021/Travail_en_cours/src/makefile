
all : Fonction.o main.o registre.o memory.o
	gcc Fonction.o main.o registre.o memory.o -o prog -Wall

Fonction.o : Fonction.c Fonction.h data.h struct.h
	gcc -c Fonction.c -o Fonction.o -Wall

registre.o : registre.c registre.h struct.h
	gcc -c registre.c -o registre.o -Wall

memory.o : memory.c memory.h struct.h
	gcc -c memory.c -o memory.o -Wall

main.o : main.c Fonction.h data.h memory.h registre.h
	gcc -c main.c -o main.o -Wall

clean :
	rm *.o

