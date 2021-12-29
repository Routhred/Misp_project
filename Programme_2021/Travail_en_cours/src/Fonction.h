#ifndef __FONCTION_H__
#define __FONCTION_H__

#include "struct.h"
#include "utile.h"

#define MAX 200

//permet de traduire tout le fichier source ligne par ligne et de mettre le resultat dans le fichier dest
int traduireFichier(char source[],char dest[],int mode,instruction programme[MAX_PRG],char code[MAX_PRG][100]);
/*************************************************************************************************************
 * 											Split:
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
/*************************************************************************************************************
*						instruction to table
*	on prend une instruction en entrée et on ressort un tableau binaire de 32bits en concatenant les differents
*	mots binaires de l'instruction
**************************************************************************************************************/
void structToTab(instruction *in);
//renvoie la valeur decimale d'un registre
void registre_mnemo(char in[],char out[]);
#endif
