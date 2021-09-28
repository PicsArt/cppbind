"""
This module is responsible for loading, processing code, types, actions snippets
"""

import copy
import filecmp
import glob
import os
import shutil
from collections.abc import MutableMapping
from types import SimpleNamespace

from jinja2 import Template

import clang.cindex as cli
import iegen.utils.clang as cutil
from iegen import converter, logging
from iegen.common import JINJA_UNIQUE_MARKER
from iegen.common.error import Error
from iegen.common.yaml_process import to_value
from iegen.ir.exec_rules import Context
from iegen.utils import JINJA2_ENV

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

    def __bool__(self):
        return str(self) != ''


class Action:
    """Base class for any action subclass"""

    def __init__(self, kind_name):
        self.kind_name = kind_name

    def do(self, context):
        return {}


class FileAction(Action):
    """Class represents file actions"""

    def __init__(self, glob_tmpls, copy_to_tmpl, variables_tmpl):
        super().__init__('file_action')
        self.glob_tmpls = glob_tmpls
        self.copy_to_tmpl = copy_to_tmpl
        self.variables_tmpl = variables_tmpl

    def do(self, ctx):
        variables = {name: [] for name in self.variables_tmpl}
        globs = [tmpl.render(ctx) for tmpl in self.glob_tmpls]

        def _make_context(ctx):
            def make():
                # helper variables
                path = os.path
                pat_sep = os.sep
                file_name = None
                return locals()

            context = copy.copy(ctx)
            context.update(make())
            return context

        context = _make_context(ctx)
        for file_name in [fl for gl in globs for fl in sorted(glob.glob(gl, recursive=True))]:

            context['file_name'] = file_name
            # take copy action
            if self.copy_to_tmpl:
                target_file = self.copy_to_tmpl.render(context)
                if target_file:
                    os.makedirs(os.path.dirname(target_file), exist_ok=True)
                    if not os.path.isfile(target_file) or not filecmp.cmp(file_name, target_file):
                        shutil.copyfile(file_name, target_file)

            # update variables
            for var_name, tmpl in self.variables_tmpl.items():
                variables[var_name].append(tmpl.render(context))

        return variables


