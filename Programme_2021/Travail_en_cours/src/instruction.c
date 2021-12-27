#include "instruction.h"
#include "registre.h"

void add(int dest,int first,int second){
    char value1[33];
    char value2[33];
    char value_dest[33];
    lireRegistre(first, value1);
    printf("Valeur du registre %d : %s\n",first,value1);
    lireRegistre(second, value2);
    printf("Valeur du registre %d : %s\n",second,value2);
    somme(value1,value2,value_dest);
    printf("Valeur du registre %d : %s\n",dest,value_dest);
    ecrireRegistre(dest,value_dest);

}