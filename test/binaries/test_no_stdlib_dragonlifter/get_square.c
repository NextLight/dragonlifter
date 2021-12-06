#include "dragonlifter.h"

void get_square() {
	ADDR_10194A:; // ENDBR64
	
	ADDR_10194E:; // PUSH RBP
	temp_59264._8 = RBP;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_10194F:; // MOV RBP,RSP
	RBP = RSP;
	ADDR_101952:; // SUB RSP,0x10
	CF = RSP < ((u64)16);
	OF = SIGN(8, RSPs) != SIGN(8, ((i64)16)) && SIGN(8, (i64)(RSPs - ((i64)16))) == SIGN(8, ((i64)16));
	RSP = RSP - ((u64)16);
	SF = RSPs < ((i64)0);
	ZF = RSP == ((u64)0);
	temp_76800._8 = RSP & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_101956:; // LEA RDI,[0x10208b]
	RDI = ((u64)0x10208b);
	ADDR_10195D:; // CALL 0x00101279
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x101962);
	input_prompt();
	ADDR_101962:; // MOV RDI,RAX
	RDI = RAX;
	ADDR_101965:; // CALL 0x001014e4
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x10196a);
	string_to_int();
	ADDR_10196A:; // MOV dword ptr [RBP + -0x4],EAX
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = EAX;
	RAM(temp_12544._8)._4 = temp_48256._4;
	ADDR_10196D:; // CMP dword ptr [RBP + -0x4],0x15
	temp_12544._8 = RBP + ((u64)-4);
	temp_48384._4 = RAM(temp_12544._8)._4;
	CF = temp_48384._4 < ((u32)21);
	temp_48384._4 = RAM(temp_12544._8)._4;
	OF = SIGN(4, temp_48384._4s) != SIGN(4, ((i32)21)) && SIGN(4, (i32)(temp_48384._4s - ((i32)21))) == SIGN(4, ((i32)21));
	temp_48384._4 = RAM(temp_12544._8)._4;
	temp_164352._4 = temp_48384._4 - ((u32)21);
	SF = temp_164352._4s < ((i32)0);
	ZF = temp_164352._4 == ((u32)0);
	temp_76800._4 = temp_164352._4 & ((u32)255);
	temp_76928._1 = POPCOUNT(4, temp_76800._4);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_101971:; // JA 0x00101a37
	temp_51200._1 = CF || ZF;
	temp_51456._1 = !temp_51200._1;
	if (temp_51456._1) goto ADDR_101A37;
	ADDR_101977:; // MOV EAX,dword ptr [RBP + -0x4]
	temp_12544._8 = RBP + ((u64)-4);
	temp_48256._4 = RAM(temp_12544._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_10197A:; // LEA RDX,[RAX*0x4]
	temp_13952._8 = RAX * ((u64)4);
	RDX = temp_13952._8;
	ADDR_101982:; // LEA RAX,[0x1020a8]
	RAX = ((u64)0x1020a8);
	ADDR_101989:; // MOV EAX,dword ptr [RDX + RAX*0x1]
	temp_13056._8 = RAX * ((u64)1);
	temp_13312._8 = RDX + temp_13056._8;
	temp_48256._4 = RAM(temp_13312._8)._4;
	EAX = temp_48256._4;
	RAX = EAX;
	ADDR_10198C:; // CDQE
	RAXs = EAXs;
	ADDR_10198E:; // LEA RDX,[0x1020a8]
	RDX = ((u64)0x1020a8);
	ADDR_101995:; // ADD RAX,RDX
	CF = (u64)(RAX + RDX) < RAX;
	OF = SIGN(8, RAXs) == SIGN(8, RDXs) && SIGN(8, (i64)(RAXs + RDXs)) != SIGN(8, RDXs);
	RAX = RAX + RDX;
	SF = RAXs < ((i64)0);
	ZF = RAX == ((u64)0);
	temp_76800._8 = RAX & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_101998:; // JMP RAX
	//NOT-IMPL: Pcode(op=<Op.BRANCHIND: 6>, output=None, input=[Varnode(type=REGISTER, value=0, size=8)])
	ADDR_10199B:; // MOV EAX,0x1
	RAX = ((u64)1);
	ADDR_1019A0:; // JMP 0x00101a3c
	goto ADDR_101A3C;
	ADDR_1019A5:; // MOV EAX,0x4
	RAX = ((u64)4);
	ADDR_1019AA:; // JMP 0x00101a3c
	goto ADDR_101A3C;
	ADDR_1019AF:; // MOV EAX,0x9
	RAX = ((u64)9);
	ADDR_1019B4:; // JMP 0x00101a3c
	goto ADDR_101A3C;
	ADDR_1019B9:; // MOV EAX,0x10
	RAX = ((u64)16);
	ADDR_1019BE:; // JMP 0x00101a3c
	goto ADDR_101A3C;
	ADDR_1019C0:; // MOV EAX,0x19
	RAX = ((u64)25);
	ADDR_1019C5:; // JMP 0x00101a3c
	goto ADDR_101A3C;
	ADDR_1019C7:; // MOV EAX,0x24
	RAX = ((u64)36);
	ADDR_1019CC:; // JMP 0x00101a3c
	goto ADDR_101A3C;
	ADDR_1019CE:; // MOV EAX,0x31
	RAX = ((u64)49);
	ADDR_1019D3:; // JMP 0x00101a3c
	goto ADDR_101A3C;
	ADDR_1019D5:; // MOV EAX,0x40
	RAX = ((u64)64);
	ADDR_1019DA:; // JMP 0x00101a3c
	goto ADDR_101A3C;
	ADDR_1019DC:; // MOV EAX,0x51
	RAX = ((u64)81);
	ADDR_1019E1:; // JMP 0x00101a3c
	goto ADDR_101A3C;
	ADDR_1019E3:; // MOV EAX,0x64
	RAX = ((u64)100);
	ADDR_1019E8:; // JMP 0x00101a3c
	goto ADDR_101A3C;
	ADDR_1019EA:; // MOV EAX,0x79
	RAX = ((u64)121);
	ADDR_1019EF:; // JMP 0x00101a3c
	goto ADDR_101A3C;
	ADDR_1019F1:; // MOV EAX,0x90
	RAX = ((u64)144);
	ADDR_1019F6:; // JMP 0x00101a3c
	goto ADDR_101A3C;
	ADDR_1019F8:; // MOV EAX,0xa9
	RAX = ((u64)169);
	ADDR_1019FD:; // JMP 0x00101a3c
	goto ADDR_101A3C;
	ADDR_1019FF:; // MOV EAX,0xc4
	RAX = ((u64)196);
	ADDR_101A04:; // JMP 0x00101a3c
	goto ADDR_101A3C;
	ADDR_101A06:; // MOV EAX,0xe1
	RAX = ((u64)225);
	ADDR_101A0B:; // JMP 0x00101a3c
	goto ADDR_101A3C;
	ADDR_101A0D:; // MOV EAX,0x100
	RAX = ((u64)0x100);
	ADDR_101A12:; // JMP 0x00101a3c
	goto ADDR_101A3C;
	ADDR_101A14:; // MOV EAX,0x121
	RAX = ((u64)0x121);
	ADDR_101A19:; // JMP 0x00101a3c
	goto ADDR_101A3C;
	ADDR_101A1B:; // MOV EAX,0x144
	RAX = ((u64)0x144);
	ADDR_101A20:; // JMP 0x00101a3c
	goto ADDR_101A3C;
	ADDR_101A22:; // MOV EAX,0x169
	RAX = ((u64)0x169);
	ADDR_101A27:; // JMP 0x00101a3c
	goto ADDR_101A3C;
	ADDR_101A29:; // MOV EAX,0x190
	RAX = ((u64)0x190);
	ADDR_101A2E:; // JMP 0x00101a3c
	goto ADDR_101A3C;
	ADDR_101A30:; // MOV EAX,0x1b9
	RAX = ((u64)0x1b9);
	ADDR_101A35:; // JMP 0x00101a3c
	goto ADDR_101A3C;
	ADDR_101A37:; // MOV EAX,0xffffffff
	RAX = ((u64)0xffffffff);
	ADDR_101A3C:; // LEAVE
	RSP = RBP;
	RBP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_101A3D:; // RET
	RIP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	return;
	
}
