#include "dragonlifter.h"

void getchar() {
	ADDR_1011DA:; // ENDBR64
	++__instruction_count;
	
	ADDR_1011DE:; // PUSH RBP
	++__instruction_count;
	temp_59264._8 = RBP;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_1011DF:; // MOV RBP,RSP
	++__instruction_count;
	RBP = RSP;
	ADDR_1011E2:; // MOV EDX,0x1
	++__instruction_count;
	RDX = ((u64)1);
	ADDR_1011E7:; // LEA RSI,[0x104000]
	++__instruction_count;
	RSI = ((u64)0x104000);
	ADDR_1011EE:; // MOV EDI,0x0
	++__instruction_count;
	RDI = ((u64)0);
	ADDR_1011F3:; // CALL 0x0010102c
	++__instruction_count;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x1011f8);
	read();
	ADDR_1011F8:; // MOVZX EAX,byte ptr [0x00104000]
	++__instruction_count;
	EAX = RAM(1064960)._1;
	RAX = EAX;
	ADDR_1011FF:; // POP RBP
	++__instruction_count;
	RBP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_101200:; // RET
	++__instruction_count;
	RIP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	return;
	
}
