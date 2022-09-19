from examples_lib.rv_policies import (
    ValuesHolder,
    Value,
    ValueSharedRef,
    Child1,
    Child2,
    Child3,
    Parent1,
    Parent2,
)

# return raw pointer
# RVP not specified the default is used i.e.take_ownership for pointers
holder = ValuesHolder()

value_ptr_default = holder.get_ptr_default()
value_ptr_default.name = "update"
assert holder.get_ptr_default() == value_ptr_default

# RVP=copy - a new object is created and the owner is python
holder = ValuesHolder()
value_ptr_copied = holder.get_ptr_copy()
value_ptr_copied.name = "update"
print("DEBUG: ", holder.get_ptr_copy().name)
assert holder.get_ptr_copy().name == "initial"
holder.clean()

# RVP=move - a new object is created and the owner is python
holder = ValuesHolder()
value_ptr_moved = holder.get_ptr_move()
value_ptr_moved.name = "update"
print("DEBUG: ", holder.get_ptr_move().name)
assert holder.get_ptr_reference().name == ""
holder.clean()

holder = ValuesHolder()
movable_value = holder.get_movable_value()
assert movable_value.name == "abc"

# RVP=reference - owner is cpp
holder = ValuesHolder()
value_ptr_ref = holder.get_ptr_reference()
value_ptr_ref.name = "update"
print("DEBUG: ", holder.get_ptr_reference().name)
assert holder.get_ptr_reference().name == value_ptr_ref.name
holder.clean()

# RVP=automatic_reference - owner is cpp
holder = ValuesHolder()
value_ptr_auto_ref = holder.get_ptr_automatic_reference()
value_ptr_auto_ref.name = "update"
print("DEBUG: ", holder.get_ptr_automatic_reference().name)
assert holder.get_ptr_automatic_reference().name == value_ptr_auto_ref.name
holder.clean()

# RVP in (automatic, take_ownership) - are handled similarly for pointers i.e new object is not created
# and the owner is python
holder = ValuesHolder()
value_ptr_take_ownership = holder.get_ptr_take_ownership()
value_ptr_take_ownership.name = "update"
print("DEBUG: ", holder.get_ptr_take_ownership().name)
assert holder.get_ptr_take_ownership().name == value_ptr_take_ownership.name
# for the above tree methods pybind returns the same instance as the first call is with RVP=reference
# then the owner is cpp


# return by value
# In case return by value given RVP is ignored and copy is always used.

# RVP not specified the default is used i.e.copy for values
holder = ValuesHolder()

value_default = holder.get_value_default()
value_default.name = "update"
print("DEBUG: ", holder.get_value_default().name)
assert holder.get_value_default().name != "update"
assert holder.get_value_default() != value_default
holder.clean()

holder = ValuesHolder()
# RVP=copy - a new object is created and the owner is python
value_copied = holder.get_value_copy()
print("DEBUG: ", value_copied.name)
assert value_copied.name == "initial"
value_copied.name = "update"
# original instance is not updated
print("DEBUG: ", holder.get_value_copy().name)
assert holder.get_value_copy().name == "initial"
holder.clean()

holder = ValuesHolder()
# RVP=move a new object is created and the owner is python
value_moved = holder.get_value_move()
value_moved.name = "update"
# original instance is not updated
print("DEBUG: ", holder.get_value_move().name)
assert holder.get_value_move().name == "initial"
holder.clean()

# RVP=reference and it's ignored as object is returned by value copy is used instead
holder = ValuesHolder()
value_by_ref = holder.get_value_reference()
value_by_ref.name = "update"
# original instance is not updated
print("DEBUG: ", holder.get_value_reference().name)
assert holder.get_value_reference().name == "initial"
holder.clean()

# RVP=automatic and it's ignored as object is returned by value copy is used instead
holder = ValuesHolder()
holder.get_value_automatic().name = "update"
# original instance is not updated
print("DEBUG: ", holder.get_value_automatic().name)
assert holder.get_value_automatic().name == "initial"
holder.clean()

