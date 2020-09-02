import os
import hashlib

from iegnen.builder.out_builder import Builder, Scope
from iegnen.builder.ir_builder import CXXIEGIRBuilder
from iegnen.parser.ieg_parser import CXXParser


def test_builder(out_dir):
    builder = Builder()

    file_scope = builder.get_file("test_file", os.path.join(out_dir, "test.txt"))

    file_scope.add("class a {", Scope(name="class_body", tab=1), "}")

    builder.get_scope("class_body").add("testing text")

    class_scope = builder.get_scope("class_body")
    class_scope.add("#adding more start")
    class_scope.add(None, Scope(name="new_method"))

    builder.get_scope("new_method").add("function a", Scope("return something", tab=1))
    result = str(file_scope)
    print(f"output=\n{result}")
    assert hashlib.md5(result.encode()).hexdigest() == '7069d55149d357558aee93c65be23b71',\
        "Builder output has bean changed"


# @pytest.mark.skip(reason="Due to dict test is not stable")
def test_build_ir(parser_config, attributes, api_start_kw):
    parsser = CXXParser(parser_config=parser_config)
    # print(config)

    ir_builder = CXXIEGIRBuilder(attributes=attributes,
                                 api_start_kw=api_start_kw)
    parsser.parse(ir_builder)

    ir = ir_builder.ir

    print(ir)
    assert hashlib.md5(repr(ir).encode()).hexdigest() == '3e95a69105618109602772889b9f7eb2',\
        "ir representation string has bean changed."
