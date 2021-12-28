#include "registre.h"


char GBR[33][33];

void init_registre(){
    strcpy(GBR[0],"00000000000000000000000000000000");
    strcpy(GBR[32],"00000000000000000000000000000000");

}
void ecrireRegistre(int registre, char value[]){
    if(verifRegistre(registre)){
        strcpy(GBR[registre], value);
        printf("\nRegistre: %d <= Valeur : __%s__\n", registre, GBR[registre]);
    }else{
        printf("Erreur, registre protégé\n");
    }
}

void lireRegistre(int registre, char value[]){
    strcpy(value, GBR[registre]);

}
int verifRegistre(int registre){
    int result = 1;
    int registre_protege[] = {0,1,26,27,2,30};
    for(int i = 0;i<6;i++){
        if (registre == registre_protege[i]){
            result = 0;
        }
    }
    return result;


}
void afficherRegistres(){
    printf("==========================================\nAffichage des registres\n");
    for(int i = 0;i<33;i++){
        printf("%s\n",GBR[i]);
    }
    printf("==========================================\n");
}
void inc(int registre){
    char value[33];
    char un[]="00000000000000000000000000000001";
    lireRegistre(registre, value);
    somme(un,value,value);
    ecrireRegistre(registre,value);
}