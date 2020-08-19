"""
Processor module provides various processor for ieg parser
"""


class CXXPrintProcsessor(object):

    def __call__(self, node, *args, **kwargs):
        print(f'Found {node.kind} Display name {node.displayname} \
              [line={node.location.line}, \
              col={node.location.column}]',
              f'Comments {node.raw_comment} Brief Comments {node.brief_comment}')


cxx_ieg_processor = CXXPrintProcsessor()
