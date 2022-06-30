from examples_lib.nested_types import List
from examples_lib.nested_types.usage import ListWrapper


# [nested-types-usage-start]
value1 = List.Item.Value(1)
value2 = List.Item.Value(3)

item1 = List.Item(value1)
item2 = List.Item(value2)

l = List()

l.push_back(item1)
assert l.back.value.value == value1.value

l.push_back(item2)
assert l.back.value.value == value2.value

l.pop_back()
assert l.back.value.value == value1.value

list_wrapper = ListWrapper()
list_wrapper.push_back(item1)
assert(list_wrapper.back.value.value == value1.value)
# [nested-types-usage-end]
