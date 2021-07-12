import clang.cindex as cli

NEW_LINE = '\n'


class Validator:
    """
    Class to validate some constraints on variables
    """

    @staticmethod
    def shared_ref_set(type_ctx):
        """Check whether shared_ref variable is set"""
        if not type_ctx.root.shared_ref:
            raise Exception("Root must have an attribute \"shared_ref: True\"")

    @staticmethod
    def shared_ref_unset(type_ctx):
        """Check whether shared_ref variable is false"""
        if type_ctx.root.shared_ref:
            raise Exception("Root has an invalid attribute \"shared_ref: True\"")

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
        if ancestors and not all(item.shared_ref == ancestors[0].shared_ref for item in ancestors[1:]):
            raise TypeError('All ancestors must have the same value for shared_ref.')

    @staticmethod
    def validate_bases(class_name, base_types_converters):
        """Ensure the class has only one non abstract base"""
        non_abstract_bases = 0
        for base_type in base_types_converters:
            if not base_type.ctx.action == 'gen_interface':
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
    def is_std_custom_exc(ctx):
        """Check whether the given class is derived from C++ std exceptions"""
        std_exc_list = (
            "std::exception", "std::runtime_error", "std::logic_error", "std::bad_alloc",
            "std::bad_cast", "std::bad_typeid", "std::bad_exception", "std::overflow_error",
            "std::range_error", "std::underflow_error", "std::invalid_argument", "std::length_error",
            "std::out_of_range", "std::domain_error"
        )

        for cursor in list(ctx.cursor.get_children()):
            if cursor.kind == cli.CursorKind.CXX_BASE_SPECIFIER and cursor.spelling in std_exc_list:
                return True
        return False

    @staticmethod
    def has_exc_base(ctx):
        """Check whether current class has a base class which is exception class"""
        return any(base.is_exception for base in ctx.ancestors)

    @staticmethod
    def get_exc_name(name):
        """Returns mangled name of class to use in target language"""
        if not name.startswith("std::"):
            return name.split("::")[-1]

        name = name.replace("::", "_")
        components = name.split("_")
        return ''.join(x.title() for x in components)


def make_doxygen_comment(pure_comment):
    if isinstance(pure_comment, str):
        pure_comment = pure_comment.split(NEW_LINE)
    nl = f'{NEW_LINE} * '
    if not pure_comment or all((not line or line.isspace() for line in pure_comment)):
        return ''
    start = '' if not pure_comment[0] or pure_comment[0].isspace() else nl
    return f"""/**{start}{nl.join(pure_comment)}
 */"""
