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
char code [MAX_PRG][100];
//tableau temporaires
char buffer[100];
char buffer1 [100];
//variable temporaire
int decimal;
int i = 0;
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
        printf("\n\nMode fichier\n\n===================================\n");
        //traduction du fichier source
        traduireFichier(source,dest,0,programme_in,code);
    //si on a 4 arguments alors on utilise le mode pas a pas
    }else if((argc == 4)&&!(strcmp("-pas",argv[3]))){
        char * source = strcat(strcpy(buffer1,path_test),argv[1]);
        char * dest = strcat(strcpy(buffer,path_hex),argv[2]);
        printf("===================================\n\nMode pas a pas\n\n===================================\n");
        traduireFichier(source,dest,1,programme_in,code);
    //sinon on indique une erreur
    }else{
        printf("\nEcrivez le chemins du fichier source en lancement du programme ou de bons arguments\n");
    }
    printf("\n===================================\n");
    //afficherProgrammeInstruction(programme_in);
    printf("colonne 1 : PC\ncolonne 2 : Registre modifié\ncolonne 3 : Nouvelle valeur registre\ncolonne 4 : adresse memoire modifiée\ncolonne 5 : nouvelle valeur memoire\ncolonne 6 : instruction en cours\n");
    printf("\n===================================\n");
    while(programme_in[i].binaire[0]!='Z'){
        lireRegistre(32,buffer);
        binToHex(buffer,buffer1);
        printf("%s\t",buffer1);
        faireInstruction(programme_in[i]);
        printf("%s",code[i]);
        if(programme_in[i+1].binaire[0]!='Z'){
            inc(32);
            inc(32);
            inc(32);
            inc(32);
        }
        
        printf("                                                                                            \n");
        i++;
    }
    afficherRegistres();
    afficherMemoire(0,40);
    

    return 0;
}
