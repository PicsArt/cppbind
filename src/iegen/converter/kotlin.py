"""
Helper codes for kotlin conversion
"""
from . import *


OPERATOR_MAPPING = {
    '*': 'times',
    '-': 'minus',
    '+': 'plus',
    '/': 'div',
    '==': 'equals',
    '%': 'mod',
    '&': 'and',
    '!': 'not',
    '()': 'invoke',
    '|': 'or',
    '|=': 'orAssign',
    '^': 'xor',
    '^=': 'xorAssign',
    '~': 'inv',
    '~=': 'invAssign',
    '<<': 'shl',
    '>>': 'shr',
    '[]': 'get',
}


def get_operator_name(spelling):
    operator = spelling.replace('operator', '').strip()
    return OPERATOR_MAPPING.get(operator, spelling)


def arg_str(type_name, name, default=None, **kwargs):
    arg_str = name + ': ' + type_name
    if default:
        val = default
        if val in ['nullptr', 'NULL']:
            arg_str += '? = null'
        else:
            arg_str += " = " + val
    return arg_str


def get_owners_names(owner_class, impl_member=False):
    owners = []
    while owner_class:
        converter = owner_class.converter.kotlin
        action = owner_class.vars.action
        if impl_member:
            # constructors and destructors are moved to implementation classes in case of gen_interface
            owners.append(converter.get_target_type_name(interface_class=action == 'gen_interface'))
        else:
            # methods, getters etc. go to helper class in case if gen_interface
            owners.append(
                converter.target_type_name + 'Helper' if action == 'gen_interface' else converter.target_type_name)
        owner_class = owner_class.owner_class
    return owners


def get_jni_func_name(package_name, owners_names, method_name, args_type_name=None):
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
    # consider nested types as well
    class_name = '_00024'.join([fix_name(owner) for owner in reversed(owners_names)])
    method_name = fix_name(method_name)
    if args_type_name is None or any((a not in args_type_signature for a in args_type_name)):
        return f'Java_{package_name}_{class_name}_{method_name}'
    return f'Java_{package_name}_{class_name}_{method_name}__\
{"".join([args_type_signature[arg] for arg in args_type_name])}'
