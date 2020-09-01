"""
"""
import copy
import clang.cindex as cli
from iegnen import (
    logging as logging
)


class Context(object):

    def __init__(self, runner, node, lang):
        assert node.clang_cursor, "cursor is not provided"
        self.runner = runner
        self.node = node
        self.lang = lang

    @property
    def type(self):
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
                ]:
                    val = next(def_curs.get_tokens(), None)
                    if val:
                        val = val.spelling
            return val

        for arg_c in self.node.clang_cursor.get_arguments():
            arg_params = dict(name=arg_c.spelling, type=arg_c.type.spelling)

            def_val = get_default(arg_c)
            if def_val:
                arg_params['default'] = def_val
            _args.append(arg_params)

        return _args

    @property
    def result_type(self):

        if self.node.clang_cursor.kind not in [cli.CursorKind.CXX_METHOD, cli.CursorKind.FUNCTION_DECL]:
            raise AttributeError(f"{self.__class__.__name__}.returns is invalid.")
        return self.node.clang_cursor.result_type.spelling

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
            enum_val_params = dict(name=enum_value_c.spelling, type=type_name,
                                   value=enum_value_c.enum_value)

            _vals.append(enum_val_params)
        return _vals

    @property
    def parent(self):
        return self.runner.access_context(self.lang, self.node.parent)

    def find_by_type(self, search_type):
        return self.runner.get_context(self.lang, search_type)

    def __getattr__(self, name):
        val = self.node.args.get(name, None)
        if not val:
            raise AttributeError(f"{self.__class__.__name__}.{name} is invalid. API has no '{name}' attribute.")
        val = val.get(self.lang, None)
        if not val:
            raise AttributeError(f"{self.__class__.__name__}.{name} is invalid. API has no '{name}'\
                                    attribute for language {self.lang}.")
        return val


class RunRule(object):

    def __init__(self, ir):
        self.ir = ir
        # calling order should be such as that parent node processes first
        self.api_call_order = [
            {'class', 'enum'},
            {'constructor'},
            {'method'},
            {}
        ]

    def run(self, rules, builders):

        # running order is defined by type of node
        # at first we run nodes for namespace/class/enums and then for methods

        # walk is traversing in dept first order
        self.all_contexts = dict()
        processed = dict()
        for calling_api in self.api_call_order:
            logging.debug(f"Calling APIs: {calling_api}")

            def _run_recursive(node):
                stack_added = False
                if node in processed:
                    # for already called api resume builders scope stack
                    logging.debug(f"Restoring stack for {node.displayname}.")
                    self.restore_stacks(builders, processed[node])
                    logging.debug(f"Restored stack {[s.keys() for s in processed[node]['java']]}.")
                elif node.api and (not calling_api or node.api in calling_api):
                    # allocate scope
                    stack_added = True
                    for b in builders.values():
                        b.add_scope_stack()

                    # call api
                    self.call_api(rules, node.api, node, builders)
                    logging.debug(f"Capturing stack for {node.displayname}.")
                    processed[node] = self.capture_stacks(builders)
                    logging.debug(f"Captured stack {[s.keys() for s in processed[node]['java']]}.")

                if node.children:
                    logging.debug(f"Processing children for {node.displayname}.")
                    for child in node.children:
                        _run_recursive(child)
                    logging.debug(f"End processing children for {node.displayname}.")

                if stack_added:
                    for b in builders.values():
                        b.pop_scope_stack()

            for root in self.ir.roots:
                _run_recursive(root)

    def capture_stacks(self, builders):
        return {lang: copy.copy(builder._scope_stack) for lang, builder in builders.items()}

    def restore_stacks(self, builders, capture_data):
        for lang, builder in builders.items():
            builder._scope_stack = capture_data[lang]

    def call_api(self, rules, api, node, builders):
        att_name = "gen_" + api
        for lang, builder in builders.items():
            logging.debug(f"Call API: {api} on {node.displayname} for {lang}")
            func = getattr(rules[lang], att_name)
            func(self.access_context(lang, node), builder)

    def access_context(self, lang, node):
        if node is None:
            return None
        cntx = self.all_contexts.setdefault(lang,
                                            {}).setdefault(node.type_name,
                                                           Context(self, node, lang))
        return cntx

    def get_context(self, lang, type_name):
        cntx = self.all_contexts.get(lang, {}).get(type_name, None)
        return cntx
