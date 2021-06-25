"""
"""
import itertools
import json
import os
import types

import clang.cindex as cli
import iegen.utils.clang as cutil
from iegen import logging as logging
from iegen.ir.ast import NodeType, Node
from iegen.utils.clang import extract_pure_comment


class BaseContext:
    def __init__(self, runner, node=None):
        self.runner = runner
        self.node = node or runner.ir

    def __getattr__(self, name):
        val = self.node.args.get(name, None)
        if val is None:
            raise AttributeError(f"{self.__class__.__name__}.{name} is invalid.\
    API has no '{name}' attribute for {self.node.displayname}.")
        return val


class Context(BaseContext):

    def __init__(self, runner, node, template_ctx=None):
        super().__init__(runner, node)
        if node.type == NodeType.CLANG_NODE:
            assert node.clang_cursor, "cursor is not provided"
        self.template_ctx = template_ctx

    @property
    def kind_name(self):
        return self.node.kind_name

    @property
    def args(self):

        _args = []

        def get_default(param_var):
            # todo implementation is odd for now
            assert param_var.kind == cli.CursorKind.PARM_DECL
            val = None
            if cutil.get_pointee_type(param_var.type).kind == cli.TypeKind.ENUM:
                for def_curs in param_var.walk_preorder():
                    if def_curs.kind == cli.CursorKind.DECL_REF_EXPR:
                        for token in def_curs.get_tokens():
                            if token.cursor.kind == cli.CursorKind.DECL_REF_EXPR and token.kind != cli.TokenKind.PUNCTUATION:
                                return token.spelling
            for def_curs in param_var.walk_preorder():
                if def_curs.kind in [
                    cli.CursorKind.INTEGER_LITERAL,
                    cli.CursorKind.FLOATING_LITERAL,
                    cli.CursorKind.IMAGINARY_LITERAL,
                    cli.CursorKind.STRING_LITERAL,
                    cli.CursorKind.CHARACTER_LITERAL,
                    cli.CursorKind.CXX_NULL_PTR_LITERAL_EXPR,
                    cli.CursorKind.GNU_NULL_EXPR,
                    cli.CursorKind.NULL_STMT,
                ]:
                    if def_curs.kind == cli.CursorKind.GNU_NULL_EXPR:
                        val = 'NULL'
                    else:
                        val = next(def_curs.get_tokens(), None)
                        if val:
                            val = val.spelling
            return val

        # for function templates Cursor.get_arguments returns an empty array, using Type.argument_types instead
        if self.node.is_function_template:
            for i, arg_type in enumerate(self.node.clang_cursor.type.argument_types()):
                arg_params = types.SimpleNamespace(name=f'arg{i}',
                                                   type=arg_type,
                                                   cursor=None,
                                                   default=None)
                _args.append(arg_params)
        else:
            for arg_c in self.node.clang_cursor.get_arguments():
                def_val = get_default(arg_c)
                arg_params = types.SimpleNamespace(name=arg_c.spelling,
                                                   type=arg_c.type,
                                                   cursor=arg_c,
                                                   default=def_val)
                _args.append(arg_params)

        return _args

    @property
    def result_type(self):

        if self.node.clang_cursor.kind not in [cli.CursorKind.CXX_METHOD, cli.CursorKind.FUNCTION_DECL,
                                               cli.CursorKind.FUNCTION_TEMPLATE]:
            raise AttributeError(f"{self.__class__.__name__}.returns is invalid.")
        return self.node.clang_cursor.result_type

    @property
    def overloading_prefix(self):
        if self.node.clang_cursor.kind not in [cli.CursorKind.CXX_METHOD, cli.CursorKind.FUNCTION_DECL,
                                               cli.CursorKind.CONSTRUCTOR, cli.CursorKind.FUNCTION_TEMPLATE]:
            raise AttributeError(f"{self.__class__.__name__}.setter is invalid.")

        if not hasattr(self, '_overloading_prefix'):
            search_api = self.node.api
            name = self.name
            search_names = {name}
            overloads = self.find_adjacents(search_names, search_api)
            _overloading_prefix = ''
            for i, ctx in enumerate(overloads):
                if ctx == self:
                    _overloading_prefix = f'_{i}' if i != 0 else ''
                    break

        return _overloading_prefix

    @property
    def setter(self):
        if self.node.api != 'gen_getter':
            raise AttributeError(f"{self.__class__.__name__}.setter is invalid.")

        search_api = 'gen_setter'
        name = self.name
        if name.lower().startswith('get'):
            name = name[3:].lstrip('_')
        search_names = {f"set_{name}", "set" + name[:1].upper() + name[1:],
                        'set' + ''.join(map(lambda n: n.capitalize(), name.split('_')))}
        return self.find_adjacent(search_names, search_api)

    @property
    def getter(self):
        if self.node.api != 'gen_setter':
            raise AttributeError(f"{self.__class__.__name__}.setter is invalid.")

        search_api = 'gen_getter'
        name = self.name
        if name.lower().startswith('set'):
            name = name[3:].lstrip('_')
        search_names = {f"get_{name}", "get" + name[:1].upper() + name[1:],
                        name, name[:1].lower() + name[1:]}
        return self.find_adjacent(search_names, search_api)

    @property
    def base_types(self):

        if self.node.clang_cursor.kind not in [cli.CursorKind.STRUCT_DECL, cli.CursorKind.CLASS_DECL,
                                               cli.CursorKind.CLASS_TEMPLATE]:
            raise AttributeError(f"{self.__class__.__name__}.base_type is invalid.")

        return [
            base_specifier.type
            for base_specifier in self.base_types_specifier_cursor
        ]

    @property
    def ancestors(self):

        if self.node.clang_cursor.kind not in [cli.CursorKind.STRUCT_DECL,
                                               cli.CursorKind.CLASS_DECL,
                                               cli.CursorKind.CLASS_TEMPLATE]:
            raise AttributeError(f"{self.__class__.__name__}.ancestors is invalid.")

        def walk(base_types):
            for base in base_types:
                base = self.find_by_type(base)
                for _base in walk(base.base_types):
                    yield _base
                yield base

        _ancestors = [b for b in walk(self.base_types)]

        return _ancestors

    @property
    def root(self):

        _ancestors = self.ancestors + [self]

        return _ancestors[0]

    @property
    def base_types_specifier_cursor(self):

        if self.node.clang_cursor.kind not in [cli.CursorKind.STRUCT_DECL,
                                               cli.CursorKind.CLASS_DECL,
                                               cli.CursorKind.CLASS_TEMPLATE]:
            raise AttributeError(f"{self.__class__.__name__}.base_type is invalid.")
        base_types_cursor = []

        for base_specifier in self.node.clang_cursor.get_children():
            # check if base type also has a context
            if base_specifier.kind == cli.CursorKind.CXX_BASE_SPECIFIER and self.find_by_type(base_specifier.type):
                base_types_cursor.append(base_specifier)
        return base_types_cursor

    @property
    def cursor(self):
        return self.node.clang_cursor

    @property
    def enum_values(self):

        if self.node.clang_cursor.kind not in [cli.CursorKind.ENUM_DECL]:
            raise AttributeError(f"{self.__class__.__name__}.enum_values is invalid.")

        _vals = []

        last_case_comment = None
        for enum_value_c in self.node.clang_cursor.walk_preorder():
            if enum_value_c.kind != cli.CursorKind.ENUM_CONSTANT_DECL:
                continue
            type_name = enum_value_c.kind.name.lower().replace("_decl", "")
            if enum_value_c.raw_comment != last_case_comment:
                comment = extract_pure_comment(enum_value_c.raw_comment)
            elif last_case_comment:
                comment = ['', 'The Same as previous case comment.', '']
            else:
                comment = None
            last_case_comment = enum_value_c.raw_comment
            enum_val_params = types.SimpleNamespace(name=enum_value_c.spelling, type=type_name,
                                                    value=enum_value_c.enum_value, comment=comment)

            _vals.append(enum_val_params)
        return _vals

    @property
    def parent_context(self):
        return self.runner.get_context(self.node.parent.full_displayname)

    @property
    def namespace(self):
        namespaces = []
        parent = self.node.parent
        while cli.CursorKind.NAMESPACE == parent.clang_cursor.kind:
            namespaces.append(parent.spelling)
            parent = parent.parent
        return '::'.join(reversed(namespaces))

    @property
    def prj_rel_file_name(self):
        if not hasattr(self, '_prj_rel_file_name'):
            self._prj_rel_file_name = os.path.relpath(self.cursor.location.file.name, self.out_prj_dir)
        return self._prj_rel_file_name

    @property
    def api_args(self):
        if not hasattr(self, '_api_args'):
            self._api_args = self.node.args
        return self._api_args

    @property
    def template_includes(self):
        """
        Returns list of generated cxx imports based on template arguments values.

        Returns:
            list(str): List containing includes.
        """
        template_arg = self.node.args.get('template', None)
        includes = []
        if template_arg:
            template_arg = itertools.chain(*template_arg.values())
            for t in template_arg:
                ctx = self.find_by_type(t['type'])
                if ctx:
                    includes.append(os.path.relpath(ctx.node.clang_cursor.location.file.name,
                                                    self.out_prj_dir))
        return includes

    @property
    def template_type_parameters(self):
        return [child.type.spelling for child in self.cursor.get_children() if
                child.kind == cli.CursorKind.TEMPLATE_TYPE_PARAMETER]

    def find_by_type(self, search_type):
        search_name = search_type
        if isinstance(search_type, cli.Type):
            # getting canonical for template base types
            return self.find_by_type(cutil.template_type_name(search_type)) or \
                   self.find_by_type(cutil.template_type_name(search_type.get_canonical()))
        return self.runner.get_context(search_name)

    def find_adjacent(self, search_names, search_api=None):
        return next(self.find_adjacents(search_names, search_api), None)

    def find_adjacents(self, search_names, search_api=None):
        return (self.find_by_type(node.full_displayname) for node in self.node.parent.children
                if (search_api is None or node.api == search_api)
                and node.spelling in search_names)

    def set_template_ctx(self, template_ctx):
        self.template_ctx = template_ctx

    @property
    def template_choice(self):
        return self.template_ctx['choice'] if self.template_ctx else None

    @property
    def template_names(self):
        return self.template_ctx['names'] if self.template_ctx else None


