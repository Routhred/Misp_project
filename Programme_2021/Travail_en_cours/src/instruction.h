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
void jump(char first[32]);
void jr(int first);
void sw(int rs,char offset[17],int base);
void lui(int registre, char immediate[]);
void lw(int rs,char offset[17],int base);

void faireInstruction(instruction in);