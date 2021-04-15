package com.examples.containers

import alias.*



/**
 * comments
 * 
 */
open class Item
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
        if(id == 0L) {
            throw RuntimeException("Object is not allocated")
        }
        return id;
    }
    /**
     * comments
     * 
     */
    constructor(_value: Int): this(construct_helper(_value)) {
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
    private external fun jSetvalue(id: Long, value : Int): Void
    private external fun jSet_this(id: Long, self: Any): Void
    private external fun jFinalize(id: Long): Void
}

/**
 * comments
 * 
 */
open class Containers
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
    fun addStringPair(info: Pair<String, String>): Void {
        
        val first = info.first
        val second = info.second


        val kotlin_to_jdk_info = Pair<String, String>(first, second)
        val result = jAddstringpair(getObjId(), kotlin_to_jdk_info)
        
        return result
    }

    /**
     * comments
     * 
     */
    fun addIntMap(info: Map<Int, Int>): Void {
        
        
        val tmp_key_kotlin_to_jdk_info = IntArray(info.size)
        val tmp_val_kotlin_to_jdk_info = IntArray(info.size)
        val kotlin_to_jdk_info = Pair<IntArray, IntArray>(tmp_key_kotlin_to_jdk_info, tmp_val_kotlin_to_jdk_info)
        var index = 0
        for ((key, value) in info) {
            
            
            tmp_key_kotlin_to_jdk_info[index] = key
            tmp_val_kotlin_to_jdk_info[index] = value
            ++index
        }
        val result = jAddintmap(getObjId(), kotlin_to_jdk_info)
        
        return result
    }

    /**
     * comments
     * 
     */
    fun addStringMap(info: Map<String, String>): Void {
        
        
        val tmp_key_kotlin_to_jdk_info = StringArray(info.size){String()}
        val tmp_val_kotlin_to_jdk_info = StringArray(info.size){String()}
        val kotlin_to_jdk_info = Pair<StringArray, StringArray>(tmp_key_kotlin_to_jdk_info, tmp_val_kotlin_to_jdk_info)
        var index = 0
        for ((key, value) in info) {
            
            
            tmp_key_kotlin_to_jdk_info[index] = key
            tmp_val_kotlin_to_jdk_info[index] = value
            ++index
        }
        val result = jAddstringmap(getObjId(), kotlin_to_jdk_info)
        
        return result
    }

    /**
     * comments
     * 
     */
    fun addIntPair(info: Pair<Int, Int>): Void {
        
        val first = info.first
        val second = info.second


        val kotlin_to_jdk_info = Pair<Int, Int>(first, second)
        val result = jAddintpair(getObjId(), kotlin_to_jdk_info)
        
        return result
    }

    /**
     * comments
     * 
     */
    fun getStringPair(): Pair<String, String> {
        
        val result = jGetstringpair(getObjId())
        val first  = result.first
        val second  = result.second


        val jdk_to_kotlin_result = Pair<String, String>(first, second)
        return jdk_to_kotlin_result
    }

    /**
     * comments
     * 
     */
    fun getStringMap(): Map<String, String> {
        
        val result = jGetstringmap(getObjId())
        val jdk_to_kotlin_result = HashMap<String, String>()
        for (i in 0..result.first.size - 1) {
            val elem1 = result.first.get(i)
            val elem2 = result.second.get(i)
            
            
            jdk_to_kotlin_result.put(elem1, elem2)
        }
        return jdk_to_kotlin_result
    }

    /**
     * comments
     * 
     */
    fun getIntMap(): Map<Int, Int> {
        
        val result = jGetintmap(getObjId())
        val jdk_to_kotlin_result = HashMap<Int, Int>()
        for (i in 0..result.first.size - 1) {
            val elem1 = result.first.get(i)
            val elem2 = result.second.get(i)
            
            
            jdk_to_kotlin_result.put(elem1, elem2)
        }
        return jdk_to_kotlin_result
    }

    /**
     * comments
     * 
     */
    fun getMap(): Map<String, Item> {
        
        val result = jGetmap(getObjId())
        val jdk_to_kotlin_result = HashMap<String, Item>()
        for (i in 0..result.first.size - 1) {
            val elem1 = result.first.get(i)
            val elem2 = result.second.get(i)
            
            val jdk_to_kotlin_elem2 = Item(elem2)
            jdk_to_kotlin_result.put(elem1, jdk_to_kotlin_elem2)
        }
        return jdk_to_kotlin_result
    }

    /**
     * comments
     * 
     */
    fun addIntVector(v: List<Int>): Void {
        
        
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
    fun addStringVector(v: List<String>): Void {
        
        
        val kotlin_to_jdk_v = StringArray(v.size){String()}
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
    private external fun jAddstringpair(id: Long, info: Pair<String, String>): Void
    private external fun jAddintmap(id: Long, info: Pair<IntArray, IntArray>): Void
    private external fun jAddstringmap(id: Long, info: Pair<StringArray, StringArray>): Void
    private external fun jAddintpair(id: Long, info: Pair<Int, Int>): Void
    private external fun jGetstringpair(id: Long): Pair<String, String>
    private external fun jGetstringmap(id: Long): Pair<StringArray, StringArray>
    private external fun jGetintmap(id: Long): Pair<IntArray, IntArray>
    private external fun jGetmap(id: Long): Pair<StringArray, LongArray>
    private external fun jAddintvector(id: Long, v: IntArray): Void
    private external fun jAddstringvector(id: Long, v: StringArray): Void
    private external fun jGetstringvector(id: Long): StringArray
    private external fun jGetintvector(id: Long): IntArray
    private external fun jSet_this(id: Long, self: Any): Void
    private external fun jFinalize(id: Long): Void
}