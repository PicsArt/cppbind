# Copyright (c) 2022 PicsArt, Inc.
# All rights reserved. Use of this source code is governed by a
# MIT-style license that can be found in the LICENSE file.

import copy
import types

import clang.cindex as cli
import cppbind
import cppbind.converter
import cppbind.utils.clang as cutil
from cppbind.common.cxx_type import CXXType
from cppbind.common.error import Error
from cppbind.common.snippets_engine import (
    JINJA_UNIQUE_MARKER,
    SnippetsEngine,
)
from cppbind.common.type_info import create_type_info
from cppbind.utils import DefaultValueKind, get_language_helper_module

SNIPPETS_ENGINE = None
GLOBAL_VARIABLES = {}
# variables below should be set after loading this module by calling set_language function
LANGUAGE = None
LANGUAGE_HELPER_MODULE = None


def set_language(language):
    global LANGUAGE
    LANGUAGE = language
    global LANGUAGE_HELPER_MODULE
    LANGUAGE_HELPER_MODULE = get_language_helper_module(language)


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
        helper = LANGUAGE_HELPER_MODULE
        marker = JINJA_UNIQUE_MARKER
        banner_logo = cppbind.BANNER_LOGO
        new_line = cppbind.converter.NEW_LINE

        vars = ctx.vars

        def make_type_converter(type_name, template_choice=None):
            return SNIPPETS_ENGINE.build_type_converter_with_typename(type_name, template_choice)

        def get_type_info(type_name, template_choice=None):
            converter = SNIPPETS_ENGINE.build_type_converter_with_typename(type_name, template_choice)
            if converter:
                return getattr(converter, LANGUAGE)._type_info
            Error.critical(f'No type info found for: {type_name} with template choice - {template_choice}')

        return locals()

    context = make()
    context.update(GLOBAL_VARIABLES)
    return context


def make_package_context(ctx):
    context = make_def_context(ctx)
    return context


def make_func_context(ctx):
    def make():
        args = [
            types.SimpleNamespace(
                converter=SNIPPETS_ENGINE.build_type_converter(CXXType(type_=arg.type,
                                                                       template_choice=ctx.template_choice)),
                type_info=create_type_info(ctx.runner, CXXType(type_=arg.type,
                                                               template_choice=ctx.template_choice)),
                name=arg.name,
                default=arg.default.value,
                is_enum=arg.type.get_canonical().kind == cli.TypeKind.ENUM,
                is_bool=arg.type.get_canonical().kind == cli.TypeKind.BOOL,
                is_long=arg.type.get_canonical().kind == cli.TypeKind.LONG,
                is_float=arg.type.get_canonical().kind in (cli.TypeKind.FLOAT, cli.TypeKind.FLOAT128),
                is_char=arg.type.get_canonical().kind in (cli.TypeKind.CHAR_S, cli.TypeKind.CHAR_U),
                is_uchar=arg.type.get_canonical().kind == cli.TypeKind.UCHAR,
                default_is_literal=arg.default.kind == DefaultValueKind.LITERAL,
                default_is_nullptr=arg.default.kind == DefaultValueKind.NULL_PTR,
            ) for arg in ctx.args
        ]

        if hasattr(ctx, 'result_type'):
            _cxx_type = CXXType(type_=ctx.result_type,
                                template_choice=ctx.template_choice)
            rconverter = SNIPPETS_ENGINE.build_type_converter(_cxx_type)
            return_type_info = create_type_info(ctx.runner, _cxx_type)

        # global functions do not have owner_class
        owner_class = types.SimpleNamespace(
            **make_class_context(ctx.parent_context)) if ctx.parent_context and ctx.parent_context.vars.action in (
            'gen_class', 'gen_interface') else None

        overloading_postfix = ctx.overloading_postfix
        # capturing template related properties since we use single context with different template choice
        template_choice = ctx.template_choice
        template_args_postfixes = ctx.template_args_postfixes
        template_type_converters = [SNIPPETS_ENGINE.build_type_converter(CXXType(type_=template_arg_type)) for
                                    template_arg_type in template_choice.values()] if template_choice else []

        cxx = types.SimpleNamespace(
            name=ctx.cursor.spelling,
            displayname=ctx.cursor.displayname,
            source_file_name=ctx.node.file_name,
            is_abstract=ctx.cursor.is_abstract_record(),
            is_open=not cutil.is_final_cursor(ctx.cursor),
            is_public=ctx.cursor.access_specifier == cli.AccessSpecifier.PUBLIC,
            is_protected=ctx.cursor.access_specifier == cli.AccessSpecifier.PROTECTED,
            is_private=ctx.cursor.access_specifier == cli.AccessSpecifier.PRIVATE,
            is_const=ctx.cursor.is_const_method(),
            kind_name=ctx.kind_name,
            access_specifier=ctx.cursor.access_specifier.name.lower(),
            is_template=ctx.node.is_function_template,
            is_overloaded=cutil.is_overloaded(ctx.cursor),
            is_static=bool(ctx.cursor.is_static_method()),
            namespace=ctx.namespace,
            # for template methods
            is_override=False
        )

        if ctx.cursor.kind == cli.CursorKind.CXX_METHOD:
            # at least one of the overridden cursors should have an api
            cxx.is_override = bool(ctx.overridden_contexts)

            is_interface_override = cxx.is_override and all(
                [c.parent_context.vars.action == 'gen_interface' for c in ctx.overridden_contexts])
            cxx.is_virtual = bool(ctx.cursor.is_virtual_method())

        return locals()

    context = make_def_context(ctx)
    context.update(make())
    return context


