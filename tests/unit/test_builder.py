import os
import hashlib

from iegen.builder.out_builder import Builder, Scope
from iegen.builder.ir_builder import CXXIEGIRBuilder
from iegen.parser.ieg_parser import CXXParser


def test_builder(out_dir):
    builder = Builder()

    builder.add_scope_stack()

    file_scope = builder.get_file("test_file", os.path.join(out_dir, "test.txt"))

    file_scope.add("class a {", Scope(name="class_body", tab=1), "}")

    file_scope.get_scope("class_body").add("testing text")

    class_scope = file_scope.get_scope("class_body")
    class_scope.add("#adding more start")
    class_scope.add(None, Scope(name="new_method"))

    file_scope.get_scope("new_method").add("function a", Scope("return something", tab=1))
    result = str(file_scope)
    print(f"output=\n{result}")
    assert hashlib.md5(result.encode()).hexdigest() == '48fba040b7f3c229b23a31b329d33b4f',\
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
    assert hashlib.md5(repr(ir).encode()).hexdigest() == 'fa67cbca9bad59401e4e4930c4caeb34',\
        "ir representation string has bean changed."
