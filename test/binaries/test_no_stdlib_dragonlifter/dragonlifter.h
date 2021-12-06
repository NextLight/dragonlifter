#include <stddef.h>
#include <stdint.h>
#include <assert.h>
#include <math.h>


typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef float f32;
typedef double f64;
typedef long double f80;
typedef uint8_t byte;
typedef __int128_t i128;
typedef __uint128_t u128;

typedef u64 address_t;
typedef void (*funcptr_t)();

typedef union {
	i8 _1s;
	i16 _2s;
	i32 _4s;
	i64 _8s;
	i128 _16s;
	u8 _1;
	u16 _2;
	u32 _4;
	u64 _8;
	u128 _16;
	f32 _4f;
	f64 _8f;
	f80 _10f;
} varnode_t;
typedef struct { address_t addr; byte * ptr; } memory_block_t;
typedef struct { address_t addr; funcptr_t func; } addr_to_func_t;


extern byte memory[];
extern byte stack[];
extern const memory_block_t memory_blocks[];
extern const size_t memory_blocks_count;
extern varnode_t temp_76800, temp_364544, temp_12800, temp_164352, temp_90624, temp_13312, temp_91136, temp_78848, temp_226304, temp_79360, temp_213504, temp_86912, temp_214016, temp_91392, temp_87424, temp_165376, temp_13952, temp_87936, temp_51200, temp_80000, temp_358528, temp_92416, temp_88448, temp_51712, temp_47744, temp_220032, temp_52224, temp_89472, temp_48768, temp_89984, temp_48256, temp_76928, temp_53376, temp_77952, temp_90752, temp_78464, temp_91264, temp_50816, temp_91776, temp_333440, temp_86016, temp_213120, temp_86528, temp_332288, temp_78592, temp_340736, temp_332800, temp_79104, temp_226560, temp_333312, temp_79616, temp_227072, temp_88064, temp_358656, temp_162048, temp_88576, temp_89088, temp_163072, temp_220672, temp_77696, temp_12544, temp_48384, temp_77056, temp_47872, temp_90368, temp_78080, temp_13056, temp_21248, temp_164608, temp_357120, temp_86144, temp_213248, temp_86656, temp_213760, temp_340864, temp_332928, temp_87680, temp_79744, temp_259968, temp_92160, temp_51456, temp_88704, temp_80768, temp_89216, temp_220288, temp_52992, temp_59264, temp_48512, temp_90496, temp_357248, temp_91008, temp_78720, temp_226176, temp_79232, temp_226688, temp_92032, temp_77824, temp_86272, temp_213376, temp_86784, temp_160768, temp_87296, temp_214400, temp_87808, temp_79872, temp_92288, temp_88832, temp_219904, temp_89344, temp_48640, temp_77440, temp_89856, temp_53120;
extern byte registers[];
extern const addr_to_func_t functions[];
extern const size_t functions_count;


#define SIGN(sz, v) ((v) >= 0)
#define ISNAN(sz, v) isnan(v)
#define FABS(sz, v) fabs(v)
#define SQRT(sz, v) sqrt(v)
#define CEIL(sz, v) ceil(v)
#define FLOOR(sz, v) floor(v)
#define ROUND(sz, v) round(v)
#define POPCOUNT(sz, v) _popcount8(v)
#define RAM_ADDR(addr) ((varnode_t*)find_memory_pos(addr))
#define RAM(addr) (*RAM_ADDR(addr))

