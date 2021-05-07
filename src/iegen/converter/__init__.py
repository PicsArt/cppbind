import clang.cindex as cli


class Validator:
    @staticmethod
    def shared_ref_set(type_ctx):
        if not type_ctx.root.shared_ref:
            raise Exception("Root must have an attribute \"shared_ref: True\"")

    @staticmethod
    def shared_ref_unset(type_ctx):
        if type_ctx.root.shared_ref:
            raise Exception("Root has an invalid attribute \"shared_ref: True\"")

    @staticmethod
    def validate_single_root(cursor):
        roots = _get_roots(cursor)
        if len(roots) > 1 and not all((roots[0].type == root.type for root in roots)):
            raise TypeError(
                f'Type {cursor.spelling} has more than one root - [{", ".join(map(lambda root: root.spelling, roots))}].')

    @staticmethod
    def validate_ancestors(ancestors):
        if ancestors and not all(item.shared_ref == ancestors[0].shared_ref for item in ancestors[1:]):
            raise TypeError('All ancestors must have the same value for shared_ref.')

    @staticmethod
    def validate_bases(class_name, base_types_converters):
        non_abstract_bases = 0
        for base_type in base_types_converters:
            if not base_type.is_interface:
                non_abstract_bases += 1
        if non_abstract_bases > 1:
            raise TypeError(f'{class_name} has more than 1 non abstract bases.')


def _get_roots(cursor):
    roots = []
    for parent in cursor.get_children():
        if parent.kind == cli.CursorKind.CXX_BASE_SPECIFIER:
            parent_children = []
            for child in parent.get_definition().get_children():
                if child.kind == cli.CursorKind.CXX_BASE_SPECIFIER:
                    parent_children.append(child.get_definition())
            if not parent_children:
                roots.append(parent)
            else:
                roots += _get_roots(parent.get_definition())
    return roots
