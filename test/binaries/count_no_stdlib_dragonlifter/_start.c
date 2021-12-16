#include "dragonlifter.h"

void _start() {
	ADDR_10155F:; // ENDBR64
	++__instruction_count;
	
	ADDR_101563:; // PUSH RBP
	++__instruction_count;
	temp_59264._8 = RBP;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_101564:; // MOV RBP,RSP
	++__instruction_count;
	RBP = RSP;
	ADDR_101567:; // SUB RSP,0x20
	++__instruction_count;
	CF = RSP < ((u64)32);
	OF = SIGN(8, RSPs) != SIGN(8, ((i64)32)) && SIGN(8, (i64)(RSPs - ((i64)32))) == SIGN(8, ((i64)32));
	RSP = RSP - ((u64)32);
	SF = RSPs < ((i64)0);
	ZF = RSP == ((u64)0);
	temp_76800._8 = RSP & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_10156B:; // MOV EDX,0x0
	++__instruction_count;
	RDX = ((u64)0);
	ADDR_101570:; // LEA RSI,[0x102000]
	++__instruction_count;
	RSI = ((u64)0x102000);
	ADDR_101577:; // LEA RDI,[0x102002]
	++__instruction_count;
	RDI = ((u64)0x102002);
	ADDR_10157E:; // MOV EAX,0x0
	++__instruction_count;
	RAX = ((u64)0);
	ADDR_101583:; // CALL 0x001010aa
	++__instruction_count;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x101588);
	print_raw();
	ADDR_101588:; // LEA RAX,[0x102009]
	++__instruction_count;
	RAX = ((u64)0x102009);
	ADDR_10158F:; // MOV qword ptr [RBP + -0x10],RAX
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-16);
	temp_48512._8 = RAX;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_101593:; // MOV RAX,qword ptr [RBP + -0x10]
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-16);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RAX = temp_48512._8;
	ADDR_101597:; // MOV RDI,RAX
	++__instruction_count;
	RDI = RAX;
	ADDR_10159A:; // CALL 0x00101076
	++__instruction_count;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x10159f);
	strlen();
	ADDR_10159F:; // MOV dword ptr [RBP + -0x14],EAX
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-20);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_1015A2:; // LEA RDI,[0x102019]
	++__instruction_count;
	RDI = ((u64)0x102019);
	ADDR_1015A9:; // CALL 0x00101279
	++__instruction_count;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x1015ae);
	input_prompt();
	ADDR_1015AE:; // MOV qword ptr [RBP + -0x20],RAX
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-32);
	temp_48512._8 = RAX;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_1015B2:; // MOV dword ptr [RBP + -0x4],0x0
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-4);
	temp_48384._4 = ((u32)0);
	RAM(temp_12544._8)._4 = temp_48384._4;
	ADDR_1015B9:; // JMP 0x001015ed
	++__instruction_count;
	goto ADDR_1015ED;
	ADDR_1015BB:; // MOV EAX,dword ptr [RBP + -0x4]
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_1015BE:; // MOVSXD RDX,EAX
	++__instruction_count;
	RDXs = EAXs;
	ADDR_1015C1:; // MOV RAX,qword ptr [RBP + -0x10]
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-16);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RAX = temp_48512._8;
	ADDR_1015C5:; // ADD RAX,RDX
	++__instruction_count;
	CF = (u64)(RAX + RDX) < RAX;
	OF = SIGN(8, RAXs) == SIGN(8, RDXs) && SIGN(8, (i64)(RAXs + RDXs)) != SIGN(8, RDXs);
	RAX = RAX + RDX;
	SF = RAXs < ((i64)0);
	ZF = RAX == ((u64)0);
	temp_76800._8 = RAX & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_1015C8:; // MOVZX EDX,byte ptr [RAX]
	++__instruction_count;
	temp_47872._1 = RAM(RAX)._1;
	EDX = temp_47872._1;
	RDX = EDX;
	ADDR_1015CB:; // MOV EAX,dword ptr [RBP + -0x4]
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_1015CE:; // MOVSXD RCX,EAX
	++__instruction_count;
	RCXs = EAXs;
	ADDR_1015D1:; // MOV RAX,qword ptr [RBP + -0x20]
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-32);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RAX = temp_48512._8;
	ADDR_1015D5:; // ADD RAX,RCX
	++__instruction_count;
	CF = (u64)(RAX + RCX) < RAX;
	OF = SIGN(8, RAXs) == SIGN(8, RCXs) && SIGN(8, (i64)(RAXs + RCXs)) != SIGN(8, RCXs);
	RAX = RAX + RCX;
	SF = RAXs < ((i64)0);
	ZF = RAX == ((u64)0);
	temp_76800._8 = RAX & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_1015D8:; // MOVZX EAX,byte ptr [RAX]
	++__instruction_count;
	temp_47872._1 = RAM(RAX)._1;
	EAX = temp_47872._1;
	RAX = EAX;
	ADDR_1015DB:; // CMP DL,AL
	++__instruction_count;
	CF = DL < AL;
	OF = SIGN(1, DLs) != SIGN(1, ALs) && SIGN(1, (i8)(DLs - ALs)) == SIGN(1, ALs);
	temp_164864._1 = DL - AL;
	SF = temp_164864._1s < ((i8)0);
	ZF = temp_164864._1 == ((u8)0);
	temp_76800._1 = temp_164864._1 & ((u8)255);
	temp_76928._1 = POPCOUNT(1, temp_76800._1);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_1015DD:; // JZ 0x001015e9
	++__instruction_count;
	if (ZF) goto ADDR_1015E9;
	ADDR_1015DF:; // MOV EDI,0x1
	++__instruction_count;
	RDI = ((u64)1);
	ADDR_1015E4:; // CALL 0x00101058
	++__instruction_count;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x1015e9);
	exit();
	ADDR_1015E9:; // ADD dword ptr [RBP + -0x4],0x1
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-4);
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
	ADDR_1015ED:; // MOV EAX,dword ptr [RBP + -0x4]
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_1015F0:; // CMP EAX,dword ptr [RBP + -0x14]
	++__instruction_count;
	temp_12544._8 = RBP + ((u64)-20);
	temp_20992._4 = RAM(temp_12544._8)._4;
	CF = EAX < temp_20992._4;
	temp_20992._4 = RAM(temp_12544._8)._4;
	OF = SIGN(4, EAXs) != SIGN(4, temp_20992._4s) && SIGN(4, (i32)(EAXs - temp_20992._4s)) == SIGN(4, temp_20992._4s);
	temp_20992._4 = RAM(temp_12544._8)._4;
	temp_166656._4 = EAX - temp_20992._4;
	SF = temp_166656._4s < ((i32)0);
	ZF = temp_166656._4 == ((u32)0);
	temp_76800._4 = temp_166656._4 & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_1015F3:; // JL 0x001015bb
	++__instruction_count;
	temp_52224._1 = OF != SF;
	if (temp_52224._1) goto ADDR_1015BB;
	ADDR_1015F5:; // MOV EDI,0x0
	++__instruction_count;
	RDI = ((u64)0);
	ADDR_1015FA:; // CALL 0x00101058
	++__instruction_count;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x1015ff);
	exit();
	
}
