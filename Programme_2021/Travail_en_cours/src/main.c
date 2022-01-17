#include "traduction.h"
#include "memory.h"
#include "registre.h"
#include "utile.h"
#include "instruction.h"

//arguments: 
//	argv[0] = nom du programme
//	argv[1] = nom du premier fichier
//	argv[2] = nom du fichier de destination de la traduction
//  argv[3] = nom du fichier de destination des registres

//chemins des fichiers source et dest
char * path_test = "tests/";
char * path_hex = "hexified/";
char * path_reg = "registres/";
//declaration des tableaux contenant le programme
instruction programme_in[MAX_PRG];
char code [MAX_PRG][100];
//tableau temporaires
char temp_pc[100];
char buffer [100];
char buffer1 [100];
char buffer2 [100];
//variable temporaire
int pc = 0;
int id = 0;
int decimal;
int fin = 0;
//variable mode console
char ligne [100];
instruction instruction_console;
int s;
//mode d'execution
int mode = 0;
//il sera interdit d'ecrire en dessous de la memoire de base, ca sera la memoire deidee a l'alocation du programme
int memoire_base;

int main(int argc,char * argv[]){

    printf("===================================\nDebut programme\n===================================");
    //on initialise les registres qui doivent l'être
    init_registre();
    //si on a que 3 arguments alors on traduit le fichier en entier
    //on met le resultat dans le fichier de destination 
    //on remplit les tableaux programme
    if (argc == 4){
	    mode = 0;
        //creation des fichiers sources et dest
        char * source = strcat(strcpy(buffer1,path_test),argv[1]);
        char * dest = strcat(strcpy(buffer,path_hex),argv[2]);
        printf("\n\nMode fichier\n\n===================================\n");
        //traduction du fichier source
        memoire_base = traduireFichier(source,dest,programme_in,code);
    //si on a 4 arguments alors on utilise le mode pas a pas
    }else if((argc == 5)&&!(strcmp("-pas",argv[4]))){
	//on set le mode pas a pas
        mode = 1;
	//creation des pointeurs
	char * source = strcat(strcpy(buffer1,path_test),argv[1]);
        char * dest = strcat(strcpy(buffer,path_hex),argv[2]);
	printf("\n\nMode pas a pas\n\n===================================\n");
	//traduction du fichier
	memoire_base = traduireFichier(source,dest,programme_in,code);
    //sinon on indique une erreur
    }else if(argc == 1){
        mode = 2;
	printf("\n\nMode console\n\n===================================\n");
	printf("\"exit\" pour quitter le mode console\n");
    //sinon on indique une erreur
    }else{
        printf("\nEcrivez le chemins du fichier source en lancement du programme ou de bons arguments\n");
		return 0;
    }
    
    //tant que l'instruction courante est active
    if(mode != 2){
		
	    printf("\n===================================\n");
	    //afficherProgrammeInstruction(programme_in);
	    printf("colonne 1 : PC\ncolonne 2 : Registre modifié\ncolonne 3 : Nouvelle valeur registre\ncolonne 4 : adresse memoire modifiée\ncolonne 5 : nouvelle valeur memoire\ncolonne 6 : instruction en cours\n");
	    printf("\n===================================\n");
	    while((pc<memoire_base)&&(!fin)){
		//on lit la valeur du programme compteur
		lireRegistre(32,temp_pc);
		//on traduit le pc en hexa pour l'affichage
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
		    //on effectue l'instruction courante
		    faireInstruction(programme_in[id]);
		    printf("%s",code[id]);
		}else{
		    //sinon c'est la fin du programme, on sort du while
		    printf("Fin du programme");
		    fin = 1;
		}
		printf("                                                                                            \n");
		//si le mode est le mode pas a pas
		if(mode == 1){
			//on attend que l'utilisateur tappe <return>
			s = getchar();
		}
		
	    }
	    //on affiche les registres
		afficherRegistres();
		char * fichier_registre = strcat(strcpy(buffer2,path_reg),argv[3]);
		stockerRegistres(fichier_registre);
	    afficherMemoire();
    }else{
	    //tant qu'on a pas eu exit dans la console
	    while(!fin){
		//on recupere la ligne
		printf(">");
		fgets(ligne,100,stdin);
		//on test si l'utilisateur a entr� exit
		if(testExit(ligne)){
			//si non on traduit la ligne
			traduireLigne(ligne,programme_in);
			//on effectue l'instruction
			faireInstruction(programme_in[0]);
			//on affiche les registres
			afficherRegistres();
		}else{
			return 0;
		}
		}
    }
    

    

    return 0;
}

