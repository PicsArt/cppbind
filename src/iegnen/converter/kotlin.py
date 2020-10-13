"""
Helper codes for kotlin conversion
"""
import clang.cindex as cli
import iegnen.utils.clang as cutil

OBJECT_CXX_ID_TYPE = 'jobjectid'
OBJECT_CXX_TYPE = 'jobject'
OBJECT_CXX_MAP_TYPE = 'jmapobject'
OBJECT_ID_TYPE = 'Long'
OBJECT_TYPE = 'Object'
OBJECT_INFO_TYPE = 'tmpObject'
ENUM_INFO_TYPE = 'tmpEnum'

CXX_INCLUDE_NAMES = ["jni.h"]


CXX_HELPERS = ""


def get_includes():
    return '\n'.join([f'#include "{n}"' for n in CXX_INCLUDE_NAMES])


def indent(s, numSpaces):
    s = s.splitlines()
    s = [(numSpaces * ' ') + line for line in s]
    return '\n'.join(s)


def jni_type_prefix(type_converter):
    type_map = {
        "long long": "long"
    }
    type_name = type_converter.target_type_name
    type_name = type_map.get(type_name, type_name)
    if type_converter.primitive_type:
        if type_name.startswith('j'):
            type_name = type_name[1:]

        return type_name.capitalize()

    if isinstance(type_converter, ObjConvertor):
        return 'Long'
    # else
    return OBJECT_TYPE


def jni_array_get(type_converter):

    if isinstance(type_converter, ObjConvertor):
        return "getLongArray"

    if not type_converter.primitive_type:
        return "getObjectArray"

    prefix = jni_type_prefix(type_converter)
    # else
    return f'get{prefix}Array'


def jni_array_set(type_converter):

    if isinstance(type_converter, ObjConvertor):
        return "SetLongArrayRegion"

    if not type_converter.primitive_type:
        return "SetObjectArrayElement"

    prefix = jni_type_prefix(type_converter)
    # else
    return f'Set{prefix}ArrayRegion'


def kt_arg_str(type_name, name, default=None, **kwargs):
    arg_str = name + ': ' + type_name
    if default:
        val = default
        if val in ['nullptr', 'NULL']:
            arg_str += '? = null'
        else:
            arg_str += " = " + val
    return arg_str


def kt_jni_arg_str(type_name, name, **kwargs):
    arg_str = name + ': ' + type_name
    return arg_str


def cxx_jni_arg_str(type_name, name, **kwargs):
    arg_str = type_name + ' ' + name
    return arg_str


def format_args_str(args):
    from iegnen.builder.out_builder import Scope
    if args:
        args = '\n' + str(Scope(*args, tab=1, parts_spliter=',\n')) + '\n'
    else:
        args = ''
    return args


def jni_func_name(ctx):
    return f'j{ctx.name.capitalize()}'


class TypeInfo:

    def __init__(self, converters):
        self.converters = converters

    def __getattr__(self, name):
        if name.startswith('to_'):
            choice = name[3:]
            return self.converters[choice]
        return super().__getattribute__(name)

    def target_type():
        """
        """
        def fget(self):
            return self._target_type

        def fset(self, value):
            self._target_type = value
            for converter in self.converters.values():
                converter.target_clang_type = value
        return locals()

    target_type = property(**target_type(), doc=target_type.__doc__)

    def set_template_args(self, args_typeinfo):
        # TODO set template args for each type of converter correspondingly
        for conv_type, conv in self.converters.items():
            conv.template_args = [arg.converters[conv_type] for arg in args_typeinfo]


class TargetType:

    def __init__(self, converter_type, target_type_info, clang_type=None, primitive_type=True):
        self.target_type_info = target_type_info
        self.converter_type = converter_type
        self.clang_type = clang_type
        self.target_clang_type = clang_type
        self.primitive_type = primitive_type

    def converted_name(self, name):
        return f"{self.converter_type}_{name}"

    @property
    def target_type_name(self):
        return self.target_type_info


