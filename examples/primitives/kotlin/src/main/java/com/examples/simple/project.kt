/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 08/12/2022-06:48.
 * Please do not change it manually.
 */

package com.examples.simple

import com.examples.cppbind.*
import com.examples.cppbind.exceptions.*

/**
 * Class holding project information.
 */
open class Project
internal constructor(obj: CppBindObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        /**
         * Project constructor.
         */
        protected fun constructHelper(title: String): Long {
            val id = jConstructor(title)
            return id
        }

        @JvmStatic
        private external fun jConstructor(title: String, vararg extraObjs: Any?): Long
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::Project"
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
    
    /**
     * Project constructor.
     */
    constructor(title: String): this(CppBindObject(constructHelper(title), true)) {
    }
    
    /**
     * Get project´s title.
     */
    val title: String
        get() {
            val result = jTitle(cppbindObjId)
            
            return result
        }
    
    /**
     * Add a task to project.
     */
    fun addTask(task: Task): Unit {
        val kotlintojdktask = task.cppbindObjId
        val result = jAddtask(cppbindObjId, kotlintojdktask, task)
        
        return result
    }

    /**
     * Get project´s tasks.
     */
    fun tasks(): List<Task> {
        val result = jTasks(cppbindObjId)
        val jdktokotlinresult: MutableList<Task> = mutableListOf()
        for (valueResult in result) {
            val jdktokotlinvalueResult = Task(CppBindObject(valueResult))
            jdktokotlinresult.add(jdktokotlinvalueResult)
        }
        return jdktokotlinresult
    }

    override fun equals(other: Any?): Boolean {
        other as Project
        return jEquals(cppbindObjId, other.cppbindObjId, other)
    }

    /**
     * CppBind generated hashCode method returning the hash of underlying C++ object id.
     */
    override fun hashCode(): Int {
        return cxxId.hashCode()
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
    private external fun jTitle(id: Long): String
    private external fun jAddtask(id: Long, task: Long, vararg extraObjs: Any?): Unit
    private external fun jTasks(id: Long): LongArray
    private external fun jEquals(id: Long, p: Long, vararg extraObjs: Any?): Boolean
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

private external fun jGettypebyid(id: Long): String
