#include "syscalls.h"

#define CALLOTHER_syscall() __dispatch_syscall(RAX)

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
} varnode128_t;