class TypeConvertor(TargetType):

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

    def conversion_snipped(self, name):
        return ""
        raise NotImplementedError(f"There is no conversion snipped implementation for {self.target_type_info}.")


class TemplateConvertor(TypeConvertor):

    def __init__(self, *args, **kwargs):
        kwargs.update({"primitive_type": False})
        super().__init__(*args, **kwargs)
        self._template_args = []

    @property
    def target_type_name(self):
        if self.template_args:
            tmpl_args = (arg.target_type_name for arg in self.template_args if arg)
            return self.target_type_info.format(*tmpl_args)
        # else
        return super().target_type_name

    @property
    def template_args(self):
        return self._template_args

    @template_args.setter
    def template_args(self, value):
        oldVal = self._template_args
        self._template_args = value
        self.template_args_changed(value, oldVal)

    def template_args_changed(self, newVal, oldVal):
        pass


class SimpleTemplateConverter(TemplateConvertor):

    def conversion_snipped(self, name):
        return ""

    def converted_name(self, name):
        return name


class SimpleConverter(TypeConvertor):

    def conversion_snipped(self, name):
        return ""

    def converted_name(self, name):
        return name


class ObjConvertor(TypeConvertor):

    def __init__(self, *args, **kwargs):
        kwargs.update({"primitive_type": False})
        super().__init__(*args, **kwargs)


class ObjJniToCxxConvertor(ObjConvertor):

    def __init__(self, target_type_info, clang_type):
        super().__init__(converter_type='jni_to_cxx', target_type_info=target_type_info,
                         clang_type=clang_type)

    def conversion_snipped(self, name):
        pointee = cutil.get_unqualified_type_name(cutil.get_pointee_type(self.target_clang_type))
        # TODO do we need target or target_type_info.target_clang_type is enough
        dereferencer = '*' if self.target_clang_type.kind is not cli.TypeKind.POINTER else ''
        return f"{self.target_type_name} {self.converted_name(name)} = {dereferencer}RefFromLong<{pointee}>(id)"


class ObjCxxToJniConvertor(ObjConvertor):

    def __init__(self, clang_type):
        super().__init__(converter_type='cxx_to_jni', target_type_info=OBJECT_CXX_ID_TYPE,
                         clang_type=clang_type)

    def conversion_snipped(self, name):
        return f"{self.target_type_name} {self.converted_name(name)} = UnsafeRefAsLong({name});"


class ObjKotlinToNativeConvertor(ObjConvertor):

    def __init__(self, clang_type):
        super().__init__(converter_type='kotlin_to_native', target_type_info=OBJECT_ID_TYPE,
                         clang_type=clang_type)

    def conversion_snipped(self, name):
        return f"val {self.converted_name(name)} = {name}.id"


class ObjNativeToKotlinConvertor(ObjConvertor):

    def __init__(self, target_type_info, clang_type):
        super().__init__(converter_type='native_to_kotlin', target_type_info=target_type_info,
                         clang_type=clang_type)

    def conversion_snipped(self, name):
        return f"val {self.converted_name(name)} = {self.target_type_name}({name})"


class EnumJniToCxxConvertor(ObjConvertor):

    def __init__(self, target_type_info, clang_type):
        super().__init__(converter_type='jni_to_cxx', target_type_info=target_type_info,
                         clang_type=clang_type)

    def conversion_snipped(self, name):
        return f"auto {self.converted_name(name)} = ({self.target_type_name}){name};"


class EnumCxxToJniConvertor(ObjConvertor):

    def __init__(self, clang_type):
        super().__init__(converter_type='cxx_to_jni', target_type_info='jint',
                         clang_type=clang_type)

    def conversion_snipped(self, name):
        return f"{self.target_type_name} {self.converted_name(name)} = ({self.target_type_name}){name};"


class EnumKotlinToNativeConvertor(ObjConvertor):

    def __init__(self, clang_type):
        super().__init__(converter_type='kotlin_to_native', target_type_info='Int',
                         clang_type=clang_type)

    def conversion_snipped(self, name):
        return f"val {self.converted_name(name)} = {name}.value"


