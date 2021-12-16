#include "dragonlifter.h"

void bitwise_or() {
	static const void* labels[] = { &&ADDR_101799,NULL,NULL,NULL,&&ADDR_10179D,&&ADDR_10179E,NULL,NULL,&&ADDR_1017A1,NULL,NULL,&&ADDR_1017A4,NULL,NULL,&&ADDR_1017A7,NULL,NULL,&&ADDR_1017AA,NULL,NULL,&&ADDR_1017AD,&&ADDR_1017AE };
	static const size_t labels_base_address = 1054617;
	ADDR_101799:; // ENDBR64
	
	ADDR_10179D:; // PUSH RBP
	temp_59264._8 = RBP;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_10179E:; // MOV RBP,RSP
	RBP = RSP;
	ADDR_1017A1:; // MOV dword ptr [RBP + -0x4],EDI
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = EDI;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_1017A4:; // MOV dword ptr [RBP + -0x8],ESI
	temp_12544._8 = RBP + ((u64)-8);
	temp_48256._4 = ESI;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_1017A7:; // MOV EAX,dword ptr [RBP + -0x4]
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_1017AA:; // OR EAX,dword ptr [RBP + -0x8]
	temp_12544._8 = RBP + ((u64)-8);
	CF = ((u8)0);
	OF = ((u8)0);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = EAX | temp_48256._4;
	RAX = EAX;
	SF = EAXs < ((i32)0);
	ZF = EAX == ((u32)0);
	temp_76800._4 = EAX & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_1017AD:; // POP RBP
	RBP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_1017AE:; // RET
	RIP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	return;
	
}
