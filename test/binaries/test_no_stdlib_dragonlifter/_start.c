#include "dragonlifter.h"

void _start() {
	ADDR_400A52:; // PUSH RBP
	temp_59264._8 = RBP;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_400A53:; // MOV RBP,RSP
	RBP = RSP;
	ADDR_400A56:; // SUB RSP,0x40
	CF = RSP < ((u64)64);
	OF = SIGN(8, RSPs) != SIGN(8, ((i64)64)) && SIGN(8, (i64)(RSPs - ((i64)64))) == SIGN(8, ((i64)64));
	RSP = RSP - ((u64)64);
	SF = RSPs < ((i64)0);
	ZF = RSP == ((u64)0);
	temp_76800._8 = RSP & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_400A5A:; // MOV EDX,0x0
	RDX = ((u64)0);
	ADDR_400A5F:; // LEA RSI,[0x400bb8]
	RSI = ((u64)0x400bb8);
	ADDR_400A66:; // LEA RDI,[0x400c43]
	RDI = ((u64)0x400c43);
	ADDR_400A6D:; // MOV EAX,0x0
	RAX = ((u64)0);
	ADDR_400A72:; // CALL 0x004001de
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x400a77);
	print_raw();
	ADDR_400A77:; // MOV dword ptr [RBP + -0x4],0x2
	temp_12544._8 = RBP + ((u64)-4);
	temp_48384._4 = ((u32)2);
	RAM(temp_12544._8)._4 = temp_48384._4;
	ADDR_400A7E:; // ADD dword ptr [RBP + -0x4],0x5
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
	ADDR_400A82:; // MOV EDX,dword ptr [RBP + -0x4]
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EDX = temp_48256._4;
	RDX = EDX;
	ADDR_400A85:; // MOV EAX,EDX
	EAX = EDX;
	RAX = EAX;
	ADDR_400A87:; // SHL EAX,0x3
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
	ADDR_400A8A:; // SUB EAX,EDX
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
	ADDR_400A8C:; // MOV dword ptr [RBP + -0x4],EAX
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_400A8F:; // MOV ECX,dword ptr [RBP + -0x4]
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = RAM(temp_12544._8)._4;
	ECX = temp_48256._4;
	RCX = ECX;
	ADDR_400A92:; // MOV EDX,0x55555556
	RDX = ((u64)0x55555556);
	ADDR_400A97:; // MOV EAX,ECX
	EAX = ECX;
	RAX = EAX;
	ADDR_400A99:; // IMUL EDX
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
	ADDR_400A9B:; // MOV EAX,ECX
	EAX = ECX;
	RAX = EAX;
	ADDR_400A9D:; // SAR EAX,0x1f
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
	ADDR_400AA0:; // SUB EDX,EAX
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
	ADDR_400AA2:; // MOV EAX,EDX
	EAX = EDX;
	RAX = EAX;
	ADDR_400AA4:; // MOV dword ptr [RBP + -0x4],EAX
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_400AA7:; // MOV EAX,dword ptr [RBP + -0x4]
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_400AAA:; // MOV EDI,EAX
	EDI = EAX;
	RDI = EDI;
	ADDR_400AAC:; // CALL 0x004003d2
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x400ab1);
	int_to_string();
	ADDR_400AB1:; // MOV EDX,0x0
	RDX = ((u64)0);
	ADDR_400AB6:; // LEA RSI,[0x400bb8]
	RSI = ((u64)0x400bb8);
	ADDR_400ABD:; // MOV RDI,RAX
	RDI = RAX;
	ADDR_400AC0:; // MOV EAX,0x0
	RAX = ((u64)0);
	ADDR_400AC5:; // CALL 0x004001de
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x400aca);
	print_raw();
	ADDR_400ACA:; // MOV EAX,dword ptr [RBP + -0x4]
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_400ACD:; // NEG EAX
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
	ADDR_400ACF:; // MOV EDI,EAX
	EDI = EAX;
	RDI = EDI;
	ADDR_400AD1:; // CALL 0x004003d2
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x400ad6);
	int_to_string();
	ADDR_400AD6:; // MOV EDX,0x0
	RDX = ((u64)0);
	ADDR_400ADB:; // LEA RSI,[0x400bb8]
	RSI = ((u64)0x400bb8);
	ADDR_400AE2:; // MOV RDI,RAX
	RDI = RAX;
	ADDR_400AE5:; // MOV EAX,0x0
	RAX = ((u64)0);
	ADDR_400AEA:; // CALL 0x004001de
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x400aef);
	print_raw();
	ADDR_400AEF:; // MOV ESI,0x0
	RSI = ((u64)0);
	ADDR_400AF4:; // LEA RDI,[0x400c49]
	RDI = ((u64)0x400c49);
	ADDR_400AFB:; // MOV EAX,0x0
	RAX = ((u64)0);
	ADDR_400B00:; // CALL 0x004001de
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x400b05);
	print_raw();
	ADDR_400B05:; // MOV EAX,0x0
	RAX = ((u64)0);
	ADDR_400B0A:; // CALL 0x0040032c
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x400b0f);
	input();
	ADDR_400B0F:; // MOV qword ptr [RBP + -0x10],RAX
	temp_12544._8 = RBP + ((u64)-16);
	temp_48512._8 = RAX;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_400B13:; // MOV ESI,0x0
	RSI = ((u64)0);
	ADDR_400B18:; // LEA RDI,[0x400c5b]
	RDI = ((u64)0x400c5b);
	ADDR_400B1F:; // MOV EAX,0x0
	RAX = ((u64)0);
	ADDR_400B24:; // CALL 0x004001de
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x400b29);
	print_raw();
	ADDR_400B29:; // MOV RAX,qword ptr [RBP + -0x10]
	temp_12544._8 = RBP + ((u64)-16);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RAX = temp_48512._8;
	ADDR_400B2D:; // MOV EDX,0x0
	RDX = ((u64)0);
	ADDR_400B32:; // LEA RSI,[0x400bb8]
	RSI = ((u64)0x400bb8);
	ADDR_400B39:; // MOV RDI,RAX
	RDI = RAX;
	ADDR_400B3C:; // MOV EAX,0x0
	RAX = ((u64)0);
	ADDR_400B41:; // CALL 0x004001de
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x400b46);
	print_raw();
	ADDR_400B46:; // MOV RAX,qword ptr [RBP + -0x10]
	temp_12544._8 = RBP + ((u64)-16);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RAX = temp_48512._8;
	ADDR_400B4A:; // MOV RDI,RAX
	RDI = RAX;
	ADDR_400B4D:; // CALL 0x0040060a
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x400b52);
	string_to_int();
	ADDR_400B52:; // MOV dword ptr [RBP + -0x14],EAX
	temp_12544._8 = RBP + ((u64)-20);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_400B55:; // MOV ESI,0x0
	RSI = ((u64)0);
	ADDR_400B5A:; // LEA RDI,[0x400c70]
	RDI = ((u64)0x400c70);
	ADDR_400B61:; // MOV EAX,0x0
	RAX = ((u64)0);
	ADDR_400B66:; // CALL 0x004001de
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x400b6b);
	print_raw();
	ADDR_400B6B:; // MOV EAX,dword ptr [RBP + -0x14]
	temp_12544._8 = RBP + ((u64)-20);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_400B6E:; // ADD EAX,EAX
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
	ADDR_400B70:; // MOV EDI,EAX
	EDI = EAX;
	RDI = EDI;
	ADDR_400B72:; // CALL 0x004003d2
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x400b77);
	int_to_string();
	ADDR_400B77:; // MOV EDX,0x0
	RDX = ((u64)0);
	ADDR_400B7C:; // LEA RSI,[0x400bb8]
	RSI = ((u64)0x400bb8);
	ADDR_400B83:; // MOV RDI,RAX
	RDI = RAX;
	ADDR_400B86:; // MOV EAX,0x0
	RAX = ((u64)0);
	ADDR_400B8B:; // CALL 0x004001de
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x400b90);
	print_raw();
	ADDR_400B90:; // MOV EAX,0x0
	RAX = ((u64)0);
	ADDR_400B95:; // CALL 0x00400779
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x400b9a);
	calc();
	ADDR_400B9A:; // MOV EAX,0x0
	RAX = ((u64)0);
	ADDR_400B9F:; // CALL 0x004008d8
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x400ba4);
	calc_bitwise();
	ADDR_400BA4:; // MOV EDI,0x2a
	RDI = ((u64)42);
	ADDR_400BA9:; // CALL 0x00400194
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x400bae);
	exit();
	
}
