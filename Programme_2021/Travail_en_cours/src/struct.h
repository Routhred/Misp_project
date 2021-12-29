#ifndef __STRUCT_H__
#define __STRUCT_H__

#define MAX_PRG 1000
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//=========Define structures instructions==========
//Pour savoir quelle instruction est de quel type
typedef struct{
  char nom[8];
  char type[4];
  int operandes;
} type_instruction;
//Pour connaitre les ordres des opérandes de chaque instruction
typedef struct{
	char nom[8];
	char emplacement_operandes[10];
	char code [8];
}structure_instruction;
//pour connaitre les équivalences des noms et des numeros de registre
typedef struct{
	char mnemo[6];
	char reg[4];
	int bin[5];
}nom_registre;
//pour enregistrer chaque mot d'une instruction et le nombre d'opérande
typedef struct{
	char mots[10][32];
	int operandes;
	int numero;
	char binaire[33];
	char hexa[9];
	int actif;
}instruction;


#endif
