#include "dragonlifter.h"

void write() {
	ADDR_101000:; // ENDBR64
	++__instruction_count;
	
	ADDR_101004:; // PUSH RBP
	++__instruction_count;
	temp_59264._8 = RBP;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_101005:; // MOV RBP,RSP
	++__instruction_count;
	RBP = RSP;
	ADDR_101008:; // MOV dword ptr [RBP + -0x14],EDI
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-20);
	temp_48256._4 = EDI;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_10100B:; // MOV qword ptr [RBP + -0x20],RSI
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-32);
	temp_48512._8 = RSI;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_10100F:; // MOV qword ptr [RBP + -0x28],RDX
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-40);
	temp_48512._8 = RDX;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_101013:; // MOV EAX,0x1
	++__instruction_count;
	RAX = ((u64)1);
	ADDR_101018:; // MOV EDI,dword ptr [RBP + -0x14]
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-20);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EDI = temp_48256._4;
	RDI = EDI;
	ADDR_10101B:; // MOV RSI,qword ptr [RBP + -0x20]
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-32);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RSI = temp_48512._8;
	ADDR_10101F:; // MOV RDX,qword ptr [RBP + -0x28]
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-40);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RDX = temp_48512._8;
	ADDR_101023:; // SYSCALL
	++__instruction_count;
	CALLOTHER(syscall);
	ADDR_101025:; // MOV qword ptr [RBP + -0x8],RAX
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-8);
	temp_48512._8 = RAX;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_101029:; // NOP
	++__instruction_count;
	
	ADDR_10102A:; // POP RBP
	++__instruction_count;
	RBP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_10102B:; // RET
	++__instruction_count;
	RIP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	return;
	
}
