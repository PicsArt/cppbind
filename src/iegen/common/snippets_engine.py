import re
import types
import os
import glob
import shutil
import copy
from jinja2 import Environment, BaseLoader, StrictUndefined
import clang.cindex as cli
import iegen.utils.clang as cutil
from iegen.common.yaml_process import load_yaml
from iegen.common.config import config
from iegen import logging as logging
from iegen import converter
from iegen.utils import make_camel_case, make_snake_case

OBJECT_INFO_TYPE = '$Object'
ENUM_INFO_TYPE = '$Enum'
FUNCTION_PROTO_INFO_TYPE = '$FunctionProto'
TYPE_SECTION = 'types'
CODE_SECTION = 'codes'
INIT_SECTION = 'init'
ACTIONS_SECTION = 'actions'


class Snippet:

    def __init__(self, context, template):
        self.context = context
        self.template = template

    def __str__(self):
        return self.template.render(self.context)


class Action:

    def __init__(self, kind_name):
        self.kind_name = kind_name

    def do(self, context):
        return {}


class FileAction(Action):

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
                    shutil.copyfile(file_name, target_file)

            # update variables
            for var_name, tmpl in self.variables_tmpl.items():
                variables[var_name].append(tmpl.render(context))

        return variables


class Converter:

    def __init__(self, clang_type, original_clang_type,
                 template_args,
                 target_lang,
                 custom,
                 ctx,
                 type_converter,
                 template_choice):
        self.clang_type = clang_type
        self.type_converter = type_converter
        self.template_args = template_args
        self.target_lang = target_lang
        self.custom = custom
        self.ctx = ctx
        self.original_clang_type = original_clang_type
        self.template_choice = template_choice
        self.context = self._make_context()

    def snippet(self, name, **kwargs):
        return self.type_converter.snippet(name, {**self.context, **kwargs})

    def converted_name(self, name):
        return self.type_converter.converted_name(name)

    @property
    def target_type_name(self):
        return self.type_converter.target_type_name(self.context)

    @property
    def cxx_type_name(self):
        return cutil.replace_template_choice(self.original_clang_type.spelling, self.template_choice)

    def _make_context(self):
        # is_type_converter = isinstance(self.type_converter, TypeConvertorInfo)
        def make():
            # helper variables
            args = [getattr(arg, self.target_lang) for arg in self.template_args]
            args_converters = self.template_args
            template_suffix = ''

            args_t = [arg.target_type_name for arg in args]
            args_t_bases = [
                cutil.get_base_cursor(arg.ctx.cursor).type.get_canonical().spelling if arg.ctx else arg.target_type_name
                for arg in args]

            # # NOTE template(not specialized) base is not considered
            # args_bases = [
            #     cutil.get_base_cursor(
            #         arg.ctx.cursor).type.get_canonical().spelling if arg.ctx else arg.target_clang_type.spelling for
            #     arg in self.template_args]

            custom = types.SimpleNamespace(**self.custom)

            cxx_type_name = self.original_clang_type.spelling

            _original_pointee = cutil.get_pointee_type(self.original_clang_type)
            cxx_pointee_name = _original_pointee.spelling
            is_pointer = self.original_clang_type.kind == cli.TypeKind.POINTER
            is_value_type = self.original_clang_type.kind == cli.TypeKind.RECORD
            is_reference = self.original_clang_type.kind == cli.TypeKind.LVALUEREFERENCE
            cxx_pointee_unqualified_name = cutil.get_unqualified_type_name(
                _original_pointee
            )
            if self.ctx:
                type_name = self.ctx.name
                type_ctx = self.ctx  # todo should we just import all attributes
                cxx_root_type = cutil.get_base_cursor(self.ctx.cursor).type.get_canonical()
                cxx_root_type_name = cutil.get_unqualified_type_name(
                    cutil.get_pointee_type(cutil.get_base_cursor(self.ctx.cursor).type))
                if self.ctx.node.is_template:
                    _base_cursor = cutil.get_base_cursor(self.ctx.cursor)
                    if _base_cursor == self.ctx.cursor:
                        cxx_root_type_name = cxx_pointee_unqualified_name
                cxx_root_type_name = cutil.replace_template_choice(
                    cxx_root_type_name, self.template_choice)
            if args:
                template_suffix = ''.join([arg.target_type_name for arg in args])

            cxx_type_name = cutil.replace_template_choice(cxx_type_name, self.template_choice)
            cxx_pointee_name = cutil.replace_template_choice(cxx_pointee_name, self.template_choice)
            cxx_pointee_unqualified_name = cutil.replace_template_choice(cxx_pointee_unqualified_name,
                                                                         self.template_choice)

            # helper name spaces

            # helper functions
            helper = converter

            return locals()

        context = make()
        del context['self']
        return context


