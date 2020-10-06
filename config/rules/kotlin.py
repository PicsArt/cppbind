import os
import shutil
import glob
from iegnen.common.config import PROJECT_CONFIG_DIR
from iegnen.builder.out_builder import Scope
import iegnen.converter.kotlin as convert
from iegnen import logging


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
    body.append(f"auto* this_object = RefFromLong<{full_class_name}>(id)")
    cxx_call_args = []
    for arg in ctx.args:
        # lookup type, create argument list and conversion code
        type_ctx = arg['type']
        type_converter = convert.build_type_converter(ctx, type_ctx)

        arg_scope.add(convert.cxx_jni_arg_str(type_name=type_converter.type_name.jni, **arg))
        converter_code = type_converter.converter_code.from_jni_to_cxx
        cxx_call_args.append(converter_code.converted_name(arg['name']))
        # now add conversion code into body if needed
        snipped = converter_code.conversion_snipped(arg['name'])
        if snipped:
            body.append(snipped)

    args_str = str(arg_scope)

    result_type_converter = convert.build_type_converter(ctx, ctx.result_type)

    # todo for cxx to jni
    converter_code = result_type_converter.converter_code.from_cxx_to_jni

    package = ctx.package.replace('.', '_')
    class_name = ctx.parent_context.name.replace("_", "_1")
    method_name = convert.jni_func_name(ctx).replace("_", "_1")

    result_cxx_name = result_type_converter.type_name.jni

    jni_cxx_func = f'extern "C" JNIEXPORT {result_cxx_name} Java_{package}_{class_name}_{method_name}({args_str}){{'

    body.append(f"auto result = this_object->{cxx_name}({', '.join(cxx_call_args)});")
    # TODO result conversion needs to be from cxx to jni

    result_name = converter_code.converted_name('result')

    body.append(converter_code.conversion_snipped('result'))
    body.append(f"return {result_name};")

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
            tab=1
        ),
        "}",
        "\n",
    )


def build_jni_func(ctx, builder):

    file_scope = get_file(ctx, builder)
    arg_scope = Scope(tab=1, parts_spliter=',\n')

    for arg in ctx.args:
        # lookup type, create argument list and conversion code
        type_ctx = arg['type']
        type_converter = convert.build_type_converter(ctx, type_ctx)

        arg = convert.kt_jni_arg_str(type_name=type_converter.type_name.native, **arg)
        arg_scope.add(arg)

    args_str = '\n' + str(arg_scope) + '\n' if arg_scope else ''

    result_type_converter = convert.build_type_converter(ctx, ctx.result_type)
    # TODO for complex type use id for builtin use directly
    jni_func = f"{convert.jni_func_name(ctx)}({args_str}): {result_type_converter.type_name.native}"

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

    cxx_name = ctx.cursor.spelling
    cxx_call_args = []
    for arg in ctx.args:
        # lookup type, create argument list and conversion code
        type_ctx = arg['type']
        type_converter = convert.build_type_converter(ctx, type_ctx)

        arg_scope.add(convert.cxx_jni_arg_str(type_name=type_converter.type_name.jni, **arg))
        converter_code = type_converter.converter_code.from_jni_to_cxx
        cxx_call_args.append(converter_code.converted_name(arg['name']))
        # now add conversion code into body if needed
        snipped = converter_code.conversion_snipped(arg['name'])
        if snipped:
            body.append(snipped)

    args_str = str(arg_scope)

    package = ctx.package.replace('.', '_')
    class_name = ctx.parent_context.name.replace("_", "_1")
    method_name = 'jConstructor'

    jni_cxx_func = f'extern "C" JNIEXPORT {convert.OBJECT_CXX_ID_TYPE} \
Java_{package}_{class_name}_{method_name}({args_str}){{'

    body.append(f"auto this_object = new {cxx_name}({', '.join(cxx_call_args)});")
    body.append("return UnsafeRefAsLong(this_object)")

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
            tab=1
        ),
        "}",
        "\n",
    )


def build_jni_constructor(ctx, builder):

    file_scope = get_file(ctx, builder)
    arg_scope = Scope(tab=1, parts_spliter=',\n')

    for arg in ctx.args:
        # lookup type, create argument list and conversion code
        type_ctx = arg['type']
        type_converter = convert.build_type_converter(ctx, type_ctx)

        arg = convert.kt_jni_arg_str(type_name=type_converter.type_name.native, **arg)
        arg_scope.add(arg)

    args_str = '\n' + str(arg_scope) + '\n' if arg_scope else ''

    # TODO for complex type use id for builtin use directly
    create_object = 'jConstructor'
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
        )
        fscope["helpers_cxx"].add_unique(
            convert.CXX_HELPERS,
        )
        fscope.get_scope('body_cxx', create=True)

    file_scope = builder.get_file(file_path, init_func=init_func)

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

        fscope.get_scope('body', create=True)

    file_scope = builder.get_file(file_path, init_func=init_func)

    file_scope["include"].add_unique(
        *[f"import {imp}" for imp in ctx.include],
        "\n",
    )

    return file_scope


def gen_init(config, builder):
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
        shutil.copyfile(file_name, os.path.join(config.cxx_out_dir, file_rel_name))


