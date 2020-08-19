from iegnen.parser.ieg_parser import CXXParser
from iegnen.parser.processor import CXXPrintProcsessor


def test_parser(config):
    parsser = CXXParser(config=config)
    # print(config)
    processor = CXXPrintProcsessor()
    for c in parsser.parss_x():
        processor(c)