class CXXType:
    """
    Type which holds a clang type or a string type with it's template choice if it's a template type,
    and gives some utility functionality based on it.
    """

    def __init__(self, type_, template_choice=None):
        self.type_ = type_
        self.template_choice = template_choice

    @property
    def type_name(self):
        return cutil.replace_template_choice(self.type_ if isinstance(self.type_, str) else self.type_.spelling,
                                             self.template_choice)

    @property
    def pointee_type(self):
        if isinstance(self.type_, cli.Type):
            return CXXType(self.type_.get_pointee(),
                           self.template_choice) if self.type_.get_pointee().spelling else self
        # type_ is a string
        _type = self.type_.strip()
        if _type.endswith('&&'):
            return CXXType(_type[:-2], self.template_choice)
        if _type.endswith('*') or _type.endswith('&'):
            return CXXType(_type[:-1], self.template_choice)
        return self

    @property
    def canonical_type(self):
        if isinstance(self.type_, cli.Type):
            return CXXType(self.type_.get_canonical(),
                           self.template_choice) if self.type_.get_canonical().spelling else self
        else:
            # we do not have a mechanism for string types yet
            return self

    @property
    def is_template(self):
        # we have to use type_name for clang types as well as it can be an unexposed type and it's choice can be a
        # template for example if it's spelling is T and the choice of T is std::vector<int> then T is a template
        return self.type_name.find('<') != -1

    @property
    def is_function_proto(self):
        if isinstance(self.type_, cli.Type):
            return self.type_.kind == cli.TypeKind.FUNCTIONPROTO
        # we don't have  a mechanism for string types yet
        return False

    @property
    def is_typedef(self):
        if isinstance(self.type_, cli.Type):
            return self.type_.kind == cli.TypeKind.TYPEDEF
        # we don't have  a mechanism for string types yet
        return False

    @property
    def template_argument_types(self):
        # if type is unexposed it's choice can be a template thus we need to use string parsing in that case
        if isinstance(self.type_, cli.Type) and self.type_.kind != cli.TypeKind.UNEXPOSED:
            return [CXXType(self.type_.get_template_argument_type(num), self.template_choice)
                    for num in range(self.type_.get_num_template_arguments())]
        return self._get_template_arguments()

    def _get_template_arguments(self):
        """
        Retrieves template arguments spelling from a type's spelling.
        E.g. for 'std::pair<std::string, std::vector<int>>' will return ['std::string', 'std::vector<int>']
        """
        type_spelling = self.type_name
        start_idx = type_spelling.find('<')
        all_arguments_string = type_spelling[start_idx + 1: -1]

        template_args = []
        parts = all_arguments_string.split(',')
        ii = 0
        while ii < len(parts):
            if '<' not in parts[ii]:
                # not a template
                template_args.append(CXXType(parts[ii].strip(), self.template_choice))
            else:
                # template argument
                start_count = parts[ii].count('<')
                arg_parts = []
                end_count = 0
                # find remaining part(s)
                while True:
                    end_count += parts[ii].count('>')
                    arg_parts.append(parts[ii])
                    if start_count == end_count:
                        # argument parts found join and add to the list
                        template_args.append(CXXType(','.join(arg_parts).strip()))
                        break
                    ii += 1
            ii += 1
        return template_args

    @property
    def template_type_name(self):
        return cutil.template_type_name(self.type_name)

    @property
    def is_lval_reference(self):
        return self.type_.kind == cli.TypeKind.LVALUEREFERENCE if isinstance(self.type_, cli.Type) else \
            not self.type_.strip().endswith('&&') and self.type_.strip().endswith('&')

    @property
    def is_pointer(self):
        return self.type_.kind == cli.TypeKind.POINTER if isinstance(self.type_,
                                                                     cli.Type) else self.type_.strip().endswith('*')

    @property
    def is_value(self):
        return self.type_.kind == cli.TypeKind.RECORD if isinstance(self.type_,
                                                                    cli.Type) else not self.is_pointer and not self.is_lval_reference

    @property
    def unqualified_type_name(self):
        return cutil.get_unqualified_type_name(self.type_name)

    @property
    def unqualified_pointee_name(self):
        return cutil.get_unqualified_type_name(self.pointee_name)

    @property
    def pointee_name(self):
        return cutil.replace_template_choice(
            self.pointee_type.type_.spelling if isinstance(self.type_, cli.Type) else self.pointee_type.type_,
            self.template_choice)

    @property
    def is_unexposed(self):
        """
        Recursively checks if the type has an unexposed template argument.
        E.g. std::vector<std::shared_ptr<T>> is unexposed.
        Returns:
            bool: True if the has an unexposed template argument and False otherwise.
        """
        if isinstance(self.type_, str):
            return self.type_ != cutil.replace_template_choice(self.type_, self.template_choice)
        clang_type = self.canonical_type.type_
        if clang_type.kind == cli.TypeKind.UNEXPOSED:
            return True
        if clang_type.kind == cli.TypeKind.POINTER:
            return self.pointee_type.is_unexposed
        if self.is_template:
            for arg_type in self.template_argument_types:
                if arg_type.is_unexposed:
                    return True
        return False