class EnumNativeToKotlinConvertor(ObjConvertor):

    def __init__(self, target_type_info, clang_type):
        super().__init__(converter_type='native_to_kotlin', target_type_info=target_type_info,
                         clang_type=clang_type)

    def conversion_snipped(self, name):
        return f"val {self.converted_name(name)} = {self.target_type_name}.getByValue({name})!!"


class StringJniToCxxConvertor(TypeConvertor):

    def __init__(self, clang_type):
        super().__init__(converter_type='jni_to_cxx', target_type_info="std::string",
                         primitive_type=False,
                         clang_type=clang_type)

    def conversion_snipped(self, name):
        return f"{self.target_type_name} {self.converted_name(name)} = jni_to_string(env, {name});"


class StringCxxToJniConvertor(TypeConvertor):

    def __init__(self, clang_type):
        super().__init__(converter_type='cxx_to_jni', target_type_info='jstring',
                         primitive_type=False,
                         clang_type=clang_type)

    def conversion_snipped(self, name):
        return f"{self.target_type_name} {self.converted_name(name)} = string_to_jni(env, {name});"


class ArrayConvertor(TemplateConvertor):

    def __init__(self, converter_type, target_type_info, clang_type):
        super().__init__(converter_type=converter_type, target_type_info=target_type_info, clang_type=clang_type)

    def conversion_snipped(self, name):
        return ""

    def converted_name(self, name):
        return f"_arr_{name}"

    def template_args_changed(self, *args, **kwargs):
        self.jni_type_prefix = jni_type_prefix(self.template_args[0])
        self.jni_array_get = jni_array_get(self.template_args[0])
        self.jni_array_set = jni_array_set(self.template_args[0])


class ArrayKotlinConvertor(ArrayConvertor):

    def __init__(self, converter_type, target_type_info, clang_type):
        super().__init__(converter_type=converter_type, target_type_info=target_type_info, clang_type=clang_type)

    def conversion_snipped(self, name):
        # TODO
        array_arg_converter = self.template_args[0]
        return f"""val {self.converted_name(name)}: \
MutableList<{array_arg_converter.target_type_name}> = mutableListOf()
for (data in {name}) {{
{indent(array_arg_converter.conversion_snipped('data'), 4)}
    {self.converted_name(name)}.add({array_arg_converter.converted_name('data')})
}}"""

    def converted_name(self, name):
        return f"_array_{name}"


class ArrayKotlinToNativeConvertor(ArrayKotlinConvertor):

    def __init__(self, clang_type):
        super().__init__(converter_type='kotlin_to_native', target_type_info='{0}Array', clang_type=clang_type)


class ArrayNativeToKotlinConvertor(ArrayKotlinConvertor):

    def __init__(self, clang_type):
        super().__init__(converter_type='native_to_kotlin', target_type_info='List<{0}>', clang_type=clang_type)


class ArrayCxxToJniConvertor(ArrayConvertor):

    def __init__(self, clang_type):
        super().__init__(converter_type="cxx_to_jni", target_type_info="{0}Array", clang_type=clang_type)

    def conversion_snipped(self, name):
        # TODO
        array_arg_converter = self.template_args[0]
        arg_type_name = array_arg_converter.target_type_name
        return f"""{self.target_type_name} {self.converted_name(name)} \
= env->New{self.jni_type_prefix}Array({name}.size());
std::vector<{arg_type_name}> temp;
for (auto& data : {name}) {{
{indent(array_arg_converter.conversion_snipped('data'), 4)}
    temp.emplace_back({array_arg_converter.converted_name('data')});
}}
env->{self.jni_array_set}({self.converted_name(name)}, 0, \
static_cast<jsize>({name}.size()), &temp[0]);"""

    def converted_name(self, name):
        return f"_arr_{name}"


