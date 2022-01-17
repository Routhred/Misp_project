#ifndef __MEMORY_H__
#define __MEMORY_H__

#include "struct.h"
#include "utile.h"
//fonction pour ecrire dans la memoire, si la valeur fait plus de 8 bits on écrit sur plusieurs adresses
void ecrireMemoire(char value[],int adresse);
//fonction pour lire dans la mémoire, on vient lire 32bits sur 4 adresses
void lireMemoire(char value[], int adresse);
//fonction qui affiche toute la memoire utilisee
void afficherMemoire();











#endif