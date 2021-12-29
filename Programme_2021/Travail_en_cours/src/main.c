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
char temp_pc[100];
char buffer [100];
char buffer1 [100];
//variable temporaire
int pc = 0;
int id = 0;
int decimal;
int fin = 0;
//il sera interdit d'ecrire en dessous de la memoire de base, ca sera la memoire deidee a l'alocation du programme
int memoire_base;


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
        memoire_base = traduireFichier(source,dest,0,programme_in,code);
    //si on a 4 arguments alors on utilise le mode pas a pas
    }else if((argc == 4)&&!(strcmp("-pas",argv[3]))){
        char * source = strcat(strcpy(buffer1,path_test),argv[1]);
        char * dest = strcat(strcpy(buffer,path_hex),argv[2]);
        printf("===================================\n\nMode pas a pas\n\n===================================\n");
        memoire_base = traduireFichier(source,dest,1,programme_in,code);
    //sinon on indique une erreur
    }else{
        printf("\nEcrivez le chemins du fichier source en lancement du programme ou de bons arguments\n");
    }
    printf("\n===================================\n");
    //afficherProgrammeInstruction(programme_in);
    printf("colonne 1 : PC\ncolonne 2 : Registre modifié\ncolonne 3 : Nouvelle valeur registre\ncolonne 4 : adresse memoire modifiée\ncolonne 5 : nouvelle valeur memoire\ncolonne 6 : instruction en cours\n");
    printf("\n===================================\n");
    //tant que l'instruction courante est active
    while((pc<memoire_base)&&(!fin)){
        //on lite la valeur du programme compteur
        lireRegistre(32,temp_pc);
        binToHex(temp_pc,buffer);
        printf("%s\t",buffer);
        //on calcul la valeur du pc en fonction du registre pc
        pc = binToInt(temp_pc);
        id = pc/4;
        //si l'instruction designee par le prochain pc est active alor on incrémente le registre pc
        if(pc<memoire_base){
            inc(32);
            inc(32);
            inc(32);
            inc(32);
            //printf("PC = %d = %s\t",pc,temp_pc);
            //on effectue l'instruction courante
            faireInstruction(programme_in[id]);
            printf("%s",code[id]);
        }else{
            //sinon c'est la fin du programme, on sort du while
            printf("Fin du programme");
            fin = 1;
        }
        printf("                                                                                            \n");
    }
    afficherRegistres();
    //afficherMemoire(0,40);
    

    return 0;
}
