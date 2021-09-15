from functools import cmp_to_key

from iegen.converter.swift import imports_comparator


def test_swift_import_order():
    unordered = [
        '@testable import MyModuleUnderTest',
        'import DEF',
        'import ABC',
        'import func Darwin.C.isatty',
        'import class Darwin.D',
        'import class Darwin.C',
        '@testable import MyAnotherModuleUnderTest'
    ]
    expected = [
        'import ABC',
        'import DEF',
        'import class Darwin.C',
        'import class Darwin.D',
        'import func Darwin.C.isatty',
        '@testable import MyAnotherModuleUnderTest',
        '@testable import MyModuleUnderTest',
    ]

    result = sorted(unordered, key=cmp_to_key(imports_comparator))
    assert result == expected
