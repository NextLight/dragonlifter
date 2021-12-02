#include "dragonlifter.h"

void getchar() {
	ADDR_400309:; // PUSH RBP
	temp_59264._8 = RBP;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_40030A:; // MOV RBP,RSP
	RBP = RSP;
	ADDR_40030D:; // MOV EDX,0x1
	RDX = ((u64)1);
	ADDR_400312:; // LEA RSI,[0x601000]
	RSI = ((u64)0x601000);
	ADDR_400319:; // MOV EDI,0x0
	RDI = ((u64)0);
	ADDR_40031E:; // CALL 0x0040016c
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x400323);
	read();
	ADDR_400323:; // MOVZX EAX,byte ptr [0x00601000]
	EAX = RAM(6295552)._1;
	RAX = EAX;
	ADDR_40032A:; // POP RBP
	RBP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_40032B:; // RET
	RIP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	return;
	
}
