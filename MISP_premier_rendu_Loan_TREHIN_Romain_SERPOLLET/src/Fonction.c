#include "Fonction.h"
#include "data.h"
//definition des constantes
const char * delimiter = " ,$()\n\r\t";

//traduit tout le fichier source et le stock dans le fichier dest
void traduireFichier(char source[],char dest[]){
	//declaration des variables
	FILE * fichier_source;
	FILE * fichier_dest;
	char ligne[100];
	instruction in;
	//ouverture des fichiers en mode lecture et ecriture (pour ne pas modifier le fichier source)
	fichier_source = fopen(source,"r");
	fichier_dest = fopen(dest,"w");
	//Si l'ouverture du fichier source renvoie NULL alors on affiche une problème
	if (fichier_source == NULL){
		perror("Probleme ouverture fichier");
		exit(1);
	}
	//tant que la lecture du fichier source n'est pas finie on effectue la boucle
	while(!feof(fichier_source)){
		//on recupere la ligne du fichier source
		fgets(ligne,MAX,fichier_source);
		//on split la ligne en fonction des delimiter et on stock le resultat dans une nInstruction
		//si le resultat est 1 <=> la ligne est non vide on passe a la suite
		//sinon on passe a la ligne suivante
		if(split(ligne,&in)){

			//On recupere le numero de ligne correspondant au code de l'instruction dans les tables de correspondance
			in.numero = findInstruction(&in);
			//on met les operandes de l'instruction dans le bon ordre
			//on traduit l'instruction en binaire
			trier_instruction(&in);
			//on regroupe toute l'instruction dans un tableau de 32 bits
			structToTab(&in);
			//on traduit le tableau en binaire
			binToHex(in.binaire,in.hexa);
			//on ecrit le tableau en hexa dans le fichier dest
			fputs(in.hexa,fichier_dest);
			fputs("\n",fichier_dest);
		}
	}
	//on ferme les fichiers
	fclose(fichier_source);
	fclose(fichier_dest);
}
/*************************************************************************************************************
 * 											Slit:
 * 	Permet de découper la ligne passée en parametre, on utilise les delimiter
 *
 * **************************************************************************************************************/
int split(char ligne[], instruction *in){
	char flag;
	int result = 0;
	char cpy_ligne[100];
	char * strtoken;
	int compteur = 0;
	int i = 0;
	strcpy(cpy_ligne,ligne);
	strtoken = strtok(cpy_ligne,delimiter);
	while((strtoken != NULL)&&(strtoken[0]!='#')){
		flag = 'a';
		result = 1;
		i = 0;
		while(flag != NULL){
			flag = strtoken[i];
			in->mots[compteur][i] = flag;
			i++;
		}
	
		strtoken = strtok ( NULL, delimiter);
		
		compteur ++;

	}
	in->operandes = compteur;
	return result;
}
/*************************************************************************************************************
 * 											findInstruction:
 * 	Permet de savoir a quelle ligne des tables de correspondance est l'instruction que l'on passe en parametre
 *
 * **************************************************************************************************************/
int findInstruction(instruction *in){
	int compteur = 0;
	while(strcmp((in->mots[0]),(table_type[compteur].nom))){
		compteur++;
	}
	return compteur;
}
/*************************************************************************************************************
*						Fonction de trie des instruction:
*	lorsque l'on prend une instruction depuis le fichier, les operandes ne sont pas dans le même ordre que ce que
*	le misp va comprendre, on doit donc remettre les opérandes dans le bon ordre.
*	On utilise une table de correspondance se trouvant dans data.h: table_structure
**************************************************************************************************************/
void trier_instruction(instruction *in){
	char ordre[11];
	char zero[6] = {'0','0','0','0','0','\0'};
	char special[7] = {'0','0','0','0','0','0','\0'};
	char r[6] = {'0','0','0','0','1','\0'};
	int i = 0;
	int numero = in->numero;
	strcpy(ordre,table_structure[numero].emplacement_operandes);

	instruction temp;
	while(ordre[i]!='F'){
		switch(ordre[i]){
			case 'N':
				strcpy(temp.mots[i],table_structure[numero].code);
				break;
			case 'Z':
				strcpy(temp.mots[i],zero);
				break;
			case 'R':
				strcpy(temp.mots[i],r);
				break;
			case 'S':
				strcpy(temp.mots[i],special);
				break;
			case 'J':
				strcpy(temp.mots[i],in->mots[1]);
				decToBin(temp.mots[i],26);
				break;
			case 'I':
				strcpy(temp.mots[i],in->mots[table_type[numero].operandes]);
				//printf("Immediate: %s\n",in->mots[table_type[numero].operandes]);
				decToBin(temp.mots[i],16);
				break;
			case 'O':
				strcpy(temp.mots[i],in->mots[2]);
				decToBin(temp.mots[i],16);
				break;
			case 'H':
				strcpy(temp.mots[i],zero);
				break;
			case '0':
				strcpy(temp.mots[i],in->mots[1]);
				registre_mnemo(temp.mots[i],temp.mots[i]);
				decToBin(temp.mots[i],5);
				break;
			case '1':
				strcpy(temp.mots[i],in->mots[2]);
				registre_mnemo(temp.mots[i],temp.mots[i]);
				decToBin(temp.mots[i],5);
				break;
			case '2':
				strcpy(temp.mots[i],in->mots[3]);
				registre_mnemo(temp.mots[i],temp.mots[i]);
				decToBin(temp.mots[i],5);
				break;
			default:
				printf("Fin");
				break;
		}
		i++;

	}
	for(int j = 0;j<i;j++){
		 	strcpy(in->mots[j],temp.mots[j]);
		 }
     in->mots[i++][0]="\0";
}
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
/*************************************************************************************************************
*						instruction to table
*	on prend une instruction en entrée et on ressort un tableau binaire de 32bits en concatenant les differents
*	mots binaires de l'instruction
**************************************************************************************************************/
void structToTab(instruction *in){
	int i = 0;
	int j = 0;
	int k = 0;

	while(k<32){
		while(in->mots[i][j]!='\0'){
			in->binaire[k] = in->mots[i][j];

			k++;
			j++;
		}
		i++;j=0;


	}
	in->binaire[32] = '\0';
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
//Renvoie la valeur decimale d'un registre
void registre_mnemo(char in[],char out[]){
	if((in[0]>96)&&(in[0]<123)){
		int i = 0;
		while((in[0]!=table_registre[i].mnemo[0])||(in[1]!=table_registre[i].mnemo[1])){

				printf("i = %d, registre:%s, in: %s\n",i,table_registre[i].mnemo,in);
				i++;
			}
			strcpy(out,table_registre[i].reg);
	}else{
		strcpy(out,in);
	}



}