#define RAX ((varnode_t*)&registers[0])->_8
#define RAXs ((varnode_t*)&registers[0])->_8s
#define RAXf ((varnode_t*)&registers[0])->_8f
#define EAX ((varnode_t*)&registers[0])->_4
#define EAXs ((varnode_t*)&registers[0])->_4s
#define EAXf ((varnode_t*)&registers[0])->_4f
#define AX ((varnode_t*)&registers[0])->_2
#define AXs ((varnode_t*)&registers[0])->_2s
#define AXf ((varnode_t*)&registers[0])->_2f
#define AL ((varnode_t*)&registers[0])->_1
#define ALs ((varnode_t*)&registers[0])->_1s
#define ALf ((varnode_t*)&registers[0])->_1f
#define CF ((varnode_t*)&registers[512])->_1
#define CFs ((varnode_t*)&registers[512])->_1s
#define CFf ((varnode_t*)&registers[512])->_1f
#define PF ((varnode_t*)&registers[514])->_1
#define PFs ((varnode_t*)&registers[514])->_1s
#define PFf ((varnode_t*)&registers[514])->_1f
#define R8 ((varnode_t*)&registers[128])->_8
#define R8s ((varnode_t*)&registers[128])->_8s
#define R8f ((varnode_t*)&registers[128])->_8f
#define R8D ((varnode_t*)&registers[128])->_4
#define R8Ds ((varnode_t*)&registers[128])->_4s
#define R8Df ((varnode_t*)&registers[128])->_4f
#define R8W ((varnode_t*)&registers[128])->_2
#define R8Ws ((varnode_t*)&registers[128])->_2s
#define R8Wf ((varnode_t*)&registers[128])->_2f
#define R8B ((varnode_t*)&registers[128])->_1
#define R8Bs ((varnode_t*)&registers[128])->_1s
#define R8Bf ((varnode_t*)&registers[128])->_1f
#define XMM0 ((varnode_t*)&registers[4608])->_16
#define XMM0s ((varnode_t*)&registers[4608])->_16s
#define XMM0f ((varnode_t*)&registers[4608])->_16f
#define XMM0_Qa ((varnode_t*)&registers[4608])->_8
#define XMM0_Qas ((varnode_t*)&registers[4608])->_8s
#define XMM0_Qaf ((varnode_t*)&registers[4608])->_8f
#define XMM0_Da ((varnode_t*)&registers[4608])->_4
#define XMM0_Das ((varnode_t*)&registers[4608])->_4s
#define XMM0_Daf ((varnode_t*)&registers[4608])->_4f
#define XMM0_Wa ((varnode_t*)&registers[4608])->_2
#define XMM0_Was ((varnode_t*)&registers[4608])->_2s
#define XMM0_Waf ((varnode_t*)&registers[4608])->_2f
#define XMM0_Ba ((varnode_t*)&registers[4608])->_1
#define XMM0_Bas ((varnode_t*)&registers[4608])->_1s
#define XMM0_Baf ((varnode_t*)&registers[4608])->_1f
#define YMM0 ((varnode_t*)&registers[4608])->_32
#define YMM0s ((varnode_t*)&registers[4608])->_32s
#define YMM0f ((varnode_t*)&registers[4608])->_32f
#define XMM4 ((varnode_t*)&registers[4736])->_16
#define XMM4s ((varnode_t*)&registers[4736])->_16s
#define XMM4f ((varnode_t*)&registers[4736])->_16f
#define XMM4_Qa ((varnode_t*)&registers[4736])->_8
#define XMM4_Qas ((varnode_t*)&registers[4736])->_8s
#define XMM4_Qaf ((varnode_t*)&registers[4736])->_8f
#define XMM4_Da ((varnode_t*)&registers[4736])->_4
#define XMM4_Das ((varnode_t*)&registers[4736])->_4s
#define XMM4_Daf ((varnode_t*)&registers[4736])->_4f
#define XMM4_Wa ((varnode_t*)&registers[4736])->_2
#define XMM4_Was ((varnode_t*)&registers[4736])->_2s
#define XMM4_Waf ((varnode_t*)&registers[4736])->_2f
#define XMM4_Ba ((varnode_t*)&registers[4736])->_1
#define XMM4_Bas ((varnode_t*)&registers[4736])->_1s
#define XMM4_Baf ((varnode_t*)&registers[4736])->_1f
#define YMM4 ((varnode_t*)&registers[4736])->_32
#define YMM4s ((varnode_t*)&registers[4736])->_32s
#define YMM4f ((varnode_t*)&registers[4736])->_32f
#define ZF ((varnode_t*)&registers[518])->_1
#define ZFs ((varnode_t*)&registers[518])->_1s
#define ZFf ((varnode_t*)&registers[518])->_1f
#define SF ((varnode_t*)&registers[519])->_1
#define SFs ((varnode_t*)&registers[519])->_1s
#define SFf ((varnode_t*)&registers[519])->_1f
#define RIP ((varnode_t*)&registers[648])->_8
#define RIPs ((varnode_t*)&registers[648])->_8s
#define RIPf ((varnode_t*)&registers[648])->_8f
#define EIP ((varnode_t*)&registers[648])->_4
#define EIPs ((varnode_t*)&registers[648])->_4s
#define EIPf ((varnode_t*)&registers[648])->_4f
#define IP ((varnode_t*)&registers[648])->_2
#define IPs ((varnode_t*)&registers[648])->_2s
#define IPf ((varnode_t*)&registers[648])->_2f
#define RCX ((varnode_t*)&registers[8])->_8
#define RCXs ((varnode_t*)&registers[8])->_8s
#define RCXf ((varnode_t*)&registers[8])->_8f
#define ECX ((varnode_t*)&registers[8])->_4
#define ECXs ((varnode_t*)&registers[8])->_4s
#define ECXf ((varnode_t*)&registers[8])->_4f
#define CX ((varnode_t*)&registers[8])->_2
#define CXs ((varnode_t*)&registers[8])->_2s
#define CXf ((varnode_t*)&registers[8])->_2f
#define CL ((varnode_t*)&registers[8])->_1
#define CLs ((varnode_t*)&registers[8])->_1s
#define CLf ((varnode_t*)&registers[8])->_1f
#define R9 ((varnode_t*)&registers[136])->_8
#define R9s ((varnode_t*)&registers[136])->_8s
#define R9f ((varnode_t*)&registers[136])->_8f
#define R9D ((varnode_t*)&registers[136])->_4
#define R9Ds ((varnode_t*)&registers[136])->_4s
#define R9Df ((varnode_t*)&registers[136])->_4f
#define R9W ((varnode_t*)&registers[136])->_2
#define R9Ws ((varnode_t*)&registers[136])->_2s
#define R9Wf ((varnode_t*)&registers[136])->_2f
#define R9B ((varnode_t*)&registers[136])->_1
#define R9Bs ((varnode_t*)&registers[136])->_1s
#define R9Bf ((varnode_t*)&registers[136])->_1f
#define OF ((varnode_t*)&registers[523])->_1
#define OFs ((varnode_t*)&registers[523])->_1s
#define OFf ((varnode_t*)&registers[523])->_1f
#define RDX ((varnode_t*)&registers[16])->_8
#define RDXs ((varnode_t*)&registers[16])->_8s
#define RDXf ((varnode_t*)&registers[16])->_8f
#define EDX ((varnode_t*)&registers[16])->_4
#define EDXs ((varnode_t*)&registers[16])->_4s
#define EDXf ((varnode_t*)&registers[16])->_4f
#define DX ((varnode_t*)&registers[16])->_2
#define DXs ((varnode_t*)&registers[16])->_2s
#define DXf ((varnode_t*)&registers[16])->_2f
#define DL ((varnode_t*)&registers[16])->_1
#define DLs ((varnode_t*)&registers[16])->_1s
#define DLf ((varnode_t*)&registers[16])->_1f
#define RBX ((varnode_t*)&registers[24])->_8
#define RBXs ((varnode_t*)&registers[24])->_8s
#define RBXf ((varnode_t*)&registers[24])->_8f
#define EBX ((varnode_t*)&registers[24])->_4
#define EBXs ((varnode_t*)&registers[24])->_4s
#define EBXf ((varnode_t*)&registers[24])->_4f
#define BX ((varnode_t*)&registers[24])->_2
#define BXs ((varnode_t*)&registers[24])->_2s
#define BXf ((varnode_t*)&registers[24])->_2f
#define BL ((varnode_t*)&registers[24])->_1
#define BLs ((varnode_t*)&registers[24])->_1s
#define BLf ((varnode_t*)&registers[24])->_1f
#define RSP ((varnode_t*)&registers[32])->_8
#define RSPs ((varnode_t*)&registers[32])->_8s
#define RSPf ((varnode_t*)&registers[32])->_8f
#define ESP ((varnode_t*)&registers[32])->_4
#define ESPs ((varnode_t*)&registers[32])->_4s
#define ESPf ((varnode_t*)&registers[32])->_4f
#define SP ((varnode_t*)&registers[32])->_2
#define SPs ((varnode_t*)&registers[32])->_2s
#define SPf ((varnode_t*)&registers[32])->_2f
#define SPL ((varnode_t*)&registers[32])->_1
#define SPLs ((varnode_t*)&registers[32])->_1s
#define SPLf ((varnode_t*)&registers[32])->_1f
#define XMM1 ((varnode_t*)&registers[4640])->_16
#define XMM1s ((varnode_t*)&registers[4640])->_16s
#define XMM1f ((varnode_t*)&registers[4640])->_16f
#define XMM1_Qa ((varnode_t*)&registers[4640])->_8
#define XMM1_Qas ((varnode_t*)&registers[4640])->_8s
#define XMM1_Qaf ((varnode_t*)&registers[4640])->_8f
#define XMM1_Da ((varnode_t*)&registers[4640])->_4
#define XMM1_Das ((varnode_t*)&registers[4640])->_4s
#define XMM1_Daf ((varnode_t*)&registers[4640])->_4f
#define XMM1_Wa ((varnode_t*)&registers[4640])->_2
#define XMM1_Was ((varnode_t*)&registers[4640])->_2s
#define XMM1_Waf ((varnode_t*)&registers[4640])->_2f
#define XMM1_Ba ((varnode_t*)&registers[4640])->_1
#define XMM1_Bas ((varnode_t*)&registers[4640])->_1s
#define XMM1_Baf ((varnode_t*)&registers[4640])->_1f
#define YMM1 ((varnode_t*)&registers[4640])->_32
#define YMM1s ((varnode_t*)&registers[4640])->_32s
#define YMM1f ((varnode_t*)&registers[4640])->_32f
#define XMM5 ((varnode_t*)&registers[4768])->_16
#define XMM5s ((varnode_t*)&registers[4768])->_16s
#define XMM5f ((varnode_t*)&registers[4768])->_16f
#define XMM5_Qa ((varnode_t*)&registers[4768])->_8
#define XMM5_Qas ((varnode_t*)&registers[4768])->_8s
#define XMM5_Qaf ((varnode_t*)&registers[4768])->_8f
#define XMM5_Da ((varnode_t*)&registers[4768])->_4
#define XMM5_Das ((varnode_t*)&registers[4768])->_4s
#define XMM5_Daf ((varnode_t*)&registers[4768])->_4f
#define XMM5_Wa ((varnode_t*)&registers[4768])->_2
#define XMM5_Was ((varnode_t*)&registers[4768])->_2s
#define XMM5_Waf ((varnode_t*)&registers[4768])->_2f
#define XMM5_Ba ((varnode_t*)&registers[4768])->_1
#define XMM5_Bas ((varnode_t*)&registers[4768])->_1s
#define XMM5_Baf ((varnode_t*)&registers[4768])->_1f
#define YMM5 ((varnode_t*)&registers[4768])->_32
#define YMM5s ((varnode_t*)&registers[4768])->_32s
#define YMM5f ((varnode_t*)&registers[4768])->_32f
#define R12 ((varnode_t*)&registers[160])->_8
#define R12s ((varnode_t*)&registers[160])->_8s
#define R12f ((varnode_t*)&registers[160])->_8f
#define R12D ((varnode_t*)&registers[160])->_4
#define R12Ds ((varnode_t*)&registers[160])->_4s
#define R12Df ((varnode_t*)&registers[160])->_4f
#define R12W ((varnode_t*)&registers[160])->_2
#define R12Ws ((varnode_t*)&registers[160])->_2s
#define R12Wf ((varnode_t*)&registers[160])->_2f
#define R12B ((varnode_t*)&registers[160])->_1
#define R12Bs ((varnode_t*)&registers[160])->_1s
#define R12Bf ((varnode_t*)&registers[160])->_1f
#define RBP ((varnode_t*)&registers[40])->_8
#define RBPs ((varnode_t*)&registers[40])->_8s
#define RBPf ((varnode_t*)&registers[40])->_8f
#define EBP ((varnode_t*)&registers[40])->_4
#define EBPs ((varnode_t*)&registers[40])->_4s
#define EBPf ((varnode_t*)&registers[40])->_4f
#define BP ((varnode_t*)&registers[40])->_2
#define BPs ((varnode_t*)&registers[40])->_2s
#define BPf ((varnode_t*)&registers[40])->_2f
#define BPL ((varnode_t*)&registers[40])->_1
#define BPLs ((varnode_t*)&registers[40])->_1s
#define BPLf ((varnode_t*)&registers[40])->_1f
#define R13 ((varnode_t*)&registers[168])->_8
#define R13s ((varnode_t*)&registers[168])->_8s
#define R13f ((varnode_t*)&registers[168])->_8f
#define R13D ((varnode_t*)&registers[168])->_4
#define R13Ds ((varnode_t*)&registers[168])->_4s
#define R13Df ((varnode_t*)&registers[168])->_4f
#define R13W ((varnode_t*)&registers[168])->_2
#define R13Ws ((varnode_t*)&registers[168])->_2s
#define R13Wf ((varnode_t*)&registers[168])->_2f
#define R13B ((varnode_t*)&registers[168])->_1
#define R13Bs ((varnode_t*)&registers[168])->_1s
#define R13Bf ((varnode_t*)&registers[168])->_1f
#define RSI ((varnode_t*)&registers[48])->_8
#define RSIs ((varnode_t*)&registers[48])->_8s
#define RSIf ((varnode_t*)&registers[48])->_8f
#define ESI ((varnode_t*)&registers[48])->_4
#define ESIs ((varnode_t*)&registers[48])->_4s
#define ESIf ((varnode_t*)&registers[48])->_4f
#define SI ((varnode_t*)&registers[48])->_2
#define SIs ((varnode_t*)&registers[48])->_2s
#define SIf ((varnode_t*)&registers[48])->_2f
#define SIL ((varnode_t*)&registers[48])->_1
#define SILs ((varnode_t*)&registers[48])->_1s
#define SILf ((varnode_t*)&registers[48])->_1f
#define R14 ((varnode_t*)&registers[176])->_8
#define R14s ((varnode_t*)&registers[176])->_8s
#define R14f ((varnode_t*)&registers[176])->_8f
#define R14D ((varnode_t*)&registers[176])->_4
#define R14Ds ((varnode_t*)&registers[176])->_4s
#define R14Df ((varnode_t*)&registers[176])->_4f
#define R14W ((varnode_t*)&registers[176])->_2
#define R14Ws ((varnode_t*)&registers[176])->_2s
#define R14Wf ((varnode_t*)&registers[176])->_2f
#define R14B ((varnode_t*)&registers[176])->_1
#define R14Bs ((varnode_t*)&registers[176])->_1s
#define R14Bf ((varnode_t*)&registers[176])->_1f
#define RDI ((varnode_t*)&registers[56])->_8
#define RDIs ((varnode_t*)&registers[56])->_8s
#define RDIf ((varnode_t*)&registers[56])->_8f
#define EDI ((varnode_t*)&registers[56])->_4
#define EDIs ((varnode_t*)&registers[56])->_4s
#define EDIf ((varnode_t*)&registers[56])->_4f
#define DI ((varnode_t*)&registers[56])->_2
#define DIs ((varnode_t*)&registers[56])->_2s
#define DIf ((varnode_t*)&registers[56])->_2f
#define DIL ((varnode_t*)&registers[56])->_1
#define DILs ((varnode_t*)&registers[56])->_1s
#define DILf ((varnode_t*)&registers[56])->_1f
#define R15 ((varnode_t*)&registers[184])->_8
#define R15s ((varnode_t*)&registers[184])->_8s
#define R15f ((varnode_t*)&registers[184])->_8f
#define R15D ((varnode_t*)&registers[184])->_4
#define R15Ds ((varnode_t*)&registers[184])->_4s
#define R15Df ((varnode_t*)&registers[184])->_4f
#define R15W ((varnode_t*)&registers[184])->_2
#define R15Ws ((varnode_t*)&registers[184])->_2s
#define R15Wf ((varnode_t*)&registers[184])->_2f
#define R15B ((varnode_t*)&registers[184])->_1
#define R15Bs ((varnode_t*)&registers[184])->_1s
#define R15Bf ((varnode_t*)&registers[184])->_1f
#define XMM2 ((varnode_t*)&registers[4672])->_16
#define XMM2s ((varnode_t*)&registers[4672])->_16s
#define XMM2f ((varnode_t*)&registers[4672])->_16f
#define XMM2_Qa ((varnode_t*)&registers[4672])->_8
#define XMM2_Qas ((varnode_t*)&registers[4672])->_8s
#define XMM2_Qaf ((varnode_t*)&registers[4672])->_8f
#define XMM2_Da ((varnode_t*)&registers[4672])->_4
#define XMM2_Das ((varnode_t*)&registers[4672])->_4s
#define XMM2_Daf ((varnode_t*)&registers[4672])->_4f
#define XMM2_Wa ((varnode_t*)&registers[4672])->_2
#define XMM2_Was ((varnode_t*)&registers[4672])->_2s
#define XMM2_Waf ((varnode_t*)&registers[4672])->_2f
#define XMM2_Ba ((varnode_t*)&registers[4672])->_1
#define XMM2_Bas ((varnode_t*)&registers[4672])->_1s
#define XMM2_Baf ((varnode_t*)&registers[4672])->_1f
#define YMM2 ((varnode_t*)&registers[4672])->_32
#define YMM2s ((varnode_t*)&registers[4672])->_32s
#define YMM2f ((varnode_t*)&registers[4672])->_32f
#define XMM6 ((varnode_t*)&registers[4800])->_16
#define XMM6s ((varnode_t*)&registers[4800])->_16s
#define XMM6f ((varnode_t*)&registers[4800])->_16f
#define XMM6_Qa ((varnode_t*)&registers[4800])->_8
#define XMM6_Qas ((varnode_t*)&registers[4800])->_8s
#define XMM6_Qaf ((varnode_t*)&registers[4800])->_8f
#define XMM6_Da ((varnode_t*)&registers[4800])->_4
#define XMM6_Das ((varnode_t*)&registers[4800])->_4s
#define XMM6_Daf ((varnode_t*)&registers[4800])->_4f
#define XMM6_Wa ((varnode_t*)&registers[4800])->_2
#define XMM6_Was ((varnode_t*)&registers[4800])->_2s
#define XMM6_Waf ((varnode_t*)&registers[4800])->_2f
#define XMM6_Ba ((varnode_t*)&registers[4800])->_1
#define XMM6_Bas ((varnode_t*)&registers[4800])->_1s
#define XMM6_Baf ((varnode_t*)&registers[4800])->_1f
#define YMM6 ((varnode_t*)&registers[4800])->_32
#define YMM6s ((varnode_t*)&registers[4800])->_32s
#define YMM6f ((varnode_t*)&registers[4800])->_32f
#define XMM3 ((varnode_t*)&registers[4704])->_16
#define XMM3s ((varnode_t*)&registers[4704])->_16s
#define XMM3f ((varnode_t*)&registers[4704])->_16f
#define XMM3_Qa ((varnode_t*)&registers[4704])->_8
#define XMM3_Qas ((varnode_t*)&registers[4704])->_8s
#define XMM3_Qaf ((varnode_t*)&registers[4704])->_8f
#define XMM3_Da ((varnode_t*)&registers[4704])->_4
#define XMM3_Das ((varnode_t*)&registers[4704])->_4s
#define XMM3_Daf ((varnode_t*)&registers[4704])->_4f
#define XMM3_Wa ((varnode_t*)&registers[4704])->_2
#define XMM3_Was ((varnode_t*)&registers[4704])->_2s
#define XMM3_Waf ((varnode_t*)&registers[4704])->_2f
#define XMM3_Ba ((varnode_t*)&registers[4704])->_1
#define XMM3_Bas ((varnode_t*)&registers[4704])->_1s
#define XMM3_Baf ((varnode_t*)&registers[4704])->_1f
#define YMM3 ((varnode_t*)&registers[4704])->_32
#define YMM3s ((varnode_t*)&registers[4704])->_32s
#define YMM3f ((varnode_t*)&registers[4704])->_32f
#define XMM7 ((varnode_t*)&registers[4832])->_16
#define XMM7s ((varnode_t*)&registers[4832])->_16s
#define XMM7f ((varnode_t*)&registers[4832])->_16f
#define XMM7_Qa ((varnode_t*)&registers[4832])->_8
#define XMM7_Qas ((varnode_t*)&registers[4832])->_8s
#define XMM7_Qaf ((varnode_t*)&registers[4832])->_8f
#define XMM7_Da ((varnode_t*)&registers[4832])->_4
#define XMM7_Das ((varnode_t*)&registers[4832])->_4s
#define XMM7_Daf ((varnode_t*)&registers[4832])->_4f
#define XMM7_Wa ((varnode_t*)&registers[4832])->_2
#define XMM7_Was ((varnode_t*)&registers[4832])->_2s
#define XMM7_Waf ((varnode_t*)&registers[4832])->_2f
#define XMM7_Ba ((varnode_t*)&registers[4832])->_1
#define XMM7_Bas ((varnode_t*)&registers[4832])->_1s
#define XMM7_Baf ((varnode_t*)&registers[4832])->_1f
#define YMM7 ((varnode_t*)&registers[4832])->_32
#define YMM7s ((varnode_t*)&registers[4832])->_32s
#define YMM7f ((varnode_t*)&registers[4832])->_32f

