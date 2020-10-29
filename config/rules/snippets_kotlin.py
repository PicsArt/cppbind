import os
import types
import shutil
import glob
import copy
from functools import partial
import iegen.utils.clang as cutil
from iegen.utils import load_from_paths
from iegen.common.config import PROJECT_CONFIG_DIR, DEFAULT_DIRS
import iegen.converter.kotlin as convert
from iegen import logging


def make_kotlin_comment(pure_comment):
    nl = '\n * '
    if not pure_comment:
        return ""
    return f"""/**{nl.join(pure_comment)}
 */"""


def gen_init(config, *args, **kwargs):
    # load snippets

    load_from_paths(lambda path: convert.load_snipppets_engine(path, 'kotlin'),
                    config.snippets, DEFAULT_DIRS)

    # handle cxx helper files
    prj_rel = os.path.relpath(config.cxx_out_dir, config.out_prj_dir)
    cxx_helpers_dir = config.cxx_helpers_dir
    if not os.path.isabs(cxx_helpers_dir):
        if not os.path.isdir(cxx_helpers_dir):
            cxx_helpers_dir = os.path.abspath(os.path.join(PROJECT_CONFIG_DIR, cxx_helpers_dir))
    cxx_helpers_files = os.path.join(cxx_helpers_dir, '**/*.h*')
    for file_name in glob.glob(cxx_helpers_files, recursive=True):
        logging.info(f"Using helper file {file_name}")
        file_rel_name = os.path.relpath(file_name, cxx_helpers_dir)
        incude_name = os.path.join(prj_rel, file_rel_name)
        logging.info(f"Helper include name {incude_name}")
        convert.CXX_INCLUDE_NAMES.append(incude_name)
        target_file = os.path.join(config.cxx_out_dir, file_rel_name)
        os.makedirs(os.path.dirname(target_file), exist_ok=True)
        shutil.copyfile(file_name, target_file)

    # now handle kotlin helper files
    prj_rel = os.path.relpath(config.out_dir, config.out_prj_dir)
    kotlin_helpers_dir = config.kotlin_helpers_dir
    if not os.path.isabs(kotlin_helpers_dir):
        if not os.path.isdir(kotlin_helpers_dir):
            kotlin_helpers_dir = os.path.abspath(os.path.join(PROJECT_CONFIG_DIR, kotlin_helpers_dir))
    kotlin_helpers_files = os.path.join(kotlin_helpers_dir, '**/*.kt')
    java_helpers_files = os.path.join(kotlin_helpers_dir, '**/*.java')
    for file_name in glob.glob(java_helpers_files, recursive=True) +\
            glob.glob(kotlin_helpers_files, recursive=True):
        logging.info(f"Using helper file {file_name}")
        file_rel_name = os.path.relpath(file_name, kotlin_helpers_dir)
        import_name = os.path.splitext(file_rel_name)[0].replace(os.sep, '.')
        logging.info(f"Helper import name {import_name}")
        convert.KOTLIN_IMPORTS.append(import_name)
        target_file = os.path.join(config.out_dir, file_rel_name)
        os.makedirs(os.path.dirname(target_file), exist_ok=True)
        shutil.copyfile(file_name, target_file)


def make_def_context(ctx):
    def make():
        # helper variables
        config = ctx.config
        package = ctx.package
        file = ctx.file
        pat_sep = os.sep

        name = ctx.name

        includes = ctx.include
        prj_rel_file_name = ctx.prj_rel_file_name
        helper_includes = convert.KOTLIN_IMPORTS
        comment = make_kotlin_comment(ctx.node.pure_comment)

        return locals()

    context = make()
    return context


def make_func_context(ctx):
    def make():
        # helper variables
        args = [
            types.SimpleNamespace(
                converter=convert.build_type_converter(ctx, arg.type),
                name=arg.name,
                default=arg.default,
                cursor=arg.cursor,
                type=arg.type
            ) for arg in ctx.args
        ]

        if hasattr(ctx, 'result_type'):
            rconverter = convert.build_type_converter(ctx, ctx.result_type)

        overloading_prefix = ctx.overloading_prefix
        get_jni_name = partial(convert.get_jni_func_name,
                               f'{ctx.config.package_prefix}.{ctx.package}',
                               ctx.parent_context.name)
        cxx_type_name = ctx.cursor.semantic_parent.type.spelling

        if ctx.cursor.kind == cutil.cli.CursorKind.CXX_METHOD:
            is_override = bool(ctx.cursor.get_overriden_cursors())
        is_open = not cutil.is_final_cursor(ctx.cursor)

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
        scope.add_unique(str(info.unique_make_snippet(context_scope)))


def preprocess_entry(context, builder, code_name):
    code_info = convert.get_code_info(code_name)
    for fs, info in code_info.items():
        fscope_name, scope_name = fs
        file_scope = get_file(context, builder, fscope_name)
        parent_scope = file_scope[scope_name]
        preprocess_scope(context, parent_scope, info)


def get_file(context, builder, fscope_name):
    file_info = convert.get_file_info(fscope_name)
    file_name = file_info.get_file_name(context)

    return builder.get_file(file_name, init_func=lambda s: preprocess_scope(context, s, file_info))


def gen_enum(ctx, builder):
    def _make_context(ctx):
        def make():
            # helper variables
            enum_cases = ctx.enum_values
            return locals()

        context = make_def_context(ctx)
        context.update(make())
        return context

    context = _make_context(ctx)
    preprocess_entry(context, builder, 'enum')


def gen_class(ctx, builder):
    def _make_context(ctx):
        def make():
            # helper variables
            is_open = not cutil.is_final_cursor(ctx.cursor)
            if ctx.base_types:
                base_type = convert.build_type_converter(
                    ctx, ctx.base_types[0]
                )
            return locals()

        context = make_def_context(ctx)
        context.update(make())
        return context

    context = _make_context(ctx)
    preprocess_entry(context, builder, 'class')


def gen_constructor(ctx, builder):
    def _make_context(ctx):
        def make():
            # helper variables

            return locals()

        context = make_func_context(ctx)
        context.update(make())
        return context

    context = _make_context(ctx)
    preprocess_entry(context, builder, 'constructor')


def gen_method(ctx, builder):
    def _make_context(ctx):
        def make():
            # helper variables

            return locals()

        context = make_func_context(ctx)
        context.update(make())
        return context

    context = _make_context(ctx)
    preprocess_entry(context, builder, 'function')
    return


def gen_getter(ctx, builder):
    def _make_context(ctx):
        def make():
            # helper variables
            if ctx.setter:
                setter_ctx = make_func_context(ctx.setter)

            return locals()

        context = make_func_context(ctx)
        context.update(make())
        return context

    assert not ctx.args, "getter should not have arguments"
    if ctx.setter:
        assert len(ctx.setter.args) == 1, "Setter should have one argument."

    context = _make_context(ctx)
    preprocess_entry(context, builder, 'getter')
    return


def gen_setter(ctx, builder):
    return
