import copy
import importlib
import os
import types

import clang.cindex as cli
import iegen
import iegen.converter
import iegen.utils.clang as cutil
from iegen import find_prj_dir
from iegen.common.error import Error
from iegen.common.snippets_engine import (
    ENUM_INFO_TYPE,
    JINJA_UNIQUE_MARKER,
    OBJECT_INFO_TYPE,
    SnippetsEngine
)

SNIPPETS_ENGINE = None
GLOBAL_VARIABLES = {}
# variables below should be set after loading this module by calling set_language function
LANGUAGE = None
LANGUAGE_HELPER_MODULE = None


def set_language(language):
    global LANGUAGE
    LANGUAGE = language
    global LANGUAGE_HELPER_MODULE
    LANGUAGE_HELPER_MODULE = importlib.import_module(f'iegen.converter.{language}')


def load_snippets_engine(ctx_desc):
    global SNIPPETS_ENGINE
    SNIPPETS_ENGINE = SnippetsEngine(ctx_desc)
    SNIPPETS_ENGINE.load()


def gen_init(ctx, ctx_desc, *args, **kwargs):
    global SNIPPETS_ENGINE, GLOBAL_VARIABLES
    # load snippets

    context = make_root_context(ctx)

    load_snippets_engine(ctx_desc)

    GLOBAL_VARIABLES = SNIPPETS_ENGINE.do_actions(context)


def make_root_context(ctx):
    def make():
        # helper variables
        cxx_helpers_dir = find_prj_dir(ctx.cxx_helpers_dir)
        helpers_dir = find_prj_dir(ctx.helpers_dir)
        out_dir = ctx.out_dir
        helpers_package_prefix = ctx.helpers_package_prefix
        helpers_out_dir = os.path.join(out_dir + helpers_package_prefix.replace('.', os.sep))
        # base variables
        cxx_base_dir = find_prj_dir(ctx.cxx_base_dir)
        return locals()

    context = {k: getattr(ctx, k) for k in ctx.node.args}
    context.update(make())

    return context


def make_def_context(ctx):
    def make():
        # helper variables
        pat_sep = os.sep
        path = os.path
        helper = LANGUAGE_HELPER_MODULE
        marker = JINJA_UNIQUE_MARKER
        banner_logo = iegen.BANNER_LOGO
        new_line = iegen.converter.NEW_LINE
        return locals()

    context = make()
    context.update(GLOBAL_VARIABLES)
    context.update(ctx.api_args)
    return context


def make_clang_context(ctx):
    def make():
        cursor = ctx.cursor
        cxx_name = ctx.cursor.spelling

        prj_rel_file_name = ctx.prj_rel_file_name
        comment = ctx.comment

        return locals()

    context = make_def_context(ctx)
    context.update(make())
    return context


def make_package_context(ctx):
    context = make_def_context(ctx)

    context['package'] = ctx.name
    return context


def make_func_context(ctx):
    def make():
        args = [
            types.SimpleNamespace(
                converter=SNIPPETS_ENGINE.build_type_converter(ctx,
                                                               arg.type,
                                                               template_choice=ctx.template_choice),
                name=arg.name,
                default=arg.default,
                cursor=arg.cursor,
                type=arg.type,
                nullable=arg.name in ctx.nullable_arg or arg.default in ('nullptr', 'NULL')
            ) for arg in ctx.args
        ]

        if hasattr(ctx, 'result_type'):
            rconverter = SNIPPETS_ENGINE.build_type_converter(ctx, ctx.result_type, template_choice=ctx.template_choice)

        owner_class = types.SimpleNamespace(**make_class_context(ctx.parent_context))

        overloading_prefix = ctx.overloading_prefix
        # capturing suffix since we use single context with different template choice
        _suffix = owner_class.template_suffix
        template_choice = ctx.template_choice
        template_names = ctx.template_names
        if ctx.node.is_function_template:
            overloading_prefix = get_template_suffix(ctx, LANGUAGE)

        if ctx.cursor.kind in [cli.CursorKind.CXX_METHOD, cli.CursorKind.FUNCTION_TEMPLATE]:
            _overriden_cursors = ctx.cursor.get_overriden_cursors()
            is_override = bool(_overriden_cursors)
            if is_override:
                original_definition_context = ctx.find_by_type(
                    _overriden_cursors[0].lexical_parent.type.spelling)
            is_static = bool(ctx.cursor.is_static_method())
            is_virtual = bool(ctx.cursor.is_virtual_method())
        is_abstract = ctx.cursor.is_abstract_record()
        is_open = not cutil.is_final_cursor(ctx.cursor)
        is_public = ctx.cursor.access_specifier == cli.AccessSpecifier.PUBLIC
        is_protected = ctx.cursor.access_specifier == cli.AccessSpecifier.PROTECTED
        is_private = ctx.cursor.access_specifier == cli.AccessSpecifier.PRIVATE
        access_specifier = ctx.cursor.access_specifier.name.lower()

        return locals()

    context = make_clang_context(ctx)
    context.update(make())
    return context


