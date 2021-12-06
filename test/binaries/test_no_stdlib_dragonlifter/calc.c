#include "dragonlifter.h"

void calc() {
	ADDR_101655:; // ENDBR64
	
	ADDR_101659:; // PUSH RBP
	temp_59264._8 = RBP;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_10165A:; // MOV RBP,RSP
	RBP = RSP;
	ADDR_10165D:; // PUSH R12
	temp_59264._8 = R12;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_10165F:; // PUSH RBX
	temp_59264._8 = RBX;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_101660:; // SUB RSP,0x40
	CF = RSP < ((u64)64);
	OF = SIGN(8, RSPs) != SIGN(8, ((i64)64)) && SIGN(8, (i64)(RSPs - ((i64)64))) == SIGN(8, ((i64)64));
	RSP = RSP - ((u64)64);
	SF = RSPs < ((i64)0);
	ZF = RSP == ((u64)0);
	temp_76800._8 = RSP & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_101664:; // MOV EDX,0x0
	RDX = ((u64)0);
	ADDR_101669:; // LEA RSI,[0x102000]
	RSI = ((u64)0x102000);
	ADDR_101670:; // LEA RDI,[0x102008]
	RDI = ((u64)0x102008);
	ADDR_101677:; // MOV EAX,0x0
	RAX = ((u64)0);
	ADDR_10167C:; // CALL 0x001010aa
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x101681);
	print_raw();
	ADDR_101681:; // LEA RDI,[0x10202c]
	RDI = ((u64)0x10202c);
	ADDR_101688:; // CALL 0x00101279
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x10168d);
	input_prompt();
	ADDR_10168D:; // MOV RDI,RAX
	RDI = RAX;
	ADDR_101690:; // CALL 0x001014e4
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x101695);
	string_to_int();
	ADDR_101695:; // MOV dword ptr [RBP + -0x18],EAX
	temp_12544._8 = RBP + ((u64)-24);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_101698:; // LEA RDI,[0x10203a]
	RDI = ((u64)0x10203a);
	ADDR_10169F:; // CALL 0x00101279
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x1016a4);
	input_prompt();
	ADDR_1016A4:; // MOV qword ptr [RBP + -0x20],RAX
	temp_12544._8 = RBP + ((u64)-32);
	temp_48512._8 = RAX;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_1016A8:; // LEA RDI,[0x102046]
	RDI = ((u64)0x102046);
	ADDR_1016AF:; // CALL 0x00101279
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x1016b4);
	input_prompt();
	ADDR_1016B4:; // MOV RDI,RAX
	RDI = RAX;
	ADDR_1016B7:; // CALL 0x001014e4
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x1016bc);
	string_to_int();
	ADDR_1016BC:; // MOV dword ptr [RBP + -0x24],EAX
	temp_12544._8 = RBP + ((u64)-36);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_1016BF:; // MOV RAX,qword ptr [RBP + -0x20]
	temp_12544._8 = RBP + ((u64)-32);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RAX = temp_48512._8;
	ADDR_1016C3:; // MOVZX EAX,byte ptr [RAX]
	temp_47872._1 = RAM(RAX)._1;
	EAX = temp_47872._1;
	RAX = EAX;
	ADDR_1016C6:; // MOVSX EAX,AL
	EAXs = ALs;
	RAX = EAX;
	ADDR_1016C9:; // CMP EAX,0x2f
	CF = EAX < ((u32)47);
	OF = SIGN(4, EAXs) != SIGN(4, ((i32)47)) && SIGN(4, (i32)(EAXs - ((i32)47))) == SIGN(4, ((i32)47));
	temp_164352._4 = EAX - ((u32)47);
	SF = temp_164352._4s < ((i32)0);
	ZF = temp_164352._4 == ((u32)0);
	temp_76800._4 = temp_164352._4 & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_1016CC:; // JZ 0x0010170b
	if (ZF) goto ADDR_10170B;
	ADDR_1016CE:; // CMP EAX,0x2f
	CF = EAX < ((u32)47);
	OF = SIGN(4, EAXs) != SIGN(4, ((i32)47)) && SIGN(4, (i32)(EAXs - ((i32)47))) == SIGN(4, ((i32)47));
	temp_164352._4 = EAX - ((u32)47);
	SF = temp_164352._4s < ((i32)0);
	ZF = temp_164352._4 == ((u32)0);
	temp_76800._4 = temp_164352._4 & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_1016D1:; // JG 0x00101716
	temp_52992._1 = !ZF;
	temp_53120._1 = OF == SF;
	temp_53376._1 = temp_52992._1 && temp_53120._1;
	if (temp_53376._1) goto ADDR_101716;
	ADDR_1016D3:; // CMP EAX,0x2d
	CF = EAX < ((u32)45);
	OF = SIGN(4, EAXs) != SIGN(4, ((i32)45)) && SIGN(4, (i32)(EAXs - ((i32)45))) == SIGN(4, ((i32)45));
	temp_164352._4 = EAX - ((u32)45);
	SF = temp_164352._4s < ((i32)0);
	ZF = temp_164352._4 == ((u32)0);
	temp_76800._4 = temp_164352._4 & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_1016D6:; // JZ 0x001016f4
	if (ZF) goto ADDR_1016F4;
	ADDR_1016D8:; // CMP EAX,0x2d
	CF = EAX < ((u32)45);
	OF = SIGN(4, EAXs) != SIGN(4, ((i32)45)) && SIGN(4, (i32)(EAXs - ((i32)45))) == SIGN(4, ((i32)45));
	temp_164352._4 = EAX - ((u32)45);
	SF = temp_164352._4s < ((i32)0);
	ZF = temp_164352._4 == ((u32)0);
	temp_76800._4 = temp_164352._4 & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_1016DB:; // JG 0x00101716
	temp_52992._1 = !ZF;
	temp_53120._1 = OF == SF;
	temp_53376._1 = temp_52992._1 && temp_53120._1;
	if (temp_53376._1) goto ADDR_101716;
	ADDR_1016DD:; // CMP EAX,0x2a
	CF = EAX < ((u32)42);
	OF = SIGN(4, EAXs) != SIGN(4, ((i32)42)) && SIGN(4, (i32)(EAXs - ((i32)42))) == SIGN(4, ((i32)42));
	temp_164352._4 = EAX - ((u32)42);
	SF = temp_164352._4s < ((i32)0);
	ZF = temp_164352._4 == ((u32)0);
	temp_76800._4 = temp_164352._4 & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_1016E0:; // JZ 0x001016ff
	if (ZF) goto ADDR_1016FF;
	ADDR_1016E2:; // CMP EAX,0x2b
	CF = EAX < ((u32)43);
	OF = SIGN(4, EAXs) != SIGN(4, ((i32)43)) && SIGN(4, (i32)(EAXs - ((i32)43))) == SIGN(4, ((i32)43));
	temp_164352._4 = EAX - ((u32)43);
	SF = temp_164352._4s < ((i32)0);
	ZF = temp_164352._4 == ((u32)0);
	temp_76800._4 = temp_164352._4 & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_1016E5:; // JNZ 0x00101716
	temp_50816._1 = !ZF;
	if (temp_50816._1) goto ADDR_101716;
	ADDR_1016E7:; // MOV EDX,dword ptr [RBP + -0x18]
	temp_12544._8 = RBP + ((u64)-24);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EDX = temp_48256._4;
	RDX = EDX;
	ADDR_1016EA:; // MOV EAX,dword ptr [RBP + -0x24]
	temp_12544._8 = RBP + ((u64)-36);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_1016ED:; // ADD EAX,EDX
	CF = (u32)(EAX + EDX) < EAX;
	OF = SIGN(4, EAXs) == SIGN(4, EDXs) && SIGN(4, (i32)(EAXs + EDXs)) != SIGN(4, EDXs);
	EAX = EAX + EDX;
	RAX = EAX;
	SF = EAXs < ((i32)0);
	ZF = EAX == ((u32)0);
	temp_76800._4 = EAX & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_1016EF:; // MOV dword ptr [RBP + -0x14],EAX
	temp_12544._8 = RBP + ((u64)-20);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_1016F2:; // JMP 0x00101716
	goto ADDR_101716;
	ADDR_1016F4:; // MOV EAX,dword ptr [RBP + -0x18]
	temp_12544._8 = RBP + ((u64)-24);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_1016F7:; // SUB EAX,dword ptr [RBP + -0x24]
	temp_12544._8 = RBP + ((u64)-36);
	temp_48256._4 = RAM(temp_12544._8)._4;
	CF = EAX < temp_48256._4;
	temp_48256._4 = RAM(temp_12544._8)._4;
	OF = SIGN(4, EAXs) != SIGN(4, temp_48256._4s) && SIGN(4, (i32)(EAXs - temp_48256._4s)) == SIGN(4, temp_48256._4s);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = EAX - temp_48256._4;
	RAX = EAX;
	SF = EAXs < ((i32)0);
	ZF = EAX == ((u32)0);
	temp_76800._4 = EAX & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_1016FA:; // MOV dword ptr [RBP + -0x14],EAX
	temp_12544._8 = RBP + ((u64)-20);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_1016FD:; // JMP 0x00101716
	goto ADDR_101716;
	ADDR_1016FF:; // MOV EAX,dword ptr [RBP + -0x18]
	temp_12544._8 = RBP + ((u64)-24);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_101702:; // IMUL EAX,dword ptr [RBP + -0x24]
	temp_12544._8 = RBP + ((u64)-36);
	temp_219904._8s = EAXs;
	temp_48256._4 = RAM(temp_12544._8)._4;
	temp_220032._8s = temp_48256._4s;
	temp_220288._8 = temp_219904._8 * temp_220032._8;
	EAX = (temp_220288._8 / 0x1);
	temp_220672._4 = (temp_220288._8 / 0x100000000);
	temp_80768._8s = EAXs;
	CF = temp_80768._8 != temp_220288._8;
	OF = CF;
	RAX = EAX;
	ADDR_101706:; // MOV dword ptr [RBP + -0x14],EAX
	temp_12544._8 = RBP + ((u64)-20);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_101709:; // JMP 0x00101716
	goto ADDR_101716;
	ADDR_10170B:; // MOV EAX,dword ptr [RBP + -0x18]
	temp_12544._8 = RBP + ((u64)-24);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_10170E:; // CDQ
	temp_160768._8s = EAXs;
	EDX = (temp_160768._8 / 0x100000000);
	RDX = EDX;
	ADDR_10170F:; // IDIV dword ptr [RBP + -0x24]
	temp_12544._8 = RBP + ((u64)-36);
	temp_48256._4 = RAM(temp_12544._8)._4;
	temp_213120._8s = temp_48256._4s;
	temp_213248._8 = EDX;
	temp_213376._8 = temp_213248._8 << ((u32)32);
	temp_213504._8 = EAX;
	temp_213760._8 = temp_213376._8 | temp_213504._8;
	temp_214016._8s = temp_213760._8s / temp_213120._8s;
	EAX = (temp_214016._8 / 0x1);
	RAX = EAX;
	temp_214400._8s = temp_213760._8s % temp_213120._8s;
	EDX = (temp_214400._8 / 0x1);
	RDX = EDX;
	ADDR_101712:; // MOV dword ptr [RBP + -0x14],EAX
	temp_12544._8 = RBP + ((u64)-20);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_101715:; // NOP
	
	ADDR_101716:; // MOV EAX,dword ptr [RBP + -0x14]
	temp_12544._8 = RBP + ((u64)-20);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_101719:; // MOV EDI,EAX
	EDI = EAX;
	RDI = EDI;
	ADDR_10171B:; // CALL 0x001012ac
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x101720);
	int_to_string();
	ADDR_101720:; // MOV RBX,RAX
	RBX = RAX;
	ADDR_101723:; // MOV EAX,dword ptr [RBP + -0x24]
	temp_12544._8 = RBP + ((u64)-36);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_101726:; // MOV EDI,EAX
	EDI = EAX;
	RDI = EDI;
	ADDR_101728:; // CALL 0x001012ac
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x10172d);
	int_to_string();
	ADDR_10172D:; // MOV R12,RAX
	R12 = RAX;
	ADDR_101730:; // MOV EAX,dword ptr [RBP + -0x18]
	temp_12544._8 = RBP + ((u64)-24);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_101733:; // MOV EDI,EAX
	EDI = EAX;
	RDI = EDI;
	ADDR_101735:; // CALL 0x001012ac
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x10173a);
	int_to_string();
	ADDR_10173A:; // MOV RDI,RAX
	RDI = RAX;
	ADDR_10173D:; // MOV RAX,qword ptr [RBP + -0x20]
	temp_12544._8 = RBP + ((u64)-32);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RAX = temp_48512._8;
	ADDR_101741:; // SUB RSP,0x8
	CF = RSP < ((u64)8);
	OF = SIGN(8, RSPs) != SIGN(8, ((i64)8)) && SIGN(8, (i64)(RSPs - ((i64)8))) == SIGN(8, ((i64)8));
	RSP = RSP - ((u64)8);
	SF = RSPs < ((i64)0);
	ZF = RSP == ((u64)0);
	temp_76800._8 = RSP & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_101745:; // PUSH 0x0
	temp_259968._8 = ((u64)0);
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_259968._8;
	ADDR_101747:; // LEA RDX,[0x102000]
	RDX = ((u64)0x102000);
	ADDR_10174E:; // PUSH RDX
	temp_59264._8 = RDX;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_10174F:; // PUSH RBX
	temp_59264._8 = RBX;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_101750:; // LEA R9,[0x102055]
	R9 = ((u64)0x102055);
	ADDR_101757:; // MOV R8,R12
	R8 = R12;
	ADDR_10175A:; // LEA RCX,[0x102059]
	RCX = ((u64)0x102059);
	ADDR_101761:; // MOV RDX,RAX
	RDX = RAX;
	ADDR_101764:; // LEA RSI,[0x102059]
	RSI = ((u64)0x102059);
	ADDR_10176B:; // MOV EAX,0x0
	RAX = ((u64)0);
	ADDR_101770:; // CALL 0x001010aa
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x101775);
	print_raw();
	ADDR_101775:; // ADD RSP,0x20
	CF = (u64)(RSP + ((u64)32)) < RSP;
	OF = SIGN(8, RSPs) == SIGN(8, ((i64)32)) && SIGN(8, (i64)(RSPs + ((i64)32))) != SIGN(8, ((i64)32));
	RSP = RSP + ((u64)32);
	SF = RSPs < ((i64)0);
	ZF = RSP == ((u64)0);
	temp_76800._8 = RSP & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_101779:; // NOP
	
	ADDR_10177A:; // LEA RSP,[RBP + -0x10]
	temp_12544._8 = RBP + ((u64)-16);
	RSP = temp_12544._8;
	ADDR_10177E:; // POP RBX
	RBX = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_10177F:; // POP R12
	R12 = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_101781:; // POP RBP
	RBP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_101782:; // RET
	RIP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	return;
	
}
