#include "dragonlifter.h"

void input_prompt() {
	ADDR_101279:; // ENDBR64
	
	ADDR_10127D:; // PUSH RBP
	temp_59264._8 = RBP;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_10127E:; // MOV RBP,RSP
	RBP = RSP;
	ADDR_101281:; // SUB RSP,0x10
	CF = RSP < ((u64)16);
	OF = SIGN(8, RSPs) != SIGN(8, ((i64)16)) && SIGN(8, (i64)(RSPs - ((i64)16))) == SIGN(8, ((i64)16));
	RSP = RSP - ((u64)16);
	SF = RSPs < ((i64)0);
	ZF = RSP == ((u64)0);
	temp_76800._8 = RSP & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_101285:; // MOV qword ptr [RBP + -0x8],RDI
	temp_12544._8 = RBP + ((u64)-8);
	temp_48512._8 = RDI;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_101289:; // MOV RAX,qword ptr [RBP + -0x8]
	temp_12544._8 = RBP + ((u64)-8);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RAX = temp_48512._8;
	ADDR_10128D:; // MOV ESI,0x0
	RSI = ((u64)0);
	ADDR_101292:; // MOV RDI,RAX
	RDI = RAX;
	ADDR_101295:; // MOV EAX,0x0
	RAX = ((u64)0);
	ADDR_10129A:; // CALL 0x001010aa
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x10129f);
	print_raw();
	ADDR_10129F:; // MOV EAX,0x0
	RAX = ((u64)0);
	ADDR_1012A4:; // CALL 0x00101201
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x1012a9);
	input();
	ADDR_1012A9:; // NOP
	
	ADDR_1012AA:; // LEAVE
	RSP = RBP;
	RBP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_1012AB:; // RET
	RIP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	return;
	
}
