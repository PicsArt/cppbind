"""
Module is intended to support modifications/augmentations to IR
"""

import clang.cindex as cli


class IRPostProcessor:
    """Class intended to do manipulations with IR"""

    def __init__(self, ir, cxx_node_map):
        self.__ir = ir
        self.__cxx_node_map = cxx_node_map

    def process_ir(self):
        """Public method to do manipulations with ir"""
        self.__register_direct_descendants()

        # return modified IR, since not always the changes can be done in-place
        return self.__ir

    def __register_direct_descendants(self):
        """Private method to register each node to its bases in IR"""

        for node in self.__cxx_node_map.values():
            if node.is_class_or_struct:
                for base_specifier in node.clang_cursor.get_children():
                    if base_specifier.kind == cli.CursorKind.CXX_BASE_SPECIFIER:
                        base_node = self.__cxx_node_map.get(base_specifier.type.spelling)
                        if base_node and not node in base_node.direct_descendants:
                            base_node.direct_descendants.append(node)
