import os
import shutil
import glob
import iegen.utils.clang as cutil
from iegen.utils import load_from_paths
from iegen.common.config import PROJECT_CONFIG_DIR, DEFAULT_DIRS
from iegen.builder.out_builder import Scope
import iegen.converter.kotlin as convert
from iegen import logging


def make_kotlin_comment(pure_comment):
    nl = '\n * '
    if not pure_comment:
        return ""
    return f"""/**{nl.join(pure_comment)}
 */"""


def build_jni_func_cxx(ctx, builder):

    arg_scope = Scope(tab=1, parts_spliter=',\n')

    arg_scope.add(
        "\n"
        "JNIEnv* env",
        f"{convert.OBJECT_CXX_TYPE} obj",
        f"{convert.OBJECT_CXX_ID_TYPE} id"
    )
    body = []
    body.append("validateID(id);")

    cxx_name = ctx.cursor.spelling
    full_class_name = ctx.cursor.semantic_parent.type.spelling
    body.append(f"auto this_object = RefFromLong<{full_class_name}>(id);")
    cxx_call_args = []
    for arg in ctx.args:
        # lookup type, create argument list and conversion code
        type_ctx = arg['type']
        type_converter = convert.build_type_converter(ctx, type_ctx)

        arg_scope.add(convert.cxx_jni_arg_str(type_name=type_converter.jni.target_type_name, **arg))
        converter_code = type_converter.jni_to_cxx
        cxx_call_args.append(converter_code.converted_name(arg['name']))
        # now add conversion code into body if needed
        snippet = converter_code.snippet(arg['name'])
        if snippet:
            body.append(snippet)

    args_str = str(arg_scope)

    result_type_converter = convert.build_type_converter(ctx, ctx.result_type)

    # todo for cxx to jni
    converter_code = result_type_converter.cxx_to_jni

    package = f'{ctx.config.package_prefix}.{ctx.package}'
    class_name = ctx.parent_context.name
    method_name = convert.jni_func_name(ctx) + ctx.overloading_prefix

    result_cxx_name = result_type_converter.jni.target_type_name

    jni_cxx_func = f'extern "C" JNIEXPORT {result_cxx_name} \
{convert.get_jni_func_name(package, class_name, method_name)}({args_str}){{'

    if result_cxx_name != 'void':
        body.append(f"auto result = this_object->{cxx_name}({', '.join(cxx_call_args)});")
        result_name = converter_code.converted_name('result')
        res_snipped = converter_code.snippet('result')
        if res_snipped:
            body.append(res_snipped)
        body.append(f"return {result_name};")
    else:
        body.append(f"this_object->{cxx_name}({', '.join(cxx_call_args)});")

    jni_cxx_file = get_cxx_jni_file(ctx, builder)
    jni_cxx_file['body_cxx'].add(
        jni_cxx_func,
        Scope(
            "return jni::handleNativeCrash(env, [&] {",
            Scope(
                *body,
                tab=1
            ),
            "}",
            ");",
            tab=1
        ),
        "}",
        "",
    )


def build_jni_func(ctx, builder):

    file_scope = get_file(ctx, builder)
    arg_scope = Scope(tab=1, parts_spliter=',\n')
    arg_scope.add('id: Long')

    for arg in ctx.args:
        # lookup type, create argument list and conversion code
        type_ctx = arg['type']
        type_converter = convert.build_type_converter(ctx, type_ctx)

        arg = convert.kt_jni_arg_str(type_name=type_converter.jdk.target_type_name, **arg)
        arg_scope.add(arg)

    args_str = '\n' + str(arg_scope) + '\n' if arg_scope else ''

    result_type_converter = convert.build_type_converter(ctx, ctx.result_type)
    # TODO for complex type use id for builtin use directly
    jni_func = f"{convert.jni_func_name(ctx)}({args_str}): {result_type_converter.jdk.target_type_name}"

    file_scope['private_external'].add(
        f"private external fun {jni_func}"
    )

    build_jni_func_cxx(ctx, builder)


