import os
import pytest
import hashlib

from iegnen.builder.builder import Builder, Scope


def test_builder(out_dir):
    builder = Builder()

    file_scope = builder.get_file("test_file", os.path.join(out_dir, "test.txt"))

    file_scope.add("class a {", Scope(name="class_body", tab=1), "}")

    builder.get_scope("class_body").add("testing text")

    class_scope = builder.get_scope("class_body")
    class_scope.add("#adding more start")
    class_scope.add(None, Scope(name="new_method"))

    builder.get_scope("new_method").add("function a", Scope("return something", tab=1))
    print(f"output=\n{str(file_scope)}")
