from examples_lib.containers.map_pygen import MapItem, MapExamples
from examples_lib.containers.vector_pygen import VectorItem, VectorExamples
from examples_lib.containers.pair_pygen import PairExamples

# [map-usage]
mapusages = MapExamples()
item1 = MapItem(5)
mapusages.add_string_map({"a": "1"})
mapusages.add_int_map({1: 1})
mapusages.add_mixed_map({"a": item1})
intMap = mapusages.get_int_map()
assert intMap[1] == 1
strMap = mapusages.get_string_map()
assert strMap["a"] == "1"
mixedMap = mapusages.get_mixed_map()
assert mixedMap["a"].value == item1.value
# [map-usage]

# [vector-usage]
vectorusages = VectorExamples()

vectorusages.add_int_vector([1, 2, 3])
intVec = vectorusages.get_int_vector()
assert len(intVec) == 3
assert intVec[1] == 2

vectorusages.add_string_vector(["a", "b"])
strVec = vectorusages.get_string_vector()
assert len(strVec) == 2
assert strVec[1] == "b"

item2 = VectorItem(5)
item3 = VectorItem(1)
vectorusages.add_obj_vector([item2, item3])
objVec = vectorusages.get_obj_vector()
assert len(objVec) == 2
assert objVec[1].value == 1
# [vector-usage]

# [pair-usage]
pair_usage = PairExamples()
assert pair_usage.get_string_pair() == ("first", "second")

p1 = (1, 5)
p2 = (2, -3)
assert pair_usage.sum_int_pairs(p1, p2) == (p1[0] + p2[0], p1[1] + p2[1])

nested_pair = (("a", "b"), ("c", "d"))
pair_usage.set_nested_pair(nested_pair)
result_pair = pair_usage.get_nested_pair()
assert result_pair == nested_pair
# [pair-usage]
