# Copyright (c) 2022 PicsArt, Inc.
# All rights reserved. Use of this source code is governed by a
# MIT-style license that can be found in the LICENSE file.

"""
Module is responsible for yaml config files loading, merging and context variables forming.
"""

import copy
import glob
import os
from collections import defaultdict
from itertools import chain

import yaml

from cppbind import default_config
from cppbind.common.error import Error
from cppbind.common.yaml_process import load_yaml, YamlKeyDuplicationError
from cppbind.ir.ast import RootNode
from cppbind.utils.clang import join_type_parts

NODE_GROUP_ALIASES = {
    'cmd_line': ('cmd_line', 'root'),
    'file_system': ('dir', 'file'),
    'cxx_method': ('method', 'method_template'),
    'cxx_function': ('function', 'function_template'),
    'cxx_constructor': ('constructor', 'constructor_template'),
    'cxx': (
        'class', 'class_template', 'class_template_partial_specialization', 'struct', 'struct_template', 'constructor', 'constructor_template',
        'function', 'function_template', 'method', 'method_template', 'enum', 'field'
    ),
}


class ContextDescriptor:
    """
    A class to read/load/merge yaml config files and calc/eval context variables
    """

    ROOT_SECTION_KEY = 'vars'
    DIR_SECTION_KEY = 'dir_vars'
    FILE_SECTION_KEY = 'file_vars'
    TYPE_SECTION_KEY = 'type_vars'
    VAR_DEF_SECTION_KEY = 'var_def'

    RULE_SECTION_KEY = 'rules'
    CODE_SNIPPETS_KEY = 'code_snippets'
    TYPE_CONVERTER_SNIPPETS_KEY = 'type_converters'
    ACTION_SNIPPETS_KEY = 'actions'

    VARS_RULE_KEY = 'vars'
    TYPE_RULE_KEY = 'type'
    DIR_RULE_KEY = 'dir'
    FILE_RULE_KEY = 'file'
    SUB_RULE_KEY = ':'

    def __init__(self, context_def_glob):
        self.__ctx_def_map = ContextDescriptor.build_ctx_def_map(context_def_glob)
        self.__deduced_languages = self.__validate_and_deduce_languages()
        self.__var_def = ContextDescriptor.resolve_attr_aliases(self.__get_raw_var_def())
        self.__validate_var_def()

    @staticmethod
    def resolve_attr_aliases(attrs):
        """
        A function to replace node group aliases with their actual values list
        """

        for field in ['allowed_on', 'required_on']:
            for key, val in attrs.items():
                if field not in val:
                    attrs[key][field] = set(chain(*NODE_GROUP_ALIASES.values()) if field == 'allowed_on' else [])
                else:
                    res = set()
                    for node in val[field]:
                        if node in NODE_GROUP_ALIASES:
                            res.update(NODE_GROUP_ALIASES[node])
                        else:
                            res.add(node)
                    attrs[key][field] = res

        return attrs

    @classmethod
    def build_ctx_def_map(cls, context_def_glob):
        """
        A method for iterating over yaml config files and
        building context definition map by loading/merging yaml files.
        """
        if context_def_glob is None:
            return {}

        files = set()
        for file in context_def_glob.split(','):
            files_glob = glob.glob(file.strip(), recursive=True)
            for file_path in files_glob:
                files.add(os.path.abspath(file_path))

        ctx_def_map = {}
        for current_file in list(sorted(files)):
            try:
                attrs = load_yaml(current_file)
            except yaml.YAMLError as err:
                raise yaml.YAMLError(f"Wrong yaml format: {current_file}: {err}")

            if attrs:
                cls.load_merge_ctx_def_map(attrs, ctx_def_map)

        return ctx_def_map

    @classmethod
    def load_merge_ctx_def_map(cls, attrs, ctx_def_map):
        """
        A method for loading/merging yaml config files corresponding sections.
        """
        def flatten_dict(src_dict, section_key, ancestors):
            cls.validate_section_keys(src_dict, section_key)
            if cls.TYPE_RULE_KEY in src_dict:
                ancestors.append(src_dict[cls.TYPE_RULE_KEY].value)
            try:
                if cls.VARS_RULE_KEY in src_dict:
                    flat_key = ContextDescriptor._get_key(src_dict=src_dict,
                                                          ancestors=ancestors)
                    if flat_key in ctx_def_map:
                        cls._raise_redefinition_error(flat_key, src_dict[cls.VARS_RULE_KEY], ctx_def_map[flat_key])
                    ctx_def_map[flat_key] = src_dict[cls.VARS_RULE_KEY]
                if cls.SUB_RULE_KEY in src_dict:
                    for sub in src_dict[cls.SUB_RULE_KEY]:
                        flatten_dict(sub, section_key, ancestors)
            finally:
                if cls.TYPE_RULE_KEY in src_dict:
                    ancestors.pop()

        if cls.ROOT_SECTION_KEY in attrs:
            root_section = attrs[cls.ROOT_SECTION_KEY]
            if RootNode.ROOT_KEY in ctx_def_map:
                cls._raise_redefinition_error(cls.ROOT_SECTION_KEY, root_section, ctx_def_map[RootNode.ROOT_KEY])
            ctx_def_map[RootNode.ROOT_KEY] = attrs[cls.ROOT_SECTION_KEY]

        for section in (cls.DIR_SECTION_KEY, cls.FILE_SECTION_KEY, cls.TYPE_SECTION_KEY):
            if section in attrs:
                if attrs[section].value is not None:
                    for item in attrs[section]:
                        flatten_dict(item, section, [])

        if cls.VAR_DEF_SECTION_KEY in attrs:
            var_def_section = attrs[cls.VAR_DEF_SECTION_KEY]
            if cls.VAR_DEF_SECTION_KEY in ctx_def_map:
                intersection = var_def_section.keys() & ctx_def_map[cls.VAR_DEF_SECTION_KEY].keys()
                if intersection:
                    redefinitions = '\n'.join([f"{redefined_var}: {var_def_section[redefined_var].line_number} - "
                                               f"{ctx_def_map[cls.VAR_DEF_SECTION_KEY][redefined_var].line_number}"
                                               for redefined_var in intersection])
                    raise YamlKeyDuplicationError(f"Variable definition duplicate(s) in\n"
                                                  f"{ctx_def_map[cls.VAR_DEF_SECTION_KEY].file}"
                                                  f" - {var_def_section.file}: \n{redefinitions}.")
                ctx_def_map[cls.VAR_DEF_SECTION_KEY].update(var_def_section)
            else:
                ctx_def_map[cls.VAR_DEF_SECTION_KEY] = var_def_section

        cls.load_merge_rules(attrs, ctx_def_map)

    @classmethod
    def _raise_redefinition_error(cls, key, current_section, previous_section):
        raise YamlKeyDuplicationError(f"Redefinition of '{key}' "
                                      f"section in line {current_section.line_number} "
                                      f"of {current_section.file} file, which must be "
                                      f"uniquely specified only in one file.\n"
                                      f"It was previously defined in line "
                                      f"{previous_section.line_number} "
                                      f"of {previous_section.file} file.")

    @classmethod
    def _get_key(cls, src_dict, ancestors):
        """
        A method to construct a key from loaded yaml config file's current section.
        """

        # dir
        if cls.DIR_RULE_KEY in src_dict:
            dir_name = src_dict[cls.DIR_RULE_KEY].value
            if os.path.isabs(dir_name):
                # if an absolute path is specified then we assume it's absolute to current dir
                return dir_name.replace('/', '', 1) or '.'
            return os.path.relpath(
                os.path.abspath(os.path.join(os.path.dirname(
                    src_dict[cls.DIR_RULE_KEY].file), dir_name)),
                os.getcwd())
        # file
        if cls.FILE_RULE_KEY in src_dict:
            file_name = src_dict[cls.FILE_RULE_KEY].value
            if os.path.isabs(file_name):
                # if an absolute path is specified then we assume it's absolute to current dir
                flat_key = file_name.replace('/', '', 1)
                return os.path.join(flat_key, os.getcwd())
            return os.path.abspath(os.path.join(os.path.dirname(
                src_dict[cls.FILE_RULE_KEY].file), file_name))

        # type
        return join_type_parts(ancestors)

    @staticmethod
    def load_merge_rules(attrs, ctx_def_map):
        """
        A method for loading/merging snippets related sections from yaml config files.
        """

        def merge_rules(rules, rules_map, path):
            """
            Method to merge current tree with global one and report errors
            """
            # actions are list items
            if isinstance(rules_map, list):
                rules_map.extend(rules)
                return
            for key, val in rules.items():
                # keep current key path (list of parent keys) to use in error message
                path.append(key)
                if key in rules_map:
                    if val.is_of_type(dict) and rules_map[key].is_of_type(dict):
                        merge_rules(val, rules_map[key], path)
                    else:
                        raise YamlKeyDuplicationError(f"Redefinition of '{'.'.join(path)}' "
                                                      f"key section in line {val.line_number} "
                                                      f"of {val.file} file,\n"
                                                      f"which already has been defined in line "
                                                      f"{rules_map[key].line_number} of "
                                                      f"{rules_map[key].file} file")
                else:
                    rules_map[key] = copy.deepcopy(val)
                path.pop()

        current_rules = attrs.get(ContextDescriptor.RULE_SECTION_KEY)
        if current_rules:
            for rule_key in current_rules:
                platforms = lang = section_type = None
                rule_key_tokens = rule_key.split('.')

                if len(rule_key_tokens) == 3:
                    platforms = [rule_key_tokens[0]]
                    lang = rule_key_tokens[1]
                    section_type = rule_key_tokens[2]
                elif len(rule_key_tokens) == 2:
                    platforms = default_config.platforms
                    lang = rule_key_tokens[0]
                    section_type = rule_key_tokens[1]

                if lang is None:
                    continue

                for plat in platforms:
                    if section_type == ContextDescriptor.CODE_SNIPPETS_KEY:
                        global_code_snippets = ctx_def_map.setdefault(ContextDescriptor.CODE_SNIPPETS_KEY,
                                                                      defaultdict(lambda: defaultdict(dict)))
                        merge_rules(current_rules[rule_key], global_code_snippets[lang][plat], [])
                    elif section_type == ContextDescriptor.TYPE_CONVERTER_SNIPPETS_KEY:
                        global_type_converters = ctx_def_map.setdefault(ContextDescriptor.TYPE_CONVERTER_SNIPPETS_KEY,
                                                                        defaultdict(lambda: defaultdict(dict)))
                        merge_rules(current_rules[rule_key], global_type_converters[lang][plat], [])
                    elif section_type == ContextDescriptor.ACTION_SNIPPETS_KEY:
                        global_actions = ctx_def_map.setdefault(ContextDescriptor.ACTION_SNIPPETS_KEY,
                                                                defaultdict(lambda: defaultdict(list)))
                        merge_rules(current_rules[rule_key], global_actions[lang][plat], [])

    @classmethod
    def validate_section_keys(cls, src_dict, section_key):
        """
        A method to validate current section and raise an error
        in case of disallowed key usages in the section.
        """
        if section_key == cls.FILE_SECTION_KEY and (cls.DIR_RULE_KEY in src_dict or cls.TYPE_RULE_KEY in src_dict):
            Error.critical(f"API file section definition can only contain '{cls.FILE_RULE_KEY}' key")
        elif section_key == cls.DIR_SECTION_KEY and (cls.FILE_RULE_KEY in src_dict or cls.TYPE_RULE_KEY in src_dict):
            Error.critical(f"API dir section definition can only contain '{cls.DIR_RULE_KEY}' key")
        elif section_key == cls.TYPE_SECTION_KEY and (cls.DIR_RULE_KEY in src_dict or cls.FILE_RULE_KEY in src_dict):
            Error.critical(f"API type section definition can only contain '{cls.TYPE_RULE_KEY}' key")

    def __validate_var_def(self):
        """Method for variables definition validation"""
        for var_name, prop in self.get_var_def().items():
            extra_nodes = set(prop['required_on']) - set(prop['allowed_on'])
            if extra_nodes:
                Error.error(f"Variable '{var_name}' is required on '{', '.join(extra_nodes)}' "
                            f"node{'s' if len(extra_nodes) > 1 else ''}, while it's not allowed on "
                            f"{'them' if len(extra_nodes) > 1 else 'it'}",
                            prop.file,
                            prop.line_number)

    def __validate_and_deduce_languages(self):
        if ContextDescriptor.CODE_SNIPPETS_KEY not in self.__ctx_def_map:
            Error.critical("CppBind error: there is no any specified code snippet rule")
        if ContextDescriptor.TYPE_CONVERTER_SNIPPETS_KEY not in self.__ctx_def_map:
            Error.critical("CppBind error: there is no any specified type converter snippet rule")

        code_snippets_languages = sorted(list(self.__ctx_def_map[ContextDescriptor.CODE_SNIPPETS_KEY].keys()))
        type_converter_languages = sorted(
            list(self.__ctx_def_map[ContextDescriptor.TYPE_CONVERTER_SNIPPETS_KEY].keys()))
        if code_snippets_languages != type_converter_languages:
            languages_with_diff = set(code_snippets_languages).symmetric_difference(set(type_converter_languages))
            Error.critical(f"CppBind error: code snippets and type converters must be both specified for a language. "
                           f"This rule is violated for {', '.join(languages_with_diff)} "
                           f"language{'s' if len(languages_with_diff) > 1 else ''}")

        return code_snippets_languages

    def __get_raw_var_def(self):
        """Get raw variable definitions section without resolving node alias names"""
        return self.__ctx_def_map.get(ContextDescriptor.VAR_DEF_SECTION_KEY, {})

    def get_var_def(self):
        """Get variable definitions with already resolved node alias names"""
        return self.__var_def

    def get_code_snippets(self):
        """Get final code snippets section"""
        return self.__ctx_def_map.get(ContextDescriptor.CODE_SNIPPETS_KEY, {})

    def get_type_converter_snippets(self):
        """Get type converter snippets section"""
        return self.__ctx_def_map.get(ContextDescriptor.TYPE_CONVERTER_SNIPPETS_KEY, {})

    def get_action_snippets(self):
        """Get action snippets section"""
        return self.__ctx_def_map.get(ContextDescriptor.ACTION_SNIPPETS_KEY, [])

    def has_yaml_api(self, name):
        """
        Check whether current name is present in context definition map
        """
        return name in self.__ctx_def_map

    def get_api_def_filename(self, name):
        """
        Method to get yaml config file name in which file/dir api is defined
        """
        return self.__ctx_def_map[name].file

    def get_yaml_api(self, name):
        """
        Get yaml api value from context definition map
        """
        return self.__ctx_def_map.get(name)

    def get_deduced_languages(self):
        """
        Returns the list of languages deduced from snippets info under "rules" section
        """
        return self.__deduced_languages

    def get_all_languages(self):
        """
        Returns the set of all languages: deduced languages merged with application supported languages
        """
        return set(self.__deduced_languages + default_config.languages)
