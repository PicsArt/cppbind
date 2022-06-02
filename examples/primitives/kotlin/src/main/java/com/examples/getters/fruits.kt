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

package com.examples.getters

import com.examples.cppbind.alias.*
import com.examples.cppbind.exceptionUtils.*
import com.examples.cppbind.exception_helpers.*

enum class FruitType(val value: Int) {
    Apple(1),
    Pineapple(2);

    companion object {
        private val values = values()
        fun getByValue(value: Int) = values.firstOrNull { it.value == value }
    }
}

open class Fruit
internal constructor(obj: CppBindObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        const val cppbindCxxTypeName: String = "cppbind::example::Fruit"

        public fun cppbindConstructObject(id: Long, owner: Boolean = false): Fruit {
            val idType = jGettypebyid(id)
            when (idType) {
                Apple.cppbindCxxTypeName -> return Apple(CppBindObject(id, owner))
                Pineapple.cppbindCxxTypeName -> return Pineapple(CppBindObject(id, owner))
                else -> return Fruit(CppBindObject(id, owner))
            }
        }
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
    
    open val type: FruitType
        get() {
            val result = jType(id)
            val jdktokotlinresult_optional = FruitType.getByValue(result)
            if (jdktokotlinresult_optional == null) {
                ExceptionHandler.handleUncaughtException("Internal error: unresolved reference to non existing field of FruitType enum.")
            }
            val jdktokotlinresult = jdktokotlinresult_optional!!
            return jdktokotlinresult
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
    private external fun jType(id: Long): Int
    private external fun jFinalize(id: Long): Unit
}

open class Apple
internal constructor(obj: CppBindObject) : Fruit(obj) {
    companion object {
        
        protected fun construct_helper(): Long {
            val id = jConstructor()
            return id
        }

        @JvmStatic
        private external fun jConstructor(): Long
        const val cppbindCxxTypeName: String = "cppbind::example::Apple"
    }
    
    
    constructor(): this(CppBindObject(construct_helper(), true)) {
    }
    
    open override val type: FruitType
        get() {
            val result = jType(id)
            val jdktokotlinresult_optional = FruitType.getByValue(result)
            if (jdktokotlinresult_optional == null) {
                ExceptionHandler.handleUncaughtException("Internal error: unresolved reference to non existing field of FruitType enum.")
            }
            val jdktokotlinresult = jdktokotlinresult_optional!!
            return jdktokotlinresult
        }

    ///// External wrapper functions ////////////
    private external fun jType(id: Long): Int
}

open class Pineapple
internal constructor(obj: CppBindObject) : Fruit(obj) {
    companion object {
        
        protected fun construct_helper(): Long {
            val id = jConstructor()
            return id
        }

        @JvmStatic
        private external fun jConstructor(): Long
        const val cppbindCxxTypeName: String = "cppbind::example::Pineapple"
    }
    
    
    constructor(): this(CppBindObject(construct_helper(), true)) {
    }
    
    open override val type: FruitType
        get() {
            val result = jType(id)
            val jdktokotlinresult_optional = FruitType.getByValue(result)
            if (jdktokotlinresult_optional == null) {
                ExceptionHandler.handleUncaughtException("Internal error: unresolved reference to non existing field of FruitType enum.")
            }
            val jdktokotlinresult = jdktokotlinresult_optional!!
            return jdktokotlinresult
        }

    ///// External wrapper functions ////////////
    private external fun jType(id: Long): Int
}

/**
 * An example class containing template getters.
 */
open class Fruits
internal constructor(obj: CppBindObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(fruits: List<Fruit>): Long {
            val kotlintojdkfruits = LongArray(fruits.size) 
            var index_fruits = 0
            for (value_fruits in fruits) {
                val kotlintojdkvalue_fruits = value_fruits.id
                kotlintojdkfruits[index_fruits] = kotlintojdkvalue_fruits
                ++index_fruits
            }
            val id = jConstructor(kotlintojdkfruits, fruits)
            return id
        }

        @JvmStatic
        private external fun jConstructor(fruits: LongArray, vararg extraObjs: Any?): Long
        const val cppbindCxxTypeName: String = "cppbind::example::Fruits"
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
    
    constructor(fruits: List<Fruit>): this(CppBindObject(construct_helper(fruits), true)) {
    }
    
    open val apples: List<Apple>
        get() {
            val result = jFruitsApple(id)
            val jdktokotlinresult: MutableList<Apple> = mutableListOf()
            for (value_result in result) {
                val jdktokotlinvalue_result = Apple(CppBindObject(value_result))
                jdktokotlinresult.add(jdktokotlinvalue_result)
            }
            return jdktokotlinresult
        }

    open val pineapple: List<Pineapple>
        get() {
            val result = jFruitsPineapple(id)
            val jdktokotlinresult: MutableList<Pineapple> = mutableListOf()
            for (value_result in result) {
                val jdktokotlinvalue_result = Pineapple(CppBindObject(value_result))
                jdktokotlinresult.add(jdktokotlinvalue_result)
            }
            return jdktokotlinresult
        }

    open var applesWithPineapples: List<Fruit>
        get() {
            val result = jAllfruitsApplePineapple(id)
            val jdktokotlinresult: MutableList<Fruit> = mutableListOf()
            for (value_result in result) {
                
                val jdktokotlinvalue_result : Fruit
                jdktokotlinvalue_result = Fruit.cppbindConstructObject(value_result)
                jdktokotlinresult.add(jdktokotlinvalue_result)
            }
            for (valuejdktokotlinresult in jdktokotlinresult) {
                valuejdktokotlinresult.keepCppBindReference(this)
            }
            return jdktokotlinresult
        }
        set(value) {
            val kotlintojdkvalue = LongArray(value.size) 
            var index_value = 0
            for (value_value in value) {
                val kotlintojdkvalue_value = value_value.id
                kotlintojdkvalue[index_value] = kotlintojdkvalue_value
                ++index_value
            }
            jSetallfruitsApplePineapple(id, kotlintojdkvalue, value)
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
    private external fun jFruitsApple(id: Long): LongArray
    private external fun jFruitsPineapple(id: Long): LongArray
    private external fun jAllfruitsApplePineapple(id: Long): LongArray
    private external fun jSetallfruitsApplePineapple(id: Long, value: LongArray, valueObj: Any?): Unit
    private external fun jFinalize(id: Long): Unit
}

private external fun jGettypebyid(id: Long): String
