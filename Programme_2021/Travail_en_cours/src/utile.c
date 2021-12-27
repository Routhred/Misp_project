
#include "utile.h"






//Fonction qui sert a afficher les nb premiers élements d'une instruction passée en parametre
void afficher_instruction(instruction *in,int nb){
  int i = 0;
  printf("\nInstruction: ");
  for (i;i<nb;i++){
    printf("%s ", in->mots[i]);
  }
  printf("\n");
}
/*************************************************************************************************************
*						Decimal to binaire:
*	on prend un tableau en entrée avec une taille de retour voulu
**************************************************************************************************************/
void decToBin(char tableau[],int taille){
	int negatif = 0;

	if(tableau[0]=='-'){
		negatif = 1;
		enleverPremierChar(tableau,taille);

	}
	int temp = atoi(tableau);
	int i = 0;
	char temp_tab[taille+1];
	for(i;i<taille;i++){
		if(temp>0){
			temp_tab[i] = (temp%2)+'0';
			temp/=2;
		}else{
			temp_tab[i] = 0 +'0';
		}
	}
	int j = 0; i =0;
	for (i ,j = taille-1; i<taille;i++,j--){
		tableau[i] = temp_tab[j];
	}
	tableau[i] = '\0';
	if (negatif){
		complementADeux(tableau,taille);
	}

}
/*************************************************************************************************************
*						complementADeux
*	Prend un tableau de char en parametre et la taille du tableau de retour
* Modifie le tableau d'entree en mettant l'opposé de la valeur du tableau (binaire) pour avoir l'inverse en
*complement a deux
**************************************************************************************************************/
void complementADeux(char tableau[],int taille){
	int i;
	int carry = 1;
	for(i = 0;i<taille;i++){
		if(tableau[i]=='0'){
			tableau[i]='1';
		}else{
			tableau[i]='0';
		}
	}
	for(i=taille-1;i>0;i--){
		if((tableau[i] == '0')&&(carry == 1)){
			tableau[i] = '1';
			carry = 0;
		}else if((tableau[i] == '1')&&(carry == 1)){
			tableau[i] = '0';
			carry = 1;
		}
	}
}
// enleve le premier caractere d'un tableau de taille taille
void enleverPremierChar(char tableau[],int taille){
	int i = 0;
	for(i;i<taille;i++){
		tableau[i]=tableau[i+1];
	}
	tableau[i]='\0';
}

//Traduit le tableau bin de 32 bits en hexadécimal et le met dans le tableau hex
void binToHex(char bin[],char hex[]){
	int i = 0;
	int value;
	static char hexa[] = "0123456789abcdef";
	for(i = 0;i<8;i++){
		value = 0;
		value += (bin[(4*i)]-48)*8;
		value +=  (bin[(4*i)+1]-48)*4;
		value += (bin[(4*i)+2]-48)*2;
		value += (bin[(4*i)+3]-48)*1;
		hex[i] = hexa[value];
	}
	hex[8] = '\0';

}
//affiche le programme en binaire
void affiche_programme_binaire(char programme[MAX_PRG][33]){
    int i = 0;
    while(programme[i][0]!='Z'){
        printf("__%s__\n",programme[i]);
        i++;
    }
    //printf("Fin affichage programme\n");
    
}
//somme de 2 tableaux de 32 bits
void somme(char tab1[],char tab2[],char result[]){
	char carry = '0';
	for(int i = 31;i>=0;i--){
		if( (tab1[i] == '1') && (tab2[i] == '1') && (carry == '1') ){
			result[i] = '1';
			carry = '1';
		}else if( (tab1[i] == '1') && (tab2[i] == '1') && (carry == '0') ){
			result[i] = '0';
			carry = '1';
		}else if( ((tab1[i] == '1') ^ (tab2[i] == '1')) && (carry == '1') ){
			result[i] = '0';
			carry = '1';
		}else if( ((tab1[i] == '1') ^ (tab2[i] == '1')) && (carry == '0') ){
			result[i] = '1';
			carry = '0';
		
		}else if( (tab1[i] == '0') && (tab2[i] == '0') && (carry == '1') ){
			result[i] = '1';
			carry = '0';
		}else{
			result[i] = '0';
			carry = '0';
		}



	}
}