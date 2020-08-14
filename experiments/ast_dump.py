"""
"""

import argparse
import clang.cindex as cli

from ctypes.util import find_library

clang_lib = find_library('clang-9')

if clang_lib is None:
    print("clang dev is not installed. Please read README.md")
    exit(1)

cli.Config.set_library_file(clang_lib)
# cli.Config.set_library_path("/usr/lib/llvm-9/lib/")
# cli.Config.set_library_file("libclang-9.so")


def print_ast(node):
    """
    Prints ast
    """
    print(f'Found {node.kind} Display name {node.displayname} [line={node.location.line}, col={node.location.column}]')
    # Recurse for children of this node
    for c in node.get_children():
        print_ast(c)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Prints AST.")
    parser.add_argument('cppfile', type=str,
                        help='c++ file')
    args = parser.parse_args()
    index = cli.Index.create()
    tu = index.parse(args.cppfile)
    print('Translation unit:', tu.spelling)
    print_ast(tu.cursor)
