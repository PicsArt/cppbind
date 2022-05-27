# Copyright (c) 2022 PicsArt, Inc.
# All rights reserved. Use of this source code is governed by a
# MIT-style license that can be found in the LICENSE file.

import types
from functools import lru_cache
from cached_property import cached_property

import cppbind.utils.clang as cutil
from cppbind.common.cxx_type import CXXType
from cppbind.ir.exec_rules import RunRule


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

    @cached_property
    def cxx(self):
        _cxx = types.SimpleNamespace(
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
            _cxx.namespace = self._type_ctx.namespace
            _cxx.is_open = not cutil.is_final_cursor(self._type_ctx.cursor)
            _cxx.is_abstract = self._type_ctx.cursor.is_abstract_record()
            _cxx.kind_name = self._type_ctx.kind_name
            _cxx.displayname = self._type_ctx.cursor.displayname
            _cxx.source_file_name = self._type_ctx.node.file_name
            if self._type_ctx.kind_name != 'enum':
                _cxx.is_polymorphic = cutil.is_polymorphic(self._type_ctx.cursor)
                _cxx.has_multiple_base_branches = cutil.has_multiple_base_branches(self._type_ctx.cursor)

        return _cxx

    @cached_property
    def base_types_infos(self):
        return [create_type_info(self._runner, CXXType(base_type, self._type_ctx.template_choice))
                for base_type in
                self._type_ctx.base_types] if self._type_ctx and self._type_ctx.kind_name != 'enum' else []

    @cached_property
    def parent_type_info(self):
        _parent_type_info = create_type_info(self._runner, CXXType(self._type_ctx.parent_context.cxx_type_name,
                                                                   self._type_ctx.template_choice)) \
            if self._type_ctx and self._type_ctx.parent_context else None
        return _parent_type_info

    @cached_property
    def arg_types_infos(self):
        return [create_type_info(self._runner, t) for t in
                self._raw_type.template_argument_types] if self._raw_type.is_template else []

    @property
    def vars(self):
        return self._type_ctx.vars if self._type_ctx else None

    @property
    def template_args_postfixes(self):
        return self._type_ctx.template_args_postfixes if self._type_ctx else None

    @property
    def template_choice(self):
        return self._type_ctx.template_choice if self._type_ctx else None

    @property
    def descendants(self):
        return [descendant.full_displayname for descendant in self._type_ctx.node.descendants] \
            if (self._type_ctx and self._type_ctx.node.descendants is not None) else None
