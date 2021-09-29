import clang.cindex as cli

from iegen.common.error import Error

NEW_LINE = '\n'


class Validator:
    """
    Class to validate some constraints on variables
    """

    @staticmethod
    def shared_ref_set(type_ctx):
        """Check whether shared_ref variable is set"""
        if not type_ctx.root.vars.shared_ref:
            Error.critical("Root must have an attribute \"shared_ref: True\"",
                           type_ctx.node.file_name,
                           type_ctx.node.line_number)

    @staticmethod
    def shared_ref_unset(type_ctx):
        """Check whether shared_ref variable is false"""
        if type_ctx.root.vars.shared_ref:
            Error.critical("Root has an invalid attribute \"shared_ref: True\"",
                           type_ctx.node.file_name,
                           type_ctx.node.line_number)

    @staticmethod
    def validate_single_root(cursor):
        """Validate that the cursor has only a single base root"""
        roots = _get_roots(cursor)
        if len(roots) > 1 and not all((roots[0].type == root.type for root in roots)):
            raise TypeError(
                f'Type {cursor.spelling} has more than one root - '
                f'[{", ".join(map(lambda root: root.spelling, roots))}].')

    @staticmethod
    def validate_ancestors(ancestors):
        """Ensure that all ancestors has the same value for shared_ref variable"""
        if ancestors and not all(item.vars.shared_ref == ancestors[0].vars.shared_ref for item in ancestors[1:]):
            raise TypeError('All ancestors must have the same value for shared_ref.')

    @staticmethod
    def validate_bases(class_name, base_types_converters):
        """Ensure the class has only one non abstract base"""
        non_abstract_bases = 0
        for base_type in base_types_converters:
            if not base_type.ctx.vars.action == 'gen_interface':
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


class Exceptions:
    """
    Helper class for exceptions
    """

    @staticmethod
    def can_throw(throws):
        """Check whether the node has list of throwable exceptions"""
        return "no_throw" not in throws

    @staticmethod
    def is_std_custom_exc(cursor):
        """Check whether the given class is derived from C++ std exceptions"""
        std_exc_list = (
            "std::exception", "std::runtime_error", "std::logic_error", "std::bad_alloc",
            "std::bad_cast", "std::bad_typeid", "std::bad_exception", "std::overflow_error",
            "std::range_error", "std::underflow_error", "std::invalid_argument", "std::length_error",
            "std::out_of_range", "std::domain_error"
        )

        for base in list(cursor.get_children()):
            if base.kind == cli.CursorKind.CXX_BASE_SPECIFIER and base.spelling in std_exc_list:
                return True
        return False


def make_doxygen_comment(pure_comment):
    if isinstance(pure_comment, str):
        pure_comment = pure_comment.split(NEW_LINE)
    nl = f'{NEW_LINE} * '
    if not pure_comment or all((not line or line.isspace() for line in pure_comment)):
        return ''
    start = '' if not pure_comment[0] or pure_comment[0].isspace() else nl
    return f"""/**{start}{nl.join(pure_comment)}
*/"""
