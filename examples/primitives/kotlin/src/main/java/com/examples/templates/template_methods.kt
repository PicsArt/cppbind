/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 06/06/2022-05:25.
 * Please do not change it manually.
 */

package com.examples.templates

import com.examples.cppbind.alias.*
import com.examples.cppbind.exceptionUtils.*
import com.examples.cppbind.exception_helpers.*
import com.examples.simple.Project
import com.examples.simple.Root

open class TemplateMethods
internal constructor(obj: CppBindObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(): Long {
            val id = jConstructor()
            return id
        }

        @JvmStatic
        private external fun jConstructor(): Long
        const val cppbindCxxTypeName: String = "cppbind::example::TemplateMethods"
    }
    
    protected var cppbindObj = obj
    private var refs: MutableList<Any> = mutableListOf()

    fun keepCppBindReference(ref: Any) {
        refs.add(ref)
    }
    
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
    
    constructor(): this(CppBindObject(construct_helper(), true)) {
    }
    
    open fun max(a: Int, b: Int): Int {
        val result = jMaxInt(id, a, b)
        
        return result
    }

    open fun max(a: String, b: String): String {
        val result = jMaxString(id, a, b)
        
        return result
    }

    open fun makePair(a: Project, b: Project): Pair<Project, Project> {
        val kotlintojdka = a.id
        val kotlintojdkb = b.id
        val result = jMakepairProjectProject(id, kotlintojdka, kotlintojdkb, a, b)
        val first_result = result.first
        val second_result = result.second
        val jdktokotlinfirst_result = Project(CppBindObject(first_result))
        val jdktokotlinsecond_result = Project(CppBindObject(second_result))
        val jdktokotlinresult = Pair<Project, Project>(jdktokotlinfirst_result, jdktokotlinsecond_result)
        return jdktokotlinresult
    }

    open fun makePair(a: Root, b: Project): Pair<Root, Project> {
        val kotlintojdka = a.id
        val kotlintojdkb = b.id
        val result = jMakepairRootProject(id, kotlintojdka, kotlintojdkb, a, b)
        val first_result = result.first
        val second_result = result.second
        val jdktokotlinfirst_result = Root(CppBindObject(first_result))
        val jdktokotlinsecond_result = Project(CppBindObject(second_result))
        val jdktokotlinresult = Pair<Root, Project>(jdktokotlinfirst_result, jdktokotlinsecond_result)
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
        other as TemplateMethods
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
    private external fun jMaxInt(id: Long, a: Int, b: Int, vararg extraObjs: Any?): Int
    private external fun jMaxString(id: Long, a: String, b: String, vararg extraObjs: Any?): String
    private external fun jMakepairProjectProject(id: Long, a: Long, b: Long, vararg extraObjs: Any?): Pair<Long, Long>
    private external fun jMakepairRootProject(id: Long, a: Long, b: Long, vararg extraObjs: Any?): Pair<Long, Long>
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

private external fun jGettypebyid(id: Long): String