# RVP=automatic_reference and it's ignored as object is returned by value copy is used instead
holder = ValuesHolder()
holder.get_value_automatic_reference().name = "update"
# original instance is not updated
print("DEBUG: ", holder.get_value_automatic_reference().name)
assert holder.get_value_automatic_reference().name == "initial"
holder.clean()

# RVP=take_ownership and it's ignored as object is returned by value copy is used instead
holder = ValuesHolder()
holder.get_value_take_ownership().name = "update"
# original instance is not updated
print("DEBUG: ", holder.get_value_take_ownership().name)
assert holder.get_value_take_ownership().name == "initial"
holder.clean()


# return by reference
# RVP not specified the default is used i.e.copy for methods returning reference
holder = ValuesHolder()

value_ref_default = holder.get_ref_default()
value_ref_default.name = "update"
print("DEBUG: ", holder.get_ref_default().name)
assert holder.get_ref_default().name != "update"
assert holder.get_ref_default() != value_ref_default
holder.clean()

# RVP=copy - a new object is created and the owner is python
holder = ValuesHolder()
value_ref_copied = holder.get_ref_copy()
value_ref_copied.name = "update"
print("DEBUG: ", holder.get_ref_copy().name)
assert holder.get_ref_copy().name == "initial"
holder.clean()

# RVP=move - a new object is created and the owner is python
holder = ValuesHolder()
value_ref_moved = holder.get_ref_move()
value_ref_moved.name = "update"
print("DEBUG: ", holder.get_ref_move().name)
assert holder.get_ref_reference().name == ""
holder.clean()

# RVP=automatic_reference - copy is used and a new object is created which owner is python
holder = ValuesHolder()
value_ref_auto_ref = holder.get_ref_automatic_reference()
value_ref_auto_ref.name = "update"
print("DEBUG: ", holder.get_ref_automatic_reference().name)
assert holder.get_ref_automatic_reference().name == "initial"
holder.clean()

# RVP=automatic - copy is used and a new object is created which owner is python
holder = ValuesHolder()
value_ref_automatic = holder.get_ref_automatic()
value_ref_automatic.name = "update"
# sometimes we have an assertion error here (the name is not "initial")
print("DEBUG: ", holder.get_ref_automatic().name)
# this assertion is to understand random failure is because cached object is returned or not
assert value_ref_automatic != holder.get_ref_automatic()
assert holder.get_ref_automatic().name == "initial"
holder.clean()

# RVP=take_ownership - a new object is not created and the owner is python
holder = ValuesHolder()
value_ref_take_ownership = holder.get_ref_take_ownership()
value_ref_take_ownership.name = "update"
print("DEBUG: ", holder.get_ref_take_ownership().name)
assert holder.get_ref_take_ownership().name == value_ref_take_ownership.name

# RVP=reference - owner is cpp after python object will be deleted, cpp object won't be deallocated
# but in this case as the above method returns the same instance with RVP=reference then this one returns
# the same python cached instance which means the owner is python
holder = ValuesHolder()
value_ref_ref = holder.get_ref_reference()
value_ref_ref.name = "update"
print("DEBUG: ", holder.get_ref_reference().name)
assert holder.get_ref_reference().name == value_ref_ref.name
# after gc clean of python object cpp object also will be deleted
# for the above four methods pybind returns the same instance as the first call is with RVP=reference
# then the owner is cpp


# return a shared pointer
# For shared pointers RVP is ignored and take ownership is always used.
# RVP not specified the default is used i.e. take_ownership for shared_pointers
holder = ValuesHolder()

value_ref_default = holder.get_shared_ref_default()
value_ref_default.name = "update"
print("DEBUG: ", holder.get_shared_ref_default().name)
assert holder.get_shared_ref_default().name == "update"
assert holder.get_shared_ref_default() == value_ref_default
holder.clean()

