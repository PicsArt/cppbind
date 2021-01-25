from iegen.builder.out_builder import Scope
# from iegen import context_of_type


def gen_class(ctx, builder):
    # get or create logical file
    file_path = f"local_expr/{ctx.lang}_test.h"  # path
    scope = builder.get_file(ctx.file, file_path)  # .get_scope(ctx.module, True)
    scope.add(
        f"module={ctx.module}",
        f"class {ctx.name} {{",
        Scope(name="enum", tab=1),
        Scope(name="class_body", tab=1),
        Scope(name="class_constructors", tab=1),
        "}",
        )
    # print(ctx.type) # class
    # print(ctx.shared_ref) # False
    # print(ctx.module) # pi.xxx
    # print(ctx.file) # pi.utils
    # print(ctx.name) # Example


# def gen_module(ctx, builder):
    # # get or create logical file
    # file_path = f"local_expr/{ctx.lang}_test.h"  # path
    # builder.get_file(ctx.file, file_path).get_scope("module", True).add(
    # Scope(name="enum", tab = 1)
    # )


def gen_enum(ctx, builder):
    file_path = f"local_expr/{ctx.lang}_test.h"  # path
    scope = builder.get_file(ctx.file, file_path)  # .get_scope(ctx.module, True)

    scope.get_scope("enum", True).add(
        f"module={ctx.module}",
        f"enum {ctx.name} ",
        f"{ctx.enum_values}",
    )
    pass
    # print(ctx.type) # enum
    # print(ctx.module) # pi.xxx.Example
    # print(ctx.file) # pi.utils
    # print(ctx.name) # Type

    # print(ctx.type) # enum_case
    # print(ctx.name) # A
    # print(ctx.value) # 0


def gen_constructor(ctx, builder):
    builder.get_scope("class_constructors").add(
        f"module={ctx.module}",
        f"void {ctx.name}() ",
        f"{ctx.args}",
    )

    pass
    # print(ctx.type) # constuctor
    # print(ctx.name) # Example
    # print(ctx.args)
    # [{'name': 'x', 'type': 'int', 'ptr': None},
    #  {'name':'t', 'type': 'Type', 'ptr': 'shared'},
    #  {'name': 'name', 'type': 'std::string', 'default': 'XXX', 'ptr': None}]
    # print(ctx.parent.shared_ref)  # False


def gen_method(ctx, builder):
    # get or create logical file

    result_context = ctx.find_by_type_spelling(ctx.result_type)
    builder.get_scope("class_body").add(
        f"module={ctx.module}",
        f"{result_context and result_context.cursor.type.spelling} {ctx.name}({ctx.args}) ",
    )
    pass
    # print(ctx.type) # method
    # print(ctx.name) # f
    # print(ctx.args) # [{'name':'t', 'type': 'Type', 'ptr': 'raw'}]
    # print(ctx.returns) # {'type': 'Type', 'ptr': 'None'}

    # print(context_of_type(ctx.returns['type']).type) # enum