class ArrayJniToCxxConvertor(ArrayConvertor):

    def __init__(self, clang_type):
        target_type_name = cutil.get_unqualified_type_name(cutil.get_pointee_type(clang_type))
        super().__init__(converter_type="jni_to_cxx", target_type_info=target_type_name, clang_type=clang_type)

    def conversion_snipped(self, name):
        array_arg_converter = self.template_args[0]
        temp_name = f"_{self.converted_name(name)}"
        return f"""
{self.target_type_name} {self.converted_name(name)};
auto {temp_name} = {self.jni_array_get}(env, {name});
for (auto& data : {temp_name}) {{
{indent(array_arg_converter.conversion_snipped('data'), 4)}
    {self.converted_name(name)}.emplace_back({array_arg_converter.converted_name('data')});
}}
   """

    def converted_name(self, name):
        return f"_vec_{name}"


class MapConvertor(TemplateConvertor):

    def __init__(self, converter_type, target_type_info, clang_type):
        super().__init__(converter_type=converter_type, target_type_info=target_type_info, clang_type=clang_type)

    def conversion_snipped(self, name):
        return ""

    def converted_name(self, name):
        return f"_map_{name}"

    def template_args_changed(self, *args, **kwargs):
        self.jni_type_prefix_k = jni_type_prefix(self.template_args[0])
        self.jni_type_prefix_v = jni_type_prefix(self.template_args[1])
        self.jni_array_get_k = jni_array_get(self.template_args[0])
        self.jni_array_get_v = jni_array_get(self.template_args[1])


class MapKotlinToNativeConvertor(MapConvertor):

    def __init__(self, clang_type):
        super().__init__(converter_type='kotlin_to_native', target_type_info='Pair<{0}Array, {1}Array>',
                         clang_type=clang_type)

    def conversion_snipped(self, name):
        key_converter = self.template_args[0]
        val_converter = self.template_args[1]

        def array_init(converter):
            return "" if converter.primitive_type else f"{{{converter.target_type_name}()}}"

        return f"""val tmp_key_{self.converted_name(name)} =\
{key_converter.target_type_name}Array({name}.size){array_init(key_converter)}
val tmp_val_{self.converted_name(name)} = {val_converter.target_type_name}Array({name}.size){array_init(val_converter)}
val {self.converted_name(name)} = \
{self.target_type_name}(tmp_key_{self.converted_name(name)}, tmp_val_{self.converted_name(name)})
var index = 0
for ((key, value) in {name}) {{
{indent(key_converter.conversion_snipped('key'), 4)}
{indent(val_converter.conversion_snipped('value'), 4)}
    tmp_key_{self.converted_name(name)}[index] = {key_converter.converted_name('key')}
    tmp_val_{self.converted_name(name)}[index] = {val_converter.converted_name('value')}
    index++
}}
"""


class MapNativeToKotlinConvertor(MapConvertor):

    def __init__(self, clang_type):
        super().__init__(converter_type='native_to_kotlin', target_type_info='Map<{0}, {1}>', clang_type=clang_type)

    def conversion_snipped(self, name):
        key_converter = self.template_args[0]
        val_converter = self.template_args[1]

        return f"""val {self.converted_name(name)} = {self.target_type_name}()
for ((key, value) in {name}.first zip {name}.second) {{
{indent(key_converter.conversion_snipped('key'), 4)}
{indent(val_converter.conversion_snipped('value'), 4)}
    {self.converted_name(name)}[{key_converter.converted_name('key')}] = {val_converter.converted_name('val')}
}}
"""


class MapCxxToJniConvertor(MapConvertor):

    def __init__(self, clang_type):
        super().__init__(converter_type="cxx_to_jni", target_type_info=OBJECT_CXX_MAP_TYPE, clang_type=clang_type)

    def conversion_snipped(self, name):
        # TODO
        key_converter = self.template_args[0]
        val_converter = self.template_args[1]
        return f"""
{key_converter.target_type_name} key_{self.converted_name(name)} = env->New{self.jni_type_prefix_k}Array({name}.size());
{val_converter.target_type_name} val_{self.converted_name(name)} = env->New{self.jni_type_prefix_v}Array({name}.size());
size_t index = 0;
for (auto& data : {name}) {{
    key = data.first
    val = data.second
{indent(key_converter.conversion_snipped('key'), 4)}
    key_{self.converted_name(name)}[index] = {key_converter.converted_name('key')};
{indent(val_converter.conversion_snipped('val'), 4)}
    val_{self.converted_name(name)}[index] = {val_converter.converted_name('val')};
    ++index
}}
{self.target_type_name} {self.converted_name(name)} pair = make_jni_pair(env, \
key_{self.converted_name(name)}, val_{self.converted_name(name)});
"""

    def converted_name(self, name):
        return f"_map_{name}"


