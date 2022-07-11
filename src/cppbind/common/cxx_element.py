"""Module to define cxx related element class and its dependencies."""


class CXXElement:
    """Wrapper type on clang cursor to provide unified access to cxx functionality/properties"""

    def __init__(self, clang_cursor):
        self.__clang_cursor = clang_cursor
        # maybe later we'll need access to IR root

    def __getattr__(self, item):
        """Delegate all calls to clang Cursor object"""

        if not hasattr(self.__clang_cursor, item):
            raise AttributeError(f"{self.__class__.__name__}.{item} is invalid")

        return getattr(self.__clang_cursor, item)

    # TODO: move cxx-related properties/methods from CXXType and context make-functions to here
