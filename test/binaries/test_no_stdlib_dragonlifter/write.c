#include "dragonlifter.h"

void write() {
	ADDR_400144:; // PUSH RBP
	temp_59264._8 = RBP;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_400145:; // MOV RBP,RSP
	RBP = RSP;
	ADDR_400148:; // MOV dword ptr [RBP + -0x14],EDI
	temp_12544._8 = RBP + ((u64)-20);
	temp_48256._4 = EDI;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_40014B:; // MOV qword ptr [RBP + -0x20],RSI
	temp_12544._8 = RBP + ((u64)-32);
	temp_48512._8 = RSI;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_40014F:; // MOV qword ptr [RBP + -0x28],RDX
	temp_12544._8 = RBP + ((u64)-40);
	temp_48512._8 = RDX;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_400153:; // MOV EAX,0x1
	RAX = ((u64)1);
	ADDR_400158:; // MOV EDI,dword ptr [RBP + -0x14]
	temp_12544._8 = RBP + ((u64)-20);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EDI = temp_48256._4;
	RDI = EDI;
	ADDR_40015B:; // MOV RSI,qword ptr [RBP + -0x20]
	temp_12544._8 = RBP + ((u64)-32);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RSI = temp_48512._8;
	ADDR_40015F:; // MOV RDX,qword ptr [RBP + -0x28]
	temp_12544._8 = RBP + ((u64)-40);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RDX = temp_48512._8;
	ADDR_400163:; // SYSCALL
	CALLOTHER(syscall);
	ADDR_400165:; // MOV qword ptr [RBP + -0x8],RAX
	temp_12544._8 = RBP + ((u64)-8);
	temp_48512._8 = RAX;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_400169:; // NOP
	
	ADDR_40016A:; // POP RBP
	RBP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_40016B:; // RET
	RIP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	return;
	
}
