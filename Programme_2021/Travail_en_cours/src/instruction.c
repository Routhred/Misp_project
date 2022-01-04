#include "instruction.h"
#include "registre.h"
#include "memory.h"

void add(int dest,int first,int second){
        //printf("\nadd\n");
    //on créer des tableaux temporaires de 32 bits
    char value1[33];
    char value2[33];
    char value_dest[33];
    char hexa[9];
    //lecture du registre de la premiere operande
    lireRegistre(first, value1);
        //printf("Valeur du registre %d : %s\n",first,value1);
    //lecture du registre de la deuxieme operande
    lireRegistre(second, value2);
        //printf("Valeur du registre %d : %s\n",second,value2);
    //calcul de la valeur du registre de destination
    somme(value1,value2,value_dest);
        //printf("Valeur du registre %d : %s\n",dest,value_dest);
    //ecriture du tableau temporaire dans le registre de destination
    ecrireRegistre(dest,value_dest);
    binToHex(value_dest,hexa);
    printf("%d\t%s\tX\tX\t\t",dest,hexa);

}
void addi(int dest,int first,char immediate[]){
        //printf("\naddi\n");
    char value1[33];
    char im[33];
    char value_dest[33];
    char hexa[9];
    lireRegistre(first, value1);
        //printf("Valeur du registre first %d : %s\n",first,value1);
    tabTo32bits(im,immediate);
    somme(value1,im,value_dest);
        //printf("Valeur du registre second %d : %s\n",dest,value_dest);
    ecrireRegistre(dest,value_dest);
    binToHex(value_dest,hexa);
    printf("%d\t%s\tX\tX\t\t",dest,hexa);
}
void and(int dest,int first,int second){
    char value1[33];
    char value2[33];
    char value_dest[33];
    char hexa[9];
    //lecture du registre de la premiere operande
    lireRegistre(first, value1);
        //printf("Valeur du registre %d : %s\n",first,value1);
    //lecture du registre de la deuxieme operande
    lireRegistre(second, value2);
        //printf("Valeur du registre %d : %s\n",second,value2);
    //calcul de la valeur du registre de destination
    bitwiseAnd(value_dest,value1,value2);
        //printf("Valeur du registre %d : %s\n",dest,value_dest);
    //ecriture du tableau temporaire dans le registre de destination
    ecrireRegistre(dest,value_dest);
    binToHex(value_dest,hexa);
    printf("%d\t%s\tX\tX\t\t",dest,hexa);
}
void or(int dest,int first,int second){
    char value1[33];
    char value2[33];
    char value_dest[33];
    char hexa[9];
    //lecture du registre de la premiere operande
    lireRegistre(first, value1);
        //printf("Valeur du registre %d : %s\n",first,value1);
    //lecture du registre de la deuxieme operande
    lireRegistre(second, value2);
        //printf("Valeur du registre %d : %s\n",second,value2);
    //calcul de la valeur du registre de destination
    bitwiseOr(value_dest,value1,value2);
        //printf("Valeur du registre %d : %s\n",dest,value_dest);
    //ecriture du tableau temporaire dans le registre de destination
    ecrireRegistre(dest,value_dest);
    binToHex(value_dest,hexa);
    printf("%d\t%s\tX\tX\t\t",dest,hexa);
}
void xor(int dest,int first,int second){
    char value1[33];
    char value2[33];
    char value_dest[33];
    char hexa[9];
    //lecture du registre de la premiere operande
    lireRegistre(first, value1);
        //printf("Valeur du registre %d : %s\n",first,value1);
    //lecture du registre de la deuxieme operande
    lireRegistre(second, value2);
        //printf("Valeur du registre %d : %s\n",second,value2);
    //calcul de la valeur du registre de destination
    bitwiseXor(value_dest,value1,value2);
        //printf("Valeur du registre %d : %s\n",dest,value_dest);
    //ecriture du tableau temporaire dans le registre de destination
    ecrireRegistre(dest,value_dest);
    binToHex(value_dest,hexa);
    printf("%d\t%s\tX\tX\t\t",dest,hexa);
}
void beq(int first, int second, char offset[]){
    char value1[33];
    char value2[33];
    char offset32[33];
    char hexa[9];
    //lecture du registre de la premiere operande
    lireRegistre(first, value1);
        //printf("Valeur du registre %d : %s\n",first,value1);
    //lecture du registre de la deuxieme operande
    lireRegistre(second, value2);
        //printf("Valeur du registre %d : %s\n",second,value2);
    if(!strcmp(value1,value2)){
        tabTo32bits(offset32,offset);
        ecrireRegistre(32,offset32);
        binToHex(offset32,hexa);
        printf("%d\t%s\tX\tX\t\t",32,hexa);
    }else{
        printf("X\tX\t\tX\tX\t\t");
    }
}
void bgtz(int first, char offset[]){
    char offset32[33];
    char hexa[9];
    char value1[33];
    char zero[33] = {"00000000000000000000000000000000"};
    //lecture du registre de la premiere operande
    lireRegistre(first, value1);
        //printf("Valeur du registre %d : %s\n",first,value1);
    if((strcmp(value1,zero))&&(value1[0]=='0')){
        tabTo32bits(offset32,offset);
        ecrireRegistre(32,offset32);
        binToHex(offset32,hexa);
        printf("%d\t%s\tX\tX\t",32,hexa);
    }else{
        printf("X\tX\t\tX\tX\t");
    }
}
void blez(int first, char offset[]){
    char offset32[33];
    char hexa[9];
    char value1[33];
    char zero[33] = {"00000000000000000000000000000000"};
    //lecture du registre de la premiere operande
    lireRegistre(first, value1);
        //printf("Valeur du registre %d : %s\n",first,value1);
    if((!strcmp(value1,zero))||(value1[0]=='1')){
        tabTo32bits(offset32,offset);
        ecrireRegistre(32,offset32);
        binToHex(offset32,hexa);
        printf("%d\t%s\tX\tX\t\t",32,hexa);
    }else{
        printf("X\tX\t\tX\tX\t\t");
    }
}
void bne(int first, int second, char offset[]){
    char value1[33];
    char value2[33];
    char offset32[33];
    char hexa[9];
    //lecture du registre de la premiere operande
    lireRegistre(first, value1);
        //printf("Valeur du registre %d : %s\n",first,value1);
    //lecture du registre de la deuxieme operande
    lireRegistre(second, value2);
        //printf("Valeur du registre %d : %s\n",second,value2);
    if(strcmp(value1,value2)){
        tabTo32bits(offset32,offset);
        ecrireRegistre(32,offset32);
        binToHex(offset32,hexa);
        printf("%d\t%s\tX\tX\t\t",32,hexa);
    }else{
        printf("X\tX\t\tX\tX\t\t");
    }
}
void divid(int first, int second){
    //on créer des tableaux temporaires de 32 bits
    char value1[33];
    int valeur1;
    char value2[33];
    int valeur2;
    int quotient;
    int reste;
    char value_dest[33];
    char hexa_q[9];
    char hexa_r[9];
    //lecture du registre de la premiere operande
    lireRegistre(first, value1);
        //printf("Valeur du registre %d : %s\n",first,value1);
    //lecture du registre de la deuxieme operande
    lireRegistre(second, value2);
        //on met les valeurs en decimale
    valeur1 = binToInt(value1);
    valeur2 = binToInt(value2);
    if(valeur2){
	//on fait les calculs sur les valeurs en decimal
        quotient = valeur1 / valeur2;
        reste = valeur1 % valeur2;
	    //on traduit les valeurs en binaire 
        intToBin(quotient,value1);
        intToBin(reste,value2);
	    //on ecrit les valeurs dans les registres
        ecrireRegistre(33,value1);
        ecrireRegistre(34,value2);
	    //on traduit les valeurs en hexa pour les afficher
        binToHex(value1,hexa_q);
        binToHex(value2,hexa_r);
        printf("%d\t%s\tX\tX\t\n\t\t%d\t%s\tX\tX\t\t",33,hexa_q,34,hexa_r);
    }else{
        printf("Division par 0");
    }
}
void jump(char target[27]){
	char hexa[9];
	char temp[33];
	tabTo32bits(temp,target);
	binToHex(temp,hexa);
	ecrireRegistre(32,temp);
	printf("32\t%s\tX\tX\t\t",hexa);
}
void jal(char target[27]){
	char valeur_pc[33];
	char hexa[9];
	jump(target);
	printf("\n");
	lireRegistre(32,valeur_pc);
	ecrireRegistre(31,valeur_pc);
	inc(31);
	inc(31);
	inc(31);
	inc(31);
	binToHex(valeur_pc,hexa);
	printf("\t\t31\t%s\tX\tX\t\t",hexa);
	
}
void jr(int first){
	char value[33];
	char hexa [9];
	lireRegistre(first,value);
	ecrireRegistre(32,value);
	binToHex(value,hexa);
	printf("32\t%s\tX\t\tX\t\t",hexa);
	
}
void sw(int rs,char offset[17],int base){
	char int_base[33];
	char adresse[33];
	char offset_32bits[33];
	char valeur[33];
	char hexa[9];
	int adresse_int;
	lireRegistre(rs,valeur);
	tabTo32bits(offset_32bits,offset);
	lireRegistre(base,int_base);
	somme(int_base,offset_32bits,adresse);
	adresse_int = binToInt(adresse);
	ecrireMemoire(valeur,adresse_int);
	binToHex(valeur,hexa);
	printf("X\tX\t\t%d\t%s\t",adresse_int,hexa);
	
	
}
void faireInstruction(instruction in){

	switch(in.numero){
		case 0:
		    add(binToInt(in.mots[3]),binToInt(in.mots[1]),binToInt(in.mots[2]));
		    break;
		case 1:
		    addi(binToInt(in.mots[2]),binToInt(in.mots[1]),in.mots[3]);
		    break;
		case 2:
		    and(binToInt(in.mots[3]),binToInt(in.mots[1]),binToInt(in.mots[2]));
		    break;
		case 3:
		    beq(binToInt(in.mots[1]),binToInt(in.mots[2]),in.mots[3]);
		    break;
		case 4:
		    bgtz(binToInt(in.mots[1]),in.mots[3]);
		    break;
		case 5:
		    blez(binToInt(in.mots[1]),in.mots[3]);
		    break;
		case 6:
		    bne(binToInt(in.mots[1]),binToInt(in.mots[2]),in.mots[3]);
		    break;
		case 7:
		    divid(binToInt(in.mots[1]),binToInt(in.mots[2]));
		    break;
		case 8:
			jump(in.mots[1]);
			break;
		case 9:
			jal(in.mots[1]);
			break;
		case 10:
			jr(binToInt(in.mots[1]));
			break;
		case 16:
			break;
		case 17:
		    or(binToInt(in.mots[3]),binToInt(in.mots[1]),binToInt(in.mots[2]));
		    break;
		case 23:
			sw(binToInt(in.mots[2]),in.mots[3],binToInt(in.mots[1]));
			break;
		case 25:
		    xor(binToInt(in.mots[3]),binToInt(in.mots[1]),binToInt(in.mots[2]));
		    break;
		default:
		    printf("Pas d'instruction dispoonible\t");
		    break;


	    }
}
