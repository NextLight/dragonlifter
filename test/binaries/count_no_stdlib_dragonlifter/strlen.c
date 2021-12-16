#include "dragonlifter.h"

void strlen() {
	ADDR_101076:; // ENDBR64
	++__instruction_count;
	
	ADDR_10107A:; // PUSH RBP
	++__instruction_count;
	temp_59264._8 = RBP;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_10107B:; // MOV RBP,RSP
	++__instruction_count;
	RBP = RSP;
	ADDR_10107E:; // MOV qword ptr [RBP + -0x18],RDI
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-24);
	temp_48512._8 = RDI;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_101082:; // MOV dword ptr [RBP + -0x4],0x0
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-4);
	temp_48384._4 = ((u32)0);
	RAM(temp_12544._8)._4 = temp_48384._4;
	ADDR_101089:; // JMP 0x0010108f
	++__instruction_count;
	goto ADDR_10108F;
	ADDR_10108B:; // ADD dword ptr [RBP + -0x4],0x1
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-4);
	temp_48384._4 = RAM(temp_12544._8)._4;
	CF = (u32)(temp_48384._4 + ((u32)1)) < temp_48384._4;
	temp_48384._4 = RAM(temp_12544._8)._4;
	OF = SIGN(4, temp_48384._4s) == SIGN(4, ((i32)1)) && SIGN(4, (i32)(temp_48384._4s + ((i32)1))) != SIGN(4, ((i32)1));
	temp_48384._4 = RAM(temp_12544._8)._4;
	temp_48384._4 = temp_48384._4 + ((u32)1);
	RAM(temp_12544._8)._4 = temp_48384._4;
	temp_48384._4 = RAM(temp_12544._8)._4;
	SF = temp_48384._4s < ((i32)0);
	temp_48384._4 = RAM(temp_12544._8)._4;
	ZF = temp_48384._4 == ((u32)0);
	temp_48384._4 = RAM(temp_12544._8)._4;
	temp_76800._4 = temp_48384._4 & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_10108F:; // MOV EAX,dword ptr [RBP + -0x4]
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_101092:; // MOVSXD RDX,EAX
	++__instruction_count;
	RDXs = EAXs;
	ADDR_101095:; // MOV RAX,qword ptr [RBP + -0x18]
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-24);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RAX = temp_48512._8;
	ADDR_101099:; // ADD RAX,RDX
	++__instruction_count;
	CF = (u64)(RAX + RDX) < RAX;
	OF = SIGN(8, RAXs) == SIGN(8, RDXs) && SIGN(8, (i64)(RAXs + RDXs)) != SIGN(8, RDXs);
	RAX = RAX + RDX;
	SF = RAXs < ((i64)0);
	ZF = RAX == ((u64)0);
	temp_76800._8 = RAX & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_10109C:; // MOVZX EAX,byte ptr [RAX]
	++__instruction_count;
	temp_47872._1 = RAM(RAX)._1;
	EAX = temp_47872._1;
	RAX = EAX;
	ADDR_10109F:; // TEST AL,AL
	++__instruction_count;
	CF = ((u8)0);
	OF = ((u8)0);
	temp_364544._1 = AL & AL;
	SF = temp_364544._1s < ((i8)0);
	ZF = temp_364544._1 == ((u8)0);
	temp_76800._1 = temp_364544._1 & ((u8)255);
	temp_76928._1 = POPCOUNT(1, temp_76800._1);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_1010A1:; // JNZ 0x0010108b
	++__instruction_count;
	temp_50816._1 = !ZF;
	if (temp_50816._1) goto ADDR_10108B;
	ADDR_1010A3:; // MOV EAX,dword ptr [RBP + -0x4]
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_1010A6:; // CDQE
	++__instruction_count;
	RAXs = EAXs;
	ADDR_1010A8:; // POP RBP
	++__instruction_count;
	RBP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_1010A9:; // RET
	++__instruction_count;
	RIP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	return;
	
}
