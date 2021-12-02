#include "dragonlifter.h"

void strlen() {
	ADDR_4001AE:; // PUSH RBP
	temp_59264._8 = RBP;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_4001AF:; // MOV RBP,RSP
	RBP = RSP;
	ADDR_4001B2:; // MOV qword ptr [RBP + -0x18],RDI
	temp_12544._8 = RBP + ((u64)-24);
	temp_48512._8 = RDI;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_4001B6:; // MOV dword ptr [RBP + -0x4],0x0
	temp_12544._8 = RBP + ((u64)-4);
	temp_48384._4 = ((u32)0);
	RAM(temp_12544._8)._4 = temp_48384._4;
	ADDR_4001BD:; // JMP 0x004001c3
	goto ADDR_4001C3;
	ADDR_4001BF:; // ADD dword ptr [RBP + -0x4],0x1
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
	ADDR_4001C3:; // MOV EAX,dword ptr [RBP + -0x4]
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_4001C6:; // MOVSXD RDX,EAX
	RDXs = EAXs;
	ADDR_4001C9:; // MOV RAX,qword ptr [RBP + -0x18]
	temp_12544._8 = RBP + ((u64)-24);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RAX = temp_48512._8;
	ADDR_4001CD:; // ADD RAX,RDX
	CF = (u64)(RAX + RDX) < RAX;
	OF = SIGN(8, RAXs) == SIGN(8, RDXs) && SIGN(8, (i64)(RAXs + RDXs)) != SIGN(8, RDXs);
	RAX = RAX + RDX;
	SF = RAXs < ((i64)0);
	ZF = RAX == ((u64)0);
	temp_76800._8 = RAX & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_4001D0:; // MOVZX EAX,byte ptr [RAX]
	temp_47872._1 = RAM(RAX)._1;
	EAX = temp_47872._1;
	RAX = EAX;
	ADDR_4001D3:; // TEST AL,AL
	CF = ((u8)0);
	OF = ((u8)0);
	temp_364544._1 = AL & AL;
	SF = temp_364544._1s < ((i8)0);
	ZF = temp_364544._1 == ((u8)0);
	temp_76800._1 = temp_364544._1 & ((u8)255);
	temp_76928._1 = POPCOUNT(1, temp_76800._1);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_4001D5:; // JNZ 0x004001bf
	temp_50816._1 = !ZF;
	if (temp_50816._1) goto ADDR_4001BF;
	ADDR_4001D7:; // MOV EAX,dword ptr [RBP + -0x4]
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_4001DA:; // CDQE
	RAXs = EAXs;
	ADDR_4001DC:; // POP RBP
	RBP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_4001DD:; // RET
	RIP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	return;
	
}
