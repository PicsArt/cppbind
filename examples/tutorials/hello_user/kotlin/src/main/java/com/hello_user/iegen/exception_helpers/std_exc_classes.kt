/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 05/04/2022-08:31.
 * Please do not change it manually.
 */

package com.hello_user.iegen.exception_helpers

import com.hello_user.iegen.alias.*
import com.hello_user.iegen.exceptionUtils.*
import com.hello_user.iegen.exception_helpers.*

open class StdException
internal constructor(obj: IEGenObject) : AutoCloseable, Exception() {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        const val iegenCxxTypeName: String = "std::exception"

        public fun iegenDowncast(id: Long, owner: Boolean = false): StdException {
            val idType = jGettypebyid(id)
            when (idType) {
                StdDomainError.iegenCxxTypeName -> return StdDomainError(IEGenObject(id, owner))
                StdInvalidArgument.iegenCxxTypeName -> return StdInvalidArgument(IEGenObject(id, owner))
                StdLengthError.iegenCxxTypeName -> return StdLengthError(IEGenObject(id, owner))
                StdOutOfRange.iegenCxxTypeName -> return StdOutOfRange(IEGenObject(id, owner))
                StdOverflowError.iegenCxxTypeName -> return StdOverflowError(IEGenObject(id, owner))
                StdRangeError.iegenCxxTypeName -> return StdRangeError(IEGenObject(id, owner))
                StdUnderflowError.iegenCxxTypeName -> return StdUnderflowError(IEGenObject(id, owner))
                StdBadAlloc.iegenCxxTypeName -> return StdBadAlloc(IEGenObject(id, owner))
                StdBadCast.iegenCxxTypeName -> return StdBadCast(IEGenObject(id, owner))
                StdBadTypeId.iegenCxxTypeName -> return StdBadTypeId(IEGenObject(id, owner))
                StdLogicError.iegenCxxTypeName -> return StdLogicError(IEGenObject(id, owner))
                StdRuntimeError.iegenCxxTypeName -> return StdRuntimeError(IEGenObject(id, owner))
                else -> return StdException(IEGenObject(id, owner))
            }
        }
    }
    
    protected var iegObj = obj
    private var refs: MutableList<Any> = mutableListOf()

    fun keepIEGenReference(ref: Any) {
        refs.add(ref)
    }
    
    open val id: Long
        get() {
            if (iegObj.id == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return iegObj.id
        }
    
    open fun what(): String {
        val result = jWhat(id)
        val jdktokotlinresult = result!!
        return jdktokotlinresult
    }

    override fun close() {
        if (iegObj.owner && iegObj.id != 0L) {
            jFinalize(iegObj.id)
            iegObj.id = 0L
        }
    }

    /**
     * Finalize and deletes the object
     */
    protected fun finalize() {
        close()
    }

    ///// External wrapper functions ////////////
    private external fun jWhat(id: Long): String?
    private external fun jFinalize(id: Long): Unit
}

open class StdLogicError
internal constructor(obj: IEGenObject) : StdException(obj) {
    companion object {
        
        const val iegenCxxTypeName: String = "std::logic_error"

        public fun iegenDowncast(id: Long, owner: Boolean = false): StdLogicError {
            val idType = jGettypebyid(id)
            when (idType) {
                StdDomainError.iegenCxxTypeName -> return StdDomainError(IEGenObject(id, owner))
                StdInvalidArgument.iegenCxxTypeName -> return StdInvalidArgument(IEGenObject(id, owner))
                StdLengthError.iegenCxxTypeName -> return StdLengthError(IEGenObject(id, owner))
                StdOutOfRange.iegenCxxTypeName -> return StdOutOfRange(IEGenObject(id, owner))
                else -> return StdLogicError(IEGenObject(id, owner))
            }
        }
    }
    
}

open class StdRuntimeError
internal constructor(obj: IEGenObject) : StdException(obj) {
    companion object {
        
        const val iegenCxxTypeName: String = "std::runtime_error"

        public fun iegenDowncast(id: Long, owner: Boolean = false): StdRuntimeError {
            val idType = jGettypebyid(id)
            when (idType) {
                StdOverflowError.iegenCxxTypeName -> return StdOverflowError(IEGenObject(id, owner))
                StdRangeError.iegenCxxTypeName -> return StdRangeError(IEGenObject(id, owner))
                StdUnderflowError.iegenCxxTypeName -> return StdUnderflowError(IEGenObject(id, owner))
                else -> return StdRuntimeError(IEGenObject(id, owner))
            }
        }
    }
    
}

open class StdDomainError
internal constructor(obj: IEGenObject) : StdLogicError(obj) {
    companion object {
        
        const val iegenCxxTypeName: String = "std::domain_error"
    }
    
}

open class StdInvalidArgument
internal constructor(obj: IEGenObject) : StdLogicError(obj) {
    companion object {
        
        const val iegenCxxTypeName: String = "std::invalid_argument"
    }
    
}

open class StdLengthError
internal constructor(obj: IEGenObject) : StdLogicError(obj) {
    companion object {
        
        const val iegenCxxTypeName: String = "std::length_error"
    }
    
}

open class StdOutOfRange
internal constructor(obj: IEGenObject) : StdLogicError(obj) {
    companion object {
        
        const val iegenCxxTypeName: String = "std::out_of_range"
    }
    
}

open class StdRangeError
internal constructor(obj: IEGenObject) : StdRuntimeError(obj) {
    companion object {
        
        const val iegenCxxTypeName: String = "std::range_error"
    }
    
}

open class StdOverflowError
internal constructor(obj: IEGenObject) : StdRuntimeError(obj) {
    companion object {
        
        const val iegenCxxTypeName: String = "std::overflow_error"
    }
    
}

open class StdUnderflowError
internal constructor(obj: IEGenObject) : StdRuntimeError(obj) {
    companion object {
        
        const val iegenCxxTypeName: String = "std::underflow_error"
    }
    
}

open class StdBadAlloc
internal constructor(obj: IEGenObject) : StdException(obj) {
    companion object {
        
        const val iegenCxxTypeName: String = "std::bad_alloc"
    }
    
}

open class StdBadCast
internal constructor(obj: IEGenObject) : StdException(obj) {
    companion object {
        
        const val iegenCxxTypeName: String = "std::bad_cast"
    }
    
}

open class StdBadTypeId
internal constructor(obj: IEGenObject) : StdException(obj) {
    companion object {
        
        const val iegenCxxTypeName: String = "std::bad_typeid"
    }
    
}

private external fun jGettypebyid(id: Long): String