class RunRule(object):

    def __init__(self, ir, ctx_desc, platform, language):
        self.ir = ir
        self.ctx_desc = ctx_desc
        self.language = language
        self.platform = platform
        # calling order should be such as that parent node processes first
        self.api_call_order = [
            # {'gen_class', 'gen_interface', 'gen_enum'},
            # {'gen_constructor'},
            # {'gen_method'},
            # {'gen_getter'},
            # {'gen_setter'},
            {}
        ]

    def run(self, rule, builder):  # noqa: C901

        # running order is defined by type of node
        # at first we run nodes for namespace/class/enums and then for methods

        # walk is traversing in dept first order
        self.allocate_all_contexts()

        # init all rules
        init_att_name = "gen_init"
        logging.debug(f"Initialising rule for {self.language} for {self.platform} platform.")
        func = getattr(rule, init_att_name)
        if func:
            func(BaseContext(self), self.ctx_desc)

        # executes once for a type
        processed = dict()
        for calling_api in self.api_call_order:
            logging.debug(f"Calling APIs: {calling_api}")

            def _run_recursive(node, template_ctx=None):
                stack_added = False
                node_key = self.__node_key(node, template_ctx)
                if node.api and (not calling_api or node.api in calling_api) and node_key not in processed:
                    ancestor = node.ancestor_with_api
                    ancestor_key = self.__node_key(ancestor, template_ctx)
                    if ancestor_key in processed:
                        # for already called api resume builders scope stack
                        logging.debug(f"Restoring stack for {ancestor.displayname}.")
                        builder.restore_stacks(processed[ancestor_key])
                        logging.debug(
                            f"Restored stack {self.__str_stacks(processed[ancestor_key])}."
                        )
                    # allocate scope
                    if node.type == NodeType.CLANG_NODE:
                        stack_added = True
                        builder.add_scope_stack()

                    # call api
                    self.call_api(rule, node, builder, template_ctx)
                    logging.debug(f"Capturing stack for {node.displayname}.")
                    processed[node_key] = builder.capture_stacks()
                    logging.debug(f"Captured stack {self.__str_stacks(processed[node_key])}.")

                if node.children:
                    logging.debug(f"Processing children for {node.displayname}.")
                    for child in node.children:
                        if child.type == NodeType.CLANG_NODE:
                            # check if the node is template and generate code for each combination of template args
                            if child.clang_cursor.kind in [cli.CursorKind.CLASS_TEMPLATE, cli.CursorKind.FUNCTION_TEMPLATE]:
                                parent_template = node.args.get('template', None)
                                template_arg = {}
                                # if parent also has a template argument join with child´s
                                if parent_template:
                                    template_arg = template_arg.update(parent_template)
                                template_arg.update(child.args['template'])
                                all_possible_args = list(itertools.product(*template_arg.values()))
                                template_keys = child.args['template'].keys()
                                for i, combination in enumerate(all_possible_args):
                                    choice = [item['type'] for item in combination]
                                    choice_names = [item['name'] for item in combination if 'name' in item]
                                    _template_choice = dict(zip(template_keys, choice))
                                    _template_ctx = {'choice': _template_choice, 'names': choice_names}
                                    _run_recursive(child, _template_ctx)
                            else:
                                _run_recursive(child, template_ctx)
                        else:
                            _run_recursive(child, template_ctx)
                    logging.debug(f"End processing children for {node.displayname}.")

                if stack_added:
                    builder.pop_scope_stack()

            # create common scope for entire ir
            # we have to add this scope to be able to allow write into single file from multiple roots
            # since we do not have gen api for file
            # we register file and add one scope
            builder.add_scope_stack()

            _run_recursive(self.ir)

            builder.pop_scope_stack()

    def call_api(self, rule, node, builder, template_ctx=None):
        api = node.api
        if api == Node.API_NONE:
            return
        logging.debug(f"Call API: {api.lstrip('gen_')} on {node.displayname}")
        func = getattr(rule, api)
        context = self.get_context(node.full_displayname)
        # set current template context to generate code based on correct template choice
        context.set_template_ctx(template_ctx)
        func(context, builder)

    def create_context(self, node):
        assert node is not None
        if node.api:
            return self.all_contexts.setdefault(node.full_displayname,
                                                Context(self, node))
        return None

    def get_context(self, type_name):

        return self.all_contexts.get(type_name, None)

    def allocate_all_contexts(self):
        logging.debug("Allocating context for all nodes")
        self.all_contexts = dict()
        for node in self.ir.walk():
            self.create_context(node)

    def __node_key(self, node, template_ctx):
        node_key = (node,)
        if node and node.type == NodeType.CLANG_NODE and node.is_template:
            node_key = (node, json.dumps(template_ctx))
        return node_key

    def __str_stacks(self, capture_data):
        # first lang stack data
        stack_data = capture_data
        return f"{[s.keys() for fs in stack_data.values() for s in fs]}"
