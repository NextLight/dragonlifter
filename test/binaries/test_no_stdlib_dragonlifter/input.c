#include "dragonlifter.h"

void input() {
	ADDR_40032C:; // PUSH RBP
	temp_59264._8 = RBP;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_40032D:; // MOV RBP,RSP
	RBP = RSP;
	ADDR_400330:; // SUB RSP,0x10
	CF = RSP < ((u64)16);
	OF = SIGN(8, RSPs) != SIGN(8, ((i64)16)) && SIGN(8, (i64)(RSPs - ((i64)16))) == SIGN(8, ((i64)16));
	RSP = RSP - ((u64)16);
	SF = RSPs < ((i64)0);
	ZF = RSP == ((u64)0);
	temp_76800._8 = RSP & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_400334:; // MOV EAX,dword ptr [0x00601004]
	EAX = RAM(6295556)._4;
	RAX = EAX;
	ADDR_40033A:; // MOVSXD RDX,EAX
	RDXs = EAXs;
	ADDR_40033D:; // LEA RAX,[0x601020]
	RAX = ((u64)0x601020);
	ADDR_400344:; // ADD RAX,RDX
	CF = (u64)(RAX + RDX) < RAX;
	OF = SIGN(8, RAXs) == SIGN(8, RDXs) && SIGN(8, (i64)(RAXs + RDXs)) != SIGN(8, RDXs);
	RAX = RAX + RDX;
	SF = RAXs < ((i64)0);
	ZF = RAX == ((u64)0);
	temp_76800._8 = RAX & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_400347:; // MOV qword ptr [RBP + -0x8],RAX
	temp_12544._8 = RBP + ((u64)-8);
	temp_48512._8 = RAX;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_40034B:; // JMP 0x0040036d
	goto ADDR_40036D;
	ADDR_40034D:; // MOV EAX,dword ptr [0x00601004]
	EAX = RAM(6295556)._4;
	RAX = EAX;
	ADDR_400353:; // LEA EDX,[RAX + 0x1]
	temp_12544._8 = RAX + ((u64)1);
	EDX = (temp_12544._8 / 0x1);
	RDX = EDX;
	ADDR_400356:; // MOV dword ptr [0x00601004],EDX
	RAM(6295556)._4 = EDX;
	ADDR_40035C:; // MOVSXD RDX,EAX
	RDXs = EAXs;
	ADDR_40035F:; // LEA RAX,[0x601020]
	RAX = ((u64)0x601020);
	ADDR_400366:; // MOVZX ECX,byte ptr [RBP + -0x9]
	temp_12544._8 = RBP + ((u64)-9);
	temp_47872._1 = RAM(temp_12544._8)._1;
	ECX = temp_47872._1;
	RCX = ECX;
	ADDR_40036A:; // MOV byte ptr [RDX + RAX*0x1],CL
	temp_13056._8 = RAX * ((u64)1);
	temp_13312._8 = RDX + temp_13056._8;
	temp_47744._1 = CL;
	RAM(temp_13312._8)._1 = temp_47744._1;
	ADDR_40036D:; // MOV EAX,0x0
	RAX = ((u64)0);
	ADDR_400372:; // CALL 0x00400309
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x400377);
	getchar();
	ADDR_400377:; // MOV byte ptr [RBP + -0x9],AL
	temp_12544._8 = RBP + ((u64)-9);
	temp_47744._1 = AL;
	RAM(temp_12544._8)._1 = temp_47744._1;
	ADDR_40037A:; // CMP byte ptr [RBP + -0x9],0x1f
	temp_12544._8 = RBP + ((u64)-9);
	temp_47872._1 = RAM(temp_12544._8)._1;
	CF = temp_47872._1 < ((u8)31);
	temp_47872._1 = RAM(temp_12544._8)._1;
	OF = SIGN(1, temp_47872._1s) != SIGN(1, ((i8)31)) && SIGN(1, (i8)(temp_47872._1s - ((i8)31))) == SIGN(1, ((i8)31));
	temp_47872._1 = RAM(temp_12544._8)._1;
	temp_163072._1 = temp_47872._1 - ((u8)31);
	SF = temp_163072._1s < ((i8)0);
	ZF = temp_163072._1 == ((u8)0);
	temp_76800._1 = temp_163072._1 & ((u8)255);
	temp_76928._1 = POPCOUNT(1, temp_76800._1);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_40037E:; // JG 0x0040034d
	temp_52992._1 = !ZF;
	temp_53120._1 = OF == SF;
	temp_53376._1 = temp_52992._1 && temp_53120._1;
	if (temp_53376._1) goto ADDR_40034D;
	ADDR_400380:; // MOV EAX,dword ptr [0x00601004]
	EAX = RAM(6295556)._4;
	RAX = EAX;
	ADDR_400386:; // LEA EDX,[RAX + 0x1]
	temp_12544._8 = RAX + ((u64)1);
	EDX = (temp_12544._8 / 0x1);
	RDX = EDX;
	ADDR_400389:; // MOV dword ptr [0x00601004],EDX
	RAM(6295556)._4 = EDX;
	ADDR_40038F:; // MOVSXD RDX,EAX
	RDXs = EAXs;
	ADDR_400392:; // LEA RAX,[0x601020]
	RAX = ((u64)0x601020);
	ADDR_400399:; // MOV byte ptr [RDX + RAX*0x1],0x0
	temp_13056._8 = RAX * ((u64)1);
	temp_13312._8 = RDX + temp_13056._8;
	temp_47872._1 = ((u8)0);
	RAM(temp_13312._8)._1 = temp_47872._1;
	ADDR_40039D:; // MOV RAX,qword ptr [RBP + -0x8]
	temp_12544._8 = RBP + ((u64)-8);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RAX = temp_48512._8;
	ADDR_4003A1:; // LEAVE
	RSP = RBP;
	RBP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_4003A2:; // RET
	RIP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	return;
	
}
