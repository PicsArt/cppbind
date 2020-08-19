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

    def __init__(self, filter=None, processor=None, config=None):
        self.config = config or default_config
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
        args = ['-x', 'c++']
        glob_filter = self.config.parser.src_glob or "*"
        files = os.path.join(self.config.parser.source_dir, glob_filter)

        logging.info(f"parsing files: {files}")
        for file_name in glob.glob(files):
            logging.info(f"parsing file {file_name}")
            self.current_file = file_name
            tu = index.parse(path=file_name, args=args, options=CXXParser.CLANG_DEF_OPTIONS)
            yield tu

    def parss_x(self):
        """
        Pares cxx files and returns generator of cursors
        """
        for tu in self.parss_tu_x():
            for c in self.walk(tu.cursor):
                yield c

    def walk(self, node):
        """
        walk ast recursively by filtering using filter
        """
        if self.filter.filter_cursor(node):
            logging.debug(f"Filtering node: {node}")
            return

        # process current node
        yield node

        # now if needed dive into children
        if not self.filter.filter_cursor_children(node):
            for child in node.get_children():
                for descendant in self.walk(child):
                    yield descendant
