# Copyright (c) 2022 PicsArt, Inc.
# All rights reserved. Use of this source code is governed by a
# MIT-style license that can be found in the LICENSE file.

"""
Parser module based on clang
"""
import glob
import os
import re

import clang.cindex as cli
import cppbind.utils.clang as cutil
from cppbind import logging
from cppbind.common.error import Error


class CXXParser:
    """
    Class is responsible for source cxx files parsing and cursor returning
    """
    CLANG_DEF_OPTIONS = cli.TranslationUnit.PARSE_SKIP_FUNCTION_BODIES | \
                        cli.TranslationUnit.PARSE_INCOMPLETE
    EXTRA_INCLUDES_FILE_NAME = "extra_includes.cpp"

    def __init__(self, processor, single_tu, filter_=None):
        self.current_file = None
        self.filter = filter_
        self.processor = processor
        self.single_tu = single_tu
        # list to keep track of which files are already processed to not process them again
        self.processed_files = []
        # current files stack which are being processed
        self.files_stack = []

    def parse_tu(self):
        """
        Parses cxx files and returns list of TranslationUnit s
        """
        return list(self.parse_x())

    def parse_tu_x(self, clang_args, include_dirs, src_glob, extra_headers, **kwargs):
        """
        Parses cxx files and returns generator of TranslationUnit s
        """
        index = cli.Index.create()
        # build parser arguments
        args = ['-x', 'c++', '--std=c++20'] + clang_args + ['-I' + includeDir.strip()
                                                            for includeDir in
                                                            include_dirs]

        logging.debug(f"Clang path: {cutil.get_libclang_full_path()}")
        logging.debug(f"Clang args: {args}")

        logging.info("parsing files: {}".format(' '.join(src_glob)))

        # using list to keep files order constant
        all_files = []
        for file in src_glob:
            files_glob = sorted(glob.glob(file.strip(), recursive=True))
            for file_path in files_glob:
                abs_fp = os.path.abspath(file_path)
                if not (self.filter and self.filter.filter_by_file(abs_fp)):
                    all_files.append(abs_fp)

        extra_includes = None
        unsaved_files = None
        if extra_headers:
            extra_includes = "\n".join(f"#include <{header}>" for header in extra_headers)
            unsaved_files = [(CXXParser.EXTRA_INCLUDES_FILE_NAME, extra_includes)]

        if self.single_tu and all_files:
            # include all src files in a virtual file to parse everything once
            includes = "\n".join(f'#include "{file}"' for file in all_files)
            if extra_includes:
                includes = extra_includes + f"\n{includes}"
            unsaved_files = [(CXXParser.EXTRA_INCLUDES_FILE_NAME, includes)]
            all_files = [CXXParser.EXTRA_INCLUDES_FILE_NAME]
        else:
            if extra_includes:
                all_files = [CXXParser.EXTRA_INCLUDES_FILE_NAME] + all_files

        for file in all_files:
            try:
                tu = index.parse(path=file,
                                 args=args,
                                 unsaved_files=unsaved_files,
                                 options=CXXParser.CLANG_DEF_OPTIONS)
            except cli.TranslationUnitLoadError as err:
                Error.critical(f"Cannot continue: cppbind error has occurred: {err}.")
            has_error = False
            for diagnostic in tu.diagnostics:
                diagnostic_error_msg = diagnostic.spelling
                if diagnostic.severity in (cli.Diagnostic.Error, cli.Diagnostic.Fatal):
                    Error.error(diagnostic_error_msg,
                                   diagnostic.location.file,
                                   diagnostic.location.line)
                    has_error = True
                else:
                    Error.warning(diagnostic_error_msg,
                                  diagnostic.location.file,
                                  diagnostic.location.line)
            if not has_error and tu.spelling not in self.processed_files:
                    # allow different files(includes) in translation unit level
                    self._process_cursor_children(tu.cursor, allow_includes=True)
                    if self.files_stack:
                        for _ in range(len(self.files_stack)):
                            self._end_process_file(self.files_stack[-1])

    def cursor_walk(self, cursor):
        """
        cursor_walk ast recursively by filtering using filter
        """
        if self.filter and self.filter.filter_cursor(cursor):
            logging.debug(f"Filtering cursor: {cursor.spelling}")
            return

        # processor current cursor
        yield cursor

        # now if needed dive into children
        if not (self.filter and self.filter.filter_cursor_children(cursor)):
            for child in cursor.get_children():
                for descendant in self.cursor_walk(child):
                    yield descendant

    def _start_process_file(self, file_name):
        logging.info(f'parsing {file_name}')
        self.files_stack.append(file_name)
        tu_parent_dirs = CXXParser.__dirs_to_process(file_name)
        # TODO:
        # currently we are not parsing the entire directory tree at once,
        # instead for each file we are going from root to leaf,
        # if there are already processed dirs then we are retrieving them from the dict,
        # later we may construct the whole source directory tree and then build the ir tree
        for dir_name in tu_parent_dirs:
            if hasattr(self.processor, 'start_dir'):
                self.processor.start_dir(dir_name)

        if hasattr(self.processor, 'start_file'):
            self.processor.start_file(file_name)

    def _end_process_file(self, file_name):
        tu_parent_dirs = CXXParser.__dirs_to_process(file_name)

        if hasattr(self.processor, 'end_file'):
            self.processor.end_file(file_name)

        if tu_parent_dirs:
            for dir_name in reversed(tu_parent_dirs):
                if hasattr(self.processor, 'end_dir'):
                    self.processor.end_dir(dir_name)

        if not self.single_tu:
            self.processed_files.append(file_name)
        self.files_stack.pop()

    def parse(self, **kwargs):
        """
        Method parses all translation units
        """
        self.parse_tu_x(**kwargs)

    @staticmethod
    def __dirs_to_process(file_name):
        if not os.path.isfile(file_name):
            return []

        dirs_to_search = set()

        root = os.path.abspath(file_name)
        while root:
            root = os.path.dirname(root)
            dir_name = os.path.relpath(root, os.getcwd())

            match = re.match(r'^[./]+$', dir_name) and dir_name != '.'
            if match:
                break
            dirs_to_search.add(dir_name)
        # sort to get root to child list
        return sorted(dirs_to_search)

    def _process_cursor(self, cursor, allow_includes=False):
        if self.filter and self.filter.filter_cursor(cursor):
            return

        # process current cursor
        if hasattr(self.processor, 'start_cursor'):
            self.processor.start_cursor(cursor)

        if callable(self.processor):
            self.processor(cursor)

        self._process_cursor_children(cursor, allow_includes)

        if hasattr(self.processor, 'end_cursor'):
            self.processor.end_cursor(cursor)

    def _process_cursor_children(self, cursor, allow_includes=False):
        current_allow_includes = cursor.kind not in (
            cli.CursorKind.NAMESPACE,
            cli.CursorKind.STRUCT_DECL,
            cli.CursorKind.CLASS_DECL,
            cli.CursorKind.CLASS_TEMPLATE,
            cli.CursorKind.CLASS_TEMPLATE_PARTIAL_SPECIALIZATION,
            cli.CursorKind.ENUM_DECL,
            cli.CursorKind.FUNCTION_DECL,
            cli.CursorKind.FUNCTION_TEMPLATE)
        for child in cursor.get_children():
            process_child = child.kind in (
                cli.CursorKind.NAMESPACE,
                cli.CursorKind.STRUCT_DECL,
                cli.CursorKind.CLASS_DECL,
                cli.CursorKind.CLASS_TEMPLATE,
                cli.CursorKind.CLASS_TEMPLATE_PARTIAL_SPECIALIZATION,
                cli.CursorKind.CONSTRUCTOR,
                cli.CursorKind.CXX_METHOD,
                cli.CursorKind.FIELD_DECL,
                cli.CursorKind.ENUM_DECL,
                cli.CursorKind.FUNCTION_DECL,
                cli.CursorKind.FUNCTION_TEMPLATE)
            if process_child:
                if child.extent.start.file:
                    file = os.path.abspath(child.extent.start.file.name)
                    # file is changed, either we ignore it if it's not allowed(e.g. include in namespace)
                    # or start/continue processing the new/not_finished file
                    current_file = self.files_stack[-1] if self.files_stack else None
                    if file != current_file:
                        # consider parent allow includes and current allow includes
                        if allow_includes and current_allow_includes:
                            # file is already started to be processed but due to includes is not finalized yet, e.g.
                            # void func1()
                            # #include "other.h"
                            # void func2()
                            if file in self.files_stack:
                                child_file = self.files_stack[-1]
                                # end included files to come to current file to be able to continue its processing
                                while file != child_file:
                                    self._end_process_file(child_file)
                                    child_file = self.files_stack[-1]
                                self._process_cursor(child, allow_includes and current_allow_includes)
                            else:
                                # file is not processed, start its processing
                                # if merge src is true we can not have duplicate files
                                if self.single_tu or file not in self.processed_files:
                                    self._start_process_file(file)
                                    self._process_cursor(child, allow_includes and current_allow_includes)
                    else:
                        # file is not changed, continue processing
                        self._process_cursor(child, allow_includes and current_allow_includes)
            else:
                self._process_cursor_children(child, allow_includes and current_allow_includes)
