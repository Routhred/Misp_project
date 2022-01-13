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
    tabTo32bits(im,immediate,1);
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
        tabTo32bits(offset32,offset,1);
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
        tabTo32bits(offset32,offset,1);
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
        tabTo32bits(offset32,offset,1);
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
        tabTo32bits(offset32,offset,1);
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
void jump(char target[]){
	char hexa[9];
	char temp[33];
	tabTo32bits(temp,target,1);
	binToHex(temp,hexa);
	ecrireRegistre(32,temp);
	printf("32\t%s\tX\tX\t\t",hexa);
}
void jal(char target[]){
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

void lui(int registre, char immediate[]){
	char value[33];
	char hexa [9];
	tabTo32bits(value,immediate,0);
	ecrireRegistre(registre,value);
	binToHex(value,hexa);
	printf("%d\t%s\tX\t\tX\t\t",registre,hexa);
	
	
}
void lw(int rs,char offset[],int base){
	char int_base[33];
	char adresse[33];
	char offset_32bits[33];
	char valeur[33];
	char hexa[9];
	int adresse_int;
	tabTo32bits(offset_32bits,offset,1);
	lireRegistre(base,int_base);
	somme(int_base,offset_32bits,adresse);
	adresse_int = binToInt(adresse);
	lireMemoire(valeur,adresse_int);
	printf("valeur = %s\n",valeur);
	ecrireRegistre(rs,valeur);
	binToHex(valeur,hexa);
	printf("%d\t%s\tX\t\tX\t\t",rs,hexa);
	
}
void mfhr(int registre){
	char value[33];
	char hexa[9];
	lireRegistre(34,value);
	ecrireRegistre(registre,value);
	binToHex(value,hexa);
	printf("%d\t%s\tX\t\tX\t\t",registre,hexa);
	
}
void mflr(int registre){
	char value[33];
	char hexa[9];
	lireRegistre(33,value);
	ecrireRegistre(registre,value);
	binToHex(value,hexa);
	printf("%d\t%s\tX\t\tX\t\t",registre,hexa);
	
}
void mult(int first, int second){
	char value1[33];
	char value2[33];
	char resultat_binaire[65];
	char resultat_binaire1[33];
	char resultat_binaire2[33];
	char hexa_1[9];
	char hexa_2[9];

	int valeur1;
	int valeur2;
	int resultat_decimal;
	lireRegistre(first,value1);
	lireRegistre(second,value2);
	valeur1 = binToInt(value1);
	valeur2 = binToInt(value2);
	resultat_decimal = valeur1*valeur2;
	intToBin(resultat_decimal,resultat_binaire);
	for(int i = 0;i<32;i++){
		resultat_binaire1[i] = resultat_binaire[i];
		resultat_binaire2[i]= resultat_binaire[i+32];
	}
	resultat_binaire1[32] = '\0'; 
	resultat_binaire2[32] = '\0'; 
	ecrireRegistre(33,resultat_binaire1);
        ecrireRegistre(34,resultat_binaire2);
	binToHex(resultat_binaire1,hexa_1);
        binToHex(resultat_binaire2,hexa_2);
	printf("%d\t%s\tX\tX\t\n\t\t%d\t%s\tX\tX\t\t",33,hexa_1,34,hexa_2);
	
}
void sw(int rs,char offset[],int base){
	char int_base[33];
	char adresse[33];
	char offset_32bits[33];
	char valeur[33];
	char hexa[9];
	int adresse_int;
	lireRegistre(rs,valeur);
	tabTo32bits(offset_32bits,offset,1);
	lireRegistre(base,int_base);
	somme(int_base,offset_32bits,adresse);
	adresse_int = binToInt(adresse);
	ecrireMemoire(valeur,adresse_int);
	binToHex(valeur,hexa);
	printf("X\tX\t\t%d\t%s\t",adresse_int,hexa);
	
	
}

void shift(int mode,int first, int second, int nbits){
    char registre_1[33];
    char hexa[9];


    lireRegistre(first, registre_1);
    rotate(mode,nbits,registre_1);
    ecrireRegistre(second,registre_1);
    binToHex(registre_1,hexa);
    printf("X\tX\t\t%d\t%s\t",second,hexa);

}
void slt(int dest,int first,int second){
    char registre_1[33];
    char registre_2[33];
    char hexa[9];
    char true [] = "00000000000000000000000000000001";
    char false [] = "00000000000000000000000000000000";
    int valeur1;
    int valeur2;
    lireRegistre(first, registre_1);
    lireRegistre(second, registre_2);
    valeur1 = binToInt(registre_1);
    valeur2 = binToInt(registre_2);
    if(valeur1<valeur2){
        ecrireRegistre(dest,true);
        binToHex(true,hexa);
        printf("%d\t%s\tX\t\tX\t\t",dest,hexa);
    }else{
        ecrireRegistre(dest,false);
        binToHex(false,hexa);
        printf("%d\t%s\tX\t\tX\t\t",dest,hexa);
    }


}
void sub(int dest,int first,int second){
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
    complementADeux(value2,32);
        //printf("Valeur du registre %d : %s\n",second,value2);
    //calcul de la valeur du registre de destination
    somme(value1,value2,value_dest);
        //printf("Valeur du registre %d : %s\n",dest,value_dest);
    //ecriture du tableau temporaire dans le registre de destination
    ecrireRegistre(dest,value_dest);
    binToHex(value_dest,hexa);
    printf("%d\t%s\tX\tX\t\t",dest,hexa);

}
void syscall(){
    printf("\nInstruction non implémentée\n");
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
		case 11:
			lui(binToInt(in.mots[2]),in.mots[3]);
			break;
		case 12:
			lw(binToInt(in.mots[2]),in.mots[3],binToInt(in.mots[1]));
			break;
		case 13:
			mfhr(binToInt(in.mots[3]));
			break;
		case 14:
			mflr(binToInt(in.mots[3]));
			break;
		case 15:
			mult(binToInt(in.mots[1]),binToInt(in.mots[2]));
			break;
		case 16:
			break;
		case 17:
			or(binToInt(in.mots[3]),binToInt(in.mots[1]),binToInt(in.mots[2]));
			break;
        case 18:
            shift(1,binToInt(in.mots[3]),binToInt(in.mots[2]),binToInt(in.mots[4]));
            break;
        case 19:
            shift(2,binToInt(in.mots[3]),binToInt(in.mots[2]),binToInt(in.mots[4]));
            break;
        case 20:
            slt(binToInt(in.mots[3]),binToInt(in.mots[1]),binToInt(in.mots[2]));
            break;
        case 21: 
            shift(3,binToInt(in.mots[3]),binToInt(in.mots[2]),binToInt(in.mots[4]));
            break;
        case 22:
            sub(binToInt(in.mots[3]),binToInt(in.mots[1]),binToInt(in.mots[2]));
            break;
		case 23:
			sw(binToInt(in.mots[2]),in.mots[3],binToInt(in.mots[1]));
			break;
        case 24:
            syscall();
            break;
		case 25:
		    xor(binToInt(in.mots[3]),binToInt(in.mots[1]),binToInt(in.mots[2]));
		    break;
		default:
		    printf("Pas d'instruction dispoonible\t");
		    break;


	    }
}
