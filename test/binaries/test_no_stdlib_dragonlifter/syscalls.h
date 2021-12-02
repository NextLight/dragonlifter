static inline void __syscall_sys_read() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_write() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_open() {
	unsigned long long rax = RAX;
	unsigned long long rdi = (unsigned long long)RAM_ADDR(RDI);
	unsigned long long rsi = RSI;
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_close() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_newstat() {
	unsigned long long rax = RAX;
	unsigned long long rdi = (unsigned long long)RAM_ADDR(RDI);
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_newfstat() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_newlstat() {
	unsigned long long rax = RAX;
	unsigned long long rdi = (unsigned long long)RAM_ADDR(RDI);
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_poll() {
	unsigned long long rax = RAX;
	unsigned long long rdi = (unsigned long long)RAM_ADDR(RDI);
	unsigned long long rsi = RSI;
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_lseek() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = RSI;
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_mmap() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = RSI;
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_mprotect() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = RSI;
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_munmap() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = RSI;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_brk() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_rt_sigaction() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	unsigned long long rdx = (unsigned long long)RAM_ADDR(RDX);
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_rt_sigprocmask() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	unsigned long long rdx = (unsigned long long)RAM_ADDR(RDX);
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_rt_sigreturn() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_ioctl() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = RSI;
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_pread64() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_pwrite64() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_readv() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_writev() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_access() {
	unsigned long long rax = RAX;
	unsigned long long rdi = (unsigned long long)RAM_ADDR(RDI);
	unsigned long long rsi = RSI;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_pipe() {
	unsigned long long rax = RAX;
	unsigned long long rdi = (unsigned long long)RAM_ADDR(RDI);
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_select() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	unsigned long long rdx = (unsigned long long)RAM_ADDR(RDX);
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_sched_yield() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_mremap() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = RSI;
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_msync() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = RSI;
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_mincore() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = RSI;
	unsigned long long rdx = (unsigned long long)RAM_ADDR(RDX);
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_madvise() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = RSI;
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_shmget() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = RSI;
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_shmat() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_shmctl() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = RSI;
	unsigned long long rdx = (unsigned long long)RAM_ADDR(RDX);
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_dup() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_dup2() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = RSI;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_pause() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_nanosleep() {
	unsigned long long rax = RAX;
	unsigned long long rdi = (unsigned long long)RAM_ADDR(RDI);
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_getitimer() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_alarm() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_setitimer() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	unsigned long long rdx = (unsigned long long)RAM_ADDR(RDX);
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_getpid() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_sendfile64() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = RSI;
	unsigned long long rdx = (unsigned long long)RAM_ADDR(RDX);
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_socket() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = RSI;
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_connect() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_accept() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	unsigned long long rdx = (unsigned long long)RAM_ADDR(RDX);
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_sendto() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_recvfrom() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_sendmsg() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_recvmsg() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_shutdown() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = RSI;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_bind() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_listen() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = RSI;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_getsockname() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	unsigned long long rdx = (unsigned long long)RAM_ADDR(RDX);
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_getpeername() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	unsigned long long rdx = (unsigned long long)RAM_ADDR(RDX);
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_socketpair() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = RSI;
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_setsockopt() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = RSI;
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_getsockopt() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = RSI;
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_clone() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = RSI;
	unsigned long long rdx = (unsigned long long)RAM_ADDR(RDX);
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_fork() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_vfork() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_execve() {
	unsigned long long rax = RAX;
	unsigned long long rdi = (unsigned long long)RAM_ADDR(RDI);
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	unsigned long long rdx = (unsigned long long)RAM_ADDR(RDX);
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_exit() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_wait4() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_kill() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = RSI;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_newuname() {
	unsigned long long rax = RAX;
	unsigned long long rdi = (unsigned long long)RAM_ADDR(RDI);
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_semget() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = RSI;
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_semop() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_semctl() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = RSI;
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_shmdt() {
	unsigned long long rax = RAX;
	unsigned long long rdi = (unsigned long long)RAM_ADDR(RDI);
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_msgget() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = RSI;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_msgsnd() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_msgrcv() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_msgctl() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = RSI;
	unsigned long long rdx = (unsigned long long)RAM_ADDR(RDX);
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_fcntl() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = RSI;
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_flock() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = RSI;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_fsync() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_fdatasync() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_truncate() {
	unsigned long long rax = RAX;
	unsigned long long rdi = (unsigned long long)RAM_ADDR(RDI);
	unsigned long long rsi = RSI;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_ftruncate() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = RSI;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_getdents() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_getcwd() {
	unsigned long long rax = RAX;
	unsigned long long rdi = (unsigned long long)RAM_ADDR(RDI);
	unsigned long long rsi = RSI;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_chdir() {
	unsigned long long rax = RAX;
	unsigned long long rdi = (unsigned long long)RAM_ADDR(RDI);
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_fchdir() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_rename() {
	unsigned long long rax = RAX;
	unsigned long long rdi = (unsigned long long)RAM_ADDR(RDI);
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_mkdir() {
	unsigned long long rax = RAX;
	unsigned long long rdi = (unsigned long long)RAM_ADDR(RDI);
	unsigned long long rsi = RSI;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_rmdir() {
	unsigned long long rax = RAX;
	unsigned long long rdi = (unsigned long long)RAM_ADDR(RDI);
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_creat() {
	unsigned long long rax = RAX;
	unsigned long long rdi = (unsigned long long)RAM_ADDR(RDI);
	unsigned long long rsi = RSI;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_link() {
	unsigned long long rax = RAX;
	unsigned long long rdi = (unsigned long long)RAM_ADDR(RDI);
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_unlink() {
	unsigned long long rax = RAX;
	unsigned long long rdi = (unsigned long long)RAM_ADDR(RDI);
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_symlink() {
	unsigned long long rax = RAX;
	unsigned long long rdi = (unsigned long long)RAM_ADDR(RDI);
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_readlink() {
	unsigned long long rax = RAX;
	unsigned long long rdi = (unsigned long long)RAM_ADDR(RDI);
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_chmod() {
	unsigned long long rax = RAX;
	unsigned long long rdi = (unsigned long long)RAM_ADDR(RDI);
	unsigned long long rsi = RSI;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_fchmod() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = RSI;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_chown() {
	unsigned long long rax = RAX;
	unsigned long long rdi = (unsigned long long)RAM_ADDR(RDI);
	unsigned long long rsi = RSI;
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_fchown() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = RSI;
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_lchown() {
	unsigned long long rax = RAX;
	unsigned long long rdi = (unsigned long long)RAM_ADDR(RDI);
	unsigned long long rsi = RSI;
	unsigned long long rdx = RDX;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi), "d" (rdx)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_umask() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_gettimeofday() {
	unsigned long long rax = RAX;
	unsigned long long rdi = (unsigned long long)RAM_ADDR(RDI);
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_getrlimit() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_getrusage() {
	unsigned long long rax = RAX;
	unsigned long long rdi = RDI;
	unsigned long long rsi = (unsigned long long)RAM_ADDR(RSI);
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi), "S" (rsi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __syscall_sys_sysinfo() {
	unsigned long long rax = RAX;
	unsigned long long rdi = (unsigned long long)RAM_ADDR(RDI);
	__asm__ __volatile__(
		"syscall"
		: "+a" (rax)
		: "D" (rdi)
		: "rcx", "r11", "memory"
	);
	RAX = rax;
}
static inline void __dispatch_syscall(int id) {
	switch (id) {
	case 0: return __syscall_sys_read();
	case 1: return __syscall_sys_write();
	case 2: return __syscall_sys_open();
	case 3: return __syscall_sys_close();
	case 4: return __syscall_sys_newstat();
	case 5: return __syscall_sys_newfstat();
	case 6: return __syscall_sys_newlstat();
	case 7: return __syscall_sys_poll();
	case 8: return __syscall_sys_lseek();
	case 9: return __syscall_sys_mmap();
	case 10: return __syscall_sys_mprotect();
	case 11: return __syscall_sys_munmap();
	case 12: return __syscall_sys_brk();
	case 13: return __syscall_sys_rt_sigaction();
	case 14: return __syscall_sys_rt_sigprocmask();
	case 15: return __syscall_sys_rt_sigreturn();
	case 16: return __syscall_sys_ioctl();
	case 17: return __syscall_sys_pread64();
	case 18: return __syscall_sys_pwrite64();
	case 19: return __syscall_sys_readv();
	case 20: return __syscall_sys_writev();
	case 21: return __syscall_sys_access();
	case 22: return __syscall_sys_pipe();
	case 23: return __syscall_sys_select();
	case 24: return __syscall_sys_sched_yield();
	case 25: return __syscall_sys_mremap();
	case 26: return __syscall_sys_msync();
	case 27: return __syscall_sys_mincore();
	case 28: return __syscall_sys_madvise();
	case 29: return __syscall_sys_shmget();
	case 30: return __syscall_sys_shmat();
	case 31: return __syscall_sys_shmctl();
	case 32: return __syscall_sys_dup();
	case 33: return __syscall_sys_dup2();
	case 34: return __syscall_sys_pause();
	case 35: return __syscall_sys_nanosleep();
	case 36: return __syscall_sys_getitimer();
	case 37: return __syscall_sys_alarm();
	case 38: return __syscall_sys_setitimer();
	case 39: return __syscall_sys_getpid();
	case 40: return __syscall_sys_sendfile64();
	case 41: return __syscall_sys_socket();
	case 42: return __syscall_sys_connect();
	case 43: return __syscall_sys_accept();
	case 44: return __syscall_sys_sendto();
	case 45: return __syscall_sys_recvfrom();
	case 46: return __syscall_sys_sendmsg();
	case 47: return __syscall_sys_recvmsg();
	case 48: return __syscall_sys_shutdown();
	case 49: return __syscall_sys_bind();
	case 50: return __syscall_sys_listen();
	case 51: return __syscall_sys_getsockname();
	case 52: return __syscall_sys_getpeername();
	case 53: return __syscall_sys_socketpair();
	case 54: return __syscall_sys_setsockopt();
	case 55: return __syscall_sys_getsockopt();
	case 56: return __syscall_sys_clone();
	case 57: return __syscall_sys_fork();
	case 58: return __syscall_sys_vfork();
	case 59: return __syscall_sys_execve();
	case 60: return __syscall_sys_exit();
	case 61: return __syscall_sys_wait4();
	case 62: return __syscall_sys_kill();
	case 63: return __syscall_sys_newuname();
	case 64: return __syscall_sys_semget();
	case 65: return __syscall_sys_semop();
	case 66: return __syscall_sys_semctl();
	case 67: return __syscall_sys_shmdt();
	case 68: return __syscall_sys_msgget();
	case 69: return __syscall_sys_msgsnd();
	case 70: return __syscall_sys_msgrcv();
	case 71: return __syscall_sys_msgctl();
	case 72: return __syscall_sys_fcntl();
	case 73: return __syscall_sys_flock();
	case 74: return __syscall_sys_fsync();
	case 75: return __syscall_sys_fdatasync();
	case 76: return __syscall_sys_truncate();
	case 77: return __syscall_sys_ftruncate();
	case 78: return __syscall_sys_getdents();
	case 79: return __syscall_sys_getcwd();
	case 80: return __syscall_sys_chdir();
	case 81: return __syscall_sys_fchdir();
	case 82: return __syscall_sys_rename();
	case 83: return __syscall_sys_mkdir();
	case 84: return __syscall_sys_rmdir();
	case 85: return __syscall_sys_creat();
	case 86: return __syscall_sys_link();
	case 87: return __syscall_sys_unlink();
	case 88: return __syscall_sys_symlink();
	case 89: return __syscall_sys_readlink();
	case 90: return __syscall_sys_chmod();
	case 91: return __syscall_sys_fchmod();
	case 92: return __syscall_sys_chown();
	case 93: return __syscall_sys_fchown();
	case 94: return __syscall_sys_lchown();
	case 95: return __syscall_sys_umask();
	case 96: return __syscall_sys_gettimeofday();
	case 97: return __syscall_sys_getrlimit();
	case 98: return __syscall_sys_getrusage();
	case 99: return __syscall_sys_sysinfo();
	}
}
