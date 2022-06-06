/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 06/06/2022-08:28.
 * Please do not change it manually.
 */

package com.examples.cppbind.exception_helpers

import com.examples.cppbind.alias.*
import com.examples.cppbind.exceptionUtils.*
import com.examples.cppbind.exception_helpers.*
import com.examples.exceptions.FileError
import com.examples.exceptions.SystemError

open class StdException
internal constructor(obj: CppBindObject) : AutoCloseable, Exception() {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "std::exception"

        /**
         * An internal method to create a Kotlin object from a C++ object.
         * It is intended to be used by the generated code.
         */
        public fun cppbindConstructObject(id: Long, owner: Boolean = false): StdException {
            val idType = jGettypebyid(id)
            when (idType) {
                FileError.cppbindCxxTypeName -> return FileError(CppBindObject(id, owner))
                StdDomainError.cppbindCxxTypeName -> return StdDomainError(CppBindObject(id, owner))
                StdInvalidArgument.cppbindCxxTypeName -> return StdInvalidArgument(CppBindObject(id, owner))
                StdLengthError.cppbindCxxTypeName -> return StdLengthError(CppBindObject(id, owner))
                StdOutOfRange.cppbindCxxTypeName -> return StdOutOfRange(CppBindObject(id, owner))
                StdOverflowError.cppbindCxxTypeName -> return StdOverflowError(CppBindObject(id, owner))
                StdRangeError.cppbindCxxTypeName -> return StdRangeError(CppBindObject(id, owner))
                StdUnderflowError.cppbindCxxTypeName -> return StdUnderflowError(CppBindObject(id, owner))
                SystemError.cppbindCxxTypeName -> return SystemError(CppBindObject(id, owner))
                StdBadAlloc.cppbindCxxTypeName -> return StdBadAlloc(CppBindObject(id, owner))
                StdBadCast.cppbindCxxTypeName -> return StdBadCast(CppBindObject(id, owner))
                StdBadTypeId.cppbindCxxTypeName -> return StdBadTypeId(CppBindObject(id, owner))
                StdLogicError.cppbindCxxTypeName -> return StdLogicError(CppBindObject(id, owner))
                StdRuntimeError.cppbindCxxTypeName -> return StdRuntimeError(CppBindObject(id, owner))
                else -> return StdException(CppBindObject(id, owner))
            }
        }
    }
    
    protected var cppbindObj = obj
    private var refs: MutableList<Any> = mutableListOf()

    /**
     * An internal method to bind the lifetimes of the current and another object.
     * It is intended to be used by the generated code.
     */
    fun keepCppBindReference(ref: Any) {
        refs.add(ref)
    }
    /**
     * An internal getter to get the id of an object.
     * It is intended to be used by the generated code.
     */
    
    open val id: Long
        get() {
            if (cppbindObj.id == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return cppbindObj.id
        }

    /**
     * An internal property returning underlying C++ object id.
     * It is intended to be used by the generated code.
     */
    internal val cxxId: Long by lazy {
        jGetcxxid(cppbindObj.id)
    }

    /**
     * An internal property returning underlying C++ type name.
     * It is intended to be used by the generated code.
     */
    internal val cxxTypeName: String by lazy {
        jGettypebyid(cppbindObj.id)
    }
    
    open fun what(): String {
        val result = jWhat(id)
        val jdktokotlinresult = result!!
        return jdktokotlinresult
    }

    /**
     * CPPBind generated hashCode method returning the hash of underlying C++ object id. .
     */
    override fun hashCode(): Int {
        return cxxId.hashCode()
    }

    /**
     * CPPBind generated equals method comparing the underlying C++ object ids.
     */
    override fun equals(other: Any?): Boolean {
        other as StdException
        return cxxId == other.cxxId
    }

    /**
     * CPPBind generated toString method returning underlying C++ object type and id.
     */
    override fun toString(): String {
        return "<0x%x: %s>".format(cxxId, cxxTypeName)
    }

    override fun close() {
        if (cppbindObj.owner && cppbindObj.id != 0L) {
            jFinalize(cppbindObj.id)
            cppbindObj.id = 0L
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
    private external fun jGetcxxid(id: Long): Long
}

open class StdLogicError
internal constructor(obj: CppBindObject) : StdException(obj) {
    companion object {
        
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "std::logic_error"

        /**
         * An internal method to create a Kotlin object from a C++ object.
         * It is intended to be used by the generated code.
         */
        public fun cppbindConstructObject(id: Long, owner: Boolean = false): StdLogicError {
            val idType = jGettypebyid(id)
            when (idType) {
                StdDomainError.cppbindCxxTypeName -> return StdDomainError(CppBindObject(id, owner))
                StdInvalidArgument.cppbindCxxTypeName -> return StdInvalidArgument(CppBindObject(id, owner))
                StdLengthError.cppbindCxxTypeName -> return StdLengthError(CppBindObject(id, owner))
                StdOutOfRange.cppbindCxxTypeName -> return StdOutOfRange(CppBindObject(id, owner))
                else -> return StdLogicError(CppBindObject(id, owner))
            }
        }
    }
    
}

open class StdRuntimeError
internal constructor(obj: CppBindObject) : StdException(obj) {
    companion object {
        
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "std::runtime_error"

        /**
         * An internal method to create a Kotlin object from a C++ object.
         * It is intended to be used by the generated code.
         */
        public fun cppbindConstructObject(id: Long, owner: Boolean = false): StdRuntimeError {
            val idType = jGettypebyid(id)
            when (idType) {
                StdOverflowError.cppbindCxxTypeName -> return StdOverflowError(CppBindObject(id, owner))
                StdRangeError.cppbindCxxTypeName -> return StdRangeError(CppBindObject(id, owner))
                StdUnderflowError.cppbindCxxTypeName -> return StdUnderflowError(CppBindObject(id, owner))
                else -> return StdRuntimeError(CppBindObject(id, owner))
            }
        }
    }
    
}

open class StdDomainError
internal constructor(obj: CppBindObject) : StdLogicError(obj) {
    companion object {
        
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "std::domain_error"
    }
    
}

open class StdInvalidArgument
internal constructor(obj: CppBindObject) : StdLogicError(obj) {
    companion object {
        
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "std::invalid_argument"
    }
    
}

open class StdLengthError
internal constructor(obj: CppBindObject) : StdLogicError(obj) {
    companion object {
        
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "std::length_error"
    }
    
}

open class StdOutOfRange
internal constructor(obj: CppBindObject) : StdLogicError(obj) {
    companion object {
        
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "std::out_of_range"
    }
    
}

open class StdRangeError
internal constructor(obj: CppBindObject) : StdRuntimeError(obj) {
    companion object {
        
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "std::range_error"
    }
    
}

open class StdOverflowError
internal constructor(obj: CppBindObject) : StdRuntimeError(obj) {
    companion object {
        
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "std::overflow_error"
    }
    
}

open class StdUnderflowError
internal constructor(obj: CppBindObject) : StdRuntimeError(obj) {
    companion object {
        
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "std::underflow_error"
    }
    
}

open class StdBadAlloc
internal constructor(obj: CppBindObject) : StdException(obj) {
    companion object {
        
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "std::bad_alloc"
    }
    
}

open class StdBadCast
internal constructor(obj: CppBindObject) : StdException(obj) {
    companion object {
        
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "std::bad_cast"
    }
    
}

open class StdBadTypeId
internal constructor(obj: CppBindObject) : StdException(obj) {
    companion object {
        
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "std::bad_typeid"
    }
    
}

private external fun jGettypebyid(id: Long): String
