import XCTest
import Wrapper

func runRVPoliciesExamples() {
    // [rv-policies-usage]

    /// return raw pointer

    // RVP not specified the default is used i.e. take_ownership for pointers
    do {
        let holder = ValuesHolder()

        let _ = holder.getPtrDefault()
        // if we call here holder.getPtrDefault() again then there will ba an
        // attempt to deallocate the original cpp object for the second time
    }

    do {
        let holder = ValuesHolder()
        defer { holder.clean() }
        // RVP=copy - a new object is created and the owner is swift
        let valuePtrCopied = holder.getPtrCopy()
        valuePtrCopied.name = "update"
        assert(holder.getPtrCopy().name == "initial")

        // RVP=move - a new object is created and the owner is swift
        let valuePtrMoved = holder.getPtrMove()
        valuePtrMoved.name = "update"
        assert(holder.getPtrMove().name == "initial")
    }

    // RVP=reference - owner is cpp without the clean pointer is not deleted
    do {
        let holder = ValuesHolder()
        defer { holder.clean() }
        let valuePtrRef = holder.getPtrReference()
        valuePtrRef.name = "update"
        assert(holder.getPtrReference().name == valuePtrRef.name)
    }

    // RVP=automatic_reference - owner is cpp without the clean pointer is not deleted
    do {
        let holder = ValuesHolder()
        defer { holder.clean() }
        let valuePtrAutoRef = holder.getPtrAutomaticReference()
        valuePtrAutoRef.name = "update"
        assert(holder.getPtrAutomaticReference().name == valuePtrAutoRef.name)
    }


    // RVP in (automatic, take_ownership) - are handled similarly for pointers i.e new object is not created and the owner is swift
    // after exiting the block with swift object deallocation cpp object also will be deallocated
    do {
        let holder = ValuesHolder()
        let valuePtrAutomatic = holder.getPtrAutomatic()
        valuePtrAutomatic.name = "update"
        // if we call here holder.getPtrAutomatic() or holder.getPtrTakeOwnership() again then there will ba an
        // attempt to deallocate the same object for the second time
    }


    /// return by value
    /// In case return by value given RVP is ignored and copy is always used.

    // RVP not specified the default is used i.e. copy for values
    do {
        let holder = ValuesHolder()
        defer { holder.clean() }
        let value = holder.getValueDefault()
        assert(value.name == "initial")
        value.name = "update"
        assert(holder.getValueDefault().name == "initial")
    }

    do {

        let holder = ValuesHolder()
        defer { holder.clean() }
        // RVP=copy - a new object is created and the owner is swift
        let valueCopied = holder.getValueCopy()
        assert(valueCopied.name == "initial")
        valueCopied.name = "update"
        // original instance is not updated
        assert(holder.getValueCopy().name == "initial")

        // RVP=move - a new object is created and the owner is swift
        let valueMoved = holder.getValueMove()
        valueMoved.name = "update"
        // original instance is not updated
        assert(holder.getValueMove().name == "initial")
    }

    // RVP=reference - and it's ignored as object is returned by value copy is used instead
    do {
        let holder = ValuesHolder()
        defer { holder.clean() }
        let valueRef = holder.getValueReference()
        valueRef.name = "update"
        // original instance is not updated
        assert(holder.getValueReference().name == "initial")
    }

    // RVP=automatic - and it's ignored as object is returned by value copy is used instead
    do {
        let holder = ValuesHolder()
        defer { holder.clean() }
        holder.getValueAutomatic().name = "update"
        // original instance is not updated
        assert(holder.getValueAutomatic().name == "initial")
    }

    // RVP=automatic_reference - and it's ignored as object is returned by value copy is used instead
    do {
        let holder = ValuesHolder()
        defer { holder.clean() }
        holder.getValueAutomaticReference().name = "update"
        // original instance is not updated
        assert(holder.getValueAutomaticReference().name == "initial")
    }

    // RVP=take_ownership - and it's ignored as object is returned by value copy is used instead
    do {
        let holder = ValuesHolder()
        defer { holder.clean() }
        holder.getValueTakeOwnership().name = "update"
        // original instance is not updated
        assert(holder.getValueTakeOwnership().name == "initial")
    }


    /// return by reference

    // RVP not specified the default is used i.e. copy for methods returning a reference
    do {
        let holder = ValuesHolder()
        defer { holder.clean() }
        let value = holder.getRefDefault()
        assert(value.name == "initial")
        value.name = "update"
        assert(holder.getRefDefault().name == "initial")
    }

    do {
        let holder = ValuesHolder()
        defer { holder.clean() }
        // RVP=copy - a new object is created and the owner is swift
        let valueRefCopied = holder.getRefCopy()
        valueRefCopied.name = "update"
        assert(holder.getRefCopy().name == "initial")

        // RVP=move - a new object is created and the owner is swift
        let valueRefMoved = holder.getRefMove()
        valueRefMoved.name = "update"
        assert(holder.getRefMove().name == "initial")
    }

    // RVP=reference - owner is cpp without calling clean after exiting the block swift object will be deleted but cpp object won't be deallocated
    do {
        let holder = ValuesHolder()
        defer { holder.clean() }
        let valueRefRef = holder.getRefReference()
        valueRefRef.name = "update"
        assert(holder.getRefReference().name == valueRefRef.name)
    }

    // RVP=automatic_reference - copy is used and a new object is created which owner is swift
    do {
        let holder = ValuesHolder()
        defer { holder.clean() }
        let valueRefAutoRef = holder.getRefAutomaticReference()
        valueRefAutoRef.name = "update"
        assert(holder.getRefAutomaticReference().name == "initial")
    }


    // RVP=automatic - copy is used and a new object is created which owner is swift
    do {
        let holder = ValuesHolder()
        defer { holder.clean() }
        let valueRefAutomatic = holder.getRefAutomatic()
        valueRefAutomatic.name = "update"
        assert(holder.getRefAutomatic().name == "initial")
    }

    // RVP=take_ownership - new object is not created and the owner is swift
    // after exiting the block with swift object deallocation cpp object also will be deallocated
    do {
        let holder = ValuesHolder()
        let valueRefTakeOwnership = holder.getRefTakeOwnership()
        valueRefTakeOwnership.name = "update"
        // if we call here holder.getRefTakeOwnership() again then there will ba an
        // attempt to deallocate the original cpp object for the second time
    }


    /// return a shared pointer
    /// For shared pointers RVP is ignored and take ownership is always used.

    // RVP not specified the default is used i.e. take_ownership is used
    do {
        let holder = ValuesHolder()
        defer { holder.clean() }
        let value = holder.getSharedRefDefault()
        assert(value.name == "initial")
        value.name = "update"
        assert(holder.getSharedRefDefault().name == "update")
    }

    // RVP=copy - reference counter is incremented and the owner is swift
    do {
        let holder = ValuesHolder()
        defer { holder.clean() }
        let sharedRefCopied = holder.getSharedRefCopy()
        assert(sharedRefCopied.name == "initial")
        sharedRefCopied.name = "update"
        assert(holder.getSharedRefCopy().name == sharedRefCopied.name)
    }

    // RVP=move - reference counter is incremented and the owner is swift
    do {
        let holder = ValuesHolder()
        defer { holder.clean() }
        let sharedRefMoved = holder.getSharedRefMove()
        assert(sharedRefMoved.name == "initial")
        sharedRefMoved.name = "update"
        assert(holder.getSharedRefCopy().name == sharedRefMoved.name)
    }

    // RVP=reference - reference counter is incremented and the owner is swift
    do {
        let holder = ValuesHolder()
        defer { holder.clean() }
        let sharedRefReference = holder.getSharedRefReference()
        assert(sharedRefReference.name == "initial")
        sharedRefReference.name = "update"
        assert(holder.getSharedRefReference().name == sharedRefReference.name)
    }


    // RVP=automatic - reference counter is incremented and the owner is swift
    do {
        let holder = ValuesHolder()
        defer { holder.clean() }
        let sharedRefAutomatic = holder.getSharedRefAutomatic()
        assert(sharedRefAutomatic.name == "initial")
        sharedRefAutomatic.name = "update"
        assert(holder.getSharedRefAutomatic().name == sharedRefAutomatic.name)
    }

    // RVP=automatic_reference - reference counter is incremented and the owner is swift
    do {
        let holder = ValuesHolder()
        defer { holder.clean() }
        let sharedRefAutomaticReference = holder.getSharedRefAutomaticReference()
        assert(sharedRefAutomaticReference.name == "initial")
        sharedRefAutomaticReference.name = "update"
        assert(holder.getSharedRefAutomaticReference().name == sharedRefAutomaticReference.name)
    }

    // RVP=take_ownership - reference counter is incremented and the owner is swift
    do {
        let holder = ValuesHolder()
        defer { holder.clean() }
        let sharedRefTakeOwnership = holder.getSharedRefTakeOwnership()
        assert(sharedRefTakeOwnership.name == "initial")
        sharedRefTakeOwnership.name = "update"
        assert(holder.getSharedRefTakeOwnership().name == sharedRefTakeOwnership.name)
    }

    /// reference internal
    // the default policy for getters and properties
    do {
        var value: SwValue?
        do {
            let holder = AnotherValueHolder()
            value = holder.value
            assert(holder.value.cself.ptr == value!.cself.ptr)
        }
        // value is not deleted as it keeps reference on it's parent i.e. on holder
        assert(value!.name == "initial")
    }

    // rvp = reference
    do {
        var value: SwValue?
        do {
            let holder = AnotherValueHolder()
            value = holder.valueReference
            assert(holder.valueReference.cself.ptr == value!.cself.ptr)
        }
        // value is deleted holder keeps an invalid pointer
    }

    // the default policy for getters and properties for shared pointers it's ignored and take_ownership is always used
    do {
        var value: ValueSharedRef?
        do {
            let holder = AnotherValueHolder()
            value = holder.sharedValue
            assert(holder.sharedValue.cself.ptr != value!.cself.ptr)
        }
        // value is not deleted as it keeps reference on it's parent i.e. on holder
        assert(value!.name == "initial")
    }

    // rvp = reference but still take_ownership is used
    do {
        var value: ValueSharedRef?
        do {
            let holder = AnotherValueHolder()
            value = holder.sharedValueReference
            assert(holder.sharedValueReference.cself.ptr != value!.cself.ptr)
        }
        // for shared pointers rvp is ignored reference count is incremented and ownership is given to swift
        assert(value!.name == "initial")
    }


    // [rv-policies-usage]

}

#if os(Linux)
runRVPoliciesExamples()
#elseif os(OSX)
class OverloadsTests: XCTestCase {
    func testRun() throws {
        runRVPoliciesExamples()
    }
}
#endif
