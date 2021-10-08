import types

import iegen.utils.clang as cutil
from iegen.common.cxx_type import CXXType
from iegen.ir.exec_rules import Context


def create_type_info(ctx: Context, cxx_type: CXXType):
    return TypeInfo(ctx, cxx_type)


class TypeInfo:

    def __init__(self, ctx, cxx_type):
        self._ctx = ctx
        self._cxx_type = cxx_type
        # get raw type to be able to find it's context(cxx type might be a typedef, pointer etc.)
        self._raw_type = cxx_type.raw_type
        self._type_ctx = None
        if ctx and self._raw_type.unqualified_type_name:
            # for template types find exact context with appropriate template choice
            self._type_ctx = ctx.lookup_ctx_by_name(self._raw_type.unqualified_type_name)

    @property
    def cxx(self):
        if not hasattr(self, '_cxx'):
            root_type_name = None
            if self._type_ctx and self._type_ctx.kind_name != 'enum':
                root_type_name = self._type_ctx.cxx_root_type_name
                if root_type_name == self._type_ctx.cxx_type_name:
                    # might be cases when cxx_type.type_name and self._type_ctx.cxx_type_name are different as we
                    # retrieve self._type_ctx from the raw type
                    # and in this case self._type_ctx.cxx_type_name is full name while cxx_type.type_name might
                    # not contain namespace
                    root_type_name = self._cxx_type.unqualified_pointee_name
            self._cxx = types.SimpleNamespace(
                type_name=self._cxx_type.type_name,
                pointee_name=self._cxx_type.pointee_name,
                is_pointer=self._cxx_type.is_pointer,
                is_value_type=self._cxx_type.is_value,
                is_reference=self._cxx_type.is_lval_reference,
                pointee_unqualified_name=self._cxx_type.unqualified_pointee_name,
                namespace=self._type_ctx.namespace if self._type_ctx else None,
                is_open=not cutil.is_final_cursor(self._type_ctx.cursor) if self._type_ctx else None,
                is_abstract=self._type_ctx.cursor.is_abstract_record() if self._type_ctx else None,
                kind_name=self._type_ctx.kind_name if self._type_ctx else None,
                cursor=self._type_ctx.cursor if self._type_ctx else None,
                root_type_name=root_type_name)

        return self._cxx

    @property
    def base_types_infos(self):
        if not hasattr(self, '_base_types_infos'):
            self._base_types_infos = [create_type_info(self._ctx, CXXType(base_type, self._type_ctx.template_choice))
                                      for base_type in
                                      self._type_ctx.base_types] if self._type_ctx and self._type_ctx.kind_name != 'enum' else []
        return self._base_types_infos

    @property
    def arg_types_infos(self):
        if not hasattr(self, '_arg_types_infos'):
            self._arg_types_infos = [create_type_info(self._ctx, t) for t in
                                     self._raw_type.template_argument_types] if self._raw_type.is_template else []
        return self._arg_types_infos

    @property
    def root_type_info(self):
        if not hasattr(self, '_root_type_info'):
            self._root_type_info = None
            if self._type_ctx and self._type_ctx.kind_name != 'enum':
                self._root_type_info = create_type_info(self._type_ctx,
                                                        CXXType(self._type_ctx.root.cxx_type_name,
                                                                self._type_ctx.template_choice))
        return self._root_type_info

    @property
    def vars(self):
        return self._type_ctx.vars if self._type_ctx else None

    @property
    def prj_rel_file_name(self):
        return self._type_ctx.prj_rel_file_name if self._type_ctx else None

    @property
    def is_proj_type(self):
        return self._type_ctx.is_proj_type if self._type_ctx else False
