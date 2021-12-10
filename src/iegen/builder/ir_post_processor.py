"""
Module is intended to support modifications/augmentations to IR
"""

import clang.cindex as cli

from iegen.ir.ast import CXXNode


class IRPostProcessor:
    """Class intended to do manipulations with IR"""

    @classmethod
    def process_ir(cls, ir):
        """Public method to do manipulations with ir"""
        cls.__register_direct_descendants(ir)

        # return modified IR, since not always the changes can be done in-place
        return ir

    @staticmethod
    def __register_direct_descendants(ir):
        """Private method to register each node to its bases in IR"""

        node_map = ir.get_node_map()

        for node in node_map.values():
            if isinstance(node, CXXNode) and node.is_class_or_struct:
                for base_specifier in node.clang_cursor.get_children():
                    if base_specifier.kind == cli.CursorKind.CXX_BASE_SPECIFIER:
                        base_node = node_map.get(base_specifier.type.spelling)
                        if base_node:
                            base_node.direct_descendants.append(node)
