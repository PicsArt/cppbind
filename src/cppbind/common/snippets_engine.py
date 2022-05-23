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
from types import SimpleNamespace

from jinja2 import Template

import clang.cindex as cli
from cppbind import BANNER_LOGO, converter, logging
from cppbind.common import JINJA_UNIQUE_MARKER
from cppbind.common.cxx_type import CXXType
from cppbind.common.error import Error
from cppbind.common.type_info import create_type_info
from cppbind.common.yaml_process import to_value
from cppbind.utils import JINJA2_ENV

OBJECT_INFO_TYPE = '$Object'
ENUM_INFO_TYPE = '$Enum'
FUNCTION_PROTO_INFO_TYPE = '$FunctionProto'


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


class Action:
    """Base class for any action subclass"""

    def __init__(self, kind_name):
        self.kind_name = kind_name

    def do(self, context):
        return {}


class FileAction(Action):
    """Class represents file actions"""

    def __init__(self, src_glob_tmpls, dest_tmpl, variables_tmpl):
        super().__init__('file_action')
        self.src_glob_tmpls = src_glob_tmpls
        self.dest_tmpl = dest_tmpl
        self.variables_tmpl = variables_tmpl

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
        src_file_content = JINJA2_ENV.from_string(open(src_file).read()).render(context)
        target_file_content = None
        if os.path.isfile(target_file):
            target_file_content = open(target_file).read()

        if target_file_content != src_file_content:
            with open(target_file, 'w') as f:
                f.write(src_file_content)


class Converter:

    def __init__(self,
                 type_info,
                 template_args,
                 snippet_name,
                 custom,
                 type_converter,
                 type_converter_builder,
                 **kwargs):
        self._type_info = type_info
        self._type_converter = type_converter
        self._template_args = template_args
        self._snippet_name = snippet_name
        self._custom = custom
        self._type_converter_builder = type_converter_builder
        self._context = self._make_context()

    def snippet(self, name=None, **kwargs):
        return self._type_converter.snippet(name, {**self._context, **kwargs})

    def converted_name(self, name):
        return self._type_converter.converted_name(name)

    @property
    def target_type_name(self):
        return self._type_converter.target_type_name(self._context)

    def get_target_type_name(self, **kwargs):
        return self._type_converter.target_type_name(self._context, **kwargs)

    @property
    def source_type_name(self):
        return self._type_converter.source_type_name(self._context)

    @property
    def cxx(self):
        return self._type_info.cxx

    @property
    def vars(self):
        return self._type_info.vars

    @property
    def is_obj_type(self):
        return self._type_info.vars is not None

    @property
    def template_args_postfixes(self):
        return self._type_info.template_args_postfixes

    @property
    def descendants(self):
        return self._type_info.descendants

    @property
    def args(self):
        return [getattr(arg, self._snippet_name) for arg in self._template_args]

    @property
    def args_converters(self):
        return self._template_args

    @property
    def parent_type_info(self):
        return self._type_info.parent_type_info

    def _make_context(self):
        # is_type_converter = isinstance(self.type_converter, TypeConvertorInfo)
        def make():
            # helper variables
            args = self.args
            args_converters = self.args_converters

            parent_type_info = self.parent_type_info

            cxx = self.cxx
            # make api variables available in converter under vars
            vars = self.vars
            template_args_postfixes = self.template_args_postfixes

            descendants = self.descendants

            # helper name spaces

            # helper functions
            helper = converter

            make_type_converter = self._type_converter_builder

            return locals()

        context = make()
        del context['self']

        # expose cxx and vars so that they can be overridden if required when calling snippets
        self._expose_namespace(context, 'cxx')
        self._expose_namespace(context, 'vars')

        # evaluate custom sections jinja expressions
        self._eval_custom(context)

        return context

    def _eval_custom(self, context):
        custom = SimpleNamespace()
        # evaluate custom fields one by one to make available by defined order
        for k, v in self._custom.__dict__.items():
            setattr(custom, k, v.render(context) if isinstance(v, Template) else v)
            # to make accessible for coming fields
            context['custom'] = custom

        self.custom = custom

    def _expose_namespace(self, context, name):
        if context[name]:
            for k, v in context[name].__dict__.items():
                context[f'{name}_{k}'] = v


