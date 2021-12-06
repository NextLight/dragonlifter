#include "dragonlifter.h"

void string_to_int() {
	ADDR_1014E4:; // ENDBR64
	
	ADDR_1014E8:; // PUSH RBP
	temp_59264._8 = RBP;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_1014E9:; // MOV RBP,RSP
	RBP = RSP;
	ADDR_1014EC:; // MOV qword ptr [RBP + -0x28],RDI
	temp_12544._8 = RBP + ((u64)-40);
	temp_48512._8 = RDI;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_1014F0:; // MOV RAX,qword ptr [RBP + -0x28]
	temp_12544._8 = RBP + ((u64)-40);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RAX = temp_48512._8;
	ADDR_1014F4:; // MOVZX EAX,byte ptr [RAX]
	temp_47872._1 = RAM(RAX)._1;
	EAX = temp_47872._1;
	RAX = EAX;
	ADDR_1014F7:; // CMP AL,0x2d
	CF = AL < ((u8)45);
	OF = SIGN(1, ALs) != SIGN(1, ((i8)45)) && SIGN(1, (i8)(ALs - ((i8)45))) == SIGN(1, ((i8)45));
	temp_162048._1 = AL - ((u8)45);
	SF = temp_162048._1s < ((i8)0);
	ZF = temp_162048._1 == ((u8)0);
	temp_76800._1 = temp_162048._1 & ((u8)255);
	temp_76928._1 = POPCOUNT(1, temp_76800._1);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_1014F9:; // SETZ AL
	AL = ZF;
	ADDR_1014FC:; // MOVZX EAX,AL
	EAX = AL;
	RAX = EAX;
	ADDR_1014FF:; // MOV dword ptr [RBP + -0x14],EAX
	temp_12544._8 = RBP + ((u64)-20);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_101502:; // CMP dword ptr [RBP + -0x14],0x0
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
	ADDR_101506:; // JZ 0x0010150d
	if (ZF) goto ADDR_10150D;
	ADDR_101508:; // ADD qword ptr [RBP + -0x28],0x1
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
	ADDR_10150D:; // MOV dword ptr [RBP + -0x4],0x0
	temp_12544._8 = RBP + ((u64)-4);
	temp_48384._4 = ((u32)0);
	RAM(temp_12544._8)._4 = temp_48384._4;
	ADDR_101514:; // MOV RAX,qword ptr [RBP + -0x28]
	temp_12544._8 = RBP + ((u64)-40);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RAX = temp_48512._8;
	ADDR_101518:; // MOV qword ptr [RBP + -0x10],RAX
	temp_12544._8 = RBP + ((u64)-16);
	temp_48512._8 = RAX;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_10151C:; // JMP 0x00101542
	goto ADDR_101542;
	ADDR_10151E:; // MOV EDX,dword ptr [RBP + -0x4]
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EDX = temp_48256._4;
	RDX = EDX;
	ADDR_101521:; // MOV EAX,EDX
	EAX = EDX;
	RAX = EAX;
	ADDR_101523:; // SHL EAX,0x2
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
	ADDR_101526:; // ADD EAX,EDX
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
	ADDR_101528:; // ADD EAX,EAX
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
	ADDR_10152A:; // MOV dword ptr [RBP + -0x4],EAX
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_10152D:; // MOV RAX,qword ptr [RBP + -0x10]
	temp_12544._8 = RBP + ((u64)-16);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RAX = temp_48512._8;
	ADDR_101531:; // MOVZX EAX,byte ptr [RAX]
	temp_47872._1 = RAM(RAX)._1;
	EAX = temp_47872._1;
	RAX = EAX;
	ADDR_101534:; // MOVSX EAX,AL
	EAXs = ALs;
	RAX = EAX;
	ADDR_101537:; // SUB EAX,0x30
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
	ADDR_10153A:; // ADD dword ptr [RBP + -0x4],EAX
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
	ADDR_10153D:; // ADD qword ptr [RBP + -0x10],0x1
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
	ADDR_101542:; // MOV RAX,qword ptr [RBP + -0x10]
	temp_12544._8 = RBP + ((u64)-16);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RAX = temp_48512._8;
	ADDR_101546:; // MOVZX EAX,byte ptr [RAX]
	temp_47872._1 = RAM(RAX)._1;
	EAX = temp_47872._1;
	RAX = EAX;
	ADDR_101549:; // TEST AL,AL
	CF = ((u8)0);
	OF = ((u8)0);
	temp_364544._1 = AL & AL;
	SF = temp_364544._1s < ((i8)0);
	ZF = temp_364544._1 == ((u8)0);
	temp_76800._1 = temp_364544._1 & ((u8)255);
	temp_76928._1 = POPCOUNT(1, temp_76800._1);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_10154B:; // JNZ 0x0010151e
	temp_50816._1 = !ZF;
	if (temp_50816._1) goto ADDR_10151E;
	ADDR_10154D:; // CMP dword ptr [RBP + -0x14],0x0
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
	ADDR_101551:; // JZ 0x0010155a
	if (ZF) goto ADDR_10155A;
	ADDR_101553:; // MOV EAX,dword ptr [RBP + -0x4]
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_101556:; // NEG EAX
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
	ADDR_101558:; // JMP 0x0010155d
	goto ADDR_10155D;
	ADDR_10155A:; // MOV EAX,dword ptr [RBP + -0x4]
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_10155D:; // POP RBP
	RBP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_10155E:; // RET
	RIP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	return;
	
}
