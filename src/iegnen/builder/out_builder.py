"""
Builder module allows rule script to add source code blokes
to generated output.
"""


TAB_STR = '\t'


class Scope(object):

    def __init__(self, *parts, name=None, tab=0, tab_str=None, builder=None):
        self.builder = builder
        self.parts = [[]]
        self.tab = tab
        self.tab_str = tab_str or TAB_STR
        self._name = name
        self.add(*parts)

    @property
    def name(self):
        return self._name

    def add(self, *parts):
        """
        Adds text or scope to corresponding partition
        """
        len_diff = len(parts) - len(self.parts)
        self.parts += [[] for i in range(len_diff)]
        for container, data in zip(self.parts, parts):
            if data is not None:
                container.append(data)
                if isinstance(data, Scope):
                    assert self.builder, "to be able to add scope builder should be specified."
                    data.builder = self.builder
                    # also if name is not empty add to builder for lookup
                    if data.name:
                        self.builder.register_scope(data)

    def get_scope(self, scope_name, create=False):
        scope = self.builder.lookup_scope(scope_name)

        if scope is None and create:
            scope = Scope(name=scope_name, builder=self.builder)
            self.add(scope)

        return scope

    def __repr__(self):
        return f"Scope({self.__dict__})"

    def __str__(self):

        lines = [
            (self.tab_str*self.tab)+s+'\n'
            for part in self.parts
            for line in part
            for s in str(line).splitlines()
        ]
        str_scope = ''.join(lines)

        return str_scope


class File(Scope):

    def __init__(self, file_path, **kwargs):
        super().__init__(**kwargs)
        self.file_path = file_path

    def dump_output(self):
        # todo temporary
        print(str(self))


class Builder(object):

    def __init__(self):
        self._scope_stack = [dict()]
        self._files = dict()
        self.last_file_scope = None

    def dump_outputs(self):
        for name, fl in self._files.items():
            fl.dump_output()

    def get_file(self, file_name, file_path, create=True):
        file_scope = self._files.get(file_path, self.lookup_scope(file_name))
        assert file_scope is None or file_scope.name == file_name

        if file_scope is None and create:
            file_scope = File(file_path, builder=self, name=file_name)
            self._files[file_path] = file_scope
            self.register_scope(file_scope)

        self.last_file_scope = file_scope
        return file_scope

    def register_scope(self, scope):
        assert self._scope_stack and scope.name
        self._scope_stack[-1][scope.name] = scope

    def add_scope_stack(self):
        self._scope_stack.append(dict())

    def pop_scope_stack(self):
        self._scope_stack.pop()

    def clear_scope_stack(self):
        self._scope_stack[-1] = {}

    def lookup_scope(self, scope_name):
        return self.__lookup_scope(scope_name)

    def get_scope(self, scope_name, create=False):
        scope = self.lookup_scope(scope_name)

        if scope is None and create and self.last_file_scope:
            scope = self.last_file_scope.get_scope(scope_name, create)

        return scope

    def __lookup_scope(self, scope_name, dept=-1):
        if len(self._scope_stack) < -dept:
            return None
        return self._scope_stack[dept].get(scope_name,
                                           self.__lookup_scope(
                                               scope_name, dept-1
                                           )
                                           )
