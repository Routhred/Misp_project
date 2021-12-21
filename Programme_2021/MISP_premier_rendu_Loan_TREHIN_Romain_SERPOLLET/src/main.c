#include "Fonction.h"
char * path_test = "tests/";
char * path_hex = "hexified/";
char buffer[100];
char buffer1 [100];


int main(int argc,char * argv[]){
    if (argc>1){
        char* source = strcat(strcpy(buffer1,path_test),argv[1]);
        if (!argv[2]){
            char* dest = strcat(strcpy(buffer,path_hex),argv[1]);
            traduireFichier(source,dest);
        }else{
            char* dest = strcat(strcpy(buffer,path_hex),argv[2]);
            traduireFichier(source,dest);
        }
        

    }else{
        printf("Ecrivez le chemins du fichier source en lancement du programme\n");
    }

    return 0;
}
