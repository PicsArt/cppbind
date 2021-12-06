"""
Filter module decides which clang cursor needs to be processed and which one needs to be skipped.
"""
import glob
import os

import clang.cindex as cli
from iegen.utils import get_excluded_files

class CXXParserFilter:
    """
    Simple filter implementation to skip unnecessary records for AST of clang.
    """

    DISALLOWED_CXX_KINDS = [
        cli.CursorKind.CXX_BASE_SPECIFIER
    ]

    def __init__(self, include_files=None, exclude_glob=None):
        self.include_files = include_files
        self.exclude_files = get_excluded_files(exclude_glob)

    def include_files():
        """
        File list that should be included.
        If this list is not empty all cursors that not belonging
        this files are filtered.

        :returns: list of files
        """
        def fget(self):
            return self._include_files

        def fset(self, value):
            if value is None:
                value = []

            if not isinstance(value, list):
                value = [value]
            self._include_files = value

        return locals()

    include_files = property(**include_files(), doc=include_files.__doc__)

    def filter_cursor(self, node):
        """Function test whether or not node needs to be processed.

        args:
            node: Node that need to be tested

        Returns:
            True if cursor needs to be processed

        """
        if self.filter_by_file(node) or node.kind in CXXParserFilter.DISALLOWED_CXX_KINDS:
            return True

        return False

    def filter_cursor_children(self, node):
        """Function test whether or not nodes children needs to be processed.

        args:
            node: Node that need to be tested

        Returns:
            True if cursor needs to be processed

        """
        return False

    def filter_by_file(self, node):
        if node.extent.start.file is None:
            return True
        for file in self.exclude_files:
            if file in node.extent.start.file.name:
                return True
        if self.include_files:
            return node.extent.start.file.name not in self.include_files
        return False



