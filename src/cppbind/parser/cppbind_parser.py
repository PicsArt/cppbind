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
from cppbind import logging
from cppbind.common.error import Error
import cppbind.utils.clang as cutil


class CXXParser:
    """
    Class is responsible for source cxx files parsing and cursor returning
    """
    CLANG_DEF_OPTIONS = cli.TranslationUnit.PARSE_SKIP_FUNCTION_BODIES | \
                        cli.TranslationUnit.PARSE_INCOMPLETE
    EXTRA_INCLUDES_FILE_NAME = "extra_includes.cpp"

    def __init__(self, filter_=None):
        self.current_file = None
        self.filter = filter_

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
        args = ['-x', 'c++', '--std=c++17'] + clang_args + ['-I' + includeDir.strip()
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

        # logging.debug(f"parsing found files: {all_files}")

        # push extra_headers virtual file name also in list to have corresponding tu for that headers
        unsaved_files = None
        if extra_headers:
            all_files.insert(0, CXXParser.EXTRA_INCLUDES_FILE_NAME)
            extra_includes = "\n".join(f"#include <{header}>" for header in extra_headers)
            unsaved_files = [(CXXParser.EXTRA_INCLUDES_FILE_NAME, extra_includes)]

        for file_name in all_files:
            if file_name != CXXParser.EXTRA_INCLUDES_FILE_NAME:
                logging.info(f"parsing file {file_name}")
            self.current_file = file_name
            try:
                tu = index.parse(path=file_name,
                                 args=args,
                                 unsaved_files=unsaved_files,
                                 options=CXXParser.CLANG_DEF_OPTIONS)
            except cli.TranslationUnitLoadError as err:
                Error.critical(f"Cannot continue: cppbind error has occurred: {err}", file_name)

            has_error = False
            for diagnostic in tu.diagnostics:
                extra_include_error_msg = "Error in extra includes definition: "
                diagnostic_error_msg = (extra_include_error_msg if
                                        file_name == CXXParser.EXTRA_INCLUDES_FILE_NAME else '') + diagnostic.spelling
                if diagnostic.severity in (cli.Diagnostic.Error, cli.Diagnostic.Fatal):
                    Error.error(diagnostic_error_msg,
                                diagnostic.location.file,
                                diagnostic.location.line)
                    has_error = True
                else:
                    Error.warning(diagnostic_error_msg,
                                  diagnostic.location.file,
                                  diagnostic.location.line)
            if not has_error:
                yield tu

    def parse_x(self, **kwargs):
        """
        Parses cxx files and returns generator of cursors
        """
        for tu in self.parse_tu_x(**kwargs):
            for cursor in self.cursor_walk(tu.cursor):
                yield cursor

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

    def parse(self, processor, **kwargs):
        """
        Method parses all translation units
        """
        for tu in self.parse_tu_x(**kwargs):
            tu_parent_dirs = CXXParser.__dirs_to_process(tu)

            # TODO:
            # currently we are not parsing the entire directory tree at once,
            # instead for each file we are going from root to leaf,
            # if there are already processed dirs then we are retrieving them from the dict,
            # later we may construct the whole source directory tree and then build the ir tree
            for dir_name in tu_parent_dirs:
                if hasattr(processor, 'start_dir'):
                    processor.start_dir(dir_name)

            if hasattr(processor, 'start_tu'):
                processor.start_tu(tu)

            self._process_cursor_children(tu.cursor, processor)

            if hasattr(processor, 'end_tu'):
                processor.end_tu(tu)

            for dir_name in reversed(tu_parent_dirs):
                if hasattr(processor, 'end_dir'):
                    processor.end_dir(dir_name)

    @staticmethod
    def __dirs_to_process(tu):
        if not os.path.isfile(tu.spelling):
            return []

        dirs_to_search = set()

        root = tu.spelling
        while root:
            root = os.path.dirname(root)
            dir_name = os.path.relpath(root, os.getcwd())

            match = re.match(r'^[./]+$', dir_name) and dir_name != '.'
            if match:
                break
            dirs_to_search.add(dir_name)
        # sort to get root to child list
        return sorted(dirs_to_search)

    def _process_cursor(self, cursor, processor):
        if self.filter and self.filter.filter_cursor(cursor):
            return

        # process current cursor
        if hasattr(processor, 'start_cursor'):
            processor.start_cursor(cursor)

        if callable(processor):
            processor(cursor)

        # now if needed dive into children
        self._process_cursor_children(cursor, processor)

        if hasattr(processor, 'end_cursor'):
            processor.end_cursor(cursor)

    def _process_cursor_children(self, cursor, processor):
        if not (self.filter and self.filter.filter_cursor_children(cursor)):
            for child in cursor.get_children():
                self._process_cursor(child, processor)