class MapJniToCxxConvertor(MapConvertor):

    def __init__(self, clang_type):
        target_type_name = cutil.get_unqualified_type_name(cutil.get_pointee_type(clang_type))
        super().__init__(converter_type="jni_to_cxx", target_type_info=target_type_name, clang_type=clang_type)

    def conversion_snipped(self, name):
        # TODO
        key_converter = self.template_args[0]
        val_converter = self.template_args[1]

        temp_name = f"_{self.converted_name(name)}"
        return f"""
{self.target_type_name} {self.converted_name(name)};
auto {temp_name} = extract_jni_pair(env, {name});
auto key{temp_name} = {self.jni_array_get_k}(env, {temp_name}.first);
auto val{temp_name} = {self.jni_array_get_v}(env, {temp_name}.second);
for (size_t i = 0; i < key{temp_name}.size(); ++i) {{
    auto ktmp = key{temp_name}[i];
    auto vtmp = val{temp_name}[i];
{indent(key_converter.conversion_snipped('ktmp'), 4)}
{indent(val_converter.conversion_snipped('vtmp'), 4)}
    {self.converted_name(name)}.\
insert({{ {key_converter.converted_name('ktmp')}, {val_converter.converted_name('vtmp')} }});
}}
   """

    def converted_name(self, name):
        return f"_map_{name}"


def simple_converter(jni_cxx_type_info, native_type_info, kotlin_type_info, primitive_type=True):
    def make(clang_type, ref_ctx):
        jni_to_cxx = SimpleConverter('jni_to_cxx', ref_ctx and ref_ctx.name or clang_type.spelling,
                                     clang_type, primitive_type=primitive_type)
        cxx_to_jni = SimpleConverter('cxx_to_jni', jni_cxx_type_info, clang_type, primitive_type=primitive_type)
        kotlin_to_native = SimpleConverter('kotlin_to_native', native_type_info, clang_type,
                                           primitive_type=primitive_type)
        native_to_kotlin = SimpleConverter('native_to_kotlin', kotlin_type_info, clang_type,
                                           primitive_type=primitive_type)
        kotlin = SimpleConverter('kotlin', kotlin_type_info, clang_type, primitive_type=primitive_type)
        return TypeInfo(
            dict(
                jni_to_cxx=jni_to_cxx,
                cxx_to_jni=cxx_to_jni,
                kotlin_to_native=kotlin_to_native,
                native_to_kotlin=native_to_kotlin,
                kotlin=kotlin,
                jni=cxx_to_jni,
                native=kotlin_to_native,
            )
        )

    return make


def object_converter():
    def make(clang_type, ref_ctx):
        jni_to_cxx = ObjJniToCxxConvertor(clang_type.spelling, clang_type)
        cxx_to_jni = ObjCxxToJniConvertor(clang_type)
        kotlin_to_native = ObjKotlinToNativeConvertor(clang_type)
        native_to_kotlin = ObjNativeToKotlinConvertor(ref_ctx.name, clang_type)
        return TypeInfo(
            dict(
                jni_to_cxx=jni_to_cxx,
                cxx_to_jni=cxx_to_jni,
                kotlin_to_native=kotlin_to_native,
                native_to_kotlin=native_to_kotlin,
                kotlin=native_to_kotlin,
                jni=cxx_to_jni,
                native=kotlin_to_native,
            )
        )

    return make


