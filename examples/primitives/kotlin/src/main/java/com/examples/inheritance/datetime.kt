/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 06/06/2022-15:10.
 * Please do not change it manually.
 */

package com.examples.inheritance

import com.examples.cppbind.alias.*
import com.examples.cppbind.exceptionUtils.*
import com.examples.cppbind.exception_helpers.*


/**
 * datetime.hpp is parsed before time.hpp and it contains DateTime class which is inherited from Time(declared in time.hpp).
 * We generate bindings for these two classes in the same datetime file to validate their order.
 */
interface ITime : IBase {
    
    val time: String
        get() {
            val result = ITimeHelper.jTime(cppbindObjId)
            
            return result
        }
    
    open override fun value(): String {
        val result = ITimeHelper.jValue(cppbindObjId)
        
        return result
    }

    companion object {
        /**
         * An internal method to create a Kotlin object from a C++ object.
         * It is intended to be used by the generated code.
         */
        public fun cppbindConstructObject(id: Long, owner: Boolean = false): ITime {
            val idType = jGettypebyid(id)
            when (idType) {
                DateTime.cppbindCxxTypeName -> return DateTime(CppBindObject(id, owner))
                else -> return TimeImpl(CppBindObject(id, owner))
            }
        }
    }
}


class ITimeHelper {
    companion object {
        @JvmStatic
        external fun jValue(id: Long): String
        @JvmStatic
        external fun jTime(id: Long): String
    }
}


open class TimeImpl
internal constructor(obj : CppBindObject) : ITime {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(h: Int, m: Int, s: Int): Long {
            val id = jConstructor(h, m, s)
            return id
        }

        @JvmStatic
        private external fun jConstructor(h: Int, m: Int, s: Int, vararg extraObjs: Any?): Long
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::Time"
    }

    protected var cppbindObj = obj
    private var refs: MutableList<Any> = mutableListOf()

    override fun keepCppBindReference(ref: Any) {
        refs.add(ref)
    }

    override val cppbindObjId: Long
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
    
    constructor(h: Int, m: Int, s: Int): this(CppBindObject(construct_helper(h, m, s), true)) {
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
    
    /**
     * CppBind generated hashCode method returning the hash of underlying C++ object id.
     */
    override fun hashCode(): Int {
        return cxxId.hashCode()
    }

    /**
     * CppBind generated equals method comparing the underlying C++ object ids.
     */
    override fun equals(other: Any?): Boolean {
        other as TimeImpl
        return cxxId == other.cxxId
    }

    /**
     * CppBind generated toString method returning underlying C++ object type and id.
     */
    override fun toString(): String {
        return "<0x%x: %s>".format(cxxId, cxxTypeName)
    }

    ///// External wrapper functions ////////////
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

/**
 * datetime.hpp is parsed before time.hpp and it contains DateTime class which is inherited from Time(declared in time.hpp).
 * We generate bindings for these two classes in the same datetime file to validate their order.
 */
open class DateTime
internal constructor(obj: CppBindObject) : ITime, Date(obj) {
    companion object {
        
        protected fun construct_helper(d: Int, mo: Int, y: Int, h: Int, mi: Int, s: Int): Long {
            val id = jConstructor(d, mo, y, h, mi, s)
            return id
        }

        @JvmStatic
        private external fun jConstructor(d: Int, mo: Int, y: Int, h: Int, mi: Int, s: Int, vararg extraObjs: Any?): Long
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::DateTime"
    }
    
    /**
     * An internal getter to get the id of an object.
     * It is intended to be used by the generated code.
     */
    override val cppbindObjId: Long
        get() {
            if (cppbindObj.id == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return cppbindObj.id
        }
    
    constructor(d: Int, mo: Int, y: Int, h: Int, mi: Int, s: Int): this(CppBindObject(construct_helper(d, mo, y, h, mi, s), true)) {
    }
    
    val datetime: String
        get() {
            val result = jDatetime(cppbindObjId)
            
            return result
        }
    
    open override fun value(): String {
        val result = jValue(cppbindObjId)
        
        return result
    }

    ///// External wrapper functions ////////////
    private external fun jValue(id: Long): String
    private external fun jDatetime(id: Long): String
}

private external fun jGettypebyid(id: Long): String
