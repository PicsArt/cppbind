/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 08/11/2022-07:04.
 * Please do not change it manually.
 */

package com.examples.templates

import com.examples.cppbind.*
import com.examples.cppbind.exception_helpers.*
import com.examples.simple.Root


/**
 * Addressable is a base class for all the objects, that have abs path.
 * FIXME: swift.descendants is given manually since we have an issue with descendants list formation for templates (#410)
 */
interface IAddressableRoot : AutoCloseable {
    /**
     * An internal getter to get the id of an object.
     * It is intended to be used by the generated code.
     */
    val cppbindObjId: Long
    /**
     * An internal method to bind the lifetimes of the current and another object.
     * It is intended to be used by the generated code.
     */
    fun keepCppBindReference(ref: Any)
    
    
    /**
     * comments
     * @brief Get object's abs path based on parent's abs path and object's name
     * @return the abs path of the object
     */
    fun absPath(): String {
        val result = IAddressableRootHelper.jAbspath(cppbindObjId)
        
        return result
    }

    companion object {
        /**
         * An internal method to create a Kotlin object from a C++ object.
         * It is intended to be used by the generated code.
         */
        public fun cppbindConstructObject(id: Long, owner: Boolean = false): IAddressableRoot {
            val idType = jGettypebyid(id)
            when (idType) {
                Component.cppbindCxxTypeName -> return Component(CppBindObject(id, owner))
                else -> return AddressableImplRoot(CppBindObject(id, owner))
            }
        }
    }
}


class IAddressableRootHelper {
    companion object {
        @JvmStatic
        external fun jAbspath(id: Long): String
    }
}


open class AddressableImplRoot
internal constructor(obj : CppBindObject) : IAddressableRoot {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        /**
         * comments
         */
        protected fun constructHelper(parent: Root, name: String): Long {
            val kotlintojdkparent = parent.cppbindObjId
            val id = jConstructor(kotlintojdkparent, name, parent)
            return id
        }

        @JvmStatic
        private external fun jConstructor(parent: Long, name: String, vararg extraObjs: Any?): Long
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::Addressable<cppbind::example::Root>"
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
    
    /**
     * comments
     */
    constructor(parent: Root, name: String): this(CppBindObject(constructHelper(parent, name), true)) {
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
        other as AddressableImplRoot
        return cxxId == other.cxxId
    }

    /**
     * CppBind generated toString method returning underlying C++ object type and id.
     */
    override fun toString(): String {
        return "<0x$cxxId: $cxxTypeName>"
    }

    ///// External wrapper functions ////////////
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

private external fun jGettypebyid(id: Long): String
