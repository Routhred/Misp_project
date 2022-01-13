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
	char temp[8];
	
	for(int i = 0;i<4;i++){
		strcpy(temp,memoire[adresse+i]);
		for(int j = 0;j<8;j++){
			value[j+8*i] = temp[j];
			printf(" value[%d] = %c\n",j+8*i,value[j+8*i]);
		}
	}
	value[32] = '\0';
}
void afficherMemoire(int a,int b){
    for(int i = a;i<5000;i++){
        if((memoire[i][0]=='0')||(memoire[i][0]=='1')){
		printf("Adresse: %d,\tvaleur: %s\n",i,memoire[i]);
	}
}

}