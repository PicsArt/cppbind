package com.examples.rv_policies


fun use() {
// [rv-policies-usage]

    /// return raw pointer
    // RVP not specified the default is used i.e. take_ownership for pointers
    run {
        val holder = ValuesHolder()

        holder.getPtrDefault().use {
            it.name = "update"
        }
        // if we call here holder.getPtrDefault() again then there will ba an
        // attempt to deallocate the original cpp object for the second time
        // holder.getPtrDefault().use {}
    }

    run {
        val holder = ValuesHolder()

        // RVP=copy - a new object is created and the owner is kotlin
        val valuePtrCopied = holder.getPtrCopy()
        valuePtrCopied.name = "update"
        assert(holder.getPtrCopy().name == "initial")

        // RVP=move - a new object is created and the owner is kotlin
        val valuePtrMoved = holder.getPtrMove()
        valuePtrMoved.name = "update"
        assert(holder.getPtrMove().name == "initial")
        holder.clean()
    }

    // RVP=reference - owner is cpp without calling clean next after use block pointer is not deleted
    run {
        val holder = ValuesHolder()
        val valuePtrRef = holder.getPtrReference()
        valuePtrRef.use {
            valuePtrRef.name = "update"
            holder.getPtrReference()
                .use { res -> assert(res.name == valuePtrRef.name) }
        }
        holder.clean()
    }

    // RVP=automatic_reference - owner is cpp without calling clean next after use block pointer is not deleted
    run {
        ValuesHolder().use { holder ->
            holder.getPtrAutomaticReference().use { valuePtrAutoRef ->
                valuePtrAutoRef.name = "update"
                holder.getPtrAutomaticReference().use { res ->
                    assert(res.name == valuePtrAutoRef.name)
                }
            }
            holder.clean()
        }
    }


    // RVP in (automatic, take_ownership) - are handled similarly for pointers i.e new object is not created and the owner is kotlin
    // after exiting the block with kotlin object deallocation cpp object also will be deallocated
    run {
        val holder = ValuesHolder()
        holder.getPtrAutomatic().use { valuePtrAutomatic ->
            valuePtrAutomatic.name = "update"
        }
        // if we call here holder.getPtrAutomatic() or holder.getPtrTakeOwnership() again then there will ba an
        // attempt to deallocate the same object for the second time
        // holder.getPtrAutomatic().use { assert(it.name == "update") }
    }


    /// return by value
    /// In case return by value given RVP is ignored and copy is always used.


    // RVP not specified the default is used i.e. copy for values
    run {
        val holder = ValuesHolder()

        val value = holder.getValueDefault()
        assert(value.name == "initial")
        value.name = "update"
        assert(holder.getValueDefault().name == "initial")
        holder.clean()
    }
    run {

        val holder = ValuesHolder()

        // RVP=copy - a new object is created and the owner is kotlin
        val valueCopied = holder.getValueCopy()
        assert(valueCopied.name == "initial")
        valueCopied.name = "update"
        // original instance is not updated
        assert(holder.getValueCopy().name == "initial")

        // RVP=move - a new object is created and the owner is kotlin
        val valueMoved = holder.getValueMove()
        valueMoved.name = "update"
        // original instance is not updated
        assert(holder.getValueMove().name == "initial")
        holder.clean()
    }

    // RVP=reference - and it's ignored as object is returned by value copy is used instead
    run {
        val holder = ValuesHolder()
        val valueRef = holder.getValueReference()
        valueRef.name = "update"
        // original instance is not updated
        assert(holder.getValueReference().name == "initial")
        holder.clean()
    }

    // RVP=automatic - and it's ignored as object is returned by value copy is used instead
    run {
        val holder = ValuesHolder()
        holder.getValueAutomatic().name = "update"
        // original instance is not updated
        assert(holder.getValueAutomatic().name == "initial")
        holder.clean()
    }

    // RVP=automatic_reference - and it's ignored as object is returned by value copy is used instead
    run {
        val holder = ValuesHolder()
        holder.getValueAutomaticReference().name = "update"
        // original instance is not updated
        assert(holder.getValueAutomaticReference().name == "initial")
        holder.clean()
    }

    // RVP=take_ownership - and it's ignored as object is returned by value copy is used instead
    run {
        val holder = ValuesHolder()
        holder.getValueTakeOwnership().name = "update"
        // original instance is not updated
        assert(holder.getValueTakeOwnership().name == "initial")
        holder.clean()
    }


    /// return by reference
    
    // RVP not specified the default is used i.e. copy for methods returning a reference
    run {
        val holder = ValuesHolder()

        val value = holder.getRefDefault()
        assert(value.name == "initial")
        value.name = "update"
        assert(holder.getRefDefault().name == "initial")
        holder.clean()
    }

    run {
        val holder = ValuesHolder()

        // RVP=copy - a new object is created and the owner is kotlin
        val valueRefCopied = holder.getRefCopy()
        valueRefCopied.name = "update"
        assert(holder.getRefCopy().name == "initial")

        // RVP=move - a new object is created and the owner is kotlin
        val valueRefMoved = holder.getRefMove()
        valueRefMoved.name = "update"
        assert(holder.getRefMove().name == "initial")
        holder.clean()
    }

    // RVP=reference - owner is cpp without calling clean after use block kotlin object will be deleted but cpp object won't be deallocated
    run {
        val holder = ValuesHolder()
        val valueRefRef = holder.getRefReference()
        valueRefRef.use {
            valueRefRef.name = "update"
            holder.getRefReference().use { res ->
                assert(res.name == valueRefRef.name)
            }
        }
        holder.clean()
    }

    // RVP=automatic_reference - copy is used and a new object is created which owner is kotlin
    run {
        val holder = ValuesHolder()
        val valueRefAutoRef = holder.getRefAutomaticReference()
        valueRefAutoRef.name = "update"
        assert(holder.getRefAutomaticReference().name == "initial")
        holder.clean()
    }


    // RVP=automatic - copy is used and a new object is created which owner is kotlin
    run {
        val holder = ValuesHolder()
        val valueRefAutomatic = holder.getRefAutomatic()
        valueRefAutomatic.name = "update"
        assert(holder.getRefAutomatic().name == "initial")
        holder.clean()
    }

    // RVP=take_ownership - new object is not created and the owner is kotlin
    // after exiting the block with kotlin object deallocation cpp object also will be deallocated
    run {
        val holder = ValuesHolder()
        holder.getRefTakeOwnership()
            .use { it.name = "update" }
        // if we call here holder.getRefTakeOwnership() again then there will ba an
        // attempt to deallocate the original cpp object for the second time
        // holder.getRefTakeOwnership().use { assert(it.name == "update") }
    }


    /// return a shared pointer
    /// For shared pointers given RVP is ignored and take ownership is always used.

    // RVP not specified the default is used i.e. take_ownership is used
    run {
        val holder = ValuesHolder()

        val value = holder.getSharedRefDefault()
        assert(value.name == "initial")
        value.name = "update"
        assert(holder.getSharedRefDefault().name == "update")
        holder.clean()
    }

    // RVP=copy - reference counter is incremented and the owner is kotlin
    run {
        val holder = ValuesHolder()
        val sharedRefCopied = holder.getSharedRefCopy()
        assert(sharedRefCopied.name == "initial")
        sharedRefCopied.name = "update"
        assert(holder.getSharedRefCopy().name == sharedRefCopied.name)
        holder.clean()
    }

    // RVP=move - reference counter is incremented and the owner is kotlin
    run {
        val holder = ValuesHolder()
        val sharedRefMoved = holder.getSharedRefMove()
        assert(sharedRefMoved.name == "initial")
        sharedRefMoved.name = "update"
        assert(holder.getSharedRefCopy().name == sharedRefMoved.name)
        holder.clean()
    }

    // RVP=reference - reference counter is incremented and the owner is kotlin
    run {
        val holder = ValuesHolder()
        val sharedRefReference = holder.getSharedRefReference()
        assert(sharedRefReference.name == "initial")
        sharedRefReference.name = "update"
        assert(holder.getSharedRefReference().name == sharedRefReference.name)
        holder.clean()
    }


    // RVP=automatic - reference counter is incremented and the owner is kotlin
    run {
        val holder = ValuesHolder()
        val sharedRefAutomatic = holder.getSharedRefAutomatic()
        assert(sharedRefAutomatic.name == "initial")
        sharedRefAutomatic.name = "update"
        assert(holder.getSharedRefAutomatic().name == sharedRefAutomatic.name)
        holder.clean()
    }

    // RVP=automatic_reference - reference counter is incremented and the owner is kotlin
    run {
        val holder = ValuesHolder()
        val sharedRefAutomaticReference = holder.getSharedRefAutomaticReference()
        assert(sharedRefAutomaticReference.name == "initial")
        sharedRefAutomaticReference.name = "update"
        assert(holder.getSharedRefAutomaticReference().name == sharedRefAutomaticReference.name)
        holder.clean()
    }

    // RVP=take_ownership - reference counter is incremented and the owner is kotlin
    run {
        val holder = ValuesHolder()
        val sharedRefTakeOwnership = holder.getSharedRefTakeOwnership()
        sharedRefTakeOwnership.use {
            assert(sharedRefTakeOwnership.name == "initial")
            sharedRefTakeOwnership.name = "update"
            holder.getSharedRefTakeOwnership()
                .use { res -> assert(res.name == sharedRefTakeOwnership.name) }
        }
        holder.clean()
    }

    /// reference internal
    // for kotlin reference_internal cannot be properly tested as we can't force a gc
    run {
        val holder = AnotherValueHolder()
        // value keeps reference on it's parent i.e. on holder
        val value = holder.value
        assert(value.name == "initial")
    }

    // for shared pointers rvp is ignored and take_ownership is always used
    run {
        val holder = AnotherValueHolder()
        val value = holder.sharedValue
        holder.close()
        // for shared pointers even if holder gets deleted still value will hold a valid pointer
        assert(value.name == "initial")
    }

    /// keep alive policy
    run {
        var p2: Parent1
        run {
            val child1 = Child1("child1")
            val child2 = Child2("child2")
            val child3 = Child3Impl("child3")
            p2 = Parent1("parent2", child1, child2, child3)
        }
        // NOTE: here we will have a reference cycle after adding object caching and
        // with default return value policy for getters(reference_internal) for non shared_ref types
        assert(p2.child1.name == "child1")
        assert(p2.child2.name == "child2")
        assert(p2.child3.name == "child3")
    }

    // an example using container types
    run {
        // raw pointers
        val p2 = Parent2("parent2")
        run {
            val child11 = Child1("child11")
            val child12 = Child1("child12")
            p2.addChildren1(listOf(child11, child12))
        }
        val children1 = p2.children1
        // NOTE: here we will have a reference cycle after adding object caching and
        // with default return value policy for getters(reference_internal) for non shared_ref types
        assert(children1[0].name == "child11")
        assert(children1[1].name == "child12")
    }

    run {
        // shared pointers no keep alive policy required
        val p2 = Parent2("parent2")
        run {
            val child21 = Child2("child21")
            val child22 = Child2("child22")
            p2.addChildren2(listOf(child21, child22))
        }
        val children2 = p2.children2
        assert(children2[0].name == "child21")
        assert(children2[1].name == "child22")
    }

// [rv-policies-usage]

}

class RVPApp {

    companion object {
        @JvmStatic
        fun main(args: Array<String>) {
            use()
       }

    }
}
