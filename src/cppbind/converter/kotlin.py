# Copyright (c) 2022 PicsArt, Inc.
# All rights reserved. Use of this source code is governed by a
# MIT-style license that can be found in the LICENSE file.

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
    '%': 'rem',
    '!': 'not',
    '()': 'invoke',
    '[]': 'get',
}

JNI_TYPE_SIGNATURE = dict(
    jboolean='Z',
    jbyte='B',
    jchar='C',
    jshort='S',
    jint='I',
    jlong='J',
    jfloat='F',
    jdouble='D',
    jobjectid='J'
)


def get_operator_name(spelling):
    operator = spelling.replace('operator', '').strip()
    return OPERATOR_MAPPING.get(operator, spelling)


def get_jni_type_signature(native_type):
    return JNI_TYPE_SIGNATURE.get(native_type)


def arg_str(type_name, name, default=None, **kwargs):
    arg_str = name + ': ' + type_name
    if default:
        val = default
        if val in ['nullptr', 'NULL']:
            arg_str += '? = null'
        else:
            arg_str += " = " + val
    return arg_str


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
    # consider nested types as well
    class_name = '_00024'.join([fix_name(t) for t in class_name.split('.')])
    method_name = fix_name(method_name)
    if args_type_name is None or any((a not in args_type_signature for a in args_type_name)):
        return f'Java_{package_name}_{class_name}_{method_name}'
    return f'Java_{package_name}_{class_name}_{method_name}__\
{"".join([args_type_signature[arg] for arg in args_type_name])}'
