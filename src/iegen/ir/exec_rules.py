"""
"""
import os
import types
import clang.cindex as cli
from iegen import logging as logging


class Context(object):

    def __init__(self, runner, node):
        assert node.clang_cursor, "cursor is not provided"
        self.runner = runner
        self.config = runner.config
        self.node = node

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

        for arg_c in self.node.clang_cursor.get_arguments():
            def_val = get_default(arg_c)
            arg_params = types.SimpleNamespace(name=arg_c.spelling,
                                               type=arg_c.type,
                                               cursor=arg_c,
                                               default=def_val
                                               )
            _args.append(arg_params)

        return _args

    @property
    def result_type(self):

        if self.node.clang_cursor.kind not in [cli.CursorKind.CXX_METHOD, cli.CursorKind.FUNCTION_DECL]:
            raise AttributeError(f"{self.__class__.__name__}.returns is invalid.")
        return self.node.clang_cursor.result_type

    @property
    def overloading_prefix(self):
        if self.node.clang_cursor.kind not in [cli.CursorKind.CXX_METHOD, cli.CursorKind.FUNCTION_DECL,
                                               cli.CursorKind.CONSTRUCTOR]:
            raise AttributeError(f"{self.__class__.__name__}.setter is invalid.")

        if not hasattr(self, '_overloading_prefix'):
            search_api = self.node.api
            name = self.name
            search_names = {name}
            oveloads = self.find_adjacents(search_names, search_api)
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

        if self.node.clang_cursor.kind not in [cli.CursorKind.STRUCT_DECL, cli.CursorKind.CLASS_DECL]:
            raise AttributeError(f"{self.__class__.__name__}.base_type is invalid.")

        return [
            base_specifier.type
            for base_specifier in self.base_types_specifier_cursor
        ]

    @property
    def ancestors(self):

        if self.node.clang_cursor.kind not in [cli.CursorKind.STRUCT_DECL, cli.CursorKind.CLASS_DECL]:
            raise AttributeError(f"{self.__class__.__name__}.ancestors is invalid.")

        def walk(base_types):
            for base in base_types:
                base = self.find_by_type(base.spelling)
                yield base
                for base in walk(base.base_types):
                    yield base

        _ancestors = [b for b in walk(self.base_types)]

        return _ancestors

    @property
    def base_types_specifier_cursor(self):

        if self.node.clang_cursor.kind not in [cli.CursorKind.STRUCT_DECL, cli.CursorKind.CLASS_DECL]:
            raise AttributeError(f"{self.__class__.__name__}.base_type is invalid.")

        bases_types = []
        non_abstract_bases = 0
        for base_specifier in self.node.clang_cursor.get_children():
            if base_specifier.kind == cli.CursorKind.CXX_BASE_SPECIFIER:
                bases_types.append(base_specifier)
                if base_specifier.is_abstract_record():
                    non_abstract_bases += 1

        if non_abstract_bases > 1:
            raise AttributeError(f"{self.__class__.__name__} has more than 1 non abstract bases.")

        return bases_types

    @property
    def cursor(self):
        return self.node.clang_cursor

    @property
    def enum_values(self):

        if self.node.clang_cursor.kind not in [cli.CursorKind.ENUM_DECL]:
            raise AttributeError(f"{self.__class__.__name__}.enum_values is invalid.")

        _vals = []

        for enum_value_c in self.node.clang_cursor.walk_preorder():
            if enum_value_c.kind != cli.CursorKind.ENUM_CONSTANT_DECL:
                continue
            type_name = enum_value_c.kind.name.lower().replace("_decl", "")
            enum_val_params = types.SimpleNamespace(name=enum_value_c.spelling, type=type_name,
                                                    value=enum_value_c.enum_value)

            _vals.append(enum_val_params)
        return _vals

    @property
    def parent_context(self):
        return self.runner.get_context(self.node.parent.type_name)

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

    def find_by_type(self, search_type):
        return self.runner.get_context(search_type)

    def find_adjacent(self, search_names, search_api=None):
        return next(self.find_adjacents(search_names, search_api), None)

    def find_adjacents(self, search_names, search_api=None):
        return (self.find_by_type(node.full_displayname) for node in self.node.parent.children
                if (search_api is None or node.api == search_api)
                and node.spelling in search_names)

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
            {'class', 'enum'},
            {'constructor'},
            {'method'},
            {'getter'},
            {'setter'},
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

            def _run_recursive(node):
                stack_added = False
                if node.api and (not calling_api or node.api in calling_api) and node not in processed:
                    ancesstor = node.ancestor_with_api
                    if ancesstor in processed:
                        # for already called api resume builders scope stack
                        logging.debug(f"Restoring stack for {ancesstor.displayname}.")
                        builder.restore_stacks(processed[ancesstor])
                        logging.debug(
                            f"Restored stack {self.__str_stacks(processed[ancesstor])}."
                        )
                    # allocate scope
                    stack_added = True
                    builder.add_scope_stack()

                    # call api
                    self.call_api(rule, node, builder)
                    logging.debug(f"Capturing stack for {node.displayname}.")
                    processed[node] = builder.capture_stacks()
                    logging.debug(f"Captured stack {self.__str_stacks(processed[node])}.")

                if node.children:
                    logging.debug(f"Processing children for {node.displayname}.")
                    for child in node.children:
                        _run_recursive(child)
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

    def call_api(self, rule, node, builder):
        api = node.api
        att_name = "gen_" + api
        logging.debug(f"Call API: {api} on {node.displayname}")
        func = getattr(rule, att_name)
        func(self.get_context(node.full_displayname), builder)

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
