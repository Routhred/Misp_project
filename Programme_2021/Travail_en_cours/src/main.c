#include "Fonction.h"
#include "memory.h"
#include "registre.h"



char * path_test = "tests/";
char * path_hex = "hexified/";
char * programme[20];
char buffer[100];
char buffer1 [100];
//valeurs de test
char valeur_test[] = "00001111000011110000111100001111";
int adresse = 10;


int main(int argc,char * argv[]){

    printf("===================================\nDebut programme\n===================================");
    
    if (argc == 3){
        char * source = strcat(strcpy(buffer1,path_test),argv[1]);
        char* dest = strcat(strcpy(buffer,path_hex),argv[2]);
        printf("===================================\n\nMode fichier\n\n===================================");
        traduireFichier(source,dest,0,programme);
    }else if((argc == 4)&&!(strcmp("-pas",argv[3]))){
        char * source = strcat(strcpy(buffer1,path_test),argv[1]);
        char* dest = strcat(strcpy(buffer,path_hex),argv[2]);
        printf("===================================\n\nMode pas a pas\n\n===================================\n");
        traduireFichier(source,dest,1,programme);
    }else{
        printf("\nEcrivez le chemins du fichier source en lancement du programme ou de bons arguments\n");
    }

    affiche_programme_binaire(programme);
    

    return 0;
}
