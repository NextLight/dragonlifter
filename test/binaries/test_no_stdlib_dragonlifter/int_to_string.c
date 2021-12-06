#include "dragonlifter.h"

void int_to_string() {
	ADDR_1012AC:; // ENDBR64
	
	ADDR_1012B0:; // PUSH RBP
	temp_59264._8 = RBP;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_1012B1:; // MOV RBP,RSP
	RBP = RSP;
	ADDR_1012B4:; // MOV dword ptr [RBP + -0x24],EDI
	temp_12544._8 = RBP + ((u64)-36);
	temp_48256._4 = EDI;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_1012B7:; // MOV EAX,dword ptr [0x00104820]
	EAX = RAM(1067040)._4;
	RAX = EAX;
	ADDR_1012BD:; // MOV dword ptr [RBP + -0xc],EAX
	temp_12544._8 = RBP + ((u64)-12);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_1012C0:; // CMP dword ptr [RBP + -0x24],0x0
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
	ADDR_1012C4:; // JNZ 0x00101312
	temp_50816._1 = !ZF;
	if (temp_50816._1) goto ADDR_101312;
	ADDR_1012C6:; // MOV EAX,dword ptr [0x00104820]
	EAX = RAM(1067040)._4;
	RAX = EAX;
	ADDR_1012CC:; // LEA EDX,[RAX + 0x1]
	temp_12544._8 = RAX + ((u64)1);
	EDX = (temp_12544._8 / 0x1);
	RDX = EDX;
	ADDR_1012CF:; // MOV dword ptr [0x00104820],EDX
	RAM(1067040)._4 = EDX;
	ADDR_1012D5:; // CDQE
	RAXs = EAXs;
	ADDR_1012D7:; // LEA RDX,[0x104840]
	RDX = ((u64)0x104840);
	ADDR_1012DE:; // MOV byte ptr [RAX + RDX*0x1],0x30
	temp_13056._8 = RDX * ((u64)1);
	temp_13312._8 = RAX + temp_13056._8;
	temp_47872._1 = ((u8)48);
	RAM(temp_13312._8)._1 = temp_47872._1;
	ADDR_1012E2:; // MOV EAX,dword ptr [0x00104820]
	EAX = RAM(1067040)._4;
	RAX = EAX;
	ADDR_1012E8:; // LEA EDX,[RAX + 0x1]
	temp_12544._8 = RAX + ((u64)1);
	EDX = (temp_12544._8 / 0x1);
	RDX = EDX;
	ADDR_1012EB:; // MOV dword ptr [0x00104820],EDX
	RAM(1067040)._4 = EDX;
	ADDR_1012F1:; // CDQE
	RAXs = EAXs;
	ADDR_1012F3:; // LEA RDX,[0x104840]
	RDX = ((u64)0x104840);
	ADDR_1012FA:; // MOV byte ptr [RAX + RDX*0x1],0x0
	temp_13056._8 = RDX * ((u64)1);
	temp_13312._8 = RAX + temp_13056._8;
	temp_47872._1 = ((u8)0);
	RAM(temp_13312._8)._1 = temp_47872._1;
	ADDR_1012FE:; // MOV EAX,dword ptr [RBP + -0xc]
	temp_12544._8 = RBP + ((u64)-12);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_101301:; // CDQE
	RAXs = EAXs;
	ADDR_101303:; // LEA RDX,[0x104840]
	RDX = ((u64)0x104840);
	ADDR_10130A:; // ADD RAX,RDX
	CF = (u64)(RAX + RDX) < RAX;
	OF = SIGN(8, RAXs) == SIGN(8, RDXs) && SIGN(8, (i64)(RAXs + RDXs)) != SIGN(8, RDXs);
	RAX = RAX + RDX;
	SF = RAXs < ((i64)0);
	ZF = RAX == ((u64)0);
	temp_76800._8 = RAX & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_10130D:; // JMP 0x001014e2
	goto ADDR_1014E2;
	ADDR_101312:; // MOV EAX,dword ptr [RBP + -0x24]
	temp_12544._8 = RBP + ((u64)-36);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_101315:; // SHR EAX,0x1f
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
	ADDR_101318:; // MOVZX EAX,AL
	EAX = AL;
	RAX = EAX;
	ADDR_10131B:; // MOV dword ptr [RBP + -0x10],EAX
	temp_12544._8 = RBP + ((u64)-16);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_10131E:; // CMP dword ptr [RBP + -0x10],0x0
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
	ADDR_101322:; // JZ 0x0010132b
	if (ZF) goto ADDR_10132B;
	ADDR_101324:; // MOV EAX,dword ptr [RBP + -0x24]
	temp_12544._8 = RBP + ((u64)-36);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_101327:; // NEG EAX
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
	ADDR_101329:; // JMP 0x0010132e
	goto ADDR_10132E;
	ADDR_10132B:; // MOV EAX,dword ptr [RBP + -0x24]
	temp_12544._8 = RBP + ((u64)-36);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_10132E:; // MOV dword ptr [RBP + -0x4],EAX
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_101331:; // MOV dword ptr [RBP + -0x14],0x0
	temp_12544._8 = RBP + ((u64)-20);
	temp_48384._4 = ((u32)0);
	RAM(temp_12544._8)._4 = temp_48384._4;
	ADDR_101338:; // JMP 0x001013a2
	goto ADDR_1013A2;
	ADDR_10133A:; // MOV ECX,dword ptr [RBP + -0x4]
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = RAM(temp_12544._8)._4;
	ECX = temp_48256._4;
	RCX = ECX;
	ADDR_10133D:; // MOVSXD RAX,ECX
	RAXs = ECXs;
	ADDR_101340:; // IMUL RAX,RAX,0x66666667
	temp_226176._16s = RAXs;
	temp_226304._16s = ((i32)0x66666667);
	temp_226560._16 = temp_226176._16 * temp_226304._16;
	temp_226688._8s = ((i32)0x66666667);
	RAX = RAX * temp_226688._8;
	temp_227072._8 = (temp_226560._16 / 0x10000000000000000);
	temp_80768._16s = RAXs;
	CF = temp_80768._16 != temp_226560._16;
	OF = CF;
	ADDR_101347:; // SHR RAX,0x20
	temp_358528._4 = ((u32)32) & ((u32)63);
	temp_358656._8 = RAX;
	RAX = RAX >> temp_358528._4;
	temp_90368._1 = temp_358528._4 != ((u32)0);
	temp_90496._4 = temp_358528._4 - ((u32)1);
	temp_90624._8 = temp_358656._8 >> temp_90496._4;
	temp_90752._8 = temp_90624._8 & ((u64)1);
	temp_91008._1 = temp_90752._8 != ((u64)0);
	temp_91136._1 = !temp_90368._1;
	temp_91264._1 = temp_91136._1 & CF;
	temp_91392._1 = temp_90368._1 & temp_91008._1;
	CF = temp_91264._1 | temp_91392._1;
	temp_91776._1 = temp_358528._4 == ((u32)1);
	temp_92032._1 = temp_358656._8s < ((i64)0);
	temp_92160._1 = !temp_91776._1;
	temp_92288._1 = temp_92160._1 & OF;
	temp_92416._1 = temp_91776._1 & temp_92032._1;
	OF = temp_92288._1 | temp_92416._1;
	temp_77440._1 = temp_358528._4 != ((u32)0);
	temp_77696._1 = RAXs < ((i64)0);
	temp_77824._1 = !temp_77440._1;
	temp_77952._1 = temp_77824._1 & SF;
	temp_78080._1 = temp_77440._1 & temp_77696._1;
	SF = temp_77952._1 | temp_78080._1;
	temp_78464._1 = RAX == ((u64)0);
	temp_78592._1 = !temp_77440._1;
	temp_78720._1 = temp_78592._1 & ZF;
	temp_78848._1 = temp_77440._1 & temp_78464._1;
	ZF = temp_78720._1 | temp_78848._1;
	temp_79104._8 = RAX & ((u64)255);
	temp_79232._1 = POPCOUNT(8, temp_79104._8);
	temp_79360._1 = temp_79232._1 & ((u8)1);
	temp_79616._1 = temp_79360._1 == ((u8)0);
	temp_79744._1 = !temp_77440._1;
	temp_79872._1 = temp_79744._1 & PF;
	temp_80000._1 = temp_77440._1 & temp_79616._1;
	PF = temp_79872._1 | temp_80000._1;
	ADDR_10134B:; // MOV EDX,EAX
	EDX = EAX;
	RDX = EDX;
	ADDR_10134D:; // SAR EDX,0x2
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
	ADDR_101350:; // MOV EAX,ECX
	EAX = ECX;
	RAX = EAX;
	ADDR_101352:; // SAR EAX,0x1f
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
	ADDR_101355:; // SUB EDX,EAX
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
	ADDR_101357:; // MOV EAX,EDX
	EAX = EDX;
	RAX = EAX;
	ADDR_101359:; // SHL EAX,0x2
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
	ADDR_10135C:; // ADD EAX,EDX
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
	ADDR_10135E:; // ADD EAX,EAX
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
	ADDR_101360:; // SUB ECX,EAX
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
	ADDR_101362:; // MOV EDX,ECX
	EDX = ECX;
	RDX = EDX;
	ADDR_101364:; // MOV EAX,EDX
	EAX = EDX;
	RAX = EAX;
	ADDR_101366:; // LEA ECX,[RAX + 0x30]
	temp_12544._8 = RAX + ((u64)48);
	ECX = (temp_12544._8 / 0x1);
	RCX = ECX;
	ADDR_101369:; // MOV EAX,dword ptr [0x00104820]
	EAX = RAM(1067040)._4;
	RAX = EAX;
	ADDR_10136F:; // LEA EDX,[RAX + 0x1]
	temp_12544._8 = RAX + ((u64)1);
	EDX = (temp_12544._8 / 0x1);
	RDX = EDX;
	ADDR_101372:; // MOV dword ptr [0x00104820],EDX
	RAM(1067040)._4 = EDX;
	ADDR_101378:; // CDQE
	RAXs = EAXs;
	ADDR_10137A:; // LEA RDX,[0x104840]
	RDX = ((u64)0x104840);
	ADDR_101381:; // MOV byte ptr [RAX + RDX*0x1],CL
	temp_13056._8 = RDX * ((u64)1);
	temp_13312._8 = RAX + temp_13056._8;
	temp_47744._1 = CL;
	RAM(temp_13312._8)._1 = temp_47744._1;
	ADDR_101384:; // MOV EAX,dword ptr [RBP + -0x4]
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_101387:; // MOVSXD RDX,EAX
	RDXs = EAXs;
	ADDR_10138A:; // IMUL RDX,RDX,0x66666667
	temp_226176._16s = RDXs;
	temp_226304._16s = ((i32)0x66666667);
	temp_226560._16 = temp_226176._16 * temp_226304._16;
	temp_226688._8s = ((i32)0x66666667);
	RDX = RDX * temp_226688._8;
	temp_227072._8 = (temp_226560._16 / 0x10000000000000000);
	temp_80768._16s = RDXs;
	CF = temp_80768._16 != temp_226560._16;
	OF = CF;
	ADDR_101391:; // SHR RDX,0x20
	temp_358528._4 = ((u32)32) & ((u32)63);
	temp_358656._8 = RDX;
	RDX = RDX >> temp_358528._4;
	temp_90368._1 = temp_358528._4 != ((u32)0);
	temp_90496._4 = temp_358528._4 - ((u32)1);
	temp_90624._8 = temp_358656._8 >> temp_90496._4;
	temp_90752._8 = temp_90624._8 & ((u64)1);
	temp_91008._1 = temp_90752._8 != ((u64)0);
	temp_91136._1 = !temp_90368._1;
	temp_91264._1 = temp_91136._1 & CF;
	temp_91392._1 = temp_90368._1 & temp_91008._1;
	CF = temp_91264._1 | temp_91392._1;
	temp_91776._1 = temp_358528._4 == ((u32)1);
	temp_92032._1 = temp_358656._8s < ((i64)0);
	temp_92160._1 = !temp_91776._1;
	temp_92288._1 = temp_92160._1 & OF;
	temp_92416._1 = temp_91776._1 & temp_92032._1;
	OF = temp_92288._1 | temp_92416._1;
	temp_77440._1 = temp_358528._4 != ((u32)0);
	temp_77696._1 = RDXs < ((i64)0);
	temp_77824._1 = !temp_77440._1;
	temp_77952._1 = temp_77824._1 & SF;
	temp_78080._1 = temp_77440._1 & temp_77696._1;
	SF = temp_77952._1 | temp_78080._1;
	temp_78464._1 = RDX == ((u64)0);
	temp_78592._1 = !temp_77440._1;
	temp_78720._1 = temp_78592._1 & ZF;
	temp_78848._1 = temp_77440._1 & temp_78464._1;
	ZF = temp_78720._1 | temp_78848._1;
	temp_79104._8 = RDX & ((u64)255);
	temp_79232._1 = POPCOUNT(8, temp_79104._8);
	temp_79360._1 = temp_79232._1 & ((u8)1);
	temp_79616._1 = temp_79360._1 == ((u8)0);
	temp_79744._1 = !temp_77440._1;
	temp_79872._1 = temp_79744._1 & PF;
	temp_80000._1 = temp_77440._1 & temp_79616._1;
	PF = temp_79872._1 | temp_80000._1;
	ADDR_101395:; // SAR EDX,0x2
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
	ADDR_101398:; // SAR EAX,0x1f
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
	ADDR_10139B:; // SUB EDX,EAX
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
	ADDR_10139D:; // MOV EAX,EDX
	EAX = EDX;
	RAX = EAX;
	ADDR_10139F:; // MOV dword ptr [RBP + -0x4],EAX
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_1013A2:; // CMP dword ptr [RBP + -0x4],0x0
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
	ADDR_1013A6:; // JG 0x0010133a
	temp_52992._1 = !ZF;
	temp_53120._1 = OF == SF;
	temp_53376._1 = temp_52992._1 && temp_53120._1;
	if (temp_53376._1) goto ADDR_10133A;
	ADDR_1013A8:; // CMP dword ptr [RBP + -0x10],0x0
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
	ADDR_1013AC:; // JZ 0x001013ca
	if (ZF) goto ADDR_1013CA;
	ADDR_1013AE:; // MOV EAX,dword ptr [0x00104820]
	EAX = RAM(1067040)._4;
	RAX = EAX;
	ADDR_1013B4:; // LEA EDX,[RAX + 0x1]
	temp_12544._8 = RAX + ((u64)1);
	EDX = (temp_12544._8 / 0x1);
	RDX = EDX;
	ADDR_1013B7:; // MOV dword ptr [0x00104820],EDX
	RAM(1067040)._4 = EDX;
	ADDR_1013BD:; // CDQE
	RAXs = EAXs;
	ADDR_1013BF:; // LEA RDX,[0x104840]
	RDX = ((u64)0x104840);
	ADDR_1013C6:; // MOV byte ptr [RAX + RDX*0x1],0x2d
	temp_13056._8 = RDX * ((u64)1);
	temp_13312._8 = RAX + temp_13056._8;
	temp_47872._1 = ((u8)45);
	RAM(temp_13312._8)._1 = temp_47872._1;
	ADDR_1013CA:; // MOV dword ptr [RBP + -0x8],0x0
	temp_12544._8 = RBP + ((u64)-8);
	temp_48384._4 = ((u32)0);
	RAM(temp_12544._8)._4 = temp_48384._4;
	ADDR_1013D1:; // JMP 0x0010149c
	goto ADDR_10149C;
	ADDR_1013D6:; // MOV EDX,dword ptr [RBP + -0xc]
	temp_12544._8 = RBP + ((u64)-12);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EDX = temp_48256._4;
	RDX = EDX;
	ADDR_1013D9:; // MOV EAX,dword ptr [RBP + -0x8]
	temp_12544._8 = RBP + ((u64)-8);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_1013DC:; // ADD EAX,EDX
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
	ADDR_1013DE:; // CDQE
	RAXs = EAXs;
	ADDR_1013E0:; // LEA RDX,[0x104840]
	RDX = ((u64)0x104840);
	ADDR_1013E7:; // MOVZX ESI,byte ptr [RAX + RDX*0x1]
	temp_13056._8 = RDX * ((u64)1);
	temp_13312._8 = RAX + temp_13056._8;
	temp_47872._1 = RAM(temp_13312._8)._1;
	ESI = temp_47872._1;
	RSI = ESI;
	ADDR_1013EB:; // MOV EAX,dword ptr [0x00104820]
	EAX = RAM(1067040)._4;
	RAX = EAX;
	ADDR_1013F1:; // SUB EAX,0x1
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
	ADDR_1013F4:; // SUB EAX,dword ptr [RBP + -0x8]
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
	ADDR_1013F7:; // CDQE
	RAXs = EAXs;
	ADDR_1013F9:; // LEA RDX,[0x104840]
	RDX = ((u64)0x104840);
	ADDR_101400:; // MOVZX ECX,byte ptr [RAX + RDX*0x1]
	temp_13056._8 = RDX * ((u64)1);
	temp_13312._8 = RAX + temp_13056._8;
	temp_47872._1 = RAM(temp_13312._8)._1;
	ECX = temp_47872._1;
	RCX = ECX;
	ADDR_101404:; // MOV EDX,dword ptr [RBP + -0xc]
	temp_12544._8 = RBP + ((u64)-12);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EDX = temp_48256._4;
	RDX = EDX;
	ADDR_101407:; // MOV EAX,dword ptr [RBP + -0x8]
	temp_12544._8 = RBP + ((u64)-8);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_10140A:; // ADD EAX,EDX
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
	ADDR_10140C:; // XOR ESI,ECX
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
	ADDR_10140E:; // MOVSXD RDX,EAX
	RDXs = EAXs;
	ADDR_101411:; // LEA RCX,[0x104840]
	RCX = ((u64)0x104840);
	ADDR_101418:; // MOV byte ptr [RDX + RCX*0x1],SIL
	temp_13056._8 = RCX * ((u64)1);
	temp_13312._8 = RDX + temp_13056._8;
	temp_47744._1 = SIL;
	RAM(temp_13312._8)._1 = temp_47744._1;
	ADDR_10141C:; // CDQE
	RAXs = EAXs;
	ADDR_10141E:; // LEA RDX,[0x104840]
	RDX = ((u64)0x104840);
	ADDR_101425:; // MOVZX ECX,byte ptr [RAX + RDX*0x1]
	temp_13056._8 = RDX * ((u64)1);
	temp_13312._8 = RAX + temp_13056._8;
	temp_47872._1 = RAM(temp_13312._8)._1;
	ECX = temp_47872._1;
	RCX = ECX;
	ADDR_101429:; // MOV EAX,dword ptr [0x00104820]
	EAX = RAM(1067040)._4;
	RAX = EAX;
	ADDR_10142F:; // SUB EAX,0x1
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
	ADDR_101432:; // SUB EAX,dword ptr [RBP + -0x8]
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
	ADDR_101435:; // CDQE
	RAXs = EAXs;
	ADDR_101437:; // LEA RDX,[0x104840]
	RDX = ((u64)0x104840);
	ADDR_10143E:; // MOVZX EDX,byte ptr [RAX + RDX*0x1]
	temp_13056._8 = RDX * ((u64)1);
	temp_13312._8 = RAX + temp_13056._8;
	temp_47872._1 = RAM(temp_13312._8)._1;
	EDX = temp_47872._1;
	RDX = EDX;
	ADDR_101442:; // MOV EAX,dword ptr [0x00104820]
	EAX = RAM(1067040)._4;
	RAX = EAX;
	ADDR_101448:; // SUB EAX,0x1
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
	ADDR_10144B:; // SUB EAX,dword ptr [RBP + -0x8]
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
	ADDR_10144E:; // MOV ESI,ECX
	ESI = ECX;
	RSI = ESI;
	ADDR_101450:; // XOR ESI,EDX
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
	ADDR_101452:; // MOVSXD RDX,EAX
	RDXs = EAXs;
	ADDR_101455:; // LEA RCX,[0x104840]
	RCX = ((u64)0x104840);
	ADDR_10145C:; // MOV byte ptr [RDX + RCX*0x1],SIL
	temp_13056._8 = RCX * ((u64)1);
	temp_13312._8 = RDX + temp_13056._8;
	temp_47744._1 = SIL;
	RAM(temp_13312._8)._1 = temp_47744._1;
	ADDR_101460:; // CDQE
	RAXs = EAXs;
	ADDR_101462:; // LEA RDX,[0x104840]
	RDX = ((u64)0x104840);
	ADDR_101469:; // MOVZX ESI,byte ptr [RAX + RDX*0x1]
	temp_13056._8 = RDX * ((u64)1);
	temp_13312._8 = RAX + temp_13056._8;
	temp_47872._1 = RAM(temp_13312._8)._1;
	ESI = temp_47872._1;
	RSI = ESI;
	ADDR_10146D:; // MOV EDX,dword ptr [RBP + -0xc]
	temp_12544._8 = RBP + ((u64)-12);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EDX = temp_48256._4;
	RDX = EDX;
	ADDR_101470:; // MOV EAX,dword ptr [RBP + -0x8]
	temp_12544._8 = RBP + ((u64)-8);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_101473:; // ADD EAX,EDX
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
	ADDR_101475:; // CDQE
	RAXs = EAXs;
	ADDR_101477:; // LEA RDX,[0x104840]
	RDX = ((u64)0x104840);
	ADDR_10147E:; // MOVZX ECX,byte ptr [RAX + RDX*0x1]
	temp_13056._8 = RDX * ((u64)1);
	temp_13312._8 = RAX + temp_13056._8;
	temp_47872._1 = RAM(temp_13312._8)._1;
	ECX = temp_47872._1;
	RCX = ECX;
	ADDR_101482:; // MOV EDX,dword ptr [RBP + -0xc]
	temp_12544._8 = RBP + ((u64)-12);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EDX = temp_48256._4;
	RDX = EDX;
	ADDR_101485:; // MOV EAX,dword ptr [RBP + -0x8]
	temp_12544._8 = RBP + ((u64)-8);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_101488:; // ADD EAX,EDX
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
	ADDR_10148A:; // XOR ECX,ESI
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
	ADDR_10148C:; // CDQE
	RAXs = EAXs;
	ADDR_10148E:; // LEA RDX,[0x104840]
	RDX = ((u64)0x104840);
	ADDR_101495:; // MOV byte ptr [RAX + RDX*0x1],CL
	temp_13056._8 = RDX * ((u64)1);
	temp_13312._8 = RAX + temp_13056._8;
	temp_47744._1 = CL;
	RAM(temp_13312._8)._1 = temp_47744._1;
	ADDR_101498:; // ADD dword ptr [RBP + -0x8],0x1
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
	ADDR_10149C:; // MOV EAX,dword ptr [0x00104820]
	EAX = RAM(1067040)._4;
	RAX = EAX;
	ADDR_1014A2:; // SUB EAX,dword ptr [RBP + -0xc]
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
	ADDR_1014A5:; // MOV EDX,EAX
	EDX = EAX;
	RDX = EDX;
	ADDR_1014A7:; // SHR EDX,0x1f
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
	ADDR_1014AA:; // ADD EAX,EDX
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
	ADDR_1014AC:; // SAR EAX,1
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
	ADDR_1014AE:; // CMP dword ptr [RBP + -0x8],EAX
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
	ADDR_1014B1:; // JL 0x001013d6
	temp_52224._1 = OF != SF;
	if (temp_52224._1) goto ADDR_1013D6;
	ADDR_1014B7:; // MOV EAX,dword ptr [0x00104820]
	EAX = RAM(1067040)._4;
	RAX = EAX;
	ADDR_1014BD:; // LEA EDX,[RAX + 0x1]
	temp_12544._8 = RAX + ((u64)1);
	EDX = (temp_12544._8 / 0x1);
	RDX = EDX;
	ADDR_1014C0:; // MOV dword ptr [0x00104820],EDX
	RAM(1067040)._4 = EDX;
	ADDR_1014C6:; // CDQE
	RAXs = EAXs;
	ADDR_1014C8:; // LEA RDX,[0x104840]
	RDX = ((u64)0x104840);
	ADDR_1014CF:; // MOV byte ptr [RAX + RDX*0x1],0x0
	temp_13056._8 = RDX * ((u64)1);
	temp_13312._8 = RAX + temp_13056._8;
	temp_47872._1 = ((u8)0);
	RAM(temp_13312._8)._1 = temp_47872._1;
	ADDR_1014D3:; // MOV EAX,dword ptr [RBP + -0xc]
	temp_12544._8 = RBP + ((u64)-12);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_1014D6:; // CDQE
	RAXs = EAXs;
	ADDR_1014D8:; // LEA RDX,[0x104840]
	RDX = ((u64)0x104840);
	ADDR_1014DF:; // ADD RAX,RDX
	CF = (u64)(RAX + RDX) < RAX;
	OF = SIGN(8, RAXs) == SIGN(8, RDXs) && SIGN(8, (i64)(RAXs + RDXs)) != SIGN(8, RDXs);
	RAX = RAX + RDX;
	SF = RAXs < ((i64)0);
	ZF = RAX == ((u64)0);
	temp_76800._8 = RAX & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_1014E2:; // POP RBP
	RBP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_1014E3:; // RET
	RIP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	return;
	
}
