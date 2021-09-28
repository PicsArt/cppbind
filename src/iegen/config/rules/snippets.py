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
from iegen.converter import Validator
from iegen.common.snippets_engine import (
    JINJA_UNIQUE_MARKER,
    SnippetsEngine,
    CXXType
)
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
    LANGUAGE_HELPER_MODULE = importlib.import_module(f'iegen.converter.{language}')


def load_snippets_engine(ctx_desc, platform, language):
    global SNIPPETS_ENGINE
    SNIPPETS_ENGINE = SnippetsEngine(ctx_desc, platform, language)
    SNIPPETS_ENGINE.load()


def gen_init(ctx, ctx_desc, platform, language, *args, **kwargs):
    global SNIPPETS_ENGINE, GLOBAL_VARIABLES
    # load snippets

    context = make_root_context(ctx)

    load_snippets_engine(ctx_desc, platform, language)

    GLOBAL_VARIABLES = SNIPPETS_ENGINE.do_actions(context)


def make_root_context(ctx):
    def make():
        # api
        vars = ctx.vars

        # helper variables
        vars.cxx_helpers_dir = find_prj_dir(ctx.vars.cxx_helpers_dir)
        vars.helpers_dir = find_prj_dir(ctx.vars.helpers_dir)
        vars.cxx_base_dir = find_prj_dir(ctx.vars.cxx_base_dir)

        # base variables
        return locals()

    context = make()

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

        vars = ctx.vars

        def make_converter(type_name, template_choice=None):
            return SNIPPETS_ENGINE.build_type_converter(ctx, CXXType(type_name,
                                                                     template_choice))

        return locals()

    context = make()
    context.update(GLOBAL_VARIABLES)
    return context


def make_package_context(ctx):
    context = make_def_context(ctx)

    context['package'] = ctx.vars.name
    return context


def make_func_context(ctx):
    def make():
        args = [
            types.SimpleNamespace(
                converter=SNIPPETS_ENGINE.build_type_converter(ctx,
                                                               CXXType(type_=arg.type,
                                                                       template_choice=ctx.template_choice)),
                name=arg.name,
                default=arg.default.value,
                cursor=arg.cursor,
                type=arg.type,
                nullable=arg.name in ctx.vars.nullable_arg or arg.default.kind == DefaultValueKind.NULL_PTR,
                is_enum=arg.type.kind == cli.TypeKind.ENUM,
                is_bool=arg.type.kind == cli.TypeKind.BOOL,
                is_long=arg.type.kind == cli.TypeKind.LONG,
                is_float=arg.type.kind in (cli.TypeKind.FLOAT, cli.TypeKind.FLOAT128),
                is_literal=arg.default.kind == DefaultValueKind.LITERAL,
                is_null_ptr=arg.default.kind == DefaultValueKind.NULL_PTR,
            ) for arg in ctx.args
        ]

        if hasattr(ctx, 'result_type'):
            rconverter = SNIPPETS_ENGINE.build_type_converter(ctx, CXXType(type_=ctx.result_type,
                                                                           template_choice=ctx.template_choice))

        owner_class = types.SimpleNamespace(**make_class_context(ctx.parent_context))
        prj_rel_file_name = ctx.prj_rel_file_name

        overloading_prefix = ctx.overloading_prefix
        # capturing template related properties since we use single context with different template choice
        template_choice = ctx.template_choice
        template_names = ctx.template_names
        template_type_converters = [SNIPPETS_ENGINE.build_type_converter(ctx, CXXType(type_=template_arg_type)) for
                                    template_arg_type in template_choice.values()] if template_choice else []

        cxx = types.SimpleNamespace(
            name=ctx.cursor.spelling,
            is_abstract=ctx.cursor.is_abstract_record(),
            is_open=not cutil.is_final_cursor(ctx.cursor),
            is_public=ctx.cursor.access_specifier == cli.AccessSpecifier.PUBLIC,
            is_protected=ctx.cursor.access_specifier == cli.AccessSpecifier.PROTECTED,
            is_private=ctx.cursor.access_specifier == cli.AccessSpecifier.PRIVATE,
            access_specifier=ctx.cursor.access_specifier.name.lower(),
            is_template=ctx.node.is_function_template,
        )
        if ctx.cursor.kind in [cli.CursorKind.CXX_METHOD, cli.CursorKind.FUNCTION_TEMPLATE]:
            _overriden_cursors = ctx.cursor.get_overriden_cursors()
            cxx.is_override = bool(_overriden_cursors)
            cxx.is_original_definition_override = cxx.is_override and ctx.find_by_type(
                _overriden_cursors[0].lexical_parent.type.spelling).vars.action == 'gen_interface'
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
                                    type_name=ctx.cxx_type_name)
        return locals()

    context = make_def_context(ctx)
    context.update(make())
    return context


