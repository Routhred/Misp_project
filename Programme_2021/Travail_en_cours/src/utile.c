
#include "utile.h"






void afficher_instruction(instruction *in,int nb){
  int i = 0;
  printf("\nInstruction: ");
  for (i;i<nb;i++){
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
void enleverPremierChar(char tableau[],int taille){
	int i = 0;
	for(i;i<taille;i++){
		tableau[i]=tableau[i+1];
	}
	tableau[i]='\0';
}
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
	int i = taille-1;
	int puissance = 0;
	int result = 0;
	for(i;i>=0;i--){
		result = result + ((int)tab[i]-48)*pow(2,puissance);
		//printf("puissance: %d, result: %d\n",puissance,result);
		puissance ++;
	}
	return result;
}
void tabTo32bits(char tab[],char tab2[]){
	size_t taille = strlen(tab2);
	int i = 32;
	for(i;i>=0;i--){
		if(i>=taille){
			tab[i] = tab2[taille-(32-i)];
		}else{
			tab[i] = '0';
		}
		tab[33] = '\0';
		
	}
	//printf("\ntableau 32 bits: %s,taill:%d\n",tab,taille);
}