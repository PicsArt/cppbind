# Copyright (c) 2022 PicsArt, Inc.
# All rights reserved. Use of this source code is governed by a
# MIT-style license that can be found in the LICENSE file.

"""
This module is responsible for loading, processing code, types, actions snippets
"""

import copy
import filecmp
import glob
import os
import shutil
from collections.abc import MutableMapping
from functools import lru_cache, partial
from operator import attrgetter
from types import SimpleNamespace
from typing import Iterable

from jinja2 import TemplateSyntaxError, Template

from cppbind import BANNER_LOGO, logging
from cppbind.common import JINJA_UNIQUE_MARKER
from cppbind.common.error import Error, CppBindError
from cppbind.common.type_info import create_type_info
from cppbind.common.yaml_process import to_value
from cppbind.cxx_exposed import CXXExposedType
from cppbind.ir import ElementKind
from cppbind.utils import (
    get_public_attributes,
    init_jinja_env,
)

OBJECT_INFO_TYPE = '$Object'
ENUM_INFO_TYPE = '$Enum'
FUNCTION_PROTO_INFO_TYPE = '$FunctionProto'

# snippets
FILE = 'file'
FILE_PATH = 'file_path'
CONTENT = 'content'
UNIQUE_CONTENT = 'unique_content'
SCOPES = 'scopes'

# actions
FILES_GLOB = 'files_glob'
FILES_ACTION_KIND = 'file'
FILE_ACTION_VARIABLE = 'variables'
COPY_ACTION = 'copy_to'
RENDER_ACTION = 'render_to'


class Snippet:
    """
    Class represents a snippet with template and own context
    """

    def __init__(self, context, template, marker=None):
        self.context = context
        self.template = template
        self.marker = marker

    def __str__(self):
        value = self.template.render(self.context)
        if self.marker:
            return value.replace(self.marker, '')
        return value


class JinjaTemplate:
    def __init__(self, jinja_env, template_str, scope, file, line_number):
        try:
            self.template = jinja_env.from_string(template_str) if isinstance(template_str, str) else template_str
        except TemplateSyntaxError as e:
            Error.critical(f"Jinja syntax error in {scope} - {str(e)}" if scope else f"Jinja syntax error - {str(e)}",
                           file=file,
                           line=line_number + e.lineno)
        self.scope = scope
        self.file = file
        self.line_number = line_number

    def render(self, context):
        try:
            return self.template.render(context) if isinstance(self.template, Template) else self.template
        except CppBindError:
            raise
        except Exception as e:
            raise Error.critical(
                f'Jinja render error in {self.scope} - {str(e)}.', file=self.file, line=self.line_number)


class Action:
    """Base class for any action subclass"""

    def __init__(self, kind_name):
        self.kind_name = kind_name

    def do(self, context):
        return {}


class FileAction(Action):
    """Class represents file actions"""

    def __init__(self, jinja_env, src_glob_tmpls, dest_tmpl, variables_tmpl):
        super().__init__(FILES_ACTION_KIND)
        self.src_glob_tmpls = src_glob_tmpls
        self.dest_tmpl = dest_tmpl
        self.variables_tmpl = variables_tmpl
        self.jinja_env = jinja_env

    def do(self, ctx):
        variables = {name: [] for name in self.variables_tmpl}
        src_globs = [tmpl.render(ctx) for tmpl in self.src_glob_tmpls]

        def _make_context(ctx):
            def make():
                # helper variables
                path = os.path
                pat_sep = os.sep
                file_name = None
                banner_logo = BANNER_LOGO
                return locals()

            context = copy.copy(ctx)
            context.update(make())
            return context

        context = _make_context(ctx)

        for src_file in [fl for gl in src_globs for fl in sorted(glob.glob(gl, recursive=True))]:
            context['file_name'] = src_file
            if self.dest_tmpl:
                target_file = self.dest_tmpl.render(context)
                if target_file:
                    try:
                        self.do_main_action(src_file, target_file, context)
                    except OSError as err:
                        Error.error(f"CppBind couldn't do action: {err}")

            # update variables
            for var_name, tmpl in self.variables_tmpl.items():
                variables[var_name].append(tmpl.render(context))

        return variables


