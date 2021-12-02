#include "dragonlifter.h"

void read() {
	ADDR_40016C:; // PUSH RBP
	temp_59264._8 = RBP;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_40016D:; // MOV RBP,RSP
	RBP = RSP;
	ADDR_400170:; // MOV dword ptr [RBP + -0x14],EDI
	temp_12544._8 = RBP + ((u64)-20);
	temp_48256._4 = EDI;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_400173:; // MOV qword ptr [RBP + -0x20],RSI
	temp_12544._8 = RBP + ((u64)-32);
	temp_48512._8 = RSI;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_400177:; // MOV qword ptr [RBP + -0x28],RDX
	temp_12544._8 = RBP + ((u64)-40);
	temp_48512._8 = RDX;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_40017B:; // MOV EAX,0x0
	RAX = ((u64)0);
	ADDR_400180:; // MOV EDI,dword ptr [RBP + -0x14]
	temp_12544._8 = RBP + ((u64)-20);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EDI = temp_48256._4;
	RDI = EDI;
	ADDR_400183:; // MOV RSI,qword ptr [RBP + -0x20]
	temp_12544._8 = RBP + ((u64)-32);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RSI = temp_48512._8;
	ADDR_400187:; // MOV RDX,qword ptr [RBP + -0x28]
	temp_12544._8 = RBP + ((u64)-40);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RDX = temp_48512._8;
	ADDR_40018B:; // SYSCALL
	CALLOTHER(syscall);
	ADDR_40018D:; // MOV qword ptr [RBP + -0x8],RAX
	temp_12544._8 = RBP + ((u64)-8);
	temp_48512._8 = RAX;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_400191:; // NOP
	
	ADDR_400192:; // POP RBP
	RBP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_400193:; // RET
	RIP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	return;
	
}
