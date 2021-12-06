#include "dragonlifter.h"

void calc_bitwise() {
	ADDR_1017C5:; // ENDBR64
	
	ADDR_1017C9:; // PUSH RBP
	temp_59264._8 = RBP;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_1017CA:; // MOV RBP,RSP
	RBP = RSP;
	ADDR_1017CD:; // PUSH R15
	temp_59264._8 = R15;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_1017CF:; // PUSH R14
	temp_59264._8 = R14;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_1017D1:; // PUSH R13
	temp_59264._8 = R13;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_1017D3:; // PUSH R12
	temp_59264._8 = R12;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_1017D5:; // PUSH RBX
	temp_59264._8 = RBX;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_1017D6:; // SUB RSP,0x48
	CF = RSP < ((u64)72);
	OF = SIGN(8, RSPs) != SIGN(8, ((i64)72)) && SIGN(8, (i64)(RSPs - ((i64)72))) == SIGN(8, ((i64)72));
	RSP = RSP - ((u64)72);
	SF = RSPs < ((i64)0);
	ZF = RSP == ((u64)0);
	temp_76800._8 = RSP & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_1017DA:; // MOV EDX,0x0
	RDX = ((u64)0);
	ADDR_1017DF:; // LEA RSI,[0x102000]
	RSI = ((u64)0x102000);
	ADDR_1017E6:; // LEA RDI,[0x102060]
	RDI = ((u64)0x102060);
	ADDR_1017ED:; // MOV EAX,0x0
	RAX = ((u64)0);
	ADDR_1017F2:; // CALL 0x001010aa
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x1017f7);
	print_raw();
	ADDR_1017F7:; // LEA RDI,[0x10202c]
	RDI = ((u64)0x10202c);
	ADDR_1017FE:; // CALL 0x00101279
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x101803);
	input_prompt();
	ADDR_101803:; // MOV RDI,RAX
	RDI = RAX;
	ADDR_101806:; // CALL 0x001014e4
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x10180b);
	string_to_int();
	ADDR_10180B:; // MOV dword ptr [RBP + -0x3c],EAX
	temp_12544._8 = RBP + ((u64)-60);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_10180E:; // LEA RDI,[0x10203a]
	RDI = ((u64)0x10203a);
	ADDR_101815:; // CALL 0x00101279
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x10181a);
	input_prompt();
	ADDR_10181A:; // MOV qword ptr [RBP + -0x48],RAX
	temp_12544._8 = RBP + ((u64)-72);
	temp_48512._8 = RAX;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_10181E:; // LEA RDI,[0x102046]
	RDI = ((u64)0x102046);
	ADDR_101825:; // CALL 0x00101279
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x10182a);
	input_prompt();
	ADDR_10182A:; // MOV RDI,RAX
	RDI = RAX;
	ADDR_10182D:; // CALL 0x001014e4
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x101832);
	string_to_int();
	ADDR_101832:; // MOV dword ptr [RBP + -0x4c],EAX
	temp_12544._8 = RBP + ((u64)-76);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_101835:; // MOV RAX,qword ptr [RBP + -0x48]
	temp_12544._8 = RBP + ((u64)-72);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RAX = temp_48512._8;
	ADDR_101839:; // MOVZX EAX,byte ptr [RAX]
	temp_47872._1 = RAM(RAX)._1;
	EAX = temp_47872._1;
	RAX = EAX;
	ADDR_10183C:; // MOVSX EAX,AL
	EAXs = ALs;
	RAX = EAX;
	ADDR_10183F:; // CMP EAX,0x7c
	CF = EAX < ((u32)124);
	OF = SIGN(4, EAXs) != SIGN(4, ((i32)124)) && SIGN(4, (i32)(EAXs - ((i32)124))) == SIGN(4, ((i32)124));
	temp_164352._4 = EAX - ((u32)124);
	SF = temp_164352._4s < ((i32)0);
	ZF = temp_164352._4 == ((u32)0);
	temp_76800._4 = temp_164352._4 & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_101842:; // JZ 0x00101862
	if (ZF) goto ADDR_101862;
	ADDR_101844:; // CMP EAX,0x7c
	CF = EAX < ((u32)124);
	OF = SIGN(4, EAXs) != SIGN(4, ((i32)124)) && SIGN(4, (i32)(EAXs - ((i32)124))) == SIGN(4, ((i32)124));
	temp_164352._4 = EAX - ((u32)124);
	SF = temp_164352._4s < ((i32)0);
	ZF = temp_164352._4 == ((u32)0);
	temp_76800._4 = temp_164352._4 & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_101847:; // JG 0x0010187b
	temp_52992._1 = !ZF;
	temp_53120._1 = OF == SF;
	temp_53376._1 = temp_52992._1 && temp_53120._1;
	if (temp_53376._1) goto ADDR_10187B;
	ADDR_101849:; // CMP EAX,0x26
	CF = EAX < ((u32)38);
	OF = SIGN(4, EAXs) != SIGN(4, ((i32)38)) && SIGN(4, (i32)(EAXs - ((i32)38))) == SIGN(4, ((i32)38));
	temp_164352._4 = EAX - ((u32)38);
	SF = temp_164352._4s < ((i32)0);
	ZF = temp_164352._4 == ((u32)0);
	temp_76800._4 = temp_164352._4 & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_10184C:; // JZ 0x00101855
	if (ZF) goto ADDR_101855;
	ADDR_10184E:; // CMP EAX,0x5e
	CF = EAX < ((u32)94);
	OF = SIGN(4, EAXs) != SIGN(4, ((i32)94)) && SIGN(4, (i32)(EAXs - ((i32)94))) == SIGN(4, ((i32)94));
	temp_164352._4 = EAX - ((u32)94);
	SF = temp_164352._4s < ((i32)0);
	ZF = temp_164352._4 == ((u32)0);
	temp_76800._4 = temp_164352._4 & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_101851:; // JZ 0x0010186f
	if (ZF) goto ADDR_10186F;
	ADDR_101853:; // JMP 0x0010187b
	goto ADDR_10187B;
	ADDR_101855:; // LEA RAX,[0x101783]
	RAX = ((u64)0x101783);
	ADDR_10185C:; // MOV qword ptr [RBP + -0x38],RAX
	temp_12544._8 = RBP + ((u64)-56);
	temp_48512._8 = RAX;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_101860:; // JMP 0x0010187b
	goto ADDR_10187B;
	ADDR_101862:; // LEA RAX,[0x101799]
	RAX = ((u64)0x101799);
	ADDR_101869:; // MOV qword ptr [RBP + -0x38],RAX
	temp_12544._8 = RBP + ((u64)-56);
	temp_48512._8 = RAX;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_10186D:; // JMP 0x0010187b
	goto ADDR_10187B;
	ADDR_10186F:; // LEA RAX,[0x1017af]
	RAX = ((u64)0x1017af);
	ADDR_101876:; // MOV qword ptr [RBP + -0x38],RAX
	temp_12544._8 = RBP + ((u64)-56);
	temp_48512._8 = RAX;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_10187A:; // NOP
	
	ADDR_10187B:; // MOV EDX,dword ptr [RBP + -0x4c]
	temp_12544._8 = RBP + ((u64)-76);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EDX = temp_48256._4;
	RDX = EDX;
	ADDR_10187E:; // MOV EAX,dword ptr [RBP + -0x3c]
	temp_12544._8 = RBP + ((u64)-60);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_101881:; // MOV RCX,qword ptr [RBP + -0x38]
	temp_12544._8 = RBP + ((u64)-56);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RCX = temp_48512._8;
	ADDR_101885:; // MOV ESI,EDX
	ESI = EDX;
	RSI = ESI;
	ADDR_101887:; // MOV EDI,EAX
	EDI = EAX;
	RDI = EDI;
	ADDR_101889:; // CALL RCX
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x10188b);
	CALL_FUNCTION_AT(RCX);
	ADDR_10188B:; // MOV dword ptr [RBP + -0x50],EAX
	temp_12544._8 = RBP + ((u64)-80);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_10188E:; // MOV EAX,dword ptr [RBP + -0x50]
	temp_12544._8 = RBP + ((u64)-80);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_101891:; // MOV EDI,EAX
	EDI = EAX;
	RDI = EDI;
	ADDR_101893:; // CALL 0x0010155f
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x101898);
	bin();
	ADDR_101898:; // MOV R14,RAX
	R14 = RAX;
	ADDR_10189B:; // MOV EAX,dword ptr [RBP + -0x50]
	temp_12544._8 = RBP + ((u64)-80);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_10189E:; // MOV EDI,EAX
	EDI = EAX;
	RDI = EDI;
	ADDR_1018A0:; // CALL 0x001012ac
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x1018a5);
	int_to_string();
	ADDR_1018A5:; // MOV R13,RAX
	R13 = RAX;
	ADDR_1018A8:; // MOV EAX,dword ptr [RBP + -0x4c]
	temp_12544._8 = RBP + ((u64)-76);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_1018AB:; // MOV EDI,EAX
	EDI = EAX;
	RDI = EDI;
	ADDR_1018AD:; // CALL 0x0010155f
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x1018b2);
	bin();
	ADDR_1018B2:; // MOV R12,RAX
	R12 = RAX;
	ADDR_1018B5:; // MOV EAX,dword ptr [RBP + -0x4c]
	temp_12544._8 = RBP + ((u64)-76);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_1018B8:; // MOV EDI,EAX
	EDI = EAX;
	RDI = EDI;
	ADDR_1018BA:; // CALL 0x001012ac
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x1018bf);
	int_to_string();
	ADDR_1018BF:; // MOV RBX,RAX
	RBX = RAX;
	ADDR_1018C2:; // MOV EAX,dword ptr [RBP + -0x3c]
	temp_12544._8 = RBP + ((u64)-60);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_1018C5:; // MOV EDI,EAX
	EDI = EAX;
	RDI = EDI;
	ADDR_1018C7:; // CALL 0x0010155f
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x1018cc);
	bin();
	ADDR_1018CC:; // MOV R15,RAX
	R15 = RAX;
	ADDR_1018CF:; // MOV EAX,dword ptr [RBP + -0x3c]
	temp_12544._8 = RBP + ((u64)-60);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_1018D2:; // MOV EDI,EAX
	EDI = EAX;
	RDI = EDI;
	ADDR_1018D4:; // CALL 0x001012ac
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x1018d9);
	int_to_string();
	ADDR_1018D9:; // MOV RCX,qword ptr [RBP + -0x48]
	temp_12544._8 = RBP + ((u64)-72);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RCX = temp_48512._8;
	ADDR_1018DD:; // PUSH 0x0
	temp_259968._8 = ((u64)0);
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_259968._8;
	ADDR_1018DF:; // LEA RDX,[0x102000]
	RDX = ((u64)0x102000);
	ADDR_1018E6:; // PUSH RDX
	temp_59264._8 = RDX;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_1018E7:; // LEA RDX,[0x102084]
	RDX = ((u64)0x102084);
	ADDR_1018EE:; // PUSH RDX
	temp_59264._8 = RDX;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_1018EF:; // PUSH R14
	temp_59264._8 = R14;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_1018F1:; // LEA RDX,[0x102082]
	RDX = ((u64)0x102082);
	ADDR_1018F8:; // PUSH RDX
	temp_59264._8 = RDX;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_1018F9:; // PUSH R13
	temp_59264._8 = R13;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_1018FB:; // LEA RDX,[0x102086]
	RDX = ((u64)0x102086);
	ADDR_101902:; // PUSH RDX
	temp_59264._8 = RDX;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_101903:; // PUSH R12
	temp_59264._8 = R12;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_101905:; // LEA RDX,[0x102082]
	RDX = ((u64)0x102082);
	ADDR_10190C:; // PUSH RDX
	temp_59264._8 = RDX;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_10190D:; // PUSH RBX
	temp_59264._8 = RBX;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_10190E:; // LEA R9,[0x102059]
	R9 = ((u64)0x102059);
	ADDR_101915:; // MOV R8,RCX
	R8 = RCX;
	ADDR_101918:; // LEA RCX,[0x10207f]
	RCX = ((u64)0x10207f);
	ADDR_10191F:; // MOV RDX,R15
	RDX = R15;
	ADDR_101922:; // LEA RSI,[0x102082]
	RSI = ((u64)0x102082);
	ADDR_101929:; // MOV RDI,RAX
	RDI = RAX;
	ADDR_10192C:; // MOV EAX,0x0
	RAX = ((u64)0);
	ADDR_101931:; // CALL 0x001010aa
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x101936);
	print_raw();
	ADDR_101936:; // ADD RSP,0x50
	CF = (u64)(RSP + ((u64)80)) < RSP;
	OF = SIGN(8, RSPs) == SIGN(8, ((i64)80)) && SIGN(8, (i64)(RSPs + ((i64)80))) != SIGN(8, ((i64)80));
	RSP = RSP + ((u64)80);
	SF = RSPs < ((i64)0);
	ZF = RSP == ((u64)0);
	temp_76800._8 = RSP & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_10193A:; // NOP
	
	ADDR_10193B:; // LEA RSP,[RBP + -0x28]
	temp_12544._8 = RBP + ((u64)-40);
	RSP = temp_12544._8;
	ADDR_10193F:; // POP RBX
	RBX = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_101940:; // POP R12
	R12 = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_101942:; // POP R13
	R13 = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_101944:; // POP R14
	R14 = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_101946:; // POP R15
	R15 = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_101948:; // POP RBP
	RBP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_101949:; // RET
	RIP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	return;
	
}
