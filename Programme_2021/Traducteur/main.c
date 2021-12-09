#include "Fonction.h"




int main(int argc,char * argv[]){
    if (argc>1){
        char* source = argv[1];
        char* dest = argv[2];
        traduireFichier(source,dest);

    }else{
        printf("Ecrivez les chemins des fichiers au lancement du programme\n");
    }

    return 0;
}
