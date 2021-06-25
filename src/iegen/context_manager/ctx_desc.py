import copy
import glob
import os
from types import SimpleNamespace
import yaml

from iegen.common import PROJECT_CONFIG_DIR
from iegen.common.config import config
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

    def __init__(self, context_def_glob, platform, language):
        self.platform = platform
        self.language = language
        self.ctx_def_map = self.build_ctx_def_map(context_def_glob)
        self.var_def = ContextDescriptor.resolve_attr_aliases(self.get_var_def())

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

    def build_ctx_def_map(self, context_def_glob):
        if context_def_glob is None:
            return {}

        files = set()
        for file in context_def_glob.split(','):
            files_glob = glob.glob(file.strip(), recursive=True)
            for fp in files_glob:
                files.add(os.path.abspath(fp))

        dirs = [PROJECT_CONFIG_DIR]
        if hasattr(config.application, 'custom_config_dir'):
            dirs.append(config.application.custom_config_dir)

        ctx_def_map = {}
        for current_file in list(files):
            try:
                attrs = load_yaml(current_file, dirs=[PROJECT_CONFIG_DIR])
            except yaml.YAMLError as e:
                raise yaml.YAMLError(f"Wrong yaml format: {current_file}: {e}")

            if attrs:
                self.load_merge_ctx_def_map(attrs, current_file, ctx_def_map)

        return ctx_def_map

    def load_merge_ctx_def_map(self, attrs, current_file, ctx_def_map):
        cls = self.__class__

        def flatten_dict(src_dict, section_key, ancestors):
            cls.validate_section_keys(src_dict, section_key)
            cls.TYPE_RULE_KEY in src_dict and ancestors.append(src_dict[cls.TYPE_RULE_KEY])
            try:
                if cls.VARS_RULE_KEY in src_dict:
                    flat_key = cls._get_key(current_file=current_file,
                                            src_dict=src_dict,
                                            ancestors=ancestors)
                    if flat_key in ctx_def_map:
                        raise YamlKeyDuplicationError(
                            f"Definition with duplicate '{flat_key}' key in {current_file},\n"
                            f"which already has been previously defined in {ctx_def_map[flat_key].file}")
                    ctx_def_map[flat_key] = SimpleNamespace(attr=src_dict[cls.VARS_RULE_KEY],
                                                            file=current_file)
                if cls.SUB_RULE_KEY in src_dict:
                    for sub in src_dict[cls.SUB_RULE_KEY]:
                        flatten_dict(sub, section_key, ancestors)
            finally:
                cls.TYPE_RULE_KEY in src_dict and ancestors.pop()

        if cls.ROOT_SECTION_KEY in attrs:
            if RootNode.ROOT_KEY in ctx_def_map:
                raise YamlKeyDuplicationError(f"Redefinition of '{cls.ROOT_SECTION_KEY}' section in {current_file} file, "
                                              f"which must be uniquely specified only in one file.\n"
                                              f"It was previously defined in {ctx_def_map[RootNode.ROOT_KEY].file} file.")
            ctx_def_map[RootNode.ROOT_KEY] = SimpleNamespace(attr=attrs[cls.ROOT_SECTION_KEY],
                                                             file=current_file)

        for section in (cls.DIR_SECTION_KEY, cls.FILE_SECTION_KEY, cls.TYPE_SECTION_KEY):
            if section in attrs:
                for item in attrs[section]:
                    flatten_dict(item, section, [])

        if cls.VAR_DEF_SECTION_KEY in attrs:
            ctx_def_map[cls.VAR_DEF_SECTION_KEY] = attrs[cls.VAR_DEF_SECTION_KEY]

        self.load_merge_rules(attrs, current_file, ctx_def_map)

    @classmethod
    def _get_key(cls, src_dict, current_file, ancestors):
        # dir
        if cls.DIR_RULE_KEY in src_dict:
            dir_name = src_dict[cls.DIR_RULE_KEY]
            if os.path.isabs(dir_name):
                # if an absolute path is specified then we assume it's absolute to current dir
                return dir_name.replace('/', '', 1) or '.'
            else:
                return os.path.relpath(
                    os.path.abspath(os.path.join(os.path.dirname(current_file), dir_name)),
                    os.getcwd())
        # file
        elif cls.FILE_RULE_KEY in src_dict:
            file_name = src_dict[cls.FILE_RULE_KEY]
            if os.path.isabs(file_name):
                # if an absolute path is specified then we assume it's absolute to current dir
                flat_key = file_name.replace('/', '', 1)
                return os.path.join(flat_key, os.getcwd())
            else:
                return os.path.abspath(os.path.join(os.path.dirname(current_file), file_name))
        # type
        elif cls.VARS_RULE_KEY in src_dict:
            return join_type_parts(ancestors)

    def load_merge_rules(self, attrs, file, ctx_def_map):
        def merge_rules(rules, rules_map, path, files_info):
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
                    if isinstance(val, dict) and isinstance(rules_map[key], dict):
                        merge_rules(val, rules_map[key], path, files_info[key].value)
                    else:
                        Error.critical(f"Redefinition of '{'.'.join(path)}' key section in {file} file,\n"
                                       f"which already has been defined in {files_info[key].file}")
                else:
                    rules_map[key] = val
                    insert_file_info(files_info, key, val)
                path.pop()

        def insert_file_info(tree, key, val):
            val = copy.deepcopy(val)
            tree[key] = SimpleNamespace(file=file, value=val)
            if isinstance(val, dict):
                for k, v in val.items():
                    insert_file_info(val, k, v)

        def merge_section(section_key, global_section_value, files_info=None):
            """
            Method to lookup with current section key and merge contents
            """
            for key in (self.platform + '.' + self.language + '.' + section_key,
                        self.platform + '.' + section_key,
                        self.language + '.' + section_key,
                        section_key):
                if key in current_rules:
                    merge_rules(current_rules[key], global_section_value, [], files_info)

        current_rules = attrs.get(ContextDescriptor.RULE_SECTION_KEY)
        if current_rules:
            global_code_snippets = ctx_def_map.setdefault(ContextDescriptor.CODE_SNIPPETS_KEY, {})
            global_type_converters = ctx_def_map.setdefault(ContextDescriptor.TYPE_CONVERTER_SNIPPETS_KEY, {})
            global_actions = ctx_def_map.setdefault(ContextDescriptor.ACTION_SNIPPETS_KEY, [])

            code_snippets_files_info = ctx_def_map.setdefault('code_snippets_files', {})
            type_converters_files_info = ctx_def_map.setdefault('type_converters_files', {})

            merge_section(ContextDescriptor.CODE_SNIPPETS_KEY,
                          global_code_snippets,
                          code_snippets_files_info)
            merge_section(ContextDescriptor.TYPE_CONVERTER_SNIPPETS_KEY,
                          global_type_converters,
                          type_converters_files_info)
            merge_section(ContextDescriptor.ACTION_SNIPPETS_KEY,
                          global_actions)

    @classmethod
    def validate_section_keys(cls, src_dict, section_key):
        if section_key == cls.FILE_SECTION_KEY and (cls.DIR_RULE_KEY in src_dict or cls.TYPE_RULE_KEY in src_dict):
            Error.critical(f"API file section definition can only contain '{cls.FILE_RULE_KEY}' key")
        elif section_key == cls.DIR_SECTION_KEY and (cls.FILE_RULE_KEY in src_dict or cls.TYPE_RULE_KEY in src_dict):
            Error.critical(f"API dir section definition can only contain '{cls.DIR_RULE_KEY}' key")
        elif section_key == cls.TYPE_SECTION_KEY and (cls.DIR_RULE_KEY in src_dict or cls.FILE_RULE_KEY in src_dict):
            Error.critical(f"API type section definition can only contain '{cls.TYPE_RULE_KEY}' key")

    def get_var_def(self):
        return self.ctx_def_map.get(ContextDescriptor.VAR_DEF_SECTION_KEY, {})

    def get_code_snippets(self):
        return self.ctx_def_map.get(ContextDescriptor.CODE_SNIPPETS_KEY, {})

    def get_type_converter_snippets(self):
        return self.ctx_def_map.get(ContextDescriptor.TYPE_CONVERTER_SNIPPETS_KEY, {})

    def get_action_snippets(self):
        return self.ctx_def_map.get(ContextDescriptor.ACTION_SNIPPETS_KEY, [])
