# from iegnen import context_of_type

def gen_class(ctx, builder):
    pass
    # print(ctx.type) # class
    # print(ctx.shared_ref) # False
    # print(ctx.module) # pi.xxx
    # print(ctx.file) # pi.utils
    # print(ctx.name) # Example


def gen_enum(ctx, builder):
    pass
    # print(ctx.type) # enum
    # print(ctx.module) # pi.xxx.Example
    # print(ctx.file) # pi.utils
    # print(ctx.name) # Type


def gen_enum_case(ctx, builder):
    pass
    # print(ctx.type) # enum_case
    # print(ctx.name) # A
    # print(ctx.value) # 0


def gen_constructor(ctx, builder):
    pass
    # print(ctx.type) # constuctor
    # print(ctx.name) # Example
    # print(ctx.args)
    # [{'name': 'x', 'type': 'int', 'ptr': None},
    #  {'name':'t', 'type': 'Type', 'ptr': 'shared'},
    #  {'name': 'name', 'type': 'std::string', 'default': 'XXX', 'ptr': None}]
    # print(ctx.parent.shared_ref)  # False


def gen_method(ctx, builder):
    pass
    # print(ctx.type) # method
    # print(ctx.name) # f
    # print(ctx.args) # [{'name':'t', 'type': 'Type', 'ptr': 'raw'}]
    # print(ctx.returns) # {'type': 'Type', 'ptr': 'None'}

    # print(context_of_type(ctx.returns['type']).type) # enum
