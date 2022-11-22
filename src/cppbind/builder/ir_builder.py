# Copyright (c) 2022 PicsArt, Inc.
# All rights reserved. Use of this source code is governed by a
# MIT-style license that can be found in the LICENSE file.

"""
Processor module provides various processor for cppbind parser
"""
import copy
import datetime
import os
import sys
from collections import OrderedDict
from types import SimpleNamespace

from cppbind import DATETIME_FORMAT, logging, PROJECT_CONFIG_DIR
from cppbind.builder import OUTPUT_MODIFICATION_KEY
from cppbind.common.error import Error
from cppbind.ir.ast import (
    CXXNode,
    DirectoryNode,
    FileNode,
    NodeType,
    RootNode
)
from cppbind.parser.cppbind_api_parser import APIParser
from cppbind.utils import get_android_ndk_sysroot
import clang.cindex as cli
import cppbind.utils.clang as cutil

try:
    import git
except ImportError as e:
    Error.warning("Couldn't find Git. '_get_git_repo_url' system variable will not work properly.")


class CXXPrintProcessor:
    """Class to show an information about a cursor"""
    def __call__(self, cursor, *args, **kwargs):
        print(f'Found {cursor.kind} Display name {cursor.displayname} \
              [line={cursor.location.line}, \
              col={cursor.location.column}]',
              f'Comments {cursor.raw_comment} Brief Comments {cursor.brief_comment}')