# RVP=copy - reference counter is incremented and the owner is python
holder = ValuesHolder()
shared_ref_copied = holder.get_shared_ref_copy()
print("DEBUG: ", shared_ref_copied.name)
assert shared_ref_copied.name == "initial"
shared_ref_copied.name = "update"
print("DEBUG: ", holder.get_shared_ref_copy().name)
assert holder.get_shared_ref_copy().name == shared_ref_copied.name
holder.clean()

# RVP=move - reference counter is incremented and the owner is python
holder = ValuesHolder()
shared_ref_moved = holder.get_shared_ref_move()
print("DEBUG: ", shared_ref_moved.name)
assert shared_ref_moved.name == "initial"
shared_ref_moved.name = "update"
print("DEBUG: ", holder.get_shared_ref_move().name)
assert holder.get_shared_ref_move().name == shared_ref_moved.name
holder.clean()

# RVP=reference - reference counter is incremented and the owner is python
holder = ValuesHolder()
shared_ref_reference = holder.get_shared_ref_reference()
print("DEBUG: ", shared_ref_reference.name)
assert shared_ref_reference.name == "initial"
shared_ref_reference.name = "update"
print("DEBUG: ", holder.get_shared_ref_reference().name)
assert holder.get_shared_ref_reference().name == shared_ref_reference.name
holder.clean()

# RVP=automatic - reference counter is incremented and the owner is python
holder = ValuesHolder()
shared_ref_automatic = holder.get_shared_ref_automatic()
print("DEBUG: ",shared_ref_automatic.name)
assert shared_ref_automatic.name == "initial"
shared_ref_automatic.name = "update"
print("DEBUG: ", holder.get_shared_ref_automatic().name)
assert holder.get_shared_ref_automatic().name == shared_ref_automatic.name
holder.clean()

# RVP=automatic_reference - reference counter is incremented and the owner is python
holder = ValuesHolder()
shared_ref_automatic_reference = holder.get_shared_ref_automatic_reference()
print("DEBUG: ", shared_ref_automatic_reference.name)
assert shared_ref_automatic_reference.name == "initial"
shared_ref_automatic_reference.name = "update"
print("DEBUG: ", holder.get_shared_ref_automatic_reference().name)
assert holder.get_shared_ref_automatic_reference().name == shared_ref_automatic_reference.name
holder.clean()

# RVP=take_ownership - reference counter is incremented and the owner is python
holder = ValuesHolder()
shared_ref_take_ownership = holder.get_shared_ref_take_ownership()
print("DEBUG: ", shared_ref_take_ownership.name)
assert shared_ref_take_ownership.name == "initial"
shared_ref_take_ownership.name = "update"
print("DEBUG: ", holder.get_shared_ref_take_ownership().name)
assert holder.get_shared_ref_take_ownership().name == shared_ref_take_ownership.name
holder.clean()

value_ptr = Value("from python")
value_ref = ValueSharedRef("from python")
holder_py = ValuesHolder(value_ptr, value_ref)

# Case when the object is created in python i.e the owner is python.
# In this case the cached object is always returned
assert holder_py.get_ptr_automatic() == holder_py.get_ptr_copy() == holder_py.get_ptr_reference() == value_ptr

# keep_alive
child1 = Child1("child1")
child2 = Child2("child2")
child3 = Child3("child3")
p2 = Parent1("parent2", child1, child2, child3)

# NOTE: here we have a reference cycle as the default return value policy
# for getters(reference_internal) is used alongside with keep_alive policy
assert (p2.child1.name == "child1")
assert (p2.child2.name == "child2")
assert (p2.child3.name == "child3")

p2 = Parent2("parent2")
child11 = Child1("child11")
child12 = Child1("child12")
p2.add_children1([child11, child12])
children1 = p2.children1
# NOTE: here we have a reference cycle as the default return value policy
# for getters(reference_internal) is used alongside with keep_alive policy
assert (children1[0].name == "child11")
assert (children1[1].name == "child12")

p2 = Parent2("parent2")
child21 = Child2("child21")
child22 = Child2("child22")
p2.add_children2([child21, child22])
children2 = p2.children2
assert (children2[0].name == "child21")
assert (children2[1].name == "child22")
