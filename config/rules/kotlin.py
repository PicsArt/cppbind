import os
from iegnen.builder.out_builder import Scope
import iegnen.converter.kotlin as convert


def kt_arg_str(type_name, name, default=None, **kwargs):
    arg_str = name + ': ' + type_name
    if default:
        val = default
        if val in ['nullptr', 'NULL']:
            arg_str += '? = null'
        else:
            arg_str += " = " + val
    return arg_str


def kt_jni_arg_str(type_name, name, **kwargs):
    arg_str = name + ': ' + type_name
    return arg_str


def cxx_jni_arg_str(type_name, name, **kwargs):
    arg_str = type_name + ' ' + name
    return arg_str


def format_args_str(args):
    if args:
        args = '\n' + str(Scope(*args, tab=1, parts_spliter=',\n')) + '\n'
    else:
        args = ''
    return args


def jni_func_name(ctx):
    return f'j{ctx.name.capitalize()}'


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

        arg_scope.add(cxx_jni_arg_str(type_name=type_converter.type_name.jni, **arg))
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
    method_name = jni_func_name(ctx).replace("_", "_1")

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
            "return pi::handleNativeCrash(env, [&] {",
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

        arg = kt_jni_arg_str(type_name=type_converter.type_name.native, **arg)
        arg_scope.add(arg)

    args_str = '\n' + str(arg_scope) + '\n' if arg_scope else ''

    result_type_converter = convert.build_type_converter(ctx, ctx.result_type)
    # TODO for complex type use id for builtin use directly
    jni_func = f"{jni_func_name(ctx)}({args_str}): {result_type_converter.type_name.native}"

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

        arg_scope.add(cxx_jni_arg_str(type_name=type_converter.type_name.jni, **arg))
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
            "return pi::handleNativeCrash(env, [&] {",
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

        arg = kt_jni_arg_str(type_name=type_converter.type_name.native, **arg)
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
    file_scope = builder.get_file(file_path)

    file_scope["include_cxx"].add_unique(
        convert.CXX_INCLUDES,
        "\n",
    )
    file_scope["typedefs_cxx"].add_unique(
        convert.CXX_OBJECT_MAP_DEF_SNIPPED,
        convert.CXX_OBJECT_OBJID_DEF_SNIPPED,
        convert.CXX_HELPERS,
        "\n",
    )

    file_scope.get_scope('body_cxx', create=True)

    return file_scope


def get_file(ctx, builder):
    out_dir = ctx.config.out_dir
    package_prefix = ctx.config.package_prefix

    module_dir = os.path.join(package_prefix, ctx.package).replace('.', os.sep)
    file_path = os.path.join(out_dir, module_dir, ctx.file + '.kt')
    file_scope = builder.get_file(file_path)
    file_scope["package"].add_unique(
        f"package {package_prefix}.{ctx.package}",
        "\n",
    )

    file_scope["include"].add_unique(
        *[f"import {imp}" for imp in ctx.include],
        "\n",
    )

    file_scope.get_scope('body', create=True)

    return file_scope


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

        arg_scope.add(kt_arg_str(type_name=type_converter.type_name.kotlin, **arg))
        # now add conversion code into body if needed
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

        arg_scope.add(kt_arg_str(type_name=type_converter.type_name.kotlin, **arg))
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
    body.append(f"val result = {jni_func_name(ctx)}({', '.join(jni_call_args)});")
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