#define CALL_FUNCTION_AT(addr) function_binary_search(functions, functions_count, addr)()
#define CALLOTHER(f, ...) CALLOTHER_##f(__VA_ARGS__)



static inline u8 _popcount8(u64 v) {
	u8 o = 0;
	for (; v; o++)
	v &= v - 1;
	return o;
}

static inline byte * find_memory_pos(address_t addr) {
	for (size_t i = memory_blocks_count - 1; i >= 0; i--) {
		if (memory_blocks[i].addr <= addr)
		return (byte *)memory_blocks[i].ptr + addr - memory_blocks[i].addr;
	}
	assert(0);
}

extern void write();
extern void read();
extern void exit();
extern void strlen();
extern void print_raw();
extern void getchar();
extern void input();
extern void input_prompt();
extern void int_to_string();
extern void string_to_int();
extern void bin();
extern void calc();
extern void bitwise_and();
extern void bitwise_or();
extern void bitwise_xor();
extern void calc_bitwise();
extern void get_square();
extern void _start();

static inline funcptr_t function_binary_search(const addr_to_func_t * arr, size_t size, address_t addr) {
	size_t l = 0, r = size;
	while (l < r) {
		size_t m = (l + r) / 2;
		if (arr[m].addr == addr)
		return arr[m].func;
		else if (arr[m].addr > addr)
		r = m;
		else
		l = m + 1;
	}
	// assert(0);
}

#include "dragonlifter_user.h"
