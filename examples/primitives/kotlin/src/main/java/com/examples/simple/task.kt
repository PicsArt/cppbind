/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 06/01/2022-07:54.
 * Please do not change it manually.
 */

package com.examples.simple

import com.examples.cppbind.alias.*
import com.examples.cppbind.exceptionUtils.*
import com.examples.cppbind.exception_helpers.*

/**
 * Class holding task information.
 */
open class Task
internal constructor(obj: CppBindObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        /**
         * Task Constructor.
         */
        protected fun construct_helper(title: String): Long {
            val id = jConstructor(title)
            return id
        }

        @JvmStatic
        private external fun jConstructor(title: String, vararg extraObjs: Any?): Long
        const val cppbindCxxTypeName: String = "cppbind::example::Task"
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
     * Task Constructor.
     */
    constructor(title: String): this(CppBindObject(construct_helper(title), true)) {
    }
    
    /**
     * Get objects title.
     */
    val title: String
        get() {
            val result = jTitle(id)
            
            return result
        }
    
    /**
     * Get objects title.
     */
    fun setTitle(title: String): Unit {
        val result = jSettitle(id, title)
        
        return result
    }

    fun equals(t: Task): Boolean {
        val kotlintojdkt = t.id
        val result = jEquals(id, kotlintojdkt, t)
        
        return result
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
    private external fun jSettitle(id: Long, title: String, vararg extraObjs: Any?): Unit
    private external fun jEquals(id: Long, t: Long, vararg extraObjs: Any?): Boolean
    private external fun jFinalize(id: Long): Unit
}

private external fun jGettypebyid(id: Long): String
