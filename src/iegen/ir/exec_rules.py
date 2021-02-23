"""
"""
import itertools
import json
import os
import types
import clang.cindex as cli
from iegen import logging as logging
from iegen.utils.clang import extract_pure_comment
import iegen.utils.clang as cutil


class Context(object):

    def __init__(self, runner, node, template_choice=None):
        assert node.clang_cursor, "cursor is not provided"
        self.runner = runner
        self.config = runner.config
        self.node = node
        self.template_choice = template_choice

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
            oveloads = self.find_adjacents(search_names, search_api)
            self._overloading_prefix = ''
            for i, ctx in enumerate(oveloads):
                if ctx == self:
                    self._overloading_prefix = f'_{i}' if i != 0 else ''
                    break

        return self._overloading_prefix

    @property
    def setter(self):
        if self.node.api != 'getter':
            raise AttributeError(f"{self.__class__.__name__}.setter is invalid.")

        search_api = 'setter'
        name = self.name
        if name.lower().startswith('get'):
            name = name[3:].lstrip('_')
        search_names = {f"set_{name}", "set" + name[:1].upper() + name[1:]}
        return self.find_adjacent(search_names, search_api)

    @property
    def getter(self):
        if self.node.api != 'setter':
            raise AttributeError(f"{self.__class__.__name__}.setter is invalid.")

        search_api = 'getter'
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

        if self.node.clang_cursor.kind not in [cli.CursorKind.STRUCT_DECL, cli.CursorKind.CLASS_DECL,
                                               cli.CursorKind.CLASS_TEMPLATE]:
            raise AttributeError(f"{self.__class__.__name__}.ancestors is invalid.")

        def walk(base_types):
            for base in base_types:
                base = self.find_by_type(base)
                yield base
                for base in walk(base.base_types):
                    yield base

        _ancestors = [b for b in walk(self.base_types)]

        return _ancestors

    @property
    def base_types_specifier_cursor(self):

        if self.node.clang_cursor.kind not in [cli.CursorKind.STRUCT_DECL, cli.CursorKind.CLASS_DECL,
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
    def prj_rel_file_name(self):
        if not hasattr(self, '_prj_rel_file_name'):
            self._prj_rel_file_name = os.path.relpath(self.cursor.location.file.name, self.runner.config.out_prj_dir)
        return self._prj_rel_file_name

    @property
    def api_args(self):
        if not hasattr(self, '_api_args'):
            self._api_args = {name: values[self.runner.language] for name, values in self.node.args.items()}
        return self._api_args

    @property
    def template_includes(self):
        """
        Returns list of generated cxx imports based on template arguments values.

        Returns:
            list(str): List containing includes.
        """
        template_arg = self.node.args.get('template', None)
        includes = set()
        if template_arg:
            template_arg = itertools.chain(*template_arg[self.runner.language].values())
            for t in template_arg:
                ctx = self.find_by_type(t)
                if ctx:
                    includes.add(os.path.relpath(ctx.node.clang_cursor.location.file.name,
                                                 self.runner.config.out_prj_dir))
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

    def set_template_choice(self, template_choice):
        self.template_choice = template_choice

    def __getattr__(self, name):
        val = self.node.args.get(name, None)
        if val is None:
            raise AttributeError(f"{self.__class__.__name__}.{name} is invalid.\
 API has no '{name}' attribute for {self.node.displayname}.")
        val = val.get(self.runner.language, None)
        if val is None:
            raise AttributeError(f"{self.__class__.__name__}.{name} is invalid. API has no '{name}'\
                                    attribute for language {self.runner.language}.")
        return val


class RunRule(object):

    def __init__(self, ir, language, config):
        self.ir = ir
        self.language = language
        self.config = config
        # calling order should be such as that parent node processes first
        self.api_call_order = [
            # {'class', 'interface', 'enum'},
            # {'constructor'},
            # {'method'},
            # {'getter'},
            # {'setter'},
            {}
        ]

    def run(self, rule, builder):  # noqa: C901

        # running order is defined by type of node
        # at first we run nodes for namespace/class/enums and then for methods

        # walk is traversing in dept first order
        self.allocate_all_contexts()

        # init all rules
        init_att_name = "gen_init"
        logging.debug(f"Initialising rule for {self.language}.")
        func = getattr(rule, init_att_name)
        if func:
            func(self.config, builder)

        # executes once for a type
        processed = dict()
        for calling_api in self.api_call_order:
            logging.debug(f"Calling APIs: {calling_api}")

            def _run_recursive(node, template_choice=None):
                stack_added = False
                node_key = (node, json.dumps(template_choice))
                if node.api and (not calling_api or node.api in calling_api) and node_key not in processed:
                    ancestor = node.ancestor_with_api
                    ancestor_key = (ancestor, json.dumps(template_choice))
                    if ancestor_key in processed:
                        # for already called api resume builders scope stack
                        logging.debug(f"Restoring stack for {ancestor.displayname}.")
                        builder.restore_stacks(processed[ancestor_key])
                        logging.debug(
                            f"Restored stack {self.__str_stacks(processed[ancestor_key])}."
                        )
                    # allocate scope
                    stack_added = True
                    builder.add_scope_stack()

                    # call api
                    self.call_api(rule, node, builder, template_choice)
                    logging.debug(f"Capturing stack for {node.displayname}.")
                    processed[node_key] = builder.capture_stacks()
                    logging.debug(f"Captured stack {self.__str_stacks(processed[node_key])}.")

                if node.children:
                    logging.debug(f"Processing children for {node.displayname}.")
                    for child in node.children:
                        # check if the node is template and generate code for each combination of template args
                        if child.clang_cursor.kind in [cli.CursorKind.CLASS_TEMPLATE, cli.CursorKind.FUNCTION_TEMPLATE]:
                            parent_template = node.args.get('template', None)
                            template_arg = {}
                            # if parent also has a template argument join with child´s
                            if parent_template:
                                template_arg = template_arg.update(parent_template[self.language])
                            template_arg.update(child.args['template'][self.language])
                            all_possible_args = list(itertools.product(*template_arg.values()))
                            template_keys = child.args['template'][self.language].keys()
                            for i, choice in enumerate(all_possible_args):
                                _template_choice = dict(zip(template_keys, choice))
                                _run_recursive(child, _template_choice)
                        else:
                            _run_recursive(child, template_choice)
                    logging.debug(f"End processing children for {node.displayname}.")

                if stack_added:
                    builder.pop_scope_stack()

            # create common scope for entire ir
            # we have to add this scope to be able to allow write into single file from multiple roots
            # since we do not have gen api for file
            # we register file and add one scope
            builder.add_scope_stack()

            for root in self.ir.roots:
                _run_recursive(root)

            builder.pop_scope_stack()

    def call_api(self, rule, node, builder, template_choice=None):
        api = node.api
        att_name = "gen_" + api
        logging.debug(f"Call API: {api} on {node.displayname}")
        func = getattr(rule, att_name)
        context = self.get_context(node.full_displayname)
        # set current template choice to generate code based on correct template choice
        context.set_template_choice(template_choice)
        func(context, builder)

    def create_context(self, node):
        assert node is not None
        cntx = self.all_contexts.setdefault(node.full_displayname,
                                            Context(self, node))
        return cntx

    def get_context(self, type_name):

        cntx = self.all_contexts.get(type_name, None)
        return cntx

    def allocate_all_contexts(self):
        logging.debug("Allocating context for all nodes")
        self.all_contexts = dict()
        for node in self.ir.walk():
            self.create_context(node)

    def __str_stacks(self, capture_data):
        # first lang stack data
        stack_data = capture_data
        return f"{[s.keys() for fs in stack_data.values() for s in fs]}"
