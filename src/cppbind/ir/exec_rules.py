# Copyright (c) 2022 PicsArt, Inc.
# All rights reserved. Use of this source code is governed by a
# MIT-style license that can be found in the LICENSE file.

"""
"""
import itertools
import json
import types
from dataclasses import dataclass

from cached_property import cached_property

from .utils import available_on
import cppbind.utils.clang as cutil
from cppbind import logging
from cppbind.ir import ElementKind
from cppbind.ir.ast import NodeType, Node
from cppbind.parser import TEMPLATE_TYPE_PARAMETER_KEY, TEMPLATE_NON_TYPE_PARAMETER_KEY


@dataclass
class TemplateInfo:
    """Holds information about specialized template type's choice and template argument postfixes."""

    # template parameter - actual type mapping(e.g {'T': 'std::string', 'N': 'int'})
    choice: dict
    # template parameter argument postfixes retrieved from the api, will be none if not specified by user
    # these postfixes are used when constructing the name for template type in target languages, see object converter
    template_args_postfixes: list


class BaseContext:
    def __init__(self, runner, node=None):
        self.runner = runner
        self.node = node or runner.ir

    @cached_property
    def vars(self):
        return types.SimpleNamespace(**self.node.args)


class Context(BaseContext):

    def __init__(self, runner, node, template_info=None):
        super().__init__(runner, node)
        self.template_info = template_info

    @property
    def setter(self):
        """Find the context of the setter corresponding to the current getter context"""

        if self.node.api != 'gen_getter':
            raise AttributeError(f"{self.__class__.__name__}.setter is invalid.")

        search_api = 'gen_setter'
        name = self.node.spelling
        if name.lower().startswith('get'):
            name = name[3:].lstrip('_')
        search_names = {f"set_{name}", "set" + name[:1].upper() + name[1:],
                        'set' + ''.join(map(lambda n: n.capitalize(), name.split('_')))}

        node = self.node.find_adjacent_node(search_names, search_api)
        return self.runner.find_ctx_by_node(node)

    @property
    def getter(self):
        """Find the context of the getter corresponding to the current setter context"""

        if self.node.api != 'gen_setter':
            raise AttributeError(f"{self.__class__.__name__}.getter is invalid.")

        search_api = 'gen_getter'
        name = self.node.spelling
        if name.lower().startswith('set'):
            name = name[3:].lstrip('_')
        search_names = {f"get_{name}", "get" + name[:1].upper() + name[1:],
                        name, name[:1].lower() + name[1:]}

        node = self.node.find_adjacent_node(search_names, search_api)
        return self.runner.find_ctx_by_node(node)

    @cached_property
    @available_on(ElementKind.STRUCT_DECL,
                  ElementKind.CLASS_DECL,
                  ElementKind.CLASS_TEMPLATE)
    def ancestor_contexts(self):
        """The list of contexts of the ancestors"""
        return [
            self.lookup_ctx_by_name(cutil.replace_template_choice(ancestor_node.full_displayname, self.template_choice))
            for ancestor_node in self.node.ancestor_nodes]

    @property
    def parent_context(self):
        if self.node.parent.type == NodeType.CLANG_NODE:
            # TODO update this when we will expose templates at node level
            return self.lookup_ctx_by_name(
                cutil.replace_template_choice(self.node.parent.full_displayname,
                                              self.template_choice))
        else:
            return self.lookup_ctx_by_name(self.node.parent.full_displayname)

    def set_template_info(self, template_info):
        self.template_info = template_info

    @property
    def template_choice(self):
        return self.template_info.choice if self.template_info else None

    @property
    def template_args_postfixes(self):
        return self.template_info.template_args_postfixes if self.template_info else None

    def lookup_ctx_by_name(self, name):
        return self.runner.get_context(name)

    @property
    @available_on(ElementKind.STRUCT_DECL,
                  ElementKind.CLASS_DECL,
                  ElementKind.CLASS_TEMPLATE,
                  ElementKind.ENUM_DECL)
    def cxx_type_name(self):
        """
        Returns cxx type name. Main usage of this property is for template types. For templates clang's type information
        is not enough, so we retrieve some additional info from type's string representation
        Returns:
           str: Type name.
        """
        # in case of a template class - cursor type is TypeKind.INVALID,
        # that's why can't get type spelling from the
        # cursor using this approach instead
        # for example for the type a::Stack<T> full_displayname=a::Stack,
        # spelling=Stack, displayname=Stack<T>

        template_choice = self.template_choice or {}
        if self.node.cxx_element.is_templated:
            cxx_type_name = self.node.full_displayname
            return cutil.replace_template_choice(cxx_type_name, template_choice)
        return self.node.cxx_element.type.spelling


