
all : Fonction.o main.o registre.o memory.o utile.o instruction.o
	gcc Fonction.o main.o registre.o memory.o utile.o instruction.o -o prog -Wall -lm

Fonction.o : Fonction.c Fonction.h data.h struct.h utile.h
	gcc -c Fonction.c -o Fonction.o -Wall

registre.o : registre.c registre.h struct.h utile.h
	gcc -c registre.c -o registre.o -Wall

memory.o : memory.c memory.h struct.h utile.h
	gcc -c memory.c -o memory.o -Wall

utile.o : utile.c utile.h struct.h
	gcc -c utile.c -o utile.o -Wall

instruction.o : instruction.c instruction.h registre.h utile.h
	gcc -c instruction.c -o instruction.o -Wall

main.o : main.c Fonction.h data.h memory.h registre.h utile.h instruction.h
	gcc -c main.c -o main.o -Wall

clean :
	rm *.o

