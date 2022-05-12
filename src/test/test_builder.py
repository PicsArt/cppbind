import hashlib
import os

from cppbind import current_datetime
from cppbind.builder import OUTPUT_MODIFICATION_KEY, is_output_changed
from cppbind.builder.out_builder import Builder, Scope


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
    assert hashlib.md5(result.encode()).hexdigest() == '0179f22c51279fdc282a779455aa8a1f', \
        "Builder output has bean changed"


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
