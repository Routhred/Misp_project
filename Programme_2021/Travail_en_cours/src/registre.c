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
    int registre_protege[] = {0,26,27,30};
    for(int i = 0;i<4;i++){
        if (registre == registre_protege[i]){
            result = 0;
        }
    }
    return result;


}
void afficherRegistres(){
    printf("\n==========================================\nAffichage des registres\n");
    for(int i = 0;i<8;i++){
        printf(" [%d][%s] %x\t\t\t\t[%d][%s] %x\t\t\t\t[%d][%s] %x\t\t\t\t[%d][%s] %x\n",i,mnemo[i],binToInt(GBR[i]),i+8,mnemo[i+8],binToInt(GBR[i+8]),i+16,mnemo[i+16],binToInt(GBR[i+16]),i+24,mnemo[i+24],binToInt(GBR[i+24]));
    }
    printf("\n\n [%d][%s] %x\t\t\t\t[%d][%s] %x\t\t\t\t[%d][%s] %x\n",32,mnemo[32],binToInt(GBR[32]),33,mnemo[33],binToInt(GBR[33]),34,mnemo[34],binToInt(GBR[34]));
    printf("\n==========================================\n");
}
void inc(int registre){
    char value[33];
    char un[]="00000000000000000000000000000001";
    lireRegistre(registre, value);
    somme(un,value,value);
    ecrireRegistre(registre,value);
}
void stockerRegistres(char dest[]){
    FILE * fichier_registre;
    fichier_registre = fopen(dest,"w");
    char buffer[20];
    char hexa[9];
    char value[3];
    for(int i = 0;i<35;i++){
        binToHex(GBR[i],hexa);
        value[0] = (i/10)+48;
        value[1] = (i%10)+48;
        strcat(strcpy(buffer,"$"),value);
        strcat(buffer," :");
        strcat(buffer,hexa);

        fputs(buffer,fichier_registre);
        fputs("\n",fichier_registre);
    }
    fclose(fichier_registre);
}