def make_enum_context(ctx):
    def make():
        # helper variables
        enum_cases = ctx.enum_values
        cxx_type_name = ctx.node.type_name()
        return locals()

    context = make_clang_context(ctx)
    context.update(make())
    return context


def make_class_context(ctx):
    def _make(ctx):
        def make():
            # helper variables
            template_suffix = get_template_suffix(ctx, LANGUAGE)
            is_open = not cutil.is_final_cursor(ctx.cursor)
            cxx_type_name = ctx.node.type_name(ctx.template_choice)
            converter = SNIPPETS_ENGINE.build_type_converter(ctx, ctx.cursor.type,
                                                             template_choice=ctx.template_choice,
                                                             search_name=ctx.node.full_displayname
                                                             if ctx.cursor.type.kind == cli.TypeKind.INVALID
                                                             else None)
            base_types_converters = [SNIPPETS_ENGINE.build_type_converter(ctx, base_type, ctx.template_choice)
                                     for base_type in ctx.base_types]
            has_non_abstract_base_class = not all(b.ctx.action == 'gen_interface' for b in base_types_converters)

            cxx_root_type_name = ctx.node.root_type_name(template_choice=ctx.template_choice)
            is_abstract = ctx.cursor.is_abstract_record()
            return locals()

        context = make_clang_context(ctx)
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
            setter_ctx = make_func_context(setter_ctx)

        return locals()

    context = make_func_context(ctx)
    context.update(make())
    return context


def make_member_context(ctx):
    def make():
        # helper variables
        rconverter = SNIPPETS_ENGINE.build_type_converter(ctx, ctx.cursor.type, template_choice=ctx.template_choice)

        owner_class = types.SimpleNamespace(**make_class_context(ctx.parent_context))

        return locals()

    context = make_clang_context(ctx)
    context.update(make())
    return context


def get_template_suffix(ctx, target_language):
    template_choice = ctx.template_choice
    template_types = ctx.template_type_parameters
    args_names = []
    if template_choice:
        for t in template_types:
            search_name = template_choice[t]

            ref_ctx = ctx.find_by_type(search_name)
            if ref_ctx is not None:
                if ctx.cursor.type.kind == cli.TypeKind.ENUM:
                    search_name = ENUM_INFO_TYPE
                else:
                    search_name = OBJECT_INFO_TYPE

            type_converter = SNIPPETS_ENGINE.get_type_info(search_name)
            if not type_converter:
                raise KeyError(f"Can not find type for {search_name}")
            type_converter = type_converter.make_converter(ctx.cursor.type, ref_ctx,
                                                           template_choice=template_choice)

            args_names.append(getattr(type_converter, target_language).target_type_name)

    return ''.join(args_names)


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
    _validate_nullable_args(ctx)
    context = make_constructor_context(ctx)
    preprocess_entry(context, builder, 'constructor')


def gen_method(ctx, builder):
    _validate_nullable_args(ctx)
    context = make_func_context(ctx)
    preprocess_entry(context, builder, 'function')


def gen_getter(ctx, builder):
    _validate_getter(ctx)
    context = make_getter_context(ctx)
    preprocess_entry(context, builder, 'getter')


def gen_property_getter(ctx, builder):
    _validate_property_getter(ctx)
    context = make_member_context(ctx)
    preprocess_entry(context, builder, 'property_getter')


def gen_property_setter(ctx, builder):
    gen_property_getter(ctx, builder)


def gen_setter(ctx, builder):
    return


def _validate_nullable_args(ctx):
    args = [arg.name for arg in ctx.args]
    incorrect_args = [arg for arg in ctx.nullable_arg if arg not in args]
    if incorrect_args:
        Error.critical(
            f'{", ".join(incorrect_args)} arguments are marked as nullable but '
            f'{ctx.cursor.lexical_parent.displayname}.{ctx.cursor.displayname} does not have such arguments.')


def _validate_getter(ctx):
    if ctx.args:
        Error.critical(
            f'Getter should not have arguments: {ctx.cursor.lexical_parent.displayname}.{ctx.cursor.displayname}.')
    if ctx.setter:
        if len(ctx.setter.args) != 1:
            Error.critical(
                f'Setter should have one argument: {ctx.cursor.lexical_parent.displayname}.{ctx.cursor.displayname}.')

        _validate_nullable_args(ctx.setter)

        have_diff_nullability = len(ctx.setter.nullable_arg) == 0 ^ ctx.nullable_return is False
        if have_diff_nullability:
            Error.critical(
                f'Setter argument and getter return value should have the same nullability:'
                f' {ctx.cursor.lexical_parent.displayname}.{ctx.cursor.displayname}.')


def _validate_property_getter(ctx):
    if ctx.cursor.access_specifier != cli.AccessSpecifier.PUBLIC:
        Error.critical(
            f'{ctx.cursor.lexical_parent.displayname}.{ctx.cursor.displayname} is not a public field.'
            f'Make it public or remove iegen API.')
