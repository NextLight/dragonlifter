#include "dragonlifter.h"

void int_to_string() {
	ADDR_4003D2:; // PUSH RBP
	temp_59264._8 = RBP;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_4003D3:; // MOV RBP,RSP
	RBP = RSP;
	ADDR_4003D6:; // MOV dword ptr [RBP + -0x24],EDI
	temp_12544._8 = RBP + ((u64)-36);
	temp_48256._4 = EDI;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_4003D9:; // MOV EAX,dword ptr [0x00601820]
	EAX = RAM(6297632)._4;
	RAX = EAX;
	ADDR_4003DF:; // MOV dword ptr [RBP + -0xc],EAX
	temp_12544._8 = RBP + ((u64)-12);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_4003E2:; // CMP dword ptr [RBP + -0x24],0x0
	temp_12544._8 = RBP + ((u64)-36);
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
	ADDR_4003E6:; // JNZ 0x00400437
	temp_50816._1 = !ZF;
	if (temp_50816._1) goto ADDR_400437;
	ADDR_4003E8:; // MOV EAX,dword ptr [0x00601820]
	EAX = RAM(6297632)._4;
	RAX = EAX;
	ADDR_4003EE:; // LEA EDX,[RAX + 0x1]
	temp_12544._8 = RAX + ((u64)1);
	EDX = (temp_12544._8 / 0x1);
	RDX = EDX;
	ADDR_4003F1:; // MOV dword ptr [0x00601820],EDX
	RAM(6297632)._4 = EDX;
	ADDR_4003F7:; // MOVSXD RDX,EAX
	RDXs = EAXs;
	ADDR_4003FA:; // LEA RAX,[0x601840]
	RAX = ((u64)0x601840);
	ADDR_400401:; // MOV byte ptr [RDX + RAX*0x1],0x30
	temp_13056._8 = RAX * ((u64)1);
	temp_13312._8 = RDX + temp_13056._8;
	temp_47872._1 = ((u8)48);
	RAM(temp_13312._8)._1 = temp_47872._1;
	ADDR_400405:; // MOV EAX,dword ptr [0x00601820]
	EAX = RAM(6297632)._4;
	RAX = EAX;
	ADDR_40040B:; // LEA EDX,[RAX + 0x1]
	temp_12544._8 = RAX + ((u64)1);
	EDX = (temp_12544._8 / 0x1);
	RDX = EDX;
	ADDR_40040E:; // MOV dword ptr [0x00601820],EDX
	RAM(6297632)._4 = EDX;
	ADDR_400414:; // MOVSXD RDX,EAX
	RDXs = EAXs;
	ADDR_400417:; // LEA RAX,[0x601840]
	RAX = ((u64)0x601840);
	ADDR_40041E:; // MOV byte ptr [RDX + RAX*0x1],0x0
	temp_13056._8 = RAX * ((u64)1);
	temp_13312._8 = RDX + temp_13056._8;
	temp_47872._1 = ((u8)0);
	RAM(temp_13312._8)._1 = temp_47872._1;
	ADDR_400422:; // MOV EAX,dword ptr [RBP + -0xc]
	temp_12544._8 = RBP + ((u64)-12);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_400425:; // MOVSXD RDX,EAX
	RDXs = EAXs;
	ADDR_400428:; // LEA RAX,[0x601840]
	RAX = ((u64)0x601840);
	ADDR_40042F:; // ADD RAX,RDX
	CF = (u64)(RAX + RDX) < RAX;
	OF = SIGN(8, RAXs) == SIGN(8, RDXs) && SIGN(8, (i64)(RAXs + RDXs)) != SIGN(8, RDXs);
	RAX = RAX + RDX;
	SF = RAXs < ((i64)0);
	ZF = RAX == ((u64)0);
	temp_76800._8 = RAX & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_400432:; // JMP 0x00400608
	goto ADDR_400608;
	ADDR_400437:; // MOV EAX,dword ptr [RBP + -0x24]
	temp_12544._8 = RBP + ((u64)-36);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_40043A:; // SHR EAX,0x1f
	temp_357120._4 = ((u32)31) & ((u32)31);
	temp_357248._4 = EAX;
	EAX = EAX >> temp_357120._4;
	RAX = EAX;
	temp_90368._1 = temp_357120._4 != ((u32)0);
	temp_90496._4 = temp_357120._4 - ((u32)1);
	temp_90624._4 = temp_357248._4 >> temp_90496._4;
	temp_90752._4 = temp_90624._4 & ((u32)1);
	temp_91008._1 = temp_90752._4 != ((u32)0);
	temp_91136._1 = !temp_90368._1;
	temp_91264._1 = temp_91136._1 & CF;
	temp_91392._1 = temp_90368._1 & temp_91008._1;
	CF = temp_91264._1 | temp_91392._1;
	temp_91776._1 = temp_357120._4 == ((u32)1);
	temp_92032._1 = temp_357248._4s < ((i32)0);
	temp_92160._1 = !temp_91776._1;
	temp_92288._1 = temp_92160._1 & OF;
	temp_92416._1 = temp_91776._1 & temp_92032._1;
	OF = temp_92288._1 | temp_92416._1;
	temp_77440._1 = temp_357120._4 != ((u32)0);
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
	ADDR_40043D:; // MOVZX EAX,AL
	EAX = AL;
	RAX = EAX;
	ADDR_400440:; // MOV dword ptr [RBP + -0x10],EAX
	temp_12544._8 = RBP + ((u64)-16);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_400443:; // CMP dword ptr [RBP + -0x10],0x0
	temp_12544._8 = RBP + ((u64)-16);
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
	ADDR_400447:; // JZ 0x00400450
	if (ZF) goto ADDR_400450;
	ADDR_400449:; // MOV EAX,dword ptr [RBP + -0x24]
	temp_12544._8 = RBP + ((u64)-36);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_40044C:; // NEG EAX
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
	ADDR_40044E:; // JMP 0x00400453
	goto ADDR_400453;
	ADDR_400450:; // MOV EAX,dword ptr [RBP + -0x24]
	temp_12544._8 = RBP + ((u64)-36);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_400453:; // MOV dword ptr [RBP + -0x4],EAX
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_400456:; // MOV dword ptr [RBP + -0x14],0x0
	temp_12544._8 = RBP + ((u64)-20);
	temp_48384._4 = ((u32)0);
	RAM(temp_12544._8)._4 = temp_48384._4;
	ADDR_40045D:; // JMP 0x004004be
	goto ADDR_4004BE;
	ADDR_40045F:; // MOV ECX,dword ptr [RBP + -0x4]
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = RAM(temp_12544._8)._4;
	ECX = temp_48256._4;
	RCX = ECX;
	ADDR_400462:; // MOV EDX,0x66666667
	RDX = ((u64)0x66666667);
	ADDR_400467:; // MOV EAX,ECX
	EAX = ECX;
	RAX = EAX;
	ADDR_400469:; // IMUL EDX
	temp_217472._8s = EAXs;
	temp_217600._8s = EDXs;
	temp_217856._8 = temp_217472._8 * temp_217600._8;
	EDX = (temp_217856._8 / 0x100000000);
	RDX = EDX;
	EAX = (temp_217856._8 / 0x1);
	RAX = EAX;
	temp_80768._8s = EAXs;
	CF = temp_80768._8 != temp_217856._8;
	OF = CF;
	ADDR_40046B:; // SAR EDX,0x2
	temp_333312._4 = ((u32)2) & ((u32)31);
	temp_333440._4 = EDX;
	EDXs = EDXs >> temp_333312._4;
	RDX = EDX;
	temp_88448._1 = temp_333312._4 != ((u32)0);
	temp_88576._4 = temp_333312._4 - ((u32)1);
	temp_88704._4s = temp_333440._4s >> temp_88576._4;
	temp_88832._4 = temp_88704._4 & ((u32)1);
	temp_89088._1 = temp_88832._4 != ((u32)0);
	temp_89216._1 = !temp_88448._1;
	temp_89344._1 = temp_89216._1 & CF;
	temp_89472._1 = temp_88448._1 & temp_89088._1;
	CF = temp_89344._1 | temp_89472._1;
	temp_89856._1 = temp_333312._4 == ((u32)1);
	temp_89984._1 = !temp_89856._1;
	OF = temp_89984._1 & OF;
	temp_77440._1 = temp_333312._4 != ((u32)0);
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
	ADDR_40046E:; // MOV EAX,ECX
	EAX = ECX;
	RAX = EAX;
	ADDR_400470:; // SAR EAX,0x1f
	temp_333312._4 = ((u32)31) & ((u32)31);
	temp_333440._4 = EAX;
	EAXs = EAXs >> temp_333312._4;
	RAX = EAX;
	temp_88448._1 = temp_333312._4 != ((u32)0);
	temp_88576._4 = temp_333312._4 - ((u32)1);
	temp_88704._4s = temp_333440._4s >> temp_88576._4;
	temp_88832._4 = temp_88704._4 & ((u32)1);
	temp_89088._1 = temp_88832._4 != ((u32)0);
	temp_89216._1 = !temp_88448._1;
	temp_89344._1 = temp_89216._1 & CF;
	temp_89472._1 = temp_88448._1 & temp_89088._1;
	CF = temp_89344._1 | temp_89472._1;
	temp_89856._1 = temp_333312._4 == ((u32)1);
	temp_89984._1 = !temp_89856._1;
	OF = temp_89984._1 & OF;
	temp_77440._1 = temp_333312._4 != ((u32)0);
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
	ADDR_400473:; // SUB EDX,EAX
	CF = EDX < EAX;
	OF = SIGN(4, EDXs) != SIGN(4, EAXs) && SIGN(4, (i32)(EDXs - EAXs)) == SIGN(4, EAXs);
	EDX = EDX - EAX;
	RDX = EDX;
	SF = EDXs < ((i32)0);
	ZF = EDX == ((u32)0);
	temp_76800._4 = EDX & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_400475:; // MOV EAX,EDX
	EAX = EDX;
	RAX = EAX;
	ADDR_400477:; // SHL EAX,0x2
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
	ADDR_40047A:; // ADD EAX,EDX
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
	ADDR_40047C:; // ADD EAX,EAX
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
	ADDR_40047E:; // SUB ECX,EAX
	CF = ECX < EAX;
	OF = SIGN(4, ECXs) != SIGN(4, EAXs) && SIGN(4, (i32)(ECXs - EAXs)) == SIGN(4, EAXs);
	ECX = ECX - EAX;
	RCX = ECX;
	SF = ECXs < ((i32)0);
	ZF = ECX == ((u32)0);
	temp_76800._4 = ECX & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_400480:; // MOV EDX,ECX
	EDX = ECX;
	RDX = EDX;
	ADDR_400482:; // MOV EAX,EDX
	EAX = EDX;
	RAX = EAX;
	ADDR_400484:; // LEA ECX,[RAX + 0x30]
	temp_12544._8 = RAX + ((u64)48);
	ECX = (temp_12544._8 / 0x1);
	RCX = ECX;
	ADDR_400487:; // MOV EAX,dword ptr [0x00601820]
	EAX = RAM(6297632)._4;
	RAX = EAX;
	ADDR_40048D:; // LEA EDX,[RAX + 0x1]
	temp_12544._8 = RAX + ((u64)1);
	EDX = (temp_12544._8 / 0x1);
	RDX = EDX;
	ADDR_400490:; // MOV dword ptr [0x00601820],EDX
	RAM(6297632)._4 = EDX;
	ADDR_400496:; // MOVSXD RDX,EAX
	RDXs = EAXs;
	ADDR_400499:; // LEA RAX,[0x601840]
	RAX = ((u64)0x601840);
	ADDR_4004A0:; // MOV byte ptr [RDX + RAX*0x1],CL
	temp_13056._8 = RAX * ((u64)1);
	temp_13312._8 = RDX + temp_13056._8;
	temp_47744._1 = CL;
	RAM(temp_13312._8)._1 = temp_47744._1;
	ADDR_4004A3:; // MOV ECX,dword ptr [RBP + -0x4]
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = RAM(temp_12544._8)._4;
	ECX = temp_48256._4;
	RCX = ECX;
	ADDR_4004A6:; // MOV EDX,0x66666667
	RDX = ((u64)0x66666667);
	ADDR_4004AB:; // MOV EAX,ECX
	EAX = ECX;
	RAX = EAX;
	ADDR_4004AD:; // IMUL EDX
	temp_217472._8s = EAXs;
	temp_217600._8s = EDXs;
	temp_217856._8 = temp_217472._8 * temp_217600._8;
	EDX = (temp_217856._8 / 0x100000000);
	RDX = EDX;
	EAX = (temp_217856._8 / 0x1);
	RAX = EAX;
	temp_80768._8s = EAXs;
	CF = temp_80768._8 != temp_217856._8;
	OF = CF;
	ADDR_4004AF:; // SAR EDX,0x2
	temp_333312._4 = ((u32)2) & ((u32)31);
	temp_333440._4 = EDX;
	EDXs = EDXs >> temp_333312._4;
	RDX = EDX;
	temp_88448._1 = temp_333312._4 != ((u32)0);
	temp_88576._4 = temp_333312._4 - ((u32)1);
	temp_88704._4s = temp_333440._4s >> temp_88576._4;
	temp_88832._4 = temp_88704._4 & ((u32)1);
	temp_89088._1 = temp_88832._4 != ((u32)0);
	temp_89216._1 = !temp_88448._1;
	temp_89344._1 = temp_89216._1 & CF;
	temp_89472._1 = temp_88448._1 & temp_89088._1;
	CF = temp_89344._1 | temp_89472._1;
	temp_89856._1 = temp_333312._4 == ((u32)1);
	temp_89984._1 = !temp_89856._1;
	OF = temp_89984._1 & OF;
	temp_77440._1 = temp_333312._4 != ((u32)0);
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
	ADDR_4004B2:; // MOV EAX,ECX
	EAX = ECX;
	RAX = EAX;
	ADDR_4004B4:; // SAR EAX,0x1f
	temp_333312._4 = ((u32)31) & ((u32)31);
	temp_333440._4 = EAX;
	EAXs = EAXs >> temp_333312._4;
	RAX = EAX;
	temp_88448._1 = temp_333312._4 != ((u32)0);
	temp_88576._4 = temp_333312._4 - ((u32)1);
	temp_88704._4s = temp_333440._4s >> temp_88576._4;
	temp_88832._4 = temp_88704._4 & ((u32)1);
	temp_89088._1 = temp_88832._4 != ((u32)0);
	temp_89216._1 = !temp_88448._1;
	temp_89344._1 = temp_89216._1 & CF;
	temp_89472._1 = temp_88448._1 & temp_89088._1;
	CF = temp_89344._1 | temp_89472._1;
	temp_89856._1 = temp_333312._4 == ((u32)1);
	temp_89984._1 = !temp_89856._1;
	OF = temp_89984._1 & OF;
	temp_77440._1 = temp_333312._4 != ((u32)0);
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
	ADDR_4004B7:; // SUB EDX,EAX
	CF = EDX < EAX;
	OF = SIGN(4, EDXs) != SIGN(4, EAXs) && SIGN(4, (i32)(EDXs - EAXs)) == SIGN(4, EAXs);
	EDX = EDX - EAX;
	RDX = EDX;
	SF = EDXs < ((i32)0);
	ZF = EDX == ((u32)0);
	temp_76800._4 = EDX & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_4004B9:; // MOV EAX,EDX
	EAX = EDX;
	RAX = EAX;
	ADDR_4004BB:; // MOV dword ptr [RBP + -0x4],EAX
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_4004BE:; // CMP dword ptr [RBP + -0x4],0x0
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
	ADDR_4004C2:; // JG 0x0040045f
	temp_52992._1 = !ZF;
	temp_53120._1 = OF == SF;
	temp_53376._1 = temp_52992._1 && temp_53120._1;
	if (temp_53376._1) goto ADDR_40045F;
	ADDR_4004C4:; // CMP dword ptr [RBP + -0x10],0x0
	temp_12544._8 = RBP + ((u64)-16);
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
	ADDR_4004C8:; // JZ 0x004004e7
	if (ZF) goto ADDR_4004E7;
	ADDR_4004CA:; // MOV EAX,dword ptr [0x00601820]
	EAX = RAM(6297632)._4;
	RAX = EAX;
	ADDR_4004D0:; // LEA EDX,[RAX + 0x1]
	temp_12544._8 = RAX + ((u64)1);
	EDX = (temp_12544._8 / 0x1);
	RDX = EDX;
	ADDR_4004D3:; // MOV dword ptr [0x00601820],EDX
	RAM(6297632)._4 = EDX;
	ADDR_4004D9:; // MOVSXD RDX,EAX
	RDXs = EAXs;
	ADDR_4004DC:; // LEA RAX,[0x601840]
	RAX = ((u64)0x601840);
	ADDR_4004E3:; // MOV byte ptr [RDX + RAX*0x1],0x2d
	temp_13056._8 = RAX * ((u64)1);
	temp_13312._8 = RDX + temp_13056._8;
	temp_47872._1 = ((u8)45);
	RAM(temp_13312._8)._1 = temp_47872._1;
	ADDR_4004E7:; // MOV dword ptr [RBP + -0x8],0x0
	temp_12544._8 = RBP + ((u64)-8);
	temp_48384._4 = ((u32)0);
	RAM(temp_12544._8)._4 = temp_48384._4;
	ADDR_4004EE:; // JMP 0x004005c0
	goto ADDR_4005C0;
	ADDR_4004F3:; // MOV EDX,dword ptr [RBP + -0xc]
	temp_12544._8 = RBP + ((u64)-12);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EDX = temp_48256._4;
	RDX = EDX;
	ADDR_4004F6:; // MOV EAX,dword ptr [RBP + -0x8]
	temp_12544._8 = RBP + ((u64)-8);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_4004F9:; // ADD EAX,EDX
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
	ADDR_4004FB:; // MOVSXD RDX,EAX
	RDXs = EAXs;
	ADDR_4004FE:; // LEA RAX,[0x601840]
	RAX = ((u64)0x601840);
	ADDR_400505:; // MOVZX ESI,byte ptr [RDX + RAX*0x1]
	temp_13056._8 = RAX * ((u64)1);
	temp_13312._8 = RDX + temp_13056._8;
	temp_47872._1 = RAM(temp_13312._8)._1;
	ESI = temp_47872._1;
	RSI = ESI;
	ADDR_400509:; // MOV EAX,dword ptr [0x00601820]
	EAX = RAM(6297632)._4;
	RAX = EAX;
	ADDR_40050F:; // SUB EAX,0x1
	CF = EAX < ((u32)1);
	OF = SIGN(4, EAXs) != SIGN(4, ((i32)1)) && SIGN(4, (i32)(EAXs - ((i32)1))) == SIGN(4, ((i32)1));
	EAX = EAX - ((u32)1);
	RAX = EAX;
	SF = EAXs < ((i32)0);
	ZF = EAX == ((u32)0);
	temp_76800._4 = EAX & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_400512:; // SUB EAX,dword ptr [RBP + -0x8]
	temp_12544._8 = RBP + ((u64)-8);
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
	ADDR_400515:; // MOVSXD RDX,EAX
	RDXs = EAXs;
	ADDR_400518:; // LEA RAX,[0x601840]
	RAX = ((u64)0x601840);
	ADDR_40051F:; // MOVZX ECX,byte ptr [RDX + RAX*0x1]
	temp_13056._8 = RAX * ((u64)1);
	temp_13312._8 = RDX + temp_13056._8;
	temp_47872._1 = RAM(temp_13312._8)._1;
	ECX = temp_47872._1;
	RCX = ECX;
	ADDR_400523:; // MOV EDX,dword ptr [RBP + -0xc]
	temp_12544._8 = RBP + ((u64)-12);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EDX = temp_48256._4;
	RDX = EDX;
	ADDR_400526:; // MOV EAX,dword ptr [RBP + -0x8]
	temp_12544._8 = RBP + ((u64)-8);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_400529:; // ADD EAX,EDX
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
	ADDR_40052B:; // XOR ESI,ECX
	CF = ((u8)0);
	OF = ((u8)0);
	ESI = ESI ^ ECX;
	RSI = ESI;
	SF = ESIs < ((i32)0);
	ZF = ESI == ((u32)0);
	temp_76800._4 = ESI & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_40052D:; // MOVSXD RCX,EAX
	RCXs = EAXs;
	ADDR_400530:; // LEA RDX,[0x601840]
	RDX = ((u64)0x601840);
	ADDR_400537:; // MOV byte ptr [RCX + RDX*0x1],SIL
	temp_13056._8 = RDX * ((u64)1);
	temp_13312._8 = RCX + temp_13056._8;
	temp_47744._1 = SIL;
	RAM(temp_13312._8)._1 = temp_47744._1;
	ADDR_40053B:; // MOVSXD RDX,EAX
	RDXs = EAXs;
	ADDR_40053E:; // LEA RAX,[0x601840]
	RAX = ((u64)0x601840);
	ADDR_400545:; // MOVZX ECX,byte ptr [RDX + RAX*0x1]
	temp_13056._8 = RAX * ((u64)1);
	temp_13312._8 = RDX + temp_13056._8;
	temp_47872._1 = RAM(temp_13312._8)._1;
	ECX = temp_47872._1;
	RCX = ECX;
	ADDR_400549:; // MOV EAX,dword ptr [0x00601820]
	EAX = RAM(6297632)._4;
	RAX = EAX;
	ADDR_40054F:; // SUB EAX,0x1
	CF = EAX < ((u32)1);
	OF = SIGN(4, EAXs) != SIGN(4, ((i32)1)) && SIGN(4, (i32)(EAXs - ((i32)1))) == SIGN(4, ((i32)1));
	EAX = EAX - ((u32)1);
	RAX = EAX;
	SF = EAXs < ((i32)0);
	ZF = EAX == ((u32)0);
	temp_76800._4 = EAX & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_400552:; // SUB EAX,dword ptr [RBP + -0x8]
	temp_12544._8 = RBP + ((u64)-8);
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
	ADDR_400555:; // MOVSXD RDX,EAX
	RDXs = EAXs;
	ADDR_400558:; // LEA RAX,[0x601840]
	RAX = ((u64)0x601840);
	ADDR_40055F:; // MOVZX EDX,byte ptr [RDX + RAX*0x1]
	temp_13056._8 = RAX * ((u64)1);
	temp_13312._8 = RDX + temp_13056._8;
	temp_47872._1 = RAM(temp_13312._8)._1;
	EDX = temp_47872._1;
	RDX = EDX;
	ADDR_400563:; // MOV EAX,dword ptr [0x00601820]
	EAX = RAM(6297632)._4;
	RAX = EAX;
	ADDR_400569:; // SUB EAX,0x1
	CF = EAX < ((u32)1);
	OF = SIGN(4, EAXs) != SIGN(4, ((i32)1)) && SIGN(4, (i32)(EAXs - ((i32)1))) == SIGN(4, ((i32)1));
	EAX = EAX - ((u32)1);
	RAX = EAX;
	SF = EAXs < ((i32)0);
	ZF = EAX == ((u32)0);
	temp_76800._4 = EAX & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_40056C:; // SUB EAX,dword ptr [RBP + -0x8]
	temp_12544._8 = RBP + ((u64)-8);
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
	ADDR_40056F:; // MOV ESI,ECX
	ESI = ECX;
	RSI = ESI;
	ADDR_400571:; // XOR ESI,EDX
	CF = ((u8)0);
	OF = ((u8)0);
	ESI = ESI ^ EDX;
	RSI = ESI;
	SF = ESIs < ((i32)0);
	ZF = ESI == ((u32)0);
	temp_76800._4 = ESI & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_400573:; // MOVSXD RCX,EAX
	RCXs = EAXs;
	ADDR_400576:; // LEA RDX,[0x601840]
	RDX = ((u64)0x601840);
	ADDR_40057D:; // MOV byte ptr [RCX + RDX*0x1],SIL
	temp_13056._8 = RDX * ((u64)1);
	temp_13312._8 = RCX + temp_13056._8;
	temp_47744._1 = SIL;
	RAM(temp_13312._8)._1 = temp_47744._1;
	ADDR_400581:; // MOVSXD RDX,EAX
	RDXs = EAXs;
	ADDR_400584:; // LEA RAX,[0x601840]
	RAX = ((u64)0x601840);
	ADDR_40058B:; // MOVZX ESI,byte ptr [RDX + RAX*0x1]
	temp_13056._8 = RAX * ((u64)1);
	temp_13312._8 = RDX + temp_13056._8;
	temp_47872._1 = RAM(temp_13312._8)._1;
	ESI = temp_47872._1;
	RSI = ESI;
	ADDR_40058F:; // MOV EDX,dword ptr [RBP + -0xc]
	temp_12544._8 = RBP + ((u64)-12);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EDX = temp_48256._4;
	RDX = EDX;
	ADDR_400592:; // MOV EAX,dword ptr [RBP + -0x8]
	temp_12544._8 = RBP + ((u64)-8);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_400595:; // ADD EAX,EDX
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
	ADDR_400597:; // MOVSXD RDX,EAX
	RDXs = EAXs;
	ADDR_40059A:; // LEA RAX,[0x601840]
	RAX = ((u64)0x601840);
	ADDR_4005A1:; // MOVZX ECX,byte ptr [RDX + RAX*0x1]
	temp_13056._8 = RAX * ((u64)1);
	temp_13312._8 = RDX + temp_13056._8;
	temp_47872._1 = RAM(temp_13312._8)._1;
	ECX = temp_47872._1;
	RCX = ECX;
	ADDR_4005A5:; // MOV EDX,dword ptr [RBP + -0xc]
	temp_12544._8 = RBP + ((u64)-12);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EDX = temp_48256._4;
	RDX = EDX;
	ADDR_4005A8:; // MOV EAX,dword ptr [RBP + -0x8]
	temp_12544._8 = RBP + ((u64)-8);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_4005AB:; // ADD EAX,EDX
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
	ADDR_4005AD:; // XOR ECX,ESI
	CF = ((u8)0);
	OF = ((u8)0);
	ECX = ECX ^ ESI;
	RCX = ECX;
	SF = ECXs < ((i32)0);
	ZF = ECX == ((u32)0);
	temp_76800._4 = ECX & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_4005AF:; // MOVSXD RDX,EAX
	RDXs = EAXs;
	ADDR_4005B2:; // LEA RAX,[0x601840]
	RAX = ((u64)0x601840);
	ADDR_4005B9:; // MOV byte ptr [RDX + RAX*0x1],CL
	temp_13056._8 = RAX * ((u64)1);
	temp_13312._8 = RDX + temp_13056._8;
	temp_47744._1 = CL;
	RAM(temp_13312._8)._1 = temp_47744._1;
	ADDR_4005BC:; // ADD dword ptr [RBP + -0x8],0x1
	temp_12544._8 = RBP + ((u64)-8);
	temp_48384._4 = RAM(temp_12544._8)._4;
	CF = (u32)(temp_48384._4 + ((u32)1)) < temp_48384._4;
	temp_48384._4 = RAM(temp_12544._8)._4;
	OF = SIGN(4, temp_48384._4s) == SIGN(4, ((i32)1)) && SIGN(4, (i32)(temp_48384._4s + ((i32)1))) != SIGN(4, ((i32)1));
	temp_48384._4 = RAM(temp_12544._8)._4;
	temp_48384._4 = temp_48384._4 + ((u32)1);
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
	ADDR_4005C0:; // MOV EAX,dword ptr [0x00601820]
	EAX = RAM(6297632)._4;
	RAX = EAX;
	ADDR_4005C6:; // SUB EAX,dword ptr [RBP + -0xc]
	temp_12544._8 = RBP + ((u64)-12);
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
	ADDR_4005C9:; // MOV EDX,EAX
	EDX = EAX;
	RDX = EDX;
	ADDR_4005CB:; // SHR EDX,0x1f
	temp_357120._4 = ((u32)31) & ((u32)31);
	temp_357248._4 = EDX;
	EDX = EDX >> temp_357120._4;
	RDX = EDX;
	temp_90368._1 = temp_357120._4 != ((u32)0);
	temp_90496._4 = temp_357120._4 - ((u32)1);
	temp_90624._4 = temp_357248._4 >> temp_90496._4;
	temp_90752._4 = temp_90624._4 & ((u32)1);
	temp_91008._1 = temp_90752._4 != ((u32)0);
	temp_91136._1 = !temp_90368._1;
	temp_91264._1 = temp_91136._1 & CF;
	temp_91392._1 = temp_90368._1 & temp_91008._1;
	CF = temp_91264._1 | temp_91392._1;
	temp_91776._1 = temp_357120._4 == ((u32)1);
	temp_92032._1 = temp_357248._4s < ((i32)0);
	temp_92160._1 = !temp_91776._1;
	temp_92288._1 = temp_92160._1 & OF;
	temp_92416._1 = temp_91776._1 & temp_92032._1;
	OF = temp_92288._1 | temp_92416._1;
	temp_77440._1 = temp_357120._4 != ((u32)0);
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
	ADDR_4005CE:; // ADD EAX,EDX
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
	ADDR_4005D0:; // SAR EAX,1
	temp_48768._1 = ((u8)1);
	temp_332288._4 = EAX & ((u32)1);
	CF = temp_332288._4 != ((u32)0);
	OF = ((u8)0);
	EAXs = EAXs >> ((u32)1);
	RAX = EAX;
	SF = EAXs < ((i32)0);
	ZF = EAX == ((u32)0);
	temp_76800._4 = EAX & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_4005D2:; // CMP dword ptr [RBP + -0x8],EAX
	temp_12544._8 = RBP + ((u64)-8);
	temp_48256._4 = RAM(temp_12544._8)._4;
	CF = temp_48256._4 < EAX;
	temp_48256._4 = RAM(temp_12544._8)._4;
	OF = SIGN(4, temp_48256._4s) != SIGN(4, EAXs) && SIGN(4, (i32)(temp_48256._4s - EAXs)) == SIGN(4, EAXs);
	temp_48256._4 = RAM(temp_12544._8)._4;
	temp_165376._4 = temp_48256._4 - EAX;
	SF = temp_165376._4s < ((i32)0);
	ZF = temp_165376._4 == ((u32)0);
	temp_76800._4 = temp_165376._4 & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_4005D5:; // JL 0x004004f3
	temp_52224._1 = OF != SF;
	if (temp_52224._1) goto ADDR_4004F3;
	ADDR_4005DB:; // MOV EAX,dword ptr [0x00601820]
	EAX = RAM(6297632)._4;
	RAX = EAX;
	ADDR_4005E1:; // LEA EDX,[RAX + 0x1]
	temp_12544._8 = RAX + ((u64)1);
	EDX = (temp_12544._8 / 0x1);
	RDX = EDX;
	ADDR_4005E4:; // MOV dword ptr [0x00601820],EDX
	RAM(6297632)._4 = EDX;
	ADDR_4005EA:; // MOVSXD RDX,EAX
	RDXs = EAXs;
	ADDR_4005ED:; // LEA RAX,[0x601840]
	RAX = ((u64)0x601840);
	ADDR_4005F4:; // MOV byte ptr [RDX + RAX*0x1],0x0
	temp_13056._8 = RAX * ((u64)1);
	temp_13312._8 = RDX + temp_13056._8;
	temp_47872._1 = ((u8)0);
	RAM(temp_13312._8)._1 = temp_47872._1;
	ADDR_4005F8:; // MOV EAX,dword ptr [RBP + -0xc]
	temp_12544._8 = RBP + ((u64)-12);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_4005FB:; // MOVSXD RDX,EAX
	RDXs = EAXs;
	ADDR_4005FE:; // LEA RAX,[0x601840]
	RAX = ((u64)0x601840);
	ADDR_400605:; // ADD RAX,RDX
	CF = (u64)(RAX + RDX) < RAX;
	OF = SIGN(8, RAXs) == SIGN(8, RDXs) && SIGN(8, (i64)(RAXs + RDXs)) != SIGN(8, RDXs);
	RAX = RAX + RDX;
	SF = RAXs < ((i64)0);
	ZF = RAX == ((u64)0);
	temp_76800._8 = RAX & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_400608:; // POP RBP
	RBP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_400609:; // RET
	RIP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	return;
	
}
