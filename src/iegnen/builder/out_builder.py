"""
Builder module allows rule script to add source code blokes
to generated output.
"""

import os
from iegnen import logging as logging

TAB_STR = '    '


class Scope(object):

    def __init__(self, *parts, name=None, tab=0, tab_str=None, builder=None, parts_spliter='\n'):
        self.builder = builder
        self.parts = []
        self.tab = tab
        self.parts_spliter = parts_spliter
        self.tab_str = tab_str or TAB_STR
        self._name = name
        self.add(*parts)

    @property
    def name(self):
        return self._name

    def add_unique(self, *parts, add_front=False):
        """
        Adds text or scope to corresponding partition
        """
        return self.add(*[part for part in parts if part not in self.parts], add_front=add_front)

    def add(self, *parts, add_front=False):
        """
        Adds text or scope to corresponding partition
        """
        if add_front:
            self.parts = list(parts) + self.parts
        else:
            self.parts = self.parts + list(parts)

        # register scopes
        self._register_scopes(*parts)

    def get_scope(self, scope_name, create=False):
        scope = self.builder.lookup_scope(scope_name)

        if scope is None and create:
            scope = Scope(name=scope_name, builder=self.builder)
            self.add(scope)

        return scope

    def _register_scopes(self, *parts):
        if len(parts) == 0:
            return
        # register scopes
        if self.builder:
            dept = self.builder._lookup_scope_dept(self)
            assert dept, f"current {repr(self)} scope is not register"
            # register as child
            if dept != -1:
                dept += 1

        for data in parts:
            if data is not None:
                if isinstance(data, Scope):
                    data.builder = self.builder
                    # also if name is not empty add to builder for lookup
                    if data.name:
                        assert self.builder, "to be able to add name scope builder should be specified."
                        self.builder.register_scope(data, dept)

    def __getitem__(self, scope_name):
        return self.get_scope(scope_name, create=True)

    def __repr__(self):
        return f"Scope({self.__dict__})"

    def __str__(self):

        lines = [
            (self.tab_str*self.tab)+s
            for s in self.parts_spliter.join(str(p) for p in self.parts).splitlines(keepends=True)
        ]

        str_scope = ''.join(lines)

        return str_scope

    def __bool__(self):
        return bool(self.parts)


class File(Scope):

    def __init__(self, file_path, **kwargs):
        super().__init__(**kwargs)
        self.file_path = file_path

    def dump_output(self):
        logging.info(f"Writing output for {self.name} into {self.file_path}")
        os.makedirs(os.path.dirname(self.file_path), exist_ok=True)
        with open(self.file_path, 'wt') as f:
            f.write(str(self))


class Builder(object):

    def __init__(self):
        self._scope_stack = [dict()]
        self._files = dict()
        self.last_file_scope = None

    def dump_outputs(self):
        for name, fl in self._files.items():
            fl.dump_output()

    def get_file(self, file_name, file_path=None, create=True):
        file_path = file_path or file_name
        file_scope = self._files.get(file_path, self.lookup_scope(file_name))
        assert file_scope is None or file_scope.name == file_name

        if file_scope is None and create:
            file_scope = File(file_path, builder=self, name=file_name)
            self._files[file_path] = file_scope
            self.register_scope(file_scope, dept=0)

        self.last_file_scope = file_scope
        return file_scope

    def register_scope(self, scope, dept=-1):
        assert self._scope_stack and scope.name
        self._scope_stack[dept].setdefault(scope.name, scope)

    def add_scope_stack(self):
        self._scope_stack.append(dict())

    def pop_scope_stack(self):
        self._scope_stack.pop()

    def clear_scope_stack(self):
        self._scope_stack[-1] = {}

    def lookup_scope(self, scope_name):
        scope, dept = self._lookup_scope_by_name(scope_name)
        return scope

    def get_scope(self, scope_name, create=False):
        scope = self.lookup_scope(scope_name)

        if scope is None and create and self.last_file_scope:
            scope = self.last_file_scope.get_scope(scope_name, create)

        return scope

    def __getitem__(self, scope_name):
        return self.get_scope(scope_name, create=True)

    def _lookup_scope_by_name(self, scope_name, dept=-1):
        if len(self._scope_stack) < -dept:
            return None, -1

        scope = self._scope_stack[dept].get(scope_name, None)
        if scope is not None:
            return scope, dept

        return self._lookup_scope_by_name(scope_name, dept-1)

    def _lookup_scope_dept(self, scope, dept=-1):
        if len(self._scope_stack) < -dept:
            return None

        found_scope, found_dept = self._lookup_scope_by_name(scope.name, dept)
        if found_scope is None:
            return None

        if found_scope is scope:
            return found_dept
        return self._lookup_scope_dept(scope, found_dept-1)
