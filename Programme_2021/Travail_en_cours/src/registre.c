#include "registre.h"



char GBR[35][33];
char mnemo[35][5] = {"x0","at","v0","v1","a0","a1","a2","a3","t0","t1","t2","t3","t4","t5","t6","t7","s0","s1","s2","s3"
                    ,"s4","s5","s6","s7","t8","t9","k0","k1","gp","sp","fp","ra","pc","lo","hi"};
void init_registre(){
    strcpy(GBR[0],"00000000000000000000000000000000");
    strcpy(GBR[32],"00000000000000000000000000000000");

}
void ecrireRegistre(int registre, char value[]){
    if(verifRegistre(registre)){
        strcpy(GBR[registre], value);
            //printf("\nRegistre: %d <= Valeur : __%s__\n", registre, GBR[registre]);
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
    for(int i = 0;i<8;i++){
        printf(" [%s] %d\t[%s] %d\t[%s] %d\t[%s] %d\n",mnemo[i],binToInt(GBR[i]),mnemo[i+8],binToInt(GBR[i+8]),mnemo[i+16],binToInt(GBR[i+16]),mnemo[i+24],binToInt(GBR[i+24]));
    }
    printf("\n\n [%s] %d\t[%s] %d\t[%s] %d\n",mnemo[32],binToInt(GBR[32]),mnemo[33],binToInt(GBR[33]),mnemo[34],binToInt(GBR[34]));
    printf("==========================================\n");
}
void inc(int registre){
    char value[33];
    char un[]="00000000000000000000000000000001";
    lireRegistre(registre, value);
    somme(un,value,value);
    ecrireRegistre(registre,value);
}