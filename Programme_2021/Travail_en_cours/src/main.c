#include "Fonction.h"
#include "memory.h"
#include "registre.h"
#include "utile.h"
#include "instruction.h"


//chemins des fichiers source et dest
char * path_test = "tests/";
char * path_hex = "hexified/";
//declaration des tableaux contenant le programme
instruction programme_in[MAX_PRG];
//tableau temporaires
char buffer[100];
char buffer1 [100];
//valeurs de test
char valeur_test[] = "00001111000011110000111100001111";
int adresse = 10;


int main(int argc,char * argv[]){

    printf("===================================\nDebut programme\n===================================");
    //on initialise les registres qui doivent l'être
    init_registre();
    //si on a que 3 arguments alors on traduit le fichier en entier
    //on met le resultat dans le fichier de destination 
    //on remplit les tableaux programme
    if (argc == 3){
        //creation des fichiers sources et dest
        char * source = strcat(strcpy(buffer1,path_test),argv[1]);
        char * dest = strcat(strcpy(buffer,path_hex),argv[2]);
        printf("\n\nMode fichier\n\n===================================");
        //traduction du fichier source
        traduireFichier(source,dest,0,programme_in);
    //si on a 4 arguments alors on utilise le mode pas a pas
    }else if((argc == 4)&&!(strcmp("-pas",argv[3]))){
        char * source = strcat(strcpy(buffer1,path_test),argv[1]);
        char * dest = strcat(strcpy(buffer,path_hex),argv[2]);
        printf("===================================\n\nMode pas a pas\n\n===================================\n");
        traduireFichier(source,dest,1,programme_in);
    //sinon on indique une erreur
    }else{
        printf("\nEcrivez le chemins du fichier source en lancement du programme ou de bons arguments\n");
    }
    
    afficherProgrammeInstruction(programme_in);
    

    return 0;
}
