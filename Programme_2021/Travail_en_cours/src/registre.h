#ifndef __REGISTRE_H__
#define __REGISTRE_H__
#include "struct.h"

#define MAX 200
void init_registre();
//ecrire une valeur sur 32 bits dans un registre
void ecrireRegistre(int registre, char value[]);
//1 si le registre n'est pas protégé 0 sinon
int verifRegistre(int registre);
void afficherRegistres();
void inc(int registre);





#endif