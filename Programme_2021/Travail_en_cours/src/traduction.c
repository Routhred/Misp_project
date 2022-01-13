#include "traduction.h"
#include "data.h"
#include "memory.h"
//definition des constantes
const char * delimiter = " ,$()\n\r\t";
void traduireLigne(char ligne[100],instruction programme[MAX_PRG]){
	char temp[100];
	strcpy(temp,ligne);
	instruction in;
	if(split(ligne,&in)){
			lowerToUpper(in.mots[0]);
			//On recupere le numero de ligne correspondant au code de l'instruction dans les tables de correspondance
			in.numero = findInstruction(&in);
			//on met les operandes de l'instruction dans le bon ordre
			//on traduit l'instruction en binaire
			trier_instruction(&in);
			//afficher_instruction(&in,5);
			//on regroupe toute l'instruction dans un tableau de 32 bits
			structToTab(&in);
			//afficher_instruction(&in,4);
			//on traduit le tableau en binaire
			binToHex(in.binaire,in.hexa);
			programme[0] = in;
			//printf("binaire = %s,hexa = %s",in.binaire,in.hexa);
			//on copie l'instruction dans le tableau programme instruction
			//on ecrit le tableau en hexa dans le fichier dest
			printf("\n %s	%s",in.hexa,ligne);
			//printf("Binaire : %s\n",in.binaire);
		}
	
}




//traduit tout le fichier source et le stock dans le fichier dest
int traduireFichier(char source[],char dest[],instruction programme [MAX_PRG],char code[MAX_PRG][100]){
	//declaration des variables
	FILE * fichier_source;
	FILE * fichier_dest;
	//declaration de variables locales
	char ligne[100];
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
			strcpy(code[pc],ligne);
			//on specifie que l'instruction est active
			in.actif = 1;
			lowerToUpper(in.mots[0]);
			//printf("ligne:%s\n",ligne);
			//printf("\n===================================\n");
			//On recupere le numero de ligne correspondant au code de l'instruction dans les tables de correspondance
			in.numero = findInstruction(&in);
			//on met les operandes de l'instruction dans le bon ordre
			//on traduit l'instruction en binaire
			trier_instruction(&in);
			//afficher_instruction(&in,4);
			//on regroupe toute l'instruction dans un tableau de 32 bits
			structToTab(&in);
			//afficher_instruction(&in,4);
			//on traduit le tableau en binaire
			binToHex(in.binaire,in.hexa);
			//on copie l'instruction dans le tableau programme instruction
			programme[pc] = in;
			//on ecrit le tableau en hexa dans le fichier dest
			fputs(in.hexa,fichier_dest);
			fputs("\n",fichier_dest);
			printf("\n%d	%s	%s",pc,in.hexa,code[pc]);
			//afficher_instruction(&in,4);
			ecrireMemoire(in.binaire,4*pc);
			pc ++;
				//printf("Binaire : %s\n",in.binaire);
		}
		
		
	}

	//on ferme les fichiers
	fclose(fichier_source);
	fclose(fichier_dest);
	return 4*pc;
}
int split(char ligne[], instruction *in){
	//creation des variables
	char flag;
	int result = 0;
	char cpy_ligne[100];
	char * strtoken;
	int compteur = 0;
	int i = 0;

	//sauvegarde de la ligne 
	strcpy(cpy_ligne,ligne);
	//utilisation de strtok
	strtoken = strtok(cpy_ligne,delimiter);
	//tant que notre token n'est pas null et qu'on a pas atteint un commentaire
	while((strtoken != NULL)&&(strtoken[0]!='#')){
		flag = 'a';
		result = 1;
		i = 0;
		//sauvegarde du token dans notre instruction
		while(flag){
			flag = strtoken[i];
			in->mots[compteur][i] = flag;
			i++;
		}
		//on passe au token suivant
		strtoken = strtok ( NULL, delimiter);
		
		compteur ++;

	}
	//maj du nombre d'operandes de l'instruction
	in->operandes = compteur;
	return result;
}
int findInstruction(instruction *in){
	int compteur = 0;
	while(strcmp((in->mots[0]),(table_type[compteur].nom))){
		compteur++;
	}
	return compteur;
}
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
     in->mots[i++][0]='\0';
}
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