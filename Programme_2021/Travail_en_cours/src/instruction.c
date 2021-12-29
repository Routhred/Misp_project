#include "instruction.h"
#include "registre.h"

void add(int dest,int first,int second){
        //printf("\nadd\n");
    //on créer des tableaux temporaires de 32 bits
    char value1[33];
    char value2[33];
    char value_dest[33];
    char hexa[9];
    //lecture du registre de la premiere operande
    lireRegistre(first, value1);
        //printf("Valeur du registre %d : %s\n",first,value1);
    //lecture du registre de la deuxieme operande
    lireRegistre(second, value2);
        //printf("Valeur du registre %d : %s\n",second,value2);
    //calcul de la valeur du registre de destination
    somme(value1,value2,value_dest);
        //printf("Valeur du registre %d : %s\n",dest,value_dest);
    //ecriture du tableau temporaire dans le registre de destination
    ecrireRegistre(dest,value_dest);
    binToHex(value_dest,hexa);
    printf("%d\t%s\tX\tX\t",dest,hexa);

}
void addi(int dest,int first,char immediate[]){
        //printf("\naddi\n");
    char value1[33];
    char im[33];
    char value_dest[33];
    char hexa[9];
    lireRegistre(first, value1);
        //printf("Valeur du registre first %d : %s\n",first,value1);
    tabTo32bits(im,immediate);
    somme(value1,im,value_dest);
        //printf("Valeur du registre second %d : %s\n",dest,value_dest);
    ecrireRegistre(dest,value_dest);
    binToHex(value_dest,hexa);
    printf("%d\t%s\tX\tX\t",dest,hexa);
}
void and(int dest,int first,int second){
    char value1[33];
    char value2[33];
    char value_dest[33];
    char hexa[9];
    //lecture du registre de la premiere operande
    lireRegistre(first, value1);
        //printf("Valeur du registre %d : %s\n",first,value1);
    //lecture du registre de la deuxieme operande
    lireRegistre(second, value2);
        //printf("Valeur du registre %d : %s\n",second,value2);
    //calcul de la valeur du registre de destination
    bitwiseAnd(value_dest,value1,value2);
        //printf("Valeur du registre %d : %s\n",dest,value_dest);
    //ecriture du tableau temporaire dans le registre de destination
    ecrireRegistre(dest,value_dest);
    binToHex(value_dest,hexa);
    printf("%d\t%s\tX\tX\t",dest,hexa);
}
void or(int dest,int first,int second){
    char value1[33];
    char value2[33];
    char value_dest[33];
    char hexa[9];
    //lecture du registre de la premiere operande
    lireRegistre(first, value1);
        //printf("Valeur du registre %d : %s\n",first,value1);
    //lecture du registre de la deuxieme operande
    lireRegistre(second, value2);
        //printf("Valeur du registre %d : %s\n",second,value2);
    //calcul de la valeur du registre de destination
    bitwiseOr(value_dest,value1,value2);
        //printf("Valeur du registre %d : %s\n",dest,value_dest);
    //ecriture du tableau temporaire dans le registre de destination
    ecrireRegistre(dest,value_dest);
    binToHex(value_dest,hexa);
    printf("%d\t%s\tX\tX\t",dest,hexa);
}
void xor(int dest,int first,int second){
    char value1[33];
    char value2[33];
    char value_dest[33];
    char hexa[9];
    //lecture du registre de la premiere operande
    lireRegistre(first, value1);
        //printf("Valeur du registre %d : %s\n",first,value1);
    //lecture du registre de la deuxieme operande
    lireRegistre(second, value2);
        //printf("Valeur du registre %d : %s\n",second,value2);
    //calcul de la valeur du registre de destination
    bitwiseXor(value_dest,value1,value2);
        //printf("Valeur du registre %d : %s\n",dest,value_dest);
    //ecriture du tableau temporaire dans le registre de destination
    ecrireRegistre(dest,value_dest);
    binToHex(value_dest,hexa);
    printf("%d\t%s\tX\tX\t",dest,hexa);
}


void faireInstruction(instruction in){
    switch(in.numero){
        case 0:
            add(binToInt(in.mots[3]),binToInt(in.mots[1]),binToInt(in.mots[2]));
            break;
        case 1:
            addi(binToInt(in.mots[2]),binToInt(in.mots[1]),in.mots[3]);
            break;
        case 2:
            and(binToInt(in.mots[3]),binToInt(in.mots[1]),binToInt(in.mots[2]));
            break;
        case 17:
            or(binToInt(in.mots[3]),binToInt(in.mots[1]),binToInt(in.mots[2]));
            break;
        case 25:
            xor(binToInt(in.mots[3]),binToInt(in.mots[1]),binToInt(in.mots[2]));
            break;
        default:
            printf("Pas d'instruction dispoonible\t");
            break;


    }
}