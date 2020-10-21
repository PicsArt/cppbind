"""
Helper codes for kotlin conversion
"""
from iegnen.common.snippets_engine import SnippetsEngine

OBJECT_CXX_ID_TYPE = 'jobjectid'
OBJECT_CXX_TYPE = 'jobject'

CXX_INCLUDE_NAMES = ["jni.h"]


CXX_HELPERS = ""

SNIPPETS_ENGINE = None


def get_includes():
    return '\n'.join([f'#include "{n}"' for n in CXX_INCLUDE_NAMES])


def load_snipppets_engine(path, main_target):
    global SNIPPETS_ENGINE
    SNIPPETS_ENGINE = SnippetsEngine(path, main_target)
    SNIPPETS_ENGINE.load()


def indent(s, numSpaces):
    s = s.splitlines()
    s = [(numSpaces * ' ') + line for line in s]
    return '\n'.join(s)


def kt_arg_str(type_name, name, default=None, **kwargs):
    arg_str = name + ': ' + type_name
    if default:
        val = default
        if val in ['nullptr', 'NULL']:
            arg_str += '? = null'
        else:
            arg_str += " = " + val
    return arg_str


def kt_jni_arg_str(type_name, name, **kwargs):
    arg_str = name + ': ' + type_name
    return arg_str


def cxx_jni_arg_str(type_name, name, **kwargs):
    arg_str = type_name + ' ' + name
    return arg_str


def format_args_str(args):
    from iegnen.builder.out_builder import Scope
    if args:
        args = '\n' + str(Scope(*args, tab=1, parts_spliter=',\n')) + '\n'
    else:
        args = ''
    return args


def jni_func_name(ctx):
    return f'j{ctx.name.capitalize()}'


def build_type_converter(ctx, clang_type):
    return SNIPPETS_ENGINE.build_type_converter(ctx, clang_type)
