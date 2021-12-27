#include "Fonction.h"
#include "memory.h"
#include "registre.h"



char * path_test = "tests/";
char * path_hex = "hexified/";
char buffer[100];
char buffer1 [100];
//valeurs de test
char valeur_test[] = "00001111000011110000111100001111";
int adresse = 10;


int main(int argc,char * argv[]){
    /*
    if (argc == 3){
        char * source = strcat(strcpy(buffer1,path_test),argv[1]);
        char* dest = strcat(strcpy(buffer,path_hex),argv[2]);
        traduireFichier(source,dest,0);
    }else if((argc == 4)&&!(strcmp("-pas",argv[3]))){
        char * source = strcat(strcpy(buffer1,path_test),argv[1]);
        char* dest = strcat(strcpy(buffer,path_hex),argv[2]);
        traduireFichier(source,dest,1);
    }else{
        
        //printf("\n%d\n",strcmp("-pas",argv[3]));
        printf("\nEcrivez le chemins du fichier source en lancement du programme ou de bons arguments\n");
    }*/

    ecrireMemoire(valeur_test,adresse);
    lireMemoire(valeur_test, adresse);
    printf("Adresse : %d ; Valeur : %s ",adresse, valeur_test);
    
    for(int i = 0;i<6;i++){
        ecrireRegistre(i,valeur_test);
    }
    

    return 0;
}