def enum_converter():
    def make(clang_type, ref_ctx):
        jni_to_cxx = EnumJniToCxxConvertor(clang_type.spelling, clang_type)
        cxx_to_jni = EnumCxxToJniConvertor(clang_type)
        kotlin_to_native = EnumKotlinToNativeConvertor(clang_type)
        native_to_kotlin = EnumNativeToKotlinConvertor(ref_ctx.name, clang_type)
        return TypeInfo(
            dict(
                jni_to_cxx=jni_to_cxx,
                cxx_to_jni=cxx_to_jni,
                kotlin_to_native=kotlin_to_native,
                native_to_kotlin=native_to_kotlin,
                kotlin=native_to_kotlin,
                jni=cxx_to_jni,
                native=kotlin_to_native,
            )
        )

    return make


def string_converter():

    def make(clang_type, ref_ctx):
        jni_to_cxx = StringJniToCxxConvertor(clang_type)
        cxx_to_jni = StringCxxToJniConvertor(clang_type)
        kotlin_to_native = SimpleConverter('kotlin_to_native', 'String', clang_type, primitive_type=False)
        native_to_kotlin = SimpleConverter('native_to_kotlin', 'String', clang_type, primitive_type=False)
        kotlin = native_to_kotlin
        return TypeInfo(
            dict(
                jni_to_cxx=jni_to_cxx,
                cxx_to_jni=cxx_to_jni,
                kotlin_to_native=kotlin_to_native,
                native_to_kotlin=native_to_kotlin,
                kotlin=kotlin,
                jni=cxx_to_jni,
                native=kotlin_to_native,
            )
        )

    return make


def template_converter(jni_cxx_type_info, native_type_info, kotlin_type_info):
    def make(clang_type, ref_ctx):
        jni_to_cxx = SimpleTemplateConverter('jni_to_cxx', clang_type.spelling, clang_type)
        cxx_to_jni = SimpleTemplateConverter('cxx_to_jni', jni_cxx_type_info, clang_type)
        kotlin_to_native = SimpleTemplateConverter('kotlin_to_native', native_type_info, clang_type)
        native_to_kotlin = SimpleTemplateConverter('native_to_kotlin', kotlin_type_info, clang_type)
        kotlin = SimpleTemplateConverter('kotlin', kotlin_type_info, clang_type)
        return TypeInfo(
            dict(
                jni_to_cxx=jni_to_cxx,
                cxx_to_jni=cxx_to_jni,
                kotlin_to_native=kotlin_to_native,
                native_to_kotlin=native_to_kotlin,
                kotlin=kotlin,
                jni=cxx_to_jni,
                native=kotlin_to_native,
            )
        )

    return make


def array_converter():
    def make(clang_type, ref_ctx):
        jni_to_cxx = ArrayJniToCxxConvertor(clang_type)
        cxx_to_jni = ArrayCxxToJniConvertor(clang_type=clang_type)
        kotlin_to_native = ArrayKotlinToNativeConvertor(clang_type=clang_type)
        native_to_kotlin = ArrayNativeToKotlinConvertor(clang_type=clang_type)
        return TypeInfo(
            dict(
                jni_to_cxx=jni_to_cxx,
                cxx_to_jni=cxx_to_jni,
                kotlin_to_native=kotlin_to_native,
                native_to_kotlin=native_to_kotlin,
                kotlin=native_to_kotlin,
                jni=cxx_to_jni,
                native=kotlin_to_native,
            )
        )

    return make


def map_converter():
    def make(clang_type, ref_ctx):
        jni_to_cxx = MapJniToCxxConvertor(clang_type)
        cxx_to_jni = MapCxxToJniConvertor(clang_type=clang_type)
        kotlin_to_native = MapKotlinToNativeConvertor(clang_type=clang_type)
        native_to_kotlin = MapNativeToKotlinConvertor(clang_type=clang_type)
        return TypeInfo(
            dict(
                jni_to_cxx=jni_to_cxx,
                cxx_to_jni=cxx_to_jni,
                kotlin_to_native=kotlin_to_native,
                native_to_kotlin=native_to_kotlin,
                kotlin=native_to_kotlin,
                jni=cxx_to_jni,
                native=kotlin_to_native,
            )
        )

    return make