def build_jni_constructor_cxx(ctx, builder):

    arg_scope = Scope(tab=1, parts_spliter=',\n')

    arg_scope.add(
        "\n"
        "JNIEnv* env",
        f"{convert.OBJECT_CXX_TYPE} obj",
    )
    body = []

    cxx_type_name = ctx.cursor.lexical_parent.type.spelling
    # cxx_type_name = ctx.node.full_displayname
    cxx_call_args = []
    for arg in ctx.args:
        # lookup type, create argument list and conversion code
        type_ctx = arg['type']
        type_converter = convert.build_type_converter(ctx, type_ctx)
        type_name = type_converter.jni.target_type_name
        arg_scope.add(convert.cxx_jni_arg_str(type_name=type_name, **arg))
        converter_code = type_converter.jni_to_cxx
        cxx_call_args.append(converter_code.converted_name(arg['name']))
        # now add conversion code into body if needed
        snippet = converter_code.snippet(arg['name'])
        if snippet:
            body.append(snippet)

    args_str = str(arg_scope)

    package = f'{ctx.config.package_prefix}.{ctx.package}'
    class_name = ctx.parent_context.name
    method_name = 'jConstructor' + ctx.overloading_prefix

    jni_cxx_func = f'extern "C" JNIEXPORT {convert.OBJECT_CXX_ID_TYPE} \
{convert.get_jni_func_name(package, class_name, method_name)}({args_str}){{'

    body.append(f"auto this_object = new {cxx_type_name}({', '.join(cxx_call_args)});")
    body.append("return UnsafeRefAsLong(this_object);")

    jni_cxx_file = get_cxx_jni_file(ctx, builder)
    jni_cxx_file['body_cxx'].add(
        jni_cxx_func,
        Scope(
            "return jni::handleNativeCrash(env, [&] {",
            Scope(
                *body,
                tab=1
            ),
            "}",
            ");",
            tab=1
        ),
        "}",
        "",
    )


def build_jni_constructor(ctx, builder):

    file_scope = get_file(ctx, builder)
    arg_scope = Scope(tab=1, parts_spliter=',\n')

    for arg in ctx.args:
        # lookup type, create argument list and conversion code
        type_ctx = arg['type']
        type_converter = convert.build_type_converter(ctx, type_ctx)

        arg = convert.kt_jni_arg_str(type_name=type_converter.jdk.target_type_name, **arg)
        arg_scope.add(arg)

    args_str = '\n' + str(arg_scope) + '\n' if arg_scope else ''

    # TODO for complex type use id for builtin use directly
    create_object = 'jConstructor' + ctx.overloading_prefix
    jni_func = f"{create_object}({args_str}): Long"

    file_scope['private_external'].add(
        f"private external fun {jni_func}"
    )

    build_jni_constructor_cxx(ctx, builder)


def get_cxx_jni_file(ctx, builder):
    out_dir = ctx.config.cxx_out_dir
    package_prefix = ctx.config.package_prefix

    module_dir = os.path.join(package_prefix, ctx.package).replace('.', os.sep)
    file_path = os.path.join(out_dir, module_dir, ctx.file + '.cpp')

    def init_func(fscope):
        fscope["include_cxx"].add_unique(
            convert.get_includes(),
            # also include ctx header file
        )
        fscope["helpers_cxx"].add_unique(
            convert.CXX_HELPERS,
        )
        fscope.get_scope('body_cxx', create=True)

    file_scope = builder.get_file(file_path, init_func=init_func)

    file_scope["include_cxx"].add_unique(
        # also include ctx header file
        f'#include "{ctx.prj_rel_file_name}"'
    )
    return file_scope