class CopyFileAction(FileAction):
    """Class represents file copy action"""

    def do_main_action(self, src_file, target_file, context):
        """Implementation logic of file copy action"""

        os.makedirs(os.path.dirname(target_file), exist_ok=True)
        if not os.path.isfile(target_file) or not filecmp.cmp(src_file, target_file):
            shutil.copyfile(src_file, target_file)


class RenderFileAction(CopyFileAction):
    """Class represents template file render and copy action"""

    def do_main_action(self, src_file, target_file, context):
        """Implementation logic of file render action"""

        os.makedirs(os.path.dirname(target_file), exist_ok=True)
        src_file_content = JinjaTemplate(self.jinja_env,
                                         open(src_file).read(),
                                         None,
                                         os.path.abspath(src_file),
                                         0).render(context)
        target_file_content = None
        if os.path.isfile(target_file):
            target_file_content = open(target_file).read()

        if target_file_content != src_file_content:
            with open(target_file, 'w') as f:
                f.write(src_file_content)


class TypeConverter:
    """Base type converter class"""

    def __init__(self,
                 type_info,
                 type_info_collector,
                 template_args,
                 **kwargs):
        self.type_info = type_info
        self.__type_info_collector = type_info_collector
        self.__template_args = template_args
        self.__kwargs = kwargs
        self.__context = self.__make_context()
        self.custom = self.__eval_custom(self.__context)
        self.__create_section_converters()

    @property
    def template_args(self):
        """List of template argument types"""
        return [arg.type for arg in self.__template_args]

    @property
    def template_args_kinds(self):
        """List of template argument kinds"""
        return [arg.kind for arg in self.__template_args]

    def __make_context(self):

        def make():
            # helper variables
            template_args = self.template_args
            template_args_kinds = self.template_args_kinds

            cxx = self.type_info.cxx
            vars = self.type_info.vars
            has_api = self.type_info.has_api
            template_args_postfixes = self.type_info.template_args_postfixes
            descendants = self.type_info.descendants

            return locals()

        context = make()
        del context['self']

        # expose cxx and vars so that they can be overridden if required when calling snippets
        self.__expose_type_namespace(context, 'cxx')
        self.__expose_namespace(context, 'vars')

        return context

    def __eval_custom(self, context):
        custom = SimpleNamespace()
        # evaluate custom fields one by one to make available by defined order
        for k, v in self.__type_info_collector.custom.__dict__.items():
            setattr(custom, k, v.render(context))
            # to make accessible for coming fields
            context['custom'] = custom

        return custom

    def __expose_namespace(self, context, name):
        if context[name]:
            for k, v in context[name].__dict__.items():
                context[f'{name}_{k}'] = v

    def __expose_type_namespace(self, context, name):
        if context[name]:
            for prop in get_public_attributes(CXXExposedType.__dict__):
                context[f'cxx_{prop}'] = getattr(context[name], prop)

    def __create_section_converters(self):
        """Creates concrete section type converters"""

        for name in self.__type_info_collector.target_type_infos:
            type_converter_info = self.__type_info_collector.target_type_infos[name]
            type_section_converter = TypeSectionConverter(type_converter_info, self.__context)
            setattr(self, name, type_section_converter)

        for name in self.__type_info_collector.converters:
            type_converter_info = self.__type_info_collector.converters[name]
            type_section_converter = TypeSectionConverter(type_converter_info, self.__context)
            setattr(self, name, type_section_converter)


class TypeSectionConverter:
    """Concrete type section converter"""

    def __init__(self, type_converter_info, context):
        self.__type_converter_info = type_converter_info
        self.__context = context

    def snippet(self, name=None, **kwargs):
        return self.__type_converter_info.snippet(name, {**self.__context, **kwargs})

    def converted_name(self, name):
        return self.__type_converter_info.converted_name(name)

    @property
    def target_type_name(self):
        return self.__type_converter_info.target_type_name(self.__context)

    def get_target_type_name(self, **kwargs):
        return self.__type_converter_info.target_type_name(self.__context, **kwargs)

    @property
    def source_type_name(self):
        return self.__type_converter_info.source_type_name(self.__context)


