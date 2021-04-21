package com.examples.classes

import alias.*



/**
 * comments
 * 
 */
open class Project
    internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
          System.loadLibrary("wrapper_jni");
        }
        /**
         * comments
         * 
         */
        protected fun construct_helper(title: String): Long {
            
            
            val id = jConstructor(title)
            return id
        }
        @JvmStatic
        private external fun jConstructor(title: String): Long


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
    constructor(title: String): this(construct_helper(title)) {
      //jSet_this(id, this)
    }
    
    /**
     * comments
     * 
     */
    val title: String
          get() {
            val result = jTitle(getObjId())
            
            return result
          }
          
    
    /**
     * comments
     * 
     */
    fun addTask(task: Task): Void {
        
        val kotlin_to_jdk_task = task.getObjId()
        val result = jAddtask(getObjId(), kotlin_to_jdk_task)
        
        return result
    }

    /**
     * comments
     * 
     */
    fun tasks(): List<Task> {
        
        val result = jTasks(getObjId())
        val jdk_to_kotlin_result: MutableList<Task> = mutableListOf()
        for (value in result) {
            val jdk_to_kotlin_value = Task(value)
            jdk_to_kotlin_result.add(jdk_to_kotlin_value)
        }
        return jdk_to_kotlin_result
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
    private external fun jTitle(id: Long): String
    private external fun jAddtask(id: Long, task: Long): Void
    private external fun jTasks(id: Long): LongArray
    private external fun jSet_this(id: Long, self: Any): Void
    private external fun jFinalize(id: Long): Void
}