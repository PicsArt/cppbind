/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 02/22/2022-09:26.
 * Please do not change it manually.
 */

package com.examples.templates

import com.examples.getters.NumberInt
import com.examples.iegen.alias.*
import com.examples.iegen.exceptionUtils.*
import com.examples.iegen.exception_helpers.*
import com.examples.simple.Project
import com.examples.simple.Task

/**
 * comments
 * 
 */
open class StackPrj
internal constructor(_id: Long, _owner: Boolean = false) : IContainer, AutoCloseable {
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

        protected fun construct_helper(st: Project): Long {
            val kotlintojdkst = st.id
            val id = jConstructor_1(kotlintojdkst)
            return id
        }

        @JvmStatic
        private external fun jConstructor_1(st: Long): Long
    }
    
    protected var objId = _id
    protected val owner = _owner
    private var refs: MutableList<Any> = mutableListOf()

    override fun keepIEGenReference(ref: Any) {
        refs.add(ref)
    }

    override val id: Long
        get() {
            if (objId == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return objId
        }
    
    constructor(): this(construct_helper(), true) {
    }

    constructor(st: Project): this(construct_helper(st), true) {
    }
    
    fun push(item: Project): Unit {
        val kotlintojdkitem = item.id
        val result = jPush(id, kotlintojdkitem)
        
        return result
    }

    fun pop(): Unit {
        val result = jPop(id)
        
        return result
    }

    fun top(): Project {
        val result = jTop(id)
        val jdktokotlinresult = Project(result)
        return jdktokotlinresult
    }

    fun empty(): Boolean {
        val result = jEmpty(id)
        
        return result
    }

    override fun close() {
        if (owner && objId != 0L) {
            jFinalize(objId)
            objId = 0L
        }
    }

    /**
     * Finalize and deletes the object
     */
    protected fun finalize() {
        close()
    }

    ///// External wrapper functions ////////////
    private external fun jPush(id: Long, item: Long): Unit
    private external fun jPop(id: Long): Unit
    private external fun jTop(id: Long): Long
    private external fun jEmpty(id: Long): Boolean
    private external fun jFinalize(id: Long): Unit
}

/**
 * comments
 * 
 */
open class StackTask
internal constructor(_id: Long, _owner: Boolean = false) : IContainer, AutoCloseable {
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

        protected fun construct_helper(st: Task): Long {
            val kotlintojdkst = st.id
            val id = jConstructor_1(kotlintojdkst)
            return id
        }

        @JvmStatic
        private external fun jConstructor_1(st: Long): Long
    }
    
    protected var objId = _id
    protected val owner = _owner
    private var refs: MutableList<Any> = mutableListOf()

    override fun keepIEGenReference(ref: Any) {
        refs.add(ref)
    }

    override val id: Long
        get() {
            if (objId == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return objId
        }
    
    constructor(): this(construct_helper(), true) {
    }

    constructor(st: Task): this(construct_helper(st), true) {
    }
    
    fun push(item: Task): Unit {
        val kotlintojdkitem = item.id
        val result = jPush(id, kotlintojdkitem)
        
        return result
    }

    fun pop(): Unit {
        val result = jPop(id)
        
        return result
    }

    fun top(): Task {
        val result = jTop(id)
        val jdktokotlinresult = Task(result)
        return jdktokotlinresult
    }

    fun empty(): Boolean {
        val result = jEmpty(id)
        
        return result
    }

    override fun close() {
        if (owner && objId != 0L) {
            jFinalize(objId)
            objId = 0L
        }
    }

    /**
     * Finalize and deletes the object
     */
    protected fun finalize() {
        close()
    }

    ///// External wrapper functions ////////////
    private external fun jPush(id: Long, item: Long): Unit
    private external fun jPop(id: Long): Unit
    private external fun jTop(id: Long): Long
    private external fun jEmpty(id: Long): Boolean
    private external fun jFinalize(id: Long): Unit
}

/**
 * comments
 * 
 */
open class StackNumInt
internal constructor(_id: Long, _owner: Boolean = false) : IContainer, AutoCloseable {
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

        protected fun construct_helper(st: NumberInt): Long {
            val kotlintojdkst = st.id
            val id = jConstructor_1(kotlintojdkst)
            return id
        }

        @JvmStatic
        private external fun jConstructor_1(st: Long): Long
    }
    
    protected var objId = _id
    protected val owner = _owner
    private var refs: MutableList<Any> = mutableListOf()

    override fun keepIEGenReference(ref: Any) {
        refs.add(ref)
    }

    override val id: Long
        get() {
            if (objId == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return objId
        }
    
    constructor(): this(construct_helper(), true) {
    }

    constructor(st: NumberInt): this(construct_helper(st), true) {
    }
    
    fun push(item: NumberInt): Unit {
        val kotlintojdkitem = item.id
        val result = jPush(id, kotlintojdkitem)
        
        return result
    }

    fun pop(): Unit {
        val result = jPop(id)
        
        return result
    }

    fun top(): NumberInt {
        val result = jTop(id)
        val jdktokotlinresult = NumberInt(result)
        return jdktokotlinresult
    }

    fun empty(): Boolean {
        val result = jEmpty(id)
        
        return result
    }

    override fun close() {
        if (owner && objId != 0L) {
            jFinalize(objId)
            objId = 0L
        }
    }

    /**
     * Finalize and deletes the object
     */
    protected fun finalize() {
        close()
    }

    ///// External wrapper functions ////////////
    private external fun jPush(id: Long, item: Long): Unit
    private external fun jPop(id: Long): Unit
    private external fun jTop(id: Long): Long
    private external fun jEmpty(id: Long): Boolean
    private external fun jFinalize(id: Long): Unit
}

private external fun jGettypebyid(id: Long): String