type_mapping = {
    OBJECT_INFO_TYPE: object_converter(),
    ENUM_INFO_TYPE: enum_converter(),
    'void': simple_converter('void', 'Void', 'Void'),
    'int': simple_converter('jint', 'Int', 'Int'),
    'short': simple_converter('jshort', 'Short', 'Short'),
    'long': simple_converter('jlong', 'Long', 'Long'),
    'long long': simple_converter('jlong', 'Long', 'Long'),
    'unsigned long': simple_converter('jlong', 'Long', 'Long'),
    'float': simple_converter('jfloat', 'Float', 'Float'),
    'double': simple_converter('jdouble', 'Double', 'Double'),
    'char': simple_converter('jchar', 'String', 'String'),
    'std::__cxx11::basic_string': string_converter(),
    'std::vector': array_converter(),
    'std::map': map_converter(),
    'std::unordered_map': map_converter(),
    'std::shared_ptr': template_converter('{0}', '{0}', '{0}'),
}


class Converter:

    class type_selecter:

        def __init__(self, type_converter, processor, prefix='from_'):
            self.type_converter = type_converter
            self.processor = processor
            self.prefix = prefix

        def __getattr__(self, name):
            if name.startswith(self.prefix):
                choice = name[len(self.prefix):]
            else:
                choice = name

            if choice in self.type_converter.converters:
                res = self.processor(choice)
                return res

            return super().__getattribute__(name)

    def __init__(self, type_converter, depth, template_args=None):
        self.type_converter = type_converter
        self.template_args = template_args
        self.depth = depth

    @property
    def type_name(self):
        return Converter.type_selecter(
            self.type_converter,
            lambda x: self.type_converter.converters[x].target_type_name
        )

    @property
    def converter_code(self):
        return Converter.type_selecter(
            self.type_converter,
            lambda x: self.type_converter.converters[x],
            prefix='from_'
        )


def create_type_info(ctx, search_name, depth, clang_type, template_args=None, **kwargs):
    ref_ctx = ctx.find_by_type(search_name)
    if ref_ctx is not None:
        if clang_type.kind == cli.TypeKind.ENUM:
            search_name = ENUM_INFO_TYPE
        else:
            search_name = OBJECT_INFO_TYPE

    type_converter = type_mapping.get(search_name, None)

    if type_converter is None:
        # type info for given type is not available
        return None

    type_converter = type_converter(clang_type, ref_ctx)

    if template_args:
        type_converter.set_template_args([arg.type_converter for arg in template_args if arg])

    return Converter(type_converter=type_converter, depth=depth, template_args=template_args)


def _build_type_converter(ctx, clang_type, lookup_type=None, depth=0):

    lookup_type = lookup_type or clang_type
    search_name = cutil.get_unqualified_type_name(lookup_type)
    type_info = create_type_info(ctx, search_name, depth=depth, clang_type=clang_type)

    if type_info is None:
        pointee_type = cutil.get_pointee_type(lookup_type)
        if pointee_type != lookup_type:
            return _build_type_converter(ctx, clang_type, pointee_type,
                                         depth=depth,
                                         )
        else:
            canonical_type = cutil.get_canonical_type(lookup_type)
            if canonical_type != lookup_type:
                return _build_type_converter(ctx, clang_type, canonical_type,
                                             depth=depth
                                             )
        if cutil.is_template(lookup_type):
            tmpl_args = [_build_type_converter(ctx, arg_type, depth=depth+1)
                         for arg_type in cutil.template_argument_types(lookup_type)]

            type_info = create_type_info(ctx, cutil.template_type_name(lookup_type),
                                         depth=depth,
                                         clang_type=clang_type,
                                         template_args=tmpl_args)
            return type_info

    return type_info


def build_type_converter(ctx, clang_type):

    res = _build_type_converter(ctx, clang_type)
    if res is None:
        raise KeyError(f"Can not find type for {clang_type.spelling}")
    # else
    res.type_converter.target_type = clang_type

    return res
