from lifters.core_lifter import CoreLifter


class CoreLifterSyscallLinux64(CoreLifter):
    def setup(self):
        super().setup()
        self.h_body.append('#include "syscalls.h"')
        self.functions.append('#define CALLOTHER_syscall() __dispatch_syscall(RAX)')