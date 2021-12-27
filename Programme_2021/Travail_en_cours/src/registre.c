#include "registre.h"


char GBR[32][32];

void init_registre(){
    strcpy(GBR[0],"00000000000000000000000000000000");

}
void ecrireRegistre(int registre, char value[]){
    if(verifRegistre(registre)){
        strcpy(GBR[registre], value);
        printf("\nRegistre: %d <= Valeur : %s\n", registre, GBR[registre]);
    }else{
        printf("Erreur, registre protégé\n");
    }
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