def make_enum_context(ctx):
    def make():
        # helper variables
        enum_cases = ctx.enum_values
        cxx = types.SimpleNamespace(name=ctx.cursor.spelling,
                                    type_name=ctx.cxx_type_name,
                                    source_file_name=ctx.node.file_name,
                                    namespace=ctx.namespace,
                                    kind_name=ctx.kind_name)
        return locals()

    context = make_def_context(ctx)
    context.update(make())
    return context


def make_class_context(ctx):
    def _make(ctx):
        def make():
            # for cases when type kind is invalid clang type does not give enough information
            # for such cases we use string type name
            _cxx_type = CXXType(type_=ctx.cxx_type_name,
                                template_choice=ctx.template_choice)
            _type_info = create_type_info(ctx.runner, _cxx_type)

            converter = SNIPPETS_ENGINE.build_type_converter(CXXType(type_=ctx.cxx_type_name,
                                                                     template_choice=ctx.template_choice))

            base_types_converters = [SNIPPETS_ENGINE.build_type_converter(CXXType(base_type, ctx.template_choice))
                                     for base_type in ctx.base_types]

            # nested types have their owner_class
            owner_class = types.SimpleNamespace(
                **make_class_context(ctx.parent_context)) if ctx.parent_context else None

            cxx = _type_info.cxx
            base_types_infos = _type_info.base_types_infos
            arg_types_infos = _type_info.arg_types_infos
            type_info = _type_info

            descendants = _type_info.descendants

            return locals()

        context = make_def_context(ctx)
        context.update(make())
        return context

    context = _make(ctx)
    ancestors = [types.SimpleNamespace(**_make(ancestor)) for ancestor in ctx.ancestors]
    root = types.SimpleNamespace(**_make(ctx.root))
    context.update(dict(ancestors=ancestors, root=root))
    return context


def make_constructor_context(ctx):
    def make():
        # helper variables

        return locals()

    context = make_func_context(ctx)
    context.update(make())
    return context


def make_getter_context(ctx):
    def make():
        # helper variables
        if ctx.setter:
            # setter is generated alongside with getter, setting template choice from getter context
            setter_ctx = ctx.setter
            setter_ctx.set_template_info(ctx.template_info)
            setter = make_func_context(setter_ctx)

        return locals()

    context = make_func_context(ctx)
    context.update(make())
    return context


def make_member_context(ctx):
    def make():
        # helper variables
        _cxx_type = CXXType(type_=ctx.cursor.type,
                            template_choice=ctx.template_choice)
        return_type_info = create_type_info(ctx.runner, _cxx_type)
        rconverter = SNIPPETS_ENGINE.build_type_converter(_cxx_type)

        owner_class = types.SimpleNamespace(
            **make_class_context(ctx.parent_context)) if ctx.parent_context and ctx.parent_context.vars.action in (
            'gen_class', 'gen_interface') else None

        cxx = types.SimpleNamespace(name=ctx.cursor.spelling,
                                    displayname=ctx.cursor.displayname,
                                    source_file_name=ctx.node.file_name,
                                    kind_name=ctx.kind_name,
                                    is_public=ctx.cursor.access_specifier == cli.AccessSpecifier.PUBLIC,
                                    is_template=ctx.node.is_template)

        return locals()

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


def gen_package(ctx, builder):
    context = make_package_context(ctx)
    preprocess_entry(context, builder, 'package')


def gen_enum(ctx, builder):
    context = make_enum_context(ctx)
    preprocess_entry(context, builder, 'enum')


def gen_class(ctx, builder):
    context = make_class_context(ctx)
    preprocess_entry(context, builder, 'class')


def gen_interface(ctx, builder):
    context = make_class_context(ctx)
    preprocess_entry(context, builder, 'interface')


def gen_constructor(ctx, builder):
    context = make_constructor_context(ctx)
    preprocess_entry(context, builder, 'constructor')


def gen_method(ctx, builder):
    context = make_func_context(ctx)
    preprocess_entry(context, builder, 'method')


def gen_function(ctx, builder):
    context = make_func_context(ctx)
    preprocess_entry(context, builder, 'function')


def gen_getter(ctx, builder):
    context = make_getter_context(ctx)
    preprocess_entry(context, builder, 'getter')


def gen_property_getter(ctx, builder):
    context = make_member_context(ctx)
    preprocess_entry(context, builder, 'property_getter')


def gen_property_setter(ctx, builder):
    gen_property_getter(ctx, builder)


def gen_setter(ctx, builder):
    return
