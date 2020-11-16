import os
import types
import copy
from functools import partial
import iegen.utils.clang as cutil
from iegen import find_prj_dir
from iegen.utils import load_from_paths
from iegen.common.config import PROJECT_CONFIG_DIR, DEFAULT_DIRS
from iegen.common.snippets_engine import SnippetsEngine
import iegen.converter.kotlin as convert

SNIPPETS_ENGINE = None
GLOBAL_VARIABLES = {}


def load_snipppets_engine(path, main_target):
    global SNIPPETS_ENGINE
    SNIPPETS_ENGINE = SnippetsEngine(path, main_target)
    SNIPPETS_ENGINE.load()


def gen_init(config, *args, **kwargs):
    global SNIPPETS_ENGINE, GLOBAL_VARIABLES
    # load snippets

    def make_context(config):
        # helper variables
        cxx_helpers_dir = find_prj_dir(config.cxx_helpers_dir)
        helpers_dir = find_prj_dir(config.helpers_dir)
        return locals()

    context = make_context(config)

    load_from_paths(lambda path: load_snipppets_engine(path, 'kotlin'),
                    config.snippets, DEFAULT_DIRS)

    GLOBAL_VARIABLES = SNIPPETS_ENGINE.do_actions(context)


def make_def_context(ctx):
    def make():
        # helper variables
        config = ctx.config
        pat_sep = os.sep

        cursor = ctx.cursor
        cxx_name = ctx.cursor.spelling

        prj_rel_file_name = ctx.prj_rel_file_name
        comment = convert.make_comment(ctx.node.pure_comment)

        return locals()

    context = make()
    context.update(GLOBAL_VARIABLES)
    context.update(ctx.api_args)
    return context


def make_func_context(ctx):
    def make():
        # helper variables
        args = [
            types.SimpleNamespace(
                converter=SNIPPETS_ENGINE.build_type_converter(ctx, arg.type),
                name=arg.name,
                default=arg.default,
                cursor=arg.cursor,
                type=arg.type
            ) for arg in ctx.args
        ]

        if hasattr(ctx, 'result_type'):
            rconverter = SNIPPETS_ENGINE.build_type_converter(ctx, ctx.result_type)

        owner_class = types.SimpleNamespace(**make_class_context(ctx.parent_context))

        overloading_prefix = ctx.overloading_prefix
        get_jni_name = partial(convert.get_jni_func_name,
                               f'{ctx.config.package_prefix}.{ctx.package}',
                               ctx.parent_context.name)
        cxx_type_name = ctx.cursor.semantic_parent.type.spelling

        if ctx.cursor.kind == cutil.cli.CursorKind.CXX_METHOD:
            is_override = bool(ctx.cursor.get_overriden_cursors())
            is_static = bool(ctx.cursor.is_static_method())
            is_virtual = bool(ctx.cursor.is_virtual_method())
        is_open = not cutil.is_final_cursor(ctx.cursor)
        is_public = ctx.cursor.access_specifier == cutil.cli.AccessSpecifier.PUBLIC
        is_protected = ctx.cursor.access_specifier == cutil.cli.AccessSpecifier.PROTECTED
        is_private = ctx.cursor.access_specifier == cutil.cli.AccessSpecifier.PRIVATE
        access_specifier = ctx.cursor.access_specifier.name.lower()

        return locals()

    context = make_def_context(ctx)
    context.update(make())
    return context


def make_enum_context(ctx):
    def make():
        # helper variables
        enum_cases = ctx.enum_values
        return locals()

    context = make_def_context(ctx)
    context.update(make())
    return context


def make_class_context(ctx):
    def _make(ctx):
        def make():
            # helper variables
            is_open = not cutil.is_final_cursor(ctx.cursor)
            if ctx.base_types:
                base_type_converter = SNIPPETS_ENGINE.build_type_converter(
                    ctx, ctx.base_types[0]
                )
            return locals()

        context = make_def_context(ctx)
        context.update(make())
        return context

    context = _make(ctx)
    ancestors = [types.SimpleNamespace(**_make(ancesstor)) for ancesstor in ctx.ancestors]
    context.update(dict(ancestors=ancestors))
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
            setter_ctx = make_func_context(ctx.setter)

        return locals()

    context = make_func_context(ctx)
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
        scope.add_unique(str(info.unique_make_snippet(context_scope)))


def preprocess_entry(context, builder, code_name):
    code_info = None
    if 'name' in context:
        code_info = SNIPPETS_ENGINE.get_code_info(f"{code_name}_{context['name']}")

    code_info = code_info or SNIPPETS_ENGINE.get_code_info(code_name)
    for fs, info in code_info.items():
        fscope_name, scope_name = fs
        file_scope = get_file(context, builder, fscope_name)
        parent_scope = file_scope[scope_name]
        preprocess_scope(context, parent_scope, info)


def get_file(context, builder, fscope_name):
    file_info = SNIPPETS_ENGINE.get_file_info(fscope_name)
    file_name = file_info.get_file_name(context)

    return builder.get_file(file_name, init_func=lambda s: preprocess_scope(context, s, file_info))


def gen_enum(ctx, builder):
    context = make_enum_context(ctx)
    preprocess_entry(context, builder, 'enum')


def gen_class(ctx, builder):
    context = make_class_context(ctx)
    preprocess_entry(context, builder, 'class')


def gen_constructor(ctx, builder):
    context = make_constructor_context(ctx)
    preprocess_entry(context, builder, 'constructor')


def gen_method(ctx, builder):
    context = make_func_context(ctx)
    preprocess_entry(context, builder, 'function')
    return


def gen_getter(ctx, builder):

    assert not ctx.args, "getter should not have arguments"
    if ctx.setter:
        assert len(ctx.setter.args) == 1, "Setter should have one argument."

    context = make_getter_context(ctx)
    preprocess_entry(context, builder, 'getter')
    return


def gen_setter(ctx, builder):
    return
