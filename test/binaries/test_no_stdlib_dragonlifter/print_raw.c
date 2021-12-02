#include "dragonlifter.h"

void print_raw() {
	ADDR_4001DE:; // PUSH RBP
	temp_59264._8 = RBP;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_4001DF:; // MOV RBP,RSP
	RBP = RSP;
	ADDR_4001E2:; // SUB RSP,0xe0
	CF = RSP < ((u64)224);
	OF = SIGN(8, RSPs) != SIGN(8, ((i64)224)) && SIGN(8, (i64)(RSPs - ((i64)224))) == SIGN(8, ((i64)224));
	RSP = RSP - ((u64)224);
	SF = RSPs < ((i64)0);
	ZF = RSP == ((u64)0);
	temp_76800._8 = RSP & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_4001E9:; // MOV qword ptr [RBP + -0xd8],RDI
	temp_12800._8 = RBP + ((u64)-216);
	temp_48512._8 = RDI;
	RAM(temp_12800._8)._8 = temp_48512._8;
	ADDR_4001F0:; // MOV qword ptr [RBP + -0xa8],RSI
	temp_12800._8 = RBP + ((u64)-168);
	temp_48512._8 = RSI;
	RAM(temp_12800._8)._8 = temp_48512._8;
	ADDR_4001F7:; // MOV qword ptr [RBP + -0xa0],RDX
	temp_12800._8 = RBP + ((u64)-160);
	temp_48512._8 = RDX;
	RAM(temp_12800._8)._8 = temp_48512._8;
	ADDR_4001FE:; // MOV qword ptr [RBP + -0x98],RCX
	temp_12800._8 = RBP + ((u64)-152);
	temp_48512._8 = RCX;
	RAM(temp_12800._8)._8 = temp_48512._8;
	ADDR_400205:; // MOV qword ptr [RBP + -0x90],R8
	temp_12800._8 = RBP + ((u64)-144);
	temp_48512._8 = R8;
	RAM(temp_12800._8)._8 = temp_48512._8;
	ADDR_40020C:; // MOV qword ptr [RBP + -0x88],R9
	temp_12800._8 = RBP + ((u64)-136);
	temp_48512._8 = R9;
	RAM(temp_12800._8)._8 = temp_48512._8;
	ADDR_400213:; // TEST AL,AL
	CF = ((u8)0);
	OF = ((u8)0);
	temp_364544._1 = AL & AL;
	SF = temp_364544._1s < ((i8)0);
	ZF = temp_364544._1 == ((u8)0);
	temp_76800._1 = temp_364544._1 & ((u8)255);
	temp_76928._1 = POPCOUNT(1, temp_76800._1);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_400215:; // JZ 0x00400237
	if (ZF) goto ADDR_400237;
	ADDR_400217:; // MOVAPS xmmword ptr [RBP + -0x80],XMM0
	temp_12544._8 = RBP + ((u64)-128);
	temp_21248._16 = XMM0;
	RAM(temp_12544._8)._16 = temp_21248._16;
	ADDR_40021B:; // MOVAPS xmmword ptr [RBP + -0x70],XMM1
	temp_12544._8 = RBP + ((u64)-112);
	temp_21248._16 = XMM1;
	RAM(temp_12544._8)._16 = temp_21248._16;
	ADDR_40021F:; // MOVAPS xmmword ptr [RBP + -0x60],XMM2
	temp_12544._8 = RBP + ((u64)-96);
	temp_21248._16 = XMM2;
	RAM(temp_12544._8)._16 = temp_21248._16;
	ADDR_400223:; // MOVAPS xmmword ptr [RBP + -0x50],XMM3
	temp_12544._8 = RBP + ((u64)-80);
	temp_21248._16 = XMM3;
	RAM(temp_12544._8)._16 = temp_21248._16;
	ADDR_400227:; // MOVAPS xmmword ptr [RBP + -0x40],XMM4
	temp_12544._8 = RBP + ((u64)-64);
	temp_21248._16 = XMM4;
	RAM(temp_12544._8)._16 = temp_21248._16;
	ADDR_40022B:; // MOVAPS xmmword ptr [RBP + -0x30],XMM5
	temp_12544._8 = RBP + ((u64)-48);
	temp_21248._16 = XMM5;
	RAM(temp_12544._8)._16 = temp_21248._16;
	ADDR_40022F:; // MOVAPS xmmword ptr [RBP + -0x20],XMM6
	temp_12544._8 = RBP + ((u64)-32);
	temp_21248._16 = XMM6;
	RAM(temp_12544._8)._16 = temp_21248._16;
	ADDR_400233:; // MOVAPS xmmword ptr [RBP + -0x10],XMM7
	temp_12544._8 = RBP + ((u64)-16);
	temp_21248._16 = XMM7;
	RAM(temp_12544._8)._16 = temp_21248._16;
	ADDR_400237:; // MOV dword ptr [RBP + -0xd0],0x8
	temp_12800._8 = RBP + ((u64)-208);
	temp_48384._4 = ((u32)8);
	RAM(temp_12800._8)._4 = temp_48384._4;
	ADDR_400241:; // MOV dword ptr [RBP + -0xcc],0x30
	temp_12800._8 = RBP + ((u64)-204);
	temp_48384._4 = ((u32)48);
	RAM(temp_12800._8)._4 = temp_48384._4;
	ADDR_40024B:; // LEA RAX,[RBP + 0x10]
	temp_12544._8 = RBP + ((u64)16);
	RAX = temp_12544._8;
	ADDR_40024F:; // MOV qword ptr [RBP + -0xc8],RAX
	temp_12800._8 = RBP + ((u64)-200);
	temp_48512._8 = RAX;
	RAM(temp_12800._8)._8 = temp_48512._8;
	ADDR_400256:; // LEA RAX,[RBP + -0xb0]
	temp_12800._8 = RBP + ((u64)-176);
	RAX = temp_12800._8;
	ADDR_40025D:; // MOV qword ptr [RBP + -0xc0],RAX
	temp_12800._8 = RBP + ((u64)-192);
	temp_48512._8 = RAX;
	RAM(temp_12800._8)._8 = temp_48512._8;
	ADDR_400264:; // MOV RAX,qword ptr [RBP + -0xd8]
	temp_12800._8 = RBP + ((u64)-216);
	temp_48512._8 = RAM(temp_12800._8)._8;
	RAX = temp_48512._8;
	ADDR_40026B:; // MOV RDI,RAX
	RDI = RAX;
	ADDR_40026E:; // CALL 0x004001ae
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x400273);
	strlen();
	ADDR_400273:; // MOV RDX,RAX
	RDX = RAX;
	ADDR_400276:; // MOV RAX,qword ptr [RBP + -0xd8]
	temp_12800._8 = RBP + ((u64)-216);
	temp_48512._8 = RAM(temp_12800._8)._8;
	RAX = temp_48512._8;
	ADDR_40027D:; // MOV RSI,RAX
	RSI = RAX;
	ADDR_400280:; // MOV EDI,0x1
	RDI = ((u64)1);
	ADDR_400285:; // CALL 0x00400144
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x40028a);
	write();
	ADDR_40028A:; // JMP 0x004002b2
	goto ADDR_4002B2;
	ADDR_40028C:; // MOV RAX,qword ptr [RBP + -0xb8]
	temp_12800._8 = RBP + ((u64)-184);
	temp_48512._8 = RAM(temp_12800._8)._8;
	RAX = temp_48512._8;
	ADDR_400293:; // MOV RDI,RAX
	RDI = RAX;
	ADDR_400296:; // CALL 0x004001ae
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x40029b);
	strlen();
	ADDR_40029B:; // MOV RDX,RAX
	RDX = RAX;
	ADDR_40029E:; // MOV RAX,qword ptr [RBP + -0xb8]
	temp_12800._8 = RBP + ((u64)-184);
	temp_48512._8 = RAM(temp_12800._8)._8;
	RAX = temp_48512._8;
	ADDR_4002A5:; // MOV RSI,RAX
	RSI = RAX;
	ADDR_4002A8:; // MOV EDI,0x1
	RDI = ((u64)1);
	ADDR_4002AD:; // CALL 0x00400144
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x4002b2);
	write();
	ADDR_4002B2:; // MOV EAX,dword ptr [RBP + -0xd0]
	temp_12800._8 = RBP + ((u64)-208);
	temp_48256._4 = RAM(temp_12800._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_4002B8:; // CMP EAX,0x2f
	CF = EAX < ((u32)47);
	OF = SIGN(4, EAXs) != SIGN(4, ((i32)47)) && SIGN(4, (i32)(EAXs - ((i32)47))) == SIGN(4, ((i32)47));
	temp_164352._4 = EAX - ((u32)47);
	SF = temp_164352._4s < ((i32)0);
	ZF = temp_164352._4 == ((u32)0);
	temp_76800._4 = temp_164352._4 & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_4002BB:; // JA 0x004002e0
	temp_51200._1 = CF || ZF;
	temp_51456._1 = !temp_51200._1;
	if (temp_51456._1) goto ADDR_4002E0;
	ADDR_4002BD:; // MOV RAX,qword ptr [RBP + -0xc0]
	temp_12800._8 = RBP + ((u64)-192);
	temp_48512._8 = RAM(temp_12800._8)._8;
	RAX = temp_48512._8;
	ADDR_4002C4:; // MOV EDX,dword ptr [RBP + -0xd0]
	temp_12800._8 = RBP + ((u64)-208);
	temp_48256._4 = RAM(temp_12800._8)._4;
	EDX = temp_48256._4;
	RDX = EDX;
	ADDR_4002CA:; // MOV EDX,EDX
	EDX = EDX;
	RDX = EDX;
	ADDR_4002CC:; // ADD RAX,RDX
	CF = (u64)(RAX + RDX) < RAX;
	OF = SIGN(8, RAXs) == SIGN(8, RDXs) && SIGN(8, (i64)(RAXs + RDXs)) != SIGN(8, RDXs);
	RAX = RAX + RDX;
	SF = RAXs < ((i64)0);
	ZF = RAX == ((u64)0);
	temp_76800._8 = RAX & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_4002CF:; // MOV EDX,dword ptr [RBP + -0xd0]
	temp_12800._8 = RBP + ((u64)-208);
	temp_48256._4 = RAM(temp_12800._8)._4;
	EDX = temp_48256._4;
	RDX = EDX;
	ADDR_4002D5:; // ADD EDX,0x8
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
	ADDR_4002D8:; // MOV dword ptr [RBP + -0xd0],EDX
	temp_12800._8 = RBP + ((u64)-208);
	temp_48256._4 = EDX;
	RAM(temp_12800._8)._4 = temp_48256._4;
	ADDR_4002DE:; // JMP 0x004002f2
	goto ADDR_4002F2;
	ADDR_4002E0:; // MOV RAX,qword ptr [RBP + -0xc8]
	temp_12800._8 = RBP + ((u64)-200);
	temp_48512._8 = RAM(temp_12800._8)._8;
	RAX = temp_48512._8;
	ADDR_4002E7:; // LEA RDX,[RAX + 0x8]
	temp_12544._8 = RAX + ((u64)8);
	RDX = temp_12544._8;
	ADDR_4002EB:; // MOV qword ptr [RBP + -0xc8],RDX
	temp_12800._8 = RBP + ((u64)-200);
	temp_48512._8 = RDX;
	RAM(temp_12800._8)._8 = temp_48512._8;
	ADDR_4002F2:; // MOV RAX,qword ptr [RAX]
	temp_48512._8 = RAM(RAX)._8;
	RAX = temp_48512._8;
	ADDR_4002F5:; // MOV qword ptr [RBP + -0xb8],RAX
	temp_12800._8 = RBP + ((u64)-184);
	temp_48512._8 = RAX;
	RAM(temp_12800._8)._8 = temp_48512._8;
	ADDR_4002FC:; // CMP qword ptr [RBP + -0xb8],0x0
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
	ADDR_400304:; // JNZ 0x0040028c
	temp_50816._1 = !ZF;
	if (temp_50816._1) goto ADDR_40028C;
	ADDR_400306:; // NOP
	
	ADDR_400307:; // LEAVE
	RSP = RBP;
	RBP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_400308:; // RET
	RIP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	return;
	
}
