# Copyright (c) 2022 PicsArt, Inc.
# All rights reserved. Use of this source code is governed by a
# MIT-style license that can be found in the LICENSE file.

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


def print_ast(node, extent=None, print_tokens=False):
    """
    Prints ast
    """
    if extent and extent.start.file.name != node.extent.start.file.name:
        # print("skipping file: ", node.extent)
        return
    print(f'Found {node.kind} Display name {node.displayname} [line={node.location.line}, col={node.location.column}]')
    print(f'Comments {node.raw_comment} {node.brief_comment}')
    if print_tokens:
        for tk in node.get_tokens():
            print(f'token {tk.spelling} kind {tk.kind} owner {tk.cursor.kind}, {tk.cursor.displayname}')
    # print(f'Cursor Extend {node.extent}')
    # Recurse for children of this node
    for c in node.get_children():
        print_ast(c, extent, print_tokens)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Prints AST.")
    parser.add_argument('cppfile', type=str,
                        help='c++ file')
    parser.add_argument('-t', dest='print_tokens', action='store_true', default=False,
                        help='dump tokens')
    parser.add_argument('-i', dest='dive_into_includes', action='store_true', default=False,
                        help='dumps included files as well.')
    args = parser.parse_args()
    index = cli.Index.create()
    options = cli.TranslationUnit.PARSE_SKIP_FUNCTION_BODIES|\
        cli.TranslationUnit.PARSE_INCOMPLETE
    clang_args = ['-x', 'c++']
    # options = 0
    tu = index.parse(path=args.cppfile, args=clang_args, options=options)
    print('Translation unit:', tu.spelling)
    print('Include files:')
    for f in tu.get_includes():
        print(f"Include file {f.include}")
    print_ast(tu.cursor, tu.cursor.extent if not args.dive_into_includes else None,
              args.print_tokens)
