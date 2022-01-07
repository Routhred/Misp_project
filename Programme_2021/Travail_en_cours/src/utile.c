
#include "utile.h"
#include <math.h>






void afficher_instruction(instruction *in,int nb){

  printf("\nInstruction: ");
  for (int i = 0;i<nb;i++){
    printf("%s ", in->mots[i]);
  }
  printf("\n");
}
void decToBin(char tableau[],int taille){
	int negatif = 0;

	if(tableau[0]=='-'){
		negatif = 1;
		enleverPremierChar(tableau,taille);

	}
	int temp = atoi(tableau);
	char temp_tab[34];
	for(int i = 0;i<taille;i++){
		if(temp>0){
			temp_tab[i] = (temp%2)+'0';
			temp/=2;
		}else{
			temp_tab[i] = 0 +'0';
		}
	}
	for (int i = 0 ,j = taille-1; i<taille;i++,j--){
		tableau[i] = temp_tab[j];
	}
	tableau[taille] = '\0';
	if (negatif){
		complementADeux(tableau,taille);
	}

}
void complementADeux(char tableau[],int taille){
	int carry = 1;
	for(int i = 0;i<taille;i++){
		if(tableau[i]=='0'){
			tableau[i]='1';
		}else{
			tableau[i]='0';
		}
	}
	for(int i = taille-1;i>0;i--){
		if((tableau[i] == '0')&&(carry == 1)){
			tableau[i] = '1';
			carry = 0;
		}else if((tableau[i] == '1')&&(carry == 1)){
			tableau[i] = '0';
			carry = 1;
		}
	}
}
void enleverPremierChar(char tableau[],int taille){
	for(int i = 0;i<taille;i++){
		tableau[i]=tableau[i+1];
	}
	tableau[taille]='\0';
}
void binToHex(char bin[],char hex[]){
	int value;
	static char hexa[] = "0123456789abcdef";
	for(int i = 0;i<8;i++){
		value = 0;
		value += (bin[(4*i)]-48)*8;
		value +=  (bin[(4*i)+1]-48)*4;
		value += (bin[(4*i)+2]-48)*2;
		value += (bin[(4*i)+3]-48)*1;
		hex[i] = hexa[value];
	}
	hex[8] = '\0';

}
void afficherProgrammeInstruction(instruction programme[MAX_PRG]){
	int i = 0;
	while(programme[i].binaire[0]!='Z'){
		afficher_instruction(&programme[i],4);
		i++;
	}



}
void somme(char tab1[],char tab2[],char result[]){
	char carry = '0';
	//printf("somme: %s + %s = %s",tab1,tab2,result);
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
	result[32] = '\0';


	}
}
int binToInt(char tab[]){
	size_t taille = strlen(tab);
	int puissance = 0;
	int result = 0;
	for(int i = taille-1;i>=0;i--){
		result = result + ((int)tab[i]-48)*pow(2,puissance);
		//printf("puissance: %d, result: %d\n",puissance,result);
		puissance ++;
	}
	return result;
}
void tabTo32bits(char tab[],char tab2[]){
	size_t taille = strlen(tab2);
	for(int i = 32;i>=0;i--){
		if(i>=taille){
			tab[i] = tab2[taille-(32-i)];
		}else{
			if(tab2[0] == '1'){
				tab[i] = '1';
			}else{
				tab[i] = '0';
			}
		}
		tab[33] = '\0';
		
	}
	//printf("\ntableau 32 bits: %s,taill:%d\n",tab,taille);
}
void bitwiseAnd(char dest[],char tab[],char tab2[]){
	size_t taille = strlen(tab);
	for(int i = 0;i<taille;i++){
		if((tab[i] == '1') && (tab2[i] == '1')){
			dest[i] = '1';
		}else{
			dest[i] = '0';
		}
	}
	dest[taille] = '\0';
	
}
void bitwiseOr(char dest[],char tab[],char tab2[]){
	size_t taille = strlen(tab);
	for(int i = 0;i<taille;i++){
		if((tab[i] == '1') || (tab2[i] == '1')){
			dest[i] = '1';
		}else{
			dest[i] = '0';
		}
	}
	dest[taille] = '\0';
	
}
void bitwiseXor(char dest[],char tab[],char tab2[]){
	size_t taille = strlen(tab);
	for(int i = 0;i<taille;i++){
		if(((tab[i] == '1') && (tab2[i] == '0')) || ((tab[i] == '0') && (tab2[i] == '1'))){
			dest[i] = '1';
		}else{
			dest[i] = '0';
		}
	}
	dest[taille] = '\0';
	
}
void intToBin(int nb,char tab[33]){
int negatif = 0;

	if(nb<0){
		negatif = 1;
	}
	char temp_tab[34];
	for(int i = 0; i < 32 ; i++){
		if(nb>0){
			temp_tab[i] = (nb%2)+'0';
			nb/=2;
		}else{
			temp_tab[i] = 0 +'0';
		}
	}
	for (int i = 0 ,j = 31; i<32;i++,j--){
		tab[i] = temp_tab[j];
	}
	tab[32] = '\0';
	if (negatif){
		complementADeux(tab,32);
	}
}

int testExit(char ligne[100]){

	char sortie[] = "exit";
	int result = 0;
	for (int i = 0;i<4;i++){
		if(ligne[i]!=sortie[i]){
			result = 1;
		}
	}
	return result;
}
void lowerToUpper(char ligne[100]){
	char temp;
	for (int i = 0;i<100;i++){
		temp = ligne[i];
		if(temp>=97){
			ligne[i] -= 32;
		}
	}
	
}
	


