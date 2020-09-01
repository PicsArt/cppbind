"""
"""
import copy
from iegnen import (
    logging as logging
)


class RunRule(object):

    def __init__(self, ir):
        self.ir = ir
        # calling order should be such as that parent node processes first
        self.api_call_order = [
            {'class', 'enum'},
            {'enum_case', 'constructor'},
            {'method'},
            {}
        ]

    def run(self, rules, builders):

        # running order is defined by type of node
        # at first we run nodes for namespace/class/enums and then for methods

        # walk is traversing in dept first order
        processed = dict()
        __ancestor = None
        for calling_api in self.api_call_order:
            logging.debug(f"Calling APIs: {calling_api}")
            for node in self.ir.walk():
                if node.api and (not calling_api or
                                 node.api in calling_api):
                    if node not in processed:
                        # call api
                        assert __ancestor == node.ancestor_with_api
                        map(lambda b: b.add_scope_stack(), builders.values())
                        self.call_api(rules, node.api, node, builders)
                        logging.debug(f"Capturing stack for {node.displayname}.")
                        processed[node] = self.capture_stacks(builders)
                        map(lambda b: b.pop_scope_stack(), builders.values())
                    else:
                        # for already called api resume builders scope stack
                        # this code assumes that child nodes (if any) are going to be processed next
                        __ancestor = node
                        logging.debug(f"Restoring stack for {node.displayname}.")
                        self.restore_stacks(builders, processed[node])

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
            func(node, builder)
