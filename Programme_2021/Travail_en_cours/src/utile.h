#ifndef __UTILE_H__
#define __UTILE_H__




#include "struct.h"



void afficher_instruction(instruction *in,int nb);
void decToBin(char tableau[],int taille);
void complementADeux(char tableau[],int taille);
void enleverPremierChar(char tableau[],int taille);
void binToHex(char bin[],char hex[]);
void affiche_programme_binaire(char  programme[MAX_PRG][33]);



#endif