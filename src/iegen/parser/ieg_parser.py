"""
Parser module based on clang
"""

import glob
import os
import re

import clang.cindex as cli
import iegen.utils.clang as cutil
from iegen import (
    default_config as default_config,
    logging as logging
)
from iegen.parser.filter import cxx_ieg_filter


class CXXParser(object):
    """
    """
    CLANG_DEF_OPTIONS = cli.TranslationUnit.PARSE_SKIP_FUNCTION_BODIES | \
                        cli.TranslationUnit.PARSE_INCOMPLETE

    def __init__(self, filter=None, processor=None, parser_config=None):
        self.config = parser_config or default_config.parser
        self.current_file = None
        self.filter = filter or cxx_ieg_filter

    def parss_tu(self):
        """
        Pares cxx files and returns list of TranslationUnit s
        """
        return [tu for tu in self.parss_x()]

    def parss_tu_x(self):
        """
        Pares cxx files and returns generator of TranslationUnit s
        """
        index = cli.Index.create()

        # build parser arguments
        args = ['-x', 'c++', '--std=c++17'] + self.config.clang_args.split(',') + ['-I' + includeDir.strip()
                                                                                   for includeDir in
                                                                                   self.config.include_dirs.split(',')]
        files = self.config.src_glob
        excluded_files = self.config.src_exclude_glob
        # base_files = os.path.join(find_prj_dir(self.config.cxx_base_dir), '**/*.h*')
        # base_files = glob.glob(base_files, recursive=True)

        logging.info("parsing files: {}".format(files.replace("\n", " ")))
        # logging.info(f"parsing files: {base_files}")

        all_excluded_files = set()
        for file in excluded_files.split(','):
            abs_paths = (os.path.abspath(fp) for fp in glob.glob(file.strip(), recursive=True))
            all_excluded_files.update(abs_paths)

        # using list to keep files order constant
        all_files = []
        for file in files.split(','):
            files_glob = sorted(glob.glob(file.strip(), recursive=True))
            for fp in files_glob:
                abs_fp = os.path.abspath(fp)
                if abs_fp not in all_excluded_files:
                    all_files.append(abs_fp)

        logging.debug(f"parsing found files: {all_files}")
        logging.debug(f"Clang args: {args}")

        for file_name in all_files:
            logging.info(f"parsing file {file_name}")
            self.current_file = file_name
            tu = index.parse(path=file_name, args=args, options=CXXParser.CLANG_DEF_OPTIONS)

            has_error = False
            for diagnostic in tu.diagnostics:
                if diagnostic.severity in (cli.Diagnostic.Error, cli.Diagnostic.Fatal):
                    logging.critical(f"Error while parsing {file_name}: {diagnostic.spelling}")
                    has_error = True
                else:
                    logging.warning(f"Warning while parsing {file_name}: {diagnostic.spelling}")
            if not has_error:
                yield tu

    def parss_x(self):
        """
        Pares cxx files and returns generator of cursors
        """
        for tu in self.parss_tu_x():
            for c in self.cursor_walk(tu.cursor):
                yield c

    def cursor_walk(self, cursor):
        """
        cursor_walk ast recursively by filtering using filter
        """
        if self.filter.filter_cursor(cursor):
            logging.debug(f"Filtering cursor: {cursor}")
            return

        # processor current cursor
        yield cursor

        # now if needed dive into children
        if not self.filter.filter_cursor_children(cursor):
            for child in cursor.get_children():
                for descendant in self.cursor_walk(child):
                    yield descendant

    def parse(self, processor):

        for tu in self.parss_tu_x():
            tu_parent_dirs = self.__dirs_to_process(tu)

            # TODO:
            # currently we are not parsing the entire directory tree at once instead for each file we
            # are going from root to leaf, if there are already processed dirs then we are retrieving them from the dict
            # later we may construct the whole source directory tree and then build the ir tree
            for dir_name in tu_parent_dirs:
                if hasattr(processor, 'start_dir'):
                    processor.start_dir(dir_name)

            if hasattr(processor, 'start_tu'):
                processor.start_tu(tu)

            self._process_cursor(tu.cursor, processor)

            if hasattr(processor, 'end_tu'):
                processor.end_tu(tu)

            for dir_name in reversed(tu_parent_dirs):
                if hasattr(processor, 'end_dir'):
                    processor.end_dir(dir_name)

    def __dirs_to_process(self, tu):
        dirs_to_search = set()

        root = os.path.dirname(tu.spelling)
        dirs_to_search.add(os.path.relpath(root, os.getcwd()))
        while root:
            root = os.path.dirname(root)
            dir_name = os.path.relpath(root, os.getcwd())

            match = re.match(r'^[./]+$', dir_name)
            if match:
                break
            dirs_to_search.add(dir_name)
        # sort to get root to child list
        return sorted(dirs_to_search)

    def _process_cursor(self, cursor, processor):

        if self.filter.filter_cursor(cursor):
            logging.debug(f"Filtering cursor: {cursor}")
            return

        if cutil.is_declaration(cursor):
            logging.debug(f"Filtering forward declaration cursor: {cursor}")
            return

        if self.is_implementation(cursor):
            logging.debug(f"Filtering implementation cursor: {cursor}")
            return

        # process current cursor
        if hasattr(processor, 'start_cursor'):
            processor.start_cursor(cursor)

        if callable(processor):
            processor(cursor)

        # now if needed dive into children
        if not self.filter.filter_cursor_children(cursor):
            for child in cursor.get_children():
                self._process_cursor(child, processor)

        if hasattr(processor, 'end_cursor'):
            processor.end_cursor(cursor)

    def is_implementation(self, cursor):
        if cursor.lexical_parent and cursor.semantic_parent:
            return cursor.lexical_parent != cursor.semantic_parent
        return False
