import hashlib
import os

import pytest

from iegen.utils import current_datetime
from iegen.builder import OUTPUT_MODIFICATION_KEY, is_output_changed
from iegen.builder.ir_builder import CXXIEGIRBuilder
from iegen.builder.out_builder import Builder, Scope
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
    assert hashlib.md5(result.encode()).hexdigest() == '48fba040b7f3c229b23a31b329d33b4f', \
        "Builder output has bean changed"


# @pytest.mark.skip(reason="Due to dict test is not stable")
@pytest.mark.skip(reason="Due to test contains file absolute pats that are differ from machine to machine")
def test_build_ir(parser_config, attributes, api_start_kw):
    parsser = CXXParser(parser_config=parser_config)
    # print(config)

    ir_builder = CXXIEGIRBuilder(attributes=attributes,
                                 api_start_kw=api_start_kw)
    parsser.parse(ir_builder)

    ir = ir_builder.ir

    print(ir)
    assert hashlib.md5(repr(ir).encode()).hexdigest() == '19bbafbac23454676a1fbfaee8effdf4', \
        "ir representation string has bean changed."


def test_is_output_changed():
    old = """
    some string %s next1 
    %s next2
    next3
    """

    new = f"""
    some string {OUTPUT_MODIFICATION_KEY} next1 
    {OUTPUT_MODIFICATION_KEY} next2
    next3
    """

    date = current_datetime()
    old1 = old % (date, date)
    assert is_output_changed(old1, new) is False
    old2 = old % ('date', 'date')
    assert is_output_changed(old2, new) is True

    old3 = old1 + "next4"

    assert is_output_changed(old3, new) is True
