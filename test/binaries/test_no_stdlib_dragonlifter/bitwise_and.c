#include "dragonlifter.h"

void bitwise_and() {
	ADDR_4008A2:; // PUSH RBP
	temp_59264._8 = RBP;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_4008A3:; // MOV RBP,RSP
	RBP = RSP;
	ADDR_4008A6:; // MOV dword ptr [RBP + -0x4],EDI
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = EDI;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_4008A9:; // MOV dword ptr [RBP + -0x8],ESI
	temp_12544._8 = RBP + ((u64)-8);
	temp_48256._4 = ESI;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_4008AC:; // MOV EAX,dword ptr [RBP + -0x4]
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_4008AF:; // AND EAX,dword ptr [RBP + -0x8]
	temp_12544._8 = RBP + ((u64)-8);
	CF = ((u8)0);
	OF = ((u8)0);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = EAX & temp_48256._4;
	RAX = EAX;
	SF = EAXs < ((i32)0);
	ZF = EAX == ((u32)0);
	temp_76800._4 = EAX & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_4008B2:; // POP RBP
	RBP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_4008B3:; // RET
	RIP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	return;
	
}
