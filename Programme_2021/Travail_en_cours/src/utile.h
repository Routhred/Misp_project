#ifndef __UTILE_H__
#define __UTILE_H__




#include "struct.h"


//Fonction qui sert a afficher les nb premiers élements d'une instruction passée en parametre
void afficher_instruction(instruction *in,int nb);
/*************************************************************************************************************
*						Decimal to binaire:
*	on prend un tableau en entrée avec une taille de retour voulu
**************************************************************************************************************/
void decToBin(char tableau[],int taille);
/*************************************************************************************************************
*						complementADeux
*	Prend un tableau de char en parametre et la taille du tableau de retour
* Modifie le tableau d'entree en mettant l'opposé de la valeur du tableau (binaire) pour avoir l'inverse en
*complement a deux
**************************************************************************************************************/
void complementADeux(char tableau[],int taille);
// enleve le premier caractere d'un tableau de taille taille

void enleverPremierChar(char tableau[],int taille);
//Traduit le tableau bin de 32 bits en hexadécimal et le met dans le tableau hex
void binToHex(char bin[],char hex[]);
//affiche les instructions du programme
void afficherProgrammeInstruction(instruction programme[MAX_PRG]);
//somme de 2 tableaux de 32 bits
void somme(char tab1[],char tab2[],char result[]);


#endif