/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 08/18/2022-11:03.
 * Please do not change it manually.
 */

package com.examples.templates

import com.examples.cppbind.*
import com.examples.cppbind.exceptions.*
import com.examples.simple.Project

open class StackUsage
internal constructor(obj: CppBindObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun constructHelper(): Long {
            val id = jConstructor()
            return id
        }

        @JvmStatic
        private external fun jConstructor(): Long
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::StackUsage"
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
    open val cppbindObjId: Long
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
    
    constructor(): this(CppBindObject(constructHelper(), true)) {
    }
    
    fun firstItemOfSpecializedStack(p: StackPrj): Project {
        val kotlintojdkp = p.cppbindObjId
        val result = jFirstitemofspecializedstack(cppbindObjId, kotlintojdkp, p)
        val jdktokotlinresult = Project(CppBindObject(result))
        return jdktokotlinresult
    }

    fun firstItemOfTypedefOfSpecializedStack(p: StackPrj): Project {
        val kotlintojdkp = p.cppbindObjId
        val result = jFirstitemoftypedefofspecializedstack(cppbindObjId, kotlintojdkp, p)
        val jdktokotlinresult = Project(CppBindObject(result))
        return jdktokotlinresult
    }

    /**
     * Full type name(i.e., cppbind::example::Stack<V> not just Stack<V>) should be explicitly specified otherwise
     * cppbind won't be able to generate a converter for the argument, as for templates libclang does not provide
     * enough information.
     */
    open fun firstItemOfTemplateStack(p: StackPrj): Project {
        val kotlintojdkp = p.cppbindObjId
        val result = jFirstitemoftemplatestackProject(cppbindObjId, kotlintojdkp, p)
        val jdktokotlinresult = Project(CppBindObject(result))
        return jdktokotlinresult
    }

    /**
     * Example to check typedef argument types
     */
    fun firstItemOfSpecializedStackWithTypedefArg(p: StackPrj): Project {
        val kotlintojdkp = p.cppbindObjId
        val result = jFirstitemofspecializedstackwithtypedefarg(cppbindObjId, kotlintojdkp, p)
        val jdktokotlinresult = Project(CppBindObject(result))
        return jdktokotlinresult
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
        other as StackUsage
        return cxxId == other.cxxId
    }

    /**
     * CppBind generated toString method returning underlying C++ object type and id.
     */
    override fun toString(): String {
        return "<0x$cxxId: $cxxTypeName>"
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
    private external fun jFirstitemofspecializedstack(id: Long, p: Long, vararg extraObjs: Any?): Long
    private external fun jFirstitemoftypedefofspecializedstack(id: Long, p: Long, vararg extraObjs: Any?): Long
    private external fun jFirstitemoftemplatestackProject(id: Long, p: Long, vararg extraObjs: Any?): Long
    private external fun jFirstitemofspecializedstackwithtypedefarg(id: Long, p: Long, vararg extraObjs: Any?): Long
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

private external fun jGettypebyid(id: Long): String
