"""
Processor module provides various processor for ieg parser
"""
import copy
import os
from collections import OrderedDict
from types import SimpleNamespace

from git import Repo, GitError
from jinja2.exceptions import UndefinedError as JinjaUndefinedError

from iegen import default_config as default_config
from iegen.common import JINJA_ENV
from iegen.common.error import Error
from iegen.ir.ast import DirectoryNode, CXXNode, NodeType, FileNode
from iegen.ir.ast import RootNode
from iegen.parser.ieg_api_parser import APIParser

ALL_LANGUAGES = sorted(list(default_config.languages))
ALL_PLATFORMS = sorted(list(default_config.platforms))

NODE_GROUP_ALIASES = {
    'file_system': ('dir', 'file'),
    'cxx': (
        'class', 'class_template', 'struct', 'struct_template', 'constructor',
        'function', 'function_template', 'cxx_method', 'enum', 'field'
    )
}


class CXXPrintProcsessor(object):

    def __call__(self, cursor, *args, **kwargs):
        print(f'Found {cursor.kind} Display name {cursor.displayname} \
              [line={cursor.location.line}, \
              col={cursor.location.column}]',
              f'Comments {cursor.raw_comment} Brief Comments {cursor.brief_comment}')


class CXXIEGIRBuilder(object):
    """
    Class to build intermediate representation.
    """

    def __init__(self, platform, language, attributes=None, api_start_kw=None, parser_config=None):
        attributes = attributes or default_config.attributes
        api_start_kw = api_start_kw or default_config.api_start_kw
        self.attributes = CXXIEGIRBuilder.process_attributes(attributes)
        self.ieg_api_parser = APIParser(self.attributes, api_start_kw, ALL_LANGUAGES, ALL_PLATFORMS, parser_config)
        self.ir = RootNode()
        self.node_stack = []
        self._sys_vars = {}
        self._processed_dirs = {}
        # cache for holding parent args
        self._parent_arg_mapping = {}
        self.platform = platform
        self.language = language

    def start_root(self):
        root_node = self.ir
        self.node_stack.append(root_node)
        self.__update_internal_vars(root_node)
        args = pure_comment = None
        api = root_node.api
        ctx = self.get_full_ctx()
        parsed_api = self.ieg_api_parser.parse_yaml_api(root_node.name, ctx)
        if parsed_api:
            api, args, pure_comment = parsed_api
        self.__process_attrs(root_node, args, api, pure_comment)

    def end_root(self):
        assert self.node_stack, "stack should not be empty"
        node = self.node_stack.pop()
        assert node.name == RootNode.ROOT_KEY
        assert len(self.node_stack) == 0, "stack should be empty"

    def start_dir(self, dir_name):
        if dir_name not in self._processed_dirs:
            dir_node = DirectoryNode(dir_name, file_name=self.ieg_api_parser.yaml_api_file_name(dir_name))
            self.node_stack.append(dir_node)
            self.__update_internal_vars(dir_node)
            args = api = pure_comment = None
            ctx = self.get_full_ctx()
            parsed_api = self.ieg_api_parser.parse_yaml_api(dir_name, ctx)
            if parsed_api:
                api, args, pure_comment = parsed_api
            self.__process_attrs(dir_node, args, api, pure_comment, ctx)
        else:
            # directory is already processed
            dir_node = self._processed_dirs[dir_name]
            self.node_stack.append(dir_node)

    def end_dir(self, dir_name):
        assert self.node_stack, "stack should not be empty"
        node = self.node_stack.pop()
        assert node.name == dir_name
        # node is not processed and has an API call or child with API call
        if node.name not in self._processed_dirs and (node.api or node.children):
            if len(self.node_stack) > 0:
                parent_node = self.node_stack[-1]
                if node not in parent_node.children:
                    parent_node.add_children(node)
        self._processed_dirs[dir_name] = node

    def start_tu(self, tu, *args, **kwargs):
        current_node = FileNode(tu.cursor)
        current_node.args = OrderedDict()
        self.node_stack.append(current_node)
        self.__update_internal_vars(current_node)

        ctx = self.get_full_ctx()
        parsed_api = self.ieg_api_parser.parse_yaml_api(tu.spelling, ctx)

        if parsed_api:
            api, args, pure_comment = parsed_api
            self.__process_attrs(current_node, args, api, pure_comment)

    def end_tu(self, tu, *args, **kwargs):
        tu_node = self.node_stack.pop()
        if tu_node.api or tu_node.children:  # node has API call or child whit API call
            if len(self.node_stack) > 0:
                parent_node = self.node_stack[-1]
                parent_node.add_children(tu_node)
        # tu is processed it cannot be a parent anymore delete it's args if they're present
        self._parent_arg_mapping.pop(tu_node.full_displayname, None)

    def start_cursor(self, cursor, *args, **kwargs):
        current_node = CXXNode(cursor)
        self.node_stack.append(current_node)
        self.__update_internal_vars(current_node)

        ctx = self.get_full_ctx()

        api_parser_result = self.ieg_api_parser.parse_api(cursor, ctx)
        if not api_parser_result:
            return

        api, args, pure_comment = api_parser_result

        self.__process_attrs(current_node, args, api, pure_comment, ctx)

    def __process_attrs(self, current_node, args, api, pure_comment, ctx=None):
        args = args or OrderedDict()
        context = ctx or self.get_ctx(pure_comment)
        parent_args = self._get_parent_args()

        # add all missing attributes
        for plat in ALL_PLATFORMS + ["__all__"]:
            for lang in ALL_LANGUAGES + ["__all__"]:
                context.update(self.get_ctx_by_plat_lang(plat, lang, parent_args))
                for att_name, properties in self.attributes.items():
                    att_val = args.get(
                        att_name,
                        {}
                    ).get(plat, {}).get(lang, None)

                    new_att_val = att_val
                    node_kind = current_node.kind_name
                    allowed = node_kind in properties["allowed_on"]
                    if new_att_val is None:
                        # check mandatory attribute existence
                        if node_kind in properties["required_on"]:
                            Error.error(f"Attribute '{att_name}' is mandatory attribute on {node_kind}.",
                                        current_node.file_name,
                                        current_node.line_number)
                            break

                        # inherit from parent or add default value
                        if properties["inheritable"]:
                            # directory based nodes may not have parent
                            self._parent_args = self._get_parent_args()
                            if self._parent_args:
                                new_att_val = self._parent_args.get(
                                    att_name,
                                    {}
                                ).get(plat, {}).get(lang, None)

                        if allowed:
                            if new_att_val is None:
                                # use default value
                                new_att_val = CXXIEGIRBuilder.get_attr_default_value(properties, plat, lang)
                                if isinstance(new_att_val, str):
                                    try:
                                        new_att_val = JINJA_ENV.from_string(new_att_val).render(context)
                                    except JinjaUndefinedError as e:
                                        Error.critical(
                                            f"Jinja evaluation error in attributes definition file {default_config.attr_file}: {e}")
                    else:
                        # attribute is set check weather or not it is allowed.
                        if not allowed:
                            Error.error(f"Attribute {att_name} is not allowed on {node_kind}.",
                                        current_node.file_name,
                                        current_node.line_number)
                            break

                    # now we need to process variables of value and set value
                    if new_att_val is not None:
                        if isinstance(new_att_val, str):
                            # sys vars can have different types than string parse to get correct type
                            new_att_val = self.ieg_api_parser.parse_attr(att_name, new_att_val)
                        # add attr to current node context so that it can be used for coming attributes
                        context[att_name] = new_att_val
                        args.setdefault(att_name, OrderedDict()).setdefault(plat, OrderedDict())[lang] = new_att_val

        current_node.api = api
        current_node.pure_comment = pure_comment
        assert args is not None
        current_node.args = args

    def _get_parent_args(self):
        if len(self.node_stack) < 2:
            return None
        direct_parent_name = self.node_stack[-2].full_displayname
        if direct_parent_name in self._parent_arg_mapping:
            return self._parent_arg_mapping[direct_parent_name]
        parents = reversed(self.node_stack[:-1])
        parent_args = None
        for parent in parents:
            if parent.api:
                parent_args = parent.args
                break
        self._parent_arg_mapping[direct_parent_name] = parent_args
        return parent_args

    def __update_internal_vars(self, node):
        if node.type == NodeType.ROOT_NODE:
            sys_vars = {'path': os.path}
        else:
            sys_vars = {
                'path': os.path,
                '_current_working_dir': os.getcwd(),
                '_pure_comment': '',
                '_line_number': node.line_number,
                '_file_full_name': node.file_name,
            }

        if node.type == NodeType.DIRECTORY_NODE:
            sys_vars.update({
                '_is_operator': False,
                '_object_name': node.name,
                '_file_name': os.path.splitext(os.path.basename(node.file_name))[0] if node.file_name else node.name,
            })

        elif node.type == NodeType.CLANG_NODE:
            sys_vars.update({
                '_is_operator': node.clang_cursor.displayname.startswith('operator'),
                '_object_name': node.clang_cursor.spelling,
                '_file_name': os.path.splitext(os.path.basename(node.file_name))[0],
            })

        self._sys_vars.update(sys_vars)

    def get_sys_vars(self):
        sys_vars = copy.copy(self._sys_vars)

        def _get_git_repo_url(project_dir=None):
            if project_dir:
                try:
                    repo = Repo(project_dir)
                    url = next(repo.remote().urls).replace('.git', '')
                    branch = repo.active_branch.name
                    return f'{url}/tree/{branch}/'
                except (GitError, TypeError):
                    # not a git repo leave variable empty
                    # TypeError may be thrown in case of incorrect reference to a git commit
                    Error.warning(
                        f'Could not find a git repository under: {project_dir}.')
                    return ''

        sys_vars['_get_git_repo_url'] = _get_git_repo_url

        return sys_vars

    def end_cursor(self, cursor, *args, **kwargs):
        node = self.node_stack.pop()
        if node.api or node.children:  # node has API call or child with API call
            parent_node = self.node_stack[-1]
            if not node.api:
                self.__process_attrs(node, None, None, None)
            parent_node.add_children(node)
        # cursor is processed it cannot be a parent anymore delete it's args if they're present
        self._parent_arg_mapping.pop(node.full_displayname, None)

    @staticmethod
    def get_attr_default_value(prop, plat, lang):
        def_val = prop.get("default")

        if not isinstance(def_val, dict):
            return def_val

        if plat in def_val and lang in def_val:
            Error.critical(
                f"Conflict of attributes in {default_config.attr_file} attributes definiton file: {plat} and {lang}: "
                f"only one of them must be defined separately, or they must be both specified")

        for key in (plat + '.' + lang, plat, lang, 'else'):
            if key in def_val:
                return def_val[key]

    def get_ctx(self, pure_comment=None):
        ctx = self.get_sys_vars()
        if pure_comment is None:
            current_node = self.node_stack[-1]
            if current_node.type == NodeType.CLANG_NODE and current_node.clang_cursor.raw_comment:
                pure_comment, _ = self.ieg_api_parser.separate_pure_and_api_comment(
                    current_node.clang_cursor.raw_comment)
                if pure_comment:
                    ctx['_pure_comment'] = '\n'.join(pure_comment)
        return ctx

    def get_ctx_by_plat_lang(self, plat=None, lang=None, parent_args=None):
        plat = plat or self.platform
        lang = lang or self.language
        parent_args = parent_args or self._get_parent_args()
        ctx = {}
        if parent_args:
            for attr in parent_args:
                val = parent_args[attr].get(plat, {}).get(lang)
                if val is not None:
                    ctx[attr] = val
        return ctx

    def get_full_ctx(self):
        ctx = self.get_ctx()
        ctx.update(self.get_ctx_by_plat_lang())
        return ctx

    @staticmethod
    def process_attributes(attrs):
        """
        A function to replace node group aliases with their actual values list
        """

        for field in ['allowed_on', 'required_on']:
            for key, val in attrs.items():
                if not field in val:
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
