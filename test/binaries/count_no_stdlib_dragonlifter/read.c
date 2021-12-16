#include "dragonlifter.h"

void read() {
	ADDR_10102C:; // ENDBR64
	++__instruction_count;
	
	ADDR_101030:; // PUSH RBP
	++__instruction_count;
	temp_59264._8 = RBP;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_101031:; // MOV RBP,RSP
	++__instruction_count;
	RBP = RSP;
	ADDR_101034:; // MOV dword ptr [RBP + -0x14],EDI
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-20);
	temp_48256._4 = EDI;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_101037:; // MOV qword ptr [RBP + -0x20],RSI
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-32);
	temp_48512._8 = RSI;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_10103B:; // MOV qword ptr [RBP + -0x28],RDX
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-40);
	temp_48512._8 = RDX;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_10103F:; // MOV EAX,0x0
	++__instruction_count;
	RAX = ((u64)0);
	ADDR_101044:; // MOV EDI,dword ptr [RBP + -0x14]
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-20);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EDI = temp_48256._4;
	RDI = EDI;
	ADDR_101047:; // MOV RSI,qword ptr [RBP + -0x20]
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-32);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RSI = temp_48512._8;
	ADDR_10104B:; // MOV RDX,qword ptr [RBP + -0x28]
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-40);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RDX = temp_48512._8;
	ADDR_10104F:; // SYSCALL
	++__instruction_count;
	CALLOTHER(syscall);
	ADDR_101051:; // MOV qword ptr [RBP + -0x8],RAX
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-8);
	temp_48512._8 = RAX;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_101055:; // NOP
	++__instruction_count;
	
	ADDR_101056:; // POP RBP
	++__instruction_count;
	RBP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_101057:; // RET
	++__instruction_count;
	RIP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	return;
	
}
