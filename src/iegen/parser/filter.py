"""
Filter module decides which clang cursor needs to be processed and which one needs to be skipped.
"""

import iegen.utils.clang as cutil
from iegen.parser.ieg_parser import CXXParser


class CXXComposerFilter:
    """Class to compose CXXFilers to be able to combine them"""

    def __init__(self, *filters):
        self.__filters = filters

    def filter_cursor(self, cursor):
        """Composer method to call all `filter_cursor` methods of registered filters"""
        return any(filter_.filter_cursor(cursor) for filter_ in self.__filters)

    def filter_by_file(self, file):
        """Composer method to call all `filter_by_file` methods of registered filters"""
        return any(filter_.filter_by_file(file) for filter_ in self.__filters)

    def filter_cursor_children(self, cursor):
        """Composer method to call all `filter_cursor_children` methods of registered filters"""
        return any(filter_.filter_cursor_children(cursor) for filter_ in self.__filters)


class CXXFilter:
    """Base class for CXX filter classes"""

    def filter_cursor(self, cursor):
        """Default implementation of `filter_cursor`"""
        return False

    def filter_by_file(self, file):
        """Default implementation of `filter_by_file`"""
        return False

    def filter_cursor_children(self, cursor):
        """Default implementation of `filter_cursor_children`"""
        return False


class CXXParserFilter(CXXFilter):
    """
    Simple filter implementation to skip unnecessary records for AST of clang.
    """

    def __init__(self, include_files=None, exclude_files=None):
        self.include_files = include_files
        self.exclude_files = exclude_files

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

    @staticmethod
    def __has_disallowed_cxx_kind(cursor):
        """Private static method to check whether cursor kind is disallowed for parsing"""
        return cursor.kind.is_reference()

    def filter_cursor(self, cursor):
        """Function test whether or not cursor needs to be processed.

        args:
            cursor: cursor that need to be tested

        Returns:
            True if cursor needs to be processed

        """
        if cutil.is_declaration(cursor) or cutil.is_implementation(cursor) \
                or CXXParserFilter.__has_disallowed_cxx_kind(cursor):
            return True

        file = cursor.extent.start.file
        # file is None especially in case of unexposed cursor types
        if file is None or self.filter_by_file(file.name):
            return True

        return False

    def filter_by_file(self, file):
        if self.exclude_files is not None:
            if file in self.exclude_files:
                return True
        if self.include_files:
            return file not in self.include_files
        return False


class CXXIegFilter(CXXFilter):
    """Clang cursor filter which has some dependencies on some IEGEN internal structures (e.g. IR)"""

    def __init__(self, ir):
        self.__ir = ir

    def filter_cursor_children(self, cursor):
        """
        Function test whether or not cursor children needs to be processed.

        args:
            cursor: cursor that need to be tested
        Returns:
            True if cursor needs to be processed
        """

        # condition to not process cursor children if current cursor-based node is already in node_map
        return self.__ir.find_node(cutil.get_signature(cursor)) is not None
