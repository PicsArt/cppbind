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


def get_jni_func_name(package_name, class_name, method_name, args_type_name=None):
    def fix_name(name):
        for s, r in [('_', '_1'), ('.', '_'), (';', '_2'), ('[', '_3')]:
            name = name.replace(s, r)
        return name

    args_type_signature = dict(
        jboolean='Z',
        jbyte='B',
        jchar='C',
        jshort='S',
        jint='I',
        jlong='J',
        jfloat='F',
        jdouble='D',
        jobject='Ljava_lang_Object_2',
        jstring='Ljava_lang_String_2',
    )
    package_name = fix_name(package_name)
    class_name = fix_name(class_name)
    method_name = fix_name(method_name)
    if args_type_name is None or any([a not in args_type_signature for a in args_type_name]):
        return f'Java_{package_name}_{class_name}_{method_name}'
    else:
        return f'Java_{package_name}_{class_name}_{method_name}__\
{"".join([args_type_signature[arg] for arg in args_type_name])}'


def build_type_converter(ctx, clang_type):
    return SNIPPETS_ENGINE.build_type_converter(ctx, clang_type)
