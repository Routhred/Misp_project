#include "struct.h"
#include "utile.h"

//GBR[dest] = GBR[first] + GBR[second]
void add(int dest,int first,int second);
//GBR[dest] = GBR[first] + immediate
void addi(int dest,int first,char immediate[]);
//GBR[dest] = GBR[first] && GBR[second]
void and(int dest,int first,int second);
//GBR[dest] = GBR[first] || GBR[second]
void or(int dest,int first,int second);
//GBR[dest] = GBR[first] xor GBR[second]
void xor(int dest,int first,int second);
//if (GBR[first] == GBR[second]) then pc += offset else nothing
void beq(int first, int second, char offset[]);
//if (GBR[first] > 0) then pc += offset else nothing
void bgtz(int first, char offset[]);
//if (GBR[first] <= 0) then pc += offset else nothing
void blez(int first, char offset[]);
//if (GBR[first] != GBR[second]) then pc += offset else nothing
void bne(int first, int second, char offset[]);
//HI = qutient(GBR[first]/GBR[second]);  LO = reste(GBR[first]/GBR[second])
void divid(int first, int second);
//pc = first
void jump(char first[]);
//GBR[31] = PC;  PC = target
void jal(char target[]);
//PC = GBR[first]
void jr(int first);
//GBR[registre] = concatenation(immediate,"0000000000000000")
void lui(int registre, char immediate[]);
//GBR[registre] = memoire[offset + GBR[base]]
void lw(int rs,char offset[],int base);
//GBR[registre] = GBR[HI]
void mfhr(int registre);
//GBR[registre] = GBR[LO]
void mflr(int registre);
//HI = bitsdepoidsfort(GBR[first]*GBR[second]) ; LO = bitsdepoidsfort(GBR[first]*GBR[second])
void mult(int first, int second);
//memoire[offset + GBR[base]] = GBR[registre]
void sw(int rs,char offset[],int base);
//decale les bits dans un sens ou dans l'autre en fonction du mode
//mode 1 : rotation
//mode 2 : shift left
//mode 3 : shift right
void shift(int mode,int first, int second, int nbits);
//if(GBR[first]<GBR[second]) then GBR[dest] = 1 else GBR[dest] = 0;
void slt(int dest,int first,int second);
//GBR[dest] = GBR[first] - GBR[second]
void sub(int dest,int first,int second);



void faireInstruction(instruction in);