class Converter:

    def __init__(self,
                 cxx_type,
                 template_args,
                 target_lang,
                 custom,
                 ctx,
                 type_converter,
                 **kwargs):
        self.cxx_type = cxx_type
        self.type_converter = type_converter
        self.template_args = template_args
        self.target_lang = target_lang
        self.custom = custom
        self.ctx = ctx
        self.context = self._make_context()

    def snippet(self, name, **kwargs):
        return self.type_converter.snippet(name, {**self.context, **kwargs})

    def converted_name(self, name):
        return self.type_converter.converted_name(name)

    @property
    def target_type_name(self):
        return self.type_converter.target_type_name(self.context)

    def get_target_type_name(self, **kwargs):
        return self.type_converter.target_type_name({**self.context, **kwargs})

    @property
    def source_type_name(self):
        return self.type_converter.source_type_name(self.context)

    @property
    def cxx_type_name(self):
        return self.cxx_type.type_name

    @property
    def cxx_root_type_name(self):
        return self._get_root_type(self.ctx, self.cxx_type)

    @property
    def vars(self):
        return self.ctx.vars if self.ctx else None

    @property
    def is_proj_type(self):
        return self.ctx is not None and self.ctx.is_proj_type

    @property
    def is_obj_type(self):
        return self.ctx is not None

    def _make_context(self):
        # is_type_converter = isinstance(self.type_converter, TypeConvertorInfo)
        def make():
            # helper variables
            args = [getattr(arg, self.target_lang) for arg in self.template_args]

            args_converters = self.template_args

            cxx = SimpleNamespace(
                type_name=self.cxx_type_name,
                pointee_name=self.cxx_type.pointee_name,
                is_pointer=self.cxx_type.is_pointer,
                is_value_type=self.cxx_type.is_value,
                is_reference=self.cxx_type.is_lval_reference,
                pointee_unqualified_name=self.cxx_type.unqualified_pointee_name,
            )

            if self.ctx:
                # make api variables available in converter under vars
                vars = self.ctx.vars
                template_names = self.ctx.template_names or []
                cxx.root_type_name = self.cxx_root_type_name

            # helper name spaces

            # helper functions
            helper = converter

            return locals()

        context = make()
        del context['self']

        # expose cxx and vars so that they can be overridden if required when calling snippeta
        self._expose_namespace(context, 'cxx')
        if 'vars' in context:
            self._expose_namespace(context, 'vars')

        custom = SimpleNamespace()
        # evaluate custom fields one by one to make available by defined order
        for k, v in self.custom.__dict__.items():
            setattr(custom, k, v.render(context) if isinstance(v, Template) else v)
            context['custom'] = custom

        self.custom = custom

        return context

    def _expose_namespace(self, context, name):
        for k, v in context[name].__dict__.items():
            context[f'{name}_{k}'] = v

    def _get_root_type(self, ctx, cxx_type):
        if not ctx:
            return cxx_type.type_name
        _root_cursor = cutil.get_base_cursor(ctx.cursor)
        cxx_root_type_name = _root_cursor.type.get_canonical().spelling
        # we cannot use type_converter.ctx.node.root_type_name for template types
        # as the definition and usage types may differ
        # e.g. we can have a definition like 'class Stack<T>' and a method with argument of type 'Stack<V>'
        # although they are the same, template choices are different and cannot be applied one to another
        if ctx.node.is_template:
            _root_cursor = cutil.get_base_cursor(ctx.cursor)
            if _root_cursor == ctx.cursor:
                cxx_root_type_name = cxx_type.unqualified_pointee_name
            else:
                cxx_root_type_name = cutil.replace_template_choice(
                    _root_cursor.type.spelling, self.cxx_type.template_choice)
        return cxx_root_type_name


class Adapter:

    def __init__(self, cxx_type, ctx, type_info_collector, **kwargs):
        self.type_info_collector = type_info_collector
        self.cxx_type = cxx_type
        self.ctx = ctx
        self.vars = self.ctx.vars if self.ctx else None
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

        return Converter(cxx_type=self.cxx_type,
                         template_args=self.template_args,
                         target_lang=name,
                         custom=self.type_info_collector.custom,
                         ctx=self.ctx,
                         type_converter=type_info_collector,
                         **self.kwargs)


class TypeInfoCollector:

    def __init__(self, name, target_type_infos, converters, custom):
        self.name = name
        self.converters = converters
        self.target_type_infos = target_type_infos
        self.custom = custom

    def make_converter(self, cxx_type, ref_ctx):
        return Adapter(cxx_type=cxx_type,
                       ctx=ref_ctx,
                       type_info_collector=self)


class TargetTypeInfo:

    def __init__(self, name, target_type_info):
        self.target_type_info = target_type_info
        self.name = name

    def target_type_name(self, context):
        if self.target_type_info is None:
            return None
        return self.target_type_info.render(context)