class CppBindIRBuilder:
    """
    Class to build intermediate representation.
    """

    def __init__(self, ir, ctx_mgr):
        self.ir = ir
        self.ctx_mgr = ctx_mgr
        self.node_stack = []
        self._sys_vars = {}
        self._processed_dirs = {}
        # cache for holding parent args
        self._parent_arg_mapping = {}
        # list to keep processed file by processing order
        self.processed_api_files = []

    def start_root(self, var_values=None):
        """
        Create root node and eval its context.
        """
        root_node = self.ir
        self.node_stack.append(root_node)
        self.__update_internal_vars(root_node)

        ctx = self.get_full_ctx()
        # update context with initial context provided via command line arguments
        var_values = self.ctx_mgr.filter_by_plat_lang(var_values)

        api, args = self.ctx_mgr.eval_root_attrs(ctx, var_values)
        root_node.api = api
        root_node.args = args

        return args

    def end_root(self):
        assert self.node_stack, "stack should not be empty"
        node = self.node_stack.pop()
        assert node.name == RootNode.ROOT_KEY
        assert len(self.node_stack) == 0, "stack should be empty"
        # set flag which shows that IR built process is completed
        self.ir._finalize_ir_build(self.processed_api_files)

    def start_dir(self, dir_name):
        """
        Create directory node and eval its context.
        """
        if dir_name not in self._processed_dirs:
            file_name = None
            if self.ctx_mgr.ctx_desc.has_yaml_api(dir_name):
                file_name = self.ctx_mgr.ctx_desc.get_api_def_filename(dir_name)

            dir_node = DirectoryNode(dir_name, file_name=file_name, root=self.ir)
            self.node_stack.append(dir_node)
            self._processed_dirs[dir_name] = dir_node

            self.__update_internal_vars(dir_node)
            ctx = self.get_full_ctx()
            if self.ctx_mgr.ctx_desc.has_yaml_api(dir_name):
                # in case dir has a yaml api, yaml node location can be used to report errors properly
                location = None
            else:
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
        assert isinstance(node, DirectoryNode), "Should be a directory node"
        assert node.name == dir_name
        # has an API call or child with API call
        if node.api or node.children:
            if len(self.node_stack) > 0:
                if not isinstance(self.node_stack[-1], DirectoryNode):
                    parent_node = self.node_stack[0]
                else:
                    parent_node = self.node_stack[-1]
                if node not in parent_node.children:
                    parent_node.add_child(node)

    def start_file(self, file_name, *args, **kwargs):
        """
        Create file node(can be an include) and eval its context.
        """
        current_node = FileNode(file_name, root=self.ir)
        current_node.args = OrderedDict()
        self.node_stack.append(current_node)
        self.processed_api_files.append(file_name)

        self.__update_internal_vars(current_node)
        ctx = self.get_full_ctx()

        res = self.ctx_mgr.eval_file_attrs(file_name, ctx)
        if res:
            api, args = res
            current_node.api = api
            current_node.args = args

    def end_file(self, file_name):
        """
        Ends current file from node stack and adds it to parent node if it has an api or has children with api.
        """
        tu_node = self.node_stack.pop()
        assert isinstance(tu_node, FileNode), "Should be a file node"
        assert tu_node.spelling == file_name
        if tu_node.api or tu_node.children:  # node has API call or child whit API call
            parent_node = self.node_stack[-1]
            parent_node.add_child(tu_node)
        else:
            # file is not added to IR, remove it from processed list
            self.processed_api_files.remove(file_name)

        # tu is processed it cannot be a parent anymore delete it's args if they're present
        self._parent_arg_mapping.pop(tu_node.full_displayname, None)

    def start_cursor(self, cursor, *args, **kwargs):
        """
        Create a node wrapper for current cursor and eval its context.
        """
        current_node = self.__get_node(cursor)
        self.node_stack.append(current_node)

        cursor_display_name = current_node.full_displayname

        if current_node.api is not None or (not APIParser.has_api(cursor.raw_comment) and
                                            not self.ctx_mgr.ctx_desc.has_yaml_api(cursor_display_name)):
            return

        self.__update_internal_vars(current_node)

        pure_comment = api_section = None
        if APIParser.has_api(cursor.raw_comment):
            pure_comment, api_section = APIParser.separate_pure_and_api_comment(cursor.raw_comment)

        ctx = self.get_full_ctx(pure_comment)
        if self.ctx_mgr.ctx_desc.has_yaml_api(cursor_display_name):
            # in case type has a yaml api, yaml node location can be used to report errors properly
            location = None
        else:
            location = SimpleNamespace(file_name=cursor.extent.start.file.name,
                                       line_number=cursor.extent.start.line)

        res = self.ctx_mgr.eval_clang_attrs(cursor_display_name,
                                            current_node.kind_name,
                                            api_section,
                                            ctx,
                                            location)
        if res:
            api, args = res
            current_node.api = api
            current_node.args = args
            current_node.pure_comment = pure_comment

    def end_cursor(self, cursor, *args, **kwargs):
        node = self.node_stack.pop()
        assert isinstance(node, CXXNode), "Should be a cxx node"
        if node.api or node.children:
            # node has API call or child with API call
            parent_node = self.node_stack[-1]
            parent_node.add_child(node)
        # cursor is processed it cannot be a parent anymore delete it's args if they're present
        self._parent_arg_mapping.pop(node.full_displayname, None)

    def __get_node(self, cursor):
        """Private method to create a new cxx node or return the cached one if it has been created earlier"""
        lookup_name = cutil.get_signature(cursor)
        node = self.ir.find_node(lookup_name)
        if node is not None:
            return node

        return CXXNode(cursor, root=self.ir)

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
                var_def = self.ctx_mgr.ctx_desc.get_var_def()
                # select only those variables which has 'inheritable' property set to true
                # in order not to have redundant values in context when passing to child nodes
                parent_args = {name: val for name, val in parent.args.items()
                               if var_def[name].get('inheritable')}
                break
        self._parent_arg_mapping[direct_parent_name] = parent_args
        return parent_args

    def __update_internal_vars(self, node):
        """
        Update internal variables depending current node type.
        """
        if node.type == NodeType.ROOT_NODE:
            sys_vars = {
                '_output_modification_time': OUTPUT_MODIFICATION_KEY,
                '_current_working_dir': os.getcwd(),
                'path': os.path,
                '_cppbind_extras_dir': PROJECT_CONFIG_DIR,
                'getenv': os.getenv,
                'get_android_ndk_sysroot': get_android_ndk_sysroot,
                '_object_kind': node.kind_name
            }
        else:
            sys_vars = {
                '_output_modification_time': OUTPUT_MODIFICATION_KEY,
                'path': os.path,
                'getenv': os.getenv,
                '_current_working_dir': os.getcwd(),
                '_pure_comment': '',
                '_line_number': node.line_number,
                'source_file_fullname': node.file_name,
                '_object_kind': node.kind_name
            }

        if node.type == NodeType.DIRECTORY_NODE:
            sys_vars.update({
                '_source_modification_time': CppBindIRBuilder._get_modification_time(node.name),
                '_object_name': node.name,
                '_file_name': os.path.splitext(os.path.basename(
                    node.file_name))[0] if node.file_name else node.name,
            })

        elif node.type == NodeType.FILE_NODE:
            # we have a virtual file like extra_includes.cpp so setting mod_time None for these type of files
            mod_time = CppBindIRBuilder._get_modification_time(node.file_name) if os.path.exists(
                node.file_name) else None
            sys_vars.update({
                '_source_modification_time': mod_time,
                '_object_name': node.spelling,
                '_file_name': os.path.splitext(os.path.basename(node.file_name))[0],
            })

        elif node.type == NodeType.CLANG_NODE:
            sys_vars.update({
                '_source_modification_time': CppBindIRBuilder._get_modification_time(node.file_name),
                '_is_operator': node.displayname.startswith('operator'),
                '_object_name': node.spelling,
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

        def _get_git_repo_url(project_dir):
            if 'git' in sys.modules:
                try:
                    repo = git.Repo(project_dir)
                    url = next(repo.remote().urls).replace('.git', '')
                    branch = repo.active_branch.name
                    logging.info(f'Found a git repo under {project_dir}')
                    return f'{url}/tree/{branch}/'
                except (git.GitError, TypeError):
                    # not a git repo leave variable empty
                    # TypeError may be thrown in case of incorrect reference to a git commit
                    Error.warning(
                        f'Could not find a git repository under: {project_dir}.')
                    return None

        sys_vars['_get_git_repo_url'] = _get_git_repo_url

        return sys_vars

    def get_full_ctx(self, pure_comment=None):
        """
        Construct full context: system variables + pure comment + parent context
        """
        ctx = self.get_sys_vars()
        if pure_comment is None:
            current_node = self.node_stack[-1]
            if current_node.type == NodeType.CLANG_NODE and current_node.cxx_element.raw_comment:
                pure_comment, _ = APIParser.separate_pure_and_api_comment(
                    current_node.cxx_element.raw_comment)
        if pure_comment:
            ctx['_pure_comment'] = '\n'.join(pure_comment)

        parent_args = self.get_parent_args()
        if parent_args:
            ctx.update(parent_args)
        return ctx
