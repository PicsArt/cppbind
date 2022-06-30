from examples_lib.hashing import (
    Object1,
    Object2,
    Object3,
    Object4,
    ExtendedObject1,
    ExtendedObject3,
    ExtendedObject2,
    ExtendedObject4
)

# [hashing-usage-example-start]
# custom __hash__, __eq__ and __str__
obj11 = Object1(1)
obj12 = Object1(1)
obj13 = Object1(2)

assert str(obj11) == 'Object1 1'
assert str(obj12) == 'Object1 1'
assert str(obj13) == 'Object1 2'

# obj11 and obj12 have the same value so they are equal and have the same hash
assert obj11 == obj12
assert hash(obj11) == hash(obj12)

d1 = {
    obj11: 'Object 11',
    obj13: 'Object 13',
}

assert len(d1) == 2
assert d1[obj11] == 'Object 11'
assert d1[obj13] == 'Object 13'

# default __hash__, __eq__ and __str__
obj21 = Object2()
obj22 = Object2()
assert obj21 != obj22

d2 = {
    obj21: 'Object 31',
    obj22: 'Object 32',
}

assert d2[obj21] != d2[obj22]
# CppBind generated __repr__ returning underlying C++ object type name and id
assert repr(obj21).endswith('cppbind::example::Object2>')
# [hashing-usage-example-end]


# test cases
# custom hash, equals and toString for shared_ref: False
assert hash(obj11) == hash(obj12) == 1
assert obj11 == obj12
assert obj11 != obj13
assert str(obj11) == 'Object1 1'
assert str(obj13) == 'Object1 2'

# custom hash, equals and toString for shared_ref: True
obj31 = Object3(1)
obj32 = Object3(1)
obj33 = Object3(2)
assert hash(obj31) == hash(obj32) == 1
assert obj31 == obj32
assert obj31 != obj33
assert str(obj31) == 'Object3 1'
assert str(obj33) == 'Object3 2'

# default hash, equals and toString for shared_ref: False
obj21 = Object2()
obj22 = Object2()
assert obj21 != obj22
assert hash(obj21) != hash(obj22)
assert obj21 == obj21
assert hash(obj21) == hash(obj21)
print(hash(obj21))
print(str(obj21))
assert str(obj21).endswith('cppbind::example::Object2>')

# default hash, equals and toString for shared_ref: True
obj41 = Object4()
obj42 = Object4()
assert obj41 != obj42
assert obj41 == obj41


# derived types examples
derived_obj11 = ExtendedObject1(1)
derived_obj12 = ExtendedObject1(1)
derived_obj13 = ExtendedObject1(2)
assert hash(derived_obj11) == hash(derived_obj12) == 2
assert str(derived_obj11) == 'Object1 1'
assert str(derived_obj13) == 'Object1 2'
assert derived_obj11 == derived_obj12
assert derived_obj11 != derived_obj13

derived_obj21 = ExtendedObject2()
derived_obj22 = ExtendedObject2()
assert derived_obj21 != derived_obj22
assert derived_obj21 == derived_obj21
assert str(derived_obj21).endswith('cppbind::example::ExtendedObject2>')

derived_obj31 = ExtendedObject3()
derived_obj32 = ExtendedObject3()
derived_obj33 = ExtendedObject3(1)
assert hash(derived_obj31) == hash(derived_obj32) == 0
assert derived_obj31 == derived_obj32
assert derived_obj31 != derived_obj33
assert str(derived_obj31) == 'Object3 0'
assert str(derived_obj33) == 'Object3 1'

derived_obj41 = ExtendedObject4()
derived_obj42 = ExtendedObject4()
assert derived_obj41 != derived_obj42
assert derived_obj41 == derived_obj41
assert str(derived_obj41).endswith('cppbind::example::ExtendedObject4>')

