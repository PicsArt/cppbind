"""
Processor module provides various processor for ieg parser
"""
import copy
import datetime
import os
from collections import OrderedDict
from types import SimpleNamespace

from git import Repo, GitError

from iegen import DATETIME_FORMAT
from iegen.builder import OUTPUT_MODIFICATION_KEY
from iegen.common.error import Error
from iegen.ir.ast import (
    CXXNode,
    DirectoryNode,
    FileNode,
    NodeType,
    RootNode
)
from iegen.parser.ieg_api_parser import APIParser
from iegen.utils.clang import get_full_displayname


class CXXPrintProcessor:
    """Class to show an information about a cursor"""
    def __call__(self, cursor, *args, **kwargs):
        print(f'Found {cursor.kind} Display name {cursor.displayname} \
              [line={cursor.location.line}, \
              col={cursor.location.column}]',
              f'Comments {cursor.raw_comment} Brief Comments {cursor.brief_comment}')


class CXXIEGIRBuilder:
    """
    Class to build intermediate representation.
    """

    def __init__(self, ctx_mgr):
        self.ctx_mgr = ctx_mgr
        self.ir = RootNode()
        self.node_stack = []
        self._sys_vars = {}
        self._processed_dirs = {}
        # cache for holding parent args
        self._parent_arg_mapping = {}

    def start_root(self):
        """
        Create root node and eval its context.
        """
        root_node = self.ir
        self.node_stack.append(root_node)
        self.__update_internal_vars(root_node)
        ctx = self.get_full_ctx()
        api, args = self.ctx_mgr.eval_root_attrs(root_node.name, ctx)
        root_node.api = api
        root_node.args = args
        return args

    def end_root(self):
        assert self.node_stack, "stack should not be empty"
        node = self.node_stack.pop()
        assert node.name == RootNode.ROOT_KEY
        assert len(self.node_stack) == 0, "stack should be empty"

    def start_dir(self, dir_name):
        """
        Create directory node and eval its context.
        """
        if dir_name not in self._processed_dirs:
            file_name = None
            if self.ctx_mgr.has_yaml_api(dir_name):
                file_name = self.ctx_mgr.get_api_def_filename(dir_name)

            dir_node = DirectoryNode(dir_name, file_name=file_name)
            self.node_stack.append(dir_node)
            self.__update_internal_vars(dir_node)
            ctx = self.get_full_ctx()
            location = SimpleNamespace(file_name=dir_node.file_name,
                                       line_number=dir_node.line_number)
            api, args = self.ctx_mgr.eval_dir_attrs(dir_name, ctx, location)
            dir_node.api = api
            dir_node.args = args
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
        """
        Create file node and eval its context.
        """
        current_node = FileNode(tu.cursor)
        current_node.args = OrderedDict()
        self.node_stack.append(current_node)
        self.__update_internal_vars(current_node)
        ctx = self.get_full_ctx()

        res = self.ctx_mgr.eval_file_attrs(tu.spelling, ctx)
        if res:
            api, args = res
            current_node.api = api
            current_node.args = args

    def end_tu(self, tu, *args, **kwargs):
        tu_node = self.node_stack.pop()
        if tu_node.api or tu_node.children:  # node has API call or child whit API call
            if len(self.node_stack) > 0:
                parent_node = self.node_stack[-1]
                parent_node.add_children(tu_node)
        # tu is processed it cannot be a parent anymore delete it's args if they're present
        self._parent_arg_mapping.pop(tu_node.full_displayname, None)

    def start_cursor(self, cursor, *args, **kwargs):
        """
        Create a node wrapper for current cursor and eval its context.
        """
        current_node = CXXNode(cursor)
        self.node_stack.append(current_node)
        self.__update_internal_vars(current_node)

        pure_comment = api_section = None
        if APIParser.has_api(cursor.raw_comment):
            pure_comment, api_section = APIParser.separate_pure_and_api_comment(cursor.raw_comment)

        ctx = self.get_full_ctx(pure_comment)
        location = SimpleNamespace(file_name=cursor.extent.start.file.name,
                                   line_number=cursor.extent.start.line)

        res = self.ctx_mgr.eval_clang_attrs(get_full_displayname(cursor),
                                            current_node.kind_name,
                                            api_section,
                                            ctx,
                                            location)
        if res:
            api, args = res
            current_node.api = api
            current_node.args = args
            current_node.pure_comment = pure_comment

    def get_parent_args(self):
        """
        Get context from the nearest parent which has API.
        """
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
        """
        Update internal variables depending current node type.
        """
        if node.type == NodeType.ROOT_NODE:
            sys_vars = {'path': os.path}
        else:
            sys_vars = {
                '_output_modification_time': OUTPUT_MODIFICATION_KEY,
                'path': os.path,
                '_current_working_dir': os.getcwd(),
                '_pure_comment': '',
                '_line_number': node.line_number,
                '_file_full_name': node.file_name,
            }

        if node.type == NodeType.DIRECTORY_NODE:
            sys_vars.update({
                '_source_modification_time': CXXIEGIRBuilder._get_modification_time(node.name),
                '_is_operator': False,
                '_object_name': node.name,
                '_file_name': os.path.splitext(os.path.basename(
                    node.file_name))[0] if node.file_name else node.name,
            })

        elif node.type == NodeType.CLANG_NODE:
            sys_vars.update({
                '_source_modification_time': CXXIEGIRBuilder._get_modification_time(node.file_name),
                '_is_operator': node.clang_cursor.displayname.startswith('operator'),
                '_object_name': node.clang_cursor.spelling,
                '_file_name': os.path.splitext(os.path.basename(node.file_name))[0],
            })

        self._sys_vars.update(sys_vars)

    @staticmethod
    def _get_modification_time(path):
        """Get last modification time of current file"""
        modification_time = datetime.datetime.fromtimestamp(os.stat(path).st_ctime)
        return datetime.date.strftime(modification_time, DATETIME_FORMAT)

    def get_sys_vars(self):
        """
        Get system variables and add git repo url of project directory.
        """
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
            return None

        sys_vars['_get_git_repo_url'] = _get_git_repo_url

        return sys_vars

    def end_cursor(self, cursor, *args, **kwargs):
        node = self.node_stack.pop()
        if node.api or node.children:  # node has API call or child with API call
            parent_node = self.node_stack[-1]
            parent_node.add_children(node)
        # cursor is processed it cannot be a parent anymore delete it's args if they're present
        self._parent_arg_mapping.pop(node.full_displayname, None)

    def get_full_ctx(self, pure_comment=None):
        """
        Construct full context: system variables + pure comment + parent context
        """
        ctx = self.get_sys_vars()
        if pure_comment is None:
            current_node = self.node_stack[-1]
            if current_node.type == NodeType.CLANG_NODE and current_node.clang_cursor.raw_comment:
                pure_comment, _ = APIParser.separate_pure_and_api_comment(
                    current_node.clang_cursor.raw_comment)
        if pure_comment:
            ctx['_pure_comment'] = '\n'.join(pure_comment)

        parent_args = self.get_parent_args()
        if parent_args:
            ctx.update(parent_args)
        return ctx
