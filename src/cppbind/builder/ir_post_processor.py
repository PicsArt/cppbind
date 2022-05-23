# Copyright (c) 2022 PicsArt, Inc.
# All rights reserved. Use of this source code is governed by a
# MIT-style license that can be found in the LICENSE file.

"""
Module is intended to support modifications/augmentations to IR
"""

from cppbind.ir.ast import CXXNode, Node


class IRPostProcessor:
    """Class intended to do manipulations with IR"""

    def process_ir(self, ir):
        """Public method to do manipulations with ir"""
        self.__register_direct_descendants(ir)

        # return modified IR, since not always the changes can be done in-place
        return ir

    def __register_direct_descendants(self, ir):
        """Private method to register each node to its bases in IR"""

        for node in ir._get_all_nodes():
            if isinstance(node, CXXNode) and node.is_class_or_struct and node.api != Node.API_NONE:
                for base_node in node.base_type_specifier_nodes:
                    base_node.direct_descendants.add(node)
