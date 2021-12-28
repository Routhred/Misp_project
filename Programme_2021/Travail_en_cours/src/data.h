#ifndef __DATA_H__
#define __DATA_H__ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
const type_instruction table_type[26] = {{.nom = "ADD",.type = "R",.operandes = 3},
								{.nom = "ADDI",.type = "I",.operandes = 3},
								{.nom = "AND",.type = "R",.operandes = 3},
								{.nom = "BEQ",.type = "I",.operandes = 3},
								{.nom = "BGTZ",.type = "I",.operandes = 2},
								{.nom = "BLEZ",.type = "I",.operandes = 2},
								{.nom = "BNE",.type = "I",.operandes = 3},
								{.nom = "DIV",.type = "R",.operandes = 2},
								{.nom = "J",.type = "J",.operandes = 1},
								{.nom = "JAL",.type = "J",.operandes = 1},
								{.nom = "JR",.type = "R",.operandes = 1},
								{.nom = "LUI",.type = "I",.operandes = 2},
								{.nom = "LW",.type = "I",.operandes = 2},
								{.nom = "MFHI",.type = "R",.operandes =1},
								{.nom = "MFLO",.type = "R",.operandes = 1},
								{.nom = "MULT",.type = "R",.operandes = 2},
								{.nom = "NOP",.type = "R",.operandes = 0},
								{.nom = "OR",.type = "R",.operandes = 3 },
								{.nom = "ROTR",.type = "R",.operandes = 3},
								{.nom = "SLL",.type = "R",.operandes = 3},
								{.nom = "SLT",.type = "R",.operandes = 3},
								{.nom = "SRL",.type = "R",.operandes = 3},
								{.nom = "SUB",.type = "R",.operandes = 3},
								{.nom = "SW",.type = "I",.operandes = 2},
								{.nom = "SYSCALL",.type = "S",.operandes = 0},
								{.nom = "XOR",.type = "R",.operandes = 3}
};
const nom_registre table_registre[32] = {{.mnemo ="zero",.reg="0",.bin={0,0,0,0,0}},
								{.mnemo ="at",.reg="1",.bin={0,0,0,0,1}},
								{.mnemo ="v0",.reg="2",.bin={0,0,0,1,0}},
								{.mnemo ="v1",.reg="3",.bin={0,0,0,1,1}},
								{.mnemo ="a0",.reg="4",.bin={0,0,1,0,0}},
								{.mnemo ="a1",.reg="5",.bin={0,0,1,0,1}},
								{.mnemo ="a2",.reg="6",.bin={0,0,1,1,0}},
								{.mnemo ="a3",.reg="7",.bin={0,0,1,1,1}},
								{.mnemo ="t0",.reg="8",.bin={0,1,0,0,0}},
								{.mnemo ="t1",.reg="9",.bin={0,1,0,0,1}},
								{.mnemo ="t2",.reg="10",.bin={0,1,0,1,0}},
								{.mnemo ="t3",.reg="11",.bin={0,1,0,1,1}},
								{.mnemo ="t4",.reg="12",.bin={0,1,1,0,0}},
								{.mnemo ="t5",.reg="13",.bin={0,1,1,0,1}},
								{.mnemo ="t6",.reg="14",.bin={0,1,1,1,0}},
								{.mnemo ="t7",.reg="15",.bin={0,1,1,1,1}},
								{.mnemo ="s0",.reg="16",.bin={1,0,0,0,0}},
								{.mnemo ="s1",.reg="17",.bin={1,0,0,0,1}},
								{.mnemo ="s2",.reg="18",.bin={1,0,0,1,0}},
								{.mnemo ="s3",.reg="19",.bin={1,0,0,1,1}},
								{.mnemo ="s4",.reg="20",.bin={1,0,1,0,0}},
								{.mnemo ="s5",.reg="21",.bin={1,0,1,0,1}},
								{.mnemo ="s6",.reg="22",.bin={1,0,1,1,0}},
								{.mnemo ="s7",.reg="23",.bin={1,0,1,1,1}},
								{.mnemo ="t8",.reg="24",.bin={1,1,0,0,0}},
								{.mnemo ="t9",.reg="25",.bin={1,1,0,0,1}},
								{.mnemo ="k0",.reg="26",.bin={1,1,0,1,0}},
								{.mnemo ="k1",.reg="27",.bin={1,1,0,1,1}},
								{.mnemo ="gp",.reg="28",.bin={1,1,1,0,0}},
								{.mnemo ="sp",.reg="29",.bin={1,1,1,0,1}},
								{.mnemo ="fp",.reg="30",.bin={1,1,1,1,0}},
								{.mnemo ="ra",.reg="31",.bin={1,1,1,1,1}}
};
const structure_instruction table_structure[26] = {{.nom = "ADD",	.emplacement_operandes = {'S','1','2','0','Z','N','F'},	.code = {'1','0','0','0','0','0'}},
												{.nom = "ADDI",		.emplacement_operandes = {'N','1','0','I','F'},			.code = {'0','0','1','0','0','0'}},
												{.nom = "AND",		.emplacement_operandes = {'S','1','2','0','Z','N','F'},	.code = {'1','0','0','1','0','0'}},
												{.nom = "BEQ",		.emplacement_operandes = {'N','0','1','I','F'},			.code = {'0','0','0','1','0','0'}},
												{.nom = "BGTZ",		.emplacement_operandes = {'N','0','Z','I','F'},			.code = {'0','0','0','1','1','1'}},
												{.nom = "BLEZ",		.emplacement_operandes = {'N','0','Z','I','F'},			.code = {'0','0','0','1','1','0'}},
												{.nom = "BNE",		.emplacement_operandes = {'N','0','Z','I','F'},			.code = {'0','0','0','1','0','1'}},
												{.nom = "DIV",		.emplacement_operandes = {'S','0','1','Z','Z','N','F'},	.code = {'0','1','1','0','1','0'}},
												{.nom = "J",		.emplacement_operandes = {'N','J','F'},					.code = {'0','0','0','0','1','0'}},

				{.nom = "JAL",		.emplacement_operandes = {'N','J','F'},					.code = {'0','0','0','0','1','1'}},
												{.nom = "JR",		.emplacement_operandes = {'S','0','Z','Z','H','N','F'},	.code = {'0','0','1','0','0','0'}},
												{.nom = "LUI",		.emplacement_operandes = {'N','Z','0','1','I','F'},		.code = {'0','0','1','1','1','1'}},
												{.nom = "LW",		.emplacement_operandes = {'N','2','0','O','F'},			.code = {'1','0','0','0','1','1'}},
												{.nom = "MFHI",		.emplacement_operandes = {'S','Z','Z','0','Z','N','F'}, .code = {'0','1','0','0','0','0'}},
												{.nom = "MFLO",		.emplacement_operandes = {'S','Z','Z','0','Z','N','F'},	.code = {'0','1','0','0','1','0'}},
												{.nom = "MULT",		.emplacement_operandes = {'S','0','1','Z','Z','N','F'},	.code = {'0','1','1','0','0','0'}},
												{.nom = "NOP",		.emplacement_operandes = {'S','Z','Z','Z','Z','N','F'},	.code = {'0','0','0','0','0','0'}},
												{.nom = "OR",		.emplacement_operandes = {'S','1','2','0','Z','N','F'},	.code = {'1','0','0','1','0','1'}},
												{.nom = "ROTR",		.emplacement_operandes = {'S','R','1','0','2','N','F'},	.code = {'0','0','0','0','1','0'}},
												{.nom = "SLL",		.emplacement_operandes = {'S','Z','1','0','2','N','F'},	.code = {'0','0','0','0','0','0'}},
												{.nom = "SLT",		.emplacement_operandes = {'S','1','2','0','Z','N','F'},	.code = {'1','0','1','0','1','0'}},
												{.nom = "SRL",		.emplacement_operandes = {'S','Z','1','0','2','N','F'},	.code = {'0','0','0','0','1','0'}},
												{.nom = "SUB",		.emplacement_operandes = {'S','1','2','0','Z','N','F'},	.code = {'1','0','0','0','1','0'}},
												{.nom = "SW",		.emplacement_operandes = {'N','2','0','O','F'},			.code = {'1','0','1','0','1','1'}},
												{.nom = "SYSCALL",	.emplacement_operandes = {'S','Z','Z','Z','Z','N','F'},	.code = {'0','0','1','1','0','0'}},
												{.nom = "XOR",		.emplacement_operandes = {'S','1','2','0','Z','N','F'},	.code = {'1','0','0','1','1','0'}}};



/*
S : Special : 000000
Z : Zero : 00000
N : Nom : .code
F : Fin
I : immediate: 16b
J : jump : 26b
O : ofset : 16b
R : 00001
												*/
#endif
