"""
Builder module allows rule script to add source code blokes
to generated output.
"""

import os
import copy
from iegnen import logging as logging

TAB_STR = '    '


class Scope(object):

    def __init__(self, *parts, name=None, tab=0, tab_str=None, file_scope=None, parts_spliter='\n'):
        self.file_scope = file_scope
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
        scope = self.file_scope.lookup_scope(scope_name)

        if scope is None and create:
            logging.debug(f"Creating Scope {scope_name}, current depth is {len(self.file_scope._scope_stack)}.")
            scope = Scope(name=scope_name, file_scope=self.file_scope)
            self.add(scope)

        return scope

    def _register_scopes(self, *parts):
        if len(parts) == 0:
            return
        # register scopes
        if self.file_scope:
            dept = self.file_scope._lookup_scope_dept(self)
            assert dept is not None, f"current {repr(self)} scope is not register"
            # register as child
            if dept != -1:
                dept += 1
            # else:
                # assert False, "Reached max preallocated stack"

        for data in parts:
            if data is not None:
                if isinstance(data, Scope):
                    data.file_scope = self.file_scope
                    # also if name is not empty add to file_scope for lookup
                    if data.name:
                        assert self.file_scope, "to be able to add name scope file_scope should be specified."
                        self.file_scope.register_scope(data, dept)

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
        self.file_path = file_path
        self._scope_stack = [dict()]
        super().__init__(file_scope=self, **kwargs)
        self.register_scope(self)

    def dump_output(self):
        logging.info(f"Writing output for {self.name} into {self.file_path}")
        os.makedirs(os.path.dirname(self.file_path), exist_ok=True)
        with open(self.file_path, 'wt') as f:
            f.write(str(self))

    def register_scope(self, scope, dept=-1):
        assert self.scope_stack and scope.name
        self.scope_stack[dept].setdefault(scope.name, scope)

    def add_scope_stack(self):
        self._scope_stack.append(dict())

    def pop_scope_stack(self):
        self._scope_stack.pop()

    def clear_scope_stack(self):
        self.scope_stack[-1] = {}

    def lookup_scope(self, scope_name):
        scope, dept = self._lookup_scope_by_name(scope_name)
        return scope

    @property
    def scope_stack(self):
        return self._scope_stack

    def __getitem__(self, scope_name):
        return self.get_scope(scope_name, create=True)

    def _lookup_scope_by_name(self, scope_name, dept=-1):
        if len(self.scope_stack) < -dept:
            return None, -1

        scope = self.scope_stack[dept].get(scope_name, None)
        if scope is not None:
            return scope, dept

        return self._lookup_scope_by_name(scope_name, dept-1)

    def _lookup_scope_dept(self, scope, dept=-1):
        if len(self.scope_stack) < -dept:
            return None

        found_scope, found_dept = self._lookup_scope_by_name(scope.name, dept)
        if found_scope is None:
            return None

        if found_scope is scope:
            return found_dept
        return self._lookup_scope_dept(scope, found_dept-1)


class Builder(object):

    def __init__(self):
        self._current_dept = 0
        self._files = dict()

    def dump_outputs(self):
        for name, fl in self._files.items():
            fl.dump_output()

    def get_file(self, file_name, file_path=None, create=True):
        file_path = file_path or file_name
        file_scope = self._files.get(file_path, None)
        assert file_scope is None or file_scope.name == file_name

        if file_scope is None and create:
            logging.debug(f"Creating File Scope {file_path}, current depth is {self._current_dept}.")
            file_scope = File(file_path, name=file_name)
            for i in range(self._current_dept):
                file_scope.add_scope_stack()
            self._files[file_path] = file_scope

        return file_scope

    def add_scope_stack(self):
        self._current_dept += 1
        for fl in self._files.values():
            fl.add_scope_stack()

    def pop_scope_stack(self):
        self._current_dept -= 1
        for fl in self._files.values():
            fl.pop_scope_stack()

    def clear_scope_stack(self):
        for fl in self._files.values():
            fl.clear_scope_stack()

    def capture_stacks(self):
        return {file_name: copy.copy(fl.scope_stack) for file_name, fl in self._files.items()}

    def restore_stacks(self, capture_data):
        for file_name, fl in self._files.items():
            if file_name in capture_data:
                fl._scope_stack = copy.copy(capture_data[file_name])
