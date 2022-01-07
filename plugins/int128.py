from lifters.core_helper import CoreHelper, VarKind
from lifters.core_lifter import CoreLifter


class CoreHelper128(CoreHelper):
    available_types = CoreHelper.available_types | {
        (VarKind.SIGNED, 16): 'i128',
        (VarKind.UNSIGNED, 16): 'u128',
    }

class CoreLifter128(CoreLifter):
    def generate_generic_typedefs(self) -> str:
        return '\n'.join((
            super().generate_generic_typedefs(),
            'typedef __int128 i128;',
            'typedef unsigned __int128 u128;',
        ))