class TypeInfoCollector:

    def __init__(self, name, target_type_infos, converters, custom, **kwargs):
        self.name = name
        self.converters = converters
        self.target_type_infos = target_type_infos
        self.custom = custom
        self.kwargs = kwargs

    def make_type_converter(self, type_info, template_args):
        return TypeConverter(type_info=type_info,
                             type_info_collector=self,
                             template_args=template_args,
                             **self.kwargs)


class TargetTypeInfo:

    def __init__(self, name, target_type_info):
        self.target_type_info = target_type_info
        self.name = name

    def target_type_name(self, context, **kwargs):
        if self.target_type_info is None:
            return None
        return self.target_type_info.render({**context, **kwargs})


class TypeConvertorInfo(TargetTypeInfo):

    def __init__(self, snippet_tmpl, source_type_info, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.source_type_info = source_type_info
        self.snippet_tmpl = snippet_tmpl
        self._converted_prefix = self.name.replace('_', '')

    def source_type_name(self, context):
        if self.source_type_info is None:
            return None
        return self.source_type_info.render(context)

    def snippet(self, name, context):
        if self.snippet_tmpl:
            return self.snippet_tmpl.render({'name': name,
                                             'target_name': self.converted_name(name),
                                             'target_type_name': self.target_type_name(context),
                                             'get_target_type_name': partial(self.target_type_name, context),
                                             **context})
        return ""

    def converted_name(self, name):
        return f"{self._converted_prefix}{name}" if self.snippet_tmpl else name


class ScopeInfo:

    def __init__(self, name, parent_scopes, scopes, snippet_tmpl, unique_snippet_tmpl):
        self.name = name
        self.parent_scopes = parent_scopes
        self.scopes = scopes
        self.snippet_tmpl = snippet_tmpl
        self.unique_snippet_tmpl = unique_snippet_tmpl

    def make_snippet(self, context, marker=JINJA_UNIQUE_MARKER):
        return Snippet(context=context, template=self.snippet_tmpl, marker=marker)

    def unique_make_snippet(self, context, marker=None):
        return Snippet(context=context, template=self.unique_snippet_tmpl, marker=marker)


class FileScopeInfo(ScopeInfo):

    def __init__(self, file_path_tmpl, parent_scopes, scopes, snippet_tmpl, unique_snippet_tmpl):
        super().__init__(name=FILE, parent_scopes=parent_scopes,
                         scopes=scopes, snippet_tmpl=snippet_tmpl,
                         unique_snippet_tmpl=unique_snippet_tmpl)
        self.file_path_tmpl = file_path_tmpl

    def get_file_name(self, context):
        return self.file_path_tmpl.render(context)


class SnippetsEngine:
    TARGET_KEY = 'target'
    SOURCE_KEY = 'source'
    SNIPPET_KEY = 'snippet'
    CUSTOM_KEY = 'custom'
    TYPES_KEY = 'types'
    CONVERTERS_KEY = 'converters'

    def __init__(self, runner, ctx_desc, platform, language):
        self.runner = runner
        self.platform = platform
        self.language = language
        self.ctx_desc = ctx_desc
        self.type_infos = {}
        self.file_infos = {}
        self.code_infos = {}
        self.action_infos = []
        self.jinja_env = init_jinja_env(language)
        self.__update_jinja_env()

    def load(self):
        action_snippets = self.ctx_desc.get_action_snippets()
        code_snippets = self.ctx_desc.get_code_snippets()
        type_converter_snippets = self.ctx_desc.get_type_converter_snippets()

        if action_snippets:
            self._load_actions(action_snippets[self.language][self.platform])
        if code_snippets:
            self._load_code_info(code_snippets[self.language][self.platform])
        if type_converter_snippets:
            self._load_type_info(type_converter_snippets[self.language][self.platform])

    def do_actions(self, context):
        variables = {}
        for act in self.action_infos:
            vars_ = act.do(context)
            variables.update(vars_)
        return variables

    @lru_cache(maxsize=512)
    def build_type_converter(self, cxx_exposed_type):

        res = self._build_type_converter(cxx_exposed_type)

        if res is None:
            raise KeyError(f"Can not find type for {cxx_exposed_type.type_name}")

        return res

    def get_type_info(self, type_name):
        return self.type_infos.get(type_name, None)

    def get_code_info(self, code_name):
        return self.code_infos.get(code_name, None)

    def get_file_info(self, file_name):
        return self.file_infos.get(file_name)

    def _remove_placeholder_vars(self, info_dict):
        variables = [key for key in info_dict if key.startswith('var')]
        for key in variables:
            del info_dict[key]

    def _load_actions(self, actions_info):
        def handle_file_action(info_dict):
            src_glob_tmpls = src_glob_node = info_dict[FILES_GLOB]

            if not src_glob_tmpls.is_of_type(list):
                src_glob_tmpls = [src_glob_tmpls.value]
            src_glob_tmpls = [JinjaTemplate(self.jinja_env,
                                            tmpl,
                                            f'{FILES_ACTION_KIND}:{FILES_GLOB}',
                                            src_glob_node.file,
                                            src_glob_node.line_number) for tmpl in src_glob_tmpls]

            variables = info_dict.get('variables', {})
            variables_tmpl = {}
            for var_name, var_tmpl in variables.items():
                var_tmpl = JinjaTemplate(self.jinja_env,
                                         var_tmpl.value,
                                         f'{FILES_ACTION_KIND}:{FILE_ACTION_VARIABLE}:{var_name}',
                                         var_tmpl.file,
                                         var_tmpl.line_number)
                variables_tmpl[var_name] = var_tmpl

            if COPY_ACTION in info_dict and info_dict[COPY_ACTION]:
                action_node = info_dict[COPY_ACTION]
                self.action_infos.append(CopyFileAction(self.jinja_env,
                                                        src_glob_tmpls,
                                                        JinjaTemplate(
                                                            self.jinja_env,
                                                            action_node.value,
                                                            f'{FILES_ACTION_KIND}:{COPY_ACTION}',
                                                            action_node.file,
                                                            action_node.line_number),
                                                        variables_tmpl))
            elif RENDER_ACTION in info_dict and info_dict[RENDER_ACTION]:
                action_node = info_dict[RENDER_ACTION]
                self.action_infos.append(RenderFileAction(self.jinja_env,
                                                          src_glob_tmpls,
                                                          JinjaTemplate(self.jinja_env,
                                                                        action_node.value,
                                                                        f'{FILES_ACTION_KIND}:{RENDER_ACTION}',
                                                                        action_node.file,
                                                                        action_node.line_number),
                                                          variables_tmpl))

        def handle_default(info_dict):
            Error.critical("undefined actions.")

        actions_map = {
            'file': handle_file_action
        }
        # load into structures
        for action_info in actions_info:
            for action_name, action_data in action_info.items():
                actions_map.get(action_name, handle_default)(action_data)

    def _load_code_info(self, code_info_dict):
        # load into structures
        self._load_file_info(code_info_dict[FILE])
        del code_info_dict[FILE]
        # remove variables since they are used for placeholders
        self._remove_placeholder_vars(code_info_dict)

        for code_name, info_map in code_info_dict.items():
            if info_map.is_of_type(str):
                # redirection
                info_map = code_info_dict[info_map.value]

            if info_map.value is None:
                # allow empty rules
                continue

            if not isinstance(info_map, MutableMapping):
                Error.critical("Missing scopes section.")

            self.code_infos[code_name] = self._load_code_structure_info(code_name, info_map)

    def _load_code_structure_info(self, code_name, code_info_dict):
        def scope_walk(info_map, scopes=None):
            scopes = scopes or tuple()
            if not info_map.is_of_type(MutableMapping):
                # leaf node
                yield scopes, SimpleNamespace(content=info_map, unique_content=None, scopes=[])
            elif CONTENT in info_map or UNIQUE_CONTENT in info_map:
                yield (scopes, SimpleNamespace(content=info_map.get(CONTENT, None),
                                               unique_content=info_map.get(UNIQUE_CONTENT, None),
                                               scopes=info_map.get(SCOPES, [])))
            else:
                for scope, child_info_map in info_map.items():
                    for d in scope_walk(child_info_map, scopes + tuple([scope])):
                        yield d

        scope_infos = {}

        for scopes, info in scope_walk(code_info_dict):
            snippet = info.content
            if snippet:
                snippet = JinjaTemplate(self.jinja_env,
                                        snippet.value,
                                        f'{code_name}:{":".join(scopes)}:{CONTENT}',
                                        snippet.file,
                                        snippet.line_number)

            unique_snippet = info.unique_content
            if unique_snippet:
                unique_snippet = JinjaTemplate(self.jinja_env,
                                               unique_snippet.value,
                                               f"{code_name}:{':'.join(scopes)}:{UNIQUE_CONTENT}",
                                               unique_snippet.file,
                                               unique_snippet.line_number)

            scope_infos[scopes] = ScopeInfo(name=code_name,
                                            parent_scopes=scopes,
                                            scopes=info.scopes,
                                            snippet_tmpl=snippet,
                                            unique_snippet_tmpl=unique_snippet)

        return scope_infos

    def _load_file_info(self, code_info_dict):
        # load into structures
        for file_name, info_map in code_info_dict.items():
            file_node = info_map[FILE_PATH]
            file_path = JinjaTemplate(self.jinja_env,
                                      file_node.value,
                                      f'{FILE}:{file_name}:{FILE_PATH}',
                                      file_node.file,
                                      file_node.line_number)
            snippet = info_map.get(CONTENT, None)
            if snippet:
                snippet = JinjaTemplate(self.jinja_env,
                                        snippet.value,
                                        f'{FILE}:{file_name}:{CONTENT}',
                                        snippet.file,
                                        snippet.line_number)
            unique_snippet = info_map.get(UNIQUE_CONTENT, None)
            if unique_snippet:
                unique_snippet = JinjaTemplate(self.jinja_env,
                                               unique_snippet.value,
                                               f'{FILE}:{file_name}:{UNIQUE_CONTENT}',
                                               unique_snippet.file,
                                               unique_snippet.line_number)
            self.file_infos[file_name] = FileScopeInfo(file_path,
                                                       [file_name],
                                                       info_map.get(SCOPES, []),
                                                       snippet,
                                                       unique_snippet)

    def _load_type_info(self, type_info_dict):
        # remove variables since they are used for placeholders
        self._remove_placeholder_vars(type_info_dict)
        # load into structures
        for type_name, info_map in type_info_dict.items():
            if info_map.is_of_type(str):
                # redirection
                info_map = type_info_dict[info_map.value]

            if not isinstance(info_map, MutableMapping):
                Error.critical("Missing type information")

            custom = SimpleNamespace()
            target_types = {}
            type_converters = {}

            # iterate over all sections: 'custom', 'types', 'converters'
            for section_key, section_val in info_map.items():
                if section_key == SnippetsEngine.CONVERTERS_KEY:
                    # converter
                    for name, info in section_val.items():
                        target_lang = source_lang = None
                        if '_to_' in name:
                            index = name.rfind('_to_')
                            target_lang = name[index + 4:]
                            source_lang = name[:index]

                        if info.is_of_type(dict):
                            target_lang = to_value(info.get(SnippetsEngine.TARGET_KEY, target_lang))
                            source_lang = to_value(info.get(SnippetsEngine.SOURCE_KEY, source_lang))
                        target_type_info = source_type_info = None
                        if target_lang and source_lang:
                            target_tmpl = source_tmpl = '{{cxx.type_name}}'
                            file = section_val.file
                            # setting the initial line number the start of the converter
                            # i.e. the line number of cxx type name
                            source_line_number = target_line_number = info_map.line_number
                            if target_lang in info_map[SnippetsEngine.TYPES_KEY]:
                                target_node = info_map[SnippetsEngine.TYPES_KEY][target_lang]
                                target_tmpl = target_node.value
                                target_line_number = target_node.line_number
                            if source_lang in info_map[SnippetsEngine.TYPES_KEY]:
                                source_node = info_map[SnippetsEngine.TYPES_KEY][source_lang]
                                source_tmpl = source_node.value
                                source_line_number = source_node.line_number

                            if target_tmpl is not None and source_tmpl is not None:
                                target_type_info = JinjaTemplate(self.jinja_env,
                                                                 target_tmpl,
                                                                 f'{type_name}:{SnippetsEngine.TYPES_KEY}:{target_lang}',
                                                                 file,
                                                                 target_line_number)
                                source_type_info = JinjaTemplate(self.jinja_env,
                                                                 source_tmpl,
                                                                 f'{type_name}:{SnippetsEngine.TYPES_KEY}:{source_lang}',
                                                                 file,
                                                                 source_line_number)

                        snippet_tmpl = info and JinjaTemplate(self.jinja_env,
                                                              info[SnippetsEngine.SNIPPET_KEY].value if info.is_of_type(
                                                                  dict) else info.value,
                                                              f'{type_name}:{SnippetsEngine.CONVERTERS_KEY}:{name}',
                                                              info.file,
                                                              info.line_number)

                        target_info = TypeConvertorInfo(snippet_tmpl=snippet_tmpl,
                                                        name=name,
                                                        target_type_info=target_type_info,
                                                        source_type_info=source_type_info)
                        type_converters[name] = target_info
                elif section_key == SnippetsEngine.CUSTOM_KEY:
                    # primitive type info
                    custom = {}
                    for k, v in section_val.items():
                        custom[k] = JinjaTemplate(
                            self.jinja_env,
                            v.value,
                            f'{type_name}:custom:{k}',
                            v.file,
                            v.line_number)

                    custom = SimpleNamespace(**custom)
                else:
                    # type info
                    for name, info in section_val.items():
                        target_type_info = JinjaTemplate(self.jinja_env,
                                                         info.value,
                                                         f'{type_name}:{SnippetsEngine.TYPES_KEY}:{name}',
                                                         info.file,
                                                         info.line_number)
                        target_info = TargetTypeInfo(name=name, target_type_info=target_type_info)
                        target_types[name] = target_info

            self.type_infos[type_name] = TypeInfoCollector(name=type_name,
                                                           target_type_infos=target_types,
                                                           converters=type_converters,
                                                           custom=custom)

    def build_type_converter_with_typename(self, type_name, template_choice=None):
        return self.build_type_converter(CXXExposedType(type_name, template_choice))

    def _create_type_info(self, search_name, cxx_exposed_type, template_args=None, **kwargs):
        logging.debug(f"Finding type for {search_name}")
        ref_ctx = self.runner.get_context(search_name)
        if ref_ctx is not None:
            if ref_ctx.node.kind == ElementKind.ENUM_DECL:
                search_name = ENUM_INFO_TYPE
            else:
                search_name = OBJECT_INFO_TYPE

        type_converter = self.get_type_info(search_name)

        if type_converter is None:
            # type info for given type is not available
            return None

        type_info = create_type_info(self.runner, cxx_exposed_type)

        template_args = [arg for arg in template_args if arg] if template_args else []
        type_converter = type_converter.make_type_converter(type_info, template_args)

        return type_converter

    def _build_type_converter(self,
                              cxx_exposed_type: CXXExposedType,
                              lookup_type: CXXExposedType = None,
                              search_name: str = None):
        template_choice = cxx_exposed_type._template_choice or {}

        lookup_type = lookup_type or cxx_exposed_type

        search_name = search_name or lookup_type.type_name
        search_name = template_choice.get(search_name, search_name)
        logging.debug(f"Creating type converter for {search_name} "
                      f"and template choice {template_choice}")
        type_info = None
        if not lookup_type.is_template or self.get_type_info(search_name) is not None:
            # `self.get_type_info(search_name) is not None` is to allow specialized template converters
            type_info = self._create_type_info(search_name,
                                               cxx_exposed_type=cxx_exposed_type)

        if type_info is None:
            unqualified_name = lookup_type.unqualified_type_name
            if unqualified_name != search_name:
                return self._build_type_converter(cxx_exposed_type,
                                                  lookup_type,
                                                  search_name=unqualified_name)
            pointee_type = lookup_type.pointee_type
            if pointee_type != lookup_type:
                return self._build_type_converter(cxx_exposed_type,
                                                  pointee_type)
            if lookup_type.is_function_proto:
                # here we assume lookup_type holds clang type
                # update later when we will be able to parse lambda type from string

                # TODO, maybe not only ElementKind.TEMPLATE_TYPE_PARAMETER
                tmpl_args = [SimpleNamespace(type=CXXExposedType(arg_type, cxx_exposed_type._template_choice),
                                             kind=ElementKind.TEMPLATE_TYPE_PARAMETER)
                             for arg_type in lookup_type._cxx_type.argument_types]
                tmpl_args.append(SimpleNamespace(type=CXXExposedType(lookup_type._cxx_type.get_result(),
                                                                     cxx_exposed_type._template_choice),
                                                 kind=ElementKind.TEMPLATE_TYPE_PARAMETER))

                type_info = self._create_type_info(FUNCTION_PROTO_INFO_TYPE,
                                                   cxx_exposed_type=cxx_exposed_type,
                                                   template_args=tmpl_args)
                return type_info

            # covers template parameter and template argument cases,
            # e.g. a::Stack<T> and a::Stack<Project>
            # might be a template typedef so get the canonical type and then proceed
            if lookup_type.is_template and not lookup_type.is_typedef:
                # currently, only integral parameter is supported from non-type parameters
                tmpl_args = lookup_type.template_arguments

                # for the case when all arguments are exposed
                # for example a::Stack<Project> then the canonical will
                # return type with spelling equal to a::Stack<b::Project>
                # this won´t work if there's an unexposed argument e.g.T,
                # for example for the case a::Stack<T>, the canonical
                # will remove namespaces and return
                # type with spelling equal to 'Stack<type-parameter-0-0>'
                if not lookup_type._is_unexposed:
                    lookup_type = lookup_type.canonical_type

                # at first search with full exposed name
                type_info = self._create_type_info(lookup_type.type_name,
                                                   cxx_exposed_type=cxx_exposed_type,
                                                   template_args=tmpl_args)
                if not type_info:
                    # if not found with full name search without arguments
                    type_info = self._create_type_info(lookup_type._template_type_name,
                                                       cxx_exposed_type=cxx_exposed_type,
                                                       template_args=tmpl_args)
                return type_info

            canonical_type = lookup_type.canonical_type
            if canonical_type != lookup_type:
                return self._build_type_converter(cxx_exposed_type, canonical_type)

        return type_info

    def __create_type_converter(self, type_, error=True):
        """Function to create a converter for a given type"""

        try:
            if isinstance(type_, str):
                return self.build_type_converter_with_typename(type_)
            return self.build_type_converter(type_)
        except KeyError:
            if error:
                raise
            return None

    def __get_type_info(self, type_, error=True):
        """Function to return the type info for a given type"""

        converter = self.__create_type_converter(type_, error=error)
        return converter.type_info if converter else None

    def __create_types_converters(self, input_, attribute=None, error=True):
        """Function to create converter(s) for given type(s)"""

        if isinstance(input_, Iterable) and not isinstance(input_, str):
            return [self.__create_types_converters(item, attribute, error) for item in input_]

        try:
            input_value = attrgetter(attribute)(input_) if attribute else input_
        except AttributeError as err:
            Error.critical(f"Error while applying 'type_converter' filter: {err}")
        else:
            if not isinstance(input_value, (str, CXXExposedType)):
                Error.critical(f"'type_converter' filter is applicable only for 'str' and 'CXXExposedType' types "
                               f"(or a list of those types). {type(input_value)} is an unexpected type.")

            return self.__create_type_converter(input_value, error)

    def __get_types_infos(self, input_, attribute=None, error=True):
        """Function to return the type info(s) for given type(s)"""

        if isinstance(input_, Iterable) and not isinstance(input_, str):
            return [self.__get_types_infos(item, attribute, error) for item in input_]

        try:
            input_value = attrgetter(attribute)(input_) if attribute else input_
        except AttributeError as err:
            Error.critical(f"Error while applying 'type_info' filter: {err}")
        else:
            if not isinstance(input_value, (str, CXXExposedType)):
                Error.critical(f"'type_info' filter is applicable only for 'str' and 'CXXExposedType' types "
                               f"(or a list of those types). {type(input_value)} is an unexpected type.")

            return self.__get_type_info(input_value, error)

    def __has_api(self, cxx_element):
        return self.runner.get_context(cxx_element._get_full_displayname()) is not None

    def __update_jinja_env(self):
        """Add custom filters/globals to jinja environment"""

        self.jinja_env.filters['type_converter'] = self.__create_types_converters
        self.jinja_env.filters['type_info'] = self.__get_types_infos

        self.jinja_env.globals['get_type_converter'] = self.__create_type_converter
        self.jinja_env.globals['get_type_info'] = self.__get_type_info

        self.jinja_env.globals['has_api'] = self.__has_api
        self.jinja_env.tests['has_api'] = self.__has_api
        self.jinja_env.filters['has_api'] = self.__has_api
