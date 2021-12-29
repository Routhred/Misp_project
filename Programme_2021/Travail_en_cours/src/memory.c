#include "memory.h"
char memoire [5000][9]; 
//********************************************************************************
//  Ici sera définie la mémoire et seule les fonctions de ce module pourront modifier et accéder a la memoire
//  On devra avoir les fonctions suivantes:
//      void EcrireMemoire(char value[], int adresse)
//      void LireMemoire(int registre, int adresse)

void ecrireMemoire(char value[],int adresse){
    size_t taille = strlen(value);
    int j = 0;
    for(int i = 0;i<taille;i++){
        memoire[adresse+(i/8)][j] = value[i];
        if(j>=7){
            j = 0;
        }else{
            j++;
        }
    }
        //printf("\nLa valeur : %s a ete copiée a l'adresse: %d\n",value, adresse);
}
void lireMemoire(char value[], int adresse){
    strcpy(value,memoire[adresse]);
}
void afficherMemoire(int a,int b){
    int i = a;
    for(i;i<b;i++){
        printf("Adresse: %d,\tvaleur: %s\n",i,memoire[i]);
    }

}