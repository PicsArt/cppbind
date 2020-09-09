"""
"""
import copy
import clang.cindex as cli
from iegnen.utils.clang import (
    get_unqualified_type_name,
    is_rval_referance
)
from iegnen import logging as logging


class TypeContext(object):

    def __init__(self, runner, lang, clang_type):
        self.runner = runner
        self.lang = lang
        self.clang_type = clang_type

    @property
    def name(self):
        return self.clang_type.spelling

    @property
    def unqualified_name(self):
        return get_unqualified_type_name(self.name)

    @property
    def pointee_type(self):
        clang_pointee = self.clang_type.get_pointee()
        if clang_pointee.spelling:
            return TypeContext(self.runner, self.lang, clang_pointee)
        return self

    @property
    def canonical_type(self):
        clang_canonical = self.clang_type.get_canonical()
        if clang_canonical.spelling != self.clang_type.spelling:
            return TypeContext(self.runner, self.lang, clang_canonical)
        return self

    @property
    def is_template(self):
        return self.clang_type.get_num_template_arguments() != -1

    @property
    def template_argument_types(self):
        return [TypeContext(self.runner, self.lang, self.clang_type.get_template_argument_type(num))
                for num in range(self.clang_type.get_num_template_arguments())]

    def get_num_template_arguments(self):
        return self.clang_type.get_num_template_arguments()

    def get_template_argument_type(self, num):
        return self.clang_type.get_template_argument_type(num)

    @property
    def template_type_name(self):
        # todo:self.declaration_cursor.spelling does not return name space or full name
        name = self.unqualified_name
        end_indx = name.index('<')
        if end_indx != -1:
            return name[:end_indx].strip()
        return name

    @property
    def is_rval_referance(self):
        return is_rval_referance(self.clang_type)

    @property
    def declaration_cursor(self):
        return self.clang_type.get_declaration()

    @property
    def declaration(self):
        return self.runner.get_context(self.lang, self.declaration_cursor.type.spelling)


class Context(object):

    def __init__(self, runner, node, lang):
        assert node.clang_cursor, "cursor is not provided"
        self.runner = runner
        self.node = node
        self.lang = lang

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
            arg_params = dict(name=arg_c.spelling,  type=TypeContext(self.runner, self.lang, arg_c.type), cursor=arg_c)

            def_val = get_default(arg_c)
            if def_val:
                arg_params['default'] = def_val
            _args.append(arg_params)

        return _args

    @property
    def result_type(self):

        if self.node.clang_cursor.kind not in [cli.CursorKind.CXX_METHOD, cli.CursorKind.FUNCTION_DECL]:
            raise AttributeError(f"{self.__class__.__name__}.returns is invalid.")
        return TypeContext(self.runner, self.lang, self.node.clang_cursor.result_type)

    @property
    def base_types(self):

        if self.node.clang_cursor.kind not in [cli.CursorKind.STRUCT_DECL, cli.CursorKind.CLASS_DECL]:
            raise AttributeError(f"{self.__class__.__name__}.base_type is invalid.")

        return [
            TypeContext(self.runner, self.lang, base_specifier.type)
            for base_specifier in self.base_types_specifier_cursor
        ]

    @property
    def base_types_specifier_cursor(self):

        if self.node.clang_cursor.kind not in [cli.CursorKind.STRUCT_DECL, cli.CursorKind.CLASS_DECL]:
            raise AttributeError(f"{self.__class__.__name__}.base_type is invalid.")

        return [base_specifier
                for base_specifier in self.node.clang_cursor.get_children()
                if base_specifier.kind == cli.CursorKind.CXX_BASE_SPECIFIER
                ]

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
    def parent_context(self):
        return self.runner.access_context(self.lang, self.node.parent)

    def find_by_type(self, search_type):
        return self.runner.get_context(self.lang, search_type)

    def __getattr__(self, name):
        val = self.node.args.get(name, None)
        if val is None:
            raise AttributeError(f"{self.__class__.__name__}.{name} is invalid.\
API has no '{name}' attribute for {self.node.displayname}.")
        val = val.get(self.lang, None)
        if val is None:
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

    def run(self, rules, builders):  # noqa: C901

        # running order is defined by type of node
        # at first we run nodes for namespace/class/enums and then for methods

        # walk is traversing in dept first order
        self.all_contexts = dict()
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
                        self.restore_stacks(builders, processed[ancesstor])
                        logging.debug(
                            f"Restored stack {[s.keys() for s in next(iter(processed[ancesstor].values()))]}."
                        )
                    # allocate scope
                    stack_added = True
                    for b in builders.values():
                        b.add_scope_stack()

                    # call api
                    self.call_api(rules, node.api, node, builders)
                    logging.debug(f"Capturing stack for {node.displayname}.")
                    processed[node] = self.capture_stacks(builders)
                    logging.debug(f"Captured stack {[s.keys() for s in next(iter(processed[node].values()))]}.")

                if node.children:
                    logging.debug(f"Processing children for {node.displayname}.")
                    for child in node.children:
                        _run_recursive(child)
                    logging.debug(f"End processing children for {node.displayname}.")

                if stack_added:
                    for b in builders.values():
                        b.pop_scope_stack()

            # create common scope for entire ir
            for b in builders.values():
                b.add_scope_stack()

            for root in self.ir.roots:
                _run_recursive(root)

            for b in builders.values():
                b.pop_scope_stack()

    def capture_stacks(self, builders):
        return {lang: copy.copy(builder._scope_stack) for lang, builder in builders.items()}

    def restore_stacks(self, builders, capture_data):
        for lang, builder in builders.items():
            builder._scope_stack = copy.copy(capture_data[lang])

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
