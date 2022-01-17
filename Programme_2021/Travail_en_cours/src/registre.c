#include "registre.h"


//definition de la m�moire registre
char GBR[35][33];
//definition des noms mnemo
char mnemo[35][5] = {"x0","at","v0","v1","a0","a1","a2","a3","t0","t1","t2","t3","t4","t5","t6","t7","s0","s1","s2","s3"
                    ,"s4","s5","s6","s7","t8","t9","k0","k1","gp","sp","fp","ra","pc","lo","hi"};
		    
void init_registre(){
	//boucle pour initialiser tous les registres a 0
    for(int i = 0;i<35;i++){
	    strcpy(GBR[i],"00000000000000000000000000000000");
    }
}

void ecrireRegistre(int registre, char value[]){
	//si le registre ne fait pas partie des registres proteges
    if(verifRegistre(registre)){
	    //on copie la valeur d'entree dans le registre
        strcpy(GBR[registre], value);
    }else{
	    //sinon on affiche une erreur
        printf("Erreur, registre protégé\n");
    }
}

void lireRegistre(int registre, char value[]){
	//on copie la valeur du registre dans le tableau d'entree
    strcpy(value, GBR[registre]);

}
int verifRegistre(int registre){

    int result = 1;
	//liste des regsitres proteges
    int registre_protege[] = {0,26,27,30};
    //boucle pour voir si les registres sont proteges
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
	//lit la valeur du registre
    lireRegistre(registre, value);
	//fais la somme de 1 et du regsitre
    somme(un,value,value);
	//ecrit le resultat de la somme dans le registre
    ecrireRegistre(registre,value);
}
void stockerRegistres(char dest[]){
	//declarartion et ouverture du fichier
    FILE * fichier_registre;
    fichier_registre = fopen(dest,"w");
	//declaration des variables
    char buffer[20];
    char hexa[9];
    char value[3];
	//boucle pour lire et ecrire tous les registres
    for(int i = 0;i<35;i++){
	    //traduction en hexa du registre
        binToHex(GBR[i],hexa);
	    //calcul numero registre
        value[0] = (i/10)+48;
        value[1] = (i%10)+48;
	    //concatenation et creation de la chaine a afficher
        strcat(strcpy(buffer,"$"),value);
        strcat(buffer," :");
        strcat(buffer,hexa);
	//ecriture de la chaine dans le fichier
        fputs(buffer,fichier_registre);
        fputs("\n",fichier_registre);
    }
    //fermeture du fichier
    fclose(fichier_registre);
}
