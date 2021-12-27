#include "memory.h"
char memoire [3000][33]; 
//********************************************************************************
//  Ici sera définie la mémoire et seule les fonctions de ce module pourront modifier et accéder a la memoire
//  On devra avoir les fonctions suivantes:
//      void EcrireMemoire(char value[], int adresse)
//      void LireMemoire(int registre, int adresse)

void ecrireMemoire(char value[],int adresse){
    strcpy(memoire[adresse],value);
    printf("\nLa valeur : %s a ete copiée a l'adresse: %d\n",memoire[adresse], adresse);
}
void lireMemoire(char value[], int adresse){
    strcpy(value,memoire[adresse]);
}
