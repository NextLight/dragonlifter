#include "dragonlifter.h"

void exit() {
	ADDR_101058:; // ENDBR64
	
	ADDR_10105C:; // PUSH RBP
	temp_59264._8 = RBP;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_10105D:; // MOV RBP,RSP
	RBP = RSP;
	ADDR_101060:; // MOV dword ptr [RBP + -0x14],EDI
	temp_12544._8 = RBP + ((u64)-20);
	temp_48256._4 = EDI;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_101063:; // MOV EAX,0x3c
	RAX = ((u64)60);
	ADDR_101068:; // MOV EDX,dword ptr [RBP + -0x14]
	temp_12544._8 = RBP + ((u64)-20);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EDX = temp_48256._4;
	RDX = EDX;
	ADDR_10106B:; // MOV EDI,EDX
	EDI = EDX;
	RDI = EDI;
	ADDR_10106D:; // SYSCALL
	CALLOTHER(syscall);
	ADDR_10106F:; // MOV qword ptr [RBP + -0x8],RAX
	temp_12544._8 = RBP + ((u64)-8);
	temp_48512._8 = RAX;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_101073:; // NOP
	
	ADDR_101074:; // POP RBP
	RBP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_101075:; // RET
	RIP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	return;
	
}