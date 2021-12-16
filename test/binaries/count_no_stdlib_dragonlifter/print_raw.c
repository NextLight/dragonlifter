#include "dragonlifter.h"

void print_raw() {
	ADDR_1010AA:; // ENDBR64
	++__instruction_count;
	
	ADDR_1010AE:; // PUSH RBP
	++__instruction_count;
	temp_59264._8 = RBP;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_1010AF:; // MOV RBP,RSP
	++__instruction_count;
	RBP = RSP;
	ADDR_1010B2:; // SUB RSP,0xe0
	++__instruction_count;
	CF = RSP < ((u64)224);
	OF = SIGN(8, RSPs) != SIGN(8, ((i64)224)) && SIGN(8, (i64)(RSPs - ((i64)224))) == SIGN(8, ((i64)224));
	RSP = RSP - ((u64)224);
	SF = RSPs < ((i64)0);
	ZF = RSP == ((u64)0);
	temp_76800._8 = RSP & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_1010B9:; // MOV qword ptr [RBP + -0xd8],RDI
	++__instruction_count;
	temp_12800._8 = RBP + ((u64)-216);
	temp_48512._8 = RDI;
	RAM(temp_12800._8)._8 = temp_48512._8;
	ADDR_1010C0:; // MOV qword ptr [RBP + -0xa8],RSI
	++__instruction_count;
	temp_12800._8 = RBP + ((u64)-168);
	temp_48512._8 = RSI;
	RAM(temp_12800._8)._8 = temp_48512._8;
	ADDR_1010C7:; // MOV qword ptr [RBP + -0xa0],RDX
	++__instruction_count;
	temp_12800._8 = RBP + ((u64)-160);
	temp_48512._8 = RDX;
	RAM(temp_12800._8)._8 = temp_48512._8;
	ADDR_1010CE:; // MOV qword ptr [RBP + -0x98],RCX
	++__instruction_count;
	temp_12800._8 = RBP + ((u64)-152);
	temp_48512._8 = RCX;
	RAM(temp_12800._8)._8 = temp_48512._8;
	ADDR_1010D5:; // MOV qword ptr [RBP + -0x90],R8
	++__instruction_count;
	temp_12800._8 = RBP + ((u64)-144);
	temp_48512._8 = R8;
	RAM(temp_12800._8)._8 = temp_48512._8;
	ADDR_1010DC:; // MOV qword ptr [RBP + -0x88],R9
	++__instruction_count;
	temp_12800._8 = RBP + ((u64)-136);
	temp_48512._8 = R9;
	RAM(temp_12800._8)._8 = temp_48512._8;
	ADDR_1010E3:; // TEST AL,AL
	++__instruction_count;
	CF = ((u8)0);
	OF = ((u8)0);
	temp_364544._1 = AL & AL;
	SF = temp_364544._1s < ((i8)0);
	ZF = temp_364544._1 == ((u8)0);
	temp_76800._1 = temp_364544._1 & ((u8)255);
	temp_76928._1 = POPCOUNT(1, temp_76800._1);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_1010E5:; // JZ 0x00101107
	++__instruction_count;
	if (ZF) goto ADDR_101107;
	ADDR_1010E7:; // MOVAPS xmmword ptr [RBP + -0x80],XMM0
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-128);
	temp_21248._16 = XMM0;
	RAM(temp_12544._8)._16 = temp_21248._16;
	ADDR_1010EB:; // MOVAPS xmmword ptr [RBP + -0x70],XMM1
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-112);
	temp_21248._16 = XMM1;
	RAM(temp_12544._8)._16 = temp_21248._16;
	ADDR_1010EF:; // MOVAPS xmmword ptr [RBP + -0x60],XMM2
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-96);
	temp_21248._16 = XMM2;
	RAM(temp_12544._8)._16 = temp_21248._16;
	ADDR_1010F3:; // MOVAPS xmmword ptr [RBP + -0x50],XMM3
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-80);
	temp_21248._16 = XMM3;
	RAM(temp_12544._8)._16 = temp_21248._16;
	ADDR_1010F7:; // MOVAPS xmmword ptr [RBP + -0x40],XMM4
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-64);
	temp_21248._16 = XMM4;
	RAM(temp_12544._8)._16 = temp_21248._16;
	ADDR_1010FB:; // MOVAPS xmmword ptr [RBP + -0x30],XMM5
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-48);
	temp_21248._16 = XMM5;
	RAM(temp_12544._8)._16 = temp_21248._16;
	ADDR_1010FF:; // MOVAPS xmmword ptr [RBP + -0x20],XMM6
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-32);
	temp_21248._16 = XMM6;
	RAM(temp_12544._8)._16 = temp_21248._16;
	ADDR_101103:; // MOVAPS xmmword ptr [RBP + -0x10],XMM7
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-16);
	temp_21248._16 = XMM7;
	RAM(temp_12544._8)._16 = temp_21248._16;
	ADDR_101107:; // MOV dword ptr [RBP + -0xd0],0x8
	++__instruction_count;
	temp_12800._8 = RBP + ((u64)-208);
	temp_48384._4 = ((u32)8);
	RAM(temp_12800._8)._4 = temp_48384._4;
	ADDR_101111:; // MOV dword ptr [RBP + -0xcc],0x30
	++__instruction_count;
	temp_12800._8 = RBP + ((u64)-204);
	temp_48384._4 = ((u32)48);
	RAM(temp_12800._8)._4 = temp_48384._4;
	ADDR_10111B:; // LEA RAX,[RBP + 0x10]
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)16);
	RAX = temp_12544._8;
	ADDR_10111F:; // MOV qword ptr [RBP + -0xc8],RAX
	++__instruction_count;
	temp_12800._8 = RBP + ((u64)-200);
	temp_48512._8 = RAX;
	RAM(temp_12800._8)._8 = temp_48512._8;
	ADDR_101126:; // LEA RAX,[RBP + -0xb0]
	++__instruction_count;
	temp_12800._8 = RBP + ((u64)-176);
	RAX = temp_12800._8;
	ADDR_10112D:; // MOV qword ptr [RBP + -0xc0],RAX
	++__instruction_count;
	temp_12800._8 = RBP + ((u64)-192);
	temp_48512._8 = RAX;
	RAM(temp_12800._8)._8 = temp_48512._8;
	ADDR_101134:; // MOV RAX,qword ptr [RBP + -0xd8]
	++__instruction_count;
	temp_12800._8 = RBP + ((u64)-216);
	temp_48512._8 = RAM(temp_12800._8)._8;
	RAX = temp_48512._8;
	ADDR_10113B:; // MOV RDI,RAX
	++__instruction_count;
	RDI = RAX;
	ADDR_10113E:; // CALL 0x00101076
	++__instruction_count;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x101143);
	strlen();
	ADDR_101143:; // MOV RDX,RAX
	++__instruction_count;
	RDX = RAX;
	ADDR_101146:; // MOV RAX,qword ptr [RBP + -0xd8]
	++__instruction_count;
	temp_12800._8 = RBP + ((u64)-216);
	temp_48512._8 = RAM(temp_12800._8)._8;
	RAX = temp_48512._8;
	ADDR_10114D:; // MOV RSI,RAX
	++__instruction_count;
	RSI = RAX;
	ADDR_101150:; // MOV EDI,0x1
	++__instruction_count;
	RDI = ((u64)1);
	ADDR_101155:; // CALL 0x00101000
	++__instruction_count;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x10115a);
	write();
	ADDR_10115A:; // JMP 0x00101182
	++__instruction_count;
	goto ADDR_101182;
	ADDR_10115C:; // MOV RAX,qword ptr [RBP + -0xb8]
	++__instruction_count;
	temp_12800._8 = RBP + ((u64)-184);
	temp_48512._8 = RAM(temp_12800._8)._8;
	RAX = temp_48512._8;
	ADDR_101163:; // MOV RDI,RAX
	++__instruction_count;
	RDI = RAX;
	ADDR_101166:; // CALL 0x00101076
	++__instruction_count;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x10116b);
	strlen();
	ADDR_10116B:; // MOV RDX,RAX
	++__instruction_count;
	RDX = RAX;
	ADDR_10116E:; // MOV RAX,qword ptr [RBP + -0xb8]
	++__instruction_count;
	temp_12800._8 = RBP + ((u64)-184);
	temp_48512._8 = RAM(temp_12800._8)._8;
	RAX = temp_48512._8;
	ADDR_101175:; // MOV RSI,RAX
	++__instruction_count;
	RSI = RAX;
	ADDR_101178:; // MOV EDI,0x1
	++__instruction_count;
	RDI = ((u64)1);
	ADDR_10117D:; // CALL 0x00101000
	++__instruction_count;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x101182);
	write();
	ADDR_101182:; // MOV EAX,dword ptr [RBP + -0xd0]
	++__instruction_count;
	temp_12800._8 = RBP + ((u64)-208);
	temp_48256._4 = RAM(temp_12800._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_101188:; // CMP EAX,0x2f
	++__instruction_count;
	CF = EAX < ((u32)47);
	OF = SIGN(4, EAXs) != SIGN(4, ((i32)47)) && SIGN(4, (i32)(EAXs - ((i32)47))) == SIGN(4, ((i32)47));
	temp_164352._4 = EAX - ((u32)47);
	SF = temp_164352._4s < ((i32)0);
	ZF = temp_164352._4 == ((u32)0);
	temp_76800._4 = temp_164352._4 & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_10118B:; // JA 0x001011b0
	++__instruction_count;
	temp_51200._1 = CF || ZF;
	temp_51456._1 = !temp_51200._1;
	if (temp_51456._1) goto ADDR_1011B0;
	ADDR_10118D:; // MOV RAX,qword ptr [RBP + -0xc0]
	++__instruction_count;
	temp_12800._8 = RBP + ((u64)-192);
	temp_48512._8 = RAM(temp_12800._8)._8;
	RAX = temp_48512._8;
	ADDR_101194:; // MOV EDX,dword ptr [RBP + -0xd0]
	++__instruction_count;
	temp_12800._8 = RBP + ((u64)-208);
	temp_48256._4 = RAM(temp_12800._8)._4;
	EDX = temp_48256._4;
	RDX = EDX;
	ADDR_10119A:; // MOV EDX,EDX
	++__instruction_count;
	EDX = EDX;
	RDX = EDX;
	ADDR_10119C:; // ADD RAX,RDX
	++__instruction_count;
	CF = (u64)(RAX + RDX) < RAX;
	OF = SIGN(8, RAXs) == SIGN(8, RDXs) && SIGN(8, (i64)(RAXs + RDXs)) != SIGN(8, RDXs);
	RAX = RAX + RDX;
	SF = RAXs < ((i64)0);
	ZF = RAX == ((u64)0);
	temp_76800._8 = RAX & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_10119F:; // MOV EDX,dword ptr [RBP + -0xd0]
	++__instruction_count;
	temp_12800._8 = RBP + ((u64)-208);
	temp_48256._4 = RAM(temp_12800._8)._4;
	EDX = temp_48256._4;
	RDX = EDX;
	ADDR_1011A5:; // ADD EDX,0x8
	++__instruction_count;
	CF = (u32)(EDX + ((u32)8)) < EDX;
	OF = SIGN(4, EDXs) == SIGN(4, ((i32)8)) && SIGN(4, (i32)(EDXs + ((i32)8))) != SIGN(4, ((i32)8));
	EDX = EDX + ((u32)8);
	RDX = EDX;
	SF = EDXs < ((i32)0);
	ZF = EDX == ((u32)0);
	temp_76800._4 = EDX & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_1011A8:; // MOV dword ptr [RBP + -0xd0],EDX
	++__instruction_count;
	temp_12800._8 = RBP + ((u64)-208);
	temp_48256._4 = EDX;
	RAM(temp_12800._8)._4 = temp_48256._4;
	ADDR_1011AE:; // JMP 0x001011c2
	++__instruction_count;
	goto ADDR_1011C2;
	ADDR_1011B0:; // MOV RAX,qword ptr [RBP + -0xc8]
	++__instruction_count;
	temp_12800._8 = RBP + ((u64)-200);
	temp_48512._8 = RAM(temp_12800._8)._8;
	RAX = temp_48512._8;
	ADDR_1011B7:; // LEA RDX,[RAX + 0x8]
	++__instruction_count;
	temp_12544._8 = RAX + ((u64)8);
	RDX = temp_12544._8;
	ADDR_1011BB:; // MOV qword ptr [RBP + -0xc8],RDX
	++__instruction_count;
	temp_12800._8 = RBP + ((u64)-200);
	temp_48512._8 = RDX;
	RAM(temp_12800._8)._8 = temp_48512._8;
	ADDR_1011C2:; // MOV RAX,qword ptr [RAX]
	++__instruction_count;
	temp_48512._8 = RAM(RAX)._8;
	RAX = temp_48512._8;
	ADDR_1011C5:; // MOV qword ptr [RBP + -0xb8],RAX
	++__instruction_count;
	temp_12800._8 = RBP + ((u64)-184);
	temp_48512._8 = RAX;
	RAM(temp_12800._8)._8 = temp_48512._8;
	ADDR_1011CC:; // CMP qword ptr [RBP + -0xb8],0x0
	++__instruction_count;
	temp_12800._8 = RBP + ((u64)-184);
	temp_48640._8 = RAM(temp_12800._8)._8;
	CF = temp_48640._8 < ((u64)0);
	temp_48640._8 = RAM(temp_12800._8)._8;
	OF = SIGN(8, temp_48640._8s) != SIGN(8, ((i64)0)) && SIGN(8, (i64)(temp_48640._8s - ((i64)0))) == SIGN(8, ((i64)0));
	temp_48640._8 = RAM(temp_12800._8)._8;
	temp_164608._8 = temp_48640._8 - ((u64)0);
	SF = temp_164608._8s < ((i64)0);
	ZF = temp_164608._8 == ((u64)0);
	temp_76800._8 = temp_164608._8 & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_1011D4:; // JNZ 0x0010115c
	++__instruction_count;
	temp_50816._1 = !ZF;
	if (temp_50816._1) goto ADDR_10115C;
	ADDR_1011D6:; // NOP
	++__instruction_count;
	
	ADDR_1011D7:; // NOP
	++__instruction_count;
	
	ADDR_1011D8:; // LEAVE
	++__instruction_count;
	RSP = RBP;
	RBP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_1011D9:; // RET
	++__instruction_count;
	RIP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	return;
	
}
