/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 08/18/2022-11:02.
 * Please do not change it manually.
 */

package com.examples.optionals

import com.examples.cppbind.*
import com.examples.cppbind.exceptions.*
import com.examples.enums.Color
import com.examples.enums.ColorShade
import com.examples.enums.LogLevel
import com.examples.getters.Person
import com.examples.simple.Project
import com.examples.simple.Root
import com.examples.simple.Task

open class Optionals
internal constructor(obj: CppBindObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun constructHelper(): Long {
            val id = jConstructor1()
            return id
        }

        @JvmStatic
        private external fun jConstructor1(): Long


        protected fun constructHelper(task: Task, i: Int): Long {
            val kotlintojdktask = task.cppbindObjId
            val id = jConstructor2(kotlintojdktask, i, task)
            return id
        }

        @JvmStatic
        private external fun jConstructor2(task: Long, i: Int, vararg extraObjs: Any?): Long


        protected fun constructHelper(task: Task, i: Int, r: Root): Long {
            val kotlintojdktask = task.cppbindObjId
            val kotlintojdkr = r.cppbindObjId
            val id = jConstructor(kotlintojdktask, i, kotlintojdkr, task, r)
            return id
        }

        @JvmStatic
        private external fun jConstructor(task: Long, i: Int, r: Long, vararg extraObjs: Any?): Long
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::Optionals"
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
    
    constructor(): this(CppBindObject(constructHelper(), true)) {
    }


    constructor(task: Task, i: Int = 1): this(CppBindObject(constructHelper(task, i), true)) {
    }


    constructor(task: Task, i: Int = 1, r: Root): this(CppBindObject(constructHelper(task, i, r), true)) {
    }
    
    fun optionalPtrWithNullptrDefault(task: Task? = null): Task? {
        val kotlintojdktask = task?.cppbindObjId ?: 0L
        val result = jOptionalptrwithnullptrdefault(cppbindObjId, kotlintojdktask, task)
        val jdktokotlinresult = if (result == 0L) null else Task(CppBindObject(result))
        return jdktokotlinresult
    }

    fun optionalPtrWithNullDefault(task: Task? = null): Task? {
        val kotlintojdktask = task?.cppbindObjId ?: 0L
        val result = jOptionalptrwithnulldefault(cppbindObjId, kotlintojdktask, task)
        val jdktokotlinresult = if (result == 0L) null else Task(CppBindObject(result))
        return jdktokotlinresult
    }

    fun optionalIntWithDefault(value: Int = 5): Int {
        val result = jOptionalintwithdefault(cppbindObjId, value)
        
        return result
    }

    fun optionalLongWithDefault(value: Long = 7L): Long {
        val result = jOptionallongwithdefault(cppbindObjId, value)
        
        return result
    }

    fun optionalDoubleWithDefault(value: Double = 9.0): Double {
        val result = jOptionaldoublewithdefault(cppbindObjId, value)
        
        return result
    }

    fun optionalFloatWithDefault(value: Float = 11.0F): Float {
        val result = jOptionalfloatwithdefault(cppbindObjId, value)
        
        return result
    }

    fun optionalShortWithDefault(value: Short = 10): Short {
        val result = jOptionalshortwithdefault(cppbindObjId, value)
        
        return result
    }

    fun optionalBoolWithDefault(value: Boolean = true): Boolean {
        val result = jOptionalboolwithdefault(cppbindObjId, value)
        
        return result
    }

    /**
     * @param[in] optionalStr string with default value
     */
    fun optionalStringWithDefault(optionalStr: String = "abc"): String {
        val result = jOptionalstringwithdefault(cppbindObjId, optionalStr)
        
        return result
    }

    fun optionalCharWithDefault(symbol: Char = ','): Char {
        val result = jOptionalcharwithdefault(cppbindObjId, symbol)
        
        return result
    }

    fun optionalUnsignedCharWithDefault(num: UByte = 100u): UByte {
        val kotlintojdknum = num.toInt()
        val result = jOptionalunsignedcharwithdefault(cppbindObjId, kotlintojdknum, num)
        val jdktokotlinresult = result.toUByte()
        return jdktokotlinresult
    }

    fun optionalCharPointerWithDefault(optionalStr: String = "def"): String {
        val result = jOptionalcharpointerwithdefault(cppbindObjId, optionalStr)
        val jdktokotlinresult = result!!
        return jdktokotlinresult
    }

    fun optionalEnumWithDefault(c: Color = Color.Red): Color {
        val kotlintojdkc = c.value
        val result = jOptionalenumwithdefault(cppbindObjId, kotlintojdkc, c)
        val jdktokotlinresultOptional = Color.getByValue(result)
        if (jdktokotlinresultOptional == null) {
            ExceptionHandler.handleUncaughtException("Internal error: unresolved reference to non existing field of Color enum.")
        }
        val jdktokotlinresult = jdktokotlinresultOptional!!
        return jdktokotlinresult
    }

    fun optionalEnumWithDefaultAndChangedNames(level: LogLevel = LogLevel.WARNING): LogLevel {
        val kotlintojdklevel = level.value
        val result = jOptionalenumwithdefaultandchangednames(cppbindObjId, kotlintojdklevel, level)
        val jdktokotlinresultOptional = LogLevel.getByValue(result)
        if (jdktokotlinresultOptional == null) {
            ExceptionHandler.handleUncaughtException("Internal error: unresolved reference to non existing field of LogLevel enum.")
        }
        val jdktokotlinresult = jdktokotlinresultOptional!!
        return jdktokotlinresult
    }

    fun singleComplexDefaultValue(): Task {
        val result = jSinglecomplexdefaultvalue1(cppbindObjId)
        val jdktokotlinresult = Task(CppBindObject(result, true))
        return jdktokotlinresult
    }


    fun singleComplexDefaultValue(task: Task): Task {
        val kotlintojdktask = task.cppbindObjId
        val result = jSinglecomplexdefaultvalue(cppbindObjId, kotlintojdktask, task)
        val jdktokotlinresult = Task(CppBindObject(result, true))
        return jdktokotlinresult
    }

    fun multipleMixedDefaultValues(): String {
        val result = jMultiplemixeddefaultvalues1(cppbindObjId)
        
        return result
    }


    fun multipleMixedDefaultValues(task: Task, i: Int = 1): String {
        val kotlintojdktask = task.cppbindObjId
        val result = jMultiplemixeddefaultvalues2(cppbindObjId, kotlintojdktask, i, task)
        
        return result
    }


    fun multipleMixedDefaultValues(task: Task, i: Int = 1, r: Root): String {
        val kotlintojdktask = task.cppbindObjId
        val kotlintojdkr = r.cppbindObjId
        val result = jMultiplemixeddefaultvalues(cppbindObjId, kotlintojdktask, i, kotlintojdkr, task, r)
        
        return result
    }

    fun optionalEnumWithDefaultAndFieldPrefix(c: ColorShade = ColorShade.ShadeLight): ColorShade {
        val kotlintojdkc = c.value
        val result = jOptionalenumwithdefaultandfieldprefix(cppbindObjId, kotlintojdkc, c)
        val jdktokotlinresultOptional = ColorShade.getByValue(result)
        if (jdktokotlinresultOptional == null) {
            ExceptionHandler.handleUncaughtException("Internal error: unresolved reference to non existing field of ColorShade enum.")
        }
        val jdktokotlinresult = jdktokotlinresultOptional!!
        return jdktokotlinresult
    }

    fun optionalEnumWithInternalDefault(c: ColorShade): ColorShade {
        val kotlintojdkc = c.value
        val result = jOptionalenumwithinternaldefault(cppbindObjId, kotlintojdkc, c)
        val jdktokotlinresultOptional = ColorShade.getByValue(result)
        if (jdktokotlinresultOptional == null) {
            ExceptionHandler.handleUncaughtException("Internal error: unresolved reference to non existing field of ColorShade enum.")
        }
        val jdktokotlinresult = jdktokotlinresultOptional!!
        return jdktokotlinresult
    }

    /**
     * @param[in] optionalStr string with default value
     */
    fun optionalStringViewWithDefault(optionalStr: String = "abc"): String {
        val result = jOptionalstringviewwithdefault(cppbindObjId, optionalStr)
        
        return result
    }

    fun optionalFDPtrWithNullptrDefault(project: Project? = null): Project? {
        val kotlintojdkproject = project?.cppbindObjId ?: 0L
        val result = jOptionalfdptrwithnullptrdefault(cppbindObjId, kotlintojdkproject, project)
        val jdktokotlinresult = if (result == 0L) null else Project(CppBindObject(result))
        return jdktokotlinresult
    }

    fun optionalSharedPtrWithNullptrDefault(person: Person? = null): Person? {
        val kotlintojdkperson = person?.cppbindObjId ?: 0L
        val result = jOptionalsharedptrwithnullptrdefault(cppbindObjId, kotlintojdkperson, person)
        val jdktokotlinresult = if (result == 0L) null else Person(CppBindObject(result, true))
        return jdktokotlinresult
    }

    /**
     * CppBind generated hashCode method returning the hash of underlying C++ object id.
     */
    override fun hashCode(): Int {
        return cxxId.hashCode()
    }

    /**
     * CppBind generated equals method comparing the underlying C++ object ids.
     */
    override fun equals(other: Any?): Boolean {
        other as Optionals
        return cxxId == other.cxxId
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
    private external fun jOptionalptrwithnullptrdefault(id: Long, task: Long, vararg extraObjs: Any?): Long
    private external fun jOptionalptrwithnulldefault(id: Long, task: Long, vararg extraObjs: Any?): Long
    private external fun jOptionalintwithdefault(id: Long, value: Int, vararg extraObjs: Any?): Int
    private external fun jOptionallongwithdefault(id: Long, value: Long, vararg extraObjs: Any?): Long
    private external fun jOptionaldoublewithdefault(id: Long, value: Double, vararg extraObjs: Any?): Double
    private external fun jOptionalfloatwithdefault(id: Long, value: Float, vararg extraObjs: Any?): Float
    private external fun jOptionalshortwithdefault(id: Long, value: Short, vararg extraObjs: Any?): Short
    private external fun jOptionalboolwithdefault(id: Long, value: Boolean, vararg extraObjs: Any?): Boolean
    private external fun jOptionalstringwithdefault(id: Long, optionalStr: String, vararg extraObjs: Any?): String
    private external fun jOptionalcharwithdefault(id: Long, symbol: Char, vararg extraObjs: Any?): Char
    private external fun jOptionalunsignedcharwithdefault(id: Long, num: Int, vararg extraObjs: Any?): Int
    private external fun jOptionalcharpointerwithdefault(id: Long, optionalStr: String?, vararg extraObjs: Any?): String?
    private external fun jOptionalenumwithdefault(id: Long, c: Int, vararg extraObjs: Any?): Int
    private external fun jOptionalenumwithdefaultandchangednames(id: Long, level: Int, vararg extraObjs: Any?): Int
    private external fun jSinglecomplexdefaultvalue1(id: Long): Long

    private external fun jSinglecomplexdefaultvalue(id: Long, task: Long, vararg extraObjs: Any?): Long
    private external fun jMultiplemixeddefaultvalues1(id: Long): String

    private external fun jMultiplemixeddefaultvalues2(id: Long, task: Long, i: Int, vararg extraObjs: Any?): String

    private external fun jMultiplemixeddefaultvalues(id: Long, task: Long, i: Int, r: Long, vararg extraObjs: Any?): String
    private external fun jOptionalenumwithdefaultandfieldprefix(id: Long, c: Int, vararg extraObjs: Any?): Int
    private external fun jOptionalenumwithinternaldefault(id: Long, c: Int, vararg extraObjs: Any?): Int
    private external fun jOptionalstringviewwithdefault(id: Long, optionalStr: String, vararg extraObjs: Any?): String
    private external fun jOptionalfdptrwithnullptrdefault(id: Long, project: Long, vararg extraObjs: Any?): Long
    private external fun jOptionalsharedptrwithnullptrdefault(id: Long, person: Long, vararg extraObjs: Any?): Long
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

private external fun jGettypebyid(id: Long): String
