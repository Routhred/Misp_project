#ifndef __REGISTRE_H__
#define __REGISTRE_H__
#include "struct.h"
#include "utile.h"
#define MAX 200
//initalise les registres
void init_registre();
//ecrire une valeur sur 32 bits dans un registre
void ecrireRegistre(int registre, char value[]);
//1 si le registre n'est pas protégé 0 sinon
int verifRegistre(int registre);
//affiche toute la memoire registre
void afficherRegistres();
//incremente un registre passé en parametre
void inc(int registre);
//lit ce qu'il y a dans un registre
void lireRegistre(int registre, char value[]);
void stockerRegistres(char dest[]);





#endif