#include "dragonlifter.h"

void _start() {
	static const void* labels[] = { &&ADDR_101A3E,NULL,NULL,NULL,&&ADDR_101A42,&&ADDR_101A43,NULL,NULL,&&ADDR_101A46,NULL,NULL,NULL,&&ADDR_101A4A,NULL,NULL,NULL,NULL,&&ADDR_101A4F,NULL,NULL,NULL,NULL,NULL,NULL,&&ADDR_101A56,NULL,NULL,NULL,NULL,NULL,NULL,&&ADDR_101A5D,NULL,NULL,NULL,NULL,&&ADDR_101A62,NULL,NULL,NULL,NULL,&&ADDR_101A67,NULL,NULL,NULL,NULL,NULL,NULL,&&ADDR_101A6E,NULL,NULL,NULL,&&ADDR_101A72,NULL,NULL,&&ADDR_101A75,NULL,&&ADDR_101A77,NULL,NULL,&&ADDR_101A7A,NULL,&&ADDR_101A7C,NULL,NULL,&&ADDR_101A7F,NULL,NULL,&&ADDR_101A82,NULL,NULL,&&ADDR_101A85,NULL,NULL,NULL,NULL,NULL,NULL,&&ADDR_101A8C,NULL,NULL,NULL,&&ADDR_101A90,NULL,NULL,&&ADDR_101A93,NULL,&&ADDR_101A95,NULL,&&ADDR_101A97,NULL,&&ADDR_101A99,NULL,NULL,&&ADDR_101A9C,NULL,NULL,&&ADDR_101A9F,NULL,&&ADDR_101AA1,NULL,NULL,NULL,NULL,&&ADDR_101AA6,NULL,NULL,NULL,NULL,&&ADDR_101AAB,NULL,NULL,NULL,NULL,NULL,NULL,&&ADDR_101AB2,NULL,NULL,&&ADDR_101AB5,NULL,NULL,NULL,NULL,&&ADDR_101ABA,NULL,NULL,NULL,NULL,&&ADDR_101ABF,NULL,NULL,&&ADDR_101AC2,NULL,&&ADDR_101AC4,NULL,&&ADDR_101AC6,NULL,NULL,NULL,NULL,&&ADDR_101ACB,NULL,NULL,NULL,NULL,&&ADDR_101AD0,NULL,NULL,NULL,NULL,NULL,NULL,&&ADDR_101AD7,NULL,NULL,&&ADDR_101ADA,NULL,NULL,NULL,NULL,&&ADDR_101ADF,NULL,NULL,NULL,NULL,&&ADDR_101AE4,NULL,NULL,NULL,NULL,NULL,NULL,&&ADDR_101AEB,NULL,NULL,NULL,NULL,&&ADDR_101AF0,NULL,NULL,NULL,&&ADDR_101AF4,NULL,NULL,NULL,&&ADDR_101AF8,NULL,NULL,NULL,NULL,&&ADDR_101AFD,NULL,NULL,NULL,NULL,NULL,NULL,&&ADDR_101B04,NULL,NULL,&&ADDR_101B07,NULL,NULL,NULL,NULL,NULL,NULL,&&ADDR_101B0E,NULL,NULL,NULL,NULL,&&ADDR_101B13,NULL,NULL,NULL,NULL,&&ADDR_101B18,NULL,NULL,NULL,&&ADDR_101B1C,NULL,NULL,&&ADDR_101B1F,NULL,NULL,NULL,NULL,&&ADDR_101B24,NULL,NULL,&&ADDR_101B27,NULL,NULL,&&ADDR_101B2A,NULL,&&ADDR_101B2C,NULL,&&ADDR_101B2E,NULL,NULL,NULL,NULL,&&ADDR_101B33,NULL,NULL,NULL,NULL,&&ADDR_101B38,NULL,NULL,NULL,NULL,NULL,NULL,&&ADDR_101B3F,NULL,NULL,&&ADDR_101B42,NULL,NULL,NULL,NULL,NULL,NULL,&&ADDR_101B49,NULL,NULL,NULL,NULL,&&ADDR_101B4E,NULL,NULL,NULL,NULL,&&ADDR_101B53,NULL,NULL,NULL,NULL,&&ADDR_101B58,NULL,NULL,NULL,NULL,&&ADDR_101B5D,NULL,NULL,NULL,NULL,&&ADDR_101B62,NULL,NULL,NULL,NULL,&&ADDR_101B67,NULL,NULL,NULL,NULL,&&ADDR_101B6C,NULL,NULL,NULL,NULL,&&ADDR_101B71,NULL,&&ADDR_101B73,NULL,NULL,NULL,NULL,&&ADDR_101B78,NULL,NULL,NULL,NULL,&&ADDR_101B7D,NULL,NULL,NULL,NULL,NULL,NULL,&&ADDR_101B84,NULL,NULL,&&ADDR_101B87,NULL,NULL,NULL,NULL,NULL,NULL,&&ADDR_101B8E,NULL,NULL,NULL,NULL,&&ADDR_101B93,NULL,NULL,NULL,NULL,&&ADDR_101B98,NULL,NULL,NULL,NULL,&&ADDR_101B9D };
	static const size_t labels_base_address = 1055294;
	ADDR_101A3E:; // ENDBR64
	
	ADDR_101A42:; // PUSH RBP
	temp_59264._8 = RBP;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_101A43:; // MOV RBP,RSP
	RBP = RSP;
	ADDR_101A46:; // SUB RSP,0x40
	CF = RSP < ((u64)64);
	OF = SIGN(8, RSPs) != SIGN(8, ((i64)64)) && SIGN(8, (i64)(RSPs - ((i64)64))) == SIGN(8, ((i64)64));
	RSP = RSP - ((u64)64);
	SF = RSPs < ((i64)0);
	ZF = RSP == ((u64)0);
	temp_76800._8 = RSP & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_101A4A:; // MOV EDX,0x0
	RDX = ((u64)0);
	ADDR_101A4F:; // LEA RSI,[0x102000]
	RSI = ((u64)0x102000);
	ADDR_101A56:; // LEA RDI,[0x102100]
	RDI = ((u64)0x102100);
	ADDR_101A5D:; // MOV EAX,0x0
	RAX = ((u64)0);
	ADDR_101A62:; // CALL 0x001010aa
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x101a67);
	print_raw();
	ADDR_101A67:; // MOV dword ptr [RBP + -0x4],0x2
	temp_12544._8 = RBP + ((u64)-4);
	temp_48384._4 = ((u32)2);
	RAM(temp_12544._8)._4 = temp_48384._4;
	ADDR_101A6E:; // ADD dword ptr [RBP + -0x4],0x5
	temp_12544._8 = RBP + ((u64)-4);
	temp_48384._4 = RAM(temp_12544._8)._4;
	CF = (u32)(temp_48384._4 + ((u32)5)) < temp_48384._4;
	temp_48384._4 = RAM(temp_12544._8)._4;
	OF = SIGN(4, temp_48384._4s) == SIGN(4, ((i32)5)) && SIGN(4, (i32)(temp_48384._4s + ((i32)5))) != SIGN(4, ((i32)5));
	temp_48384._4 = RAM(temp_12544._8)._4;
	temp_48384._4 = temp_48384._4 + ((u32)5);
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
	ADDR_101A72:; // MOV EDX,dword ptr [RBP + -0x4]
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EDX = temp_48256._4;
	RDX = EDX;
	ADDR_101A75:; // MOV EAX,EDX
	EAX = EDX;
	RAX = EAX;
	ADDR_101A77:; // SHL EAX,0x3
	temp_340736._4 = ((u32)3) & ((u32)31);
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
	ADDR_101A7A:; // SUB EAX,EDX
	CF = EAX < EDX;
	OF = SIGN(4, EAXs) != SIGN(4, EDXs) && SIGN(4, (i32)(EAXs - EDXs)) == SIGN(4, EDXs);
	EAX = EAX - EDX;
	RAX = EAX;
	SF = EAXs < ((i32)0);
	ZF = EAX == ((u32)0);
	temp_76800._4 = EAX & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_101A7C:; // MOV dword ptr [RBP + -0x4],EAX
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_101A7F:; // MOV EAX,dword ptr [RBP + -0x4]
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_101A82:; // MOVSXD RDX,EAX
	RDXs = EAXs;
	ADDR_101A85:; // IMUL RDX,RDX,0x55555556
	temp_226176._16s = RDXs;
	temp_226304._16s = ((i32)0x55555556);
	temp_226560._16 = temp_226176._16 * temp_226304._16;
	temp_226688._8s = ((i32)0x55555556);
	RDX = RDX * temp_226688._8;
	temp_227072._8 = temp_226560._16 / ((u128)1 << 64);
	temp_80768._16s = RDXs;
	CF = temp_80768._16 != temp_226560._16;
	OF = CF;
	ADDR_101A8C:; // SHR RDX,0x20
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
	ADDR_101A90:; // SAR EAX,0x1f
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
	ADDR_101A93:; // MOV ECX,EDX
	ECX = EDX;
	RCX = ECX;
	ADDR_101A95:; // SUB ECX,EAX
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
	ADDR_101A97:; // MOV EAX,ECX
	EAX = ECX;
	RAX = EAX;
	ADDR_101A99:; // MOV dword ptr [RBP + -0x4],EAX
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_101A9C:; // MOV EAX,dword ptr [RBP + -0x4]
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_101A9F:; // MOV EDI,EAX
	EDI = EAX;
	RDI = EDI;
	ADDR_101AA1:; // CALL 0x001012ac
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x101aa6);
	int_to_string();
	ADDR_101AA6:; // MOV EDX,0x0
	RDX = ((u64)0);
	ADDR_101AAB:; // LEA RSI,[0x102000]
	RSI = ((u64)0x102000);
	ADDR_101AB2:; // MOV RDI,RAX
	RDI = RAX;
	ADDR_101AB5:; // MOV EAX,0x0
	RAX = ((u64)0);
	ADDR_101ABA:; // CALL 0x001010aa
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x101abf);
	print_raw();
	ADDR_101ABF:; // MOV EAX,dword ptr [RBP + -0x4]
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_101AC2:; // NEG EAX
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
	ADDR_101AC4:; // MOV EDI,EAX
	EDI = EAX;
	RDI = EDI;
	ADDR_101AC6:; // CALL 0x001012ac
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x101acb);
	int_to_string();
	ADDR_101ACB:; // MOV EDX,0x0
	RDX = ((u64)0);
	ADDR_101AD0:; // LEA RSI,[0x102000]
	RSI = ((u64)0x102000);
	ADDR_101AD7:; // MOV RDI,RAX
	RDI = RAX;
	ADDR_101ADA:; // MOV EAX,0x0
	RAX = ((u64)0);
	ADDR_101ADF:; // CALL 0x001010aa
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x101ae4);
	print_raw();
	ADDR_101AE4:; // LEA RDI,[0x102106]
	RDI = ((u64)0x102106);
	ADDR_101AEB:; // CALL 0x00101279
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x101af0);
	input_prompt();
	ADDR_101AF0:; // MOV qword ptr [RBP + -0x10],RAX
	temp_12544._8 = RBP + ((u64)-16);
	temp_48512._8 = RAX;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_101AF4:; // MOV RAX,qword ptr [RBP + -0x10]
	temp_12544._8 = RBP + ((u64)-16);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RAX = temp_48512._8;
	ADDR_101AF8:; // MOV ECX,0x0
	RCX = ((u64)0);
	ADDR_101AFD:; // LEA RDX,[0x102000]
	RDX = ((u64)0x102000);
	ADDR_101B04:; // MOV RSI,RAX
	RSI = RAX;
	ADDR_101B07:; // LEA RDI,[0x102118]
	RDI = ((u64)0x102118);
	ADDR_101B0E:; // MOV EAX,0x0
	RAX = ((u64)0);
	ADDR_101B13:; // CALL 0x001010aa
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x101b18);
	print_raw();
	ADDR_101B18:; // MOV RAX,qword ptr [RBP + -0x10]
	temp_12544._8 = RBP + ((u64)-16);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RAX = temp_48512._8;
	ADDR_101B1C:; // MOV RDI,RAX
	RDI = RAX;
	ADDR_101B1F:; // CALL 0x001014e4
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x101b24);
	string_to_int();
	ADDR_101B24:; // MOV dword ptr [RBP + -0x14],EAX
	temp_12544._8 = RBP + ((u64)-20);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_101B27:; // MOV EAX,dword ptr [RBP + -0x14]
	temp_12544._8 = RBP + ((u64)-20);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_101B2A:; // ADD EAX,EAX
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
	ADDR_101B2C:; // MOV EDI,EAX
	EDI = EAX;
	RDI = EDI;
	ADDR_101B2E:; // CALL 0x001012ac
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x101b33);
	int_to_string();
	ADDR_101B33:; // MOV ECX,0x0
	RCX = ((u64)0);
	ADDR_101B38:; // LEA RDX,[0x102000]
	RDX = ((u64)0x102000);
	ADDR_101B3F:; // MOV RSI,RAX
	RSI = RAX;
	ADDR_101B42:; // LEA RDI,[0x102130]
	RDI = ((u64)0x102130);
	ADDR_101B49:; // MOV EAX,0x0
	RAX = ((u64)0);
	ADDR_101B4E:; // CALL 0x001010aa
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x101b53);
	print_raw();
	ADDR_101B53:; // MOV EAX,0x0
	RAX = ((u64)0);
	ADDR_101B58:; // CALL 0x00101655
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x101b5d);
	calc();
	ADDR_101B5D:; // MOV EAX,0x0
	RAX = ((u64)0);
	ADDR_101B62:; // CALL 0x001017c5
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x101b67);
	calc_bitwise();
	ADDR_101B67:; // MOV EAX,0x0
	RAX = ((u64)0);
	ADDR_101B6C:; // CALL 0x0010194a
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x101b71);
	get_square();
	ADDR_101B71:; // MOV EDI,EAX
	EDI = EAX;
	RDI = EDI;
	ADDR_101B73:; // CALL 0x001012ac
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x101b78);
	int_to_string();
	ADDR_101B78:; // MOV ECX,0x0
	RCX = ((u64)0);
	ADDR_101B7D:; // LEA RDX,[0x102000]
	RDX = ((u64)0x102000);
	ADDR_101B84:; // MOV RSI,RAX
	RSI = RAX;
	ADDR_101B87:; // LEA RDI,[0x102151]
	RDI = ((u64)0x102151);
	ADDR_101B8E:; // MOV EAX,0x0
	RAX = ((u64)0);
	ADDR_101B93:; // CALL 0x001010aa
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x101b98);
	print_raw();
	ADDR_101B98:; // MOV EDI,0x2a
	RDI = ((u64)42);
	ADDR_101B9D:; // CALL 0x00101058
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x101ba2);
	exit();
	
}