class Adapter:

    def __init__(self, clang_type, ctx, type_info_collector, **kwargs):
        self.type_info_colector = type_info_collector
        self.clang_type = clang_type
        self.ctx = ctx
        self.original_clang_type = clang_type
        self.template_args = []
        self.kwargs = kwargs

    def set_template_args(self, args):
        self.template_args = args

    def set_original_type(self, clang_type):
        self.original_clang_type = clang_type

    @property
    def is_interface(self):
        return self.ctx.node.is_interface if self.ctx else False

    def __getattr__(self, name):
        type_info = None

        if '_to_' in name and name in self.type_info_colector.converters:
            type_info = self.type_info_colector.converters[name]
        elif name in self.type_info_colector.target_type_infos:
            type_info = self.type_info_colector.target_type_infos[name]
        else:
            return super().__getattribute__(name)

        return Converter(clang_type=self.clang_type,
                         original_clang_type=self.original_clang_type,
                         template_args=self.template_args,
                         target_lang=name,
                         custom=self.type_info_colector.custom,
                         ctx=self.ctx,
                         type_converter=type_info,
                         **self.kwargs)

    __getitem__ = __getattr__


class TypeInfoCollector:

    def __init__(self, name, target_type_infos, converters, custom):
        self.name = name
        self.converters = converters
        self.target_type_infos = target_type_infos
        self.custom = custom

    def make_converter(self, clang_type, ref_ctx, template_choice=None):
        return Adapter(clang_type=clang_type, ctx=ref_ctx, type_info_collector=self, template_choice=template_choice)


class TargetTypeInof:

    def __init__(self, name, target_type_info):
        self.target_type_info = target_type_info
        self.name = name

    def target_type_name(self, context):
        return self.target_type_info.render(context)


