#include "Fonction.h"
#include "data.h"
//definition des constantes
const char * delimiter = " ,$()\n\r\t";
void traduireLigne(char source[],char dest[],int nb){
	FILE * fichier_source;
	FILE * fichier_dest;
	char ligne[100];
	instruction in;
	int i = 0;
	//ouverture des fichiers en mode lecture et ecriture (pour ne pas modifier le fichier source)
	fichier_source = fopen(source,"r");
	fichier_dest = fopen(dest,"w");
	//Si l'ouverture du fichier source renvoie NULL alors on affiche une problème
	if (fichier_source == NULL){
		perror("Probleme ouverture fichier");
		exit(1);
	}

	while((!feof(fichier_source))&&(i<=nb)){
		fgets(ligne,MAX,fichier_source);
		i++;

	}
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
			printf("ligne %d contient: %s%s et vaut: %s\n",i,in.mots[0],in.mots[1],in.hexa);
			fputs(in.hexa,fichier_dest);
			fputs("\n",fichier_dest);
		}

}
//traduit tout le fichier source et le stock dans le fichier dest
void traduireFichier(char source[],char dest[],int mode,char memoire[MAX_PRG][33]){
	//declaration des variables
	FILE * fichier_source;
	FILE * fichier_dest;
	char ligne[100];
	char temp;
	instruction in;
	int pc = 0;
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
			//printf("\n===================================\n");
			//On recupere le numero de ligne correspondant au code de l'instruction dans les tables de correspondance
			in.numero = findInstruction(&in);
			//on met les operandes de l'instruction dans le bon ordre
			//on traduit l'instruction en binaire
			trier_instruction(&in);
			//on regroupe toute l'instruction dans un tableau de 32 bits
			structToTab(&in);
			//afficher_instruction(&in,4);
			//on traduit le tableau en binaire
			binToHex(in.binaire,in.hexa);
			//on copie le binaire dans la memoire programme
			strcpy(memoire[pc], in.binaire);
			//on ecrit le tableau en hexa dans le fichier dest
			fputs(in.hexa,fichier_dest);
			fputs("\n",fichier_dest);
			pc ++;
			//printf("Hexa : %s",in.hexa);
		}
		if(mode){
			printf("\n//attendre appuis sur touche entree\n");
			//scanf("%c",&temp);
		}
		
		
	}
	//on ferme les fichiers et on marque l'arret du programme
	strcpy(memoire[pc],"Z00000000000000000000000000000000");
	
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

//Renvoie la valeur decimale d'un registre
void registre_mnemo(char in[],char out[]){
	if((in[0]>96)&&(in[0]<123)){
		int i = 0;
		while((in[0]!=table_registre[i].mnemo[0])||(in[1]!=table_registre[i].mnemo[1])){

				//printf("i = %d, registre:%s, in: %s\n",i,table_registre[i].mnemo,in);
				i++;
			}
			strcpy(out,table_registre[i].reg);
	}else{
		strcpy(out,in);
	}



}
