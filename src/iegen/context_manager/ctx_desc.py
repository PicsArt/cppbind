"""
Module is responsible for yaml config files loading, merging and context variables forming.
"""

import copy
import glob
import os

from collections import defaultdict
import yaml

from iegen import default_config
from iegen.common.error import Error
from iegen.common.yaml_process import load_yaml, YamlKeyDuplicationError
from iegen.ir.ast import RootNode
from iegen.utils.clang import join_type_parts

NODE_GROUP_ALIASES = {
    'file_system': ('dir', 'file'),
    'cxx': (
        'class', 'class_template', 'struct', 'struct_template', 'constructor',
        'function', 'function_template', 'cxx_method', 'enum', 'field'
    )
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

    def __init__(self):
        self.__ctx_def_map = ContextDescriptor.build_ctx_def_map(getattr(default_config.application,
                                                                         'context_def_glob',
                                                                         None))
        self.__var_def = ContextDescriptor.resolve_attr_aliases(self.get_raw_var_def())
        self.validate_var_def()

    @staticmethod
    def resolve_attr_aliases(attrs):
        """
        A function to replace node group aliases with their actual values list
        """

        for field in ['allowed_on', 'required_on']:
            for key, val in attrs.items():
                if field not in val:
                    attrs[key][field] = NODE_GROUP_ALIASES['cxx'] if field == 'allowed_on' else []
                else:
                    res = []
                    for node in val[field]:
                        if node in NODE_GROUP_ALIASES:
                            res.extend(NODE_GROUP_ALIASES[node])
                        else:
                            res.append(node)
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
                        raise YamlKeyDuplicationError(
                            f"Definition with duplicate '{flat_key}' key "
                            f"in line {src_dict[cls.VARS_RULE_KEY].line_number} "
                            f"of {src_dict[cls.VARS_RULE_KEY].file} file,\n"
                            f"which already has been previously defined "
                            f"in line {ctx_def_map[flat_key].line_number} "
                            f"of {ctx_def_map[flat_key].file} file")
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
                raise YamlKeyDuplicationError(f"Redefinition of '{cls.ROOT_SECTION_KEY}' "
                                              f"section in line {root_section.line_number} "
                                              f"of {root_section.file} file, which must be "
                                              f"uniquely specified only in one file.\n"
                                              f"It was previously defined in line "
                                              f"{ctx_def_map[RootNode.ROOT_KEY].line_number} "
                                              f"of {ctx_def_map[RootNode.ROOT_KEY].file} file.")
            ctx_def_map[RootNode.ROOT_KEY] = attrs[cls.ROOT_SECTION_KEY]

        for section in (cls.DIR_SECTION_KEY, cls.FILE_SECTION_KEY, cls.TYPE_SECTION_KEY):
            if section in attrs:
                for item in attrs[section]:
                    flatten_dict(item, section, [])

        if cls.VAR_DEF_SECTION_KEY in attrs:
            ctx_def_map[cls.VAR_DEF_SECTION_KEY] = attrs[cls.VAR_DEF_SECTION_KEY]

        cls.load_merge_rules(attrs, ctx_def_map)

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

        def merge_section(section_key, global_section_value, platform, language):
            """
            Method to lookup with current section key and merge contents
            """
            for key in (platform + '.' + language + '.' + section_key,
                        platform + '.' + section_key,
                        language + '.' + section_key,
                        section_key):
                if key in current_rules:
                    merge_rules(current_rules[key], global_section_value[plat][lang], [])

        current_rules = attrs.get(ContextDescriptor.RULE_SECTION_KEY)
        if current_rules:
            global_code_snippets = ctx_def_map.setdefault(ContextDescriptor.CODE_SNIPPETS_KEY,
                                                          defaultdict(lambda: defaultdict(dict)))
            global_type_converters = ctx_def_map.setdefault(ContextDescriptor.TYPE_CONVERTER_SNIPPETS_KEY,
                                                            defaultdict(lambda: defaultdict(dict)))
            global_actions = ctx_def_map.setdefault(ContextDescriptor.ACTION_SNIPPETS_KEY,
                                                    defaultdict(lambda: defaultdict(list)))

            for plat in default_config.platforms:
                for lang in default_config.languages:
                    merge_section(ContextDescriptor.CODE_SNIPPETS_KEY,
                                  global_code_snippets,
                                  plat,
                                  lang)
                    merge_section(ContextDescriptor.TYPE_CONVERTER_SNIPPETS_KEY,
                                  global_type_converters,
                                  plat,
                                  lang)
                    merge_section(ContextDescriptor.ACTION_SNIPPETS_KEY,
                                  global_actions,
                                  plat,
                                  lang)

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

    def validate_var_def(self):
        """Method for variables definition validation"""
        for var_name, prop in self.get_var_def().items():
            extra_nodes = set(prop['required_on']) - set(prop['allowed_on'])
            if extra_nodes:
                Error.error(f"Variable '{var_name}' is required on '{', '.join(extra_nodes)}' "
                            f"node{'s' if len(extra_nodes) > 1 else ''}, while it's not allowed on "
                            f"{'them' if len(extra_nodes) > 1 else 'it'}",
                            prop.file,
                            prop.line_number)

    def get_raw_var_def(self):
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
