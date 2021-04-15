package com.examples.templates

import alias.*
import com.example.classes.Project
import com.example.classes.Task


/**
 * comments
 * 
 */
open class StackProject
    internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
          System.loadLibrary("wrapper_jni");
        }
        /**
         * comments
         * 
         */
        protected fun construct_helper(): Long {
            
            val id = jConstructor()
            return id
        }
        @JvmStatic
        private external fun jConstructor(): Long
        /**
         * comments
         * 
         */
        protected fun construct_helper(st: Project): Long {
            val kotlin_to_jdk_st = st.getObjId()
            
            val id = jConstructor_1(kotlin_to_jdk_st)
            return id
        }
        @JvmStatic
        private external fun jConstructor_1(st: Long): Long




    }
    
    protected var id = _id
    
    open fun getObjId(): Long {
        if(id == 0L) {
            throw RuntimeException("Object is not allocated")
        }
        return id;
    }
    /**
     * comments
     * 
     */
    constructor(): this(construct_helper()) {
      //jSet_this(id, this)
    }
    /**
     * comments
     * 
     */
    constructor(st: Project): this(construct_helper(st)) {
      //jSet_this(id, this)
    }
    
    
    /**
     * comments
     * 
     */
    fun push(item: Project): Void {
        
        val kotlin_to_jdk_item = item.getObjId()
        val result = jPush(getObjId(), kotlin_to_jdk_item)
        
        return result
    }

    /**
     * comments
     * 
     */
    fun pop(): Void {
        
        val result = jPop(getObjId())
        
        return result
    }

    /**
     * comments
     * 
     */
    fun top(): Project {
        
        val result = jTop(getObjId())
        val jdk_to_kotlin_result = Project(result)
        return jdk_to_kotlin_result
    }

    /**
     * comments
     * 
     */
    fun empty(): Boolean {
        
        val result = jEmpty(getObjId())
        
        return result
    }
    override fun close() {
    	if (id != 0L) {
    		jFinalize(id)
    		id = 0L
    	}
    }
    /**
    * Finalize and deletes the object
    */
    protected fun finalize() {
    	close()
    }
    ///// External wrapper functions ////////////
    private external fun jPush(id: Long, item: Long): Void
    private external fun jPop(id: Long): Void
    private external fun jTop(id: Long): Long
    private external fun jEmpty(id: Long): Boolean
    private external fun jSet_this(id: Long, self: Any): Void
    private external fun jFinalize(id: Long): Void
}

/**
 * comments
 * 
 */
open class StackTask
    internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
          System.loadLibrary("wrapper_jni");
        }
        /**
         * comments
         * 
         */
        protected fun construct_helper(): Long {
            
            val id = jConstructor()
            return id
        }
        @JvmStatic
        private external fun jConstructor(): Long
        /**
         * comments
         * 
         */
        protected fun construct_helper(st: Task): Long {
            val kotlin_to_jdk_st = st.getObjId()
            
            val id = jConstructor_1(kotlin_to_jdk_st)
            return id
        }
        @JvmStatic
        private external fun jConstructor_1(st: Long): Long




    }
    
    protected var id = _id
    
    open fun getObjId(): Long {
        if(id == 0L) {
            throw RuntimeException("Object is not allocated")
        }
        return id;
    }
    /**
     * comments
     * 
     */
    constructor(): this(construct_helper()) {
      //jSet_this(id, this)
    }
    /**
     * comments
     * 
     */
    constructor(st: Task): this(construct_helper(st)) {
      //jSet_this(id, this)
    }
    
    
    /**
     * comments
     * 
     */
    fun push(item: Task): Void {
        
        val kotlin_to_jdk_item = item.getObjId()
        val result = jPush(getObjId(), kotlin_to_jdk_item)
        
        return result
    }

    /**
     * comments
     * 
     */
    fun pop(): Void {
        
        val result = jPop(getObjId())
        
        return result
    }

    /**
     * comments
     * 
     */
    fun top(): Task {
        
        val result = jTop(getObjId())
        val jdk_to_kotlin_result = Task(result)
        return jdk_to_kotlin_result
    }

    /**
     * comments
     * 
     */
    fun empty(): Boolean {
        
        val result = jEmpty(getObjId())
        
        return result
    }
    override fun close() {
    	if (id != 0L) {
    		jFinalize(id)
    		id = 0L
    	}
    }
    /**
    * Finalize and deletes the object
    */
    protected fun finalize() {
    	close()
    }
    ///// External wrapper functions ////////////
    private external fun jPush(id: Long, item: Long): Void
    private external fun jPop(id: Long): Void
    private external fun jTop(id: Long): Long
    private external fun jEmpty(id: Long): Boolean
    private external fun jSet_this(id: Long, self: Any): Void
    private external fun jFinalize(id: Long): Void
}