class RunRule:
    def __init__(self, ir, ctx_desc, platform, language):
        self.ir = ir
        self.ctx_desc = ctx_desc
        self.language = language
        self.platform = platform
        self.all_contexts = dict()
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
            func(BaseContext(self), self.ctx_desc, self.platform, self.language)

        # executes once for a type
        processed = dict()
        for calling_api in self.api_call_order:
            logging.debug(f"Calling APIs: {calling_api}")

            def _run_recursive(node, template_info=None):
                stack_added = False
                node_key = RunRule.__node_key(node, template_info)
                if node.api and (not calling_api or node.api in calling_api) and node_key not in processed:
                    ancestor = node.ancestor_with_api
                    ancestor_key = RunRule.__node_key(ancestor, template_info)
                    if ancestor_key in processed:
                        # for already called api resume builders scope stack
                        logging.debug(f"Restoring stack for {ancestor.displayname}.")
                        builder.restore_stacks(processed[ancestor_key])
                        logging.debug(
                            f"Restored stack {RunRule.__str_stacks(processed[ancestor_key])}."
                        )
                    # allocate scope
                    if node.type == NodeType.CLANG_NODE:
                        stack_added = True
                        builder.add_scope_stack()

                    # call api
                    self.call_api(rule, node, builder, template_info)
                    logging.debug(f"Capturing stack for {node.displayname}.")
                    processed[node_key] = builder.capture_stacks()
                    logging.debug(f"Captured stack {RunRule.__str_stacks(processed[node_key])}.")

                if node.children:
                    logging.debug(f"Processing children for {node.displayname}.")
                    for child in node.children:
                        if child.type == NodeType.CLANG_NODE:
                            # check if the node is template and generate code for each combination of template args
                            if child.kind in (ElementKind.CLASS_TEMPLATE,
                                              ElementKind.FUNCTION_TEMPLATE):
                                for _template_info in RunRule._get_template_combinations(child, ignore_parents=True):
                                    if template_info:
                                        # merge current node's context with parent
                                        # this might be revisited in #242
                                        # and will be changed after template nodes will be exposed during
                                        # ir post processing
                                        _template_info.choice.update(template_info.choice)
                                    _run_recursive(child, _template_info)
                            else:
                                _run_recursive(child, template_info)
                        else:
                            _run_recursive(child, template_info)
                    logging.debug(f"End processing children for {node.displayname}.")

                if stack_added:
                    builder.pop_scope_stack()

            # create common scope for entire ir
            # we have to add this scope to be able to allow
            # write into single file from multiple roots
            # since we do not have gen api for file
            # we register file and add one scope
            builder.add_scope_stack()

            _run_recursive(self.ir)

            builder.pop_scope_stack()

    def call_api(self, rule, node, builder, template_info=None):
        api = node.api
        if api == Node.API_NONE:
            return
        logging.debug(f"Call API: {api.lstrip(api)} on {node.displayname}")
        func = getattr(rule, api)
        context = self.get_context(node.signature)
        # set current template context to generate code based on correct template choice
        context.set_template_info(template_info)
        func(context, builder)

    def get_context(self, type_name):
        return self.all_contexts.get(type_name)

    def find_ctx_by_node(self, node):
        """Find context by node"""
        if node:
            return self.get_context(node.signature)

    def allocate_all_contexts(self):
        logging.debug("Allocating context for all nodes")
        for node in self.ir.walk():
            if node.api not in (None, Node.API_NONE):
                ctx = Context(self, node)
                self.all_contexts.setdefault(node.signature, ctx)

                # this will be changed after template nodes will be exposed during ir post-processing
                if node.type == NodeType.CLANG_NODE and node.is_class_or_struct and node.cxx_element.is_templated:
                    # for template create a context also with only template type name(NOTE: this might not be used)
                    self.all_contexts.setdefault(cutil.template_type_name(node.signature), ctx)
                    # and for each specialization also create a context
                    for template_info in RunRule._get_template_combinations(node):
                        context = Context(self, node, template_info)
                        self.all_contexts[context.cxx_type_name] = context

    @staticmethod
    def _get_template_combinations(node, ignore_parents=False):
        parent = node.parent
        # for template choice we need to consider all template parent types
        template_arg = {}

        # current node template argument
        node_template_arg = node.args.get('template') or {}
        template_arg.update(node_template_arg)

        if not ignore_parents:
            while parent.type == NodeType.CLANG_NODE and parent.is_class_or_struct:
                parent_template = parent.args.get('template')
                # if parent also has a template argument join with child's
                if parent_template:
                    template_arg.update(parent_template)
                parent = parent.parent

        # helper map to easily get template names for different combinations
        node_type_name_map = {
            k: {i.get(TEMPLATE_TYPE_PARAMETER_KEY) or i.get(TEMPLATE_NON_TYPE_PARAMETER_KEY): i.get('name') for i in v}
            for k, v in node_template_arg.items()}

        all_possible_args = list(itertools.product(*template_arg.values()))
        template_keys = template_arg.keys()
        all_contexts = []
        for _, combination in enumerate(all_possible_args):
            choice = [item.get(TEMPLATE_TYPE_PARAMETER_KEY) or item.get(TEMPLATE_NON_TYPE_PARAMETER_KEY) for item in
                      combination]
            _template_choice = dict(zip(template_keys, choice))
            # only if the current node is template then it should have template postfixes
            choice_names = [node_type_name_map[template_param][_template_choice[template_param]]
                            for template_param in node_template_arg.keys()]
            all_contexts.append(TemplateInfo(choice=_template_choice, template_args_postfixes=choice_names))
        return all_contexts

    @staticmethod
    def __node_key(node, template_info):
        node_key = (node,)
        if node and node.type == NodeType.CLANG_NODE and node.cxx_element.is_templated:
            node_key = (node, json.dumps(template_info.__dict__))
        return node_key

    @staticmethod
    def __str_stacks(capture_data):
        # first lang stack data
        stack_data = capture_data
        return f"{[s.keys() for fs in stack_data.values() for s in fs]}"
