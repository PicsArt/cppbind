package com.examples.containers

import alias.*


/**
 * comments
 * 
 */
open class VectorItem
internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni");
        }
        
        /**
         * comments
         * 
         */
        protected fun construct_helper(_value: Int): Long {
            val id = jConstructor(_value)
            return id
        }

        @JvmStatic
        private external fun jConstructor(_value: Int): Long
    }
    
    protected var id = _id
    
    open fun getObjId(): Long {
        if (id == 0L) {
            throw RuntimeException("Object is not allocated")
        }
        return id;
    }
    
    /**
     * comments
     * 
     */
    constructor(_value: Int) : this(construct_helper(_value)) {
        //jSet_this(id, this)
    }
    
    /**
     * comments
     * 
     */
    var value: Int
        get() {
            val result = jValue(getObjId())
            
            return result
        }
        set(value) {
            
            jSetvalue(getObjId(), value)
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
    private external fun jValue(id: Long): Int
    private external fun jSetvalue(id: Long, value: Int): Unit
    private external fun jSet_this(id: Long, self: Any): Unit
    private external fun jFinalize(id: Long): Unit
}

/**
 * comments
 * 
 */
open class VectorExamples
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






    }
    
    protected var id = _id
    
    open fun getObjId(): Long {
        if (id == 0L) {
            throw RuntimeException("Object is not allocated")
        }
        return id;
    }
    
    /**
     * comments
     * 
     */
    constructor() : this(construct_helper()) {
        //jSet_this(id, this)
    }
    
    /**
     * comments
     * 
     */
    fun addIntVector(v: List<Int>): Unit {
        
        val kotlin_to_jdk_v = IntArray(v.size) 
        var index = 0
        for (value in v) {
            
            kotlin_to_jdk_v[index] = value
            ++index
        }
        val result = jAddintvector(getObjId(), kotlin_to_jdk_v)
        
        return result
    }

    /**
     * comments
     * 
     */
    fun addObjVector(v: List<VectorItem>): Unit {
        
        val kotlin_to_jdk_v = LongArray(v.size) 
        var index = 0
        for (value in v) {
            val kotlin_to_jdk_value = value.getObjId()
            kotlin_to_jdk_v[index] = kotlin_to_jdk_value
            ++index
        }
        val result = jAddobjvector(getObjId(), kotlin_to_jdk_v)
        
        return result
    }

    /**
     * comments
     * 
     */
    fun addStringVector(v: List<String>): Unit {
        
        val kotlin_to_jdk_v = StringArray(v.size) { String() }
        var index = 0
        for (value in v) {
            
            kotlin_to_jdk_v[index] = value
            ++index
        }
        val result = jAddstringvector(getObjId(), kotlin_to_jdk_v)
        
        return result
    }

    /**
     * comments
     * 
     */
    fun getStringVector(): List<String> {
        val result = jGetstringvector(getObjId())
        val jdk_to_kotlin_result: MutableList<String> = mutableListOf()
        for (value in result) {
            
            jdk_to_kotlin_result.add(value)
        }
        return jdk_to_kotlin_result
    }

    /**
     * comments
     * 
     */
    fun getObjVector(): List<VectorItem> {
        val result = jGetobjvector(getObjId())
        val jdk_to_kotlin_result: MutableList<VectorItem> = mutableListOf()
        for (value in result) {
            val jdk_to_kotlin_value = VectorItem(value)
            jdk_to_kotlin_result.add(jdk_to_kotlin_value)
        }
        return jdk_to_kotlin_result
    }

    /**
     * comments
     * 
     */
    fun getIntVector(): List<Int> {
        val result = jGetintvector(getObjId())
        val jdk_to_kotlin_result: MutableList<Int> = mutableListOf()
        for (value in result) {
            
            jdk_to_kotlin_result.add(value)
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
    private external fun jAddintvector(id: Long, v: IntArray): Unit
    private external fun jAddobjvector(id: Long, v: LongArray): Unit
    private external fun jAddstringvector(id: Long, v: StringArray): Unit
    private external fun jGetstringvector(id: Long): StringArray
    private external fun jGetobjvector(id: Long): LongArray
    private external fun jGetintvector(id: Long): IntArray
    private external fun jSet_this(id: Long, self: Any): Unit
    private external fun jFinalize(id: Long): Unit
}