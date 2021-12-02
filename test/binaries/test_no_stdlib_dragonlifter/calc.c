#include "dragonlifter.h"

void calc() {
	ADDR_400779:; // PUSH RBP
	temp_59264._8 = RBP;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_40077A:; // MOV RBP,RSP
	RBP = RSP;
	ADDR_40077D:; // PUSH R12
	temp_59264._8 = R12;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_40077F:; // PUSH RBX
	temp_59264._8 = RBX;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_400780:; // SUB RSP,0x40
	CF = RSP < ((u64)64);
	OF = SIGN(8, RSPs) != SIGN(8, ((i64)64)) && SIGN(8, (i64)(RSPs - ((i64)64))) == SIGN(8, ((i64)64));
	RSP = RSP - ((u64)64);
	SF = RSPs < ((i64)0);
	ZF = RSP == ((u64)0);
	temp_76800._8 = RSP & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_400784:; // MOV EDX,0x0
	RDX = ((u64)0);
	ADDR_400789:; // LEA RSI,[0x400bb8]
	RSI = ((u64)0x400bb8);
	ADDR_400790:; // LEA RDI,[0x400bc0]
	RDI = ((u64)0x400bc0);
	ADDR_400797:; // MOV EAX,0x0
	RAX = ((u64)0);
	ADDR_40079C:; // CALL 0x004001de
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x4007a1);
	print_raw();
	ADDR_4007A1:; // LEA RDI,[0x400be4]
	RDI = ((u64)0x400be4);
	ADDR_4007A8:; // CALL 0x004003a3
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x4007ad);
	input_prompt();
	ADDR_4007AD:; // MOV RDI,RAX
	RDI = RAX;
	ADDR_4007B0:; // CALL 0x0040060a
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x4007b5);
	string_to_int();
	ADDR_4007B5:; // MOV dword ptr [RBP + -0x18],EAX
	temp_12544._8 = RBP + ((u64)-24);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_4007B8:; // LEA RDI,[0x400bf2]
	RDI = ((u64)0x400bf2);
	ADDR_4007BF:; // CALL 0x004003a3
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x4007c4);
	input_prompt();
	ADDR_4007C4:; // MOV qword ptr [RBP + -0x20],RAX
	temp_12544._8 = RBP + ((u64)-32);
	temp_48512._8 = RAX;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_4007C8:; // LEA RDI,[0x400bfe]
	RDI = ((u64)0x400bfe);
	ADDR_4007CF:; // CALL 0x004003a3
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x4007d4);
	input_prompt();
	ADDR_4007D4:; // MOV RDI,RAX
	RDI = RAX;
	ADDR_4007D7:; // CALL 0x0040060a
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x4007dc);
	string_to_int();
	ADDR_4007DC:; // MOV dword ptr [RBP + -0x24],EAX
	temp_12544._8 = RBP + ((u64)-36);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_4007DF:; // MOV RAX,qword ptr [RBP + -0x20]
	temp_12544._8 = RBP + ((u64)-32);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RAX = temp_48512._8;
	ADDR_4007E3:; // MOVZX EAX,byte ptr [RAX]
	temp_47872._1 = RAM(RAX)._1;
	EAX = temp_47872._1;
	RAX = EAX;
	ADDR_4007E6:; // MOVSX EAX,AL
	EAXs = ALs;
	RAX = EAX;
	ADDR_4007E9:; // CMP EAX,0x2b
	CF = EAX < ((u32)43);
	OF = SIGN(4, EAXs) != SIGN(4, ((i32)43)) && SIGN(4, (i32)(EAXs - ((i32)43))) == SIGN(4, ((i32)43));
	temp_164352._4 = EAX - ((u32)43);
	SF = temp_164352._4s < ((i32)0);
	ZF = temp_164352._4 == ((u32)0);
	temp_76800._4 = temp_164352._4 & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_4007EC:; // JZ 0x00400806
	if (ZF) goto ADDR_400806;
	ADDR_4007EE:; // CMP EAX,0x2b
	CF = EAX < ((u32)43);
	OF = SIGN(4, EAXs) != SIGN(4, ((i32)43)) && SIGN(4, (i32)(EAXs - ((i32)43))) == SIGN(4, ((i32)43));
	temp_164352._4 = EAX - ((u32)43);
	SF = temp_164352._4s < ((i32)0);
	ZF = temp_164352._4 == ((u32)0);
	temp_76800._4 = temp_164352._4 & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_4007F1:; // JG 0x004007fa
	temp_52992._1 = !ZF;
	temp_53120._1 = OF == SF;
	temp_53376._1 = temp_52992._1 && temp_53120._1;
	if (temp_53376._1) goto ADDR_4007FA;
	ADDR_4007F3:; // CMP EAX,0x2a
	CF = EAX < ((u32)42);
	OF = SIGN(4, EAXs) != SIGN(4, ((i32)42)) && SIGN(4, (i32)(EAXs - ((i32)42))) == SIGN(4, ((i32)42));
	temp_164352._4 = EAX - ((u32)42);
	SF = temp_164352._4s < ((i32)0);
	ZF = temp_164352._4 == ((u32)0);
	temp_76800._4 = temp_164352._4 & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_4007F6:; // JZ 0x0040081e
	if (ZF) goto ADDR_40081E;
	ADDR_4007F8:; // JMP 0x00400835
	goto ADDR_400835;
	ADDR_4007FA:; // CMP EAX,0x2d
	CF = EAX < ((u32)45);
	OF = SIGN(4, EAXs) != SIGN(4, ((i32)45)) && SIGN(4, (i32)(EAXs - ((i32)45))) == SIGN(4, ((i32)45));
	temp_164352._4 = EAX - ((u32)45);
	SF = temp_164352._4s < ((i32)0);
	ZF = temp_164352._4 == ((u32)0);
	temp_76800._4 = temp_164352._4 & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_4007FD:; // JZ 0x00400813
	if (ZF) goto ADDR_400813;
	ADDR_4007FF:; // CMP EAX,0x2f
	CF = EAX < ((u32)47);
	OF = SIGN(4, EAXs) != SIGN(4, ((i32)47)) && SIGN(4, (i32)(EAXs - ((i32)47))) == SIGN(4, ((i32)47));
	temp_164352._4 = EAX - ((u32)47);
	SF = temp_164352._4s < ((i32)0);
	ZF = temp_164352._4 == ((u32)0);
	temp_76800._4 = temp_164352._4 & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_400802:; // JZ 0x0040082a
	if (ZF) goto ADDR_40082A;
	ADDR_400804:; // JMP 0x00400835
	goto ADDR_400835;
	ADDR_400806:; // MOV EDX,dword ptr [RBP + -0x18]
	temp_12544._8 = RBP + ((u64)-24);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EDX = temp_48256._4;
	RDX = EDX;
	ADDR_400809:; // MOV EAX,dword ptr [RBP + -0x24]
	temp_12544._8 = RBP + ((u64)-36);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_40080C:; // ADD EAX,EDX
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
	ADDR_40080E:; // MOV dword ptr [RBP + -0x14],EAX
	temp_12544._8 = RBP + ((u64)-20);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_400811:; // JMP 0x00400835
	goto ADDR_400835;
	ADDR_400813:; // MOV EAX,dword ptr [RBP + -0x18]
	temp_12544._8 = RBP + ((u64)-24);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_400816:; // SUB EAX,dword ptr [RBP + -0x24]
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
	ADDR_400819:; // MOV dword ptr [RBP + -0x14],EAX
	temp_12544._8 = RBP + ((u64)-20);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_40081C:; // JMP 0x00400835
	goto ADDR_400835;
	ADDR_40081E:; // MOV EAX,dword ptr [RBP + -0x18]
	temp_12544._8 = RBP + ((u64)-24);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_400821:; // IMUL EAX,dword ptr [RBP + -0x24]
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
	ADDR_400825:; // MOV dword ptr [RBP + -0x14],EAX
	temp_12544._8 = RBP + ((u64)-20);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_400828:; // JMP 0x00400835
	goto ADDR_400835;
	ADDR_40082A:; // MOV EAX,dword ptr [RBP + -0x18]
	temp_12544._8 = RBP + ((u64)-24);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_40082D:; // CDQ
	temp_160768._8s = EAXs;
	EDX = (temp_160768._8 / 0x100000000);
	RDX = EDX;
	ADDR_40082E:; // IDIV dword ptr [RBP + -0x24]
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
	ADDR_400831:; // MOV dword ptr [RBP + -0x14],EAX
	temp_12544._8 = RBP + ((u64)-20);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_400834:; // NOP
	
	ADDR_400835:; // MOV EAX,dword ptr [RBP + -0x14]
	temp_12544._8 = RBP + ((u64)-20);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_400838:; // MOV EDI,EAX
	EDI = EAX;
	RDI = EDI;
	ADDR_40083A:; // CALL 0x004003d2
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x40083f);
	int_to_string();
	ADDR_40083F:; // MOV RBX,RAX
	RBX = RAX;
	ADDR_400842:; // MOV EAX,dword ptr [RBP + -0x24]
	temp_12544._8 = RBP + ((u64)-36);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_400845:; // MOV EDI,EAX
	EDI = EAX;
	RDI = EDI;
	ADDR_400847:; // CALL 0x004003d2
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x40084c);
	int_to_string();
	ADDR_40084C:; // MOV R12,RAX
	R12 = RAX;
	ADDR_40084F:; // MOV EAX,dword ptr [RBP + -0x18]
	temp_12544._8 = RBP + ((u64)-24);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_400852:; // MOV EDI,EAX
	EDI = EAX;
	RDI = EDI;
	ADDR_400854:; // CALL 0x004003d2
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x400859);
	int_to_string();
	ADDR_400859:; // MOV RDI,RAX
	RDI = RAX;
	ADDR_40085C:; // MOV RAX,qword ptr [RBP + -0x20]
	temp_12544._8 = RBP + ((u64)-32);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RAX = temp_48512._8;
	ADDR_400860:; // SUB RSP,0x8
	CF = RSP < ((u64)8);
	OF = SIGN(8, RSPs) != SIGN(8, ((i64)8)) && SIGN(8, (i64)(RSPs - ((i64)8))) == SIGN(8, ((i64)8));
	RSP = RSP - ((u64)8);
	SF = RSPs < ((i64)0);
	ZF = RSP == ((u64)0);
	temp_76800._8 = RSP & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_400864:; // PUSH 0x0
	temp_259968._8 = ((u64)0);
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_259968._8;
	ADDR_400866:; // LEA RDX,[0x400bb8]
	RDX = ((u64)0x400bb8);
	ADDR_40086D:; // PUSH RDX
	temp_59264._8 = RDX;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_40086E:; // PUSH RBX
	temp_59264._8 = RBX;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_40086F:; // LEA R9,[0x400c0d]
	R9 = ((u64)0x400c0d);
	ADDR_400876:; // MOV R8,R12
	R8 = R12;
	ADDR_400879:; // LEA RCX,[0x400c11]
	RCX = ((u64)0x400c11);
	ADDR_400880:; // MOV RDX,RAX
	RDX = RAX;
	ADDR_400883:; // LEA RSI,[0x400c11]
	RSI = ((u64)0x400c11);
	ADDR_40088A:; // MOV EAX,0x0
	RAX = ((u64)0);
	ADDR_40088F:; // CALL 0x004001de
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x400894);
	print_raw();
	ADDR_400894:; // ADD RSP,0x20
	CF = (u64)(RSP + ((u64)32)) < RSP;
	OF = SIGN(8, RSPs) == SIGN(8, ((i64)32)) && SIGN(8, (i64)(RSPs + ((i64)32))) != SIGN(8, ((i64)32));
	RSP = RSP + ((u64)32);
	SF = RSPs < ((i64)0);
	ZF = RSP == ((u64)0);
	temp_76800._8 = RSP & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_400898:; // NOP
	
	ADDR_400899:; // LEA RSP,[RBP + -0x10]
	temp_12544._8 = RBP + ((u64)-16);
	RSP = temp_12544._8;
	ADDR_40089D:; // POP RBX
	RBX = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_40089E:; // POP R12
	R12 = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_4008A0:; // POP RBP
	RBP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_4008A1:; // RET
	RIP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	return;
	
}
