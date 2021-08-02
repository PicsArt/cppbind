/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 07/30/2021-12:58.
 * Please do not change it manually.
 */

package com.examples.optionals

import alias.*
import exceptionUtils.*

import com.examples.exception_helpers.*import com.examples.simple.Task
import com.examples.simple.Project
import com.examples.getters.Person
import com.examples.enums.Color

open class Optionals
internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni");
        }
        
        /**
         * constructor
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
     * constructor
     */
    constructor(): this(construct_helper()) {
        //jSet_this(id, this)
    }
    
    fun optionalPtrWithNullptrDefault(task: Task? = null): Task? {
        val kotlin_to_jdk_task = task?.getObjId() ?: 0L
        val result = jOptionalptrwithnullptrdefault(getObjId(), kotlin_to_jdk_task)
        val jdk_to_kotlin_result = if (result == 0L) null else Task(result)
        return jdk_to_kotlin_result
    }

    fun optionalPtrWithNullDefault(task: Task? = null): Task? {
        val kotlin_to_jdk_task = task?.getObjId() ?: 0L
        val result = jOptionalptrwithnulldefault(getObjId(), kotlin_to_jdk_task)
        val jdk_to_kotlin_result = if (result == 0L) null else Task(result)
        return jdk_to_kotlin_result
    }

    fun optionalFDPtrWithNullptrDefault(project: Project? = null): Project? {
        val kotlin_to_jdk_project = project?.getObjId() ?: 0L
        val result = jOptionalfdptrwithnullptrdefault(getObjId(), kotlin_to_jdk_project)
        val jdk_to_kotlin_result = if (result == 0L) null else Project(result)
        return jdk_to_kotlin_result
    }

    fun optionalSharedPtrWithNullptrDefault(person: Person? = null): Person? {
        val kotlin_to_jdk_person = person?.getObjId() ?: 0L
        val result = jOptionalsharedptrwithnullptrdefault(getObjId(), kotlin_to_jdk_person)
        val jdk_to_kotlin_result = if (result == 0L) null else Person(result)
        return jdk_to_kotlin_result
    }

    fun optionalIntWithDefault(value: Int = 5): Int {
        val result = jOptionalintwithdefault(getObjId(), value)
        
        return result
    }

    fun optionalLongWithDefault(value: Long = 7L): Long {
        val result = jOptionallongwithdefault(getObjId(), value)
        
        return result
    }

    fun optionalDoubleWithDefault(value: Double = 9.0): Double {
        val result = jOptionaldoublewithdefault(getObjId(), value)
        
        return result
    }

    fun optionalFloatWithDefault(value: Float = 11.0F): Float {
        val result = jOptionalfloatwithdefault(getObjId(), value)
        
        return result
    }

    fun optionalBoolWithDefault(value: Boolean = true): Boolean {
        val result = jOptionalboolwithdefault(getObjId(), value)
        
        return result
    }

    /**
     * @param[in] optionalStr string with default value
     */
    fun optionalStringWithDefault(optionalStr: String = "abc"): String {
        val result = jOptionalstringwithdefault(getObjId(), optionalStr)
        
        return result
    }

    fun optionalCharWithDefault(symbol: Char = ','): Char {
        val result = jOptionalcharwithdefault(getObjId(), symbol)
        
        return result
    }

    fun optionalCharPointerWithDefault(optionalStr: String = "def"): String {
        val result = jOptionalcharpointerwithdefault(getObjId(), optionalStr)
        
        return result
    }

    fun optionalEnumWithDefault(c: Color = Color.Red): Color {
        val kotlin_to_jdk_c = c.value
        val result = jOptionalenumwithdefault(getObjId(), kotlin_to_jdk_c)
        val jdk_to_kotlin_result = Color.getByValue(result)!!
        return jdk_to_kotlin_result
    }

    fun optionalRefWithDefaultComplexValue(task: Task): Task {
        val kotlin_to_jdk_task = task.getObjId()
        val result = jOptionalrefwithdefaultcomplexvalue(getObjId(), kotlin_to_jdk_task)
        val jdk_to_kotlin_result = Task(result)
        return jdk_to_kotlin_result
    }

    fun optionalByValWithDefaultComplexValue(task: Task): Task {
        val kotlin_to_jdk_task = task.getObjId()
        val result = jOptionalbyvalwithdefaultcomplexvalue(getObjId(), kotlin_to_jdk_task)
        val jdk_to_kotlin_result = Task(result)
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
    private external fun jOptionalptrwithnullptrdefault(id: Long, task: Long): Long
    private external fun jOptionalptrwithnulldefault(id: Long, task: Long): Long
    private external fun jOptionalfdptrwithnullptrdefault(id: Long, project: Long): Long
    private external fun jOptionalsharedptrwithnullptrdefault(id: Long, person: Long): Long
    private external fun jOptionalintwithdefault(id: Long, value: Int): Int
    private external fun jOptionallongwithdefault(id: Long, value: Long): Long
    private external fun jOptionaldoublewithdefault(id: Long, value: Double): Double
    private external fun jOptionalfloatwithdefault(id: Long, value: Float): Float
    private external fun jOptionalboolwithdefault(id: Long, value: Boolean): Boolean
    private external fun jOptionalstringwithdefault(id: Long, optionalStr: String): String
    private external fun jOptionalcharwithdefault(id: Long, symbol: Char): Char
    private external fun jOptionalcharpointerwithdefault(id: Long, optionalStr: String): String
    private external fun jOptionalenumwithdefault(id: Long, c: Int): Int
    private external fun jOptionalrefwithdefaultcomplexvalue(id: Long, task: Long): Long
    private external fun jOptionalbyvalwithdefaultcomplexvalue(id: Long, task: Long): Long
    private external fun jSet_this(id: Long, self: Any): Unit
    private external fun jFinalize(id: Long): Unit
}