def gen_enum(ctx, builder):
    file_scope = get_file(ctx, builder)
    file_scope['body'].add(
        f"enum class {ctx.name}{{",
        Scope(*[f"{case['name']}({case['value']})" for case in ctx.enum_values], parts_spliter=',\n', tab=1),
        "}",
        "\n",
    )


def gen_class(ctx, builder):
    # get or create logical file
    file_scope = get_file(ctx, builder)
    file_scope['body'].add(
        f"class {ctx.name}",
        Scope(name="main_constructor", tab=1),
        "{",
        Scope(name="head", tab=1),
        Scope(name="body", tab=1),
        "///// External wrapper functions ////////////\n",
        Scope(name="private_external", tab=1),
        "}",
        "\n",
    )
    base_types = ctx.base_types
    base = convert.build_type_converter(
        ctx, base_types[0]
    ).type_name.kotlin if base_types else "RNativeParcelableObject"

    file_scope["main_constructor"].add(
        f"internal constructor(id: Long): {base}(id)")


def gen_constructor(ctx, builder):
    file_scope = get_file(ctx, builder)

    arg_scope = Scope(tab=1, parts_spliter=',\n')

    body = []
    jni_call_args = []

    for arg in ctx.args:
        # lookup type, create argument list and conversion code
        type_ctx = arg['type']
        type_converter = convert.build_type_converter(ctx, type_ctx)

        arg_scope.add(convert.kt_arg_str(type_name=type_converter.type_name.kotlin, **arg))

        converter_code = type_converter.converter_code.from_kotlin_to_native
        jni_call_args.append(converter_code.converted_name(arg['name']))
        # now add conversion code into body if needed
        snipped = converter_code.conversion_snipped(arg['name'])
        if snipped:
            body.append(snipped)

    # create object
    create_object = 'jConstructor'
    body.append(f"val id = {create_object}({', '.join(jni_call_args)})")
    args_str = '\n' + str(arg_scope) + '\n' if arg_scope else ''

    header = f"constructor({args_str}): this(id) {{"

    file_scope['head'].add(
        header,
        Scope(*body, tab=1),
        "}",
        "\n",
    )
    build_jni_constructor(ctx, builder)


def gen_method(ctx, builder):
    file_scope = get_file(ctx, builder)

    arg_scope = Scope(tab=1, parts_spliter=',\n')

    body = []
    jni_call_args = []

    for arg in ctx.args:
        # lookup type, create argument list and conversion code
        type_ctx = arg['type']
        type_converter = convert.build_type_converter(ctx, type_ctx)

        arg_scope.add(convert.kt_arg_str(type_name=type_converter.type_name.kotlin, **arg))
        converter_code = type_converter.converter_code.from_kotlin_to_native
        jni_call_args.append(converter_code.converted_name(arg['name']))
        # now add conversion code into body if needed
        snipped = converter_code.conversion_snipped(arg['name'])
        if snipped:
            body.append(snipped)

    args_str = '\n' + str(arg_scope) + '\n' if arg_scope else ''

    result_type_converter = convert.build_type_converter(ctx, ctx.result_type)
    # todo for jni to koti
    converter_code = result_type_converter.converter_code.from_native_to_kotlin
    body.append(f"val result = {convert.jni_func_name(ctx)}({', '.join(jni_call_args)});")
    body.append(converter_code.conversion_snipped('result'))

    result_name = converter_code.converted_name('result')
    body.append(f"return {result_name}")

    header = f"fun {ctx.name}({args_str}): {result_type_converter.type_name.kotlin} {{"
    file_scope['body'].add(
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
    breakpoint()
    file_scope = get_file(ctx, builder)

    arg_scope = Scope(tab=1, parts_spliter=',\n')

    body = []
    jni_call_args = []

    for arg in ctx.args:
        # lookup type, create argument list and conversion code
        type_ctx = arg['type']
        type_converter = convert.build_type_converter(ctx, type_ctx)

        arg_scope.add(convert.kt_arg_str(type_name=type_converter.type_name.kotlin, **arg))

        converter_code = type_converter.converter_code.from_kotlin_to_native
        jni_call_args.append(converter_code.converted_name(arg['name']))
        # now add conversion code into body if needed
        snipped = converter_code.conversion_snipped(arg['name'])
        if snipped:
            body.append(snipped)

    args_str = '\n' + str(arg_scope) + '\n' if arg_scope else ''

    result_type_converter = convert.build_type_converter(ctx, ctx.result_type)
    # todo for jni to koti
    converter_code = result_type_converter.converter_code.from_native_to_kotlin
    body.append(f"val result = {convert.jni_func_name(ctx)}({', '.join(jni_call_args)});")
    body.append(converter_code.conversion_snipped('result'))

    result_name = converter_code.converted_name('result')
    body.append(f"return {result_name}")

    header = f"fun {ctx.name}({args_str}): {result_type_converter.type_name.kotlin} {{"
    file_scope['body'].add(
        header,
        Scope(
            *body,
            tab=1
        ),
        "}",
        "\n",
    )
    build_jni_func(ctx, builder)


def gen_setter(ctx, builder):
    breakpoint()
    pass
