#include "dragonlifter.h"

void input() {
	static const void* labels[] = { &&ADDR_101201,NULL,NULL,NULL,&&ADDR_101205,&&ADDR_101206,NULL,NULL,&&ADDR_101209,NULL,NULL,NULL,&&ADDR_10120D,NULL,NULL,NULL,NULL,NULL,&&ADDR_101213,NULL,&&ADDR_101215,NULL,NULL,NULL,NULL,NULL,NULL,&&ADDR_10121C,NULL,NULL,&&ADDR_10121F,NULL,NULL,NULL,&&ADDR_101223,NULL,&&ADDR_101225,NULL,NULL,NULL,NULL,NULL,&&ADDR_10122B,NULL,NULL,&&ADDR_10122E,NULL,NULL,NULL,NULL,NULL,&&ADDR_101234,NULL,&&ADDR_101236,NULL,NULL,NULL,NULL,NULL,NULL,&&ADDR_10123D,NULL,NULL,NULL,&&ADDR_101241,NULL,NULL,&&ADDR_101244,NULL,NULL,NULL,NULL,&&ADDR_101249,NULL,NULL,NULL,NULL,&&ADDR_10124E,NULL,NULL,&&ADDR_101251,NULL,NULL,NULL,&&ADDR_101255,NULL,&&ADDR_101257,NULL,NULL,NULL,NULL,NULL,&&ADDR_10125D,NULL,NULL,&&ADDR_101260,NULL,NULL,NULL,NULL,NULL,&&ADDR_101266,NULL,&&ADDR_101268,NULL,NULL,NULL,NULL,NULL,NULL,&&ADDR_10126F,NULL,NULL,NULL,&&ADDR_101273,NULL,NULL,NULL,&&ADDR_101277,&&ADDR_101278 };
	static const size_t labels_base_address = 1053185;
	ADDR_101201:; // ENDBR64
	
	ADDR_101205:; // PUSH RBP
	temp_59264._8 = RBP;
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = temp_59264._8;
	ADDR_101206:; // MOV RBP,RSP
	RBP = RSP;
	ADDR_101209:; // SUB RSP,0x10
	CF = RSP < ((u64)16);
	OF = SIGN(8, RSPs) != SIGN(8, ((i64)16)) && SIGN(8, (i64)(RSPs - ((i64)16))) == SIGN(8, ((i64)16));
	RSP = RSP - ((u64)16);
	SF = RSPs < ((i64)0);
	ZF = RSP == ((u64)0);
	temp_76800._8 = RSP & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_10120D:; // MOV EAX,dword ptr [0x00104004]
	EAX = RAM(1064964)._4;
	RAX = EAX;
	ADDR_101213:; // CDQE
	RAXs = EAXs;
	ADDR_101215:; // LEA RDX,[0x104020]
	RDX = ((u64)0x104020);
	ADDR_10121C:; // ADD RAX,RDX
	CF = (u64)(RAX + RDX) < RAX;
	OF = SIGN(8, RAXs) == SIGN(8, RDXs) && SIGN(8, (i64)(RAXs + RDXs)) != SIGN(8, RDXs);
	RAX = RAX + RDX;
	SF = RAXs < ((i64)0);
	ZF = RAX == ((u64)0);
	temp_76800._8 = RAX & ((u64)255);
	temp_76928._1 = POPCOUNT(8, temp_76800._8);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_10121F:; // MOV qword ptr [RBP + -0x8],RAX
	temp_12544._8 = RBP + ((u64)-8);
	temp_48512._8 = RAX;
	RAM(temp_12544._8)._8 = temp_48512._8;
	ADDR_101223:; // JMP 0x00101244
	goto ADDR_101244;
	ADDR_101225:; // MOV EAX,dword ptr [0x00104004]
	EAX = RAM(1064964)._4;
	RAX = EAX;
	ADDR_10122B:; // LEA EDX,[RAX + 0x1]
	temp_12544._8 = RAX + ((u64)1);
	EDX = temp_12544._8 / ((u64)1 << 0);
	RDX = EDX;
	ADDR_10122E:; // MOV dword ptr [0x00104004],EDX
	RAM(1064964)._4 = EDX;
	ADDR_101234:; // CDQE
	RAXs = EAXs;
	ADDR_101236:; // LEA RCX,[0x104020]
	RCX = ((u64)0x104020);
	ADDR_10123D:; // MOVZX EDX,byte ptr [RBP + -0x9]
	temp_12544._8 = RBP + ((u64)-9);
	temp_47872._1 = RAM(temp_12544._8)._1;
	EDX = temp_47872._1;
	RDX = EDX;
	ADDR_101241:; // MOV byte ptr [RAX + RCX*0x1],DL
	temp_13056._8 = RCX * ((u64)1);
	temp_13312._8 = RAX + temp_13056._8;
	temp_47744._1 = DL;
	RAM(temp_13312._8)._1 = temp_47744._1;
	ADDR_101244:; // MOV EAX,0x0
	RAX = ((u64)0);
	ADDR_101249:; // CALL 0x001011da
	RSP = RSP - ((u64)8);
	RAM(RSP)._8 = ((u64)0x10124e);
	getchar();
	ADDR_10124E:; // MOV byte ptr [RBP + -0x9],AL
	temp_12544._8 = RBP + ((u64)-9);
	temp_47744._1 = AL;
	RAM(temp_12544._8)._1 = temp_47744._1;
	ADDR_101251:; // CMP byte ptr [RBP + -0x9],0x1f
	temp_12544._8 = RBP + ((u64)-9);
	temp_47872._1 = RAM(temp_12544._8)._1;
	CF = temp_47872._1 < ((u8)31);
	temp_47872._1 = RAM(temp_12544._8)._1;
	OF = SIGN(1, temp_47872._1s) != SIGN(1, ((i8)31)) && SIGN(1, (i8)(temp_47872._1s - ((i8)31))) == SIGN(1, ((i8)31));
	temp_47872._1 = RAM(temp_12544._8)._1;
	temp_163072._1 = temp_47872._1 - ((u8)31);
	SF = temp_163072._1s < ((i8)0);
	ZF = temp_163072._1 == ((u8)0);
	temp_76800._1 = temp_163072._1 & ((u8)255);
	temp_76928._1 = POPCOUNT(1, temp_76800._1);
	temp_77056._1 = temp_76928._1 & ((u8)1);
	PF = temp_77056._1 == ((u8)0);
	ADDR_101255:; // JG 0x00101225
	temp_52992._1 = !ZF;
	temp_53120._1 = OF == SF;
	temp_53376._1 = temp_52992._1 && temp_53120._1;
	if (temp_53376._1) goto ADDR_101225;
	ADDR_101257:; // MOV EAX,dword ptr [0x00104004]
	EAX = RAM(1064964)._4;
	RAX = EAX;
	ADDR_10125D:; // LEA EDX,[RAX + 0x1]
	temp_12544._8 = RAX + ((u64)1);
	EDX = temp_12544._8 / ((u64)1 << 0);
	RDX = EDX;
	ADDR_101260:; // MOV dword ptr [0x00104004],EDX
	RAM(1064964)._4 = EDX;
	ADDR_101266:; // CDQE
	RAXs = EAXs;
	ADDR_101268:; // LEA RDX,[0x104020]
	RDX = ((u64)0x104020);
	ADDR_10126F:; // MOV byte ptr [RAX + RDX*0x1],0x0
	temp_13056._8 = RDX * ((u64)1);
	temp_13312._8 = RAX + temp_13056._8;
	temp_47872._1 = ((u8)0);
	RAM(temp_13312._8)._1 = temp_47872._1;
	ADDR_101273:; // MOV RAX,qword ptr [RBP + -0x8]
	temp_12544._8 = RBP + ((u64)-8);
	temp_48512._8 = RAM(temp_12544._8)._8;
	RAX = temp_48512._8;
	ADDR_101277:; // LEAVE
	RSP = RBP;
	RBP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	ADDR_101278:; // RET
	RIP = RAM(RSP)._8;
	RSP = RSP + ((u64)8);
	return;
	
}
