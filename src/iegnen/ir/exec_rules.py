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
        return self.runner.get_context(self.lang, self.node.parent)

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
            {'module'},
            {'class', 'enum'},
            {'enum_case', 'constructor'},
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
            for node in self.ir.walk():
                if node.api and (not calling_api or
                                 node.api in calling_api)\
                        and node not in processed:
                    # call api
                    _ancestor = node.ancestor_with_api
                    if _ancestor in processed:
                        # for already called api resume builders scope stack
                        # this code assumes that child nodes (if any) are going to be processed next
                        logging.debug(f"Restoring stack for {node.displayname}.")
                        self.restore_stacks(builders, processed[_ancestor])

                    map(lambda b: b.add_scope_stack(), builders.values())
                    self.call_api(rules, node.api, node, builders)
                    logging.debug(f"Capturing stack for {node.displayname}.")
                    processed[node] = self.capture_stacks(builders)
                    map(lambda b: b.pop_scope_stack(), builders.values())

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
            func(self.get_context(lang, node), builder)

    def get_context(self, lang, node):
        cntx = self.all_contexts.setdefault(lang,
                                            {}).setdefault(node,
                                                           Context(self, node, lang))
        return cntx
