import json
import os

syscalls_json = json.load(open(os.path.join(os.path.dirname(__file__), 'syscalls-x86_64.json')))
syscalls = [None] * max(s[0] + 1 for s in syscalls_json)
for id, name, signature_params, rax, rdi, rsi, rdx, r10, r8, r9, file, line in syscalls_json:
    name = name.removeprefix('sys_')
    if not name:
        continue
    signature = f'{name}{signature_params}'
    args = [a['type'] for a in [rdi, rsi, rdx, r10, r8, r9] if a]
    assert not rax or int(rax, 16) == id
    assert ', '.join(args) == signature_params.strip('()').strip()
    syscalls[id] = (name, args)

for s in syscalls:
    print(f'{s},')