class TypeConvertorInfo(TargetTypeInof):

    def __init__(self, snippet_tmpl, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.snippet_tmpl = snippet_tmpl

    def snippet(self, name, context):
        if self.snippet_tmpl:
            return self.snippet_tmpl.render(name=name,
                                            target_name=self.converted_name(name),
                                            target_type_name=self.target_type_name(context),
                                            **context)
        else:
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

    def make_snippet(self, context):
        return Snippet(context=context, template=self.snippet_tmpl)

    def unique_make_snippet(self, context):
        return Snippet(context=context, template=self.unique_snippet_tmpl)


class FileScopeInfo(ScopeInfo):

    def __init__(self, file_path_tmpl, parent_scopes, scopes, snippet_tmpl, unique_snippet_tmpl):
        super().__init__(name='file', parent_scopes=parent_scopes,
                         scopes=scopes, snippet_tmpl=snippet_tmpl,
                         unique_snippet_tmpl=unique_snippet_tmpl)
        self.file_path_tmpl = file_path_tmpl

    def get_file_name(self, context):
        return self.file_path_tmpl.render(context)


class SnippetsEngine:

    def __init__(self, path, main_target):
        self.path = path
        self.main_target = main_target
        self.type_infos = {}
        self.file_infos = {}
        self.code_infos = {}
        self.action_infos = []
        self._init_jinja_env()

    def load(self):
        dirs = []
        lang_config = config.languages[self.main_target]
        if hasattr(lang_config, 'custom_config_dir'):
            dirs.append(lang_config.custom_config_dir)

        dataMap = load_yaml(self.path, dirs)

        self._load_actions(dataMap[INIT_SECTION][ACTIONS_SECTION])
        self._load_code_info(dataMap[CODE_SECTION])
        self._load_type_info(dataMap[TYPE_SECTION])

    def do_actions(self, context):
        variables = {}
        for act in self.action_infos:
            vars_ = act.do(context)
            variables.update(vars_)
        return variables

    def build_type_converter(self, ctx, clang_type,
                             template_choice=None,
                             search_name=None):

        res = self._build_type_converter(ctx, clang_type,
                                         template_choice=template_choice,
                                         search_name=search_name)
        if res is None:
            raise KeyError(f"Can not find type for {search_name or clang_type.spelling}")
        if not res.ctx:
            # if not our type(does not have a context) then set the original
            res.set_original_type(clang_type)
        return res

    def get_type_info(self, type_name):
        return self.type_infos.get(type_name, None)

    def get_code_info(self, code_name):
        return self.code_infos.get(code_name, None)

    def get_file_info(self, file_name):
        return self.file_infos[file_name]

    def _load_actions(self, actionsInfo):
        def handle_file_action(infoDict):
            glob_tmpls = infoDict['files_glob']
            if not isinstance(glob_tmpls, list):
                glob_tmpls = [glob_tmpls]
            glob_tmpls = [self.jinja2_env.from_string(tmpl) for tmpl in glob_tmpls]

            copy_to_tmpl = infoDict.get('copy_to', None)
            copy_to_tmpl = copy_to_tmpl and self.jinja2_env.from_string(copy_to_tmpl)

            variables = infoDict.get('variables', {})
            variables_tmpl = {}
            for var_name, var_tmpl in variables.items():
                var_tmpl = self.jinja2_env.from_string(var_tmpl)
                variables_tmpl[var_name] = var_tmpl

            self.action_infos.append(FileAction(glob_tmpls, copy_to_tmpl, variables_tmpl))

        def handle_default(infoDict):
            raise Exception("undefined actions.")

        actions_map = {
            'file': handle_file_action
        }
        # load into structures
        for action_info in actionsInfo:
            for action_name, action_data in action_info.items():
                try:
                    actions_map.get(action_name, handle_default)(action_data)
                except Exception as e:
                    raise Exception(f"Error in action {action_name}. Error {str(e)}")

    def _load_code_info(self, codeInfoDict):
        # load into structures
        self._load_file_info(codeInfoDict['file'])
        del codeInfoDict['file']
        # remove variables since they are used for placeholders
        variables = [key for key in codeInfoDict if key.startswith('var')]
        for key in variables:
            del codeInfoDict[key]

        for code_name, info_map in codeInfoDict.items():
            if isinstance(info_map, str):
                # redirection
                info_map = codeInfoDict[info_map]

            if not isinstance(info_map, dict):
                raise Exception("Missing scopes section.")

            self.code_infos[code_name] = self._load_code_structure_info(code_name, info_map)

    def _load_code_structure_info(self, code_name, codeInfoDict):
        def scope_walk(info_map, scopes=None):
            scopes = scopes or tuple()
            if not isinstance(info_map, dict):
                # leaf node
                yield (scopes, dict(content=info_map, unique_content=None, scopes=[]))
            elif 'content' in info_map or 'unique_content' in info_map:
                yield (scopes, dict(content=info_map.get('content', None),
                                    unique_content=info_map.get('unique_content', None),
                                    scopes=info_map.get('scopes', [])))
            else:
                for scope, child_info_map in info_map.items():
                    for d in scope_walk(child_info_map, scopes + tuple([scope])):
                        yield d

        scope_infos = {}

        for scopes, info in scope_walk(codeInfoDict):
            try:
                snippet = info['content']
                snippet = snippet and self.jinja2_env.from_string(snippet)
                unique_snippet = info['unique_content']
                unique_snippet = unique_snippet and self.jinja2_env.from_string(unique_snippet)
            except Exception as e:
                raise Exception(f"Error in code snippets {code_name}, in scope {':'.join(scopes)}. Error {str(e)}")
            scope_infos[scopes] = ScopeInfo(name=code_name,
                                            parent_scopes=scopes,
                                            scopes=info['scopes'],
                                            snippet_tmpl=snippet,
                                            unique_snippet_tmpl=unique_snippet,
                                            )

        return scope_infos

    def _load_file_info(self, codeInfoDict):
        # load into structures
        for file_name, info_map in codeInfoDict.items():
            try:
                file_path = self.jinja2_env.from_string(info_map['file_path'])
                snippet = info_map.get('content', None)
                snippet = snippet and self.jinja2_env.from_string(snippet)
                unique_snippet = info_map.get('unique_content', None)
                unique_snippet = unique_snippet and self.jinja2_env.from_string(unique_snippet)
            except Exception as e:
                raise Exception(f"Error in code file {file_name} snippets. Error {str(e)}")
            self.file_infos[file_name] = FileScopeInfo(file_path, [file_name], info_map.get('scopes', []),
                                                       snippet, unique_snippet)

    def _load_type_info(self, typeInfoDict):
        # load into structures
        for type_name, info_map in typeInfoDict.items():
            if isinstance(info_map, str):
                # redirection
                info_map = typeInfoDict[info_map]

            if not isinstance(info_map, dict):
                raise Exception("Missing type information")

            custom = {}
            target_types = {}
            type_converters = {}
            for name, info in info_map.items():
                target_info = None
                if '_to_' in name:
                    # converter
                    index = name.rfind('_to_')
                    target_lang = name[index + 4:]
                    target_lang_info = info_map.get(target_lang, {'type_info': '{{cxx_type_name}}'})
                    try:
                        target_type_info = self.jinja2_env.from_string(target_lang_info['type_info'])
                        snippet_tmpl = info and self.jinja2_env.from_string(info)
                    except Exception as e:
                        raise Exception(f"Error in code snippets for {type_name}, in converter {name}. Error {str(e)}")
                    target_info = TypeConvertorInfo(snippet_tmpl=snippet_tmpl, name=name,
                                                    target_type_info=target_type_info)
                    type_converters[name] = target_info
                elif name == 'custom':
                    # primitive type info
                    custom = info
                else:
                    # type info
                    try:
                        target_type_info = self.jinja2_env.from_string(info['type_info'])
                    except Exception as e:
                        raise Exception(f"Error in type info {type_name}, in converter {name}. Error {str(e)}")
                    target_info = TargetTypeInof(name=name, target_type_info=target_type_info)
                    target_types[name] = target_info

            self.type_infos[type_name] = TypeInfoCollector(name=type_name, target_type_infos=target_types,
                                                           converters=type_converters, custom=custom)

    def _create_type_info(self, ctx, search_name, clang_type, template_args=None, template_choice=None, **kwargs):
        logging.debug(f"Finding type for {search_name}")
        ref_ctx = ctx.find_by_type(search_name)
        if ref_ctx is not None:
            if clang_type.kind == cli.TypeKind.ENUM:
                search_name = ENUM_INFO_TYPE
            else:
                search_name = OBJECT_INFO_TYPE

        type_converter = self.get_type_info(search_name)

        if type_converter is None:
            # type info for given type is not available
            return None

        type_converter = type_converter.make_converter(clang_type, ref_ctx, template_choice=template_choice)

        if template_args:
            type_converter.set_template_args([arg for arg in template_args if arg])

        return type_converter

    def _build_type_converter(self, ctx, clang_type,
                              lookup_type=None,
                              template_choice=None,
                              search_name=None
                              ):
        template_choice = template_choice or {}

        lookup_type = lookup_type or clang_type

        search_name = search_name or cutil._get_unqualified_type_name(lookup_type.spelling)
        search_name = template_choice.get(search_name, search_name)
        logging.debug(f"Creating type converter for {search_name} and template choice {template_choice}")
        type_info = self._create_type_info(ctx, search_name, clang_type=clang_type, template_choice=template_choice)

        if type_info is None:
            pointee_type = cutil.get_pointee_type(lookup_type)
            if pointee_type != lookup_type:
                return self._build_type_converter(ctx, clang_type, pointee_type, template_choice=template_choice)
            else:
                if lookup_type.kind == cli.TypeKind.FUNCTIONPROTO:
                    tmpl_args = [self._build_type_converter(ctx, arg_type, template_choice=template_choice)
                                 for arg_type in lookup_type.argument_types()]
                    tmpl_args.append(
                        self._build_type_converter(ctx, lookup_type.get_result(), template_choice=template_choice))

                    type_info = self._create_type_info(ctx, FUNCTION_PROTO_INFO_TYPE,
                                                       clang_type=clang_type,
                                                       template_args=tmpl_args,
                                                       template_choice=template_choice)
                    return type_info

                # covers template parameter and template argument cases,
                # e.g. a::Stack<T> and a::Stack<Project>
                # might be a template typedef so get the canonical type and then proceed
                elif cutil.is_template(lookup_type) and lookup_type.kind != cli.TypeKind.TYPEDEF:
                    tmpl_args = [self._build_type_converter(ctx, arg_type, template_choice=template_choice)
                                 for arg_type in cutil.template_argument_types(lookup_type)]

                    # for the case when all arguments are exposed for example a::Stack<Project> then the canonical will
                    # return type with spelling equal to a::Stack<b::Project>
                    # this won´t work if theres an unexposed argument e.g.T,
                    # for example for the case a::Stack<T>, the  canonical will remove namespaces and return
                    # type with spelling equal to 'Stack<type-parameter-0-0>'
                    canonical_clang_type = all(
                        (not cutil.is_unexposed(arg.original_clang_type) for arg in tmpl_args))
                    if canonical_clang_type:
                        clang_type = cutil.get_canonical_type(clang_type)
                        lookup_type = cutil.get_canonical_type(lookup_type)

                    type_info = self._create_type_info(ctx, cutil.template_type_name(lookup_type),
                                                       clang_type=clang_type,
                                                       template_args=tmpl_args,
                                                       template_choice=template_choice)
                    return type_info
                else:
                    canonical_type = cutil.get_canonical_type(lookup_type)
                    if canonical_type != lookup_type:
                        return self._build_type_converter(ctx, clang_type, canonical_type,
                                                          template_choice=template_choice)

        return type_info

    def _init_jinja_env(self):
        env = Environment(loader=BaseLoader(), undefined=StrictUndefined,
                          extensions=['jinja2.ext.do', 'jinja2.ext.debug'])

        def path_join(inputs_):
            return os.path.join(*inputs_)

        env.filters['path_join'] = path_join

        def format_list(inputs_, format_string, arg_name=None):
            if arg_name is not None:
                return [format_string.format(**{arg_name: data}) for data in inputs_]
            else:
                return [format_string.format(data) for data in inputs_]

        env.filters['format_list'] = format_list

        def _any(inputs_, attribute=None):
            return any([d for d in inputs_]) if attribute is None else any([getattr(d, attribute) for d in inputs_])

        env.filters['any'] = _any

        env.filters['to_snake_case'] = make_snake_case

        env.filters['to_camel_case'] = make_camel_case

        self.jinja2_env = env
