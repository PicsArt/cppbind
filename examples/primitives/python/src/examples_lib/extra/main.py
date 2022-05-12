from examples_lib.extra.object_usage_pygen import ObjectUsage

# [object-usage]
obj_usage = ObjectUsage()
assert obj_usage.class_name() == "cppbind::ObjectUsage"
assert obj_usage == obj_usage
assert obj_usage.bytes_count() == 8
obj_str = str(obj_usage)
obj_repr = repr(obj_usage)
assert obj_str == obj_repr and obj_str.endswith("cppbind::ObjectUsage>")
# [object-usage]