def get_file(ctx, builder):
    out_dir = ctx.config.out_dir
    package_prefix = ctx.config.package_prefix

    module_dir = os.path.join(package_prefix, ctx.package).replace('.', os.sep)
    file_path = os.path.join(out_dir, module_dir, ctx.file + '.kt')

    def init_func(fscope):
        fscope["package"].add_unique(
            f"package {package_prefix}.{ctx.package}",
            "\n",
        )

        fscope["include"].add_unique(
            *[f"import {imp}" for imp in ctx.include],
            "\n",
        )

        fscope["type_alias"].add_unique(
            "typealias StringArray = Array<String>",
            "typealias ObjectArray = Array<Any>",
            "\n",
        )

        fscope.get_scope('body', create=True)

    file_scope = builder.get_file(file_path, init_func=init_func)

    file_scope["include"].add_unique(
        *[f"import {imp}" for imp in ctx.include],
        "\n",
    )

    return file_scope


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
    kotlin_imports = []
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
        import_name = os.path.join(prj_rel, file_rel_name)
        logging.info(f"Helper import name {import_name}")
        kotlin_imports.append(incude_name)
        target_file = os.path.join(config.out_dir, file_rel_name)
        os.makedirs(os.path.dirname(target_file), exist_ok=True)
        shutil.copyfile(file_name, target_file)


def gen_enum(ctx, builder):
    file_scope = get_file(ctx, builder)
    file_scope['body'].add(
        make_kotlin_comment(ctx.node.pure_comment),
        f"enum class {ctx.name}(val value: Int){{",
        convert.indent(',\n'.join([f"{case['name']}({case['value']})" for case in ctx.enum_values]), 3) + ';',
        "",
        convert.indent("""companion object {
    private val values = values();
    fun getByValue(value: Int) = values.firstOrNull { it.value == value }
}""", 3),
        "}",
        "\n",
    )


def gen_class(ctx, builder):
    # get or create logical file
    file_scope = get_file(ctx, builder)
    o_classification = ""
    if not cutil.is_final_cursor(ctx.cursor):
        o_classification += "open "

    base_types = ctx.base_types
    base = convert.build_type_converter(
        ctx, base_types[0]
    ).kotlin.target_type_name + '(id)' if base_types else "RNativeObject(id)"

    file_scope['body'].add(
        make_kotlin_comment(ctx.node.pure_comment),
        f"{o_classification}class {ctx.name}",
        Scope(f"internal constructor(id: Long): {base}", tab=1),
        "{",
        Scope(name="head", tab=1),
        Scope(name="properties", tab=1),
        Scope(name="body", tab=1),
        "///// External wrapper functions ////////////\n",
        Scope(name="private_external", tab=1),
        "}",
        "\n",
    )


def gen_constructor(ctx, builder):
    file_scope = get_file(ctx, builder)

    arg_scope = Scope(tab=1, parts_spliter=',\n')

    body = []
    jni_call_args = []

    for arg in ctx.args:
        # lookup type, create argument list and conversion code
        type_ctx = arg['type']
        type_converter = convert.build_type_converter(ctx, type_ctx)

        arg_scope.add(convert.kt_arg_str(type_name=type_converter.kotlin.target_type_name, **arg))

        converter_code = type_converter.kotlin_to_jdk
        jni_call_args.append(converter_code.converted_name(arg['name']))
        # now add conversion code into body if needed
        snippet = converter_code.snippet(arg['name'])
        if snippet:
            body.append(snippet)

    # create object
    create_object = 'jConstructor' + ctx.overloading_prefix
    body.append(f"this.id = {create_object}({', '.join(jni_call_args)})")
    args_str = '\n' + str(arg_scope) + '\n' if arg_scope else ''

    header = f"constructor({args_str}): this(0) {{"

    file_scope['head'].add(
        make_kotlin_comment(ctx.node.pure_comment),
        header,
        Scope(*body, tab=1),
        "}",
        "",
    )
    build_jni_constructor(ctx, builder)


