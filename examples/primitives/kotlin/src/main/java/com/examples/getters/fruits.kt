/**
 * ,--.,------. ,----.   ,------.,--.  ,--.
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  |
 * |  ||  `--, |  | .---.|  `--, |  |' '  |
 * |  ||  `---.'  '--'  ||  `---.|  | `   |
 * `--'`------' `------' `------'`--'  `--'
 * 
 * This file is generated by iegen on 12/04/2021-12:27.
 * Please do not change it manually.
 */

package com.examples.getters

import com.examples.exception_helpers.*
import com.examples.iegen.alias.*
import com.examples.iegen.exceptionUtils.*

enum class FruitType(val value: Int) {
    Apple(1),
    Pineapple(2);

    companion object {
        private val values = values()
        fun getByValue(value: Int) = values.firstOrNull { it.value == value }
    }
}

open class Fruit
internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
    }
    
    protected var objId = _id
    
    open val id: Long
        get() {
            if (objId == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return objId
        }
    
    open val type: FruitType
        get() {
            val result = jType(id)
            val jdk_to_kotlin_result_optional = FruitType.getByValue(result)
            if (jdk_to_kotlin_result_optional == null) {
                ExceptionHandler.handleUncaughtException("Internal error: unresolved reference to non existing field of FruitType enum.")
            }
            val jdk_to_kotlin_result = jdk_to_kotlin_result_optional!!
            return jdk_to_kotlin_result
        }

    override fun close() {
        if (objId != 0L) {
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
    private external fun jType(id: Long): Int
    private external fun jFinalize(id: Long): Unit
}

open class Apple
internal constructor(_id: Long) : Fruit(_id) {
    companion object {
        
        protected fun construct_helper(): Long {
            val id = jConstructor()
            return id
        }

        @JvmStatic
        private external fun jConstructor(): Long
    }
    
    
    constructor(): this(construct_helper()) {
    }
    
    open override val type: FruitType
        get() {
            val result = jType(id)
            val jdk_to_kotlin_result_optional = FruitType.getByValue(result)
            if (jdk_to_kotlin_result_optional == null) {
                ExceptionHandler.handleUncaughtException("Internal error: unresolved reference to non existing field of FruitType enum.")
            }
            val jdk_to_kotlin_result = jdk_to_kotlin_result_optional!!
            return jdk_to_kotlin_result
        }

    ///// External wrapper functions ////////////
    private external fun jType(id: Long): Int
}

open class Pineapple
internal constructor(_id: Long) : Fruit(_id) {
    companion object {
        
        protected fun construct_helper(): Long {
            val id = jConstructor()
            return id
        }

        @JvmStatic
        private external fun jConstructor(): Long
    }
    
    
    constructor(): this(construct_helper()) {
    }
    
    open override val type: FruitType
        get() {
            val result = jType(id)
            val jdk_to_kotlin_result_optional = FruitType.getByValue(result)
            if (jdk_to_kotlin_result_optional == null) {
                ExceptionHandler.handleUncaughtException("Internal error: unresolved reference to non existing field of FruitType enum.")
            }
            val jdk_to_kotlin_result = jdk_to_kotlin_result_optional!!
            return jdk_to_kotlin_result
        }

    ///// External wrapper functions ////////////
    private external fun jType(id: Long): Int
}

/**
 * An example class containing template getters.
 */
open class Fruits
internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(fruits: List<Fruit>): Long {
            val kotlin_to_jdk_fruits = LongArray(fruits.size) 
            var index_fruits = 0
            for (value_fruits in fruits) {
                val kotlin_to_jdk_value_fruits = value_fruits.id
                kotlin_to_jdk_fruits[index_fruits] = kotlin_to_jdk_value_fruits
                ++index_fruits
            }
            val id = jConstructor(kotlin_to_jdk_fruits)
            return id
        }

        @JvmStatic
        private external fun jConstructor(fruits: LongArray): Long
    }
    
    protected var objId = _id
    
    open val id: Long
        get() {
            if (objId == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return objId
        }
    
    constructor(fruits: List<Fruit>): this(construct_helper(fruits)) {
    }
    
    open val apples: List<Apple>
        get() {
            val result = jFruitsApple(id)
            val jdk_to_kotlin_result: MutableList<Apple> = mutableListOf()
            for (value_result in result) {
                val jdk_to_kotlin_value_result = Apple(value_result)
                jdk_to_kotlin_result.add(jdk_to_kotlin_value_result)
            }
            return jdk_to_kotlin_result
        }

    open val pineapple: List<Pineapple>
        get() {
            val result = jFruitsPineapple(id)
            val jdk_to_kotlin_result: MutableList<Pineapple> = mutableListOf()
            for (value_result in result) {
                val jdk_to_kotlin_value_result = Pineapple(value_result)
                jdk_to_kotlin_result.add(jdk_to_kotlin_value_result)
            }
            return jdk_to_kotlin_result
        }

    open var applesWithPineapples: List<Fruit>
        get() {
            val result = jAllfruitsApplePineapple(id)
            val jdk_to_kotlin_result: MutableList<Fruit> = mutableListOf()
            for (value_result in result) {
                val jdk_to_kotlin_value_result = Fruit(value_result)
                jdk_to_kotlin_result.add(jdk_to_kotlin_value_result)
            }
            return jdk_to_kotlin_result
        }
        set(value) {
            
            val kotlin_to_jdk_value = LongArray(value.size) 
            var index_value = 0
            for (value_value in value) {
                val kotlin_to_jdk_value_value = value_value.id
                kotlin_to_jdk_value[index_value] = kotlin_to_jdk_value_value
                ++index_value
            }
            jSetallfruitsApplePineapple(id, kotlin_to_jdk_value)
        }

    override fun close() {
        if (objId != 0L) {
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
    private external fun jFruitsApple(id: Long): LongArray
    private external fun jFruitsPineapple(id: Long): LongArray
    private external fun jAllfruitsApplePineapple(id: Long): LongArray
    private external fun jSetallfruitsApplePineapple(id: Long, value: LongArray): Unit
    private external fun jFinalize(id: Long): Unit
}