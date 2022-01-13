#include "struct.h"
#include "utile.h"


void add(int dest,int first,int second);
void addi(int dest,int first,char immediate[]);
void and(int dest,int first,int second);
void or(int dest,int first,int second);
void xor(int dest,int first,int second);
void beq(int first, int second, char offset[]);
void bgtz(int first, char offset[]);
void blez(int first, char offset[]);
void bne(int first, int second, char offset[]);
void divid(int first, int second);
void jump(char first[]);
void jr(int first);
void lui(int registre, char immediate[]);
void lw(int rs,char offset[],int base);
void mfhr(int registre);
void mflr(int registre);
void mult(int first, int second);
void sw(int rs,char offset[],int base);
void shift(int mode,int first, int second, int nbits);
void slt(int dest,int first,int second);
void sub(int dest,int first,int second);



void faireInstruction(instruction in);