import types
from functools import lru_cache

import iegen.utils.clang as cutil
from iegen.common.cxx_type import CXXType
from iegen.ir.exec_rules import RunRule


@lru_cache(maxsize=512)
def create_type_info(runner: RunRule, cxx_type: CXXType):
    return TypeInfo(runner, cxx_type)


class TypeInfo:

    def __init__(self, runner, cxx_type):
        self._runner = runner
        self._cxx_type = cxx_type
        # get raw type to be able to find it's context(cxx type might be a typedef, pointer etc.)
        self._raw_type = cxx_type.raw_type
        # get type context for cxx type
        self._type_ctx = runner.get_context(cxx_type.raw_type.unqualified_type_name)

    @property
    def cxx(self):
        if not hasattr(self, '_cxx'):
            self._cxx = types.SimpleNamespace(
                type_name=self._cxx_type.type_name,
                pointee_name=self._cxx_type.pointee_name,
                canonical_type=self._cxx_type.canonical_type,
                is_pointer=self._cxx_type.is_pointer,
                is_value_type=self._cxx_type.is_value,
                is_lval_reference=self._cxx_type.is_lval_reference,
                is_rval_reference=self._cxx_type.is_rval_reference,
                unqualified_resolved_type_name=self._cxx_type.unqualified_resolved_type_name,
                unqualified_type_name=self._cxx_type.unqualified_type_name,
                unqualified_canonical_type_name=self._cxx_type.raw_type.unqualified_type_name,
                is_const_qualified=self._cxx_type.is_const_qualified)
            if self._type_ctx:
                self._cxx.namespace = self._type_ctx.namespace
                self._cxx.is_open = not cutil.is_final_cursor(self._type_ctx.cursor)
                self._cxx.is_abstract = self._type_ctx.cursor.is_abstract_record()
                self._cxx.kind_name = self._type_ctx.kind_name
                self._cxx.displayname = self._type_ctx.cursor.displayname

        return self._cxx

    @property
    def base_types_infos(self):
        if not hasattr(self, '_base_types_infos'):
            self._base_types_infos = [create_type_info(self._runner, CXXType(base_type, self._type_ctx.template_choice))
                                      for base_type in
                                      self._type_ctx.base_types] if self._type_ctx and self._type_ctx.kind_name != 'enum' else []
        return self._base_types_infos

    @property
    def arg_types_infos(self):
        if not hasattr(self, '_arg_types_infos'):
            self._arg_types_infos = [create_type_info(self._runner, t) for t in
                                     self._raw_type.template_argument_types] if self._raw_type.is_template else []
        return self._arg_types_infos

    @property
    def root_types_infos(self):
        if not hasattr(self, '_roots'):
            self._roots = []
            if self._type_ctx and self._type_ctx.kind_name != 'enum':
                for parent in set(self._type_ctx.ancestors):
                    if not parent.base_types:
                        self._roots.append(create_type_info(self._runner, CXXType(parent.cxx_type_name,
                                                                            self._type_ctx.template_choice)))
                if not self._roots:
                    self._roots.append(self)

        return self._roots

    @property
    def vars(self):
        return self._type_ctx.vars if self._type_ctx else None

    @property
    def template_names(self):
        return self._type_ctx.template_names if self._type_ctx else None

    @property
    def template_choice(self):
        return self._type_ctx.template_choice if self._type_ctx else None

    @property
    def descendants(self):
        return [descendant.full_displayname for descendant in self._type_ctx.node.descendants]\
            if (self._type_ctx and self._type_ctx.node.descendants is not None) else None
