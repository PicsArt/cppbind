package com.examples.nested_types

import com.examples.nested_types.usage.*

fun use() {
// [nested-types-usage-start]
val value1 = Value(1)
val value2 = List.Item.Value(3)

val item1 = Item(value1)
val item2 = List.Item(value2)

val list = List()

list.push_back(item1)
assert(list.back.value.value == value1.value)

list.push_back(item2)
assert(list.back.value.value == value2.value)

list.pop_back()
assert(list.back.value.value == value1.value)

val listWrapper = ListWrapper()
listWrapper.push_back(item1)
assert(list.back.value.value == value1.value)

// [nested-types-usage-end]

val intListItemWrapper = IntListItemWrapper()
val intItem = TemplateListInt.Item(5)
intListItemWrapper.set(intItem)
val retIntItem = intListItemWrapper.get()
assert(retIntItem.value == 5)

}

class NestedTypesApp {

    companion object {
        @JvmStatic
        fun main(args: Array<String>) {
            use()
        }

    }
}
