import json

syscalls = json.load(open('syscalls-x86_64.json'))
dispatch_table = []
#REGS = ['rax', 'rdi', 'rsi', 'rdx', 'r10', 'r8', 'r9']
REGS = ['rax', 'rdi', 'rsi', 'rdx']
REGS_ASM_CONSTRAINTS = ['a', 'D', 'S', 'd']
for id, name, signature, rax, rdi, rsi, rdx, r10, r8, r9, file, line in syscalls[:100]:
	params = [
		(name, r['type'])
		for r, name in zip([{'type': 'id'}, rdi, rsi, rdx, r10, r8, r9], REGS)
		if r
	]
	fn_name = f'__syscall_{name}'
	dispatch_table.append((id, fn_name))
	nl = '\n'
	tab = '\t'
	"""print(f'''
static inline void {fn_name} {{
	{(nl+tab).join(f'register u8 {name} __asm__ ("{name}") = {name.upper()};' for name, t in params)}
	__asm__ __volatile__("syscall");
	RAX = rax;
}}''')"""
	print(f'static inline void {fn_name}() {{')
	'''for name, t in params:
		expression = name.upper()
		if '*' in t:
			expression = f'RAM_ADDR({expression})'
		print(f'\tregister unsigned long long {name} __asm__ ("{name}") = (unsigned long long){expression};')
	print('\t__asm__ __volatile__("syscall");')'''
	for name, t in params:
		expression = name.upper()
		if '*' in t:
			expression = f'(unsigned long long)RAM_ADDR({expression})'
		print(f'\tunsigned long long {name} = {expression};')
	print('\t__asm__ __volatile__(')
	print('\t\t"syscall"')
	print('\t\t: "+a" (rax)')
	print('\t\t: ' + ', '.join(f'"{c}" ({r})' for (r, _), c in zip(params, REGS_ASM_CONSTRAINTS) if r != 'rax'))
	print('\t\t: "rcx", "r11", "memory"')
	print('\t);')
	print('\tRAX = rax;')
	print('}')

print('static inline void __dispatch_syscall(int id) {')
print('\tswitch (id) {')
for id, fn_name in dispatch_table:
	print(f'\tcase {id}: return {fn_name}();')
print('\t}')
print('}')
