import os
from iegnen.builder.out_builder import Scope


def lookup_kt_type(ctx, type_name):
    return type_name


def build_arg_str(ctx, arg):
    arg_str = arg['name'] + ': ' + lookup_kt_type(ctx, arg['type'])
    if 'default' in arg:
        arg_str += "? = " + arg['default']
        return arg_str


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
        f"class {ctx.name} internal constructor(id: Long): NativeParcelabObject(id){{",
        Scope(name="head", tab=1),
        Scope(name="body", tab=1),
        "}",
        "\n",
    )


def gen_constructor(ctx, builder):
    pass
    # print(ctx.type) # constuctor
    # print(ctx.name) # Example
    # print(ctx.args)
    # [{'name': 'x', 'type': 'int', 'ptr': None},
    #  {'name':'t', 'type': 'Type', 'ptr': 'shared'},
    #  {'name': 'name', 'type': 'std::string', 'default': 'XXX', 'ptr': None}]
    # print(ctx.parent.shared_ref)  # False


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

    args = [build_arg_str(ctx, arg) for arg in ctx.args]
    if args:
        args = '\n' + str(Scope(*args, tab=1, parts_spliter=',\n')) + '\n'
    else:
        args = ''

    result = lookup_kt_type(ctx, ctx.result_type)
    header = f"fun {ctx.name}({args}): {result} {{"
    body = f"test code for {ctx.name}"

    file_scope['body'].add(
        header,
        Scope(body, tab=1),
        "}",
        "\n",
    )
