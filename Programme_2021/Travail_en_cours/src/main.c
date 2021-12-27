#include "Fonction.h"
char * path_test = "tests/";
char * path_hex = "hexified/";
char buffer[100];
char buffer1 [100];


int main(int argc,char * argv[]){
    char * source = strcat(strcpy(buffer1,path_test),argv[1]);
    char* dest = strcat(strcpy(buffer,path_hex),argv[2]);
    if (argc == 3){
        traduireFichier(source,dest,0);
    }else if(!(strcmp("-pas",argv[3]))&&(argc == 4)){
        traduireFichier(source,dest,1);
    }else{
        printf("\n%d\n",strcmp("-pas",argv[3]));
        printf("\nEcrivez le chemins du fichier source en lancement du programme ou de bons arguments\n");
    }

    return 0;
}
