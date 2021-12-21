#ifndef __FONCTION_H__
#define __FONCTION_H__

#include "struct.h"

#define MAX 200

void traduireFichier(char source[],char dest[]);
/*************************************************************************************************************
 * 											Slit:
 * 	Permet de découper la ligne passée en parametre, on utilise les delimitateurs " ,\n#()"
 *
 * **************************************************************************************************************/
int split(char ligne[], instruction *in);
/*************************************************************************************************************
 * 											findInstruction:
 * 	Permet de savoir a quelle ligne des tables de correspondance est l'instruction que l'on passe en parametre
 *
 * **************************************************************************************************************/
int findInstruction(instruction *in);
/*************************************************************************************************************
*						Fonction de trie des instruction:
*	lorsque l'on prend une instruction depuis le fichier, les operandes ne sont pas dans le même ordre que ce que
*	le misp va comprendre, on doit donc remettre les opérandes dans le bon ordre.
*	On utilise une table de correspondance se trouvant dans data.h: table_structure
**************************************************************************************************************/
void trier_instruction(instruction *in);
//Fonction qui sert a afficher les 5 premiers élements d'une instruction passée en parametre
void afficher_instruction(instruction *in,int nb);
void decToBin(char tableau[],int taille);
void structToTab(instruction *in);
void binToHex(char bin[],char hex[]);
void registre_mnemo(char in[],char out[]);
void complementADeux(char tableau[],int taille);
void enleverPremierChar(char tableau[],int taille);
#endif
