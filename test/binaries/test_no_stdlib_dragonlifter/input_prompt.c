#include "dragonlifter.h"

void input_prompt() {
	ADDR_4003A3:; // PUSH RBP
	temp_59264._8 = RBP;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_4003A4:; // MOV RBP,RSP
	RBP = RSP;
	ADDR_4003A7:; // SUB RSP,0x10
	CF = RSP < ((u64)16);
	OF = SIGN(8, RSPs) != SIGN(8, ((i64)16)) && SIGN(8, (i64)(RSPs - ((i64)16))) == SIGN(8, ((i64)16));
	RSP = RSP - ((u64)16);
	SF = RSPs < ((i64)0);
	ZF = RSP == ((u64)0);
	temp_76800._8 = RSP & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_4003AB:; // MOV qword ptr [RBP + -0x8],RDI
	temp_12544._8 = RBP + ((u64)-8);
	temp_48512._8 = RDI;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_4003AF:; // MOV RAX,qword ptr [RBP + -0x8]
	temp_12544._8 = RBP + ((u64)-8);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RAX = temp_48512._8;
	ADDR_4003B3:; // MOV ESI,0x0
	RSI = ((u64)0);
	ADDR_4003B8:; // MOV RDI,RAX
	RDI = RAX;
	ADDR_4003BB:; // MOV EAX,0x0
	RAX = ((u64)0);
	ADDR_4003C0:; // CALL 0x004001de
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x4003c5);
	print_raw();
	ADDR_4003C5:; // MOV EAX,0x0
	RAX = ((u64)0);
	ADDR_4003CA:; // CALL 0x0040032c
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x4003cf);
	input();
	ADDR_4003CF:; // NOP
	
	ADDR_4003D0:; // LEAVE
	RSP = RBP;
	RBP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_4003D1:; // RET
	RIP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	return;
	
}
