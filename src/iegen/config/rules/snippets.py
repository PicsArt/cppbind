import copy
import importlib
import logging
import os
import types

import clang.cindex as cli
import iegen
import iegen.converter
import iegen.utils.clang as cutil
from iegen.common.cxx_type import CXXType
from iegen.common.error import Error
from iegen.common.snippets_engine import (
    JINJA_UNIQUE_MARKER,
    SnippetsEngine,
)
from iegen.common.type_info import create_type_info
from iegen.utils import DefaultValueKind

SNIPPETS_ENGINE = None
GLOBAL_VARIABLES = {}
# variables below should be set after loading this module by calling set_language function
LANGUAGE = None
LANGUAGE_HELPER_MODULE = None


def set_language(language):
    global LANGUAGE
    LANGUAGE = language
    global LANGUAGE_HELPER_MODULE
    try:
        LANGUAGE_HELPER_MODULE = importlib.import_module(f'iegen.converter.{language}')
    except ModuleNotFoundError:
        logging.info(f"Helper module is not found for '{language}' language")


def load_snippets_engine(ctx_desc, platform, language):
    global SNIPPETS_ENGINE
    SNIPPETS_ENGINE = SnippetsEngine(ctx_desc, platform, language)
    SNIPPETS_ENGINE.load()


def gen_init(ctx, ctx_desc, platform, language, *args, **kwargs):
    global SNIPPETS_ENGINE, GLOBAL_VARIABLES
    # load snippets

    load_snippets_engine(ctx_desc, platform, language)

    GLOBAL_VARIABLES = SNIPPETS_ENGINE.do_actions({'vars': ctx.vars})


def make_def_context(ctx):
    def make():
        # helper variables
        pat_sep = os.sep
        path = os.path
        helper = LANGUAGE_HELPER_MODULE
        marker = JINJA_UNIQUE_MARKER
        banner_logo = iegen.BANNER_LOGO
        new_line = iegen.converter.NEW_LINE

        vars = ctx.vars

        def make_type_converter(type_name, template_choice=None):
            return SNIPPETS_ENGINE.build_type_converter(ctx, CXXType(type_name,
                                                                     template_choice))

        def get_type_info(type_name, template_choice=None):
            cxx_type = CXXType(type_name,
                               template_choice)
            converter = SNIPPETS_ENGINE.build_type_converter(ctx, cxx_type)
            if converter:
                return getattr(converter, LANGUAGE)._type_info
            Error.critical(f'No type info found for: {cxx_type.type_name}')

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
                converter=SNIPPETS_ENGINE.build_type_converter(ctx,
                                                               CXXType(type_=arg.type,
                                                                       template_choice=ctx.template_choice)),
                type_info=create_type_info(ctx, CXXType(type_=arg.type,
                                                        template_choice=ctx.template_choice)),
                name=arg.name,
                default=arg.default.value,
                cursor=arg.cursor,
                type=arg.type,
                is_enum=arg.type.kind == cli.TypeKind.ENUM,
                is_bool=arg.type.kind == cli.TypeKind.BOOL,
                is_long=arg.type.kind == cli.TypeKind.LONG,
                is_float=arg.type.kind in (cli.TypeKind.FLOAT, cli.TypeKind.FLOAT128),
                is_literal=arg.default.kind == DefaultValueKind.LITERAL,
                is_null_ptr=arg.default.kind == DefaultValueKind.NULL_PTR,
            ) for arg in ctx.args
        ]

        if hasattr(ctx, 'result_type'):
            _cxx_type = CXXType(type_=ctx.result_type,
                                template_choice=ctx.template_choice)
            rconverter = SNIPPETS_ENGINE.build_type_converter(ctx, _cxx_type)
            return_type_info = create_type_info(ctx, _cxx_type)

        owner_class = types.SimpleNamespace(**make_class_context(ctx.parent_context))

        overloading_prefix = ctx.overloading_prefix
        # capturing template related properties since we use single context with different template choice
        template_choice = ctx.template_choice
        template_names = ctx.template_names
        template_type_converters = [SNIPPETS_ENGINE.build_type_converter(ctx, CXXType(type_=template_arg_type)) for
                                    template_arg_type in template_choice.values()] if template_choice else []

        cxx = types.SimpleNamespace(
            name=ctx.cursor.spelling,
            displayname=ctx.cursor.displayname,
            is_abstract=ctx.cursor.is_abstract_record(),
            is_open=not cutil.is_final_cursor(ctx.cursor),
            is_public=ctx.cursor.access_specifier == cli.AccessSpecifier.PUBLIC,
            is_protected=ctx.cursor.access_specifier == cli.AccessSpecifier.PROTECTED,
            is_private=ctx.cursor.access_specifier == cli.AccessSpecifier.PRIVATE,
            is_const=ctx.cursor.is_const_method(),
            kind_name=ctx.kind_name,
            access_specifier=ctx.cursor.access_specifier.name.lower(),
            is_template=ctx.node.is_function_template,
            is_overloaded=cutil.is_overloaded(ctx.cursor)
        )
        if ctx.cursor.kind in [cli.CursorKind.CXX_METHOD, cli.CursorKind.FUNCTION_TEMPLATE]:
            _overridden_cursors = cutil.get_all_overridden_cursors(ctx.cursor)
            _override_contexts = []
            for cursor in _overridden_cursors:
                overridden_ctx = ctx.find_by_type(cutil.get_full_displayname(cursor))
                if overridden_ctx:
                    _override_contexts.append(overridden_ctx)

            # at least one of the overridden cursors should have an api
            cxx.is_override = bool(_override_contexts)

            is_interface_override = cxx.is_override and all(
                [c.parent_context.vars.action == 'gen_interface' for c in _override_contexts])
            cxx.is_static = bool(ctx.cursor.is_static_method())
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
            _type_info = create_type_info(ctx, _cxx_type)

            converter = SNIPPETS_ENGINE.build_type_converter(ctx, CXXType(type_=ctx.cxx_type_name,
                                                                          template_choice=ctx.template_choice))

            base_types_converters = [SNIPPETS_ENGINE.build_type_converter(ctx, CXXType(base_type, ctx.template_choice))
                                     for base_type in ctx.base_types]

            cxx = _type_info.cxx
            base_types_infos = _type_info.base_types_infos
            root_types_infos = _type_info.root_types_infos

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
            setter_ctx.set_template_ctx(ctx.template_ctx)
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
        return_type_info = create_type_info(ctx, _cxx_type)
        rconverter = SNIPPETS_ENGINE.build_type_converter(ctx, _cxx_type)

        owner_class = types.SimpleNamespace(**make_class_context(ctx.parent_context))

        cxx = types.SimpleNamespace(name=ctx.cursor.spelling,
                                    displayname=ctx.cursor.displayname,
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
