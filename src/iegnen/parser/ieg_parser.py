"""
Parser module based on clang
"""
import os
import glob
import clang.cindex as cli
from iegnen import (
    default_config as default_config,
    logging as logging
)
from iegnen.parser.filter import cxx_ieg_filter


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
        args = ['-x', 'c++', '--std=c++17'] +\
            self.config.clang_args.split(',') + ['-I' + includeDir.strip()
                                                 for includeDir in self.config.include_dirs.split(',')]
        glob_filter = self.config.src_glob or "*"
        files = os.path.join(self.config.source_dir, glob_filter)

        logging.info(f"parsing files: {files}")

        all_files = glob.glob(files, recursive=True)
        all_files = [os.path.abspath(fp) for fp in all_files]
        logging.debug(f"parsing found files: {all_files}")
        logging.debug(f"Clang args: {args}")

        for file_name in glob.glob(files, recursive=True):
            logging.info(f"parsing file {file_name}")
            self.current_file = file_name
            tu = index.parse(path=file_name, args=args, options=CXXParser.CLANG_DEF_OPTIONS)

            hass_error = False
            for diagnostic in tu.diagnostics:
                logging.critical(f"Error while parsing {file_name}: {diagnostic.spelling}")
                logging.debug(diagnostic)
            if not hass_error:
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

            if hasattr(processor, 'start_tu'):
                processor.start_tu(tu)

            self._process_cursor(tu.cursor, processor)

            if hasattr(processor, 'end_tu'):
                processor.end_tu(tu)

    def _process_cursor(self, cursor, processor):

        if self.filter.filter_cursor(cursor):
            logging.debug(f"Filtering cursor: {cursor}")
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
