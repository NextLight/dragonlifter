#include "dragonlifter.h"

void calc_bitwise() {
	ADDR_4008D8:; // PUSH RBP
	temp_59264._8 = RBP;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_4008D9:; // MOV RBP,RSP
	RBP = RSP;
	ADDR_4008DC:; // PUSH R15
	temp_59264._8 = R15;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_4008DE:; // PUSH R14
	temp_59264._8 = R14;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_4008E0:; // PUSH R13
	temp_59264._8 = R13;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_4008E2:; // PUSH R12
	temp_59264._8 = R12;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_4008E4:; // PUSH RBX
	temp_59264._8 = RBX;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_4008E5:; // SUB RSP,0x48
	CF = RSP < ((u64)72);
	OF = SIGN(8, RSPs) != SIGN(8, ((i64)72)) && SIGN(8, (i64)(RSPs - ((i64)72))) == SIGN(8, ((i64)72));
	RSP = RSP - ((u64)72);
	SF = RSPs < ((i64)0);
	ZF = RSP == ((u64)0);
	temp_76800._8 = RSP & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_4008E9:; // MOV EDX,0x0
	RDX = ((u64)0);
	ADDR_4008EE:; // LEA RSI,[0x400bb8]
	RSI = ((u64)0x400bb8);
	ADDR_4008F5:; // LEA RDI,[0x400c18]
	RDI = ((u64)0x400c18);
	ADDR_4008FC:; // MOV EAX,0x0
	RAX = ((u64)0);
	ADDR_400901:; // CALL 0x004001de
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x400906);
	print_raw();
	ADDR_400906:; // LEA RDI,[0x400be4]
	RDI = ((u64)0x400be4);
	ADDR_40090D:; // CALL 0x004003a3
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x400912);
	input_prompt();
	ADDR_400912:; // MOV RDI,RAX
	RDI = RAX;
	ADDR_400915:; // CALL 0x0040060a
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x40091a);
	string_to_int();
	ADDR_40091A:; // MOV dword ptr [RBP + -0x3c],EAX
	temp_12544._8 = RBP + ((u64)-60);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_40091D:; // LEA RDI,[0x400bf2]
	RDI = ((u64)0x400bf2);
	ADDR_400924:; // CALL 0x004003a3
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x400929);
	input_prompt();
	ADDR_400929:; // MOV qword ptr [RBP + -0x48],RAX
	temp_12544._8 = RBP + ((u64)-72);
	temp_48512._8 = RAX;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_40092D:; // LEA RDI,[0x400bfe]
	RDI = ((u64)0x400bfe);
	ADDR_400934:; // CALL 0x004003a3
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x400939);
	input_prompt();
	ADDR_400939:; // MOV RDI,RAX
	RDI = RAX;
	ADDR_40093C:; // CALL 0x0040060a
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x400941);
	string_to_int();
	ADDR_400941:; // MOV dword ptr [RBP + -0x4c],EAX
	temp_12544._8 = RBP + ((u64)-76);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_400944:; // MOV RAX,qword ptr [RBP + -0x48]
	temp_12544._8 = RBP + ((u64)-72);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RAX = temp_48512._8;
	ADDR_400948:; // MOVZX EAX,byte ptr [RAX]
	temp_47872._1 = RAM(RAX)._1;
	EAX = temp_47872._1;
	RAX = EAX;
	ADDR_40094B:; // MOVSX EAX,AL
	EAXs = ALs;
	RAX = EAX;
	ADDR_40094E:; // CMP EAX,0x5e
	CF = EAX < ((u32)94);
	OF = SIGN(4, EAXs) != SIGN(4, ((i32)94)) && SIGN(4, (i32)(EAXs - ((i32)94))) == SIGN(4, ((i32)94));
	temp_164352._4 = EAX - ((u32)94);
	SF = temp_164352._4s < ((i32)0);
	ZF = temp_164352._4 == ((u32)0);
	temp_76800._4 = temp_164352._4 & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_400951:; // JZ 0x00400977
	if (ZF) goto ADDR_400977;
	ADDR_400953:; // CMP EAX,0x7c
	CF = EAX < ((u32)124);
	OF = SIGN(4, EAXs) != SIGN(4, ((i32)124)) && SIGN(4, (i32)(EAXs - ((i32)124))) == SIGN(4, ((i32)124));
	temp_164352._4 = EAX - ((u32)124);
	SF = temp_164352._4s < ((i32)0);
	ZF = temp_164352._4 == ((u32)0);
	temp_76800._4 = temp_164352._4 & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_400956:; // JZ 0x0040096a
	if (ZF) goto ADDR_40096A;
	ADDR_400958:; // CMP EAX,0x26
	CF = EAX < ((u32)38);
	OF = SIGN(4, EAXs) != SIGN(4, ((i32)38)) && SIGN(4, (i32)(EAXs - ((i32)38))) == SIGN(4, ((i32)38));
	temp_164352._4 = EAX - ((u32)38);
	SF = temp_164352._4s < ((i32)0);
	ZF = temp_164352._4 == ((u32)0);
	temp_76800._4 = temp_164352._4 & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_40095B:; // JNZ 0x00400983
	temp_50816._1 = !ZF;
	if (temp_50816._1) goto ADDR_400983;
	ADDR_40095D:; // LEA RAX,[0x4008a2]
	RAX = ((u64)0x4008a2);
	ADDR_400964:; // MOV qword ptr [RBP + -0x38],RAX
	temp_12544._8 = RBP + ((u64)-56);
	temp_48512._8 = RAX;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_400968:; // JMP 0x00400983
	goto ADDR_400983;
	ADDR_40096A:; // LEA RAX,[0x4008b4]
	RAX = ((u64)0x4008b4);
	ADDR_400971:; // MOV qword ptr [RBP + -0x38],RAX
	temp_12544._8 = RBP + ((u64)-56);
	temp_48512._8 = RAX;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_400975:; // JMP 0x00400983
	goto ADDR_400983;
	ADDR_400977:; // LEA RAX,[0x4008c6]
	RAX = ((u64)0x4008c6);
	ADDR_40097E:; // MOV qword ptr [RBP + -0x38],RAX
	temp_12544._8 = RBP + ((u64)-56);
	temp_48512._8 = RAX;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_400982:; // NOP
	
	ADDR_400983:; // MOV ECX,dword ptr [RBP + -0x4c]
	temp_12544._8 = RBP + ((u64)-76);
	temp_48256._4 = RAM(temp_12544._8)._4;
	ECX = temp_48256._4;
	RCX = ECX;
	ADDR_400986:; // MOV EDX,dword ptr [RBP + -0x3c]
	temp_12544._8 = RBP + ((u64)-60);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EDX = temp_48256._4;
	RDX = EDX;
	ADDR_400989:; // MOV RAX,qword ptr [RBP + -0x38]
	temp_12544._8 = RBP + ((u64)-56);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RAX = temp_48512._8;
	ADDR_40098D:; // MOV ESI,ECX
	ESI = ECX;
	RSI = ESI;
	ADDR_40098F:; // MOV EDI,EDX
	EDI = EDX;
	RDI = EDI;
	ADDR_400991:; // CALL RAX
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x400993);
	//NOT-IMPL: Pcode(op=<Op.CALLIND: 8>, output=None, input=[Varnode(type=REGISTER, value=0, size=8)])
	ADDR_400993:; // MOV dword ptr [RBP + -0x50],EAX
	temp_12544._8 = RBP + ((u64)-80);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_400996:; // MOV EAX,dword ptr [RBP + -0x50]
	temp_12544._8 = RBP + ((u64)-80);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_400999:; // MOV EDI,EAX
	EDI = EAX;
	RDI = EDI;
	ADDR_40099B:; // CALL 0x00400681
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x4009a0);
	bin();
	ADDR_4009A0:; // MOV R14,RAX
	R14 = RAX;
	ADDR_4009A3:; // MOV EAX,dword ptr [RBP + -0x50]
	temp_12544._8 = RBP + ((u64)-80);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_4009A6:; // MOV EDI,EAX
	EDI = EAX;
	RDI = EDI;
	ADDR_4009A8:; // CALL 0x004003d2
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x4009ad);
	int_to_string();
	ADDR_4009AD:; // MOV R13,RAX
	R13 = RAX;
	ADDR_4009B0:; // MOV EAX,dword ptr [RBP + -0x4c]
	temp_12544._8 = RBP + ((u64)-76);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_4009B3:; // MOV EDI,EAX
	EDI = EAX;
	RDI = EDI;
	ADDR_4009B5:; // CALL 0x00400681
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x4009ba);
	bin();
	ADDR_4009BA:; // MOV R12,RAX
	R12 = RAX;
	ADDR_4009BD:; // MOV EAX,dword ptr [RBP + -0x4c]
	temp_12544._8 = RBP + ((u64)-76);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_4009C0:; // MOV EDI,EAX
	EDI = EAX;
	RDI = EDI;
	ADDR_4009C2:; // CALL 0x004003d2
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x4009c7);
	int_to_string();
	ADDR_4009C7:; // MOV RBX,RAX
	RBX = RAX;
	ADDR_4009CA:; // MOV EAX,dword ptr [RBP + -0x3c]
	temp_12544._8 = RBP + ((u64)-60);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_4009CD:; // MOV EDI,EAX
	EDI = EAX;
	RDI = EDI;
	ADDR_4009CF:; // CALL 0x00400681
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x4009d4);
	bin();
	ADDR_4009D4:; // MOV R15,RAX
	R15 = RAX;
	ADDR_4009D7:; // MOV EAX,dword ptr [RBP + -0x3c]
	temp_12544._8 = RBP + ((u64)-60);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_4009DA:; // MOV EDI,EAX
	EDI = EAX;
	RDI = EDI;
	ADDR_4009DC:; // CALL 0x004003d2
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x4009e1);
	int_to_string();
	ADDR_4009E1:; // MOV RDI,RAX
	RDI = RAX;
	ADDR_4009E4:; // MOV RDX,qword ptr [RBP + -0x48]
	temp_12544._8 = RBP + ((u64)-72);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RDX = temp_48512._8;
	ADDR_4009E8:; // PUSH 0x0
	temp_259968._8 = ((u64)0);
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_259968._8;
	ADDR_4009EA:; // LEA RAX,[0x400bb8]
	RAX = ((u64)0x400bb8);
	ADDR_4009F1:; // PUSH RAX
	temp_59264._8 = RAX;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_4009F2:; // LEA RAX,[0x400c3c]
	RAX = ((u64)0x400c3c);
	ADDR_4009F9:; // PUSH RAX
	temp_59264._8 = RAX;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_4009FA:; // PUSH R14
	temp_59264._8 = R14;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_4009FC:; // LEA RAX,[0x400c3a]
	RAX = ((u64)0x400c3a);
	ADDR_400A03:; // PUSH RAX
	temp_59264._8 = RAX;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_400A04:; // PUSH R13
	temp_59264._8 = R13;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_400A06:; // LEA RAX,[0x400c3e]
	RAX = ((u64)0x400c3e);
	ADDR_400A0D:; // PUSH RAX
	temp_59264._8 = RAX;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_400A0E:; // PUSH R12
	temp_59264._8 = R12;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_400A10:; // LEA RAX,[0x400c3a]
	RAX = ((u64)0x400c3a);
	ADDR_400A17:; // PUSH RAX
	temp_59264._8 = RAX;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_400A18:; // PUSH RBX
	temp_59264._8 = RBX;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_400A19:; // LEA R9,[0x400c11]
	R9 = ((u64)0x400c11);
	ADDR_400A20:; // MOV R8,RDX
	R8 = RDX;
	ADDR_400A23:; // LEA RCX,[0x400c37]
	RCX = ((u64)0x400c37);
	ADDR_400A2A:; // MOV RDX,R15
	RDX = R15;
	ADDR_400A2D:; // LEA RSI,[0x400c3a]
	RSI = ((u64)0x400c3a);
	ADDR_400A34:; // MOV EAX,0x0
	RAX = ((u64)0);
	ADDR_400A39:; // CALL 0x004001de
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x400a3e);
	print_raw();
	ADDR_400A3E:; // ADD RSP,0x50
	CF = (u64)(RSP + ((u64)80)) < RSP;
	OF = SIGN(8, RSPs) == SIGN(8, ((i64)80)) && SIGN(8, (i64)(RSPs + ((i64)80))) != SIGN(8, ((i64)80));
	RSP = RSP + ((u64)80);
	SF = RSPs < ((i64)0);
	ZF = RSP == ((u64)0);
	temp_76800._8 = RSP & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_400A42:; // NOP
	
	ADDR_400A43:; // LEA RSP,[RBP + -0x28]
	temp_12544._8 = RBP + ((u64)-40);
	RSP = temp_12544._8;
	ADDR_400A47:; // POP RBX
	RBX = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_400A48:; // POP R12
	R12 = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_400A4A:; // POP R13
	R13 = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_400A4C:; // POP R14
	R14 = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_400A4E:; // POP R15
	R15 = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_400A50:; // POP RBP
	RBP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_400A51:; // RET
	RIP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	return;
	
}