class Adapter:

    def __init__(self, type_info, type_info_collector, **kwargs):
        self.type_info_collector = type_info_collector
        self.type_info = type_info
        self.template_args = []
        self.kwargs = kwargs

    def set_template_args(self, args):
        self.template_args = args

    def __getattr__(self, name):
        if name in self.type_info_collector.target_type_infos:
            type_info_collector = self.type_info_collector.target_type_infos[name]
        elif name in self.type_info_collector.converters:
            type_info_collector = self.type_info_collector.converters[name]
        else:
            return None

        return Converter(type_info=self.type_info,
                         template_args=self.template_args,
                         snippet_name=name,
                         custom=self.type_info_collector.custom,
                         type_converter=type_info_collector,
                         **self.kwargs)


class TypeInfoCollector:

    def __init__(self, name, target_type_infos, converters, custom, **kwargs):
        self.name = name
        self.converters = converters
        self.target_type_infos = target_type_infos
        self.custom = custom
        self.kwargs = kwargs

    def make_type_converter(self, type_info):
        return Adapter(type_info=type_info,
                       type_info_collector=self,
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
        super().__init__(name='file', parent_scopes=parent_scopes,
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
        self.jinja2_env = JINJA2_ENV

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
    def build_type_converter(self, cxx_type):

        res = self._build_type_converter(cxx_type)

        if res is None:
            raise KeyError(f"Can not find type for {cxx_type.type_name}")

        return res

    def get_type_info(self, type_name):
        return self.type_infos.get(type_name, None)

    def get_code_info(self, code_name):
        return self.code_infos.get(code_name, None)

    def get_file_info(self, file_name):
        return self.file_infos.get(file_name)

    def _load_actions(self, actions_info):
        def handle_file_action(info_dict):
            src_glob_tmpls = info_dict['files_glob']
            if not src_glob_tmpls.is_of_type(list):
                src_glob_tmpls = [src_glob_tmpls.value]
            src_glob_tmpls = [self.jinja2_env.from_string(tmpl) for tmpl in src_glob_tmpls]

            variables = info_dict.get('variables', {})
            variables_tmpl = {}
            for var_name, var_tmpl in variables.items():
                var_tmpl = self.jinja2_env.from_string(var_tmpl.value)
                variables_tmpl[var_name] = var_tmpl

            if 'copy_to' in info_dict and info_dict['copy_to']:
                self.action_infos.append(CopyFileAction(src_glob_tmpls,
                                                        self.jinja2_env.from_string(info_dict['copy_to'].value),
                                                        variables_tmpl))
            elif 'render_to' in info_dict and info_dict['render_to']:
                self.action_infos.append(RenderFileAction(src_glob_tmpls,
                                                          self.jinja2_env.from_string(info_dict['render_to'].value),
                                                          variables_tmpl))

        def handle_default(info_dict):
            Error.critical("undefined actions.")

        actions_map = {
            'file': handle_file_action
        }
        # load into structures
        for action_info in actions_info:
            for action_name, action_data in action_info.items():
                try:
                    actions_map.get(action_name, handle_default)(action_data)
                except Exception as err:
                    Error.critical(f"Error in action {action_name}. Error {str(err)}")

    def _load_code_info(self, code_info_dict):
        # load into structures
        self._load_file_info(code_info_dict['file'])
        del code_info_dict['file']
        # remove variables since they are used for placeholders
        variables = [key for key in code_info_dict if key.startswith('var')]
        for key in variables:
            del code_info_dict[key]

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
            elif 'content' in info_map or 'unique_content' in info_map:
                yield (scopes, SimpleNamespace(content=info_map.get('content', None),
                                               unique_content=info_map.get('unique_content', None),
                                               scopes=info_map.get('scopes', [])))
            else:
                for scope, child_info_map in info_map.items():
                    for d in scope_walk(child_info_map, scopes + tuple([scope])):
                        yield d

        scope_infos = {}

        for scopes, info in scope_walk(code_info_dict):
            try:
                snippet = info.content
                snippet = snippet and self.jinja2_env.from_string(snippet.value)
                unique_snippet = info.unique_content
                unique_snippet = unique_snippet and self.jinja2_env.from_string(unique_snippet.value)
            except Exception as err:
                Error.critical(f"Error in code snippets {code_name}, "
                               f"in scope {':'.join(scopes)}. Error {str(err)}")
            scope_infos[scopes] = ScopeInfo(name=code_name,
                                            parent_scopes=scopes,
                                            scopes=info.scopes,
                                            snippet_tmpl=snippet,
                                            unique_snippet_tmpl=unique_snippet)

        return scope_infos

    def _load_file_info(self, code_info_dict):
        # load into structures
        for file_name, info_map in code_info_dict.items():
            try:
                file_path = self.jinja2_env.from_string(info_map['file_path'].value)
                snippet = info_map.get('content', None)
                snippet = snippet and self.jinja2_env.from_string(snippet.value)
                unique_snippet = info_map.get('unique_content', None)
                unique_snippet = unique_snippet and self.jinja2_env.from_string(unique_snippet.value)
            except Exception as err:
                Error.critical(f"Error in code file {file_name} snippets. "
                               f"Error {str(err)}")
            else:
                self.file_infos[file_name] = FileScopeInfo(file_path,
                                                           [file_name],
                                                           info_map.get('scopes', []),
                                                           snippet,
                                                           unique_snippet)

    def _load_type_info(self, type_info_dict):
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

                        target_tmpl = source_tmpl = None
                        if target_lang and source_lang:
                            target_tmpl = source_tmpl = '{{cxx.type_name}}'
                            if target_lang in info_map[SnippetsEngine.TYPES_KEY]:
                                target_tmpl = info_map[SnippetsEngine.TYPES_KEY][target_lang].value
                            if source_lang in info_map[SnippetsEngine.TYPES_KEY]:
                                source_tmpl = info_map[SnippetsEngine.TYPES_KEY][source_lang].value

                        try:
                            target_type_info = source_type_info = None
                            if target_tmpl is not None and source_tmpl is not None:
                                target_type_info = self.jinja2_env.from_string(target_tmpl)
                                source_type_info = self.jinja2_env.from_string(source_tmpl)
                            snippet_tmpl = info and self.jinja2_env.from_string(
                                info[SnippetsEngine.SNIPPET_KEY].value if info.is_of_type(dict) else info.value)
                        except Exception as err:
                            Error.critical(f"Error in code snippets for {type_name}, "
                                           f"in converter {name}. Error {str(err)}")
                        else:
                            target_info = TypeConvertorInfo(snippet_tmpl=snippet_tmpl,
                                                            name=name,
                                                            target_type_info=target_type_info,
                                                            source_type_info=source_type_info)
                            type_converters[name] = target_info
                elif section_key == SnippetsEngine.CUSTOM_KEY:
                    # primitive type info
                    custom = SimpleNamespace(
                        **{k: self.jinja2_env.from_string(v.value) if isinstance(v.value, str) else v.value for k, v in
                           section_val.items()})
                else:
                    # type info
                    for name, info in section_val.items():
                        try:
                            target_type_info = self.jinja2_env.from_string(info.value)
                        except Exception as err:
                            Error.critical(f"Error in type info {type_name}, "
                                           f"in converter {name}. Error {str(err)}")
                        else:
                            target_info = TargetTypeInfo(name=name, target_type_info=target_type_info)
                            target_types[name] = target_info

            self.type_infos[type_name] = TypeInfoCollector(name=type_name,
                                                           target_type_infos=target_types,
                                                           converters=type_converters,
                                                           custom=custom,
                                                           type_converter_builder=self.build_type_converter_with_typename)

    def build_type_converter_with_typename(self, type_name, template_choice=None):
        return self.build_type_converter(CXXType(type_name, template_choice))

    def _create_type_info(self, search_name, cxx_type, template_args=None, **kwargs):
        logging.debug(f"Finding type for {search_name}")
        ref_ctx = self.runner.get_context(search_name)
        if ref_ctx is not None:
            if ref_ctx.cursor.kind == cli.CursorKind.ENUM_DECL:
                search_name = ENUM_INFO_TYPE
            else:
                search_name = OBJECT_INFO_TYPE

        type_converter = self.get_type_info(search_name)

        if type_converter is None:
            # type info for given type is not available
            return None

        type_info = create_type_info(self.runner, cxx_type)
        type_converter = type_converter.make_type_converter(type_info)

        if template_args:
            type_converter.set_template_args([arg for arg in template_args if arg])

        return type_converter

    def _build_type_converter(self,
                              cxx_type: CXXType,
                              lookup_type: CXXType = None,
                              search_name: str = None):
        template_choice = cxx_type.template_choice or {}

        lookup_type = lookup_type or cxx_type

        search_name = search_name or lookup_type.type_name
        search_name = template_choice.get(search_name, search_name)
        logging.debug(f"Creating type converter for {search_name} "
                      f"and template choice {template_choice}")
        type_info = None
        if not lookup_type.is_template or self.get_type_info(search_name) is not None:
            # `self.get_type_info(search_name) is not None` is to allow specialized template converters
            type_info = self._create_type_info(search_name,
                                               cxx_type=cxx_type)

        if type_info is None:
            unqualified_name = lookup_type.unqualified_type_name
            if unqualified_name != search_name:
                return self._build_type_converter(cxx_type,
                                                  lookup_type,
                                                  search_name=unqualified_name)
            pointee_type = lookup_type.pointee_type
            if pointee_type != lookup_type:
                return self._build_type_converter(cxx_type,
                                                  pointee_type)
            if lookup_type.is_function_proto:
                # here we assume lookup_type holds clang type
                # update later when we will be able to parse lambda type from string
                tmpl_args = [self.build_type_converter(CXXType(arg_type, cxx_type.template_choice))
                             for arg_type in lookup_type.type_.argument_types()]
                tmpl_args.append(
                    self.build_type_converter(CXXType(lookup_type.type_.get_result(), cxx_type.template_choice)))

                type_info = self._create_type_info(FUNCTION_PROTO_INFO_TYPE,
                                                   cxx_type=cxx_type,
                                                   template_args=tmpl_args)
                return type_info

            # covers template parameter and template argument cases,
            # e.g. a::Stack<T> and a::Stack<Project>
            # might be a template typedef so get the canonical type and then proceed
            if lookup_type.is_template and not lookup_type.is_typedef:
                tmpl_args = [self.build_type_converter(arg_type)
                             for arg_type in lookup_type.template_argument_types]

                # for the case when all arguments are exposed
                # for example a::Stack<Project> then the canonical will
                # return type with spelling equal to a::Stack<b::Project>
                # this won´t work if theres an unexposed argument e.g.T,
                # for example for the case a::Stack<T>, the canonical
                # will remove namespaces and return
                # type with spelling equal to 'Stack<type-parameter-0-0>'
                canonical_clang_type = not lookup_type.is_unexposed and all(
                    (not arg_type.is_unexposed for arg_type in lookup_type.template_argument_types))
                if canonical_clang_type:
                    lookup_type = lookup_type.canonical_type

                # at first search with full exposed name
                type_info = self._create_type_info(lookup_type.type_name,
                                                   cxx_type=cxx_type,
                                                   template_args=tmpl_args)
                if not type_info:
                    # if not found with full name search without arguments
                    type_info = self._create_type_info(lookup_type.template_type_name,
                                                       cxx_type=cxx_type,
                                                       template_args=tmpl_args)
                return type_info

            canonical_type = lookup_type.canonical_type
            if canonical_type != lookup_type:
                return self._build_type_converter(cxx_type, canonical_type)

        return type_info
