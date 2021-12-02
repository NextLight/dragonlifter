#include "dragonlifter.h"

void string_to_int() {
	ADDR_40060A:; // PUSH RBP
	temp_59264._8 = RBP;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_40060B:; // MOV RBP,RSP
	RBP = RSP;
	ADDR_40060E:; // MOV qword ptr [RBP + -0x28],RDI
	temp_12544._8 = RBP + ((u64)-40);
	temp_48512._8 = RDI;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_400612:; // MOV RAX,qword ptr [RBP + -0x28]
	temp_12544._8 = RBP + ((u64)-40);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RAX = temp_48512._8;
	ADDR_400616:; // MOVZX EAX,byte ptr [RAX]
	temp_47872._1 = RAM(RAX)._1;
	EAX = temp_47872._1;
	RAX = EAX;
	ADDR_400619:; // CMP AL,0x2d
	CF = AL < ((u8)45);
	OF = SIGN(1, ALs) != SIGN(1, ((i8)45)) && SIGN(1, (i8)(ALs - ((i8)45))) == SIGN(1, ((i8)45));
	temp_162048._1 = AL - ((u8)45);
	SF = temp_162048._1s < ((i8)0);
	ZF = temp_162048._1 == ((u8)0);
	temp_76800._1 = temp_162048._1 & ((u8)255);
	temp_76928._1 = POPCOUNT(1, temp_76800._1);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_40061B:; // SETZ AL
	AL = ZF;
	ADDR_40061E:; // MOVZX EAX,AL
	EAX = AL;
	RAX = EAX;
	ADDR_400621:; // MOV dword ptr [RBP + -0x14],EAX
	temp_12544._8 = RBP + ((u64)-20);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_400624:; // CMP dword ptr [RBP + -0x14],0x0
	temp_12544._8 = RBP + ((u64)-20);
	temp_48384._4 = RAM(temp_12544._8)._4;
	CF = temp_48384._4 < ((u32)0);
	temp_48384._4 = RAM(temp_12544._8)._4;
	OF = SIGN(4, temp_48384._4s) != SIGN(4, ((i32)0)) && SIGN(4, (i32)(temp_48384._4s - ((i32)0))) == SIGN(4, ((i32)0));
	temp_48384._4 = RAM(temp_12544._8)._4;
	temp_164352._4 = temp_48384._4 - ((u32)0);
	SF = temp_164352._4s < ((i32)0);
	ZF = temp_164352._4 == ((u32)0);
	temp_76800._4 = temp_164352._4 & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_400628:; // JZ 0x0040062f
	if (ZF) goto ADDR_40062F;
	ADDR_40062A:; // ADD qword ptr [RBP + -0x28],0x1
	temp_12544._8 = RBP + ((u64)-40);
	temp_48640._8 = RAM(temp_12544._8)._8;
	CF = (u64)(temp_48640._8 + ((u64)1)) < temp_48640._8;
	temp_48640._8 = RAM(temp_12544._8)._8;
	OF = SIGN(8, temp_48640._8s) == SIGN(8, ((i64)1)) && SIGN(8, (i64)(temp_48640._8s + ((i64)1))) != SIGN(8, ((i64)1));
	temp_48640._8 = RAM(temp_12544._8)._8;
	temp_48640._8 = temp_48640._8 + ((u64)1);
	RAM(temp_12544._8)._8 = temp_48640._8;
	temp_48640._8 = RAM(temp_12544._8)._8;
	SF = temp_48640._8s < ((i64)0);
	temp_48640._8 = RAM(temp_12544._8)._8;
	ZF = temp_48640._8 == ((u64)0);
	temp_48640._8 = RAM(temp_12544._8)._8;
	temp_76800._8 = temp_48640._8 & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_40062F:; // MOV dword ptr [RBP + -0x4],0x0
	temp_12544._8 = RBP + ((u64)-4);
	temp_48384._4 = ((u32)0);
	RAM(temp_12544._8)._4 = temp_48384._4;
	ADDR_400636:; // MOV RAX,qword ptr [RBP + -0x28]
	temp_12544._8 = RBP + ((u64)-40);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RAX = temp_48512._8;
	ADDR_40063A:; // MOV qword ptr [RBP + -0x10],RAX
	temp_12544._8 = RBP + ((u64)-16);
	temp_48512._8 = RAX;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_40063E:; // JMP 0x00400664
	goto ADDR_400664;
	ADDR_400640:; // MOV EDX,dword ptr [RBP + -0x4]
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EDX = temp_48256._4;
	RDX = EDX;
	ADDR_400643:; // MOV EAX,EDX
	EAX = EDX;
	RAX = EAX;
	ADDR_400645:; // SHL EAX,0x2
	temp_340736._4 = ((u32)2) & ((u32)31);
	temp_340864._4 = EAX;
	EAX = EAX << temp_340736._4;
	RAX = EAX;
	temp_86016._1 = temp_340736._4 != ((u32)0);
	temp_86144._4 = temp_340736._4 - ((u32)1);
	temp_86272._4 = temp_340864._4 << temp_86144._4;
	temp_86528._1 = temp_86272._4s < ((i32)0);
	temp_86656._1 = !temp_86016._1;
	temp_86784._1 = temp_86656._1 & CF;
	temp_86912._1 = temp_86016._1 & temp_86528._1;
	CF = temp_86784._1 | temp_86912._1;
	temp_87296._1 = temp_340736._4 == ((u32)1);
	temp_87424._1 = EAXs < ((i32)0);
	temp_87680._1 = CF ^ temp_87424._1;
	temp_87808._1 = !temp_87296._1;
	temp_87936._1 = temp_87808._1 & OF;
	temp_88064._1 = temp_87296._1 & temp_87680._1;
	OF = temp_87936._1 | temp_88064._1;
	temp_77440._1 = temp_340736._4 != ((u32)0);
	temp_77696._1 = EAXs < ((i32)0);
	temp_77824._1 = !temp_77440._1;
	temp_77952._1 = temp_77824._1 & SF;
	temp_78080._1 = temp_77440._1 & temp_77696._1;
	SF = temp_77952._1 | temp_78080._1;
	temp_78464._1 = EAX == ((u32)0);
	temp_78592._1 = !temp_77440._1;
	temp_78720._1 = temp_78592._1 & ZF;
	temp_78848._1 = temp_77440._1 & temp_78464._1;
	ZF = temp_78720._1 | temp_78848._1;
	temp_79104._4 = EAX & ((u32)255);
	temp_79232._1 = POPCOUNT(4, temp_79104._4);
	temp_79360._1 = temp_79232._1 & ((u8)1);
	temp_79616._1 = temp_79360._1 == ((u8)0);
	temp_79744._1 = !temp_77440._1;
	temp_79872._1 = temp_79744._1 & PF;
	temp_80000._1 = temp_77440._1 & temp_79616._1;
	PF = temp_79872._1 | temp_80000._1;
	ADDR_400648:; // ADD EAX,EDX
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
	ADDR_40064A:; // ADD EAX,EAX
	CF = (u32)(EAX + EAX) < EAX;
	OF = SIGN(4, EAXs) == SIGN(4, EAXs) && SIGN(4, (i32)(EAXs + EAXs)) != SIGN(4, EAXs);
	EAX = EAX + EAX;
	RAX = EAX;
	SF = EAXs < ((i32)0);
	ZF = EAX == ((u32)0);
	temp_76800._4 = EAX & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_40064C:; // MOV dword ptr [RBP + -0x4],EAX
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_40064F:; // MOV RAX,qword ptr [RBP + -0x10]
	temp_12544._8 = RBP + ((u64)-16);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RAX = temp_48512._8;
	ADDR_400653:; // MOVZX EAX,byte ptr [RAX]
	temp_47872._1 = RAM(RAX)._1;
	EAX = temp_47872._1;
	RAX = EAX;
	ADDR_400656:; // MOVSX EAX,AL
	EAXs = ALs;
	RAX = EAX;
	ADDR_400659:; // SUB EAX,0x30
	CF = EAX < ((u32)48);
	OF = SIGN(4, EAXs) != SIGN(4, ((i32)48)) && SIGN(4, (i32)(EAXs - ((i32)48))) == SIGN(4, ((i32)48));
	EAX = EAX - ((u32)48);
	RAX = EAX;
	SF = EAXs < ((i32)0);
	ZF = EAX == ((u32)0);
	temp_76800._4 = EAX & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_40065C:; // ADD dword ptr [RBP + -0x4],EAX
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = RAM(temp_12544._8)._4;
	CF = (u32)(temp_48256._4 + EAX) < temp_48256._4;
	temp_48256._4 = RAM(temp_12544._8)._4;
	OF = SIGN(4, temp_48256._4s) == SIGN(4, EAXs) && SIGN(4, (i32)(temp_48256._4s + EAXs)) != SIGN(4, EAXs);
	temp_48256._4 = RAM(temp_12544._8)._4;
	temp_48256._4 = temp_48256._4 + EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	temp_48256._4 = RAM(temp_12544._8)._4;
	SF = temp_48256._4s < ((i32)0);
	temp_48256._4 = RAM(temp_12544._8)._4;
	ZF = temp_48256._4 == ((u32)0);
	temp_48256._4 = RAM(temp_12544._8)._4;
	temp_76800._4 = temp_48256._4 & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_40065F:; // ADD qword ptr [RBP + -0x10],0x1
	temp_12544._8 = RBP + ((u64)-16);
	temp_48640._8 = RAM(temp_12544._8)._8;
	CF = (u64)(temp_48640._8 + ((u64)1)) < temp_48640._8;
	temp_48640._8 = RAM(temp_12544._8)._8;
	OF = SIGN(8, temp_48640._8s) == SIGN(8, ((i64)1)) && SIGN(8, (i64)(temp_48640._8s + ((i64)1))) != SIGN(8, ((i64)1));
	temp_48640._8 = RAM(temp_12544._8)._8;
	temp_48640._8 = temp_48640._8 + ((u64)1);
	RAM(temp_12544._8)._8 = temp_48640._8;
	temp_48640._8 = RAM(temp_12544._8)._8;
	SF = temp_48640._8s < ((i64)0);
	temp_48640._8 = RAM(temp_12544._8)._8;
	ZF = temp_48640._8 == ((u64)0);
	temp_48640._8 = RAM(temp_12544._8)._8;
	temp_76800._8 = temp_48640._8 & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_400664:; // MOV RAX,qword ptr [RBP + -0x10]
	temp_12544._8 = RBP + ((u64)-16);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RAX = temp_48512._8;
	ADDR_400668:; // MOVZX EAX,byte ptr [RAX]
	temp_47872._1 = RAM(RAX)._1;
	EAX = temp_47872._1;
	RAX = EAX;
	ADDR_40066B:; // TEST AL,AL
	CF = ((u8)0);
	OF = ((u8)0);
	temp_364544._1 = AL & AL;
	SF = temp_364544._1s < ((i8)0);
	ZF = temp_364544._1 == ((u8)0);
	temp_76800._1 = temp_364544._1 & ((u8)255);
	temp_76928._1 = POPCOUNT(1, temp_76800._1);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_40066D:; // JNZ 0x00400640
	temp_50816._1 = !ZF;
	if (temp_50816._1) goto ADDR_400640;
	ADDR_40066F:; // CMP dword ptr [RBP + -0x14],0x0
	temp_12544._8 = RBP + ((u64)-20);
	temp_48384._4 = RAM(temp_12544._8)._4;
	CF = temp_48384._4 < ((u32)0);
	temp_48384._4 = RAM(temp_12544._8)._4;
	OF = SIGN(4, temp_48384._4s) != SIGN(4, ((i32)0)) && SIGN(4, (i32)(temp_48384._4s - ((i32)0))) == SIGN(4, ((i32)0));
	temp_48384._4 = RAM(temp_12544._8)._4;
	temp_164352._4 = temp_48384._4 - ((u32)0);
	SF = temp_164352._4s < ((i32)0);
	ZF = temp_164352._4 == ((u32)0);
	temp_76800._4 = temp_164352._4 & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_400673:; // JZ 0x0040067c
	if (ZF) goto ADDR_40067C;
	ADDR_400675:; // MOV EAX,dword ptr [RBP + -0x4]
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_400678:; // NEG EAX
	CF = EAX != ((u32)0);
	OF = SIGN(4, ((i32)0)) != SIGN(4, EAXs) && SIGN(4, (i32)(((i32)0) - EAXs)) == SIGN(4, EAXs);
	EAXs = -EAXs;
	SF = EAXs < ((i32)0);
	ZF = EAX == ((u32)0);
	temp_76800._4 = EAX & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	RAX = EAX;
	ADDR_40067A:; // JMP 0x0040067f
	goto ADDR_40067F;
	ADDR_40067C:; // MOV EAX,dword ptr [RBP + -0x4]
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_40067F:; // POP RBP
	RBP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_400680:; // RET
	RIP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	return;
	
}