def gen_method(ctx, builder):
    file_scope = get_file(ctx, builder)

    arg_scope = Scope(tab=1, parts_spliter=',\n')

    body = []
    jni_call_args = ['id']

    for arg in ctx.args:
        # lookup type, create argument list and conversion code
        type_ctx = arg['type']
        type_converter = convert.build_type_converter(ctx, type_ctx)

        arg_scope.add(convert.kt_arg_str(type_name=type_converter.kotlin.target_type_name, **arg))
        converter_code = type_converter.kotlin_to_jdk
        jni_call_args.append(converter_code.converted_name(arg['name']))
        # now add conversion code into body if needed
        snippet = converter_code.snippet(arg['name'])
        if snippet:
            body.append(snippet)

    args_str = '\n' + str(arg_scope) + '\n' if arg_scope else ''

    result_type_converter = convert.build_type_converter(ctx, ctx.result_type)
    # todo for jni to koti
    converter_code = result_type_converter.jdk_to_kotlin
    body.append(f"val result = {convert.jni_func_name(ctx)}({', '.join(jni_call_args)})")
    res_snipped = converter_code.snippet('result')
    if res_snipped:
        body.append(res_snipped)

    result_name = converter_code.converted_name('result')
    body.append(f"return {result_name}")

    o_v_classification = ""
    if not cutil.is_final_cursor(ctx.cursor):
        o_v_classification += "open "

    if ctx.cursor.get_overriden_cursors():
        o_v_classification += "override "

    header = f"{o_v_classification}fun {ctx.name}({args_str}): {result_type_converter.kotlin.target_type_name} {{"
    file_scope['body'].add(
        make_kotlin_comment(ctx.node.pure_comment),
        header,
        Scope(
            *body,
            tab=1
        ),
        "}",
        "\n",
    )
    build_jni_func(ctx, builder)


def gen_getter(ctx, builder):
    file_scope = get_file(ctx, builder)

    assert not ctx.args, "getter should not have arguments"
    setter_ctx = ctx.setter

    getter_body = []
    setter_body = []
    result_type_converter = convert.build_type_converter(ctx, ctx.result_type)

    if setter_ctx:
        assert len(setter_ctx.args) == 1, "Setter should have one argument."

        arg = setter_ctx.args[0]
        # lookup type, create argument list and conversion code
        type_ctx = arg['type']
        type_converter = convert.build_type_converter(ctx, type_ctx)

        converter_code = type_converter.kotlin_to_jdk
        jni_call_arg = converter_code.converted_name('value')
        # now add conversion code into body if needed
        snippet = converter_code.snippet('value')
        if snippet:
            setter_body.append(snippet)

        setter_body.append(f"{convert.jni_func_name(setter_ctx)}(id, {jni_call_arg})")

    converter_code = result_type_converter.jdk_to_kotlin
    getter_body.append(f"val result = {convert.jni_func_name(ctx)}(id)")
    res_snipped = converter_code.snippet('result')
    if res_snipped:
        getter_body.append(res_snipped)

    result_name = converter_code.converted_name('result')
    getter_body.append(f"return {result_name}")

    header = f"{'var' if setter_ctx else 'val'} {ctx.name}: {result_type_converter.kotlin.target_type_name}"
    parts = [
        make_kotlin_comment(ctx.node.pure_comment),
        header,
        Scope(
            "get() {",
            Scope(
                *getter_body,
                tab=1
            ),
            "}",
            tab=1
        ),
    ]
    if setter_ctx:
        parts.append(
            Scope(
                "set(value) {",
                Scope(
                    *setter_body,
                    tab=1
                ),
                "}",
                tab=1
            ),
        )

    file_scope['properties'].add(*parts, '')
    build_jni_func(ctx, builder)
    if setter_ctx:
        build_jni_func(setter_ctx, builder)


def gen_setter(ctx, builder):

    getter_ctx = ctx.getter
    # todo if only setter should we generate it here?
    if getter_ctx:
        return
    # else
