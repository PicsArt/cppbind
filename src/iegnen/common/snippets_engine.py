import types
import yaml
from jinja2 import Template, StrictUndefined
# from iegnen import logging as logging
import clang.cindex as cli
import iegnen.utils.clang as cutil


OBJECT_INFO_TYPE = '$Object'
ENUM_INFO_TYPE = '$Enum'


class Converter:

    def __init__(self, clang_type, target_clang_type,
                 template_args,
                 custom,
                 ctx, type_converter):
        self.clang_type = clang_type
        self.type_converter = type_converter
        self.template_args = template_args
        self.custom = custom
        self.ctx = ctx
        self.target_clang_type = target_clang_type
        self.context = self._make_context()

    def snippet(self, name):
        return self.type_converter.snippet(name, self.context)

    def converted_name(self, name):
        return self.type_converter.converted_name(name)

    @property
    def target_type_name(self):
        return self.type_converter.target_type_name(self.context)

    def _make_context(self):
        # is_type_converter = isinstance(self.type_converter, TypeConvertor)
        def make():
            # helper variables
            args = self.template_args
            args_t = [args.target_type_name for args in self.template_args]
            custom = types.SimpleNamespace(**self.custom)

            if self.ctx:
                type_name = self.ctx.name

            cxx_type_name = self.target_clang_type.spelling
            clang_type = self.target_clang_type
            target_pointee = cutil.get_pointee_type(self.target_clang_type)
            target_pointee_name = target_pointee.spelling
            is_pointer = target_pointee != self.target_clang_type
            target_pointee_unqualified_name = cutil.get_unqualified_type_name(
                cutil.get_pointee_type(self.target_clang_type)
            )

            # helper name spaces
            clang_utils = cutil

            # helper functions
            def helper(test):
                pass

            return locals()

        context = make()
        del context['self']
        return context


class Adapter:

    def __init__(self, clang_type, ctx, type_info_colector):
        self.type_info_colector = type_info_colector
        self.clang_type = clang_type
        self.ctx = ctx
        self.target_clang_type = clang_type
        self.template_args = []

    def set_template_args(self, args):
        self.template_args = args

    def set_target_type(self, clang_type):
        self.target_clang_type = clang_type

    def __getattr__(self, name):
        type_info = None

        if '_to_' in name and name in self.type_info_colector.converters:
            type_info = self.type_info_colector.converters[name]
        elif name in self.type_info_colector.target_type_infos:
            type_info = self.type_info_colector.target_type_infos[name]
        else:
            return super().__getattribute__(name)

        return Converter(clang_type=self.clang_type,
                         target_clang_type=self.target_clang_type,
                         template_args=[getattr(arg, name) for arg in self.template_args],
                         custom=self.type_info_colector.custom,
                         ctx=self.ctx, type_converter=type_info)

    __getitem__ = __getattr__


class TypeInfoCollector:

    def __init__(self, name, target_type_infos, converters, custom):
        self.name = name
        self.converters = converters
        self.target_type_infos = target_type_infos
        self.custom = custom

    def make_converter(self, clang_type, ref_ctx):
        return Adapter(clang_type=clang_type, ctx=ref_ctx, type_info_colector=self)


class TargetType:

    def __init__(self, name, target_type_info):
        self.target_type_info = target_type_info
        self.target_type_info_template = Template(target_type_info, undefined=StrictUndefined)
        self.name = name

    def target_type_name(self, context):
        return self.target_type_info_template.render(context)


class TypeConvertor(TargetType):

    def __init__(self, snippet, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.snippet_text = snippet
        self.snippet_template = snippet and Template(snippet, undefined=StrictUndefined)

    def snippet(self, name,  context):
        if self.snippet_template:
            return self.snippet_template.render(name=name,
                                                target_name=self.converted_name(name),
                                                target_type_name=self.target_type_name(context),
                                                **context)
        else:
            return ""

    def converted_name(self, name):
        return f'{self.name}_{name}' if self.snippet_template else name


class SnippetsEngine:

    def __init__(self, path, main_target):
        self.path = path
        self.main_target = main_target
        self.type_infos = {}

    def load(self):

        dataMap = {}
        with open(self.path) as f:
            dataMap = yaml.safe_load(f)

        # load into structures
        for type_name, info_map in dataMap.items():
            if isinstance(info_map, str):
                # redirection
                info_map = dataMap[info_map]

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
                    target_lang = name[index+4:]
                    target_lang_info = info_map.get(target_lang, {'type_info': '{{target_pointee_unqualified_name}}'})
                    try:
                        target_info = TypeConvertor(snippet=info, name=name,
                                                    target_type_info=target_lang_info['type_info'])
                    except Exception as e:
                        raise Exception(f"Error in code snippets for {type_name}, in converter {name}. Error {str(e)}")
                    type_converters[name] = target_info
                elif name == 'custom':
                    # primitive type info
                    custom = info
                else:
                    # type info
                    target_info = TargetType(name=name, target_type_info=info['type_info'])
                    target_types[name] = target_info

            self.type_infos[type_name] = TypeInfoCollector(name=type_name, target_type_infos=target_types,
                                                           converters=type_converters, custom=custom)

    def get_type_info(self, type_name):
        return self.type_infos.get(type_name, None)

    def create_type_info(self, ctx, search_name, clang_type, template_args=None, **kwargs):
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

        type_converter = type_converter.make_converter(clang_type, ref_ctx)

        if template_args:
            type_converter.set_template_args([arg for arg in template_args if arg])

        return type_converter

    def _build_type_converter(self, ctx, clang_type, lookup_type=None):

        lookup_type = lookup_type or clang_type
        search_name = cutil.get_unqualified_type_name(lookup_type)
        type_info = self.create_type_info(ctx, search_name, clang_type=clang_type)

        if type_info is None:
            pointee_type = cutil.get_pointee_type(lookup_type)
            if pointee_type != lookup_type:
                return self._build_type_converter(ctx, clang_type, pointee_type)
            else:
                canonical_type = cutil.get_canonical_type(lookup_type)
                if canonical_type != lookup_type:
                    return self._build_type_converter(ctx, clang_type, canonical_type)
            if cutil.is_template(lookup_type):
                tmpl_args = [self._build_type_converter(ctx, arg_type)
                             for arg_type in cutil.template_argument_types(lookup_type)]

                type_info = self.create_type_info(ctx, cutil.template_type_name(lookup_type),
                                                  clang_type=clang_type,
                                                  template_args=tmpl_args)
                return type_info

        return type_info

    def build_type_converter(self, ctx, clang_type):

        res = self._build_type_converter(ctx, clang_type)
        if res is None:
            raise KeyError(f"Can not find type for {clang_type.spelling}")
        # else
        # TODO handle target type
        res.set_target_type(clang_type)
        return res
