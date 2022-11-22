# Copyright (c) 2022 PicsArt, Inc.
# All rights reserved. Use of this source code is governed by a
# MIT-style license that can be found in the LICENSE file.

import copy
import types

import cppbind
import cppbind.converter
from cppbind.common.snippets_engine import (
    JINJA_UNIQUE_MARKER,
    SnippetsEngine,
)
from cppbind.common.type_info import create_type_info
from cppbind.cxx_exposed import (
    CXXClassExposedElement,
    CXXEnumExposedElement,
    CXXExposedType,
    CXXFunctionExposedElement,
    CXXMemberExposedElement
)
from cppbind.ir.ast import DIR_KIND_NAME, FILE_KIND_NAME
from cppbind.utils import get_public_attributes


SNIPPETS_ENGINE = None
GLOBAL_VARIABLES = {}
# variables below should be set after loading this module by calling set_language function
LANGUAGE = None


def set_language(language):
    global LANGUAGE
    LANGUAGE = language


def load_snippets_engine(runner, ctx_desc, platform, language):
    global SNIPPETS_ENGINE
    SNIPPETS_ENGINE = SnippetsEngine(runner, ctx_desc, platform, language)
    SNIPPETS_ENGINE.load()


def gen_init(ctx, ctx_desc, platform, language, *args, **kwargs):
    global SNIPPETS_ENGINE, GLOBAL_VARIABLES
    # load snippets

    load_snippets_engine(ctx.runner, ctx_desc, platform, language)

    GLOBAL_VARIABLES = SNIPPETS_ENGINE.do_actions({'vars': ctx.vars})


def make_def_context(ctx):
    def make():
        # helper variables
        banner_logo = cppbind.BANNER_LOGO
        new_line = cppbind.converter.NEW_LINE

        vars = ctx.vars

        return locals()

    context = make()
    context.update(GLOBAL_VARIABLES)
    return context


def make_dir_context(ctx):
    return make_def_context(ctx)


def make_file_context(ctx):
    return make_def_context(ctx)


def make_func_context(ctx):
    def make():
        overloading_index = ctx.node.overloading_index
        # capturing template related properties since we use single context with different template choice
        template_args_postfixes = ctx.template_args_postfixes

        cxx = CXXFunctionExposedElement(ctx.node.cxx_element, ctx.template_choice)

        return get_public_attributes(locals())

    context = make_def_context(ctx)
    context.update(make())
    return context


def make_method_context(ctx):
    def make():
        if ctx.setter:
            # setter is generated alongside with getter, setting template choice from getter context
            _setter_ctx = ctx.setter
            _setter_ctx.set_template_info(ctx.template_info)
            setter = make_method_context(_setter_ctx)

        return get_public_attributes(locals())

    context = make_func_context(ctx)
    context.update(make())
    return context


def make_constructor_context(ctx):
    return make_func_context(ctx)


def make_enum_context(ctx):
    def make():
        # helper variables
        cxx = CXXEnumExposedElement(ctx.node.cxx_element)

        return locals()

    context = make_def_context(ctx)
    context.update(make())
    return context


def make_class_context(ctx):
    def _make(ctx):
        def make():
            # for cases when type kind is invalid clang type does not give enough information
            # for such cases we use string type name
            _cxx_exposed_type = CXXExposedType(cxx_type=ctx.cxx_type_name,
                                               template_choice=ctx.template_choice,
                                               cxx_element=ctx.node.cxx_element)
            _type_info = create_type_info(ctx.runner, _cxx_exposed_type)

            cxx = CXXClassExposedElement(ctx.node.cxx_element, template_choice=ctx.template_choice)

            descendants = _type_info.descendants

            return get_public_attributes(locals())

        context = make_def_context(ctx)
        context.update(make())
        return context

    context = _make(ctx)
    return context


def make_member_context(ctx):
    def make():
        cxx = CXXMemberExposedElement(ctx.node.cxx_element, template_choice=ctx.template_choice)

        return get_public_attributes(locals())

    context = make_def_context(ctx)
    context.update(make())
    return context


def preprocess_scope(context, scope, info):
    context_scope = copy.copy(context)
    for sname in info.scopes:
        s = scope.create_scope(sname)
        context_scope[sname] = s
    if info.snippet_tmpl:
        scope.add(info.make_snippet(context_scope))
    if info.unique_snippet_tmpl:
        scope.add_unique(*str(info.unique_make_snippet(context_scope)).split(JINJA_UNIQUE_MARKER))


def preprocess_entry(context, builder, code_name):
    code_info = None
    if 'name' in context:
        code_info = SNIPPETS_ENGINE.get_code_info(f"{code_name}_{context['name']}")

    code_info = code_info or SNIPPETS_ENGINE.get_code_info(code_name)
    # continue processing if not an empty rule
    if code_info:
        for fs, info in code_info.items():
            fscope_name, scope_name = fs
            file_scope = get_file(context, builder, fscope_name)
            parent_scope = file_scope[scope_name]
            if parent_scope is not None:
                preprocess_scope(context, parent_scope, info)


def get_file(context, builder, fscope_name):
    file_info = SNIPPETS_ENGINE.get_file_info(fscope_name)
    file_name = file_info.get_file_name(context)

    return builder.get_file(file_name, init_func=lambda s: preprocess_scope(context, s, file_info))


def gen_entity(ctx, builder, api, node_kind_name):
    """A function for calling the right preprocess function"""

    # remove 'gen_'
    api_instruction_name = api[4:]

    if node_kind_name == DIR_KIND_NAME:
        context = make_dir_context(ctx)
    elif node_kind_name == FILE_KIND_NAME:
        context = make_file_context(ctx)
    elif node_kind_name in (
        'class',
        'class_template_partial_specialization',
        'class_template',
        'struct',
        'struct_template'
    ):
        context = make_class_context(ctx)
    elif node_kind_name == 'enum':
        context = make_enum_context(ctx)
    elif node_kind_name in (
        'function',
        'function_template'
    ):
        context = make_func_context(ctx)
    elif node_kind_name in (
        'method',
        'method_template'
    ):
        context = make_method_context(ctx)
    elif node_kind_name in (
        'constructor',
        'constructor_template',
    ):
        context = make_constructor_context(ctx)
    elif node_kind_name == 'field':
        context = make_member_context(ctx)
    else:
        context = make_def_context(ctx)

    preprocess_entry(context, builder, api_instruction_name)
