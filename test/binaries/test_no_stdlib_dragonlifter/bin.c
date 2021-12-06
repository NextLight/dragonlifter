#include "dragonlifter.h"

void bin() {
	ADDR_10155F:; // ENDBR64
	
	ADDR_101563:; // PUSH RBP
	temp_59264._8 = RBP;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_101564:; // MOV RBP,RSP
	RBP = RSP;
	ADDR_101567:; // MOV dword ptr [RBP + -0x24],EDI
	temp_12544._8 = RBP + ((u64)-36);
	temp_48256._4 = EDI;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_10156A:; // MOV EAX,dword ptr [0x00105040]
	EAX = RAM(1069120)._4;
	RAX = EAX;
	ADDR_101570:; // CDQE
	RAXs = EAXs;
	ADDR_101572:; // LEA RDX,[0x105060]
	RDX = ((u64)0x105060);
	ADDR_101579:; // ADD RAX,RDX
	CF = (u64)(RAX + RDX) < RAX;
	OF = SIGN(8, RAXs) == SIGN(8, RDXs) && SIGN(8, (i64)(RAXs + RDXs)) != SIGN(8, RDXs);
	RAX = RAX + RDX;
	SF = RAXs < ((i64)0);
	ZF = RAX == ((u64)0);
	temp_76800._8 = RAX & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_10157C:; // MOV qword ptr [RBP + -0x10],RAX
	temp_12544._8 = RBP + ((u64)-16);
	temp_48512._8 = RAX;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_101580:; // MOV EAX,dword ptr [0x00105040]
	EAX = RAM(1069120)._4;
	RAX = EAX;
	ADDR_101586:; // LEA EDX,[RAX + 0x1]
	temp_12544._8 = RAX + ((u64)1);
	EDX = (temp_12544._8 / 0x1);
	RDX = EDX;
	ADDR_101589:; // MOV dword ptr [0x00105040],EDX
	RAM(1069120)._4 = EDX;
	ADDR_10158F:; // CDQE
	RAXs = EAXs;
	ADDR_101591:; // LEA RDX,[0x105060]
	RDX = ((u64)0x105060);
	ADDR_101598:; // MOV byte ptr [RAX + RDX*0x1],0x30
	temp_13056._8 = RDX * ((u64)1);
	temp_13312._8 = RAX + temp_13056._8;
	temp_47872._1 = ((u8)48);
	RAM(temp_13312._8)._1 = temp_47872._1;
	ADDR_10159C:; // MOV EAX,dword ptr [0x00105040]
	EAX = RAM(1069120)._4;
	RAX = EAX;
	ADDR_1015A2:; // LEA EDX,[RAX + 0x1]
	temp_12544._8 = RAX + ((u64)1);
	EDX = (temp_12544._8 / 0x1);
	RDX = EDX;
	ADDR_1015A5:; // MOV dword ptr [0x00105040],EDX
	RAM(1069120)._4 = EDX;
	ADDR_1015AB:; // CDQE
	RAXs = EAXs;
	ADDR_1015AD:; // LEA RDX,[0x105060]
	RDX = ((u64)0x105060);
	ADDR_1015B4:; // MOV byte ptr [RAX + RDX*0x1],0x62
	temp_13056._8 = RDX * ((u64)1);
	temp_13312._8 = RAX + temp_13056._8;
	temp_47872._1 = ((u8)98);
	RAM(temp_13312._8)._1 = temp_47872._1;
	ADDR_1015B8:; // MOV dword ptr [RBP + -0x4],0x0
	temp_12544._8 = RBP + ((u64)-4);
	temp_48384._4 = ((u32)0);
	RAM(temp_12544._8)._4 = temp_48384._4;
	ADDR_1015BF:; // MOV dword ptr [RBP + -0x8],0x1f
	temp_12544._8 = RBP + ((u64)-8);
	temp_48384._4 = ((u32)31);
	RAM(temp_12544._8)._4 = temp_48384._4;
	ADDR_1015C6:; // JMP 0x0010160b
	goto ADDR_10160B;
	ADDR_1015C8:; // MOV EAX,dword ptr [RBP + -0x8]
	temp_12544._8 = RBP + ((u64)-8);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_1015CB:; // MOV EDX,dword ptr [RBP + -0x24]
	temp_12544._8 = RBP + ((u64)-36);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EDX = temp_48256._4;
	RDX = EDX;
	ADDR_1015CE:; // MOV ECX,EAX
	ECX = EAX;
	RCX = ECX;
	ADDR_1015D0:; // SAR EDX,CL
	temp_332800._1 = CL & ((u8)31);
	temp_332928._4 = EDX;
	EDXs = EDXs >> temp_332800._1;
	RDX = EDX;
	temp_88448._1 = temp_332800._1 != ((u8)0);
	temp_88576._1 = temp_332800._1 - ((u8)1);
	temp_88704._4s = temp_332928._4s >> temp_88576._1;
	temp_88832._4 = temp_88704._4 & ((u32)1);
	temp_89088._1 = temp_88832._4 != ((u32)0);
	temp_89216._1 = !temp_88448._1;
	temp_89344._1 = temp_89216._1 & CF;
	temp_89472._1 = temp_88448._1 & temp_89088._1;
	CF = temp_89344._1 | temp_89472._1;
	temp_89856._1 = temp_332800._1 == ((u8)1);
	temp_89984._1 = !temp_89856._1;
	OF = temp_89984._1 & OF;
	temp_77440._1 = temp_332800._1 != ((u8)0);
	temp_77696._1 = EDXs < ((i32)0);
	temp_77824._1 = !temp_77440._1;
	temp_77952._1 = temp_77824._1 & SF;
	temp_78080._1 = temp_77440._1 & temp_77696._1;
	SF = temp_77952._1 | temp_78080._1;
	temp_78464._1 = EDX == ((u32)0);
	temp_78592._1 = !temp_77440._1;
	temp_78720._1 = temp_78592._1 & ZF;
	temp_78848._1 = temp_77440._1 & temp_78464._1;
	ZF = temp_78720._1 | temp_78848._1;
	temp_79104._4 = EDX & ((u32)255);
	temp_79232._1 = POPCOUNT(4, temp_79104._4);
	temp_79360._1 = temp_79232._1 & ((u8)1);
	temp_79616._1 = temp_79360._1 == ((u8)0);
	temp_79744._1 = !temp_77440._1;
	temp_79872._1 = temp_79744._1 & PF;
	temp_80000._1 = temp_77440._1 & temp_79616._1;
	PF = temp_79872._1 | temp_80000._1;
	ADDR_1015D2:; // MOV EAX,EDX
	EAX = EDX;
	RAX = EAX;
	ADDR_1015D4:; // AND EAX,0x1
	CF = ((u8)0);
	OF = ((u8)0);
	EAX = EAX & ((u32)1);
	RAX = EAX;
	SF = EAXs < ((i32)0);
	ZF = EAX == ((u32)0);
	temp_76800._4 = EAX & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_1015D7:; // MOV dword ptr [RBP + -0x14],EAX
	temp_12544._8 = RBP + ((u64)-20);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_1015DA:; // MOV EAX,dword ptr [RBP + -0x14]
	temp_12544._8 = RBP + ((u64)-20);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_1015DD:; // OR dword ptr [RBP + -0x4],EAX
	temp_12544._8 = RBP + ((u64)-4);
	CF = ((u8)0);
	OF = ((u8)0);
	temp_48256._4 = RAM(temp_12544._8)._4;
	temp_48256._4 = temp_48256._4 | EAX;
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
	ADDR_1015E0:; // CMP dword ptr [RBP + -0x4],0x0
	temp_12544._8 = RBP + ((u64)-4);
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
	ADDR_1015E4:; // JZ 0x00101607
	if (ZF) goto ADDR_101607;
	ADDR_1015E6:; // MOV EAX,dword ptr [RBP + -0x14]
	temp_12544._8 = RBP + ((u64)-20);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_1015E9:; // LEA ECX,[RAX + 0x30]
	temp_12544._8 = RAX + ((u64)48);
	ECX = (temp_12544._8 / 0x1);
	RCX = ECX;
	ADDR_1015EC:; // MOV EAX,dword ptr [0x00105040]
	EAX = RAM(1069120)._4;
	RAX = EAX;
	ADDR_1015F2:; // LEA EDX,[RAX + 0x1]
	temp_12544._8 = RAX + ((u64)1);
	EDX = (temp_12544._8 / 0x1);
	RDX = EDX;
	ADDR_1015F5:; // MOV dword ptr [0x00105040],EDX
	RAM(1069120)._4 = EDX;
	ADDR_1015FB:; // CDQE
	RAXs = EAXs;
	ADDR_1015FD:; // LEA RDX,[0x105060]
	RDX = ((u64)0x105060);
	ADDR_101604:; // MOV byte ptr [RAX + RDX*0x1],CL
	temp_13056._8 = RDX * ((u64)1);
	temp_13312._8 = RAX + temp_13056._8;
	temp_47744._1 = CL;
	RAM(temp_13312._8)._1 = temp_47744._1;
	ADDR_101607:; // SUB dword ptr [RBP + -0x8],0x1
	temp_12544._8 = RBP + ((u64)-8);
	temp_48384._4 = RAM(temp_12544._8)._4;
	CF = temp_48384._4 < ((u32)1);
	temp_48384._4 = RAM(temp_12544._8)._4;
	OF = SIGN(4, temp_48384._4s) != SIGN(4, ((i32)1)) && SIGN(4, (i32)(temp_48384._4s - ((i32)1))) == SIGN(4, ((i32)1));
	temp_48384._4 = RAM(temp_12544._8)._4;
	temp_48384._4 = temp_48384._4 - ((u32)1);
	RAM(temp_12544._8)._4 = temp_48384._4;
	temp_48384._4 = RAM(temp_12544._8)._4;
	SF = temp_48384._4s < ((i32)0);
	temp_48384._4 = RAM(temp_12544._8)._4;
	ZF = temp_48384._4 == ((u32)0);
	temp_48384._4 = RAM(temp_12544._8)._4;
	temp_76800._4 = temp_48384._4 & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_10160B:; // CMP dword ptr [RBP + -0x8],0x0
	temp_12544._8 = RBP + ((u64)-8);
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
	ADDR_10160F:; // JNS 0x001015c8
	temp_51712._1 = !SF;
	if (temp_51712._1) goto ADDR_1015C8;
	ADDR_101611:; // CMP dword ptr [RBP + -0x4],0x0
	temp_12544._8 = RBP + ((u64)-4);
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
	ADDR_101615:; // JNZ 0x00101633
	temp_50816._1 = !ZF;
	if (temp_50816._1) goto ADDR_101633;
	ADDR_101617:; // MOV EAX,dword ptr [0x00105040]
	EAX = RAM(1069120)._4;
	RAX = EAX;
	ADDR_10161D:; // LEA EDX,[RAX + 0x1]
	temp_12544._8 = RAX + ((u64)1);
	EDX = (temp_12544._8 / 0x1);
	RDX = EDX;
	ADDR_101620:; // MOV dword ptr [0x00105040],EDX
	RAM(1069120)._4 = EDX;
	ADDR_101626:; // CDQE
	RAXs = EAXs;
	ADDR_101628:; // LEA RDX,[0x105060]
	RDX = ((u64)0x105060);
	ADDR_10162F:; // MOV byte ptr [RAX + RDX*0x1],0x30
	temp_13056._8 = RDX * ((u64)1);
	temp_13312._8 = RAX + temp_13056._8;
	temp_47872._1 = ((u8)48);
	RAM(temp_13312._8)._1 = temp_47872._1;
	ADDR_101633:; // MOV EAX,dword ptr [0x00105040]
	EAX = RAM(1069120)._4;
	RAX = EAX;
	ADDR_101639:; // LEA EDX,[RAX + 0x1]
	temp_12544._8 = RAX + ((u64)1);
	EDX = (temp_12544._8 / 0x1);
	RDX = EDX;
	ADDR_10163C:; // MOV dword ptr [0x00105040],EDX
	RAM(1069120)._4 = EDX;
	ADDR_101642:; // CDQE
	RAXs = EAXs;
	ADDR_101644:; // LEA RDX,[0x105060]
	RDX = ((u64)0x105060);
	ADDR_10164B:; // MOV byte ptr [RAX + RDX*0x1],0x0
	temp_13056._8 = RDX * ((u64)1);
	temp_13312._8 = RAX + temp_13056._8;
	temp_47872._1 = ((u8)0);
	RAM(temp_13312._8)._1 = temp_47872._1;
	ADDR_10164F:; // MOV RAX,qword ptr [RBP + -0x10]
	temp_12544._8 = RBP + ((u64)-16);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RAX = temp_48512._8;
	ADDR_101653:; // POP RBP
	RBP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_101654:; // RET
	RIP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	return;
	
}