class TypeConvertorInfo(TargetTypeInfo):

    def __init__(self, snippet_tmpl, source_type_info, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.source_type_info = source_type_info
        self.snippet_tmpl = snippet_tmpl

    def source_type_name(self, context):
        if self.source_type_info is None:
            return None
        return self.source_type_info.render(context)

    def snippet(self, name, context):
        if self.snippet_tmpl:
            return self.snippet_tmpl.render(name=name,
                                            target_name=self.converted_name(name),
                                            target_type_name=self.target_type_name(context),
                                            **context)
        return ""

    def converted_name(self, name):
        return f'{self.name}_{name}' if self.snippet_tmpl else name


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

    def __init__(self, ctx_desc, platform, language):
        self.platform = platform
        self.language = language
        self.ctx_desc = ctx_desc
        self.type_infos = {}
        self.file_infos = {}
        self.code_infos = {}
        self.action_infos = []
        self.jinja2_env = JINJA2_ENV

    def load(self):
        self._load_actions(self.ctx_desc.get_action_snippets()[self.language][self.platform])
        self._load_code_info(self.ctx_desc.get_code_snippets()[self.language][self.platform])
        self._load_type_info(self.ctx_desc.get_type_converter_snippets()[self.language][self.platform])

    def do_actions(self, context):
        variables = {}
        for act in self.action_infos:
            vars_ = act.do(context)
            variables.update(vars_)
        return variables

    def build_type_converter(self,
                             ctx,
                             cxx_type):

        res = self._build_type_converter(ctx,
                                         cxx_type)

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
            glob_tmpls = info_dict['files_glob']
            if not glob_tmpls.is_of_type(list):
                glob_tmpls = [glob_tmpls.value]
            glob_tmpls = [self.jinja2_env.from_string(tmpl) for tmpl in glob_tmpls]

            copy_to_tmpl = info_dict.get('copy_to', None)
            copy_to_tmpl = copy_to_tmpl and self.jinja2_env.from_string(copy_to_tmpl.value)

            variables = info_dict.get('variables', {})
            variables_tmpl = {}
            for var_name, var_tmpl in variables.items():
                var_tmpl = self.jinja2_env.from_string(var_tmpl.value)
                variables_tmpl[var_name] = var_tmpl

            self.action_infos.append(FileAction(glob_tmpls, copy_to_tmpl, variables_tmpl))

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
                info_map = code_info_dict[info_map]

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

            custom = {}
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
                                                           custom=custom)

    def _create_type_info(self, ctx, search_name, cxx_type, template_args=None, **kwargs):
        logging.debug(f"Finding type for {search_name}")
        ref_ctx = ctx.find_by_type(search_name)
        if ref_ctx is not None:
            if ref_ctx.cursor.kind == cli.CursorKind.ENUM_DECL:
                search_name = ENUM_INFO_TYPE
            else:
                search_name = OBJECT_INFO_TYPE

        type_converter = self.get_type_info(search_name)

        if type_converter is None:
            # type info for given type is not available
            return None

        type_converter = type_converter.make_converter(cxx_type,
                                                       ref_ctx)

        if template_args:
            type_converter.set_template_args([arg for arg in template_args if arg])

        return type_converter

    def _build_type_converter(self,
                              ctx: Context,
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
        if not cxx_type.is_template:
            type_info = self._create_type_info(ctx,
                                               search_name,
                                               cxx_type=cxx_type)

        if type_info is None:
            unqualified_name = lookup_type.unqualified_type_name
            if unqualified_name != search_name:
                return self._build_type_converter(ctx,
                                                  cxx_type,
                                                  lookup_type,
                                                  search_name=unqualified_name)
            pointee_type = lookup_type.pointee_type
            if pointee_type != lookup_type:
                return self._build_type_converter(ctx,
                                                  cxx_type,
                                                  pointee_type)
            if lookup_type.is_function_proto:
                # here we assume lookup_type holds clang type
                # update later when we will be able to parse lambda type from string
                tmpl_args = [self._build_type_converter(ctx,
                                                        CXXType(arg_type, cxx_type.template_choice))
                             for arg_type in lookup_type.type_.argument_types()]
                tmpl_args.append(
                    self._build_type_converter(ctx,
                                               CXXType(lookup_type.type_.get_result(), cxx_type.template_choice)))

                type_info = self._create_type_info(ctx,
                                                   FUNCTION_PROTO_INFO_TYPE,
                                                   cxx_type=cxx_type,
                                                   template_args=tmpl_args)
                return type_info

            # covers template parameter and template argument cases,
            # e.g. a::Stack<T> and a::Stack<Project>
            # might be a template typedef so get the canonical type and then proceed
            if lookup_type.is_template and not lookup_type.is_typedef:
                tmpl_args = [self._build_type_converter(ctx,
                                                        arg_type)
                             for arg_type in lookup_type.template_argument_types]

                # for the case when all arguments are exposed
                # for example a::Stack<Project> then the canonical will
                # return type with spelling equal to a::Stack<b::Project>
                # this won´t work if theres an unexposed argument e.g.T,
                # for example for the case a::Stack<T>, the canonical
                # will remove namespaces and return
                # type with spelling equal to 'Stack<type-parameter-0-0>'
                canonical_clang_type = not lookup_type.is_unexposed and all(
                    (not arg.cxx_type.is_unexposed for arg in tmpl_args))
                if canonical_clang_type:
                    lookup_type = lookup_type.canonical_type

                # at first search with full exposed name
                type_info = self._create_type_info(ctx,
                                                   lookup_type.type_name,
                                                   cxx_type=cxx_type,
                                                   template_args=tmpl_args)
                if not type_info:
                    # if not found with full name search without arguments
                    type_info = self._create_type_info(ctx,
                                                       lookup_type.template_type_name,
                                                       cxx_type=cxx_type,
                                                       template_args=tmpl_args)
                return type_info

            canonical_type = lookup_type.canonical_type
            if canonical_type != lookup_type:
                return self._build_type_converter(ctx, cxx_type, canonical_type)

        return type_info