def make_class_context(ctx):
    def _make(ctx):
        def make():
            # for cases when type kind is invalid clang type does not give enough information
            # for such cases we use string type name
            converter = SNIPPETS_ENGINE.build_type_converter(ctx,
                                                             CXXType(type_=ctx.cxx_type_name,
                                                                     template_choice=ctx.template_choice))

            base_types_converters = [SNIPPETS_ENGINE.build_type_converter(ctx, CXXType(base_type, ctx.template_choice))
                                     for base_type in ctx.base_types]
            prj_rel_file_name = ctx.prj_rel_file_name

            cxx = types.SimpleNamespace(type_name=ctx.cxx_type_name,
                                        root_type_name=getattr(converter, LANGUAGE).cxx_root_type_name,
                                        name=ctx.cursor.spelling,
                                        is_open=not cutil.is_final_cursor(ctx.cursor),
                                        is_abstract=ctx.cursor.is_abstract_record())

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
            if ctx.node.is_template:
                _validate_template_getter_setter(ctx)
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
        rconverter = SNIPPETS_ENGINE.build_type_converter(ctx, CXXType(type_=ctx.cursor.type,
                                                                       template_choice=ctx.template_choice))

        owner_class = types.SimpleNamespace(**make_class_context(ctx.parent_context))
        prj_rel_file_name = ctx.prj_rel_file_name

        cxx = types.SimpleNamespace(name=ctx.cursor.spelling)

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
        snippet = info.make_snippet(context_scope)
        if snippet:
            scope.add(snippet)
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
    _validate_class(context)
    preprocess_entry(context, builder, 'class')


def gen_interface(ctx, builder):
    context = make_class_context(ctx)
    _validate_class(context)
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


def _validate_class(context):
    if LANGUAGE in ('swift', 'kotlin'):
        Validator.validate_single_root(context['ctx'].cursor)
        Validator.validate_bases(context['vars'].name, context['base_types_converters'])
        Validator.validate_ancestors(context['ancestors'])
        Validator.validate_ancestors(context['ancestors'])


def _validate_nullable_args(ctx):
    args = [arg.name for arg in ctx.args]
    incorrect_args = [arg for arg in ctx.vars.nullable_arg if arg not in args]
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

        have_diff_nullability = len(ctx.setter.vars.nullable_arg) == 0 ^ ctx.vars.nullable_return is False
        if have_diff_nullability:
            Error.critical(
                f'Setter argument and getter return value should have the same nullability:'
                f' {ctx.cursor.lexical_parent.displayname}.{ctx.cursor.displayname}.')


def _validate_property_getter(ctx):
    if ctx.cursor.access_specifier != cli.AccessSpecifier.PUBLIC:
        Error.critical(
            f'{ctx.cursor.lexical_parent.displayname}.{ctx.cursor.displayname} is not a public field.'
            f' Make it public or remove iegen API.')


def _validate_template_getter_setter(ctx):
    is_valid = len(ctx.vars.template.keys()) == len(ctx.setter.vars.template.keys())
    if is_valid:
        for template_arg, possible_types in ctx.vars.template.items():
            getter_types = {template['type'] for template in possible_types}
            setter_types = {template['type'] for template in ctx.setter.vars.template[template_arg]}
            if getter_types != setter_types:
                is_valid = False
                break
    if not is_valid:
        parent = ctx.cursor.lexical_parent.displayname
        Error.critical(
            f'Template getter/setter should have the same template argument types: '
            f'{parent}.{ctx.cursor.displayname} and {parent}.{ctx.setter.cursor.displayname}.')
