from . import kotlin as kotlin
from . import python as python

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

class Exceptions:
    @staticmethod
    def can_throw(throws):
        return "no_throw" not in throws

    @staticmethod
    def get_std_exc_tree():
        return [
            ("std::exception", ""),
            ("std::runtime_error", "std::exception"),
            ("std::logic_error", "std::exception"),
            ("std::bad_alloc", "std::exception"),
            ("std::bad_cast", "std::exception"),
            ("std::bad_typeid", "std::exception"),
            ("std::bad_exception", "std::exception"),
            ("std::overflow_error", "std::runtime_error"),
            ("std::range_error", "std::runtime_error"),
            ("std::underflow_error", "std::runtime_error"),
            ("std::invalid_argument", "std::logic_error"),
            ("std::length_error", "std::logic_error"),
            ("std::out_of_range", "std::logic_error"),
            ("std::domain_error", "std::logic_error")
        ]

    @staticmethod
    def is_std_custom_exc(ctx):
        std_exc_list = [row[0] for row in Exceptions.get_std_exc_tree()]
        for cursor in list(ctx.cursor.get_children()):
            if cursor.kind == cli.CursorKind.CXX_BASE_SPECIFIER and cursor.spelling in std_exc_list:
                return True
        return False

    @staticmethod
    def has_exc_base(ctx):
        return any(base.is_exception for base in ctx.ancestors)

    @staticmethod
    def get_exc_name(name):
        if not name.startswith("std::"):
            return name.split("::")[-1]

        name = name.replace("::", "_")
        components = name.split("_")
        return ''.join(x.title() for x in components)

    @staticmethod
    def is_std_exc(name):
        for exc in Exceptions.get_std_exc_tree():
            if name == exc[0]:
                return True
        return False

