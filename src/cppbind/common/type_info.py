# Copyright (c) 2022 PicsArt, Inc.
# All rights reserved. Use of this source code is governed by a
# MIT-style license that can be found in the LICENSE file.
import types
from functools import lru_cache

from cached_property import cached_property

from cppbind.cxx_exposed import CXXExposedType, CXXRunnerExposedType
from cppbind.ir.exec_rules import RunRule
from cppbind.utils.clang import replace_template_choice


@lru_cache(maxsize=512)
def create_type_info(runner: RunRule, cxx_exposed_type: CXXExposedType):
    return TypeInfo(runner, cxx_exposed_type)


class TypeInfo:

    def __init__(self, runner, cxx_exposed_type):
        self._runner = runner
        self._cxx_exposed_type = cxx_exposed_type
        # get canonical_pointee_type to be able to find it's context(cxx type might be a typedef, pointer etc.)
        self._type_ctx = runner.get_context(cxx_exposed_type.canonical_pointee_type.unqualified_type_name)

    @cached_property
    def cxx(self):
        return CXXRunnerExposedType(self._cxx_exposed_type._cxx_type,
                                    template_choice=self._cxx_exposed_type._template_choice,
                                    cxx_element=self._cxx_exposed_type._cxx_element,
                                    ir=self._runner.ir,
                                    ctx=self._type_ctx)

    @property
    def vars(self):
        return self._type_ctx.vars if self._type_ctx else types.SimpleNamespace(**self._runner.ir.args)

    @property
    def has_api(self):
        return self._type_ctx is not None

    @property
    def template_args_postfixes(self):
        return self._type_ctx.template_args_postfixes if self._type_ctx else None

    @property
    def template_choice(self):
        return self._type_ctx.template_choice if self._type_ctx else None

    @property
    def descendants(self):
        if self._type_ctx is None or self._type_ctx.node.descendants is None:
            return None

        _descendants = []
        for descendant_node in self._type_ctx.node.descendants:
            if descendant_node.cxx_element.is_templated:
                template_infos = RunRule._get_template_infos(descendant_node)
                for template_info in template_infos:
                    _descendants.append(replace_template_choice(descendant_node.full_displayname,
                                                                template_info.choice))
            else:
                _descendants.append(descendant_node.full_displayname)

        return _descendants
