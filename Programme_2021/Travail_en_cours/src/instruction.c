#include "instruction.h"
#include "registre.h"

void add(int dest,int first,int second){
    //on créer des tableaux temporaires de 32 bits
    char value1[33];
    char value2[33];
    char value_dest[33];
    //lecture du registre de la premiere operande
    lireRegistre(first, value1);
    printf("Valeur du registre %d : %s\n",first,value1);
    //lecture du registre de la deuxieme operande
    lireRegistre(second, value2);
    printf("Valeur du registre %d : %s\n",second,value2);
    //calcul de la valeur du registre de destination
    somme(value1,value2,value_dest);
    printf("Valeur du registre %d : %s\n",dest,value_dest);
    //ecriture du tableau temporaire dans le registre de destination
    ecrireRegistre(dest,value_dest);

}