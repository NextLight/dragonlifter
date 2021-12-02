#include "dragonlifter.h"

void bin() {
	ADDR_400681:; // PUSH RBP
	temp_59264._8 = RBP;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_400682:; // MOV RBP,RSP
	RBP = RSP;
	ADDR_400685:; // MOV dword ptr [RBP + -0x24],EDI
	temp_12544._8 = RBP + ((u64)-36);
	temp_48256._4 = EDI;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_400688:; // MOV EAX,dword ptr [0x00602040]
	EAX = RAM(6299712)._4;
	RAX = EAX;
	ADDR_40068E:; // MOVSXD RDX,EAX
	RDXs = EAXs;
	ADDR_400691:; // LEA RAX,[0x602060]
	RAX = ((u64)0x602060);
	ADDR_400698:; // ADD RAX,RDX
	CF = (u64)(RAX + RDX) < RAX;
	OF = SIGN(8, RAXs) == SIGN(8, RDXs) && SIGN(8, (i64)(RAXs + RDXs)) != SIGN(8, RDXs);
	RAX = RAX + RDX;
	SF = RAXs < ((i64)0);
	ZF = RAX == ((u64)0);
	temp_76800._8 = RAX & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_40069B:; // MOV qword ptr [RBP + -0x10],RAX
	temp_12544._8 = RBP + ((u64)-16);
	temp_48512._8 = RAX;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_40069F:; // MOV EAX,dword ptr [0x00602040]
	EAX = RAM(6299712)._4;
	RAX = EAX;
	ADDR_4006A5:; // LEA EDX,[RAX + 0x1]
	temp_12544._8 = RAX + ((u64)1);
	EDX = (temp_12544._8 / 0x1);
	RDX = EDX;
	ADDR_4006A8:; // MOV dword ptr [0x00602040],EDX
	RAM(6299712)._4 = EDX;
	ADDR_4006AE:; // MOVSXD RDX,EAX
	RDXs = EAXs;
	ADDR_4006B1:; // LEA RAX,[0x602060]
	RAX = ((u64)0x602060);
	ADDR_4006B8:; // MOV byte ptr [RDX + RAX*0x1],0x30
	temp_13056._8 = RAX * ((u64)1);
	temp_13312._8 = RDX + temp_13056._8;
	temp_47872._1 = ((u8)48);
	RAM(temp_13312._8)._1 = temp_47872._1;
	ADDR_4006BC:; // MOV EAX,dword ptr [0x00602040]
	EAX = RAM(6299712)._4;
	RAX = EAX;
	ADDR_4006C2:; // LEA EDX,[RAX + 0x1]
	temp_12544._8 = RAX + ((u64)1);
	EDX = (temp_12544._8 / 0x1);
	RDX = EDX;
	ADDR_4006C5:; // MOV dword ptr [0x00602040],EDX
	RAM(6299712)._4 = EDX;
	ADDR_4006CB:; // MOVSXD RDX,EAX
	RDXs = EAXs;
	ADDR_4006CE:; // LEA RAX,[0x602060]
	RAX = ((u64)0x602060);
	ADDR_4006D5:; // MOV byte ptr [RDX + RAX*0x1],0x62
	temp_13056._8 = RAX * ((u64)1);
	temp_13312._8 = RDX + temp_13056._8;
	temp_47872._1 = ((u8)98);
	RAM(temp_13312._8)._1 = temp_47872._1;
	ADDR_4006D9:; // MOV dword ptr [RBP + -0x4],0x0
	temp_12544._8 = RBP + ((u64)-4);
	temp_48384._4 = ((u32)0);
	RAM(temp_12544._8)._4 = temp_48384._4;
	ADDR_4006E0:; // MOV dword ptr [RBP + -0x8],0x1f
	temp_12544._8 = RBP + ((u64)-8);
	temp_48384._4 = ((u32)31);
	RAM(temp_12544._8)._4 = temp_48384._4;
	ADDR_4006E7:; // JMP 0x0040072d
	goto ADDR_40072D;
	ADDR_4006E9:; // MOV EAX,dword ptr [RBP + -0x8]
	temp_12544._8 = RBP + ((u64)-8);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_4006EC:; // MOV EDX,dword ptr [RBP + -0x24]
	temp_12544._8 = RBP + ((u64)-36);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EDX = temp_48256._4;
	RDX = EDX;
	ADDR_4006EF:; // MOV ECX,EAX
	ECX = EAX;
	RCX = ECX;
	ADDR_4006F1:; // SAR EDX,CL
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
	ADDR_4006F3:; // MOV EAX,EDX
	EAX = EDX;
	RAX = EAX;
	ADDR_4006F5:; // AND EAX,0x1
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
	ADDR_4006F8:; // MOV dword ptr [RBP + -0x14],EAX
	temp_12544._8 = RBP + ((u64)-20);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_4006FB:; // MOV EAX,dword ptr [RBP + -0x14]
	temp_12544._8 = RBP + ((u64)-20);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_4006FE:; // OR dword ptr [RBP + -0x4],EAX
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
	ADDR_400701:; // CMP dword ptr [RBP + -0x4],0x0
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
	ADDR_400705:; // JZ 0x00400729
	if (ZF) goto ADDR_400729;
	ADDR_400707:; // MOV EAX,dword ptr [RBP + -0x14]
	temp_12544._8 = RBP + ((u64)-20);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_40070A:; // LEA ECX,[RAX + 0x30]
	temp_12544._8 = RAX + ((u64)48);
	ECX = (temp_12544._8 / 0x1);
	RCX = ECX;
	ADDR_40070D:; // MOV EAX,dword ptr [0x00602040]
	EAX = RAM(6299712)._4;
	RAX = EAX;
	ADDR_400713:; // LEA EDX,[RAX + 0x1]
	temp_12544._8 = RAX + ((u64)1);
	EDX = (temp_12544._8 / 0x1);
	RDX = EDX;
	ADDR_400716:; // MOV dword ptr [0x00602040],EDX
	RAM(6299712)._4 = EDX;
	ADDR_40071C:; // MOVSXD RDX,EAX
	RDXs = EAXs;
	ADDR_40071F:; // LEA RAX,[0x602060]
	RAX = ((u64)0x602060);
	ADDR_400726:; // MOV byte ptr [RDX + RAX*0x1],CL
	temp_13056._8 = RAX * ((u64)1);
	temp_13312._8 = RDX + temp_13056._8;
	temp_47744._1 = CL;
	RAM(temp_13312._8)._1 = temp_47744._1;
	ADDR_400729:; // SUB dword ptr [RBP + -0x8],0x1
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
	ADDR_40072D:; // CMP dword ptr [RBP + -0x8],0x0
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
	ADDR_400731:; // JNS 0x004006e9
	temp_51712._1 = !SF;
	if (temp_51712._1) goto ADDR_4006E9;
	ADDR_400733:; // CMP dword ptr [RBP + -0x4],0x0
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
	ADDR_400737:; // JNZ 0x00400756
	temp_50816._1 = !ZF;
	if (temp_50816._1) goto ADDR_400756;
	ADDR_400739:; // MOV EAX,dword ptr [0x00602040]
	EAX = RAM(6299712)._4;
	RAX = EAX;
	ADDR_40073F:; // LEA EDX,[RAX + 0x1]
	temp_12544._8 = RAX + ((u64)1);
	EDX = (temp_12544._8 / 0x1);
	RDX = EDX;
	ADDR_400742:; // MOV dword ptr [0x00602040],EDX
	RAM(6299712)._4 = EDX;
	ADDR_400748:; // MOVSXD RDX,EAX
	RDXs = EAXs;
	ADDR_40074B:; // LEA RAX,[0x602060]
	RAX = ((u64)0x602060);
	ADDR_400752:; // MOV byte ptr [RDX + RAX*0x1],0x30
	temp_13056._8 = RAX * ((u64)1);
	temp_13312._8 = RDX + temp_13056._8;
	temp_47872._1 = ((u8)48);
	RAM(temp_13312._8)._1 = temp_47872._1;
	ADDR_400756:; // MOV EAX,dword ptr [0x00602040]
	EAX = RAM(6299712)._4;
	RAX = EAX;
	ADDR_40075C:; // LEA EDX,[RAX + 0x1]
	temp_12544._8 = RAX + ((u64)1);
	EDX = (temp_12544._8 / 0x1);
	RDX = EDX;
	ADDR_40075F:; // MOV dword ptr [0x00602040],EDX
	RAM(6299712)._4 = EDX;
	ADDR_400765:; // MOVSXD RDX,EAX
	RDXs = EAXs;
	ADDR_400768:; // LEA RAX,[0x602060]
	RAX = ((u64)0x602060);
	ADDR_40076F:; // MOV byte ptr [RDX + RAX*0x1],0x0
	temp_13056._8 = RAX * ((u64)1);
	temp_13312._8 = RDX + temp_13056._8;
	temp_47872._1 = ((u8)0);
	RAM(temp_13312._8)._1 = temp_47872._1;
	ADDR_400773:; // MOV RAX,qword ptr [RBP + -0x10]
	temp_12544._8 = RBP + ((u64)-16);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RAX = temp_48512._8;
	ADDR_400777:; // POP RBP
	RBP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_400778:; // RET
	RIP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	return;
	
}
