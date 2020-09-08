import os
from iegnen.builder.out_builder import Scope

builtin_type = {
    'int': 'Int',
    'short': 'Short',
    'long': 'Long',
    'unsigned long': 'Long',
    'float': 'Float',
    'double': 'Double',
    'char': 'String',
    'std::__cxx11::basic_string': 'String',
    'std::vector': 'List<{0}>',
    'std::map': 'Map<{0}, {1}>',
    'std::shared_ptr': '{0}',
}


def _lookup_kt_type_name(ctx, unqualified_name):
    ref_ctx = ctx.find_by_type(unqualified_name)
    if ref_ctx is None:
        name = builtin_type.get(unqualified_name, None)
    else:
        name = ref_ctx.name
    return name


def lookup_kt_type(ctx, type_ctx, rise_error=True):
    unqualified_name = type_ctx.unqualified_name
    name = _lookup_kt_type_name(ctx, unqualified_name)

    if name is None:
        if type_ctx.pointee_type != type_ctx:
            return lookup_kt_type(ctx, type_ctx.pointee_type)
        else:
            if type_ctx.canonical_type != type_ctx:
                return lookup_kt_type(ctx, type_ctx.canonical_type)
        if type_ctx.is_template:
            tmpl_format = _lookup_kt_type_name(ctx, type_ctx.template_type_name)
            if tmpl_format is not None:
                return tmpl_format.format(
                    *[lookup_kt_type(ctx, arg_type, False) for arg_type in type_ctx.template_argument_types]
                )
        if rise_error:
            raise KeyError(f"Can not find type for {type_ctx.name}")
    return name


def build_arg_str(ctx, arg):
    arg_str = arg['name'] + ': ' + lookup_kt_type(ctx, arg['type'])
    if 'default' in arg:
        val = arg['default']
        if val in ['nullptr', 'NULL']:
            arg_str += '? = null'
        else:
            arg_str += " = " + val
    return arg_str


def build_args_str(ctx, args=None):
    args = args or [build_arg_str(ctx, arg) for arg in ctx.args]
    if args:
        args = '\n' + str(Scope(*args, tab=1, parts_spliter=',\n')) + '\n'
    else:
        args = ''
    return args


def get_file(ctx, builder):
    run_dir = "example_lib/"
    project_dir = "android/example_lib/"
    src_dir = "source/main/java/"
    package_prefix = "com.picsart.example_lib"

    module_dir = os.path.join(package_prefix, ctx.package).replace('.', os.sep)
    file_path = os.path.join(run_dir, project_dir, src_dir, module_dir, ctx.file + '.kt')
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


def gen_class(ctx, builder):
    # get or create logical file
    file_scope = get_file(ctx, builder)
    file_scope['body'].add(
        f"class {ctx.name}",
        Scope(name="main_constructor", tab=1),
        "{",
        Scope(name="head", tab=1),
        Scope(name="body", tab=1),
        "}",
        "\n",
    )
    base_type = lookup_kt_type(ctx, ctx.base_types[0]) if ctx.base_types else "RNativeParcelableObject"
    file_scope["main_constructor"].add(
        f"internal constructor(id: Long): {base_type}(id)")


def gen_constructor(ctx, builder):
    file_scope = get_file(ctx, builder)

    args = build_args_str(ctx, ["id: Long"] + [build_arg_str(ctx, arg) for arg in ctx.args])

    header = f"constructor({args}): this(id) {{"
    body = f"test code for {ctx.name}"

    file_scope['head'].add(
        header,
        Scope(body, tab=1),
        "}",
        "\n",
    )


def gen_enum(ctx, builder):
    file_scope = get_file(ctx, builder)
    file_scope['body'].add(
        f"enum class {ctx.name}{{",
        Scope(*[f"{case['name']}({case['value']})" for case in ctx.enum_values], parts_spliter=',\n', tab=1),
        "}",
        "\n",
    )


def gen_method(ctx, builder):
    file_scope = get_file(ctx, builder)

    args = build_args_str(ctx)
    result = lookup_kt_type(ctx, ctx.result_type)
    header = f"fun {ctx.name}({args}): {result} {{"
    body = f"test code for {ctx.name}"

    file_scope['body'].add(
        header,
        Scope(body, tab=1),
        "}",
        "\n",
    )
