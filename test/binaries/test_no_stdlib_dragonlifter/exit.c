#include "dragonlifter.h"

void exit() {
	ADDR_400194:; // PUSH RBP
	temp_59264._8 = RBP;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_400195:; // MOV RBP,RSP
	RBP = RSP;
	ADDR_400198:; // MOV dword ptr [RBP + -0x14],EDI
	temp_12544._8 = RBP + ((u64)-20);
	temp_48256._4 = EDI;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_40019B:; // MOV EAX,0x3c
	RAX = ((u64)60);
	ADDR_4001A0:; // MOV EDX,dword ptr [RBP + -0x14]
	temp_12544._8 = RBP + ((u64)-20);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EDX = temp_48256._4;
	RDX = EDX;
	ADDR_4001A3:; // MOV EDI,EDX
	EDI = EDX;
	RDI = EDI;
	ADDR_4001A5:; // SYSCALL
	CALLOTHER(syscall);
	ADDR_4001A7:; // MOV qword ptr [RBP + -0x8],RAX
	temp_12544._8 = RBP + ((u64)-8);
	temp_48512._8 = RAX;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_4001AB:; // NOP
	
	ADDR_4001AC:; // POP RBP
	RBP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_4001AD:; // RET
	RIP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	return;
	
}
